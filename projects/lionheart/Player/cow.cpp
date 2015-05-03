#include "cow.h"
#include <cmath>
#include <iostream>


void cow::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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


// tell someone what you want to do
Action cow::Recommendation(SitRep sitrep){
	
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
	// instructions for each unit
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
    if(sitrep.turnNumber<=10){
        if(tr>=ROWS/2){
            switch(rank){
                case knight:
                    if(dir==sitrep.nearestEnemyCrown.dirFor){
                        a.action=fwd;
                        a.maxDist=HORSESPEED;
                        return a;
                    } else {
                        a.action=turn;
                        a.dir=sitrep.nearestEnemyCrown.dirFor;
                        return a;
                    }
                case infantry:
                    if(dir!=up){
                        a.action=turn;
                        a.dir=up;
                    } else {
                        a.action=fwd;
                        a.maxDist=1;
                    }
                case archer:
                    if(dir!=up){
                        a.action=turn;
                        a.dir=up;
                    } else {
                        a.action=fwd;
                        a.maxDist=1;
                    }
                case crown:
                    if(dir==sitrep.nearestEnemy.dirFor){
                        a.action=turn;
                        a.dir!=sitrep.nearestEnemy.dirFor;
                        return a;
                    } else {
                        a.action=fwd;
                        a.maxDist=HORSESPEED;
                        return a;
                    }
            }
        }
        if(tr<ROWS/2){
            switch(rank){
                case knight:
                    if(dir==sitrep.nearestEnemyCrown.dirFor){
                        a.action=fwd;
                        a.maxDist=HORSESPEED;
                        return a;
                    } else {
                        a.action=turn;
                        a.dir=sitrep.nearestEnemyCrown.dirFor;
                        return a;
                    }
                case infantry:
                    if(dir!=dn){
                        a.action=turn;
                        a.dir=dn;
                    } else {
                        a.action=fwd;
                        a.maxDist=1;
                    }
                case archer:
                    if(dir!=dn){
                        a.action=turn;
                        a.dir=dn;
                    } else {
                        a.action=fwd;
                        a.maxDist=1;
                    }
                case crown:
                    if(dir==sitrep.nearestEnemy.dirFor){
                        a.action=turn;
                        a.dir!=sitrep.nearestEnemy.dirFor;
                        return a;
                    } else {
                        a.action=fwd;
                        a.maxDist=HORSESPEED;
                        return a;
                    }
            }
        }
    }
    }
    
	// everyone except crown head to nearest enemy
	if(sitrep.turnNumber>10)
    if(rank==archer||rank==infantry||rank==knight){
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
    }
	a.action=nothing;
	return a;
	
}
