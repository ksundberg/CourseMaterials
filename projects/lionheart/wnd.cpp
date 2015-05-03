#include "wnd.h"
#include <cmath>


struct Point {
	int r;
	int c;
};

int wnd::wndKnights = 0;
int wnd::wndArchers = 0;
bool wnd::crownSafe = false;
int wnd::crownR = 0;
int wnd::crownC = 0;

void wnd::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	if(minR >= maxR || minC >= maxC) {
		cout << "ERROR: IMPROPER BOUNDS USED FOR UNIT::PLACE\n";
		cout << "EXITING\n";
		exit(1);
	}

	crownsPersonalGuard = false;
	squadLeft = false;
	squadRight = false;

	if(rank == knight) {  //create system of identifying knights
		wndKnights++;
		knightId = wndKnights;
		if(knightId <= 4) {
			crownsPersonalGuard = true;
		}
	}
	if(rank == archer) {
		wndArchers++;
		archerId = wndArchers;
	}

	int i, j;
	int maxSpaces = 0;
	int cl, cr, ru, rd;
	int spacesToEdge[4];
	int countRight = 0;  //for counting with the later unit types
	int countLeft = 0;
	int loopCount = 0;
	int loopCountTwo = 0;
	int archersToCamp = 4;

	//find direction the majority of the board is in and face that direction
	cl = (maxC + minC) / 2;
	cr = ROWS - (maxC + minC) / 2;
	ru = (minR + maxR) / 2;
	rd = COLS - (minR + maxR) / 2;

	spacesToEdge[0] = cl;
	spacesToEdge[1] = cr;
	spacesToEdge[2] = ru;
	spacesToEdge[3] = rd;


	for(i = 0; i < 4; i++) {
		if(maxSpaces < spacesToEdge[i]) {
			maxSpaces = spacesToEdge[i];
		}
	}

	if(cl == maxSpaces) {
		dir = lt;
		startDir = lt;
	}

	if(cr == maxSpaces) {
		dir = rt;
		startDir = rt;
	}

	if(ru == maxSpaces) {
		dir = up;
		startDir = up;
	}

	if(rd == maxSpaces) {
		dir = dn;
		startDir = dn;
	}

	//now to figure out where to put myself
	if(rank == crown) {
		if(dir == up) {
			c = (minC + maxC) / 2;
			r = maxR;

			for(i = r; i >= minR; i--) {
				for(j = c; j <= maxC; j++) {
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						crownR = r;
						crownC = c;
						return;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						crownR = r;
						crownC = c;
						return;
					}
				}
			}
		}

		if(dir == dn) {
			c = (minC + maxC) / 2;
			r = minR;

			for(i = r; i <= maxR; i++) {
				for(j = c; j <= maxC; j++) {
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						crownR = r;
						crownC = c;
						return;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						crownR = r;
						crownC = c;
						return;
					}
				}
			}
		}

		if(dir == lt) {
			r = (minR + maxR) / 2;
			c = maxC;

			for(i = c; i >= minC; i--) {
				for(j = r; j <= minR; j--) {
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						crownR = r;
						crownC = c;
						return;
					}
				}
				for(j = r + 1; j >= maxR; j++) {
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						crownR = r;
						crownC = c;
						return;
					}
				}
			}
		}

		if(dir == rt) {
			r = (minR + maxR) / 2;
			c = minC;

			for(i = c; i <= maxC; i++) {
				for(j = r; j <= minR; j--) {
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						crownR = r;
						crownC = c;
						return;
					}
				}
				for(j = r + 1; j >= maxR; j++) {
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						crownR = r;
						crownC = c;
						return;
					}
				}
			}
		}
	}
	
	if(rank == knight) {
		if(dir == up) {
			c = (minC + maxC) / 2;
			r = maxR;
			
			for(i = r; i >= minR; i--) {
				for(j = c; j <= maxC; j++) { //count knights
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == knight) {
						countRight += 1;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == knight) {
						countLeft += 1;
					}
				}

				for(j = c; j <= maxC; j++) {  //place
					loopCount += 1;
					if(loopCount == 1) {
						continue;
					}
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						return;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						return;
					}
				}
			}
		}

		if(dir == dn) {
			c = (minC + maxC) / 2;
			r = minR;

			for(i = r; i <= maxR; i++) {
				for(j = c; j <= maxC; j++) { //count knights
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == knight) {
						countRight += 1;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == knight) {
						countLeft += 1;
					}
				}

				for(j = c; j <= maxC; j++) {  //place
					loopCount += 1;
					if(loopCount == 1) {
						continue;
					}
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						return;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						return;
					}
				}
			}
		}

		if(dir == lt) {
			r = (minR + maxR) / 2;
			c = maxC;

			for(i = c; i >= minC; i--) {
				for(j = r; j >= minR; j--) { //count
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == knight) {
						countRight += 1;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == knight) {
						countLeft += 1;
					}
				}

				for(j = r; j >= minR; j--) { //place
					loopCount += 1;
					if(loopCount == 1) {
						continue;
					}
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						return;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						return;
					}
				}
			}
		}

		if(dir == rt) {
			r = (minR + maxR) / 2;
			c = minC;

			for(i = c; i <= maxC; i++) {
				for(j = r; j >= minR; j--) { //count
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == knight) {
						countRight += 1;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == knight) {
						countLeft += 1;
					}
				}

				for(j = r; j >= minR; j--) { //place
					loopCount += 1;
					if(loopCount == 1) {
						continue;
					}
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						return;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						return;
					}
				}
			}
		}
	}

	if(rank == archer) {
		if(dir == up) {
			c = (minC + maxC) / 2;
			r = maxR;
			

			for(i = r; i >= minR; i--) {
				for(j = c; j <= maxC; j++) { //count archers
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == archer) {
						countRight += 1;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == archer) {
						countLeft += 1;
					}
				}

				for(j = c; j <= maxC; j++) {  //place
					loopCount += 1;
					if(loopCount <= 2) {
						continue;
					}
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						if(archerId <= archersToCamp) {
							squadRight = true;
						}
						return;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					loopCountTwo += 1;
					if(loopCountTwo == 1) {
						continue;
					}
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						if(archerId <= archersToCamp) {
							squadLeft = true;
						}
						return;
					}
				}
			}
		}

		if(dir == dn) {
			c = (minC + maxC) / 2;
			r = minR;

			for(i = r; i <= maxR; i++) {
				for(j = c; j <= maxC; j++) { //count knights
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == archer) {
						countRight += 1;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == archer) {
						countLeft += 1;
					}
				}

				for(j = c; j <= maxC; j++) {  //place
					loopCount += 1;
					if(loopCount <= 2) {
						continue;
					}
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						if(archerId <= archersToCamp) {
							squadRight = true;
						}
						return;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					loopCountTwo += 1;
					if(loopCountTwo ==1) {
						continue;
					}
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						if(archerId <= archersToCamp) {
							squadLeft = true;
						}
						return;
					}
				}
			}
		}

		if(dir == lt) {
			r = (minR + maxR) / 2;
			c = maxC;

			for(i = c; i >= minC; i--) {
				for(j = r; j >= minR; j--) { //count
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == archer) {
						countRight += 1;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == archer) {
						countLeft += 1;
					}
				}

				for(j = r; j >= minR; j--) { //place
					loopCount += 1;
					if(loopCount <= 2) {
						continue;
					}
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						if(archerId <= archersToCamp) {
							squadRight = true;
						}
						return;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					loopCountTwo += 1;
					if(loopCountTwo == 1) {
						continue;
					}
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						if(archerId <= archersToCamp) {
							squadLeft = true;
						}
						return;
					}
				}
			}
		}

		if(dir == rt) {
			r = (minR + maxR) / 2;
			c = minC;

			for(i = c; i <= maxC; i++) {
				for(j = r; j >= minR; j--) { //count
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == archer) {
						countRight += 1;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == archer) {
						countLeft += 1;
					}
				}

				for(j = r; j >= minR; j--) { //place
					loopCount += 1;
					if(loopCount <= 2) {
						continue;
					}
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						if(archerId <= archersToCamp) {
							squadRight = true;
						}
						return;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					loopCountTwo += 1;
					if(loopCountTwo == 1) {
						continue;
					}
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						if(archerId <= archersToCamp) {
							squadLeft = true;
						}
						return;
					}
				}
			}
		}
	}

	if(rank == infantry) {
		int loopCount = 0;
		if(dir == up) {
			c = (minC + maxC) / 2;
			r = maxR;
			

			for(i = r - 1; i >= minR; i--) {
				loopCount++;
				for(j = c; j <= maxC; j++) { //count
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == infantry) {
						countRight += 1;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == infantry) {
						countLeft += 1;
					}
				}

				for(j = c; j <= maxC; j++) {  //place
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						if(loopCount == 1) {
							squadRight = true;
						}
						return;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						if(loopCount == 1) {
							squadLeft = true;
						}
						return;
					}
				}
			}
		}

		if(dir == dn) {
			c = (minC + maxC) / 2;
			r = minR;

			for(i = r + 1; i <= maxR; i++) {
				loopCount++;
				for(j = c; j <= maxC; j++) {
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == infantry) {
						countRight += 1;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == infantry) {
						countLeft += 1;
					}
				}

				for(j = c; j <= maxC; j++) {  //place
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						if(loopCount == 1) {
							squadRight = true;
						}
						return;
					}
				}
				for(j = c - 1; j >= minC; j--) {
					if(sitrep.thing[i][j].what == space) {
						r = i;
						c = j;
						if(loopCount == 1) {
							squadLeft = true;
						}
						return;
					}
				}
			}
		}

		if(dir == lt) {
			r = (minR + maxR) / 2;
			c = maxC;

			for(i = c - 1; i >= minC; i--) {
				loopCount++;
				for(j = r; j >= minR; j--) { //count
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == infantry) {
						countRight += 1;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == infantry) {
						countLeft += 1;
					}
				}

				for(j = r; j >= minR; j--) { //place
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						if(loopCount == 1) {
							squadRight = true;
						}
						return;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						if(loopCount == 1) {
							squadLeft = true;;
						}
						return;
					}
				}
			}
		}

		if(dir == rt) {
			r = (minR + maxR) / 2;
			c = minC;

			for(i = c + 1; i <= maxC; i++) {
				loopCount++;
				for(j = r; j >= minR; j--) { //count
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == infantry) {
						countRight += 1;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == unit && sitrep.thing[j][i].rank == infantry) {
						countLeft += 1;
					}
				}

				for(j = r; j >= minR; j--) { //place
					if(countRight > countLeft) {
						break;
					}
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						if(loopCount == 1) {
							squadRight = true;
						}
						return;
					}
				}
				for(j = r + 1; j <= maxR; j++) {
					if(sitrep.thing[j][i].what == space) {
						r = j;
						c = i;
						if(loopCount == 1) {
							squadLeft = true;
						}
						return;
					}
				}
			}
		}
	}
}

// tell someone what you want to do
Action wnd::Recommendation(SitRep sitrep) {
	char pathFinding[ROWS][COLS];
	bool advance = true, rockFound = false, regenerate, changed;
	int i, j, loopCount = 0;  //i & j are basic counter variables used for the for loops, loopCount tracks loop iterations
	Action a;

	//if an enemy is near...
	if(rank != crown) {  //no, the crown is not attacking ANYTHING
		if(rank == archer) { //if you're an archer
			//first prioritize archers and crowns
			for(i = c - 1; i > c - 4; i--) {  //check left
				if(i >= 0) {
					if(sitrep.thing[r][i].what == unit && sitrep.thing[r][i].tla != tla && (sitrep.thing[r][i].rank == crown || sitrep.thing[r][i].rank == archer)) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r;
							a.ac = i;
							return a;
						}
					}
					if(sitrep.thing[r - 1][i].what == unit && sitrep.thing[r - 1][i].tla != tla && r - 1 >= 0 && (sitrep.thing[r - 1][i].rank == crown || sitrep.thing[r - 1][i].rank == archer)) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r - 1;
							a.ac = i;
							return a;
						}
					}
					if(sitrep.thing[r + 1][i].what == unit && sitrep.thing[r + 1][i].tla != tla && r + 1 < ROWS && (sitrep.thing[r + 1][i].rank == crown || sitrep.thing[r + 1][i].rank == archer)) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r + 1;
							a.ac = i;
							return a;
						}
					}
				}
			}
			for(i = c + 1; i < c + 4; i++) {  //check right
				if(i < COLS) {
					if(sitrep.thing[r][i].what == unit && sitrep.thing[r][i].tla != tla && (sitrep.thing[r][i].rank == crown || sitrep.thing[r][i].rank == archer)) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r;
							a.ac = i;
							return a;
						}
					}
					if(sitrep.thing[r - 1][i].what == unit && sitrep.thing[r - 1][i].tla != tla && r - 1 >= 0 && (sitrep.thing[r - 1][i].rank == crown || sitrep.thing[r - 1][i].rank == archer)) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r - 1;
							a.ac = i;
							return a;
						}
					}
					if(sitrep.thing[r + 1][i].what == unit && sitrep.thing[r + 1][i].tla != tla && r + 1 < ROWS && (sitrep.thing[r + 1][i].rank == crown || sitrep.thing[r + 1][i].rank == archer)) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r + 1;
							a.ac = i;
							return a;
						}
					}
				}
			}
			for(i = r - 1; i > r - 4; i--) { //check up
				if(i >= 0) {
					if(sitrep.thing[i][c].what == unit && sitrep.thing[i][c].tla != tla && (sitrep.thing[i][c].rank == crown || sitrep.thing[i][c].rank == archer)) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c;
							return a;
						}
					}
					if(sitrep.thing[i][c + 1].what == unit && sitrep.thing[i][c + 1].tla != tla && c + 1 < COLS && (sitrep.thing[i][c + 1].rank == crown || sitrep.thing[i][c + 1].rank == archer)) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c + 1;
							return a;
						}
					}
					if(sitrep.thing[i][c - 1].what == unit && sitrep.thing[i][c - 1].tla != tla && c - 1 >= 0 && (sitrep.thing[i][c - 1].rank == crown || sitrep.thing[i][c - 1].rank == archer)) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c - 1;
							return a;
						}
					}
				}
			}
			for(i = r + 1; i < r + 4; i++) {  //check down
				if(i < ROWS) {
					if(sitrep.thing[i][c].what == unit && sitrep.thing[i][c].tla != tla && (sitrep.thing[i][c].rank == crown || sitrep.thing[i][c].rank == archer)) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c;
							return a;
						}
					}
					if(sitrep.thing[i][c + 1].what == unit && sitrep.thing[i][c + 1].tla != tla && c + 1 < COLS && (sitrep.thing[i][c + 1].rank == crown || sitrep.thing[i][c + 1].rank == archer)) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c + 1;
							return a;
						}
					}
					if(sitrep.thing[i][c - 1].what == unit && sitrep.thing[i][c - 1].tla != tla && c - 1 >= 0 && (sitrep.thing[i][c - 1].rank == crown || sitrep.thing[i][c - 1].rank == archer)) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c - 1;
							return a;
						}
					}
				}
			}
			//then get other targets
			for(i = c - 1; i > c - 4; i--) {  //check left
				if(i >= 0) {
					if(sitrep.thing[r][i].what == unit && sitrep.thing[r][i].tla != tla) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r;
							a.ac = i;
							return a;
						}
					}
					if(sitrep.thing[r - 1][i].what == unit && sitrep.thing[r - 1][i].tla != tla && r - 1 >= 0) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r - 1;
							a.ac = i;
							return a;
						}
					}
					if(sitrep.thing[r + 1][i].what == unit && sitrep.thing[r + 1][i].tla != tla && r + 1 < ROWS) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r + 1;
							a.ac = i;
							return a;
						}
					}
				}
			}
			for(i = c + 1; i < c + 4; i++) {  //check right
				if(i < COLS) {
					if(sitrep.thing[r][i].what == unit && sitrep.thing[r][i].tla != tla) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r;
							a.ac = i;
							return a;
						}
					}
					if(sitrep.thing[r - 1][i].what == unit && sitrep.thing[r - 1][i].tla != tla && r - 1 >= 0) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r - 1;
							a.ac = i;
							return a;
						}
					}
					if(sitrep.thing[r + 1][i].what == unit && sitrep.thing[r + 1][i].tla != tla && r + 1 < ROWS) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
							return a;
						}
						else {
							a.action = attack;
							a.ar = r + 1;
							a.ac = i;
							return a;
						}
					}
				}
			}
			for(i = r - 1; i > r - 4; i--) { //check up
				if(i >= 0) {
					if(sitrep.thing[i][c].what == unit && sitrep.thing[i][c].tla != tla) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c;
							return a;
						}
					}
					if(sitrep.thing[i][c + 1].what == unit && sitrep.thing[i][c + 1].tla != tla && c + 1 < COLS) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c + 1;
							return a;
						}
					}
					if(sitrep.thing[i][c - 1].what == unit && sitrep.thing[i][c - 1].tla != tla && c - 1 >= 0) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c - 1;
							return a;
						}
					}
				}
			}
			for(i = r + 1; i < r + 4; i++) {  //check down
				if(i < ROWS) {
					if(sitrep.thing[i][c].what == unit && sitrep.thing[i][c].tla != tla) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c;
							return a;
						}
					}
					if(sitrep.thing[i][c + 1].what == unit && sitrep.thing[i][c + 1].tla != tla && c + 1 < COLS) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c + 1;
							return a;
						}
					}
					if(sitrep.thing[i][c - 1].what == unit && sitrep.thing[i][c - 1].tla != tla && c - 1 >= 0) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
							return a;
						}
						else {
							a.action = attack;
							a.ar = i;
							a.ac = c - 1;
							return a;
						}
					}
				}
			}
		}
		if(rank != archer) {  //if you're anyone else
			if(sitrep.thing[r][c - 1].what == unit && sitrep.thing[r][c - 1].tla != tla && c - 1 >= 0) {
				if(dir != lt) {
					a.action = turn;
					a.dir = lt;
					return a;
				}
				else {
					a.action = attack;
					a.ac = c - 1;
					a.ar = r;
					return a;
				}
			}
			if(sitrep.thing[r][c + 1].what == unit && sitrep.thing[r][c + 1].tla != tla && c + 1 < COLS) {
				if(dir != rt) {
					a.action = turn;
					a.dir = rt;
					return a;
				}
				else {
					a.action = attack;
					a.ar = r;
					a.ac = c + 1;
				}
			}
			if(sitrep.thing[r + 1][c].what == unit && sitrep.thing[r + 1][c].tla != tla && r + 1 < ROWS) {
				if(dir != dn) {
					a.action = turn;
					a.dir = dn;
					return a;
				}
				else {
					a.action = attack;
					a.ar = r + 1;
					a.ac = c;
				}
			}
			if(sitrep.thing[r - 1][c].what == unit && sitrep.thing[r - 1][c].tla != tla && r - 1 >= 0) {
				if(dir != up) {
					a.action = turn;
					a.dir = up;
					return a;
				}
				else {
					a.action = attack;
					a.ar = r - 1;
					a.ac = c;
				}
			}
			//check for enemies in archery range and move to them.
			for(i = c - 1; i > c - 4; i--) {  //check left
				if(i >= 0) {
					if(sitrep.thing[r][i].what == rock) { //first look for rocks
						rockFound = true;
					}
					loopCount++;
					if(sitrep.thing[r][i].what == unit && sitrep.thing[r][i].tla != tla && !rockFound) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
					if(sitrep.thing[r - 1][i].what == unit && sitrep.thing[r - 1][i].tla != tla && r - 1 >= 0 && !rockFound) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
					if(sitrep.thing[r + 1][i].what == unit && sitrep.thing[r + 1][i].tla != tla && r + 1 < ROWS && !rockFound) {
						if(dir != lt) {
							a.action = turn;
							a.dir = lt;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
				}
			}
			loopCount = 0;  //reset variables
			rockFound = false;
			for(i = c + 1; i < c + 4; i++) {  //check right
				if(i < COLS) {
					loopCount++;
					if(sitrep.thing[r][i].what == rock) {
						rockFound = true;
					}
					if(sitrep.thing[r][i].what == unit && sitrep.thing[r][i].tla != tla && !rockFound) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
					if(sitrep.thing[r - 1][i].what == unit && sitrep.thing[r - 1][i].tla != tla && r - 1 >= 0 && !rockFound) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
					if(sitrep.thing[r + 1][i].what == unit && sitrep.thing[r + 1][i].tla != tla && r + 1 < ROWS && !rockFound) {
						if(dir != rt) {
							a.action = turn;
							a.dir = rt;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
				}
			}
			loopCount = 0;
			rockFound = false;
			for(i = r - 1; i > r - 4; i--) { //check up
				if(i >= 0) {
					if(sitrep.thing[i][c].what == rock) {
						rockFound = true;
					}
					loopCount++;
					if(sitrep.thing[i][c].what == unit && sitrep.thing[i][c].tla != tla && !rockFound) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
					if(sitrep.thing[i][c + 1].what == unit && sitrep.thing[i][c + 1].tla != tla && c + 1 < COLS && !rockFound) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
					if(sitrep.thing[i][c - 1].what == unit && sitrep.thing[i][c - 1].tla != tla && c - 1 >= 0 && !rockFound) {
						if(dir != up) {
							a.action = turn;
							a.dir = up;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
				}
			}
			loopCount = 0;
			rockFound = false;
			for(i = r + 1; i < r + 4; i++) {  //check down
				if(i < ROWS) {
					if(sitrep.thing[i][c].what == rock) {
						rockFound = true;
					}
					loopCount++;
					if(sitrep.thing[i][c].what == unit && sitrep.thing[i][c].tla != tla && !rockFound) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
					if(sitrep.thing[i][c + 1].what == unit && sitrep.thing[i][c + 1].tla != tla && c + 1 < COLS && !rockFound) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
					if(sitrep.thing[i][c - 1].what == unit && sitrep.thing[i][c - 1].tla != tla && c - 1 >= 0 && !rockFound) {
						if(dir != dn) {
							a.action = turn;
							a.dir = dn;
						}
						else {
							a.action = fwd;
							a.maxDist = loopCount;
						}
						return a;
					}
				}
			}
			loopCount = 0;
			rockFound = false;
		}
	}
	
	//crown's personal guard protocol
	if(crownsPersonalGuard) {
		if(!crownSafe) {  //GET OUT OF THE GOSH-DARN CROWN'S WAY IF HE ISN'T THERE YET!!!
			if(sitrep.thing[r - 1][c].what == unit && sitrep.thing[r - 1][c].rank == crown && sitrep.thing[r - 1][c].tla == tla && r - 1 >= 0) {
				if(dir != lt) {
					a.action = turn;
					a.dir = lt;
					return a;
				}
				else {
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			if(sitrep.thing[r + 1][c].what == unit && sitrep.thing[r + 1][c].rank == crown && sitrep.thing[r + 1][c].tla == tla && r + 1 < ROWS) {
				if(dir != rt) {
					a.action = turn;
					a.dir = rt;
					return a;
				}
				else {
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			if(sitrep.thing[r][c - 1].what == unit && sitrep.thing[r][c - 1].rank == crown && sitrep.thing[r][c - 1].tla == tla && c - 1 >= 0) {
				if(dir != dn) {
					a.action = turn;
					a.dir = dn;
					return a;
				}
				else {
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			if(sitrep.thing[r][c + 1].what == unit && sitrep.thing[r][c + 1].rank == crown && sitrep.thing[r][c + 1].tla == tla && c + 1 < COLS) {
				if(dir != up) {
					a.action = turn;
					a.dir = up;
					return a;
				}
				else {
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
		}
		//ok, now you can surround him and protect him.
		//cover diagonals
		if(sitrep.thing[r - 1][c + 1].what == unit && sitrep.thing[r - 1][c + 1].rank == crown && sitrep.thing[r - 1][c + 1].tla == tla && r - 1 >= 0 && c + 1 < COLS) {
			if(dir != lt) {
				a.action = turn;
				a.dir = lt;
				return a;
			}
			else {
				a.action = nothing;
				return a;
			}
		}
		if(sitrep.thing[r + 1][c + 1].what == unit && sitrep.thing[r + 1][c + 1].rank == crown && sitrep.thing[r + 1][c + 1].tla == tla && r + 1 < ROWS && c + 1 < COLS) {
			if(dir != lt) {
				a.action = turn;
				a.dir = lt;
				return a;
			}
			else {
				a.action = nothing;
				return a;
			}
		}
		if(sitrep.thing[r - 1][c - 1].what == unit && sitrep.thing[r - 1][c - 1].rank == crown && sitrep.thing[r - 1][c - 1].tla == tla && r - 1 >= 0 && c - 1 >= 0) {
			if(dir != rt) {
				a.action = turn;
				a.dir = rt;
				return a;
			}
			else {
				a.action = nothing;
				return a;
			}
		}
		if(sitrep.thing[r + 1][c - 1].what == unit && sitrep.thing[r + 1][c - 1].rank == crown && sitrep.thing[r + 1][c - 1].tla == tla && r + 1 < ROWS && c - 1 >= 0) {
			if(dir != rt) {
				a.action = turn;
				a.dir = rt;
				return a;
			}
			else {
				a.action = nothing;
				return a;
			}
		}  //now for the sides
		if(sitrep.thing[r - 1][c].what == unit && sitrep.thing[r - 1][c].rank == crown && sitrep.thing[r - 1][c].tla == tla && r - 1 >= 0) {
			if(dir != dn) {
				a.action = turn;
				a.dir = dn;
				return a;
			}
			else {
				a.action = nothing;
				return a;
			}
		}
		if(sitrep.thing[r + 1][c].what == unit && sitrep.thing[r + 1][c].rank == crown && sitrep.thing[r + 1][c].tla == tla && r + 1 < ROWS) {
			if(dir != up) {
				a.action = turn;
				a.dir = up;
				return a;
			}
			else {
				a.action = nothing;
				return a;
			}
		}
		if(sitrep.thing[r][c - 1].what == unit && sitrep.thing[r][c - 1].rank == crown && sitrep.thing[r][c - 1].tla == tla && c - 1 >= 0) {
			if(dir != rt) {
				a.action = turn;
				a.dir = rt;
				return a;
			}
			else {
				a.action = nothing;
				return a;
			}
		}
		if(sitrep.thing[r][c + 1].what == unit && sitrep.thing[r][c + 1].rank == crown && sitrep.thing[r][c + 1].tla == tla && c + 1 < COLS) {
			if(dir != lt) {
				a.action = turn;
				a.dir = lt;
				return a;
			}
			else {
				a.action = nothing;
				return a;
			}
		}
	}

	//make pathfinding if there are no enemies, if you're the crown, or if you're in the guard and your protocol doesn't have anything for you to do.
	//initalize pathfinding
	for(i = 0; i < ROWS; i++) {  
		for(j = 0; j < COLS; j++) {
			pathFinding[i][j] = ' ';
		}
	}
	
	//set end point depending on who you are
	if(rank == crown) {
		Point path;
		if(startDir == lt) {
			path.r = 0;
			path.c = ROWS - 1;
			while(sitrep.thing[path.r][path.c].what == rock) {
				path.r++;
				path.c--;
			}
		}
		if(startDir == rt) {
			path.r = ROWS - 1;
			path.c = 0;
			while(sitrep.thing[path.r][path.c].what == rock) {
				path.r--;
				path.c++;
			}
		}
		pathFinding[path.r][path.c] = '*';
	}
	if(rank != crown && !crownsPersonalGuard && !squadLeft && !squadRight) { 
		for(i = 0; i < ROWS; i++) {  //find the opposing crown(s)
			for(j = 0; j < COLS; j++) {
				if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == crown && sitrep.thing[i][j].tla != tla) {
					pathFinding[i][j] = '*';
				}
			}
		}
	}
	if(crownsPersonalGuard) {
		for(i = 0; i < ROWS; i++) {  //find the friendly crown and protect
			for(j = 0; j < COLS; j++) {
				if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == crown && sitrep.thing[i][j].tla == tla) {
					pathFinding[i][j] = '*';
				}
			}
		}
	}
	if(squadRight || squadLeft) {
		Point ambush;
		if(startDir == rt) {
			ambush.c = 3 * (COLS - 1) / 4 - 3;
			if(squadRight) {
				ambush.r = (ROWS - 1) / 4;
			}
			if(squadLeft) {
				ambush.r = 3 * (ROWS - 1) / 4;
			}
		}
		if(startDir == lt) {
			ambush.c = (COLS - 1) / 4 + 3;
			if(squadRight) {
				ambush.r = (ROWS - 1) / 4;
			}
			if(squadLeft) {
				ambush.r = 3 * (ROWS - 1) / 4;
			}
		}
		if(startDir == up) {
			ambush.r = (ROWS - 1) / 4 + 3;
			if(squadRight) {
				ambush.c = 3 * (COLS - 1) / 4;
			}
			if(squadLeft) {
				ambush.c = (COLS - 1) / 4;
			}
		}
		if(startDir == dn) {
			ambush.r = 3 * (ROWS - 1) / 4 - 3;
			if(squadRight) {
				ambush.c = 3 * (COLS - 1) / 4;
			}
			if(squadLeft) {
				ambush.c = (COLS - 1) / 4;
			}
		}
		while(sitrep.thing[ambush.r][ambush.c].what == rock) { //error checking
			bool goBack = false;
			if((startDir == up || startDir == dn) && !goBack) {
				ambush.c++;
				if(ambush.c > COLS) {
					ambush.c--;
					goBack = true;
				}
			}
			if((startDir == up || startDir == dn) && goBack) {
				ambush.c--;
				if(ambush.c < 0) {
					ambush.c++;
					goBack = false;
				}
			}
			if((startDir == rt || startDir == lt) && !goBack) {
				ambush.r++;
				if(ambush.r > ROWS) {
					ambush.r--;
					goBack = true;
				}
			}
			if((startDir == rt || startDir == lt) && goBack) {
				ambush.r--;
				if(ambush.r < 0) {
					ambush.r++;
					goBack = false;
				}
			}
		}
		pathFinding[ambush.r][ambush.c] = '*';
	}

	//pathfinding generation
	do {
		regenerate = false;
		do { //core pathfinding generation loops
			changed = false;
			if(loopCount == 0) {
				for(i = 0; i < ROWS; i++) {
					for(j = 0; j < COLS; j++) {
						if(sitrep.thing[i][j].what == space  || (i == r && j == c)  || (sitrep.thing[i][j].what == unit && sitrep.thing[i][j].tla != tla)) {
							if(pathFinding[i][j] != ' ') {
								continue;
							}
							if(pathFinding[i][j + 1] != ' ' && j + 1 < ROWS) {
								changed = true;
								pathFinding[i][j] = '>';
							}
							if(pathFinding[i][j - 1] != ' ' && j - 1 >= 0) {
								changed = true;
								pathFinding[i][j] = '<';
							}
							if(pathFinding[i - 1][j] != ' ' && i - 1 >= 0) {
								changed = true;
								pathFinding[i][j] = '^';
							}
							if(pathFinding[i + 1][j] != ' ' && i + 1 < COLS) {
								changed = true;
								pathFinding[i][j] = 'v';
							}
						}
					}
				}
			}
			if(loopCount >= 1) { //if you're in the second loop you probably are being blocked by other friendly units.
				for(i = 0; i < ROWS; i++) {
					for(j = 0; j < COLS; j++) {
						if(sitrep.thing[i][j].what == space  || (i == r && j == c)  || sitrep.thing[i][j].what == unit) {
							if(pathFinding[i][j] != ' ') {
								continue;
							}
							if(pathFinding[i][j + 1] != ' ' && j + 1 < ROWS ) {
								changed = true;
								pathFinding[i][j] = '>';
							}
							if(pathFinding[i][j - 1] != ' ' && j - 1 >= 0) {
								changed = true;
								pathFinding[i][j] = '<';
							}
							if(pathFinding[i - 1][j] != ' ' && i - 1 >= 0) {
								changed = true;
								pathFinding[i][j] = '^';
							}
							if(pathFinding[i + 1][j] != ' ' && i + 1 < COLS) {
								changed = true;
								pathFinding[i][j] = 'v';
							}
						}
					}
				}
			}
		} while(changed);
		
		if(pathFinding[r][c] == ' ') {  //redo if any duds or squadLeft/squadRight
			regenerate = true;
			loopCount++;
			if(loopCount >= 2) { //if you have tried to regenerate the pathfinding once already you probably aren't going to succeed EVER (prevents endless loops)
				break;
			}

			for(i = 0; i < ROWS; i++) {  //initalize pathfinding AGAIN.
				for(j = 0; j < COLS; j++) {
					pathFinding[i][j] = ' ';
				}
			}
			//now reset or reconfigure your end point
			if(rank == crown) {
				Point path;
				if(startDir == lt) {
					path.r = 0;
					path.c = ROWS - 1;
					while(sitrep.thing[path.r][path.c].what == rock) {
						path.r++;
						path.c--;
					}
				}
				if(startDir == rt) {
					path.r = ROWS - 1;
					path.c = 0;
					while(sitrep.thing[path.r][path.c].what == rock) {
						path.r--;
						path.c++;
					}
				}
				pathFinding[path.r][path.c] = '*';
			}
			if(rank != crown && !crownsPersonalGuard) { 
				for(i = 0; i < ROWS; i++) {  //find the opposing crown(s)
					for(j = 0; j < COLS; j++) {
						if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == crown && sitrep.thing[i][j].tla != tla) {
							pathFinding[i][j] = '*';
						}
					}
				}
			}
			if(crownsPersonalGuard) {
				for(i = 0; i < ROWS; i++) {  //find the friendly crown and protect like before, but now go to the space below or above him.
					for(j = 0; j < COLS; j++) {
						if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].rank == crown && sitrep.thing[i][j].tla == tla) {
							if(i + 1 < ROWS) {
								pathFinding[i + 1][j] = '*';
							}
							else {
								pathFinding[i - 1][j] = '*';
							}
						}
					}
				}
			}
			if(squadRight || squadLeft) {
				Point ambush;
				if(startDir == rt) {
					ambush.c = 3 * (COLS - 1) / 4;
					if(squadRight) {
						ambush.r = (ROWS - 1) / 4;
					}
					if(squadLeft) {
						ambush.r = 3 * (ROWS - 1) / 4;
					}
				}
				if(startDir == lt) {
					ambush.c = (COLS - 1) / 4;
					if(squadRight) {
						ambush.r = (ROWS - 1) / 4;
					}
					if(squadLeft) {
						ambush.r = 3 * (ROWS - 1) / 4;
					}
				}
				if(startDir == up) {
					ambush.r = (ROWS - 1) / 4;
					if(squadRight) {
						ambush.c = 3 * (COLS - 1) / 4;
					}
					if(squadLeft) {
						ambush.c = (COLS - 1) / 4;
					}
				}
				if(startDir == dn) {
					ambush.r = 3 * (ROWS - 1) / 4;
					if(squadRight) {
						ambush.c = 3 * (COLS - 1) / 4;
					}
					if(squadLeft) {
						ambush.c = (COLS - 1) / 4;
					}
				}
				while(sitrep.thing[ambush.r][ambush.c].what == rock) { //error checking
					bool goBack = false;
					if((startDir == up || startDir == dn) && !goBack) {
						ambush.c++;
						if(ambush.c >= COLS) {
							ambush.c--;
							goBack = true;
						}
					}
					if((startDir == up || startDir == dn) && goBack) {
						ambush.c--;
						if(ambush.c < 0) {
							ambush.c++;
							goBack = false;
						}
					}
					if((startDir == rt || startDir == lt) && !goBack) {
						ambush.r++;
						if(ambush.r >= ROWS) {
							ambush.r--;
							goBack = true;
						}
					}
					if((startDir == rt || startDir == lt) && goBack) {
						ambush.r--;
						if(ambush.r < 0) {
							ambush.r++;
							goBack = false;
						}
					}
				}
				pathFinding[ambush.r][ambush.c] = '*';
			}
		}

	} while(regenerate);


	if(squadLeft || squadRight) {  //if you're close enough to the end point you might as well go off and kill the opposing crown
		Point objective;
		for(i = 0; i < ROWS; i++) {
			for(j = 0; j < COLS; j++) {
				if(pathFinding[i][j] == '*') {
					objective.r = i;
					objective.c = j;
				}
			}
		}
		if((r - objective.r) * (r - objective.r) + (c - objective.c) * (c - objective.c) < 5) {
			squadLeft = false;
			squadRight = false;
		}
	}

	//let's have the unit follow the pathfinding
	if(pathFinding[r][c] == '*') {  //in case he is already there
		a.action = nothing;
		if(rank == crown) {
			crownSafe = true;
		}
		if(squadRight || squadLeft) {
			squadRight = false;
			squadLeft = false;
		}
		return a;
	}
	if(pathFinding[r][c] == '^' && dir != up) { //let's have him face the proper direction
		a.action = turn;
		a.dir = up;
		return a;
	}
	if(pathFinding[r][c] == 'v' && dir != dn) {
		a.action = turn;
		a.dir = dn;
		return a;
	}
	if(pathFinding[r][c] == '>' && dir != rt) {
		a.action = turn;
		a.dir = rt;
		return a;
	}
	if(pathFinding[r][c] == '<' && dir != lt) {
		a.action = turn;
		a.dir = lt;
		return a;
	}

	//let's handle movement
	a.maxDist = 0;

	if(pathFinding[r][c] == '^' && dir == up) {
		a.action = fwd;
		while(advance == true) {//how far?
			a.maxDist++;
			if(pathFinding[r - a.maxDist][c] != '^') {
				advance = false;
			}
		}
		return a;
	}
	if(pathFinding[r][c] == 'v' && dir == dn) {
		a.action = fwd;
		while(advance == true) {
			a.maxDist++;
			if(pathFinding[r + a.maxDist][c] != 'v') {
				advance = false;
			}
		}
		return a;
	}
	if(pathFinding[r][c] == '>' && dir == rt) {
		a.action = fwd;
		while(advance == true) {
			a.maxDist++;
			if(pathFinding[r][c + a.maxDist] != '>') {
				advance = false;
			}
		}
		return a;
	}
	if(pathFinding[r][c] == '<' && dir == lt) {
		a.action = fwd;
		while(advance == true) {
			a.maxDist++;
			if(pathFinding[r][c - a.maxDist] != '<') {
				advance = false;
			}
		}
		return a;
	}

	//in case you STILL have nothing to do...
	a.action = nothing;
	return a;
}