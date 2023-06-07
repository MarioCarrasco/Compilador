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
comentario \#[a-zA-Z0-9 ]*\n

%%

{digitos} {yylval.vInt = atoi(yytext); return NUMERO;}
{variable} {yylval.sVal = strdup(yytext); return VARIABLE;}



{comentario} {yylval.sVal = strdup(yytext); return COMENTARIO;}

"+" return '+';
"-" return '-';
"*" return '*';
"/" return '/';
"^" return '^';
"=" return '=';

\n|. {}

%%