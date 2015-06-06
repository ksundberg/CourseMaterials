#ifndef LIONHEART_PLAYER_HPP
#define LIONHEART_PLAYER_HPP

#include <string>
#include "Map.hpp"
#include "Action.hpp"
#include "SituationReport.hpp"

namespace lionheart
{
enum class Color
{
  ARGENT,
  OR,
  GULES,
  VERT,
  AZURE,
  SABLE
};
enum class Style
{
  BEND,
  BEND_SINISTER,
  CHEVERON,
  CHIEF,
  CROSS,
  FESS,
  INVERTED_CHEVERON,
  PALE,
  PER_BEND,
  PER_BEND_SINISTER,
  PER_FESS,
  PER_PALE,
  QUARTERLY,
  SALTIRE
};

struct Blazon
{
  Color primary;
  Color secondary;
  Style style;
  std::string name;
};
class Player
{
public:
  virtual Placement placeUnit(UnitType,StartBox const &,SituationReport) = 0;
  virtual Action recommendAction(Unit const &,SituationReport) = 0;
  virtual Blazon getBlazon() = 0;
};
}

#endif
