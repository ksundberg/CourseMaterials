#include "SingleElimination.hpp"

std::vector<std::shared_ptr<lionheart::Player>> lionheart::SingleElimination::run()
{
  std::vector<std::shared_ptr<Player>> winners;
  auto fortMap = lionheart::makeMap("forts.in");
  auto infantryPaths = std::make_shared<lionheart::Paths>(fortMap, 1);
  auto mountedPaths = std::make_shared<lionheart::Paths>(fortMap, 5);
  auto round = 0;
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

      std::cout << p1->getBlazon().name << " vs. " << p2->getBlazon().name
                << ": ";
      if (display) {
        display->setOutput(std::string("se") + p1->getBlazon().name + "-" +
                           p2->getBlazon().name);

        display->show(game.getReport(), p1->getBlazon(), p2->getBlazon());
      }
      for (auto i = 0; i < 200; ++i)
      {
        game.doTurn(nullptr);
        if (display) {
          display->show(game.getReport(), p1->getBlazon(), p2->getBlazon());
        }
        if (!game.canContinue()) break;
      }
      auto winner = game.winner();
      if (winner) {
        winners.push_back(winner);
        std::cout << winner->getBlazon().name << " wins!" << std::endl;
      }
      else
      {
        auto tie = game.tiebreaker();
        if (tie) {
        std::cout << tie->getBlazon().name << " wins by tie break!" << std::endl;
          winners.push_back(tie);
        }
        else
        {
          winners.push_back(p1);
          std::cout << p1->getBlazon().name << " moves on." << std::endl;
        }
      }
    }
    
    std::swap(players, winners);
    ++round;
    std::cout << "Single Elimination Round " << round << std::endl;
    for(auto&& p:players)
    {
      std::cout << "     " << p->getBlazon().name << std::endl;
    }
  }
  return players;
}
