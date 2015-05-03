#include "dlt.h"
#include <cmath>
#include <iostream>


void dlt::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action dlt::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	int tr=r,tc=c, numTurn=0;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	/*if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){          original code
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
	
	if(dir==sitrep.nearestEnemy.dirFor){//change strategy
		a.action=fwd;
		a.maxDist=1;
		if(rank==crown)a.maxDist=1;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;*/

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
	while (numTurn<15)							//hold positions for first 15 turns.
	{if(dir==sitrep.nearestEnemy.dirFor){
		a.action=nothing;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	numTurn++;
	}
	while(numTurn>=15)							//attack after first 15 turns.
	{if(dir==sitrep.nearestEnemy.dirFor){
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
	numTurn++;
	}


	if(rank==crown&&dir==sitrep.nearestEnemy.dirFor&&turn<250){//keep king halted for half of the game.
		a.action=nothing;
 		a.maxDist=0;
		if(rank==knight||rank==crown)a.maxDist=0;
		return a;
	} else {
		a.action=nothing;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	
	//other ideas:
	//-move king all the way right or left.
	//-rotate other pieces around king for first half.
	//-send out knights followed by archers and infantry, king last 50 turns.
	//-have knights quickly attack archers and infantry.

	return a;
	
}
