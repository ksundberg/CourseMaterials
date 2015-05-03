
//Sam Whiting a01090851 


#include "usa.h"
#include <cmath>
#include <iostream>


void usa::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action usa::Recommendation(SitRep sitrep){
	
	Action a; 
	static bool poo = true;

	//top priority: king run away
	if(rank==crown){
		//turn
		while(poo){					
			a.action = turn;
			if(r<=(ROWS/2))a.dir = up;
			if(r>=(ROWS/2))a.dir = dn;
			poo= false;
			return a;
		}
		//run
		a.action=fwd;
		a.maxDist=HORSESPEED;
		return a;
	}

	//common folk: first spread out

	
	while(sitrep.turnNumber<=5){
		//face up or down
		while(poo){					
			a.action = turn;
			if(r<=(ROWS/2))a.dir = up;
			if(r>=(ROWS/2))a.dir = dn;
			poo= false;
			return a;
		}
		//then spread 5 times
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;

		}
	

	// then, try to attack in front of you
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
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}
