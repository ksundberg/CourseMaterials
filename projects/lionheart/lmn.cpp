#include "lmn.h"
#include <cmath>
#include <iostream>


void lmn::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc, k=0;
	Dir td;
	while(!done){
		if(rank == crown){
			tr=minR+rand()%(maxR-minR);	
			tc=maxC-5%(maxR-minR);
			if (!(tc > minC &&tc < maxC)){
				tc =tc=minC+rand()%(maxC-minC);}
			if(sitrep.thing[tr][tc].what==space)done=true;
		}
		if(rank == knight){
			tr=minR+rand()%(maxR-minR);	
			tc=(maxC-4)%(maxC-minC);	
			if (!(tc > minC &&tc < maxC)){
				tc =tc=minC+rand()%(maxC-minC);}
			if(sitrep.thing[tr][tc].what==space)done=true;
		
		}
		if(rank == archer){
			tr=minR+rand()%(maxR-minR);	
			tc=(maxC-3)%(maxC-minC);	
			if (!(tc > minC &&tc < maxC)){
				tc =tc=minC+rand()%(maxC-minC);}
			if(sitrep.thing[tr][tc].what==space)done=true;
			//if(sitrep.thing[tr][tc].what==unit)tc=minC+rand()%(maxC-minC);
		}
		if(rank == infantry){
			tr=minR+rand()%(maxR-minR);	
			tc=minC+rand()%(maxC-minC);	
			if(sitrep.thing[tr][tc].what==space)done=true;
		}
		else{
		tr=minR+rand()%(maxR-minR);	
		//tc=minC+rand()%(maxC-minC);	
		if(sitrep.thing[tr][tc].what==space)done=true;
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
Action lmn::Recommendation(SitRep sitrep){
	
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
	if (rank==crown){
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
	}
	if (rank != crown){
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
	}
	if (rank == crown){
		
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action= fwd;
			a.maxDist=1;
			if(rank==knight||rank==crown)a.maxDist=HORSESPEED*-1;
			return a;
		} else {
			a.action=turn;
			a.dir=(sitrep.nearestEnemy.dirFor);
			return a;
		}
	}
	
	if (rank == knight){
		if(dir==sitrep.nearestEnemyCrown.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown){
			
			a.maxDist=HORSESPEED;
		}
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
	a.action=nothing;
	return a;

	}
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown){
			
			a.maxDist=HORSESPEED;
		}
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}
