#include "alt.h"
#include "lionheart2.h"
#include <cmath>
#include <iostream>


void alt::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){//placement goes here.
	bool done=false;
	int tr,tc;
	Dir td;
	int placeC=minC; 
	int placeR=minR;
	int p=0,y=0;

	while(!done){
		tr=placeR;
		tc=placeC;
	/*	tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);
		if(placeR>maxR||placeR<minR){
		placeR=minR;placeC++;
		}placeR++; */
		
		if(p>5){
		placeR=minR;placeC++;p=0;
		}if(y<1){
				placeR=maxR-minR;
				placeC++;
				y++;		
		}if(y>1&&y<4){
			placeR=maxR-minR;
			y++;
			
		}
		p++;
		y++;
		placeR++;
		
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
Action alt::Recommendation(SitRep sitrep){
	
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
	if(rank==crown){
		if(dir==sitrep.nearestEnemy.dirFor){
		a.action=turn;
		a.dir=sitrep.anyOpenSpace;
		
		}else if (sitrep.thing[tr][tc].what==unit){
			a.action=turn;
			a.dir=sitrep.anyOpenSpace;
		}else if(sitrep.thing[tr][tc].what==rock) {
			a.action=turn;
			a.dir=sitrep.anyOpenSpace;
		}else{
			a.action=fwd;}
		a.maxDist=HORSESPEED;
		return a;
	}
	else if(rank==knight){
	
	
		if(dir==sitrep.nearestEnemyCrown.dirFor){
			a.action=fwd;
			a.maxDist=HORSESPEED;
		}else{
			a.action=turn;
			a.dir=sitrep.nearestEnemyCrown.dirFor;
		}
		
	return a;
	}
	else if(rank==infantry){
	
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=HORSESPEED;
		}else{
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			
		}
		
	return a;
	}
	if(rank==archer){
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=HORSESPEED;
		}else{
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			
		}
		return a;
	}
	// there is not an enemy in front of me
	// so head to the nearest enemy
/*	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	} */

	


a.action=nothing;
	return a;

}

