%{
#include <ctype.h>
#include <stdio.h>
%}

%token NUMERO
%start command
%%
command: exp {printf(" El resultado es %d\n", $1); }
   ;

exp: exp '+' term {$$ = $1 + $3; }
   | exp '-' term {$$ = $1 - $3; }
   | term {$$ = $1; }
   | exp var term {$$ = $1 - $3; }
   ;

term: term '*' factor {$$ = $1 * $3; }
    | factor {$$ = $1; }
    ;
factor: NUMERO {$$ = $1; }
    | '(' exp ')' {$$ = $2; }
    ;
%%

main()
{ return yyparse();
}


yyerror()
{ 
} 
