#include "AnsiDisplay.hpp"
#include <iostream>
#include <random>
#include <string>

namespace
{
  void displayHeader(int length)
  {
    for(int i=0;i<=length*3+1;++i)
      std::cout << "-";
    std::cout << std::endl;
  }

  void displayRock()
  {
    std::cout << "\033[31m";
    std::cout << "/-\\";
  }

  void displaySpace()
  {
    static std::random_device rd;
    static std::mt19937 engine(rd());
    const int SIZE = 6;
    std::uniform_int_distribution<> die(0, SIZE-1);

    const char c[SIZE] = { ',', '.', '~', '`', '"', '\'' };
    std::cout << "\033[32m";
    for(int i=0;i<3;++i)
    {
      auto r = die(engine);
      std::cout << c[r];
    }
  }

  char displayType(lionheart::UnitType type)
  {
    switch (type)
    {
    case lionheart::CROWN:
      return '*';
    case lionheart::KNIGHT:
      return 'k';
    case lionheart::ARCHER:
      return 'a';
    case lionheart::INFANTRY:
      return 'i';
    default:
      break;
    }
    return '.';
  }

  char displayDirection(lionheart::Direction dir)
  {
    switch (dir)
    {
    case lionheart::Direction::NORTH:
      return '^';
    case lionheart::Direction::SOUTH:
      return 'v';
    case lionheart::Direction::WEST:
      return '<';
    case lionheart::Direction::EAST:
      return '>';
    default:
      break;
    }
    return '.';
  }

  void setUnitColor(lionheart::Blazon const& blazon)
  {
    switch(blazon.primary)
    {
    case lionheart::Color::ARGENT:
      std::cout << "\033[47;1m";
      break;
    case lionheart::Color::OR:
      std::cout << "\033[43;1m";
      break;
    case lionheart::Color::GULES:
      std::cout << "\033[41;1m";
      break;
    case lionheart::Color::VERT:
      std::cout << "\033[42;1m";
      break;
    case lionheart::Color::AZURE:
      std::cout << "\033[44;1m";
      break;
    case lionheart::Color::SABLE:
      std::cout << "\033[40;m";
      break;
    default:
      std::cout << "\033[0m";
    }
    switch (blazon.secondary)
    {
    case lionheart::Color::ARGENT:
      std::cout << "\033[37;1m";
      break;
    case lionheart::Color::OR:
      std::cout << "\033[33;1m";
      break;
    case lionheart::Color::GULES:
      std::cout << "\033[31;1m";
      break;
    case lionheart::Color::VERT:
      std::cout << "\033[32;1m";
      break;
    case lionheart::Color::AZURE:
      std::cout << "\033[34;1m";
      break;
    case lionheart::Color::SABLE:
      std::cout << "\033[30;1m";
      break;
    default:
      std::cout << "\033[0m";
    }
  }
  void displayUnit(lionheart::SituationReport::Thing const& thing,
                   lionheart::Blazon const& blazon)
  {
    if(thing.hp <= 0)
    {
      displaySpace();
    }
    else
    {
      setUnitColor(blazon);
      std::cout << displayType(thing.unit) << thing.hp << displayDirection(thing.direction);
      std::cout << "\033[0m";
    }
  }

  void displayThing(lionheart::SituationReport::Thing const& thing,
                    lionheart::Blazon const& ally,
                    lionheart::Blazon const& enemy)
  {
    switch (thing.type)
    {
    case lionheart::SituationReport::ROCK:
      displayRock();
      break;
    case lionheart::SituationReport::SPACE:
      displaySpace();
      break;
    case lionheart::SituationReport::ALLY:
      displayUnit(thing, ally);
      break;
    case lionheart::SituationReport::ENEMY:
      displayUnit(thing, enemy);
      break;
    }
  }
}

void lionheart::AnsiDisplay::show(lionheart::SituationReport const& report, Blazon const& p1, Blazon const& p2)
{
  if (report.things.empty()) return;
  std::cout << p1.name << "(" << report.getHp(SituationReport::ALLY) << ") v. "
            << p2.name << "(" << report.getHp(SituationReport::ENEMY) << ")"
            << " Turn : " << report.turns << std::endl;

  displayHeader(static_cast<int>(report.things[0].size()));
  for (auto&& row : report.things)
  {
    std::cout << '|';
    for (auto&& thing : row)
    {
      displayThing(thing, p1, p2);
    }
    // turn off color
    std::cout << "\033[0m";
    std::cout << '|' << std::endl;
  }
  displayHeader(static_cast<int>(report.things[0].size()));
  std::string buf;
  std::getline(std::cin,buf);
}
