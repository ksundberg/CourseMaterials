#include "ipm.h"
#include <cmath>
#include <iostream>

void ipm::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;

	while(!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		if(sitrep.thing[tr][tc].what==space){
			done=true;
		}
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
Action ipm::Recommendation(SitRep sitrep){
	Action a; 
	int tr=r,tc=c;
	
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}

	switch(rank){
	case crown:
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
			if(sitrep.thing[tr][tc].what==unit){
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					return a;
				} else {
					a.action = turn;
					switch(dir){
					case up: a.dir=rt; break;
					case dn: a.dir=lt; break;
					case lt: a.dir=up; break;
					case rt: a.dir=dn; break;
					case none: break;
					}
					return a;
				}
			}
			if(sitrep.nearestEnemy.dirFor != dir){
				a.action = fwd;
				a.maxDist = HORSESPEED;
				return a;
			} else {
				a.action = turn;
				switch(dir){
				case up: a.dir=rt; break;
				case dn: a.dir=lt; break;
				case lt: a.dir=up; break;
				case rt: a.dir=dn; break;
				case none: break;
				}
				return a;
			}
		}
		break;
	case knight:
		if(numTurns>=20){		
			if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
				if(sitrep.thing[tr][tc].what==unit){
					if(sitrep.thing[tr][tc].tla!=tla){
						a.action=attack;
						a.ar=tr;
						a.ac=tc;
						return a;
					}
				} else if(sitrep.thing[tr][tc].what==rock){
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
			if(dir==sitrep.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=HORSESPEED;
				return a;
			} else {
				a.action=turn;
				a.dir=sitrep.nearestEnemyCrown.dirFor;
				return a;
			}
		} else {
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
			if(sitrep.nearestEnemy.dirFor != dir){
				a.action = turn;
				a.dir=sitrep.nearestEnemy.dirFor;
				return a;
			} else {
				a.action=fwd;
				a.maxDist=1;
				return a;
			}
		}
		++numTurns;
		break;
	case infantry:
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
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			return a;
		} else {
			a.action = turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
		break;
	case archer:
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
			if(sitrep.thing[tr][tc].what==unit){
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					return a;
				}
			}
		}
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			return a;
		} else {
			a.action = turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
		break;
	case none: break;
	}
	a.action=nothing;
	return a;
}
