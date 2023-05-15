#include "tabla_simbolos.h"

int buscar_simbolo(char *nombre) {
   for (int i = 0; i < num_simbolos; i++) {
      if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
         return tabla_simbolos[i].valor;
      }
   }
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