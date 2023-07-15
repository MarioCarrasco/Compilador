#include <stdbool.h>

extern FILE* yyout;
extern yylineno;

// Podemos usar los registros del 0 al 30, el 31 tiene uso reservado, el 12 lo guardamos para imprimir
bool regstrosDisponiblesF[31] = {true, true, true, true, true, true, true, true, true, true, true, true, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};

// en este aray vamos a almacenar los valores que posteriormente habrá que inicializar en MIPS
float varDeclarar[31][3]; // almacenamos el numVar de todo lo que queremos declarar y el valor float
int sigVar = 0;
int numEtiquetaTemp = 0; // numero de etiqueta que va incrementando para que estas no se repitan en la cracion de bucles y sentencias si sino
int numEtiqueta = 0; // numero de etiqueta

//estructura de los nodos
struct ASTNode{
    int valInt;
    float valFloat;
    int registro;
    int numVar; // numero asignado para declarar las variables en MIPS (solo para nodos hoja como variables o numeros)
    //char* valStr;
    char* type;             // Tipo de nodo (operador, identificador, número, etc)
    struct ASTNode* left;   // Puntero al hijo izquierdo
    struct ASTNode* right;  // Puntero al hijo derecho
    struct ASTNode* mid;  // Puntero al hijo mediano solo usado para sino
};

int siguienteRegistroLibre(){
    int i = 0;
    for (i = 0; i < 32; i++) // recorremos todos los registros 
    {
        if (regstrosDisponiblesF[i] == true) { // el primer registro libre es ocupado
            regstrosDisponiblesF[i] = false; // marcamos el registro como ocupado
            return i;
        }
    }
    // Si sale del búcle for, significa que no hay ningún registro libre
    printf("Error: No hay registros suficientes\n");
    exit(1);
    return -1;
}

void liberarRegistro(struct ASTNode* nodo){
    regstrosDisponiblesF[nodo->registro] = true; // liberamos registro
}

struct ASTNode* createASTNode(char* type, int valInt, float valFloat/*, char* valStr*/, struct ASTNode* left, struct ASTNode* right) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    node->valInt = valInt;
    node->valFloat = valFloat;
    //node->valStr = valStr;
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

struct ASTNode* createASTNodeRegistro(char* type, int valInt, float valFloat/*, char* valStr*/, struct ASTNode* left, struct ASTNode* right) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    node->valInt = valInt;
    node->valFloat = valFloat;
    //node->valStr = valStr;
    
    node->registro = siguienteRegistroLibre();

    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

struct ASTNode* createASTNodeRegistroDeclarar(char* type, int valInt, float valFloat/*, char* valStr*/, struct ASTNode* left, struct ASTNode* right) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    node->valInt = valInt;
    node->valFloat = valFloat;
    //node->valStr = valStr;
    
    node->registro = siguienteRegistroLibre();
    node->numVar = sigVar;
    varDeclarar[sigVar][0] = node->valFloat;
    varDeclarar[sigVar][1] = node->numVar;
    varDeclarar[sigVar][2] = 1;
    sigVar++;

    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

struct ASTNode* createASTNodeSino(char* type, int valInt, float valFloat/*, char* valStr*/, struct ASTNode* left, struct ASTNode* right, struct ASTNode* mid) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    node->valInt = valInt;
    node->valFloat = valFloat;
    //node->valStr = valStr;
    node->type = type;
    node->left = left;
    node->right = right;
    node->mid = mid;
    return node;
}


float generarCodigoIntermedio(struct ASTNode* node) {
    float valor = 1.0; //variable para almacenar el valor del resultado de las operaciones

    if (node == NULL) {
        return valor;
    }

    // Generar código intermedio para el nodo actual
    //VARIABLES TEMP
    if (strcmp(node->type, "SS") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        generarCodigoIntermedio(node->left);
        generarCodigoIntermedio(node->right);
    }
    else if (strcmp(node->type, "diferente") == 0) {
        valor = generarCodigoIntermedio(node->left) != generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, " c.eq.s $f%d, $f%d\n", node->right->registro, node->left->registro);

        // se ve si son iguales y con bc1f "etiqueta", si el flag de condicion es 0 (false), se entra en la etiqueta

        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "igualigual") == 0) {
        valor = generarCodigoIntermedio(node->left) == generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "c.eq.s $f%d, $f%d\n", node->right->registro, node->left->registro);

        // se ve si son iguales y con bc1t "etiqueta", si el flag de condicion es 1 (true), se entra en la etiqueta
        
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "menor") == 0) {
        valor = generarCodigoIntermedio(node->left) < generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "c.lt.s $f%d, $f%d\n", node->left->registro, node->right->registro);
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "mayor") == 0) {
        valor = generarCodigoIntermedio(node->left) > generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "c.lt.s $f%d, $f%d\n", node->right->registro, node->left->registro);
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "menorigual") == 0) {
        valor = generarCodigoIntermedio(node->left) <= generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "c.le.s $f%d, $f%d\n", node->left->registro, node->right->registro);
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "mayorigual") == 0) {
        valor = generarCodigoIntermedio(node->left) >= generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "c.le.s $f%d, $f%d\n", node->right->registro, node->left->registro);
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "decimal") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        valor = node->valFloat;
        fprintf(yyout, "lwc1 $f%d, var%d\n", node->registro, node->numVar);
    }
    else if (strcmp(node->type, "entero") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        valor = node->valFloat;
        fprintf(yyout, "lwc1 $f%d, var%d\n", node->registro, node->numVar);
    }
    else if (strcmp(node->type, "asignacion") == 0) { // nueva variable o asignacion
        printf("entra en ");
        printf("%s\n",node->type);
        valor = generarCodigoIntermedio(node->right);
        printf("RESULTADO OPERACION EN ASIGNACION: %f\n",valor);
        fprintf(yyout, "mov.s $f%d, $f%d\n", node->left->registro, node->right->registro);
        node->valFloat = valor;
        printf("Registro de almacenamiento del resultado: %d\n",node->registro);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "declaracion") == 0) { // nueva variable o asignacion
        printf("entra en ");
        printf("%s\n",node->type);
        valor = generarCodigoIntermedio(node->right);
        node->valFloat = valor;
        printf("Registro de almacenamiento del resultado: %d\n",node->registro);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "variable") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        valor = node->valFloat;
        fprintf(yyout, "lwc1 $f%d, var%d\n", node->registro, node->numVar);
    }
    else if (strcmp(node->type, "suma") == 0) {
        valor = generarCodigoIntermedio(node->left) + generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("valor de la suma: %f\n", valor);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "add.s $f%d, $f%d, $f%d\n", node->registro, node->left->registro, node->right->registro); // Suma los registros $t0 y $t1 y almacena el resultado en $t2
        //liberamos los registros de los nodos
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "resta") == 0) {
        valor = generarCodigoIntermedio(node->left) - generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("valor de la resta: %f\n", valor);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "sub.s $f%d, $f%d, $f%d\n", node->registro, node->left->registro, node->right->registro); // Suma los registros $t0 y $t1 y almacena el resultado en $t2
        //liberamos los registros de los nodos
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "multiplicacion") == 0) {
        valor = generarCodigoIntermedio(node->left) * generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("valor de la multiplicacion: %f\n", valor);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "mul.s $f%d, $f%d, $f%d\n", node->registro, node->left->registro, node->right->registro); // Suma los registros $t0 y $t1 y almacena el resultado en $t2
        //liberamos los registros de los nodos
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "division") == 0) {
        valor = generarCodigoIntermedio(node->left) / generarCodigoIntermedio(node->right);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("valor de la division: %f\n", valor);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "div.s $f%d, $f%d, $f%d\n", node->registro, node->left->registro, node->right->registro); // Suma los registros $t0 y $t1 y almacena el resultado en $t2
        //liberamos los registros de los nodos
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "potencia") == 0) { // NO ES REQUISITO
        valor = pow(generarCodigoIntermedio(node->left), generarCodigoIntermedio(node->right));
        printf("entra en ");
        printf("%s\n",node->type);
        printf("valor de la potencia: %f\n", valor);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "POTENCIA ASM\n");
    }
    else if (strcmp(node->type, "si") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);

        numEtiquetaTemp = numEtiqueta;
        numEtiqueta = numEtiqueta + 1;

        valor = generarCodigoIntermedio(node->left); // condicion
        printf("Condicion del if: %f\n", valor);
        fprintf(yyout, "bc1f etiq%d\n", numEtiquetaTemp);

        // Codigo dentro del if
        generarCodigoIntermedio(node->right);

        // Etiqueta de salida del if
        fprintf(yyout, "etiq%d:\n", numEtiquetaTemp);
    }
    else if (strcmp(node->type, "sino") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);

        numEtiquetaTemp = numEtiqueta;
        numEtiqueta = numEtiqueta + 2;

        valor = generarCodigoIntermedio(node->left); // condicion
        printf("Condicion del if: %f\n", valor);
        fprintf(yyout, "bc1f etiq%d\n", numEtiquetaTemp);

        // Codigo dentro del if
        generarCodigoIntermedio(node->right);
        fprintf(yyout, "j etiq%d\n", numEtiquetaTemp+1); // si se ha entrado en el if se salta el codigo del else

        // Etiqueta de salida del if
        fprintf(yyout, "etiq%d:\n", numEtiquetaTemp);

        // Codigo del sino
        generarCodigoIntermedio(node->mid);
        fprintf(yyout, "etiq%d:\n", numEtiquetaTemp+1);

    }
    else if (strcmp(node->type, "mientras") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        numEtiquetaTemp = numEtiqueta;
        numEtiqueta = numEtiqueta + 2;

        
        // Saltar a la etiqueta del comienzo del WHILE
        fprintf(yyout, "etiqueta%d:\n", numEtiquetaTemp);
        valor = generarCodigoIntermedio(node->left); // se evalua la operacion booleana
        printf("Condicion del while: %f\n", valor);
        fprintf(yyout, "bc1f etiqueta%d\n", numEtiquetaTemp + 1);

        generarCodigoIntermedio(node->right); // el resto del codigo del while

        // Saltar a la etiqueta del comienzo del while
        fprintf(yyout, "j etiqueta%d\n", numEtiquetaTemp);
        // Etiqueta que se usa para salir del while
        fprintf(yyout, "etiqueta%d:\n", numEtiquetaTemp + 1);

    }
    else if (strcmp(node->type, "imprimir") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        //  Resuelve la operación evaluandola
        generarCodigoIntermedio(node->left);
        printf("Resultado de la impresion por pantalla: %f", generarCodigoIntermedio(node->left));
        // Imprime el resultado almacenado en al registro de
        metodoImprimir(node->left);

    }
    else { // ERROR
        printf("entra en default ");
        printf("%s\n",node->type);
        fprintf(yyout, "ERROR: Operación '%s' inválida en la linea %d\n", node->type, yylineno);
    }
    // Generar código intermedio para los nodos hijos
    /*generarCodigoIntermedio(node->left);
    generarCodigoIntermedio(node->right);*/
    return valor;
}

void metodoImprimir(struct ASTNode* node){
    fprintf(yyout, "li $v0, 2\n");
    // Mover del registro n al registro 12
    fprintf(yyout, "add.s $f12, $f31, $f%d\n", node->registro);
    // Llamada al sistema
    fprintf(yyout, "syscall\n");

    // Salto de línea
    fprintf(yyout, "li $v0, 4\n");
    fprintf(yyout, "la $a0, newLine\n");
    fprintf(yyout, "syscall\n");
}

void iniciarGCI(struct ASTNode* node) {
    // imprimimos el .data con las variables que se quieren declarar y llamamos al método con el que recorreremos el AST
    fprintf(yyout, ".data\n");
    for (int i = 0; i < 31; i++){
        if (varDeclarar[i][2] == 1) // de esta forma evitamos imprimir los valores vacios
        {
            fprintf(yyout, "var%d: .float %f\n", (int)varDeclarar[i][1], varDeclarar[i][0]);
        }
    }
    fprintf(yyout, "newLine: .asciiz \"\\n\"\n");
    fprintf(yyout, "zero_f: .float 0.0\n"); // variable con cero en float para imprimir
    fprintf(yyout, "\n.text\n");
    fprintf(yyout, "lwc1 $f31, zero_f\n");
    float result = generarCodigoIntermedio(node);
}