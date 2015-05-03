#include "bri.h"
#include <cmath>
#include <iostream>


void bri::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action bri::Recommendation(SitRep sitrep){
	
	//action
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

	//crown stays where he is
	if(rank==crown) {
		a.action=turn; 
		return a;
	}

	//archers protect the crown
	if(rank==archer){
		if(dir==sitrep.thing[tr][tc].what) {
			if(sitrep.thing[tr][tc].rank==crown) {
				a.action=fwd; 
				return a;
			}
		} else {
		a.action=turn;
		return a;
	}
		//if there is an enemy
		if(sitrep.thing[tr][tc].what==unit) {
			if(sitrep.thing[tr][tc].what==unit){
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=attack; 
						a.ar=tr;
						a.ac=tc;
						return a;
				}
			}
		} else {
			a.action=turn;
			return a;
		}
	}

	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				if(sitrep.thing[tr][tc].rank==infantry,knight,archer) {
					if(sitrep.thing[tr][tc].hp==10) {
						a.action=attack; 
						a.ar=tr;
						a.ac=tc;
						return a;
					} else if(sitrep.thing[tr][tc].hp!=10) {
						a.action=attack; 
						a.ar=tr;
						a.ac=tc;
						return a;
					}
				} else if(sitrep.thing[tr][tc].rank==crown) {
					a.action=attack;
					a.ar=tr;
					a.ac=tc;
					return a;
				}
			}
		}
	}	

	//head towards enemy crown. will attack any enemies in the way. 
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

	
}