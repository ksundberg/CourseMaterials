#include "tpa.h"
#include <cmath>
#include <iostream>


void tpa::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	int i,j;
	for(i=minR;i<=maxR;i++){
		for(j=minC;j<=maxC;j++){
			if(sitrep.thing[i][j].what==space){
				r=i;
				c=j;
			}
		}
	}
}

// tell someone what you want to do
Action tpa::Recommendation(SitRep sitrep){
	
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
	if(rank!=crown){
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight)a.maxDist=HORSESPEED;
			return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}

	}
	if(rank==crown){
		if(sitrep.nearestEnemy.c==sitrep.nearestEnemyCrown.c&&sitrep.nearestEnemy.r==sitrep.nearestEnemyCrown.r){
			if(dir==sitrep.nearestEnemy.dirFor){
				a.action=fwd;
				a.maxDist=HORSESPEED;
				return a;
			}
		}
		if(sitrep.nearestEnemy.dirFor==up&&dir==dn||sitrep.nearestEnemy.dirFor==dn&&dir==up||sitrep.nearestEnemy.dirFor==lt&&dir==rt||sitrep.nearestEnemy.dirFor==rt&&dir==lt){
			a.action=fwd;
			a.maxDist=HORSESPEED;
			return a;
		}
	}



	a.action=nothing;
	return a;
}
