%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include "compilador.tab.h"
%}

%option noyywrap

%x comentario
%x bloquefuncion

letras [a-zA-Z]+
digitos [0-9]+

caso caso
cierto (cierto|verdadero)
continuar continuar
defecto (defecto|otro)
desde desde
elegir elegir
error error
escribir (escribir|imprimir|poner)
falso falso
fin fin
funcion (funcion|fun)
global global
hasta hasta
imprimirf imprimirf
incluir incluir
mientras mientras
nulo nulo
osi osi
repetir repetir
retorno (retorno|retornar|ret)
romper romper
si si
sino sino
tipo tipo
rango rango
ir ir
archivo archivo
cadena cadena
dic dic
lista lista
mate mate
sis sis
paquete paquete
gc gc
acadena acadena
alogico alogico
anumero anumero
leer leer
limpiar limpiar

reservadas ({caso}|{continuar}|{defecto}|{desde}|{elegir}|{error}|{escribir}|{funcion}|{fin}|{global}|{hasta}|{imprimirf}|{incluir}|{mientras}|{nulo}|{osi}|{repetir}|{retorno}|{romper}|{si}|{sino}|{tipo}|{rango}|{ir}|{archivo}|{cadena}|{dic}|{lista}|{mate}|{sis}|{paquete}|{gc})
booleanas ({cierto}|{falso}|{anumero}|{acadena}|{alogico}|{leer}|{limpiar})

variable (_*{letras}|_+{digitos})({letras}|{digitos}|_)*

%%

".." {fprintf(yyout, "%-60s %-30s %-15i\n", "AGREGACION DE CADENAS: (\")", yytext , yylineno);}
"." {fprintf(yyout, "%-60s %-30s %-15i\n", "PUNTO: (\")", yytext , yylineno);}
":" {fprintf(yyout, "%-60s %-30s %-15i\n", "DOBLE PUNTO: (\")", yytext , yylineno);}
"," {fprintf(yyout, "%-60s %-30s %-15i\n", "SEPARADOR: (\")", yytext , yylineno);}
"=" {fprintf(yyout, "%-60s %-30s %-15i\n", "ASIGNACION: (\")", yytext , yylineno);}

{digitos} yylval = atoi(yytext); return NUMERO;

"+" return SUMA;
"-" return RESTA;
"*" return MULT;
"/" return DIV;
"^" return POT;

"%" {fprintf(yyout, "%-60s %-30s %-15i\n", "MODULO: (\")", yytext , yylineno);}

"++" {fprintf(yyout, "%-60s %-30s %-15i\n", "INCREMENTACION: (\")", yytext , yylineno);}
"--" {fprintf(yyout, "%-60s %-30s %-15i\n", "DECREMENTACION: (\")", yytext , yylineno);}

"+=" {fprintf(yyout, "%-60s %-30s %-15i\n", "SUMAR CON: (\")", yytext , yylineno);}
"-=" {fprintf(yyout, "%-60s %-30s %-15i\n", "RESTAR CON: (\")", yytext , yylineno);}
"*=" {fprintf(yyout, "%-60s %-30s %-15i\n", "MULTIPLICAR CON: (\")", yytext , yylineno);}
"/=" {fprintf(yyout, "%-60s %-30s %-15i\n", "DIVIDIR CON: (\")", yytext , yylineno);}
"%=" {fprintf(yyout, "%-60s %-30s %-15i\n", "MODULAR CON: (\")", yytext , yylineno);}

"==" {fprintf(yyout, "%-60s %-30s %-15i\n", "IGUALDAD: (\")", yytext , yylineno);}
"!=" {fprintf(yyout, "%-60s %-30s %-15i\n", "DIFERENCIA: (\")", yytext , yylineno);}
">" {fprintf(yyout, "%-60s %-30s %-15i\n", "MAYOR QUE: (\")", yytext , yylineno);}
"<" {fprintf(yyout, "%-60s %-30s %-15i\n", "MENOR QUE: (\")", yytext , yylineno);}
">=" {fprintf(yyout, "%-60s %-30s %-15i\n", "MAYOR E IGUAL QUE: (\")", yytext , yylineno);}
"<=" {fprintf(yyout, "%-60s %-30s %-15i\n", "MENOR E IGUAL QUE: (\")", yytext , yylineno);}
"~=" {fprintf(yyout, "%-60s %-30s %-15i\n", "COINCIDE ER: (\")", yytext , yylineno);}

"&&" {fprintf(yyout, "%-60s %-30s %-15i\n", "AND: (\")", yytext , yylineno);}
"||" {fprintf(yyout, "%-60s %-30s %-15i\n", "OR: (\")", yytext , yylineno);}
"!" {fprintf(yyout, "%-60s %-30s %-15i\n", "NEGACION: (\")", yytext , yylineno);}

"(" {fprintf(yyout, "%-60s %-30s %-15i\n", "INICIO PARENTESIS: (\")", yytext , yylineno);}
")" {printf("PARENTESIS DERECHO: %s\n",yytext);}{fprintf(yyout, "%-60s %-30s %-15i\n", "FIN PARENTESIS: (\")", yytext , yylineno);}

"[" {fprintf(yyout, "%-60s %-30s %-15i\n", "INICIO CORCHETE: (\")", yytext , yylineno);}
"]" {fprintf(yyout, "%-60s %-30s %-15i\n", "FIN CORCHETE: (\")", yytext , yylineno);}

"{" {fprintf(yyout, "%-60s %-30s %-15i\n", "INICIO LLAVE: (\")", yytext , yylineno);}
"}" {fprintf(yyout, "%-60s %-30s %-15i\n", "FIN LLAVE: (\")", yytext , yylineno);}

"?" {fprintf(yyout, "%-60s %-30s %-15i\n", "CONDICION: (\")", yytext , yylineno);}

{reservadas} {fprintf(yyout, "%-60s %-30s %-15i\n", "PALABRA RESERVADA: (\")", yytext , yylineno);}

{booleanas} {fprintf(yyout, "%-60s %-30s %-15i\n", "PALABRA BOOLEANA: (\")", yytext , yylineno);}

(("//")|("#")).*\n {fprintf(yyout, "%-60s %-30s %-15i\n", "COMENTARIO DE UNA LINEA: (\")", yytext , yylineno);}

"/*" {BEGIN comentario; fprintf(yyout, "%-60s %-30s %-15i\n", "INICIO COMENTARIO: (\")", yytext , yylineno);}
<comentario>"*/" {BEGIN INITIAL; fprintf(yyout, "%-60s %-30s %-15i\n", "FIN COMENTARIO: (\")", yytext , yylineno);}
<comentario>.|\n {fprintf(yyout, "%-60s %-30s %-15i\n", "CONTENIDO DE COMENTARIO: (\")", yytext , yylineno);}

{variable} {fprintf(yyout, "%-60s %-30s %-15i\n", "VARIABLE: (\")", yytext , yylineno);}

\"[^\"]*\" {fprintf(yyout, "%-60s %-30s %-15i\n", "CADENA: (\")", yytext , yylineno);}
\'[^\']*\' {fprintf(yyout, "%-60s %-30s %-15i\n", "CADENA: (\")", yytext , yylineno);}

[+-]?{digitos} {fprintf(yyout, "%-60s %-30s %-15i\n", "NUMERO ENTERO: (\")", yytext , yylineno);}
[+-]?{digitos}(\.{digitos})? {fprintf(yyout, "%-60s %-30s %-15i\n", "NUMERO DECIMAL: (\")", yytext , yylineno);}

.|\n {}

%%
