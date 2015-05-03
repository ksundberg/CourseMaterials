#include "jaz.h"
#include <cmath>
#include <iostream>


void jaz::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td; // target direction
	while(!done){
		if (rank == crown){
			tr = minR;
			tc = minC;
			if (sitrep.thing[tr][tc].what == space)done = true;
		}
		else{
			tr = minR + rand()%(maxR - minR);
			tc = minC + rand()%(maxC - minC);
			if (sitrep.thing[tr][tc].what == space)done = true;
			if (tr==minR&&tc==minC)done = false;
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
Action jaz::Recommendation(SitRep sitrep){
	
	Action a; 

	//attack in front of you
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
				if (rank == !crown){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
				}
				else{
					a.action = nothing;
				}
				return a;
			}
		}
	}	
	// no one in front of you, head to the nearest enemy
	if(dir==sitrep.nearestEnemyCrown.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight)a.maxDist=HORSESPEED;
		return a;
		if (rank == crown)a.action = nothing;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}
