%{
#include <ctype.h>
#include <stdio.h>
#include "tabla_simbolos.h"
#include "ast.h"

extern yylineno;

simbolo tabla_simbolos[100];
int num_simbolos = 0;
%}

%token VARIABLE '='
%token NUMERO
%left '+' '-'
%left '*' '/'
%right '^'
%start S
%%

S: expresion
   |sentencia
   |expresion S
   |sentencia S
   |
   ;

sentencia: expresion {printf(" El resultado es %d\n", $1); }
   | VARIABLE '=' expresion {  
            if(existe_simbolo($1,tabla_simbolos,num_simbolos)==0){ // no exixte simbolo, se crea
               printf("Nuevo simbolo\n"); 
               tabla_simbolos[num_simbolos].nombre = $1;
               tabla_simbolos[num_simbolos].tipo = "entero";
               tabla_simbolos[num_simbolos].valor = $3;
               printf("Nombre del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].nombre);
               printf("Tipo del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].tipo);
               printf("Valor del nuevo simbolo: %d\n", tabla_simbolos[num_simbolos].valor);
               num_simbolos++;
            }
            else{ // exixte simbolo, se actualiza
               printf("Actualizamos simbolo\n"); 
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
            $$ = createASTNode("asignacion", $1, $1, $3);
         }
      ;

expresion: NUMERO { $$ = createASTNode("numero", $1, NULL, NULL); }
         | VARIABLE { printf("entra en variable\n"); 
            if(existe_simbolo($1, tabla_simbolos, num_simbolos)==1){
               $$ = createASTNode("variable", $1, $1, buscar_simbolo($1,tabla_simbolos,num_simbolos));
            }
            else{
               printf("Error en la linea %s: variable '%s' no declarada\n",yylineno, $1);
               // cazar error de variable no declarada
            }
         }
         | expresion '+' expresion { printf("En la linea %d", yylineno); printf(" entra en la suma: %d + %d\n", *$1, *$3); $$ = createASTNode("suma", $1+$3, $1, $3); }
         | expresion '-' expresion { $$ = createASTNode("resta", $1-$3, $1, $3); }
         | expresion '*' expresion { $$ = createASTNode("multiplicacion", $1*$3, $1, $3); }
         | expresion '/' expresion { $$ = createASTNode("division", $1/$3, $1, $3); }
         | expresion '^' expresion { $$ = createASTNode("potencia", $1^$3, $1, $3); }
      ;


%%
extern FILE* yyin;
extern FILE* yyout;

main()
{
   char pathI[100] = "./CodigoEntrada/in.txt";
   char pathO[100] = "./CodigoEntrada/out.txt";

   yyin = fopen(pathI, "rt");
   yyout = fopen(pathO, "wt");

   yyparse();
   fclose(pathI);
   fclose(pathO);
}

yyerror(){} 