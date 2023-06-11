#include <stdbool.h>

extern FILE* yyout;
extern yylineno;

// Podemos usar los registros del 0 al 30, el 31 tiene uso reservado, el 12 lo guardamos para imprimir
bool regstrosDisponiblesF[31] = {true, true, true, true, true, true, true, true, true, true, true, true, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};

// en este aray vamos a almacenar los valores que posteriormente habrá que inicializar en MIPS
float varDeclarar[31][3]; // almacenamos el numVar de todo lo que queremos declarar y el valor float
int sigVar = 0;

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
        v = eval(a->l) != eval(a->r);
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, " c.eq.s $f%d, $f%d\n", node->right->registro, node->left->registro);

        // se ve si son iguales y con bc1f "etiqueta", si el flag de condicion es 0 (false), se entra en la etiqueta

        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "igualigual") == 0) {
        v = eval(a->l) == eval(a->r);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, " c.eq.s $f%d, $f%d\n", node->right->registro, node->left->registro);

        // se ve si son iguales y con bc1t "etiqueta", si el flag de condicion es 1 (true), se entra en la etiqueta
        
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "menor") == 0) {
        v = eval(a->l) < eval(a->r);
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "c.lt.s $f%d, $f%d\n", node->left->registro, node->right->registro);
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "mayor") == 0) {
        v = eval(a->l) > eval(a->r);
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "c.lt.s $f%d, $f%d\n", node->right->registro, node->left->registro);
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "menorigual") == 0) {
        v = eval(a->l) <= eval(a->r);
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "c.le.s $f%d, $f%d\n", node->left->registro, node->right->registro);
        liberarRegistro(node->left);
        liberarRegistro(node->right);
    }
    else if (strcmp(node->type, "mayorigual") == 0) {
        v = eval(a->l) >= eval(a->r);
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
    else if (strcmp(node->type, "asignacion") == 0) { // nueva variable
        printf("entra en ");
        printf("%s\n",node->type);
        valor = generarCodigoIntermedio(node->right);
        printf("RESULTADO OPERACION EN ASIGNACION: %f\n",valor);
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
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "POTENCIA NI\n");
    }
    else if (strcmp(node->type, "si") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "TODO: SI\n");
    }
    else if (strcmp(node->type, "mientras") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "TODO: MIENTRAS\n");
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

void iniciarGCI(struct ASTNode* node) {
    // imprimimos el .data con las variables que se quieren declarar y llamamos al método con el que recorreremos el AST
    fprintf(yyout, ".data\n");
    for (int i = 0; i < 31; i++){
        if (varDeclarar[i][2] == 1) // de esta forma evitamos imprimir los valores vacios
        {
            fprintf(yyout, "var%d: .float %f\n", (int)varDeclarar[i][1], varDeclarar[i][0]);
        }
    }

    fprintf(yyout, "\n.text\n");
    float result = generarCodigoIntermedio(node);
}