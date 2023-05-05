%{
#include <ctype.h>
#include <stdio.h>
%}

%token SUMA RESTA MULT DIV POT NUMERO
%start command
%%
command: aritmetico {printf(" El resultado es %d\n", $1); }
   ;

aritmetico: NUMERO SUMA NUMERO {$$ = $1 + $3; }
    | NUMERO RESTA NUMERO {$$ = $1 - $3; }
    | NUMERO MULT NUMERO {$$ = $1 * $3; }
    | NUMERO DIV NUMERO {$$ = $1 / $3; }
    | NUMERO POT NUMERO {$$ = $1 ^ $3; }
   ;


%%

main()
{ return yyparse();
}


yyerror()
{ 
} 
