#include "Game.hpp"
#include "AnsiDisplay.hpp"
#include "Player/SittingDuck.hpp"
#include "Player/Goldfish.hpp"

int main(void)
{
  auto fortMap = lionheart::makeMap("forts.in");
  auto p1 = std::make_shared<lionheart::SittingDuck>();
  auto p2 = std::make_shared<lionheart::Goldfish>();
  lionheart::Game game(p1,p2,fortMap);
  lionheart::AnsiDisplay display;
  game.start();
  display.show(game.getReport(),p1->getBlazon(),p2->getBlazon());
  game.doTurn();
  display.show(game.getReport(),p1->getBlazon(),p2->getBlazon());
}
