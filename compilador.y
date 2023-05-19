%{
#include <ctype.h>
#include <stdio.h>
#include "tabla_simbolos.h"

simbolo tabla_simbolos[100];
int num_simbolos = 0;
%}
%token  NUMERO VARIABLE '='
%left '+' '-'
%left '*' '/'
%right '^'
%start S
%%

S: expresion {printf(" El resultado es %d\n", $1); }
   | VARIABLE '=' expresion {  
            printf("expresion1\n");    
            if(existe_simbolo($1,tabla_simbolos,num_simbolos)==0){ // no exixte simbolo, se crea
               printf("expresion2\n");    
               tabla_simbolos[num_simbolos].nombre = $1;
               tabla_simbolos[num_simbolos].tipo = "entero";
               tabla_simbolos[num_simbolos].valor = $3;
               printf("El nombre dolar es: %s\n", $1);
               printf("Nombre del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].nombre);
               printf("Tipo del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].tipo);
               printf("Valor del nuevo simbolo: %d\n", tabla_simbolos[num_simbolos].valor);
               printf("expresion3\n");
               num_simbolos++;
            }
            else{ // exixte simbolo, se actualiza
               for (int i = 0; i < num_simbolos; i++) {
                  if (strcmp(tabla_simbolos[i].nombre, $1) == 0) {
                     tabla_simbolos[num_simbolos].nombre = $1;
                     tabla_simbolos[num_simbolos].tipo = "entero";
                     tabla_simbolos[num_simbolos].valor = $3;
                     printf("Nombre del simbolo actualizado: %s\n", tabla_simbolos[num_simbolos].nombre);
                     printf("Tipo del simbolo actualizado: %s\n", tabla_simbolos[num_simbolos].tipo);
                     printf("Valor del simbolo actualizado: %d\n", tabla_simbolos[num_simbolos].valor);
                  }
               }
            }
         }
      ;

expresion: NUMERO { $$ = $1; }
         | VARIABLE { printf("entra en variable\n"); $$ = buscar_simbolo($1,tabla_simbolos,num_simbolos); }
         | expresion '+' expresion { $$ = $1 + $3; }
         | expresion '-' expresion { $$ = $1 - $3; }
         | expresion '*' expresion { $$ = $1 * $3; }
         | expresion '/' expresion { $$ = $1 * $3; }
         | expresion '^' expresion { $$ = $1 ^ $3; }
      ;


%%
main()
{
   return yyparse();
}


yyerror()
{ 
} 
