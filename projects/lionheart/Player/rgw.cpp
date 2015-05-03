#include "rgw.h"
#include <cmath>
#include <iostream>

	void rgw::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
	}
	else{
		if(rdist>0)td=up;
		else td=dn;
	}
	r=tr;
	c=tc;
	dir=td;
}



Action rgw::Recommendation(SitRep sitrep){
	
	Action a; 

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
				if(rank == archer || rank == infantry || rank == knight){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
				}
				else{
					a.action=turn;
					a.action=attack;
			}

		}
	}
}
	
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		a.action=attack;
		if(rank==crown){
			a.maxDist=1;
			a.action=attack;
			
		}

		if(rank == knight) {
			a.maxDist=HORSESPEED;
			a.action= attack;
			
		}

		if(rank==infantry){
			a.maxDist=1;
			a.action = attack;
			
		}
		if(rank== archer){
			a.maxDist=1;
			a.action= attack;
			
		}

	}
	else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;




	
}
