#include "SingleElimination.hpp"

std::vector<std::shared_ptr<lionheart::Player>> lionheart::SingleElimination::run()
{
  std::vector<std::shared_ptr<Player>> winners;
  auto fortMap = lionheart::makeMap("forts.in");
  auto infantryPaths = std::make_shared<lionheart::Paths>(fortMap, 1);
  auto mountedPaths = std::make_shared<lionheart::Paths>(fortMap, 5);
  while (players.size() > 1)
  {
    winners.clear();
    while (players.size() > 1)
    {
      auto p1 = players.back();
      players.pop_back();
      auto p2 = players.back();
      players.pop_back();

      lionheart::Game game(p1, p2, fortMap, infantryPaths, mountedPaths);
      game.start();

      if (display) {
        display->show(game.getReport(), p1->getBlazon(), p2->getBlazon());
      }
      for (auto i = 0; i < 200; ++i)
      {
        game.doTurn();
        if (display) {
          display->show(game.getReport(), p1->getBlazon(), p2->getBlazon());
        }
        if (!game.canContinue()) break;
      }
      auto winner = game.winner();
      if (winner) {
        winners.push_back(winner);
      }
      else
      {
        auto tie = game.tiebreaker();
        if (tie) {
          winners.push_back(tie);
        }
      }
    }
    std::swap(players, winners);
  }
  return players;
}
