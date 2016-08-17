#ifndef LIONHEART_GAUNTLET
#define LIONHEART_GAUNTLET

#include "Tournament.hpp"
#include "Game.hpp"
#include "Display.hpp"
#include "Player.hpp"

namespace lionheart
{
  class Gauntlet : public Tournament
  {
  public:
    Gauntlet(std::shared_ptr<Player> keyPlayer,
             std::vector<std::shared_ptr<Player>> players,
             std::shared_ptr<Display> display)
      : keyPlayer(keyPlayer),players(players), display(display)
    {
    }
    virtual std::vector<std::shared_ptr<Player>> run();
  private:
    std::shared_ptr<Player> keyPlayer;
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Display> display;
  };
}

#endif

