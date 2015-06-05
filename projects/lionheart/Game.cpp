#include "Game.hpp"
#include <algorithm>
#include "Crown.hpp"
#include "Knight.hpp"
#include "Archer.hpp"
#include "Infantry.hpp"

namespace
{
  const int NUM_KNIGHTS = 6;
  const int NUM_ARCHERS = 8;
  const int NUM_INFANTRY = 15;

template <typename UnitType>
std::shared_ptr<lionheart::Unit>
createUnit(std::shared_ptr<lionheart::Player> const &player,
           std::shared_ptr<lionheart::Map const> const &map,
           lionheart::StartBox const &box,
           lionheart::Direction const d)
    {
      auto coords = player->placeUnit(box);
      auto loc = map->at(coords.first,coords.second);
      //make sure location is in start box
      if(!loc) return nullptr;
      if(loc.col < box.minCol) return nullptr;
      if(loc.col > box.maxCol) return nullptr;
      if(loc.row < box.minRow) return nullptr;
      if(loc.row > box.maxRow) return nullptr;
      return std::make_shared<UnitType>(loc,d);
    }

    void addUnit(std::vector<std::shared_ptr<lionheart::Unit>> &units,
                 std::shared_ptr<lionheart::Unit> &u)
    {
      // check that no other unit is already in location
      auto result = std::find_if(std::begin(units),
                                 std::end(units),
                                 [&](std::shared_ptr<lionheart::Unit> const &a)
      { return a->getLocation() == u->getLocation(); });
      if (result == std::end(units))
      {
        units.push_back(u);
      }
    }
}
std::shared_ptr<lionheart::Player> lionheart::Game::winner() const
{
  if(state!=Game::NOT_STARTED) return nullptr;
  //is one crown dead?
  if (!crown[0]->isAlive() && crown[1]->isAlive())
  {
    return player[1];
  }if (!crown[1]->isAlive() && crown[0]->isAlive())
  {
    return player[0];
  }
  //are both gone?
  if(!crown[0]->isAlive() && !crown[1]->isAlive())
  {
    return nullptr;
  }
  //is one alone?
  if(units[0].size() == 1) return player[1];
  if(units[1].size() == 1) return player[0];
  //tie game
  return nullptr;
}

std::shared_ptr<lionheart::Player> lionheart::Game::tiebreaker() const
{
  // who has the most remaining hits?
  auto sumHp = [](int total, std::shared_ptr<Unit> const &u)
  { return total + u->getHp(); };
  auto p0hits = std::accumulate(std::begin(units[0]),std::end(units[0]),0,sumHp);
  auto p1hits = std::accumulate(std::begin(units[1]),std::end(units[1]),0,sumHp);
  if(p0hits < p1hits) return player[1];
  if(p1hits < p0hits) return player[0];
}
bool lionheart::Game::canContinue() const
{
  //If either crown is dead the game is over
  for(auto&&c:crown)
  {
    if(!c->isAlive()) return false;
  }
  //If either army is gone the game is over (crown doesn't count)
  for(auto&&u:units)
  {
    if(u.size() < 2) return false;
  }
}

void lionheart::Game::start()
{
  auto boxes = map->getBoxes();
  std::array<Direction,2> facing = {Direction::EAST,Direction::WEST};
  for(int i=0;i<2;++i)
  {
    // Create crowns

    crown[i] = createUnit<Crown>(player[i], map, boxes[i], facing[i]);
    if (!crown[i])
    {
      // invalid crown placement, put in middle
      auto row = (boxes[i].minRow + boxes[i].maxRow) / 2;
      auto col = (boxes[i].minCol + boxes[i].maxCol) / 2;
      crown[i] = std::make_shared<Crown>(map->at(row, col), facing[i]);
    }
    units[i].push_back(crown[i]);
    // Create knights
    for (int j = 0; j < NUM_KNIGHTS; ++j)
    {
      auto knight = createUnit<Knight>(player[i], map, boxes[i], facing[i]);
      addUnit(units[i], knight);
    }
    // Create archers
    for (int j = 0; j < NUM_ARCHERS; ++j)
    {
      auto archer = createUnit<Archer>(player[i], map, boxes[i], facing[i]);
      addUnit(units[i], archer);
    }
    // Create infantry
    for (int j = 0; j < NUM_INFANTRY; ++j)
    {
      auto infantry = createUnit<Infantry>(player[i], map, boxes[i], facing[i]);
      addUnit(units[i], infantry);
    }
  }
  state = IN_PROGRESS;
  turns = 0;
}

void lionheart::Game::doTurn()
{
  ++turns;
  //determine random turn order
  thread_local std::random_device rd;
  thread_local std::mt19937 engine(rd());
  for(auto&& u:units)
  {
    std::shuffle(std::begin(u), std::end(u), engine);
  }

  auto u0 = std::begin(units[0]);
  auto u1 = std::begin(units[1]);
  while (u0 != std::end(units[0]) && u1 != std::end(units[1]))
  {
    auto doAction = [&](Unit &unit,
                       std::shared_ptr<Player> p,
                       std::vector<std::shared_ptr<Unit>> &allies,
                       std::vector<std::shared_ptr<Unit>> &enemies)
    {
        if (unit.isAlive())
        {
          // get recommendations
          auto action = p->recommendAction(unit);
          // execute valid recommendations
          action(map, unit, allies,enemies);
        }
    };
    // do player 0 unit
    if (u0 != std::end(units[0]))
    {
      auto unit = *u0;
      doAction(*unit,player[0],units[0],units[1]);
      ++u0;
    }
    // do player 1 unit
    if (u1 != std::end(units[1]))
    {
      auto unit = *u1;
      doAction(*unit,player[1],units[1],units[0]);
      ++u1;
    }
  }
  // remove the fallen
  for (auto &&u : units)
  {
    u.erase(std::remove_if(std::begin(u),
                              std::end(u),
                              [](std::shared_ptr<Unit> const &unit)
    { return !unit->isAlive(); }),
               std::end(u));
  }
  if(!canContinue())
  {
    state = FINISHED;
  }
}
