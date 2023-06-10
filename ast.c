#include <stdbool.h>

extern FILE* yyout;
extern yylineno;

// Podemos usar los registros del 0 al 31, el 32 tiene uso reservado
bool regstrosDisponiblesF[31] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};

//estructura de los nodos
struct ASTNode{
    //añadir valor para acceder aqui en la generacion de codigo intermedio GCI (crear strct nodo para enteros, floats, etc)
    int valInt;
    float valFloat;
    int registro;
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



void iniciarGCI(struct ASTNode* node) {
    // imprimimos el .data y llamamos al método con el que recorreremos el AST
    fprintf(yyout, ".data\n\n");

    fprintf(yyout, ".text\n");
    generarCodigoIntermedio(node);
}



void generarCodigoIntermedio(struct ASTNode* node) {
    if (node == NULL) {
        return;
    }

    // Generar código intermedio para el nodo actual
    //VARIABLES TEMP
    if (strcmp(node->type, "SS") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "--SS--\n");
    }
    else if (strcmp(node->type, "diferente") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "bne $t1, $t2, correcto\n");
    }
    else if (strcmp(node->type, "igualigual") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        /*fprintf(yyout, "lw $t0, %s\n", node->left->valFloat);
        fprintf(yyout, "lw $t0, %s\n", node->right->valFloat);*/
        fprintf(yyout, "beq $t1, $t2, correcto\n");
    }
    else if (strcmp(node->type, "menor") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "blt $t1, $t2, correcto\n");
    }
    else if (strcmp(node->type, "mayor") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "bgt $t1, $t2, correcto\n");
    }
    else if (strcmp(node->type, "decimal") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "--DECIMAL--\n");
    }
    else if (strcmp(node->type, "entero") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "--ENTERO--\n");
    }
    else if (strcmp(node->type, "asignacion") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "move $t1, $t2\n");
        // aqui se puede liberar un registro
    }
    else if (strcmp(node->type, "variable") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "--VARIABLE--\n");
    }
    else if (strcmp(node->type, "suma") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "add $t2, $t0, $t1\n"); // Suma los registros $t0 y $t1 y almacena el resultado en $t2
    }
    else if (strcmp(node->type, "resta") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "sub $t2, $t0, $t1\n");
    }
    else if (strcmp(node->type, "multiplicacion") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "mul $t3, $t0, $t1\n");
    }
    else if (strcmp(node->type, "division") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "div  $t3, $t0, $t1\n");
    }
    else if (strcmp(node->type, "potencia") == 0) { // NO ES REQUISITO
        printf("entra en ");
        printf("%s\n",node->type);
        printf("%d\n",node->left->registro);
        printf("%d\n",node->right->registro);
        fprintf(yyout, "POTENCIA\n");
    }
    else if (strcmp(node->type, "si") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "SI\n");
    }
    else if (strcmp(node->type, "mientras") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "MIENTRAS\n");
    }
    else { // ERROR
        printf("entra en default ");
        printf("%s\n",node->type);
        fprintf(yyout, "ERROR: Operación '%s' inválida en la linea %d\n", node->type, yylineno);
    }

    // Generar código intermedio para los nodos hijos
    generarCodigoIntermedio(node->left);
    generarCodigoIntermedio(node->right);
}