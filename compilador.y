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
            if(existe_simbolo($3)==0){
               insertar_simbolo($1, 1, $3);
            }
            else{
               fprintf (stderr, "Error en línea: Variable ya declarada\n");
            }
         }
      ;

expresion: NUMERO { $$ = $1; }
         | VARIABLE { $$ = buscar_simbolo($1); }
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
