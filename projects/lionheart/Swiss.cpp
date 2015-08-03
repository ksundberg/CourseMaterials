#include "Swiss.hpp"
#include <map>

struct Record
{
  int win;
  int loss;
  int draw;
  Record() : win(0), loss(0), draw(0) {}
  int score() const { return win * 3 + draw; }
  int rounds() const { return win + loss + draw; };
};

bool operator<(Record const& a, Record const& b)
{
  if (a.rounds() == b.rounds()) {
    return a.score() < b.score();
  }
  return a.rounds() < b.rounds();
}

std::vector<std::shared_ptr<lionheart::Player>> lionheart::Swiss::run()
{
  std::map<Record,std::vector<std::shared_ptr<Player>>> oldBrackets;
  auto fortMap = lionheart::makeMap("forts.in");
  auto infantryPaths = std::make_shared<lionheart::Paths>(fortMap, 1);
  auto mountedPaths = std::make_shared<lionheart::Paths>(fortMap, 5);
  oldBrackets[Record()] = players;
  for(auto round=0;round<5;++round)
  {
    std::map<Record, std::vector<std::shared_ptr<Player>>> brackets;
    for(auto&& b:oldBrackets)
    {
      auto record = b.first;
      auto win = record;
      ++win.win;
      auto loss = record;
      ++loss.loss;
      auto draw = record;
      ++draw.draw;
      while (b.second.size() > 1)
      {
        auto p1 = b.second.back();
        b.second.pop_back();

        auto p2 = b.second.back();
        b.second.pop_back();

        lionheart::Game game(p1, p2, fortMap, infantryPaths, mountedPaths);
        game.start();

        if (display) {
          display->show(game.getReport(), p1->getBlazon(), p2->getBlazon());
        }
        for (auto i = 0; i < 200; ++i)
        {
          game.doTurn(display);
          if (display) {
            display->show(game.getReport(), p1->getBlazon(), p2->getBlazon());
          }
          if (!game.canContinue()) break;
        }
        auto winner = game.winner();
        if (winner) {
          brackets[win].push_back(winner);
          brackets[loss].push_back(game.loser());
        }
        else
        {
          brackets[draw].push_back(p1);
          brackets[draw].push_back(p2);
        }
      }
      //TODO deal with byes
    }
    std::swap(brackets,oldBrackets);
  }
  
  return players;
}
