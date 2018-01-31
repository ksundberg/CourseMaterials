%{
#include <iostream>
extern int yylex();
void yyerror (char const *s) 
{
	std::fprintf (stderr, "%s\n", s);
}
%}

%union
{
float val;
}

%token ADD
%token SUB
%token MULT
%token DIV
%token OPEN
%token CLOSE
%token DONE
%token NUMBER

%type <val> NUMBER
%type <val> Expression
%type <val> Factor
%type <val> Term

%%

Statement : Expression DONE {std::cout << $1 << std::endl;};
Expression : Expression ADD Term {$$ = $1 + $3;}
           | Expression SUB Term {$$ = $1 - $3;}
           | Term {$$ = $1;};

Term : Term MULT Factor { $$ = $1 * $3;}
     | Term DIV Factor { $$ = $1 / $3;}
     | Factor {$$ = $1;}
     ;
Factor : OPEN Expression CLOSE {$$ = $2;}
       | NUMBER {$$ = $1;}
       ;

%%

