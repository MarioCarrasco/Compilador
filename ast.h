
//estructura de los nodos
typedef struct {
    int type;               // Tipo de nodo (operador, identificador, número, etc)
    char* value;            // Valor del nodo (el nombre de una variable o el valor de un número)
    struct ASTNode* left;   // Puntero al hijo izquierdo
    struct ASTNode* right;  // Puntero al hijo derecho
} ASTNode;

//estructura de la lista enlazada de los nodos
typedef struct {
    NodoAST* cabeza; // Puntero al primer nodo de la lista
    NodoAST* cola;   // Puntero al último nodo de la lista
} ASTList;

void agregarNodoAST(ASTList* lista, ASTNode* nodo) {
    if (lista->cabeza == NULL) {
        lista->cabeza = nodo;
        lista->cola = nodo;
    } else {
        lista->cola->siguiente = nodo;
        lista->cola = nodo;
    }
}

ASTNode* createASTNode(char* type, char* value, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

void generarCodigoIntermedio(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    // Generar código intermedio para el nodo actual
    switch (node->type) {
        case 'suma':
            printf("ADD %d, %d\n", node->left, node->right);
            break;
        case 'resta':
            printf("SUB %d, %d\n", node->left, node->right);
            break;
        case 'multiplicacion':
            printf("IMUL %d, %d\n", node->left, node->right);
            break;
        case 'division':
            printf("SUB %d, %d\n", node->left, node->right);
            break;
        case 'potencia':
            printf("SUB %d, %d\n", node->left, node->right);
            break;
        default:
            printf("ERROR: Operación inválida\n");
            exit(1);
    }

    // Generar código intermedio para los nodos hijos
    generarCodigoIntermedio(node->left);
    generarCodigoIntermedio(node->right);
}