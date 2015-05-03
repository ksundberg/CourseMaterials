#include "dre.h"
#include <cmath>
#include <iostream>


void dre::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		tr=(minR+rand()%(maxR-minR))/2;	
		tc=(minC+rand()%(maxC-minC))/2;	
		if(sitrep.thing[tr][tc].rank==crown)
		{
			int i; //trying to place dudes around crown
			for(i=1; i<(maxC)/2; i++)
			{
				if(sitrep.thing[tr-i][tc].what==space)done=true; r=tr-i; c=tc;
				if(sitrep.thing[tr+i][tc].what==space)done=true; r=tr+i; c=tc;
				if(sitrep.thing[tr][tc-i].what==space)done=true; c=tc-i; r=tr;
				if(sitrep.thing[tr][tc+i].what==space)done=true; c=tc+i; r=tr; 		
			}
		}
		else r=tr, c=tc;
		done=true;
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
	
	dir=td;
}


// tell someone what you want to do
Action dre::Recommendation(SitRep sitrep){
	
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
	if(dir==sitrep.nearestEnemyCrown.dirFor)
	{
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	}
	if(dir==sitrep.nearestEnemy.dirFor)
	{
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
