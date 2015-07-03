#include "Game.hpp"
#include "Plan.hpp"
#include "SingleElimination.hpp"
#include "AnsiDisplay.hpp"
#include "Player/SittingDuck.hpp"
#include "Player/Goldfish.hpp"
#include "Player/ChargingBadger.hpp"
#include "Player/WildBoar.hpp"
#include "Player/SnappingTurtle.hpp"
#include "Player/CirclingShark.hpp"
#include "Player/CrouchingTiger.hpp"
#include "Player/HiddenDragon.hpp"

int main(void)
{
  auto display = std::make_shared<lionheart::AnsiDisplay>();
  std::vector<std::shared_ptr<lionheart::Player>> players;
  players.push_back(std::make_shared<lionheart::ChargingBadger>());
  players.push_back(std::make_shared<lionheart::SittingDuck>());
  players.push_back(std::make_shared<lionheart::WildBoar>());
  players.push_back(std::make_shared<lionheart::Goldfish>());
  players.push_back(std::make_shared<lionheart::SnappingTurtle>());
  players.push_back(std::make_shared<lionheart::CirclingShark>());
  players.push_back(std::make_shared<lionheart::CrouchingTiger>());
  players.push_back(std::make_shared<lionheart::HiddenDragon>());
  lionheart::SingleElimination t(players,display);
  t.run();
}
