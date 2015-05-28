#include "ben.h"
#include "lionheart2.h"
#include "Player.hpp"
#include <cmath>
#include <iostream>


void ben::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
/*	while(!done){
		tr=minR+rand()%(maxR-minR);						// minr, maxr, minc, and maxc are the size of the starting box (lh.cpp 611)
		tc=minC+rand()%(maxC-minC);						// tc = lowest number column in startbox + random number between max and min col.
														// 
		if(sitrep.thing[tr][tc].what==space)done=true;	// ?This checks to see if what you put down is a space. If it is, the loop ends.?
	}
	*/
	if (maxC < COLS / 2){
	if (rank == crown){
		while (!done){
			tr = minR/2+minR;
			tc = minC;

			if (sitrep.thing[tr][tc].what == space)done = true;
		}
		td = dn;
		r = tr;
		c = tc;
		dir = td;
	}
	if (rank == knight){
		while (!done){
			tr = minR + rand()%(maxR - minR);
			tc = minC +5;

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
		r = tr;
		c = tc;
		dir = td;

	}
	if (rank == archer){
		while (!done){
			tr = minR + 4 + rand()%(3);
			tc = minC + rand()%(3);

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
		r = tr;
		c = tc;
		dir = td;
	}
	if (rank == infantry){
		while (!done){			
			tc = minC + rand()%(4);
			if (tc == minC || tc == minC + 1){
				tr = minR + 2 + rand()%(7);
			}
			else { tr = minR + 3 + rand()%(5); }
			

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
		r = tr;
		c = tc;
		dir = td;
	}

	}
else{
		if (rank == crown){
			while (!done){
				tr = minR / 2 + minR;
				tc = maxC;

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
			r = tr;
			c = tc;
			dir = td;
		}
		if (rank == knight){
			while (!done){
				tr = minR + rand()%(maxR - minR);
				tc = minC;

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
			r = tr;
			c = tc;
			dir = td;

		}
		if (rank == archer){
			while (!done){
				tr = minR + 4 + rand()%(3);
				tc = maxC - rand()%(3);

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
			r = tr;
			c = tc;
			dir = td;
		}
		if (rank == infantry){
			while (!done){
				tc = maxC - rand()%(4);
				if (tc == maxC || tc == maxC - 1){
					tr = minR + 2 + rand()%(7);
				}
				else { tr = minR + 3 + rand()%(5); }

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
			r = tr;
			c = tc;
			dir = td;
		}

	}
/*	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=up;
		else td=dn;
	}
	r=tr;
	c=tc;
	dir=td;
	*/
}


// tell someone what you want to do
Action ben::Recommendation(SitRep sitrep){
	
	Action a; 
	
	int tr=r,tc=c;  //?target row and column?
	switch (dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}

	if (rank == crown){
		a.action = nothing;
		return a;
	}
	if (rank == knight){
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
		// there is not an enemy in front of me
		// so head to the nearest enemy
		if (dir == sitrep.nearestEnemyCrown.dirFor){
			a.action = fwd;
			a.maxDist = 1;
			if (rank == knight || rank == crown)a.maxDist = HORSESPEED;
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
	if (rank == archer){
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
			//right
			if (sitrep.thing[tr-1][tc].what == unit){
				if (sitrep.thing[tr-1][tc].tla != tla){
					a.action = attack;
					a.ar = tr-1;
					a.ac = tc;
					return a;
				}
			}
			if (sitrep.thing[tr+1][tc].what == unit){
				if (sitrep.thing[tr+1][tc].tla != tla){
					a.action = attack;
					a.ar = tr+1;
					a.ac = tc;
					return a;
				}
			}
			if (sitrep.thing[tr][tc+1].what == unit){
				if (sitrep.thing[tr][tc+1].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc+1;
					return a;
				}
			}
			if (sitrep.thing[tr-1][tc+1].what == unit){
				if (sitrep.thing[tr-1][tc+1].tla != tla){
					a.action = attack;
					a.ar = tr-1;
					a.ac = tc+1;
					return a;
				}
			}
			if (sitrep.thing[tr+1][tc+1].what == unit){
				if (sitrep.thing[tr+1][tc+1].tla != tla){
					a.action = attack;
					a.ar = tr+1;
					a.ac = tc+1;
					return a;
				}
			}
			if (sitrep.thing[tr][tc+2].what == unit){
				if (sitrep.thing[tr][tc+2].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc+2;
					return a;
				}
			}
			if (sitrep.thing[tr-1][tc+2].what == unit){
				if (sitrep.thing[tr-1][tc+2].tla != tla){
					a.action = attack;
					a.ar = tr-1;
					a.ac = tc+2;
					return a;
				}
			}
			if (sitrep.thing[tr+1][tc+2].what == unit){
				if (sitrep.thing[tr+1][tc+2].tla != tla){
					a.action = attack;
					a.ar = tr+1;
					a.ac = tc+2;
					return a;
				}
			}
			//down
			if (sitrep.thing[tr][tc-1].what == unit){
				if (sitrep.thing[tr][tc-1].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc-1;
					return a;
				}
			}
			if (sitrep.thing[tr][tc+1].what == unit){
				if (sitrep.thing[tr][tc + 1].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc + 1;
					return a;
				}
			}
			if (sitrep.thing[tr + 1][tc].what == unit){
				if (sitrep.thing[tr + 1][tc].tla != tla){
					a.action = attack;
					a.ar = tr + 1;
					a.ac = tc;
					return a;
				}
			}
			if (sitrep.thing[tr + 1][tc - 1].what == unit){
				if (sitrep.thing[tr + 1][tc - 1].tla != tla){
					a.action = attack;
					a.ar = tr + 1;
					a.ac = tc - 1;
					return a;
				}
			}
			if (sitrep.thing[tr + 2][tc].what == unit){
				if (sitrep.thing[tr + 2][tc].tla != tla){
					a.action = attack;
					a.ar = tr + 2;
					a.ac = tc;
					return a;
				}
			}
			if (sitrep.thing[tr + 2][tc - 1].what == unit){
				if (sitrep.thing[tr + 2][tc - 1].tla != tla){
					a.action = attack;
					a.ar = tr + 2;
					a.ac = tc - 1;
					return a;
				}
			}
			if (sitrep.thing[tr + 2][tc + 1].what == unit){
				if (sitrep.thing[tr + 2][tc + 1].tla != tla){
					a.action = attack;
					a.ar = tr + 2;
					a.ac = tc + 1;
					return a;
				}
			}
			//left
			if (sitrep.thing[tr][tc - 1].what == unit){
				if (sitrep.thing[tr][tc + 1].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc - 1;
					return a;
				}
			}
			if (sitrep.thing[tr - 1][tc - 1].what == unit){
				if (sitrep.thing[tr - 1][tc - 1].tla != tla){
					a.action = attack;
					a.ar = tr - 1;
					a.ac = tc - 1;
					return a;
				}
			}
			if (sitrep.thing[tr + 1][tc - 1].what == unit){
				if (sitrep.thing[tr + 1][tc - 1].tla != tla){
					a.action = attack;
					a.ar = tr + 1;
					a.ac = tc - 1;
					return a;
				}
			}
			if (sitrep.thing[tr][tc - 2].what == unit){
				if (sitrep.thing[tr][tc - 2].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc - 2;
					return a;
				}
			}
			if (sitrep.thing[tr - 1][tc - 2].what == unit){
				if (sitrep.thing[tr - 1][tc - 2].tla != tla){
					a.action = attack;
					a.ar = tr - 1;
					a.ac = tc + 2;
					return a;
				}
			}
			if (sitrep.thing[tr + 1][tc - 2].what == unit){
				if (sitrep.thing[tr + 1][tc - 2].tla != tla){
					a.action = attack;
					a.ar = tr + 1;
					a.ac = tc + 2;
					return a;
				}
			}
			//up
			if (sitrep.thing[tr - 1][tc].what == unit){
				if (sitrep.thing[tr - 1][tc].tla != tla){
					a.action = attack;
					a.ar = tr - 1;
					a.ac = tc;
					return a;
				}
			}
			if (sitrep.thing[tr - 1][tc - 1].what == unit){
				if (sitrep.thing[tr - 1][tc - 1].tla != tla){
					a.action = attack;
					a.ar = tr - 1;
					a.ac = tc - 1;
					return a;
				}
			}
			if (sitrep.thing[tr - 1][tc + 1].what == unit){
				if (sitrep.thing[tr + 1][tc + 1].tla != tla){
					a.action = attack;
					a.ar = tr - 1;
					a.ac = tc + 1;
					return a;
				}
			}
			if (sitrep.thing[tr - 2][tc].what == unit){
				if (sitrep.thing[tr - 2][tc].tla != tla){
					a.action = attack;
					a.ar = tr - 2;
					a.ac = tc;
					return a;
				}
			}
			if (sitrep.thing[tr - 2][tc - 1].what == unit){
				if (sitrep.thing[tr - 2][tc - 1].tla != tla){
					a.action = attack;
					a.ar = tr - 2;
					a.ac = tc - 1;
					return a;
				}
			}
			if (sitrep.thing[tr - 2][tc + 1].what == unit){
				if (sitrep.thing[tr - 2][tc + 1].tla != tla){
					a.action = attack;
					a.ar = tr - 2;
					a.ac = tc + 1;
					return a;
				}
			}
		}
		if (dir != sitrep.nearestEnemy.dirFor){
			a.action = turn;
			a.dir = sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action = nothing;
		return a;
	}	
	if (rank == infantry){
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
		if (dir != sitrep.nearestEnemy.dirFor){
			a.action = turn;
			a.dir = sitrep.nearestEnemy.dirFor;
			return a;
		}
		if (sitrep.turnNumber > 125){
			if (dir == sitrep.nearestEnemy.dirFor){
				a.action = fwd;
				a.maxDist = 1;
				if (rank == knight || rank == crown)a.maxDist = HORSESPEED;
				return a;
			}

		}
			a.action = nothing;
			return a;
	}
	// first, try to attack in front of you
	
	/*switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}	
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	*/
}
