#include "Swiss.hpp"
#include "SingleElimination.hpp"
#include <map>
#include <cmath>

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

struct GameResult
{
  std::shared_ptr<lionheart::Player> winner;
  std::shared_ptr<lionheart::Player> loser;
  bool draw;
};

GameResult playGame(std::shared_ptr<lionheart::Player> p1,
                    std::shared_ptr<lionheart::Player> p2,
                    std::shared_ptr<const lionheart::Map> map,
                    std::shared_ptr<const lionheart::Paths> infantryPaths,
                    std::shared_ptr<const lionheart::Paths> mountedPaths,
                    std::shared_ptr<lionheart::Display> display)
{
  lionheart::Game game(p1, p2, map, infantryPaths, mountedPaths);
  game.start();
  std::cout << p1->getBlazon().name << " vs. " << p2->getBlazon().name << ": ";
  if (display) {
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
  GameResult result;
  result.winner = game.winner();
  result.loser = game.loser();
  if(result.winner)
  {
    std::cout << result.winner->getBlazon().name << " wins!" << std::endl;
    result.draw = false;
  }
  else
  {
    result.draw = true;
    std::cout << "draw" << std:: endl;
  }
  return result;
}

std::vector<std::shared_ptr<lionheart::Player>> lionheart::Swiss::run()
{
  std::map<Record,std::vector<std::shared_ptr<Player>>> oldBrackets;
  auto fortMap = lionheart::makeMap("forts.in");
  auto infantryPaths = std::make_shared<lionheart::Paths>(fortMap, 1);
  auto mountedPaths = std::make_shared<lionheart::Paths>(fortMap, 5);
  oldBrackets[Record()] = players;
  auto rounds = static_cast<int>(std::log2(players.size()) + 1);
  for(auto round=0;round<rounds;++round)
  {
    std::map<Record, std::vector<std::shared_ptr<Player>>> brackets;
    std::vector<std::pair<Record, std::shared_ptr<Player>>> byes;
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

        if (display)
        {
          display->setOutput(std::string("round") + std::to_string(round) + "-" +
                             p1->getBlazon().name + "-" + p2->getBlazon().name);
        }
        auto result = playGame(p1,p2,fortMap,infantryPaths,mountedPaths,display);

        if (!result.draw) {
          brackets[win].push_back(result.winner);
          brackets[loss].push_back(result.loser);
        }
        else
        {
          brackets[draw].push_back(p1);
          brackets[draw].push_back(p2);
        }
      }
      while(!b.second.empty())
      {
        byes.push_back(std::make_pair(record,b.second.back()));
        b.second.pop_back();
      }
    }
    while(byes.size() > 1)
    {

        auto p1 = byes.back();
        byes.pop_back();

        auto p2 = byes.back();
        byes.pop_back();

        if (display)
        {
          display->setOutput(std::string("round") + std::to_string(round) + "-" +
                             p1.second->getBlazon().name + "-" +
                             p2.second->getBlazon().name);
        }
        auto result = playGame(p1.second,p2.second,fortMap,infantryPaths,mountedPaths,display);
        if(result.draw)
        {
          p1.first.draw+=1;
          brackets[p1.first].push_back(p1.second);
          p2.first.draw+=1;
          brackets[p2.first].push_back(p2.second);
        }
        else
        {
          if (result.winner == p1.second) {
            p1.first.win += 1;
            brackets[p1.first].push_back(p1.second);
            p2.first.loss += 1;
            brackets[p2.first].push_back(p2.second);
          }
          else
          {
            p1.first.loss += 1;
            brackets[p1.first].push_back(p1.second);
            p2.first.win += 1;
            brackets[p2.first].push_back(p2.second);
          }
        }
    }
    std::swap(brackets,oldBrackets);
    //Display round results

    std::cout << "Round " << round + 1 <<  " of " << rounds << std::endl;
    for(auto&& b:oldBrackets)
    {
      std::cout << "  Record (" << b.first.win << "-" << b.first.loss << "-" << b.first.draw << "):" << std::endl;
      for(auto&& p:b.second)
      {
        std::cout << "    " << p->getBlazon().name << std::endl;
      }
    }
  }
  std::cout << "Cut to top 8" << std::endl;
  auto best = oldBrackets.rbegin();
  std::vector<std::shared_ptr<lionheart::Player>> top8;
  while(top8.size() < 8)
  {
    top8.insert(top8.begin(),best->second.begin(),best->second.end());
    ++best;
  }
  for(auto&& p:top8)
    {
      std::cout << "     " << p->getBlazon().name << std::endl;
    }
  SingleElimination top8Tournament(top8,display);
  top8Tournament.run();
  


  return players;
}
