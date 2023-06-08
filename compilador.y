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
         float valFloat;
         char* valStr;
         char* tipo;
         struct ASTNode* nodo;
      } valores;
}

%token <sVal> VARIABLE '='
%token <vInt> ENTERO
%token <fVal> DECIMAL
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

expresion: ENTERO { $$.valInt = $1; $$.nodo = createASTNode("entero", $1, -1, NULL, NULL); $$.tipo = "entero"; }
         | DECIMAL { $$.valFloat = $1; $$.nodo = createASTNode("decimal", -1, $1, NULL, NULL); $$.tipo = "decimal"; }
         | VARIABLE { printf("entra en variable\n"); 
            if(existe_simbolo($1, tabla_simbolos, num_simbolos)==1){
               int temp2 = buscar_simbolo($1,tabla_simbolos,num_simbolos);// solo funciona para valores enteros
               $$.valInt = temp2;
               printf("Nuevo valor: %d\n", temp2);
               $$.nodo = createASTNode("variable", temp2, -1, NULL, NULL);
            }
            else{
               printf("Error en linea %d: variable '%s' no declarada\n",yylineno, $1);// cazar error de variable no declarada
               exit(1);
            }
         }
         | expresion '+' expresion {
               if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la suma de enteros: %d + %d\n", yylineno, $1.valInt, $3.valInt);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la suma de decimales: %f + %f\n", yylineno, $1.valFloat, $3.valFloat);
                  }
                  /*else if (strcmp($1.tipo, "string") == 0){
                     printf("En la linea %d entra en la concatenacion: %s + %s\n", yylineno, $1.valStr, $3.valStr);
                  }*/
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la suma: %d + %f\n", yylineno, $1.valInt, $3.valFloat);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la suma: %f + %d\n", yylineno, $1.valFloat, $3.valInt);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               $$.nodo = createASTNode("suma", -1, -1, $1.nodo, $3.nodo); 
            }
         | expresion '-' expresion { 
               if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la resta de enteros: %d - %d\n", yylineno, $1.valInt, $3.valInt);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la resta de decimales: %f - %f\n", yylineno, $1.valFloat, $3.valFloat);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la resta: %d - %f\n", yylineno, $1.valInt, $3.valFloat);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la resta: %f - %d\n", yylineno, $1.valFloat, $3.valInt);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               $$.nodo = createASTNode("resta", -1, -1, $1.nodo, $3.nodo);
            }
         | expresion '*' expresion { 
               if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la multiplicacion de enteros: %d * %d\n", yylineno, $1.valInt, $3.valInt);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la multiplicacion de decimales: %f * %f\n", yylineno, $1.valFloat, $3.valFloat);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la multiplicacion: %d * %f\n", yylineno, $1.valInt, $3.valFloat);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la multiplicacion: %f * %d\n", yylineno, $1.valFloat, $3.valInt);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               $$.nodo = createASTNode("multiplicacion", -1, -1, $1.nodo, $3.nodo);
            }
         | expresion '/' expresion { 
               if ($3.valFloat == 0 || $3.valInt == 0){
                  printf("Error en linea %s: No se puede dividir entre 0\n",yylineno);
                  exit(1);
               }
               else if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la division de enteros: %d / %d\n", yylineno, $1.valInt, $3.valInt);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la division de decimales: %f / %f\n", yylineno, $1.valFloat, $3.valFloat);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la division: %d / %f\n", yylineno, $1.valInt, $3.valFloat);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la division: %f / %d\n", yylineno, $1.valFloat, $3.valInt);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               $$.nodo = createASTNode("division", -1, -1, $1.nodo, $3.nodo);
            }
         | expresion '^' expresion { 
               if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la potencia de enteros: %d ^ %d\n", yylineno, $1.valInt, $3.valInt);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la potencia de decimales: %f ^ %f\n", yylineno, $1.valFloat, $3.valFloat);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la potencia: %d ^ %f\n", yylineno, $1.valInt, $3.valFloat);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la potencia: %f ^ %d\n", yylineno, $1.valFloat, $3.valInt);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",yylineno);
                     exit(1);
                  }
               }
               $$.nodo = createASTNode("potencia", -1, -1, $1.nodo, $3.nodo);
            }
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