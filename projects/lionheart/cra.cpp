#include "cra.h"
#include <cmath>
#include <iostream>

void cra::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		tr=minR+rand()%(maxR-minR);
		if(maxC>COLS/2){
			if(rank==knight){
				tc=minC+1;
			}else if(rank==archer){
				//tc=minC+rand()%(maxC-minC);
				tc=minC+2;
			}else if(rank==infantry){
				tc=minC+3;
				if(sitrep.thing[tr][tc].what==unit){
					tc=minC+4;
				}
			}else if(rank==crown){
				tc=minC+5;
			}
		}
		if(minC<COLS/2){
			if(rank==crown){
				tc=minC;
			}else if(rank==infantry){
				//tc=minC+rand()%(maxC-minC);
				tc=minC+1;
				if(sitrep.thing[tr][tc].what==unit){
					tc=minC+2;
				}
			}else if(rank==archer){
				tc=minC+3;
			}else if(rank==knight){
				tc=minC+4;
			}
		}
		
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
Action cra::Recommendation(SitRep sitrep){

	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	int tr=r,tc=c;
	int dr=r,dc=c;

	switch(dir){
	case up: tr--; 
			 dr-=2;
			 break;
	case dn: tr++;
			 dr+=2;
			 break;
	case rt: tc++;
			 dc+=2;
			 break;
	case lt: tc--;
			 dc-=2;
			 break;
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
	if(dr>=0&&dr<ROWS&&dc>=0&&dc<COLS){
		if(sitrep.thing[dr][dc].what==unit){
			if(sitrep.thing[dr][dc].tla!=tla){
				a.action=attack;
				a.ar=dr;
				a.ac=dc;
				return a;
			}
		}
	}	
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if (rank==crown){
		if(dir!=up){
			a.action=turn;
			a.dir=up;
			return a;
		}else{
			a.action=fwd;
			a.maxDist=HORSESPEED;
			return a;
		}
	}
	if(dir==sitrep.nearestEnemy.dirFor){
		if (sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[dr][dc].tla!=tla){
				switch(dir){
				case up:
					a.action=turn;
					a.dir=lt;
					return a;
					break;
				case dn:
					a.action=turn;
					a.dir=rt;
					return a;
					break;
				case lt:
					a.action=turn;
					a.dir=dn;
					return a;
					break;
				case rt:
					a.action=turn;
					a.dir=up;
					return a;
					break;
				}
			}
		}else{
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
		}
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	/*

	Action a;
	int tr, tc;

	if(rank==archer){

	}else{
		switch (dir)
		{
		case up:
			tr--;
			break;
		case dn:
			tr++;
			break;
		case lt:
			tc--;
			break;
		case rt:
			tc++;
			break;
		case none:
			break;
		default:
			break;
		}
	}


	return a;
	*/

}
