#include "drc.h"
#include <cmath>
#include <iostream>


void drc::Place(int minR, int maxR, int minC, int maxC, SitRep sitrep){
	bool done = false;
	int tr, tc, centerC, centerR;
	Dir td;

	// right side of the board
	if (minC + ((maxC - minC) / 2) > COLS / 2){

		if (rank == crown){
			tr = (minR + ((maxR - minR) / 2));
			if (((maxR - minR) % 2 != 0)) tr += .5;
			tc = maxC - 2;
		}
		if (rank == knight){
			centerR = (minR + ((maxR - minR) / 2));
			if (((maxR - minR) % 2 != 0)) centerR += .5;
			centerC = maxC - 2;

			while (!done){
				if (sitrep.thing[centerR + 1][centerC + 1].what == space){
					tr = centerR + 1;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR + 1][centerC - 1].what == space){
					tr = centerR + 1;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR - 1][centerC - 1].what == space){
					tr = centerR - 1;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR - 1][centerC + 1].what == space){
					tr = centerR - 1;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR + 3][centerC - 3].what == space){
					tr = centerR + 3;
					tc = centerC - 3;
					break;
				}
				if (sitrep.thing[centerR - 3][centerC - 3].what == space){
					tr = centerR - 3;
					tc = centerC - 3;
					break;
				}
				// insert code for any extra over 6 knights placement
				tr = minR + rand()%(1 + maxR - minR);
				tc = minC + rand()%(1 + maxC - minC);
				break;
			}
		}
		if (rank == archer){
			centerR = (minR + ((maxR - minR) / 2));
			if (((maxR - minR) % 2 != 0)) centerR += .5;
			centerC = maxC - 2;

			while (!done){
				if (sitrep.thing[centerR + 2][centerC + 1].what == space){
					tr = centerR + 2;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR + 3][centerC + 0].what == space){
					tr = centerR + 3;
					tc = centerC + 0;
					break;
				}
				if (sitrep.thing[centerR + 2][centerC - 1].what == space){
					tr = centerR + 2;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR + 1][centerC - 2].what == space){
					tr = centerR + 1;
					tc = centerC - 2;
					break;
				}
				if (sitrep.thing[centerR - 1][centerC - 2].what == space){
					tr = centerR - 1;
					tc = centerC - 2;
					break;
				}
				if (sitrep.thing[centerR - 2][centerC - 1].what == space){
					tr = centerR - 2;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR - 3][centerC - 0].what == space){
					tr = centerR - 3;
					tc = centerC - 0;
					break;
				}
				if (sitrep.thing[centerR - 2][centerC + 1].what == space){
					tr = centerR - 2;
					tc = centerC + 1;
					break;
				}
				// insert code for any extra over 6 knights placement
				tr = minR + rand()%(1 + maxR - minR);
				tc = minC + rand()%(1 + maxC - minC);
				break;
			}
		}
		if (rank == infantry){
			centerR = (minR + ((maxR - minR) / 2));
			if (((maxR - minR) % 2 != 0)) centerR += .5;
			centerC = maxC - 2;

			while (!done){
				if (sitrep.thing[centerR + 2][centerC + 2].what == space){
					tr = centerR + 2;
					tc = centerC + 2;
					break;
				}
				if (sitrep.thing[centerR + 3][centerC + 1].what == space){
					tr = centerR + 3;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR + 4][centerC + 0].what == space){
					tr = centerR + 4;
					tc = centerC + 0;
					break;
				}
				if (sitrep.thing[centerR + 3][centerC - 1].what == space){
					tr = centerR + 3;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR + 2][centerC - 2].what == space){
					tr = centerR + 2;
					tc = centerC - 2;
					break;
				}
				if (sitrep.thing[centerR + 1][centerC - 3].what == space){
					tr = centerR + 1;
					tc = centerC - 3;
					break;
				}
				if (sitrep.thing[centerR + 0][centerC - 3].what == space){
					tr = centerR + 0;
					tc = centerC - 3;
					break;
				}
				if (sitrep.thing[centerR - 1][centerC - 3].what == space){
					tr = centerR - 1;
					tc = centerC - 3;
					break;
				}
				if (sitrep.thing[centerR - 2][centerC - 2].what == space){
					tr = centerR - 2;
					tc = centerC - 2;
					break;
				}
				if (sitrep.thing[centerR - 3][centerC - 1].what == space){
					tr = centerR - 3;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR - 4][centerC + 0].what == space){
					tr = centerR - 4;
					tc = centerC + 0;
					break;
				}
				if (sitrep.thing[centerR - 3][centerC + 1].what == space){
					tr = centerR - 3;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR - 2][centerC + 2].what == space){
					tr = centerR - 2;
					tc = centerC + 2;
					break;
				}
				if (sitrep.thing[centerR - 4][centerC - 3].what == space){
					tr = centerR - 4;
					tc = centerC - 3;
					break;
				}
				if (sitrep.thing[centerR + 4][centerC - 3].what == space){
					tr = centerR + 4;
					tc = centerC - 3;
					break;
				}
				// insert code for any extra over 6 knights placement
				tr = minR + rand()%(1 + maxR - minR);
				tc = minC + rand()%(1 + maxC - minC);
				break;
			}
		}

		r = tr;
		c = tc;

	}

	// end right side of the board
	// left side of the board

	if (minC + ((maxC - minC) / 2) < COLS / 2){

		if (rank == crown){
			tr = (minR + ((maxR - minR) / 2));
			if (((maxR - minR) % 2 != 0)) tr += .5;
			tc = minC + 2;
			//cout << tr << endl;
			//cout << tc << endl;
		}
		if (rank == knight){
			centerR = (minR + ((maxR - minR) / 2));
			if (((maxR - minR) % 2 != 0)) centerR += .5;
			centerC = minC + 2;

			while (!done){
				if (sitrep.thing[centerR + 1][centerC + 1].what == space){
					tr = centerR + 1;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR + 1][centerC - 1].what == space){
					tr = centerR + 1;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR - 1][centerC - 1].what == space){
					tr = centerR - 1;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR - 1][centerC + 1].what == space){
					tr = centerR - 1;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR + 3][centerC + 3].what == space){
					tr = centerR + 3;
					tc = centerC + 3;
					break;
				}
				if (sitrep.thing[centerR - 3][centerC + 3].what == space){
					tr = centerR - 3;
					tc = centerC + 3;
					break;
				}
				// insert code for any extra over 6 knights placement
				tr = minR + rand()%(1 + maxR - minR);
				tc = minC + rand()%(1 + maxC - minC);
				break;
			}
		}
		if (rank == archer){
			centerR = (minR + ((maxR - minR) / 2));
			if (((maxR - minR) % 2 != 0)) centerR += .5;
			centerC = minC + 2;

			while (!done){
				if (sitrep.thing[centerR + 2][centerC + 1].what == space){
					tr = centerR + 2;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR + 3][centerC + 0].what == space){
					tr = centerR + 3;
					tc = centerC + 0;
					break;
				}
				if (sitrep.thing[centerR + 2][centerC - 1].what == space){
					tr = centerR + 2;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR + 1][centerC + 2].what == space){
					tr = centerR + 1;
					tc = centerC + 2;
					break;
				}
				if (sitrep.thing[centerR - 1][centerC + 2].what == space){
					tr = centerR - 1;
					tc = centerC + 2;
					break;
				}
				if (sitrep.thing[centerR - 2][centerC - 1].what == space){
					tr = centerR - 2;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR - 3][centerC - 0].what == space){
					tr = centerR - 3;
					tc = centerC - 0;
					break;
				}
				if (sitrep.thing[centerR - 2][centerC + 1].what == space){
					tr = centerR - 2;
					tc = centerC + 1;
					break;
				}
				// insert code for any extra over 6 knights placement
				tr = minR + rand()%(1 + maxR - minR);
				tc = minC + rand()%(1 + maxC - minC);
				break;
			}
		}
		if (rank == infantry){
			centerR = (minR + ((maxR - minR) / 2));
			if (((maxR - minR) % 2 != 0)) centerR += .5;
			centerC = minC + 2;

			while (!done){
				if (sitrep.thing[centerR + 2][centerC + 2].what == space){
					tr = centerR + 2;
					tc = centerC + 2;
					break;
				}
				if (sitrep.thing[centerR + 3][centerC + 1].what == space){
					tr = centerR + 3;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR + 4][centerC + 0].what == space){
					tr = centerR + 4;
					tc = centerC + 0;
					break;
				}
				if (sitrep.thing[centerR + 3][centerC - 1].what == space){
					tr = centerR + 3;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR + 2][centerC - 2].what == space){
					tr = centerR + 2;
					tc = centerC - 2;
					break;
				}
				if (sitrep.thing[centerR + 1][centerC + 3].what == space){
					tr = centerR + 1;
					tc = centerC + 3;
					break;
				}
				if (sitrep.thing[centerR + 0][centerC + 3].what == space){
					tr = centerR + 0;
					tc = centerC + 3;
					break;
				}
				if (sitrep.thing[centerR - 1][centerC + 3].what == space){
					tr = centerR - 1;
					tc = centerC + 3;
					break;
				}
				if (sitrep.thing[centerR - 2][centerC - 2].what == space){
					tr = centerR - 2;
					tc = centerC - 2;
					break;
				}
				if (sitrep.thing[centerR - 3][centerC - 1].what == space){
					tr = centerR - 3;
					tc = centerC - 1;
					break;
				}
				if (sitrep.thing[centerR - 4][centerC + 0].what == space){
					tr = centerR - 4;
					tc = centerC + 0;
					break;
				}
				if (sitrep.thing[centerR - 3][centerC + 1].what == space){
					tr = centerR - 3;
					tc = centerC + 1;
					break;
				}
				if (sitrep.thing[centerR - 2][centerC + 2].what == space){
					tr = centerR - 2;
					tc = centerC + 2;
					break;
				}
				if (sitrep.thing[centerR - 4][centerC + 3].what == space){
					tr = centerR - 4;
					tc = centerC + 3;
					break;
				}
				if (sitrep.thing[centerR + 4][centerC + 3].what == space){
					tr = centerR + 4;
					tc = centerC + 3;
					break;
				}
				// insert code for any extra over 6 knights placement
				tr = minR + rand()%(1 + maxR - minR);
				tc = minC + rand()%(1 + maxC - minC);
				break;
			}
		}

		r = tr;
		c = tc;

	}

	// end left side of the board
}



Action drc::Recommendation(SitRep sitrep){


	Action a;
	static bool run = true;
	static bool offensive = false;
	static int offensivestart = 25;

	int tr = r, tc = c;
	int i, j;

	if (sitrep.turnNumber >= offensivestart){
		offensive = true;
	}

	if (rank == archer){

		//attack up
		for (i = r - 1; i >= r - 3; i--){
			for (j = c - 1; j <= c + 1; j++){
				if (sitrep.thing[r - 1][c].what == unit){
					if (sitrep.thing[r - 1][c].tla != tla){
						if (dir == up){
							a.action = attack;
							a.ar = r - 1;
							a.ac = c;
							return a;
						}
					}
				}
			}
		}
		//attack left
		for (i = r - 1; i <= r + 1; i++){
			for (j = c - 1; j >= c - 3; j--){
				if (sitrep.thing[r - 1][c].what == unit){
					if (sitrep.thing[r - 1][c].tla != tla){
						if (dir == lt){
							a.action = attack;
							a.ar = r - 1;
							a.ac = c;
							return a;
						}
					}
				}
			}
		}
		//attack down
		for (i = r + 1; i <= r + 3; i++){
			for (j = c - 1; j <= c + 1; j++){
				if (sitrep.thing[r - 1][c].what == unit){
					if (sitrep.thing[r - 1][c].tla != tla){
						if (dir == dn){
							a.action = attack;
							a.ar = r - 1;
							a.ac = c;
							return a;
						}
					}
				}
			}
		}
		//attack right
		for (i = r - 1; i <= r + 1; i++){
			for (j = c + 1; j <= c + 3; j++){
				if (sitrep.thing[r - 1][c].what == unit){
					if (sitrep.thing[r - 1][c].tla != tla){
						if (dir == rt){
							a.action = attack;
							a.ar = r - 1;
							a.ac = c;
							return a;
						}
					}
				}
			}
		}
	}

	// other classes attack
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

	// if not attacking
	if (offensive == true){
		if (dir == sitrep.nearestEnemy.dirFor){
			a.action = fwd;
			a.maxDist = 1;
			if (rank == knight || rank == crown)a.maxDist = 1;
			return a;
		}
		else {
			a.action = turn;
			a.dir = sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action = nothing;
		return a;
	}


	if (rank == crown){
		//flee
		//turn around
		switch (run){
		case true:
			a.action = turn;
			a.dir = sitrep.nearestEnemy.dirFor;
			switch (a.dir){
			case up: a.dir = dn; break;
			case dn: a.dir = up; break;
			case rt: a.dir = lt; break;
			case lt: a.dir = rt; break;
			case none: break;
			}
			run = false;
			return a;
			break;
			//end turn around
			//run
		case false:
			a.action = fwd;
			a.maxDist = HORSESPEED;
			run = true;
			return a;
			break;
			//end run
		}
		//end flee
	}

	if (offensive == false){
		a.action = turn;
		a.dir = sitrep.nearestEnemy.dirFor;
		return a;
	}


}
