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
inline Action turn(Direction d){return Action();}
inline Action move(int distance){return Action();}
inline Action wait(){return Action();}
inline Action attack(){return Action();}
}
#endif
