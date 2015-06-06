#include "Game.hpp"

int main(void)
{
  auto fortMap = lionheart::makeMap("fort.in");
  lionheart::Game game(nullptr,nullptr,fortMap);
}
