#include "BrandonSmith.hpp"
#include "Unit.hpp"

bool safe(int, int, struct lionheart::SituationReport); //check area for enemies
int valid_loc(int); //makes sure you don't call for information outside the report
namespace {
auto id = 0;
}
bool check4archer(int r, int c, struct lionheart::SituationReport report);  //checks for enemy archers
bool eking_stupid();//is enemy king next to the wall
bool eking_indanger();//can I shoot the enemy king over the wall
bool mykingstupid(struct lionheart::SituationReport report);  //is there an archer by my back wall
static bool west = true; //what side of the game board am I playing on
static int numberofturns = 0;
lionheart::Action shootoverwall(lionheart::Unit const & u, lionheart::SituationReport report, lionheart::Plan p); //archers shoot over wall
void find_kings(struct lionheart::SituationReport report);  //finds location of both kings
bool enemyinthebox(struct lionheart::SituationReport report); // is there an enemy in my fort
bool kingsafe(struct lionheart::SituationReport report);  // is my king safe
void defpos(lionheart::Unit const & u, lionheart::SituationReport report); //sets the defensive possition for each piece
void setdefdir(lionheart::Unit const & u, lionheart::SituationReport report); //sets the defensive direction for each piece
static lionheart::Placement ekingloc;
static lionheart::Placement akingloc;
static lionheart::Placement defloc;
static lionheart::Direction defdir;
static auto whattodo = 0;

//placement function
lionheart::Placement lionheart::BrandonSmith::placeUnit(UnitType,
	StartBox const &box,
	SituationReport report)
{
	whattodo = 0; //resets kings decision switch for each game.
	numberofturns = 0;  //resets turns for each new game
	++id;
	if (id > 30) id = 1;  //resets id for each new game
	auto westSide = (box.minCol < static_cast<int>(report.things[0].size() / 2));
	if (westSide)

	{
		west = true;
		switch (id)
		{
			// CROWN
		case 1:  return{ 14, 2 };
				 // KNIGHTS
		case 2:  return{ 11, 4 };
		case 3:  return{ 14, 6 };
		case 4:  return{ 18, 4 };
		case 5:  return{ 15, 6 };
		case 6:  return{ 12, 4 };
		case 7:  return{ 17, 4 };
				 // ARCHERS
		case 8:  return{ 11, 3 };
		case 9:  return{ 11, 5 };
		case 10: return{ 13, 7 };
		case 11: return{ 12, 7 };
		case 12: return{ 17, 7 };
		case 13: return{ 16, 7 };
		case 14: return{ 18, 3 };
		case 15: return{ 18, 5 };
				 // INFANTRY
		case 16: return{ 10, 3 };
		case 17: return{ 10, 5 };
		case 18: return{ 10, 4 };
		case 19: return{ 19, 3 };
		case 20: return{ 19, 5 };
		case 21: return{ 19, 4 };
		case 22: return{ 12, 3 };
		case 23: return{ 12, 5 };

		case 24: return{ 13, 6 };
		case 25: return{ 14, 7 };
		case 26: return{ 15, 7 };
		case 27: return{ 16, 6 };
		case 28: return{ 17, 5 };
		case 29: return{ 17, 3 };
		case 30: return{ 13, 3 };
		}
	}
	else
	{
		west = false;
		switch (id)
		{
			// CROWN
		case 1: return{ 14, 27 };
				// KNIGHTS
		case 2: return{ 11, 25 };
		case 3: return{ 14, 22 };
		case 4: return{ 18, 25 };
		case 5: return{ 15, 22 };
		case 6: return{ 12, 25 };
		case 7: return{ 17, 25 };
				// ARCHERS
		case 8: return{ 11, 24 };
		case 9: return{ 11, 26 };
		case 10:return{ 13, 22 };
		case 11:return{ 12, 22 };
		case 12:return{ 17, 22 };
		case 13:return{ 16, 22 };
		case 14: return{ 18, 26 };
		case 15: return{ 18, 24 };
				 // INFANTRY
		case 16: return{ 10, 24 };
		case 17: return{ 10, 26 };
		case 18: return{ 10, 25 };
		case 19: return{ 19, 24 };
		case 20: return{ 19, 26 };
		case 21: return{ 19, 25 };
		case 22: return{ 12, 26 };
		case 23: return{ 12, 24 };

		case 24: return{ 13, 23 };
		case 25: return{ 14, 23 };
		case 26: return{ 15, 23 };
		case 27: return{ 16, 23 };
		case 28: return{ 17, 26 };
		case 29: return{ 17, 24 };
		case 30: return{ 13, 26 };
		}
	}
	return{ 0, 0 };
}

//function for game play
lionheart::Action
lionheart::BrandonSmith::recommendAction(Unit const & u, SituationReport report, Plan p)
{
	++numberofturns;
	auto loc = u.getLocation();
	find_kings(report);
	if (akingloc.col < 15) west = true;
	if (akingloc.col > 15)west = false;
	defpos(u, report);
	setdefdir(u, report);
	auto row = loc.row;
	auto col = loc.col;
	auto drow = defloc.row;
	auto dcol = defloc.col;

	if (u.getId() == 44) //give king bodygaurd and prevents draw with non attacking armies
	{
		if (p.hasAttack()) return p.attackEnemy();
		if ((p.movesToAllyCrown() > 2) && (p.movesToEnemy() < 2))
			return p.moveToEnemy();
		if (p.movesToAllyCrown() > 2) return p.moveToAllyCrown();
	}

	if (u.getType() == CROWN) //rules for the king
	{
		if (p.hasAttack())
		{
			return p.attackEnemy();
		}
		if (mykingstupid(report))
		{
			if (west)
			{
				defloc.row = 14;
				defloc.col = 4;
				if ((row != 14) || (col != 4))
				{
					return p.moveToLocation(14, 4);
				}
			}
			if (!west)
			{
				defloc.row = 14;
				defloc.col = 25;
				if ((row != 14) || (col != 25))
				{
					return p.moveToLocation(14, 25);
				}
			}
		}

		if ((safe(row, col, report)) && (numberofturns< 300))
		{
			return turn(defdir);
		}

		if ((!safe(row, col, report)) || (enemyinthebox(report)))
		{
			++whattodo;
			switch (whattodo)
			{
			case 0:
			case 1:
			case 2:
			case 3:
				if ((west) && (report.things[19][3].type == lionheart::SituationReport::ALLY))
				{
					return p.moveToLocation(19, 2);
				}
				if ((west) && (report.things[10][3].type == lionheart::SituationReport::ALLY))
				{
					return p.moveToLocation(10, 2);
				}
				if ((west))
				{
					return p.moveToLocation(19, 2);
				}
				if ((!west) && (report.things[19][26].type == lionheart::SituationReport::ALLY))
				{
					return p.moveToLocation(19, 27);
				}
				if ((!west) && (report.things[10][26].type == lionheart::SituationReport::ALLY))
				{
					return p.moveToLocation(10, 27);
				}
				if (!west)
				{
					return p.moveToLocation(19, 27);
				}
				break;
			case 4:
				if (akingloc.row > 15)
				{
					if (p.hasAttack())return p.attackEnemy();
					else return lionheart::turn(lionheart::Direction::NORTH);
				}

				else if (p.hasAttack())return p.attackEnemy();
				else return lionheart::turn(lionheart::Direction::SOUTH);
				break;
			case 5:
			case 6:
			case 7:
				if (safe(row, col, report))
				{
					return wait();
				}
				else return p.attackEnemy();
				break;
			}
			
		}
		if (safe(row, col, report))
			{
				return wait();
			}
			else return p.attackEnemy();
	}
	if ((numberofturns / 30) < 10)//tells everyone what direction to face for defense;
	{
		if ((u.getFacing()) != defdir)return turn(defdir);
		else return wait();
	}

	if ((numberofturns / 30) < 50)//this will stall in defense for half the game then attack
	{
		if (p.hasAttack())return p.attackEnemy();
		if (enemyinthebox(report))
		{
			return p.attackEnemy();
		}
		if ((u.getId() == 39) || (u.getId() == 40))
		{
			if (p.movesToEnemy() < 3) return p.moveToEnemy();
			if ((row != drow) || (col != dcol))return p.moveToLocation(drow, dcol);
			if ((u.getFacing()) != defdir)return turn(defdir);
			else return wait();
		}
		if ((u.getType() == KNIGHT) && (p.movesToEnemy() < 2))return p.moveToEnemy();
		if ((u.getType() != KNIGHT) && (p.movesToEnemy() < 5)) return p.moveToEnemy();
		if ((row != drow) || (col != dcol))return p.moveToLocation(drow, dcol);
		if ((u.getFacing()) != defdir)return turn(defdir);
		else return wait();
	}


	if (u.getType() == ARCHER)//sends archers around the fort if they can shoot over the wall and kill the king
	{
		return shootoverwall(u, report, p);
	}

	// tells everyone to attack  
	if (p.hasAttack())return p.attackEnemy();
	if (enemyinthebox(report))return p.attackEnemy();
	if (p.movesToEnemyCrown()<2) return p.moveToEnemyCrown();
	else return p.attackEnemy();

}

//third function to return colors and name
lionheart::Blazon lionheart::BrandonSmith::getBlazon()
{
	return{ Color::OR, Color::GULES, Style::QUARTERLY, "Brandon Smith's Pawn Sacrifice" };
}

bool safe(int row, int col, struct lionheart::SituationReport report)
{
	//checks vertical space for enemys
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if ((report.things[valid_loc((row - 1) + i)][valid_loc((col - 5) + j)].type == lionheart::SituationReport::ENEMY))return false;
		}
	}
	//checks horizonal space for enemys
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if ((report.things[valid_loc((row - 5) + i)][valid_loc((col - 1) + j)].type == lionheart::SituationReport::ENEMY))return false;
		}
	}
	return true;
}

bool enemyinthebox(struct lionheart::SituationReport report)
{

	for (auto i = 0; i < 10; ++i)
	{
		if (!west)
		{
			for (auto j = 0; j < 6; ++j)
			{
				if (report.things[(i+10)][(j+22)].type == lionheart::SituationReport::ENEMY)
				{
					return true;
				}
			}
		}
		else if (west)
		{
			for (auto j = 0; j < 6; ++j)
			{
				if (report.things[(i+10)][(j+2)].type == lionheart::SituationReport::ENEMY) return true;
			}
		}
	}
	return false;
}

void find_kings(struct lionheart::SituationReport report)
{
	for (auto i = 0; i < 30; ++i)
	{
		for (auto j = 0; j < 30; ++j)
		{
			if (report.things[i][j].unit == lionheart::UnitType::CROWN)
			{
				if (report.things[i][j].type == lionheart::SituationReport::ENEMY)
				{
					ekingloc.row = i;
					ekingloc.col = j;
				}
				if (report.things[i][j].type == lionheart::SituationReport::ALLY)
				{
					akingloc.row = i;
					akingloc.col = j;
				}
			}
		}
	}
}

bool eking_stupid()  // is the enemy king right by the wall
{
	if ((west) && ((ekingloc.col == 27) || (ekingloc.col == 22))) return true;
	if ((!west) && ((ekingloc.col == 2) || (ekingloc.col == 7))) return true;
	else return false;
}

bool eking_indanger()  // is the enemy king close enough to the wall to shoot?
{
	if (west)
	{
		if (ekingloc.col == 26) return true;
		if ((ekingloc.col == 23) && ((ekingloc.row != 14) || (ekingloc.row != 15))) return true;
		else return false;
	}
	if (!west)
	{
		if (ekingloc.col == 3) return true;
		if ((ekingloc.col == 6) && ((ekingloc.row != 14) || (ekingloc.row != 15))) return true;
		else return false;
	}
	return false;
}

bool kingsafe(struct lionheart::SituationReport report)
{
	return safe(akingloc.row, akingloc.col, report);
}

void defpos(lionheart::Unit const & u, lionheart::SituationReport )
{
	if (!west)
	{
		switch (u.getId())
		{
		case 0:  defloc.row = 14; defloc.col = 27; break;

		case 1:  defloc.row = 11; defloc.col = 25; break;
		case 2:  defloc.row = 14; defloc.col = 23; break;
		case 3:  defloc.row = 18; defloc.col = 25; break;
		case 4:  defloc.row = 15; defloc.col = 23; break;
		case 5:  defloc.row = 12; defloc.col = 25; break;
		case 6:  defloc.row = 17; defloc.col = 25; break;

		case 7:  defloc.row = 11; defloc.col = 26; break;
		case 8:  defloc.row = 11; defloc.col = 24; break;
		case 9:  defloc.row = 13; defloc.col = 22; break;
		case 10: defloc.row = 12; defloc.col = 22; break;
		case 11: defloc.row = 17; defloc.col = 22; break;
		case 12: defloc.row = 16; defloc.col = 22; break;
		case 13: defloc.row = 18; defloc.col = 26; break;
		case 14: defloc.row = 18; defloc.col = 24; break;

		case 30: defloc.row = 10; defloc.col = 26; break;
		case 31: defloc.row = 10; defloc.col = 24; break;
		case 32: defloc.row = 10; defloc.col = 25; break;
		case 33: defloc.row = 19; defloc.col = 26; break;
		case 34: defloc.row = 19; defloc.col = 24; break;
		case 35: defloc.row = 19; defloc.col = 25; break;
		case 36: defloc.row = 12; defloc.col = 26; break;
		case 37: defloc.row = 12; defloc.col = 24; break;

		case 38: defloc.row = 13; defloc.col = 23; break;
		case 39: defloc.row = 14; defloc.col = 22; break;
		case 40: defloc.row = 15; defloc.col = 22; break;
		case 41: defloc.row = 16; defloc.col = 23; break;
		case 42: defloc.row = 17; defloc.col = 24; break;
		case 43: defloc.row = 17; defloc.col = 26; break;
		case 44: defloc.row = 13; defloc.col = 26; break;

		}
	}
	if (west)
		switch (u.getId())
		{
		case 0:  defloc.row = 14; defloc.col = 2; break;

		case 1:  defloc.row = 11; defloc.col = 4; break;
		case 2:  defloc.row = 14; defloc.col = 6; break;
		case 3:  defloc.row = 18; defloc.col = 4; break;
		case 4:  defloc.row = 15; defloc.col = 6; break;
		case 5:  defloc.row = 12; defloc.col = 4; break;
		case 6:  defloc.row = 17; defloc.col = 4; break;

		case 7:  defloc.row = 11; defloc.col = 3; break;
		case 8:  defloc.row = 11; defloc.col = 5; break;
		case 9:  defloc.row = 13; defloc.col = 7; break;
		case 10: defloc.row = 12; defloc.col = 7; break;
		case 11: defloc.row = 17; defloc.col = 7; break;
		case 12: defloc.row = 16; defloc.col = 7; break;
		case 13: defloc.row = 18; defloc.col = 3; break;
		case 14: defloc.row = 18; defloc.col = 5; break;

		case 30: defloc.row = 10; defloc.col = 3; break;
		case 31: defloc.row = 10; defloc.col = 5; break;
		case 32: defloc.row = 10; defloc.col = 4; break;
		case 33: defloc.row = 19; defloc.col = 3; break;
		case 34: defloc.row = 19; defloc.col = 5; break;
		case 35: defloc.row = 19; defloc.col = 4; break;
		case 36: defloc.row = 12; defloc.col = 3; break;
		case 37: defloc.row = 12; defloc.col = 5; break;

		case 38: defloc.row = 13; defloc.col = 6; break;
		case 39: defloc.row = 14; defloc.col = 7; break;
		case 40: defloc.row = 15; defloc.col = 7; break;
		case 41: defloc.row = 16; defloc.col = 6; break;
		case 42: defloc.row = 17; defloc.col = 5; break;
		case 43: defloc.row = 17; defloc.col = 3; break;
		case 44: defloc.row = 13; defloc.col = 3; break;

		}
}
//sets the defensive direction for players
void setdefdir(lionheart::Unit const & u, lionheart::SituationReport )
{
	switch (u.getId())
	{
	case 1:
	case 5:
	case 7:
	case 8:
	case 32:
		defdir = lionheart::Direction::NORTH;
		break;
	case 31:
	case 34:
	case 37:
	case 42:
		if (west)
		{
			defdir = lionheart::Direction::WEST;
		}
		if (!west)
		{
			defdir = lionheart::Direction::EAST;
		}
		break;
	case 0:
	case 3:
	case 6:
	case 13:
	case 14:
	case 35:
		defdir = lionheart::Direction::SOUTH;
		break;
	case 30:
	case 36:
	case 10:
	case 9:
	case 38:
	case 2:
	case 4:
	case 41:
	case 39:
	case 40:
	case 12:
	case 11:
	case 43:
	case 33:
	case 44:
		if (!west)
		{
			defdir = lionheart::Direction::WEST;
		}
		if (west)
		{
			defdir = lionheart::Direction::EAST;
		}
		break;
	}
}

bool check4archer(int r, int c, struct lionheart::SituationReport report)
{
	if ((report.things[r][c].unit == lionheart::UnitType::ARCHER) &&
		(report.things[r][c].type == lionheart::SituationReport::ENEMY))
	{
		return true;
	}
	else return false;
}

bool mykingstupid(struct lionheart::SituationReport report) // this function helps if someone else knows how to shoot over walls
{
	for (auto j = 8; j < 21; ++j)
	{
		if ((west) && (check4archer(j, 0, report)))
		{
			return true;
		}
		if ((!west) && (check4archer(j, 29, report)))
		{
			return true;
		}
	}
	for (auto i = 1; i < 4; ++i)
	{
		if ((west) && (check4archer(8, i, report)))
		{
			return true;
		}
		if ((!west) && (check4archer(8, (i + 25), report)))
		{
			return true;
		}
		if ((west) && (check4archer(21, i, report)))
		{
			return true;
		}
		if ((!west) && (check4archer(21, (i + 25), report)))
		{
			return true;
		}

	}
	return false;
}

lionheart::Action shootoverwall(lionheart::Unit const & u, lionheart::SituationReport report, lionheart::Plan p)
{
	auto l = u.getLocation();
	auto c = l.col;
	auto r = l.row;

	if (p.hasAttack()) return p.attackEnemy();
	if (enemyinthebox(report))
	{
		if ((west) && (c<10))
			return p.attackEnemy();
		if ((!west && (c > 20)))
			return p.attackEnemy();
	}
	if (eking_stupid() || eking_indanger())
	{
		if (west == true)
		{
			if ((ekingloc.col == 26) || (ekingloc.col == 27))
			{
				if ((c != 29) || (r != ekingloc.row))
				{
					if ((r > 14) && (c < 26)) { return p.moveToLocation(23, 27); }
					else if ((r < 15) && (c < 26)) { return p.moveToLocation(4, 27); }
					else return p.moveToLocation(ekingloc.row, 29);
				}
				else if (u.getFacing() != lionheart::Direction::WEST)
				{
					return turn(lionheart::Direction::WEST);
				}
				else return lionheart::attack(ekingloc);
			}
			else if ((ekingloc.col == 22) || (ekingloc.col == 23))
			{
				if ((c != 20) || (r != ekingloc.row))
				{
					return p.moveToLocation(ekingloc.row, 20);
				}
				if (u.getFacing() != lionheart::Direction::EAST)
				{
					return turn(lionheart::Direction::EAST);
				}
				return lionheart::attack(ekingloc);
			}
		}
		else if (!west)
		{
			if ((ekingloc.col == 2) || (ekingloc.col == 3))
			{
				if ((c != 0) || (r != ekingloc.row))
				{
					if ((r >= 15) && (c > 2)) { return p.moveToLocation(25, 2); }
					else if ((r < 15) && (c > 2)) { return p.moveToLocation(4, 2); }
					else return p.moveToLocation(ekingloc.row, 0);
				}
				if (u.getFacing() != lionheart::Direction::EAST)
				{
					return turn(lionheart::Direction::EAST);
				}
				return lionheart::attack(ekingloc);
			}
			if ((ekingloc.col == 6) || (ekingloc.col == 8))
			{
				if ((c != 9) || (r != ekingloc.row))
				{
					return p.moveToLocation(ekingloc.row, 9);
				}
				if (u.getFacing() != lionheart::Direction::WEST)
				{
					return turn(lionheart::Direction::WEST);
				}
				return lionheart::attack(ekingloc);
			}
		}
	}
	if (p.hasAttack())return p.attackEnemy();
	if (enemyinthebox(report))return p.attackEnemy();
	return p.moveToEnemyCrown();
}

int valid_loc(int y)
{
	if (y < 0)return 0;
	else if (y > 29) return 29;
	else return y;
}
