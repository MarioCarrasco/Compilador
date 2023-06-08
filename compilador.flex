%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include "compilador.tab.h"
%}

%option noyywrap
%option yylineno

%x comentario
%x bloquefuncion

letras [a-zA-Z]+
entero [0-9]+
decimal [0-9]*\.[0-9]*
variable (_*{letras}|_+{entero})({letras}|{entero}|_)*
comentario \#[a-zA-Z0-9 ]*\n
comentarioLineas [a-zA-Z0-9\n ]*

si "si"
fin "fin"
parentesisIzq [\(]
parentesisDer [\)]

mientras "mientras"

%%

{parentesisIzq} return '(';
{parentesisDer} return ')';
{si} {yylval.sVal = strdup(yytext); return SI;}
{fin} {yylval.sVal = strdup(yytext); return FIN;}
{mientras} {yylval.sVal = strdup(yytext); return MIENTRAS;}

{decimal} {yylval.fVal = atof(yytext); return DECIMAL;}
{entero} {yylval.vInt = atoi(yytext); return ENTERO;}
{variable} {yylval.sVal = strdup(yytext); return VARIABLE;}


\/\*{comentarioLineas}\*\/ {yylval.sVal = strdup(yytext); return COMENTARIOL;}
{comentario} {yylval.sVal = strdup(yytext); return COMENTARIO;}

"==" return IGUALIGUAL;
"<" return MENOR;
">" return MAYOR;
"!=" return DIFERENTE;

"+" return '+';
"-" return '-';
"*" return '*';
"/" return '/';
"^" return '^';
"=" return '=';

\n|. {}

%%