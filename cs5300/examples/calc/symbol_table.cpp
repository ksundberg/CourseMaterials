#include "symbol_table.hpp"
#include <iostream>

SymbolTable symbol_table;

SymbolTable::Expr SymbolTable::lookup(std::string id)
{
  for(auto cur = variables.rbegin();cur!=variables.rend();cur++)
  {
    auto found = cur->find(id);
    if(found != cur->end())
    {
      return found->second;
    }
  }
  std::cerr << id << " not defined\n";
  return {};
}

void SymbolTable::store(std::string id,Expr e)
{
  //Find on top level - error if found
  auto top = variables.rbegin();
  auto found = top->find(id);
  if(found != top->end())
  {
    std::cerr << id << " already defined\n";
    return;
  }
  //Insert in top level
  top->emplace(id,e);
}

void SymbolTable::enter_scope()
{
  variables.emplace_back();
}

void SymbolTable::exit_scope()
{
  variables.pop_back();
}
