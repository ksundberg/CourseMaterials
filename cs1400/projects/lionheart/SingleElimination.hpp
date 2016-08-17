#ifndef LIONHEART_SINGLE_ELIMINATION
#define LIONHEART_SINGLE_ELIMINATION

#include "Tournament.hpp"
#include "Game.hpp"
#include "Display.hpp"
#include "Player.hpp"

namespace lionheart
{
  class SingleElimination : public Tournament
  {
  public:
    SingleElimination(std::vector<std::shared_ptr<Player>> players, std::shared_ptr<Display> display):players(players),display(display){}
    virtual std::vector<std::shared_ptr<Player>> run();
  private:
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Display> display;
  };
}

#endif

