%{
#include <ctype.h>
#include <stdio.h>
#include "tabla_simbolos.h"
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
            if(existe_simbolo($1)==0){
               printf("expresion2\n");    
               insertar_simbolo($1, $3);
               printf("expresion3\n");    
            }
            else{
               printf ("Error en línea: Variable ya declarada\n");
            }
         }
      ;

expresion: NUMERO { $$ = $1; }
         | VARIABLE { printf("entra en variable\n"); $$ = buscar_simbolo($1); }
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
