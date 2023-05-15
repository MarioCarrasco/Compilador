#include <string.h>

struct simbolo{
   char *nombre;
   int tipo;
   int valor;
};

struct simbolo tabla_simbolos[100];
int num_simbolos = 0;

int buscar_simbolo(char *nombre) {
   for (int i = 0; i < num_simbolos; i++) {
      if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
         return tabla_simbolos[i].valor;
      }
   }
   return 4;
}

int existe_simbolo(char *nombre) {
   for (int i = 0; i < num_simbolos; i++) {
      if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
         return 1;
      }
   }
   return 0;
}

void insertar_simbolo(char *nombre, int tipo, int valor) {
    // Verificar si el símbolo ya existe
    for (int i = 0; i < num_simbolos; i++) {
        if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
            tabla_simbolos[i].valor = valor;
            return;
        }
    }
    // Si el símbolo no existe, agregarlo a la tabla de símbolos
    struct simbolo nuevo_simbolo[100];
    strcpy(nuevo_simbolo->nombre, nombre);
    nuevo_simbolo->tipo = tipo;
    nuevo_simbolo->valor = valor;
    memcpy(tabla_simbolos, nuevo_simbolo, num_simbolos * sizeof(struct simbolo));
    num_simbolos++;
}