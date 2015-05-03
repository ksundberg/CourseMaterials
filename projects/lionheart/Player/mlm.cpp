#include "mlm.h"
#include <cmath>
#include <iostream>


void mlm::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
        for (int r = minR; r <= maxR; r++) {
            for (int c = minC; c <= maxC; c++) {
                if (sitrep.thing[tr][tc].what == space) {
                    tr=minR+rand()%(maxR-minR);
                    tc=minC+rand()%(maxC-minC);
                    done=true;
                }
            }
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
Action mlm::Recommendation(SitRep sitrep){
	
	Action a;
    
	// first, see if there is a unit in front of you, if there is turn in a different direction.
    //But if you cannot move away from the unit--as there is no space behind you--then attack the unit attacking you.
	int tr=r,tc=c;
	switch(dir){
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
	}
	if(tr>0&&tr<ROWS&&tc>0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=turn;
                switch (dir) {
                    case up:
                        a.dir = lt;
                        break;
                    case dn:
                        a.dir = rt;
                        break;
                    case lt:
                        a.dir = dn;
                        break;
                    case rt:
                        a.dir = up;
                        break;
                    case none:
                        a.dir = none;
                }
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	} else if(tr==0&&tr<ROWS&&tc==0&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
                a.action = attack;
                a.ar=tr;
				a.ac=tc;
				return a;            }
        }
    }
	// if there is not an enemy in front of you move forward
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