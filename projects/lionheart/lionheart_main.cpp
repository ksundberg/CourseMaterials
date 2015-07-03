#include "Game.hpp"
#include "AnsiDisplay.hpp"
#include "Player/SittingDuck.hpp"
#include "Player/Goldfish.hpp"
#include "Player/ChargingBadger.hpp"
#include "Player/WildBoar.hpp"

int main(void)
{
  auto fortMap = lionheart::makeMap("forts.in");
  auto p1 = std::make_shared<lionheart::ChargingBadger>();
  auto p2 = std::make_shared<lionheart::WildBoar>();
  lionheart::Game game(p1,p2,fortMap);
  lionheart::AnsiDisplay display;
  game.start();
  display.show(game.getReport(),p1->getBlazon(),p2->getBlazon());
  for(auto i=0;i<200;++i)
  {
  game.doTurn();
  display.show(game.getReport(),p1->getBlazon(),p2->getBlazon());
  if (!game.canContinue()) break;
  }
  auto winner = game.winner();
  if(winner)
  {
  std::cout << winner->getBlazon().name << " wins!" << std::endl;
  }
  else
  {
    std::cout << "Tie game" << std::endl;
  }
  
}
