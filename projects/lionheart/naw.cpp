#include "naw.h"
#include <cmath>
#include <iostream>


void naw::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr=6,tc=6;
	int lr=maxR,lc=maxC;   //records the last row and column visited
	Dir td=none;
	while(!done){
		
		done=false;
		if(rank == crown){
			tr = (maxR-minR);
			tc = (maxC-minC);
			done = true;
			lr=tr;
			lc=tr;
		}
		if(rank == archer){
				if(tr==lr){
					tr= lr-1;
					tc= lc;
				}
				else if(tc==lc){
					tr = lr;
					tc= lc-1;
				}
				else{
					tr=minR;
					tc=maxC;
				}
				if(sitrep.thing[tr][tc].what==space)done=true;
			int rdist=ROWS/2-tr;
			int cdist=COLS/2-tc;
			if(abs(rdist)<abs(cdist)){
				if(cdist>0)td=rt;
				else td=lt;
			}else{
				if(rdist>0)td=up;
				else td=dn;
			}
			lr=tr;
			lc=tc;
		}
		if(rank==infantry){
			if(tr==lr){
				tr = lr-1;
				tc = lc;
			}
			else if(tc==lc){
				tr = lr;
				tc = lc-1;
			}else{
					tr=minR-2;
					tc=maxC-2;
			}
			
			if(sitrep.thing[tr][tc].what==space)done=true;
			int rdist=ROWS/2-tr;
			int cdist=COLS/2-tc;
			if(abs(rdist)<abs(cdist)){
				if(cdist>0)td=rt;
				else td=lt;
			}else{
				if(rdist>0)td=up;
				else td=dn;
			}
			lr=tr;
			lc=tc;
	
		}

		if(rank==knight){
			if(tr==lr){
				tr = lr-1;
				tc = lc;
			}
			else if(tc==lc){
				tr = lr;
				tc = lc-1;
			}else{
					tr=minR-1;
					tc=maxC-1;
			}
			if(sitrep.thing[tr][tc].what==space)done=true;
			int rdist=ROWS/2-tr;
			int cdist=COLS/2-tc;
			if(abs(rdist)<abs(cdist)){
				if(cdist>0)td=rt;
				else td=lt;
			}else{
				if(rdist>0)td=up;
				else td=dn;
			}
			lr=tr;
			lc=tc;
		}
		r=tr;
		c=tc;
		dir=td;
		
	}

	
	/*while(!done){
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
	dir=td;*/
}


// tell someone what you want to do
Action naw::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk

	Action a; 

	if(rank == crown){
		int tr=r,tc=c;		//attack
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
		a.action=nothing;
	}
	
	if(rank==archer){  //archer strategy
		int tr=r,tc=c;		//attack
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
		if(dir==sitrep.nearestEnemy.dirFor){  //move towards enemy
		a.action=fwd;
		a.maxDist=1;
		return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
	}

	if(rank==infantry){   //infantry strategy
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
		if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
	}

	if(rank==knight){  //knight strategy
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
		if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=HORSESPEED;
		return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}

	}
	
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
	
}
