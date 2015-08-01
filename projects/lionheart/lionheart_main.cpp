#include "Game.hpp"
#include "Plan.hpp"
#include "SingleElimination.hpp"
#include "AnsiDisplay.hpp"
#include "getPlayers.hpp"

int main(void)
{
  auto display = std::make_shared<lionheart::AnsiDisplay>();
  auto players = lionheart::getPlayers();
  lionheart::SingleElimination t(players,display);
  t.run();
}
