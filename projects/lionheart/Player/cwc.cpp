#include "cwc.h"
#include <cmath>
#include <iostream>


void cwc::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action cwc::Recommendation(SitRep sitrep){

	// this code is provided as an example only
	// use at your own risk
	Action a; 

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
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	} //his end here.
	if(rank==crown){
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=turn;
		}else{a.action=attack;}
	}
	if(rank==infantry){
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
		}
		if(sitrep.thing[tr][tc].what=rock){
			a.action=turn;
		}
	}//not done
	if(rank==knight){
		if(dir==sitrep.nearestEnemyCrown.dirFor){
			a.action=fwd;
			a.maxDist=HORSESPEED;
			if(sitrep.thing[tr][tc].what=rock){
			a.action=turn;
		}
			if(sitrep.thing[tr][tc].what==crown){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}
	if(rank==archer){
		if(dir==sitrep.nearestEnemyCrown.dirFor){
			a.action=fwd;
			if(sitrep.thing[tr][tc].what=rock){
			a.action=turn;
		}
			if(sitrep.thing[tr][tc].what==unit){
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					a.ar=tr;
					a.ac=tc;
					return a;
				}
			}
		}
	}


	a.action=nothing;
	return a;

}
