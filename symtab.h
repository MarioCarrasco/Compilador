
/* Maximo tamaño de la tabla hash*/
#define SIZE 3

/* Maximo tamaño de tokens-identifiers */
#define MAXTOKENLEN 40

/* parameter struct */
typedef struct Param{
	// parameter type and name
	int typo;
	char param_nombre[MAXTOKENLEN];
	
	// to store the value
	int vint; 
    int vbool; 
    double vreal; 
    char* vstr;
	int passing; // value or reference
} Param;

typedef struct RefList{ 
    int lineno;
    struct RefList *next;
} RefList;

// struct that represents a list node
typedef struct list_t{
	// name, size of name, scope and occurrences (lines)
	char identificador[MAXTOKENLEN];
    int size;
    int scope;
	int inicializada;
	int pos;
    RefList *lines;
    
	int vint; double vreal; char* vstr; int vbool;
    char* tipo;
	struct list_t *next;

	// range
	int inicio_rango;
	int fin_rango;

	// tipo array
	char* identificador_rango;
	char* tipo_array;
} list_t;

static list_t **hash_table;

void inicializar_hash_table(); // initialize hash table
unsigned int hash(char *key); 
int declarar_variable(char *identificador, char* tipo, char* initipo, int vint, int vbool, char* vstr, float vreal, int lineno, int inicializada); 
int editar_variable(char* identificador, char* initipo, int vint, int vbool, char* vstr, float vreal, int lineno);
int declarar_range(char* identificador, int inicio, int fin, int lineno);
int declarar_array_tipo(char* identificador_array, char* identificador_rango, char* tipo, int lineno);
int declarar_array(char* identificador_array, char* identificador_tipo_array, char* tipo_valor, int vint, int vbool, char* vstr, float vreal, int lineno);
void symtab_dump(FILE *of); // dump file