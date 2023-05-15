#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

int cur_scope = 0;
int declare = 0; // 1: declarar variable, 0: no declarar variable
int pos_int = 0;
int pos_float = 10;

void inicializar_hash_table() { // Inicializamos la tabla con valores nulos
	int i; 
	hash_table = malloc(SIZE * sizeof(list_t*));
	for(i = 0; i < SIZE; i++) hash_table[i] = NULL;
}

unsigned int hash(char *key){
	unsigned int hashval = 0;
	for(;*key!='\0';key++) hashval += *key;
	hashval += key[0] % 11 + (key[0] << 3) - key[0];
	return hashval % SIZE;
}

int existe_variable(char *identificador) {
    unsigned int hashval = hash(identificador);
	list_t *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(identificador,l->identificador) != 0)) l = l->next;

    if (l == NULL){
        return 0;
    } else {
        return 1;
    }
}

struct list_t *obtener_variable(char *identificador) {
    unsigned int hashval = hash(identificador);
	list_t *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(identificador,l->identificador) != 0)) l = l->next;
    return l;
}

int obtener_variable_pos(char *identificador) {
    unsigned int hashval = hash(identificador);
	list_t *l = hash_table[hashval];
    while ((l != NULL) && (strcmp(identificador,l->identificador) != 0)) l = l->next;
    if (l == NULL) {
        return -1;
    } else {
        return l->pos;
    }
}

int editar_variable(char* identificador, char* initipo, int vint, int vbool, char* vstr, float vreal, int lineno){
    int error = 0;
    unsigned int hashval = hash(identificador);
	list_t *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(identificador,l->identificador) != 0)) l = l->next;
	
    RefList *t = l->lines;
    while (t->next != NULL) t = t->next;

    t->next = (RefList*) malloc(sizeof(RefList));
    t->next->lineno = lineno;
    t->next->next = NULL;

    l->inicializada = 1;
    if (l->tipo == initipo || (l->tipo == "real" && initipo == "entero")) {
        if (l->tipo == "entero") {
            l->vint = vint;
        } else if (l->tipo == "real") {
            if (initipo == "entero") {
                l->vreal = (float) vint;
            } else {
                l->vreal = vreal;
            }
        } else if (l->tipo == "booleano") {
            l->vbool = vbool;
        } else if (l->tipo == "cadena") {
            l->vstr = vstr;
        }
    } else {
        error = 1;
        yyerror("No se puede operar con tipos diferentes.");
    }

    return error;
}

int declarar_variable(char* identificador, char* tipo, char* initipo, int vint, int vbool, char* vstr, float vreal, int lineno, int inicializada){
    int error = 0;
    unsigned int hashval = hash(identificador);
	list_t *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(identificador,l->identificador) != 0)) l = l->next;
	
    if (l == NULL){ // La variable no existe
        l = (list_t*) malloc(sizeof(list_t));
        strcpy(l->identificador, identificador);
        l->tipo = tipo;
        l->scope = cur_scope;



        l->lines = (RefList*) malloc(sizeof(RefList));
        l->lines->lineno = lineno;
        l->lines->next = NULL;

        if (inicializada == 1) { // Varaiable inicializada con un valor
            if (tipo == initipo || (tipo == "real" && initipo == "entero")) {
                l->inicializada = 1;
                if (l->tipo == "entero") {
                    l->vint = vint;
                    l->pos = pos_int;
                    pos_int++;
                } else if (l->tipo == "real") {
                    if (initipo == "entero") {
                        l->vreal = (float) vint;
                    } else {
                        l->vreal = vreal;
                    }
                    l->pos = pos_float;
                    pos_float++;
                } else if (l->tipo == "booleano") {
                    l->vbool = vbool;
                    l->pos = pos_int;
                    pos_int++;
                } else if (l->tipo == "cadena") {
                    l->vstr = vstr;
                }
            } else {
                yyerror("No se puede inicializar una variable con un tipo diferente de valor asignado.");
                // exit(0);
            }
        } else {
            l->inicializada = 0;
        }
        
        /* la añadimos a la tabla */
        l->next = hash_table[hashval];
        hash_table[hashval] = l; 
        printf("Insertada %s por primera vez con el numero de linea %d\n", identificador, lineno);
    } else { // Si la variable ya existe lanzar error
        error = 1;
        yyerror("Ya ha sido declarada una variable con este identificador");
    }

    return error;
}

void symtab_dump(FILE * of){  /* dump file */
  int i;
  fprintf(of,"%-30s ", "Identificador");
  fprintf(of,"%-16s ",  "Tipo");
  fprintf(of,"%-16s ",  "Inicializada");
  fprintf(of,"%-14s ",  "Valor");
  fprintf(of,"%-16s ",  "Tipo Array");
  fprintf(of,"%-12s ", "Linea");
  fprintf(of,"\n");

  fprintf(of,"%-30s ", "------------");
  fprintf(of,"%-16s ",  "------------");
  fprintf(of,"%-16s ",  "------------");
  fprintf(of,"%-14s ",  "------------");
  fprintf(of,"%-16s ",  "------------");
  fprintf(of,"%-12s ", "------------");
  fprintf(of,"\n");
  for (i=0; i < SIZE; ++i){ 
	if (hash_table[i] != NULL){ 
		list_t *l = hash_table[i];

		while (l != NULL){ 
			RefList *t = l->lines;
            
			fprintf(of,"%-30s ",l->identificador);
			fprintf(of,"%-17s", l->tipo);
			fprintf(of,"%-17d",l->inicializada);

            if (l->inicializada == 1) {
                if (l->tipo == "entero") {
                    fprintf(of,"%-15d", l->vint);
                    fprintf(of,"%-17s", "");
                } else if (l->tipo == "real") {
                    fprintf(of,"%-15f", l->vreal);
                    fprintf(of,"%-17s", "");
                } else if (l->tipo == "booleano") {
                    fprintf(of,"%-15d", l->vbool);
                    fprintf(of,"%-17s", "");
                } else if (l->tipo == "cadena") {
                    fprintf(of,"%-15s", l->vstr);
                    fprintf(of,"%-17s", "");
                } else if (l->tipo == "rango") {
                    fprintf(of, "%d .. %d        ", l->inicio_rango, l->fin_rango);
                    fprintf(of,"%-17s", "");
                } else if (l->tipo == "tipo_array") {
                    fprintf(of, "%-15s", l->identificador_rango);
                    fprintf(of,"%-17s", l->tipo_array);
                } else {
                    if (l->tipo_array == "entero") {
                        fprintf(of,"%-15d", l->vint);
                    } else if (l->tipo_array == "real") {
                        fprintf(of,"%-15f", l->vreal);
                    } else if (l->tipo_array == "booleano") {
                        fprintf(of,"%-15d", l->vbool);
                    } else if (l->tipo_array == "cadena") {
                        fprintf(of,"%-15s", l->vstr);
                    }
                    fprintf(of,"%-17s", l->tipo_array);
                }
            } else {
                fprintf(of,"%-15s", "");
                fprintf(of,"%-17s", "");
            }

			while (t != NULL){
				fprintf(of,"%d ",t->lineno);
			    t = t->next;
			}
			fprintf(of,"\n");
			l = l->next;
		}
    }
  }
}


/***********************
 * ARRAY
 ***********************/

int declarar_range(char* identificador, int inicio, int fin, int lineno) {
    int error = 0;
    unsigned int hashval = hash(identificador);
	list_t *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(identificador,l->identificador) != 0)) l = l->next;
	
    if (l == NULL){ // La variable no existe
        l = (list_t*) malloc(sizeof(list_t));
        strcpy(l->identificador, identificador);
        l->tipo = "rango";
        l->scope = cur_scope;

        l->lines = (RefList*) malloc(sizeof(RefList));
        l->lines->lineno = lineno;
        l->lines->next = NULL;

        l->inicio_rango = inicio;
        l->fin_rango = fin;

        l->inicializada = 1;
        
        /* la añadimos a la tabla */
        l->next = hash_table[hashval];
        hash_table[hashval] = l; 
        printf("Insertada %s por primera vez con el numero de linea %d\n", identificador, lineno);
    } else { // Si la variable ya existe lanzar error
        error = 1;
        yyerror("Ya ha sido declarada una variable con este identificador");
    }

    return error;
}

int declarar_array_tipo(char* identificador_array, char* identificador_rango, char* tipo, int lineno) {
    int error = 0;
    unsigned int hashval = hash(identificador_array);
	list_t *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(identificador_array,l->identificador) != 0)) l = l->next;
	
    if (l == NULL && obtener_variable_pos(identificador_rango) != -1){ // La variable no existe
        l = (list_t*) malloc(sizeof(list_t));
        strcpy(l->identificador, identificador_array);
        l->tipo = "tipo_array";
        l->scope = cur_scope;

        l->lines = (RefList*) malloc(sizeof(RefList));
        l->lines->lineno = lineno;
        l->lines->next = NULL;

        l->identificador_rango = identificador_rango;
        l->tipo_array = tipo;

        l->inicializada = 1;
        
        /* la añadimos a la tabla */
        l->next = hash_table[hashval];
        hash_table[hashval] = l; 
        printf("Insertada %s por primera vez con el numero de linea %d\n", identificador_array, lineno);
    } else { // Si la variable ya existe lanzar error
        error = 1;
        yyerror("Ya ha sido declarada una variable con este identificador");
    }

    return error;
}

int declarar_array(char* identificador_array, char* identificador_tipo_array, char* tipo_valor, int vint, int vbool, char* vstr, float vreal, int lineno) {
    int error = 0;
    unsigned int hashval = hash(identificador_array);
	list_t *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(identificador_array,l->identificador) != 0)) l = l->next;
	
    list_t *l1 = obtener_variable(identificador_tipo_array);

    if (l == NULL && l1 != NULL){ // La variable no existe
        if (l1->tipo_array == tipo_valor) {
            l = (list_t*) malloc(sizeof(list_t));
            strcpy(l->identificador, identificador_array);
            l->tipo = l1->identificador;
            l->scope = cur_scope;

            l->lines = (RefList*) malloc(sizeof(RefList));
            l->lines->lineno = lineno;
            l->lines->next = NULL;

            l->tipo_array = tipo_valor;
            if (tipo_valor == "entero") {
                l->vint = vint;
            } else if (tipo_valor == "real") {
                l->vreal = vreal;
            } else if (tipo_valor == "booleano") {
                l->vbool = vbool;
            } else if (tipo_valor == "cadena") {
                l->vstr = vstr;
            }
            
            l->inicializada = 1;
            /* la añadimos a la tabla */
            l->next = hash_table[hashval];
            hash_table[hashval] = l; 
            printf("Insertada %s por primera vez con el numero de linea %d\n", identificador_array, lineno);
        } else {
            error = 1;
            yyerror("El tipo del array no concuerda con el valor inicializado");
        }
    } else { // Si la variable ya existe lanzar error
        error = 1;
        yyerror("Ya ha sido declarada una variable con este identificador");
    }

    return error;
}