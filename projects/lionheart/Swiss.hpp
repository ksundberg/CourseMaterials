#ifndef LIONHEART_SWISS_ROUNDS
#define LIONHEART_SWISS_ROUNDS

#include "Tournament.hpp"
#include "Game.hpp"
#include "Display.hpp"
#include "Player.hpp"

namespace lionheart
{
  class Swiss : public Tournament
  {
  public:
    Swiss(std::vector<std::shared_ptr<Player>> players, std::shared_ptr<Display> display):players(players),display(display){}
    virtual std::vector<std::shared_ptr<Player>> run();
  private:
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Display> display;
  };
}

#endif

