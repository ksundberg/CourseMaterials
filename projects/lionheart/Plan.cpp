#include "Plan.hpp"

lionheart::Plan::Plan(Unit const& self,
                      std::vector<std::shared_ptr<lionheart::Unit>> const& allies,
                      std::vector<std::shared_ptr<lionheart::Unit>> const& enemies)
{
}

lionheart::Action lionheart::Plan::attackEnemy()
{
  //return an attack if legal

  //otherwise approach enemy
  return moveToEnemy();
}

lionheart::Action lionheart::Plan::moveToEnemy()
{
  return Action();
}

lionheart::Action lionheart::Plan::moveToEnemyCrown()
{
  return Action();
}

lionheart::Action lionheart::Plan::moveToAllyCrown()
{
  return Action();
}

lionheart::Action lionheart::Plan::moveToLocation(int row,int col)
{
  return Action();
}
