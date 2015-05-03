#include "bot.h"
#include <cmath>
#include <iostream>


void bot::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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



Action bot::Recommendation(SitRep sitrep){
	

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
    if(rank==infantry || rank==archer){
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        else {a.dir=sitrep.nearestEnemyCrown.dirFor;
            a.action=turn;
            return a;
    }   }
    if(rank==knight){
        if(dir==sitrep.nearestEnemy.dirFor){
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        }else{
                a.action=turn;
                return a;
            }
            a.action=turn;
            a.dir=sitrep.nearestEnemy.dirFor;
            a.maxDist=HORSESPEED;
            return a;
        }
    if(rank==crown){
        if(dir==sitrep.nearestEnemy.dirFor || sitrep.thing[tr][tc].what==rock||tr==0||tr==ROWS||tc==0||tc==COLS){
            a.action=turn;
            a.maxDist=HORSESPEED;
            return a;
        }else{
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        }
    }
	a.action=nothing;
	return a;
	
}
