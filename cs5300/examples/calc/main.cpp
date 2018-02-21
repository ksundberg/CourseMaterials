#include "symbol_table.hpp"

extern int yyparse();

int main()
{
  symbol_table.enter_scope();
  yyparse();
};
