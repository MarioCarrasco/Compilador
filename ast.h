extern FILE* yyout;

//estructura de los nodos
typedef struct {
    int type;               // Tipo de nodo (operador, identificador, número, etc)
    char* value;            // Valor del nodo (el nombre de una variable o el valor de un número)
    struct ASTNode* left;   // Puntero al hijo izquierdo
    struct ASTNode* right;  // Puntero al hijo derecho
} ASTNode;

ASTNode* createASTNode(char* type, char* value, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

void generarCodigoIntermedio(ASTNode* node) {
    if (node == NULL) {
        return;
    }

    // Generar código intermedio para el nodo actual
    switch (*node->type) {
        case 'suma':
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
            fprintf(yyout, "ERROR: Operación inválida\n");
            exit(1);
    }

    // Generar código intermedio para los nodos hijos
    generarCodigoIntermedio(node->left);
    generarCodigoIntermedio(node->right);
}