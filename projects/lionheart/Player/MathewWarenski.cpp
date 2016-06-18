#include "MathewWarenski.hpp"

// Spring 2016 CS 3100 Champion - Mathew Warenski

// sets the defensive direction for each piece
lionheart::Direction
lionheart::MathewWarenski::setdefdir(lionheart::Unit const &u,
                                     lionheart::SituationReport)
{
  switch (u.getId())
  {
  case 1:
  case 5:
  case 7:
  case 8:
  case 17:
    return lionheart::Direction::NORTH;
    break;
  case 16:
  case 19:
  case 22:
  case 27:
    if (facingEast)
    {
      return lionheart::Direction::WEST;
    }
    else
    {
      return lionheart::Direction::EAST;
    }
    break;
  case 0:
  case 3:
  case 6:
  case 13:
  case 14:
  case 20:
    return lionheart::Direction::SOUTH;
    break;
  case 15:
  case 21:
  case 10:
  case 9:
  case 23:
  case 2:
  case 4:
  case 26:
  case 24:
  case 25:
  case 12:
  case 11:
  case 28:
  case 18:
  case 29:
    if (facingEast)
    {
      return lionheart::Direction::WEST;
    }
    else
    {
      return lionheart::Direction::EAST;
    }
    break;
  }
  return lionheart::Direction::EAST;
}

lionheart::Placement lionheart::MathewWarenski::placeUnit(
    UnitType, StartBox const &box, SituationReport report)
{
  facingEast = (box.minCol < static_cast<int>(report.things[0].size() / 2));
  
  id++;
  if (id > 30)
    id = 1; // resets id for each new game
  if (facingEast)
  {

    switch (id)
    {
    // CROWN
    case 1:
      return { 14, 4 };
    // KNIGHTS
    case 2:
      return { 11, 4 };
    case 3:
      return { 14, 6 };
    case 4:
      return { 18, 4 };
    case 5:
      return { 15, 6 };
    case 6:
      return { 12, 4 };
    case 7:
      return { 17, 4 };
    // ARCHERS
    case 8:
      return { 11, 3 };
    case 9:
      return { 11, 5 };
    case 10:
      return { 13, 7 };
    case 11:
      return { 12, 7 };
    case 12:
      return { 17, 7 };
    case 13:
      return { 16, 7 };
    case 14:
      return { 18, 3 };
    case 15:
      return { 18, 5 };
    // INFANTRY
    case 16:
      return { 10, 3 };
    case 17:
      return { 10, 5 };
    case 18:
      return { 10, 4 };
    case 19:
      return { 19, 3 };
    case 20:
      return { 19, 5 };
    case 21:
      return { 19, 4 };
    case 22:
      return { 12, 3 };
    case 23:
      return { 12, 5 };

    case 24:
    {

      return { 13, 6 };
    }
    case 25:
      return { 14, 7 };
    case 26:
      return { 15, 7 };
    case 27:
      return { 16, 6 };
    case 28:
      return { 17, 5 };
    case 29:
    {

      return { 17, 3 };
    }
    case 30:
    {

      return { 13, 3 };
    }
    }
  }
  else
  {

    switch (id)
    {
    // CROWN
    case 1:
      return { 14, 25 };
    // KNIGHTS
    case 2:
      return { 11, 25 };
    case 3:
      return { 14, 22 };
    case 4:
      return { 18, 25 };
    case 5:
      return { 15, 22 };
    case 6:
      return { 12, 25 };
    case 7:
      return { 17, 25 };
    // ARCHERS
    case 8:
      return { 11, 24 };
    case 9:
      return { 11, 26 };
    case 10:
      return { 13, 22 };
    case 11:
      return { 12, 22 };
    case 12:
      return { 17, 22 };
    case 13:
      return { 16, 22 };
    case 14:
      return { 18, 26 };
    case 15:
      return { 18, 24 };
    // INFANTRY
    case 16:
      return { 10, 24 };
    case 17:
      return { 10, 26 };
    case 18:
      return { 10, 25 };
    case 19:
      return { 19, 24 };
    case 20:
      return { 19, 26 };
    case 21:
      return { 19, 25 };
    case 22:
      return { 12, 26 };
    case 23:
      return { 12, 24 };

    case 24:
      return { 13, 23 };
    case 25:
      return { 14, 23 };
    case 26:
      return { 15, 23 };
    case 27:
      return { 16, 23 };
    case 28:
      return { 17, 26 };
    case 29:
      return { 17, 24 };
    case 30:
      return { 13, 26 };
    }
  }
  return { 0, 0 };
}

lionheart::Action lionheart::MathewWarenski::recommendAction(
    Unit const &u, SituationReport report, Plan p)
{

  if (report.turns < MAX_CHICKEN)
  {
    if (enemyInInbetween(report))
    {
      enemyWaiting = false;
    }
    return playInFortDefend(u, report, p);
  }

  return playSmartCharge(u, report, p);
}

lionheart::Blazon lionheart::MathewWarenski::getBlazon()
{
   return { Color::OR, Color::VERT, Style::CROSS, "Mathew Warenski" };
}

int lionheart::MathewWarenski::flipIfWest(int x, int w)
{
  if (facingEast)
    return x; // no adjust necessary
  int loc = w - x;
  return loc;
}

lionheart::Action lionheart::MathewWarenski::playInFortDefend(
    Unit const &u, SituationReport report, Plan p)
{
  auto dir = setdefdir(u, report);
  if (dir != u.getFacing())
    return turn(dir);
  if (p.hasAttack())
  {
    return p.attackEnemy();
  }
  return Action();
}
lionheart::Action lionheart::MathewWarenski::playSmartCharge(
    Unit const &u, SituationReport report, Plan p)
{

  if (u.getType() == CROWN)
  {

    // if (p.movesToEnemy() < 6) return p.moveToLocation(15, 15);
    return Action();
  }

  if (p.movesToEnemyCrown() <= u.getMoveSpeed())
  {
    if (!p.hasAttack())
    {
      return p.moveToEnemyCrown();
    }
  }
  if (u.getType() == ARCHER)
  {
    if (!p.hasAttack())
    {
      if (enemyWaiting)
      {

        bool kingOnWall = false;
        for (int i = 0; i < 30; i++)
        {
          for (int j = 1; j <= 2; j++)
          {
            auto backwall = flipIfWest(ENEMY_EAST_WALL - j, 29);

            if (report.things[i][backwall].unit == CROWN)
            {
              kingY = i;
              kingX = backwall;
              kingOnWall = true;
            }
          }
        }

        if (kingOnWall)
        {
          auto col = flipIfWest(29, 29);
          auto loc = u.getLocation();
          if (loc.row == kingY && loc.col == col)
          {

            if (facingEast && u.getFacing() != lionheart::Direction::WEST)
            {
              return turn(lionheart::Direction::WEST);
            }
            else if (!facingEast && u.getFacing() != lionheart::Direction::EAST)
            {
              return turn(lionheart::Direction::EAST);
            }

            return lionheart::attack({ kingY, kingX });
          }
          else if (report.things[kingY][col].unit == ARCHER)
          {
            return p.attackEnemy();
          }

          return p.moveToLocation(kingY, col);
        }
      }

      return p.moveToEnemyCrown();
    }
  }
  if (p.hasAttack())
  {
    return p.attackEnemy();
  }
  return p.moveToEnemyCrown();
}

bool lionheart::MathewWarenski::enemyInInbetween(SituationReport report)
{
  Location scanRangeTopLeft(8, 9);
  Location scanRangeBottomLeft(8, 24);
  Location scanRangeTopRight(20, 9);
  Location scanRangeBottomRight(20, 24);
  for (int i = 7; i <= 22; i++)
  {
    for (int j = 10; j <= 18; j++)
    {
      if (report.things[i][j].type == lionheart::SituationReport::ENEMY)
      {

        return true;
      }
    }
  }
  return false;
}

lionheart::Action lionheart::MathewWarenski::wait(Plan p)
{
  if (p.hasAttack())
  {
    return p.attackEnemy();
  }
  return Action();
}

