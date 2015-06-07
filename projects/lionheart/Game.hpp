#ifndef LIONHEART_GAME_HPP
#define LIONHEART_GAME_HPP

#include "Map.hpp"
#include "Unit.hpp"
#include "Player.hpp"
#include <memory>
#include <vector>

namespace lionheart
{
  class Game
  {
    public:
      enum State
      {
        NOT_STARTED,
        IN_PROGRESS,
        FINISHED
      };
      Game(std::shared_ptr<Player> p1,
           std::shared_ptr<Player> p2,
           std::shared_ptr<const Map> map)
          : map(map)
          , player({ p1, p2 })
          , units()
          , crown()
          , state(NOT_STARTED)
      {
      }
      std::shared_ptr<Player> winner()const;
      std::shared_ptr<Player> tiebreaker()const;
      State getState()const{return state;}
      bool canContinue()const;
      void start();
      void doTurn();
      lionheart::SituationReport getReport() const;
    private:
      std::shared_ptr<const Map> map;
      std::array<std::shared_ptr<Player>,2> player;
      std::array<std::vector<std::shared_ptr<Unit>>,2> units;
      std::array<std::shared_ptr<Unit>,2> crown;
      State state;
      int turns;
  };
}

#endif

