extern FILE* yyout;
extern yylineno;

//estructura de los nodos
struct ASTNode{
    //añadir valor para acceder aqui en la generacion de codigo intermedio GCI (crear strct nodo para enteros, floats, etc)
    int valInt;
    float valFloat;
    //char* valStr;
    char* type;             // Tipo de nodo (operador, identificador, número, etc)
    struct ASTNode* left;   // Puntero al hijo izquierdo
    struct ASTNode* right;  // Puntero al hijo derecho
};

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
        fprintf(yyout, "SS\n");
    }
    else if (strcmp(node->type, "diferente") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "DIFERENTE\n");
    }
    else if (strcmp(node->type, "igualigual") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "IGUALIGUAL\n");
    }
    else if (strcmp(node->type, "menor") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "MENOR\n");
    }
    else if (strcmp(node->type, "mayor") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "MAYOR\n");
    }
    else if (strcmp(node->type, "decimal") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "DECIMAL\n");
    }
    else if (strcmp(node->type, "decimal") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "DECIMAL\n");
    }
    else if (strcmp(node->type, "entero") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "ENTERO\n");
    }
    else if (strcmp(node->type, "asignacion") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "ASIGNACION\n");
    }
    else if (strcmp(node->type, "variable") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "VARIABLE\n");
    }
    else if (strcmp(node->type, "suma") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "SUMA\n");
    }
    else if (strcmp(node->type, "resta") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "RESTA\n");
    }
    else if (strcmp(node->type, "multiplicacion") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "MULTIPLICACION\n");
    }
    else if (strcmp(node->type, "division") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
        fprintf(yyout, "DIVISION\n");
    }
    else if (strcmp(node->type, "potencia") == 0) {
        printf("entra en ");
        printf("%s\n",node->type);
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
    else {
        printf("entra en default ");
        printf("%s\n",node->type);
        fprintf(yyout, "ERROR: Operación '%s' inválida en la linea %d\n", node->type, yylineno);
    }

/*    switch (node->type) {
        case 'suma':
            printf("\nentra en suma");
            printf("%d\n",node->type);
            fprintf(yyout, "ADD %d, %d\n", node->left, node->right);
            break;
        case 'resta':
            fprintf(yyout, "SUB %d, %d\n", node->left, node->right);
            break;
        case 'multiplicacion':
            fprintf(yyout, "IMUL %d, %d\n", node->left, node->right);
            break;
        case 'division':
            fprintf(yyout, "SUB %d, %d\n", node->left, node->right);
            break;
        case 'potencia':
            fprintf(yyout, "SUB %d, %d\n", node->left, node->right);
            break;
        default:
            printf("entra en default");
            printf("%s\n",node->type);
            fprintf(yyout, "ERROR: Operación inválida\n");
            exit(1);
    }
*/
    // Generar código intermedio para los nodos hijos
    generarCodigoIntermedio(node->left);
    generarCodigoIntermedio(node->right);
}