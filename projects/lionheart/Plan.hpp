#ifndef LIONHEART_PLAN_HPP
#define LIONHEART_PLAN_HPP

#include "Map.hpp"
#include "Action.hpp"
namespace lionheart
{
  class Paths
  {

  };
  class Plan
  {
  public:
    Plan(Unit const& self,
         std::vector<std::shared_ptr<lionheart::Unit>> const& allies,
         std::vector<std::shared_ptr<lionheart::Unit>> const& enemies);
    Action attackEnemy();
    Action moveToEnemy();
    Action moveToEnemyCrown();
    Action moveToAllyCrown();
    Action moveToLocation(int row,int col);
  };
}
#endif
