#ifndef LIONHEART_ACTION_HPP
#define LIONHEART_ACTION_HPP

#include "Map.hpp"
#include "Unit.hpp"
#include "Crown.hpp"
#include "Knight.hpp"
#include "Archer.hpp"
#include "Infantry.hpp"
namespace lionheart
{
struct Placement
{
  int row;
  int col;
};
class ActionImpl
{
};
class MoveImpl
{
};
class TurnImpl
{
};
class AttackImpl
{
};
class WaitImpl
{
};
class Action
{
public:
  std::unique_ptr<ActionImpl> pImpl;
  void operator()(std::shared_ptr<const Map> const & map,
                  Unit & actor,
                  std::vector<std::shared_ptr<Unit>> & allies,
                  std::vector<std::shared_ptr<Unit>> & enemies){}
};
Action turn(Direction d);
Action move(int distance);
Action wait();
Action attack();
}
#endif
