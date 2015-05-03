#include "bug.h"
#include <cmath>
#include <iostream>


void bug::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){



	int tr,tc;
	tr=(minR+maxR)/2;
	tc=(minC+maxC)/2;
	if(rank==crown&&sitrep.thing[tr][tc].what==space){
		exit(0);
	} else{
		do{
			tr=1+minR+rand()%(maxR-minR);
			tc=1+minC+rand()%(maxC-minC);
		}while(sitrep.thing[tr][tc].what!=space);
	}




/*
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
*/
}

//tell someone what you want to do

Action bug::Recommendation(SitRep sitrep){


	Action a;
	int tr,tc;
	tr=r;
	tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none:  break;
	}

	if(sitrep.thing[tr][tc].what==unit)
	{
		if(sitrep.thing[tr][tc].tla!=tla)
		{
			a.action=attack;
		}
		else 
		{
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
		}
		return a;
	/*}else if(sitrep.thing[tr][tc].what==space&&dir=sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		if(unit==knight)a.maxDist=1;
		return a;*/
	}
	else if(sitrep.thing[tr][tc].what==space&&dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		return a;
	}else if(sitrep.thing[tr][tc].what==space&&dir!=sitrep.nearestEnemy.dirFor){
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}else{
		a.action=turn;
		switch(dir){
			case up: a.dir=rt; break;
			case dn: a.dir=lt; break;
			case lt: a.dir=up; break;
			case rt: a.dir=dn; break;
		}
	}




	/*
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
