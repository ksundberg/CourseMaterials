%{
#include <iostream>
#include <map>

#include "symbol_table.hpp"

extern int yylex();
void yyerror(const char*);
%}

%union
{
float val;
char* id;
}

%token ADD
%token SUB
%token MULT
%token DIV
%token OPEN
%token CLOSE
%token DONE
%token NUMBER
%token ID
%token EQUAL
%token LET

%type <val> NUMBER
%type <val> Expression
%type <val> Factor
%type <val> Term
%type <id> ID

%%

StatementList : StatementList Statement{}
              | {};
Statement : Expression DONE {std::cout << $1 << std::endl;}
          | LET ID EQUAL Expression DONE{symbol_table.store($2,$4);delete($2);}
          | DONE{};
Expression : Expression ADD Term {$$ = $1 + $3;}
           | Expression SUB Term {$$ = $1 - $3;}
           | Term {$$ = $1;};

Term : Term MULT Factor { $$ = $1 * $3;}
     | Term Factor { $$ = $1 * $2;}
     | Term DIV Factor { $$ = $1 / $3;}
     | Factor {$$ = $1;}
     ;
Factor : OPEN Expression CLOSE {$$ = $2;}
       | NUMBER {$$ = $1;}
       | ID {$$ = symbol_table.lookup($1);delete($1);}
       ;

%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}

