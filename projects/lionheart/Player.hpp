#ifndef LIONHEART_PLAYER_HPP
#define LIONHEART_PLAYER_HPP

#include "Action.hpp"
#include "Map.hpp"
#include "Plan.hpp"
#include "SituationReport.hpp"

#include <string>

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
  virtual Action recommendAction(Unit const &,SituationReport,Plan) = 0;
  virtual Blazon getBlazon() = 0;
};
}

#endif
