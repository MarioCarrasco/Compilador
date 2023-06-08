%{
#include <ctype.h>
#include <stdio.h>
#include "tabla_simbolos.h"
#include "ast.c"

extern yylineno;
void yyerror(const char *s);

simbolo tabla_simbolos[100];
int num_simbolos = 0;
%}

%union {
   int vInt;
   char* sVal;
   float fVal;
      struct valores{
         char* nombre;
         int valInt;
         double valDoub;
         char* tipo;
         struct ASTNode* nodo;
      } valores;
}

%token <sVal> VARIABLE '='
%token <vInt> NUMERO
%token <sVal> COMENTARIO
%token <sVal> COMENTARIOL

%type <valores> sentencia
%type <valores> expresion
%type <valores> sentencias

%left '+' '-'
%left '*' '/'
%right '^'
%start S
%%

S: sentencia { generarCodigoIntermedio($1.nodo);/*llamar al método generarCodigoIntermedio()*/}
   ;

sentencia: sentencias { $$.nodo = $1.nodo; }
            | sentencia sentencias { $$.nodo = createASTNode("SS", -1, -1, $1.nodo, $2.nodo); }
         ;

sentencias: expresion { $$.nodo = $1.nodo; }
   | COMENTARIO { /*No se hace nada con los comentarios, se obvian*/ }
   | COMENTARIOL { /*No se hace nada con los comentarios, se obvian*/ }
   | VARIABLE '=' expresion {  
            printf("Tipo de la expresion: %s \n", $3.tipo);
            if(existe_simbolo($1,tabla_simbolos,num_simbolos)==0){ // no exixte simbolo, se crea
               printf("Nuevo simbolo\n"); 
               tabla_simbolos[num_simbolos].nombre = $1;
               tabla_simbolos[num_simbolos].tipo = "entero";
               tabla_simbolos[num_simbolos].valor = $3.valInt;
               printf("Nombre del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].nombre);
               printf("Tipo del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].tipo);
               printf("Valor del nuevo simbolo: %d\n", tabla_simbolos[num_simbolos].valor);
               num_simbolos++;
            }
            else{ // exixte simbolo, se actualiza
               printf("Actualizamos simbolo\n"); 
               for (int i = 0; i < num_simbolos; i++) {
                  if (strcmp(tabla_simbolos[i].nombre, $1) == 0) {
                     tabla_simbolos[i].nombre = $1;
                     tabla_simbolos[i].tipo = "entero";
                     tabla_simbolos[i].valor = $3.valInt;
                     printf("Nombre del simbolo actualizado: %s\n", tabla_simbolos[i].nombre);
                     printf("Tipo del simbolo actualizado: %s\n", tabla_simbolos[i].tipo);
                     printf("Valor del simbolo actualizado: %d\n", tabla_simbolos[i].valor);
                  }
               }
            }
            struct ASTNode* temp = createASTNode("variable", -1, -1, NULL, NULL);
            $$.nodo = createASTNode("asignacion", -1, -1, temp, $3.nodo);
         }
      ;

expresion: NUMERO { $$.valInt = $1; $$.nodo = createASTNode("numero", $1, -1, NULL, NULL); $$.tipo = "entero"; /*Añadir opcion para float*/}
         | VARIABLE { printf("entra en variable\n"); 
            if(existe_simbolo($1, tabla_simbolos, num_simbolos)==1){
               int temp2 = buscar_simbolo($1,tabla_simbolos,num_simbolos);// solo funciona para valores enteros
               $$.valInt = temp2;
               printf("Nuevo valor: %d\n", temp2);
               $$.nodo = createASTNode("variable", temp2, -1, NULL, NULL);
            }
            else{
               printf("Error en la linea %s: variable '%s' no declarada\n",yylineno, $1);
               // cazar error de variable no declarada
            }
         }
         | expresion '+' expresion { printf("En la linea %d", yylineno); printf(" entra en la suma: %d + %d\n", $1.valInt, $3.valInt); $$.nodo = createASTNode("suma", -1, -1, $1.nodo, $3.nodo); }
         | expresion '-' expresion { $$.nodo = createASTNode("resta", -1, -1, $1.nodo, $3.nodo); }
         | expresion '*' expresion { $$.nodo = createASTNode("multiplicacion", -1, -1, $1.nodo, $3.nodo); }
         | expresion '/' expresion { $$.nodo = createASTNode("division", -1, -1, $1.nodo, $3.nodo); }
         | expresion '^' expresion { $$.nodo = createASTNode("potencia", -1, -1, $1.nodo, $3.nodo); }
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

void yyerror(const char *s)
{ 
    fprintf(stderr, "Error");
}