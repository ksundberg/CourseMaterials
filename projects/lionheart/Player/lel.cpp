#include "lel.h"
#include <cmath>
#include <iostream>


void lel::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
		tr=minR+0;	
		tc=minC+0;
	if(sitrep.thing[tr][tc].what==space&&rank==crown)done=true; //places king in the corner
			
	while(!done)
	{
		
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



Action lel::Recommendation(SitRep sitrep){
	
	
	Action a; 

	
	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS)
	{
		if(sitrep.thing[tr][tc].what==rock)
				a.action=turn;
		else if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}	


	if(sitrep.nearestEnemy.dirFor&&rank==crown) //king does nothing
		a.action=nothing;

	else if(dir==sitrep.nearestEnemy.dirFor&&rank!=crown){
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
