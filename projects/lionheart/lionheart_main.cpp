#include "Game.hpp"
#include "ConsoleDisplay.hpp"

int main(void)
{
  auto fortMap = lionheart::makeMap("forts.in");
  lionheart::Game game(nullptr,nullptr,fortMap);
  lionheart::ConsoleDisplay display;
  display.show(game.getReport());
}
