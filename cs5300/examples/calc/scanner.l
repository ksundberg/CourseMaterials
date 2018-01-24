%{
#include <cstdlib>

#include "parser.hpp"
%}

%%

"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"(" {return OPEN;}
")" {return CLOSE;}
"\n" {return DONE;}
";" {return DONE;}
[ \t] {}

[0-9]*\.[0-9]* {yylval.val = atof(yytext);return NUMBER;}
[0-9]+ {yylval.val = atof(yytext);return NUMBER;}

%%
