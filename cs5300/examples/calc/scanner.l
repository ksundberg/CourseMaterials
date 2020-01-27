%{
#include <cstdlib>

#include "parser.hpp"
%}

%option noyywrap

%%

"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"(" {return OPEN;}
")" {return CLOSE;}
"\n" {return DONE;}
";" {return DONE;}
"=" {return EQUAL;}
"==" {return EQUAL;}
":=" {return EQUAL;}
"LET" {return LET;}
[a-z] {yylval.id = strdup(yytext);return ID;}
_[a-zA-Z]+ {yylval.id = strdup(yytext+1);return ID;}
[ \t] {}

[0-9]*\.[0-9]* {yylval.val = atof(yytext);return NUMBER;}
[0-9]+ {yylval.val = atof(yytext);return NUMBER;}

%%
