#include "Gauntlet.hpp"

std::vector<std::shared_ptr<lionheart::Player>> lionheart::Gauntlet::run()
{
  if(!keyPlayer) return {};
  auto fortMap = lionheart::makeMap("forts.in");
  auto infantryPaths = std::make_shared<lionheart::Paths>(fortMap, 1);
  auto mountedPaths = std::make_shared<lionheart::Paths>(fortMap, 5);
  for(auto&& p:players)
  {
      lionheart::Game game(keyPlayer, p, fortMap, infantryPaths, mountedPaths);
      game.start();

      if (display) {
        display->setOutput(keyPlayer->getBlazon().name+"-"+p->getBlazon().name);
        display->show(game.getReport(), keyPlayer->getBlazon(), p->getBlazon());
      }
      for (auto i = 0; i < 200; ++i)
      {
        game.doTurn(display);
        if (display) {
          display->show(game.getReport(), keyPlayer->getBlazon(), p->getBlazon());
        }
        if (!game.canContinue()) break;
      }
  }
  return {};
}
