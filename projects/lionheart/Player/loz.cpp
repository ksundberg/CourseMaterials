#include "loz.h"
#include <cmath>
#include <iostream>


void loz::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	int rdist=ROWS/2-tr;
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
}


// tell someone what you want to do
Action loz::Recommendation(SitRep sitrep){
	Action a; 
	//this is for the archer only
	if (rank == archer){
		return archerAttack(sitrep);
	}
	//For the Crown
	if (rank == crown){
		return kingMove(sitrep);
	}
	// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir){
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
	if(dir==sitrep.nearestEnemyCrown.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}
Action loz::kingMove(SitRep sitrep){
	Action a;
	if (sitrep.anyOpenSpace == dir)
	{
		a.action=fwd;
	    a.maxDist=HORSESPEED;
		return a;
	}
	else {
		a.action=turn;
		a.dir= sitrep.anyOpenSpace;
		return a;
    }
}
Action loz::archerAttack(SitRep sitrep){
	//we will check to see where we can attack for the archer
	Action a;
	Location nearC = sitrep.nearestEnemyCrown;
	Location nearE = sitrep.nearestEnemy;
	//enemy is up
	if (nearC.c >= (c - 1) && nearC.c <= (c + 1) && nearC.r >= (r - 3) && nearC.r <= (r - 1)){
		if (dir != up){
			a.action = turn;
			a.dir = up;
			return a;
		}
		a.action = attack;
		a.ar = nearC.r;
		a.ac = nearC.c;
		return a;
	}
	//enemy is right
	else if (nearC.c >= (c + 1) && nearC.c <= (c + 3) && nearC.r >= (r - 1) && nearC.r <= (r + 1)){
		if (dir != rt){
			a.action = turn;
			a.dir = rt;
			return a;
		}
		a.action = attack;
		a.ar = nearC.r;
		a.ac = nearC.c;
		return a;
	}
	//enemy is down
	else if (nearC.c >= (c - 1) && nearC.c <= (c + 1) && nearC.r >= (r + 1) && nearC.r <= (r + 3)){
		if (dir != dn){
			a.action = turn;
			a.dir = dn;
			return a;
		}
		a.action = attack;
		a.ar = nearC.r;
		a.ac = nearC.c;
		return a;
	}
	//enemy is left
	else if (nearC.c >= (c - 3) && nearC.c <= (c - 1) && nearC.r >= (r - 1) && nearC.r <= (r + 1)){
		if (dir != lt){
			a.action = turn;
			a.dir = lt;
			return a;
		}
		a.action = attack;
		a.ar = nearC.r;
		a.ac = nearC.c;
		return a;
	}

	//same code as above, just gives priority to attacking crown

	if (nearE.c >= (c - 1) && nearE.c <= (c + 1) && nearE.r >= (r - 3) && nearE.r <= (r - 1)){
		if (dir != up){
			a.action = turn;
			a.dir = up;
			return a;
		}
		a.action = attack;
		a.ar = nearE.r;
		a.ac = nearE.c;
		return a;
	}
	else if (nearE.c >= (c + 1) && nearE.c <= (c + 3) && nearE.r >= (r - 1) && nearE.r <= (r + 1)){
		if (dir != rt){
			a.action = turn;
			a.dir = rt;
			return a;
		}
		a.action = attack;
		a.ar = nearE.r;
		a.ac = nearE.c;
		return a;
	}
	else if (nearE.c >= (c - 1) && nearE.c <= (c + 1) && nearE.r >= (r + 1) && nearE.r <= (r + 3)){
		if (dir != dn){
			a.action = turn;
			a.dir = dn;
			return a;
		}
		a.action = attack;
		a.ar = nearE.r;
		a.ac = nearE.c;
		return a;
	}
	else if (nearE.c >= (c - 3) && nearE.c <= (c - 1) && nearE.r >= (r - 1) && nearE.r <= (r + 1)){
		if (dir != lt){
			a.action = turn;
			a.dir = lt;
			return a;
		}
		a.action = attack;
		a.ar = nearE.r;
		a.ac = nearE.c;
		return a;
	}
	// so head to the nearest enemy
	if (dir == sitrep.nearestEnemyCrown.dirFor){
		a.action = fwd;
		a.maxDist = 1;
		return a;
	}
	else {
		a.action = turn;
		a.dir = sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
	a.action = nothing;
	return a;
}
