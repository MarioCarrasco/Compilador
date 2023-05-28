#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct {
   char *nombre;
   char *tipo;
   int valor;
}simbolo;

int buscar_simbolo(char *nombre, simbolo* tabla_simbolos, int num_simbolos) {
   printf("buscando simbolo\n");
   for (int i = 0; i < num_simbolos; i++) {
      if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
         printf("encontrado\n");
         return tabla_simbolos[i].valor;
      }
   }
   printf("no encontrado\n");
   return 0;
}

int existe_simbolo(char *nombre, simbolo* tabla_simbolos, int num_simbolos) {
   for (int i = 0; i < num_simbolos; i++) {
      if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
         return 1;
      }
   }
   return 0;
}

void insertar_simbolo(char *nombre, int valor, simbolo* tabla_simbolos, int num_simbolos) {
    printf("Intentando insertar\n");    
    // Verificar si el símbolo ya existe
    for (int i = 0; i < num_simbolos; i++) {
          printf("Verificando si exixte el simbolo\n");    
        if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
            printf("variable ya existe\n");
            tabla_simbolos[i].valor = valor;
            return;
        }
    }
    printf("No exixte se va a insertar\n");
    // Si el símbolo no existe, agregarlo a la tabla de símbolos
    simbolo nuevo_simbolo[100];
    printf("struct creado\n");
    tabla_simbolos[num_simbolos] = *nuevo_simbolo;
    printf("insertando\n");
    tabla_simbolos[num_simbolos].valor = valor;
    printf("valor asignado\n");
    strcpy(tabla_simbolos[num_simbolos].nombre, nombre);
    printf("nombre asignado\n");
    num_simbolos++;
    printf("simbolo insertado\n");
}