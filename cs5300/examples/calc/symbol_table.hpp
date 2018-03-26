#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <vector>
#include <map>

class SymbolTable
{
  public:
    using Expr = float;
    SymbolTable() = default;
    Expr lookup(std::string);
    void store(std::string,Expr);
    void enter_scope();
    void exit_scope();
  private:
    std::vector<std::map<std::string,Expr>> variables;
};

extern SymbolTable symbol_table;
#endif
