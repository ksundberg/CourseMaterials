#include "Game.hpp"
#include "Plan.hpp"
#include "SingleElimination.hpp"
#include "AnsiDisplay.hpp"
#include "Player/SittingDuck.hpp"
#include "Player/Goldfish.hpp"
#include "Player/ChargingBadger.hpp"
#include "Player/WildBoar.hpp"

int main(void)
{
  std::vector<std::shared_ptr<lionheart::Player>> players;
  players.push_back(std::make_shared<lionheart::ChargingBadger>());
  players.push_back(std::make_shared<lionheart::SittingDuck>());
  players.push_back(std::make_shared<lionheart::WildBoar>());
  players.push_back(std::make_shared<lionheart::Goldfish>());
  auto display = std::make_shared<lionheart::AnsiDisplay>();
  lionheart::SingleElimination t(players,display);
  t.run();
}
