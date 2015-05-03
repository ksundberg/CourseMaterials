#include "pez.h"
#include <cmath>
#include <iostream>


void pez::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action pez::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir){
	case up: tr++; break;
	case dn: tr--; break;
	case rt: tc--; break;
	case lt: tc++; break;
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
		a.action=attack;
		a.maxDist=1;
		if(rank==crown)a.maxDist=HORSESPEED; a.dir=dn;
		if(rank==knight)a.maxDist=HORSESPEED;a.dir=up;
		if(rank==archer)a.maxDist=HORSESPEED;a.dir=lt; a.action=attack;
		
		return a;
	} else {
		a.action=fwd;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=turn;
	return a;
	
}
