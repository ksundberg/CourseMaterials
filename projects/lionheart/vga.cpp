#include "vga.h"
#include <cmath>
#include <iostream>


void vga::Place(int minR, int maxR, int minC, int maxC, SitRep sitrep){

	bool done = false;
	int tr, tc;
	Dir td;
	while (!done){
		tr = minR + rand()%(maxR - minR);
		tc = minC + rand()%(maxC - minC);
		if (sitrep.thing[tr][tc].what == space)done = true;
	}
	int rdist = ROWS / 2 - tr;
	int cdist = COLS / 2 - tc;
	if (abs(rdist) < abs(cdist)){
		if (cdist>0)td = rt;
		else td = lt;
	}
	else{
		if (rdist > 0)td = up;
		else td = dn;
	}
	if (rank == crown){
		tr = minR + (maxR - (minR + (maxR - minR)));
		if (tr >= 15)tr = 8;
		if (sitrep.thing[tr][tc].what == rock)tr++;
		tc = minC + (maxC - (minC + (maxC - minC)));
		if (tc >= 15) tc = 26;
		if (sitrep.thing[tr][tc].what == rock)tc++;
	}
	r = tr;
	c = tc;
	dir = up;


}


// tell someone what you want to do
Action vga::Recommendation(SitRep sitrep){

	// this code is provided as an example only
	// use at your own risk
	Action a;


	// first, try to attack in front of you
	int tr = r, tc = c;
	switch (dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
		if (sitrep.thing[tr][tc].what == unit){
			if (sitrep.thing[tr][tc].tla != tla){
				a.action = attack;
				a.ar = tr;
				a.ac = tc;
				return a;
			}
		}
	}
	// VGA MOVES
	if (sitrep.turnNumber <= 3){
		if (rank == crown){
			if (dir == up){
				a.action = fwd;
				a.maxDist = HORSESPEED;
				return a;
			}
			else{
				a.action = turn;
				a.dir = up;
				return a;
			}
		}
		else{
			if (dir == sitrep.nearestEnemy.dirFor){
				a.action = fwd;
				a.maxDist = 1;
				if (rank == knight) a.maxDist = HORSESPEED;
				return a;
			}
			else{
				a.action = turn;
				a.dir = sitrep.nearestEnemy.dirFor;
				return a;
			}
		}
	}
	if (sitrep.turnNumber < 9 && sitrep.turnNumber >= 4){
		if (rank == crown){
			if (dir == up){
				a.action = fwd;
				a.maxDist = 1;
				return a;
			}
			else{
				a.action = turn;
				a.dir = up;
				return a;
			}
		}
		else{
			if (dir == up){
				a.action = fwd;
				a.maxDist = 1;
				return a;
			}
			else{
				a.action = turn;
				a.dir = up;
				return a;
			}
		}
	}
	if (sitrep.turnNumber >= 9 && sitrep.turnNumber < 25){
		if (rank != crown){
			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != crown && rank != knight){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			else {
				if (rank != crown && rank != knight){
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}

			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != infantry && rank != archer && rank != crown){
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
			}
			else {
				if (rank != infantry && rank != archer && rank != crown){
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
		}
		else{
			if (dir != up){
				a.action = turn;
				a.dir = up;
				//cout << "king" << endl;
				return a;
			}
			else {
				a.action = fwd;
				a.maxDist = HORSESPEED;
				//cout << "king facing up" << endl;
				return a;
			}
		}
	}
	if (sitrep.turnNumber >= 25 && sitrep.turnNumber < 28){
		if (dir == dn){
			a.action = fwd;
			a.maxDist = 1;
			return a;
		}
		else {

			a.action = turn;
			a.dir = dn;
			return a;
		}

	}
	if (sitrep.turnNumber >= 28 && sitrep.turnNumber < 33){
		if (rank != crown){
			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != crown && rank != knight){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			else {
				if (rank != crown && rank != knight){
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}

			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != infantry && rank != archer && rank != crown){
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
			}
			else {
				if (rank != infantry && rank != archer && rank != crown){
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
		}
		else{
			if (dir != dn){
				a.action = turn;
				a.dir = dn;

				return a;
			}
			else {
				a.action = fwd;
				a.maxDist = HORSESPEED;

				return a;
			}
		}
	}
	if (sitrep.turnNumber >= 33 && sitrep.turnNumber<40){
		if (rank != crown){
			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != crown && rank != knight){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			else {
				if (rank != crown && rank != knight){
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}

			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != infantry && rank != archer && rank != crown){
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
			}
			else {
				if (rank != infantry && rank != archer && rank != crown){
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
		}
		else{
			if (dir != up){
				a.action = turn;
				a.dir = up;

				return a;
			}
			else {
				a.action = fwd;
				a.maxDist = HORSESPEED;

				return a;
			}
		}
	}
	if (sitrep.turnNumber >= 40 && sitrep.turnNumber < 47){
		if (rank != crown){
			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != crown && rank != knight){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			else {
				if (rank != crown && rank != knight){
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}

			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != infantry && rank != archer && rank != crown){
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
			}
			else {
				if (rank != infantry && rank != archer && rank != crown){
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
		}
		else{
			if (dir != dn){
				a.action = turn;
				a.dir = dn;

				return a;
			}
			else {
				a.action = fwd;
				a.maxDist = HORSESPEED;

				return a;
			}
		}
	}
	if (sitrep.turnNumber >= 47){
		if (rank != crown){
			if (dir == sitrep.nearestEnemyCrown.dirFor){
				if (rank != crown && rank != knight){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			else {
				if (rank != crown && rank != knight){
					a.action = turn;
					a.dir = sitrep.nearestEnemyCrown.dirFor;
					return a;
				}
			}

			if (dir == sitrep.nearestEnemy.dirFor){
				if (rank != infantry && rank != archer && rank != crown){
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
			}
			else {
				if (rank != infantry && rank != archer && rank != crown){
					a.action = turn;
					a.dir = sitrep.nearestEnemyCrown.dirFor;
					return a;
				}
			}
		}
		else{
			if (dir != up){
				a.action = turn;
				a.dir = up;

				return a;
			}
			else {
				a.action = fwd;
				a.maxDist = HORSESPEED;

				return a;
			}
		}
	}
}