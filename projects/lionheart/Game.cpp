#include "Game.hpp"
#include <algorithm>
#include "Crown.hpp"
#include "Knight.hpp"
#include "Archer.hpp"
#include "Infantry.hpp"
#include "SituationReport.hpp"
#include <numeric>
#include <random>

namespace
{
  const int NUM_KNIGHTS = 6;
  const int NUM_ARCHERS = 8;
  const int NUM_INFANTRY = 15;

  lionheart::SituationReport
  buildReport(std::shared_ptr<lionheart::Map const> const &map,
              int turns,
              std::vector<std::shared_ptr<lionheart::Unit>> const &allies,
              std::vector<std::shared_ptr<lionheart::Unit>> const &enemies)
  {
    lionheart::SituationReport report;
    report.turns = turns;
    // convert map to report
    report.things.reserve(map->rows());
    for (int i = 0; i < static_cast<int>(map->rows()); ++i)
    {
      report.things.emplace_back(map->cols());
      for (int j = 0; j < static_cast<int>(map->cols()); ++j)
      {
        auto tile = (*map)[map->at(i, j)];
        // default constructed things are rocks, so just clear out the spaces
        if (tile == lionheart::Tile::SPACE)
        {
          report.things[i][j].type = lionheart::SituationReport::SPACE;
        }
      }
    }

    //add ally notations

    for(auto&& ally:allies)
    {
      auto l = ally->getLocation();
      report.things[l.row][l.col] = lionheart::SituationReport::Thing(
          ally, lionheart::SituationReport::ALLY);
    }
    //add enemy notations
    for(auto&& enemy:enemies)
    {
      auto l = enemy->getLocation();
      report.things[l.row][l.col] = lionheart::SituationReport::Thing(
          enemy, lionheart::SituationReport::ENEMY);
    }
    return report;
  }

  template <typename UnitType>
  std::shared_ptr<lionheart::Unit> createUnit(int id,
                                              std::shared_ptr<lionheart::Player> const& player,
                                              std::shared_ptr<lionheart::Map const> const& map,
                                              std::vector<std::shared_ptr<lionheart::Unit>> const& units,
                                              lionheart::StartBox const& box,
                                              lionheart::Direction const d)
    {
      auto coords = player->placeUnit(UnitType::type, box, buildReport(map,0,units,std::vector<std::shared_ptr<lionheart::Unit>>()));
      auto loc = map->at(coords.row,coords.col);
      //make sure location is in start box
      if(!loc) return nullptr;
      if(loc.col < box.minCol) return nullptr;
      if(loc.col > box.maxCol) return nullptr;
      if(loc.row < box.minRow) return nullptr;
      if(loc.row > box.maxRow) return nullptr;
      return std::make_shared<UnitType>(id,loc,d);
    }

    void addUnit(std::vector<std::shared_ptr<lionheart::Unit>> &units,
                 std::shared_ptr<lionheart::Unit> &u)
    {
      if(!u) return;
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
  if(state!=Game::FINISHED) return nullptr;
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

std::shared_ptr<lionheart::Player> lionheart::Game::loser() const
{
  if(state!=Game::FINISHED) return nullptr;
  //is one crown dead?
  if (!crown[0]->isAlive() && crown[1]->isAlive())
  {
    return player[0];
  }if (!crown[1]->isAlive() && crown[0]->isAlive())
  {
    return player[1];
  }
  //are both gone?
  if(!crown[0]->isAlive() && !crown[1]->isAlive())
  {
    return nullptr;
  }
  //is one alone?
  if(units[0].size() == 1) return player[0];
  if(units[1].size() == 1) return player[1];
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
  return nullptr;
}
bool lionheart::Game::canContinue() const
{
  //If either crown is dead the game is over
  for (auto&& c : crown)
  {
    if (!c->isAlive()) {
      return false;
    }
  }
  //If either army is gone the game is over (crown doesn't count)
  for(auto&&u:units)
  {
    if (u.size() < 2) {
      return false;
    }
  }
  return true;
}

void lionheart::Game::start()
{
  auto boxes = map->getBoxes();
  std::array<Direction,2> facing = {{Direction::EAST,Direction::WEST}};
  for(int i=0;i<2;++i)
  {
    // Create crowns

    crown[i] = createUnit<Crown>(0,player[i], map, units[i],boxes[i], facing[i]);
    if (!crown[i])
    {
      // invalid crown placement, put in middle
      auto row = (boxes[i].minRow + boxes[i].maxRow) / 2;
      auto col = (boxes[i].minCol + boxes[i].maxCol) / 2;
      crown[i] = std::make_shared<Crown>(0,map->at(row, col), facing[i]);
    }
    units[i].push_back(crown[i]);
    // Create knights
    for (int j = 0; j < NUM_KNIGHTS; ++j)
    {
      auto knight = createUnit<Knight>(j+1,player[i], map,units[i], boxes[i], facing[i]);
      addUnit(units[i], knight);
    }
    // Create archers
    for (int j = 0; j < NUM_ARCHERS; ++j)
    {
      auto archer = createUnit<Archer>(NUM_KNIGHTS+j+1,player[i], map,units[i], boxes[i], facing[i]);
      addUnit(units[i], archer);
    }
    // Create infantry
    for (int j = 0; j < NUM_INFANTRY; ++j)
    {
      auto infantry = createUnit<Infantry>(
        NUM_KNIGHTS + NUM_ARCHERS  + j + 1, player[i], map, units[i], boxes[i], facing[i]);
      addUnit(units[i], infantry);
    }
  }
  state = IN_PROGRESS;
  turns = 0;
}

void lionheart::Game::doTurn(std::shared_ptr<Display> display)
{
  ++turns;
  //determine random turn order
  static std::random_device rd;
  static std::mt19937 engine(rd());
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
                       std::vector<std::shared_ptr<Unit>> &enemies)->bool
    {
        if (unit.isAlive())
        {
          std::shared_ptr<const Paths> paths = nullptr;
          if(unit.getMoveSpeed() == 5)
          {
            paths = mountedPaths;
          }
          else
          {
            paths = infantryPaths;
          }
          // get recommendations
          auto action = p->recommendAction(unit, buildReport(map, turns, allies, enemies), Plan(unit, allies, enemies,paths));
          // execute valid recommendations
          return action(map, unit, allies,enemies);
        }
		return false;
    };
    // do player 0 unit
    if (u0 != std::end(units[0]))
    {
      auto unit = *u0;
      auto result = doAction(*unit,player[0],units[0],units[1]);
      ++u0;

      if(display&&result)
      {
        display->show(getReport(),player[0]->getBlazon(),player[1]->getBlazon());
      }
    }
    // do player 1 unit
    if (u1 != std::end(units[1]))
    {
      auto unit = *u1;
      auto result = doAction(*unit,player[1],units[1],units[0]);
      ++u1;

      if(display&&result)
      {
        display->show(getReport(),player[0]->getBlazon(),player[1]->getBlazon());
      }
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

lionheart::SituationReport lionheart::Game::getReport()const
{
  return buildReport(map,turns,units[0],units[1]);
}
