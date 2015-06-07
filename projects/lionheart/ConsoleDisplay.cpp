#include "ConsoleDisplay.hpp"
#include <iostream>

namespace
{
  void displayHeader(int length)
  {
    for(int i=0;i<=length;++i)
      std::cout << "-";
    std::cout << std::endl;
  }
}
void lionheart::ConsoleDisplay::show(lionheart::SituationReport const &report)
{
  if(report.things.empty())return;
  displayHeader(report.things[0].size());
  for(auto&& row:report.things)
  {
    std::cout << '|' ;
    for(auto&& thing:row)
    {
      switch(thing.type)
      {
        case SituationReport::ROCK: std::cout << 'X';break;
        case SituationReport::SPACE: std::cout << ' ';break;
        case SituationReport::ALLY:
                    break;
        case SituationReport::ENEMY:
                    break;

      }
    }
    std::cout << '|' << std::endl;
  }
  displayHeader(report.things[0].size());
}
