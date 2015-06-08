#include "Game.hpp"
#include "ConsoleDisplay.hpp"
#include "Player/SittingDuck.hpp"

int main(void)
{
  auto fortMap = lionheart::makeMap("forts.in");
  auto p1 = std::make_shared<lionheart::SittingDuck>();
  auto p2 = std::make_shared<lionheart::SittingDuck>();
  lionheart::Game game(p1,p2,fortMap);
  lionheart::ConsoleDisplay display;
  display.show(game.getReport(),p1->getBlazon(),p2->getBlazon());
  game.start();
  display.show(game.getReport(),p1->getBlazon(),p2->getBlazon());
}
