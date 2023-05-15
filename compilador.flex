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
digitos [0-9]+
variable (_*{letras}|_+{digitos})({letras}|{digitos}|_)*

%%

{digitos} yylval = atoi(yytext); return NUMERO;
{variable} yylval = atoi(yytext); return VARIABLE;

"+" return '+';
"-" return '-';
"*" return '*';
"/" return '/';
"^" return '^';

\n {++yylineno; }
. {}

%%