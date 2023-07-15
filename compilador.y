%{
#include <ctype.h>
#include <stdio.h>
#include <math.h>
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

%token <sVal> VARIABLE
%token <vInt> ENTERO
%token <fVal> DECIMAL
%token <sVal> COMENTARIO COMENTARIOL
%token <sVal> SI OSI SINO FIN
%token <sVal> MIENTRAS
%token <sVal> IMPRIMIR

%type <valores> sentencia
%type <valores> expresion
%type <valores> sentencias
%type <valores> expr_booleanas
%type <valores> sentencia_si
%type <valores> bucle_while
%type <valores> imprimir

%left IGUALIGUAL MENOR MAYOR DIFERENTE MENORIGUAL MAYORIGUAL
%left '(' ')'
%left '+' '-' '='
%left '*' '/'
%right '^'
%start S
%%

S: sentencia { iniciarGCI($1.nodo);/*llamar al método generarCodigoIntermedio()*/}
   ;

sentencia: sentencias { $$.nodo = $1.nodo; }
            | sentencia sentencias { $$.nodo = createASTNode("SS", -1, -1, $1.nodo, $2.nodo); }
         ;

sentencias: expresion { $$.nodo = $1.nodo; }
   | COMENTARIO { /*No se hace nada con los comentarios, se obvian*/ }
   | COMENTARIOL { /*No se hace nada con los comentarios, se obvian*/ }
   | VARIABLE '=' expresion {  
            printf("Tipo de la expresion: %s \n", $3.tipo);
            char* nuevoTipo = "";
            if (strcmp($3.tipo, "entero") == 0){
               nuevoTipo = "entero";
               if(existe_simbolo($1,tabla_simbolos,num_simbolos)==0){ // no exixte simbolo, se crea
                  printf("Nuevo simbolo\n"); 
                  tabla_simbolos[num_simbolos].nombre = $1;
                  tabla_simbolos[num_simbolos].tipo = nuevoTipo;
                  tabla_simbolos[num_simbolos].valor = $3.valInt;
                  printf("Nombre del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].nombre);
                  printf("Tipo del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].tipo);
                  printf("Valor del nuevo simbolo: %d\n", tabla_simbolos[num_simbolos].valor);
                  num_simbolos++;

                  struct ASTNode* temp = createASTNode("variable", -1, -1, NULL, NULL);
                  $$.nodo = createASTNodeRegistro("declaracion", -1, -1, temp, $3.nodo);
               }
               else{ // exixte simbolo, se actualiza
                  printf("Actualizamos simbolo\n"); 
                  for (int i = 0; i < num_simbolos; i++) {
                     if (strcmp(tabla_simbolos[i].nombre, $1) == 0) {
                        tabla_simbolos[i].nombre = $1;
                        tabla_simbolos[i].tipo = nuevoTipo;
                        tabla_simbolos[i].valor = $3.valInt;
                        printf("Nombre del simbolo actualizado: %s\n", tabla_simbolos[i].nombre);
                        printf("Tipo del simbolo actualizado: %s\n", tabla_simbolos[i].tipo);
                        printf("Valor del simbolo actualizado: %d\n", tabla_simbolos[i].valor);
                     }
                  }
                  struct ASTNode* temp = createASTNodeRegistro("variable", -1, -1, NULL, NULL);
                  $$.nodo = createASTNodeRegistro("asignacion", -1, -1, temp, $3.nodo);
               }
            }
            else if (strcmp($3.tipo, "decimal") == 0){
               nuevoTipo = "decimal";
               if(existe_simbolo($1,tabla_simbolos,num_simbolos)==0){ // no exixte simbolo, se crea
                  printf("Nuevo simbolo\n"); 
                  tabla_simbolos[num_simbolos].nombre = $1;
                  tabla_simbolos[num_simbolos].tipo = nuevoTipo;
                  tabla_simbolos[num_simbolos].valorFloat = $3.valFloat;
                  printf("Nombre del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].nombre);
                  printf("Tipo del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].tipo);
                  printf("Valor del nuevo simbolo: %d\n", tabla_simbolos[num_simbolos].valorFloat);
                  num_simbolos++;

                  struct ASTNode* temp = createASTNode("variable", -1, -1, NULL, NULL);
                  $$.nodo = createASTNodeRegistro("declaracion", -1, -1, temp, $3.nodo);
               }
               else{ // exixte simbolo, se actualiza
                  printf("Actualizamos simbolo\n"); 
                  for (int i = 0; i < num_simbolos; i++) {
                     if (strcmp(tabla_simbolos[i].nombre, $1) == 0) {
                        tabla_simbolos[i].nombre = $1;
                        tabla_simbolos[i].tipo = nuevoTipo;
                        tabla_simbolos[i].valorFloat = $3.valFloat;
                        printf("Nombre del simbolo actualizado: %s\n", tabla_simbolos[i].nombre);
                        printf("Tipo del simbolo actualizado: %s\n", tabla_simbolos[i].tipo);
                        printf("Valor del simbolo actualizado: %f\n", tabla_simbolos[i].valorFloat);
                     }
                  }
                  struct ASTNode* temp = createASTNodeRegistro("variable", -1, -1, NULL, NULL);
                  $$.nodo = createASTNodeRegistro("asignacion", -1, -1, temp, $3.nodo);
               }
            }
         }
      ;

expresion: ENTERO { $$.valInt = $1; 
                  $$.valFloat = (float)$1;
                  $$.nodo = createASTNodeRegistroDeclarar("entero", $1, (float)$1, NULL, NULL); $$.tipo = "entero"; 
                  }
         | DECIMAL { $$.valFloat = $1; $$.nodo = createASTNodeRegistroDeclarar("decimal", -1, $1, NULL, NULL); $$.tipo = "decimal"; }
         | VARIABLE { printf("entra en variable\n"); 
            if(existe_simbolo($1, tabla_simbolos, num_simbolos)==1){
               int temp2;
               float temp3;
               if (buscar_tipo($1, tabla_simbolos, num_simbolos)=="entero"){
                  temp2 = buscar_simbolo($1,tabla_simbolos,num_simbolos);// solo funciona para valores enteros
                  $$.valInt = temp2;
                  $$.tipo = "entero";
                  printf("Nuevo valor: %d\n", temp2);
                  $$.nodo = createASTNodeRegistroDeclarar("variable", temp2, (float)temp2, NULL, NULL);
               }
               else if (buscar_tipo($1, tabla_simbolos, num_simbolos)=="decimal"){
                  temp3 = buscar_simboloFloat($1,tabla_simbolos,num_simbolos);// solo funciona para valores enteros
                  $$.valFloat = temp3;
                  $$.tipo = "decimal";
                  printf("Nuevo valor: %f\n", temp3);
                  $$.nodo = createASTNodeRegistroDeclarar("variable", -1, temp3, NULL, NULL);
               }
               else{
                  printf("Error en linea %d: Tipo de la variable %s no observado\n",(yylineno-1)-1, $1);
                  exit(1);
               }
            }
            else{
               printf("Error en linea %d: variable '%s' no declarada\n",(yylineno-1), $1);// cazar error de variable no declarada
               exit(1);
            }
         }
         | expresion '+' expresion {
               if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la suma de enteros: %d + %d\n", (yylineno-1), $1.valInt, $3.valInt);
                     $$.valFloat = $1.valInt + $3.valInt;
                     $$.valInt = $1.valInt + $3.valInt;
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la suma de decimales: %f + %f\n", (yylineno-1), $1.valFloat, $3.valFloat);
                     $$.valFloat = $1.valFloat + $3.valFloat;
                  }
                  /*else if (strcmp($1.tipo, "string") == 0){
                     printf("En la linea %d entra en la concatenacion: %s + %s\n", (yylineno-1), $1.valStr, $3.valStr);
                  }*/
                  else{
                     printf("Error en linea %d: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
                     printf("Error en linea %d: No se pueden operar numeros con strings\n",(yylineno-1));
                     exit(1);
                  }
                  else if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la suma: %d + %f\n", (yylineno-1), $1.valInt, $3.valFloat);
                     $$.valFloat = $1.valInt + $3.valFloat;
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la suma: %f + %d\n", (yylineno-1), $1.valFloat, $3.valInt);
                     $$.valFloat = $1.valFloat + $3.valInt;
                  }
                  else{
                     printf("Error en linea %d: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               $$.nodo = createASTNodeRegistro("suma", -1, -1, $1.nodo, $3.nodo); 
            }
         | expresion '-' expresion { 
               if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
                     printf("Error en linea %d: No se puede realizar la operación 'resta' con un string\n", (yylineno-1));
                     exit(1);
               }
               if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la resta de enteros: %d - %d\n", (yylineno-1), $1.valInt, $3.valInt);
                     $$.valFloat = $1.valInt - $3.valInt;
                     $$.valInt = $1.valInt - $3.valInt;
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la resta de decimales: %f - %f\n", (yylineno-1), $1.valFloat, $3.valFloat);
                     $$.valFloat = $1.valFloat - $3.valFloat;
                  }
                  else{
                     printf("Error en linea %d: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la resta: %d - %f\n", (yylineno-1), $1.valInt, $3.valFloat);
                     $$.valFloat = $1.valInt - $3.valFloat;
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la resta: %f - %d\n", (yylineno-1), $1.valFloat, $3.valInt);
                     $$.valFloat = $1.valFloat - $3.valInt;
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               $$.nodo = createASTNodeRegistro("resta", -1, -1, $1.nodo, $3.nodo);
            }
         | expresion '*' expresion { 
               if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
                     printf("Error en linea %s: No se puede realizar la operación 'multiplicacion' con un string\n", (yylineno-1));
                     exit(1);
               }
               else if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la multiplicacion de enteros: %d * %d\n", (yylineno-1), $1.valInt, $3.valInt);
                     $$.valFloat = $1.valInt * $3.valInt;
                     $$.valInt = $1.valInt * $3.valInt;
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la multiplicacion de decimales: %f * %f\n", (yylineno-1), $1.valFloat, $3.valFloat);
                     $$.valFloat = $1.valFloat * $3.valFloat;
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la multiplicacion: %d * %f\n", (yylineno-1), $1.valInt, $3.valFloat);
                     $$.valFloat = $1.valInt * $3.valFloat;
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la multiplicacion: %f * %d\n", (yylineno-1), $1.valFloat, $3.valInt);
                     $$.valFloat = $1.valFloat * $3.valInt;
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               $$.nodo = createASTNodeRegistro("multiplicacion", -1, -1, $1.nodo, $3.nodo);
            }
         | expresion '/' expresion { 
               if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
                     printf("Error en linea %s: No se puede realizar la operación 'division' con un string\n", (yylineno-1));
                     exit(1);
               }
               // control semantico sobre las divisiones entre 0
               else if (strcmp($3.tipo, "entero") == 0 && $3.valInt == 0){
                  printf("Error en linea %d: No se puede dividir entre 0\n",(yylineno-1));
                  exit(1);
               }
               else if (strcmp($3.tipo, "decimal") == 0 && $3.valFloat == 0){
                  printf("Error en linea %d: No se puede dividir entre 0\n",(yylineno-1));
                  exit(1);
               }
               else if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la division de enteros: %d / %d\n", (yylineno-1), $1.valInt, $3.valInt);
                     $$.valFloat = $1.valInt / $3.valInt;
                     $$.valInt = $1.valInt / $3.valInt;
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la division de decimales: %f / %f\n", (yylineno-1), $1.valFloat, $3.valFloat);
                     $$.valFloat = $1.valFloat / $3.valFloat;
                  }
                  else{
                     printf("Error en linea %d: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la division: %d / %f\n", (yylineno-1), $1.valInt, $3.valFloat);
                     $$.valFloat = $1.valInt / $3.valFloat;
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la division: %f / %d\n", (yylineno-1), $1.valFloat, $3.valInt);
                     $$.valFloat = $1.valFloat / $3.valInt;
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               $$.nodo = createASTNodeRegistro("division", -1, -1, $1.nodo, $3.nodo);
            }
         | expresion '^' expresion { 
               if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
                     printf("Error en linea %s: No se puede realizar la operación 'potencia' con un string\n", (yylineno-1));
                     exit(1);
               }
               else if (strcmp($1.tipo, $3.tipo) == 0){ // si los tipos son el mismo
                  if (strcmp($1.tipo, "entero") == 0){
                     printf("En la linea %d entra en la potencia de enteros: %d ^ %d\n", (yylineno-1), $1.valInt, $3.valInt);
                     $$.valFloat = pow($1.valInt, $3.valInt);
                     $$.valInt = pow($1.valInt, $3.valInt);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la potencia de decimales: %f ^ %f\n", (yylineno-1), $1.valFloat, $3.valFloat);
                     $$.valFloat = pow($1.valFloat, $3.valFloat);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp($1.tipo, "entero") == 0 && strcmp($3.tipo, "decimal") == 0){
                     printf("En la linea %d entra en la potencia: %d ^ %f\n", (yylineno-1), $1.valInt, $3.valFloat);
                     $$.valFloat = pow($1.valInt, $3.valFloat);
                  }
                  else if (strcmp($1.tipo, "decimal") == 0 && strcmp($3.tipo, "entero") == 0){
                     printf("En la linea %d entra en la potencia: %f ^ %d\n", (yylineno-1), $1.valFloat, $3.valInt);
                     $$.valFloat = pow($1.valFloat, $3.valInt);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               $$.nodo = createASTNodeRegistro("potencia", -1, -1, $1.nodo, $3.nodo);
            }
         // EXPRESIONES BOOLEANAS
         | expr_booleanas { $$.nodo = $1.nodo; }
         | sentencia_si { $$.nodo = $1.nodo; }
         | bucle_while { $$.nodo = $1.nodo; }
         | imprimir { $$.nodo = $1.nodo; }
      ;

expr_booleanas: expresion MAYOR expresion{
            if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               $$.tipo = "bool";
               $$.nodo = createASTNodeRegistro("mayor", -1, -1, $1.nodo, $3.nodo);
               $$.valFloat = $1.nodo > $3.nodo;
            }
         }
         | expresion MENOR expresion{
               if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               $$.tipo = "bool";
               $$.nodo = createASTNodeRegistro("menor", -1, -1, $1.nodo, $3.nodo);
               $$.valFloat = $1.nodo < $3.nodo;
            }
         }
         | expresion IGUALIGUAL expresion{
            if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               $$.tipo = "bool";
               $$.nodo = createASTNodeRegistro("igualigual", -1, -1, $1.nodo, $3.nodo);
               $$.valFloat = $1.nodo == $3.nodo;
            }         
         }
         | expresion DIFERENTE expresion{
            if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               $$.tipo = "bool";
               $$.nodo = createASTNodeRegistro("diferente", -1, -1, $1.nodo, $3.nodo);
               $$.valFloat = $1.nodo != $3.nodo;
            }
         }
         | expresion MENORIGUAL expresion{
            if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               $$.tipo = "bool";
               $$.nodo = createASTNodeRegistro("menorigual", -1, -1, $1.nodo, $3.nodo);
               $$.valFloat = $1.nodo <= $3.nodo;
            }         
         }
         | expresion MAYORIGUAL expresion{
            if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               $$.tipo = "bool";
               $$.nodo = createASTNodeRegistro("mayorigual", -1, -1, $1.nodo, $3.nodo);
               $$.valFloat = $1.nodo >= $3.nodo;
            }
         }
      ;

sentencia_si: SI '('expr_booleanas')' sentencia FIN { $$.nodo = createASTNode("si", -1, -1, $3.nodo, $5.nodo); }
         | SI '('expr_booleanas')' sentencia SINO sentencia FIN { $$.nodo = createASTNodeSino("sino", -1, -1, $3.nodo, $5.nodo, $7.nodo); }
      ;

bucle_while: MIENTRAS '('expr_booleanas')' sentencia FIN { $$.nodo = createASTNode("mientras", -1, -1, $3.nodo, $5.nodo); }
      ;

imprimir: IMPRIMIR '('sentencia')' { $$.nodo = createASTNode("imprimir", -1, -1, $3.nodo, NULL); }


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