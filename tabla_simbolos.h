#include <stdio.h>
#include <string.h>

struct simbolo{
   char nombre[100];
   int valor;
};

struct simbolo tabla_simbolos[100];
int num_simbolos = 0;

int buscar_simbolo(char *nombre) {
   printf("buscando simbolo\n");
   for (int i = 0; i < num_simbolos; i++) {
      if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
         printf("encontrado");
         return tabla_simbolos[i].valor;
      }
   }
   printf("no encontrado\n");
   return 0;
}

int existe_simbolo(char *nombre) {
   for (int i = 0; i < num_simbolos; i++) {
      if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
         return 1;
      }
   }
   return 0;
}

void insertar_simbolo(char *nombre, int valor) {
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
    struct simbolo nuevo_simbolo[100];
    printf("struct creado\n");
    strcpy((*nuevo_simbolo).nombre, nombre);
    printf("nombre asignado\n");
    (*nuevo_simbolo).valor = valor;
    printf("valor asignado\n");
    tabla_simbolos[num_simbolos] = *nuevo_simbolo;
    printf("insertando\n");
    num_simbolos++;
    printf("simbolo insertado\n");
}