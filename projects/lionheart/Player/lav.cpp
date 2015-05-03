#include "lav.h"
#include <cmath>
#include <iostream>


void lav::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
    if(rank == crown)
    {
        for(int tr = minR; tr <= maxR; ++tr)
        {
            for(int tc = (minC + maxC) / 2; tc <= maxC; ++tc)
            {
                if(sitrep.thing[tr][tc].what == space)
                {
                    r = tr;
                    c = tc;
                    dir = up;
                    return;
                }
            }
        }
    }

    else
    {
        for(int tr = maxR; tr >= minR; --tr)
        {
            for(int tc = 0; tc <= maxC; ++tc)
            {
                if(sitrep.thing[tr][tc].what == space)
                {
                    r = tr;
                    c = tc;
                    dir = up;
                    return;
                }
            }
        }
    }

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
Action lav::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir){
	case up: tr++; break;
	case dn: tr--; break;
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
    // if crown, turn away
	if(dir==sitrep.nearestEnemy.dirFor){
        if(rank == crown)
        {
            a.action = turn;
            switch(dir)
            {
                case up: a.dir = dn; break;
                case dn: a.dir = up; break;
                case rt: a.dir = lt; break;
                case lt: a.dir = rt; break;
                case none: break;
            }
            return a;
        }
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
        // if crown, go away
        if(rank == crown)
        {
            a.action = fwd;
            a.maxDist = HORSESPEED;
            return a;
        }

		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;

		return a;
	}
	a.action=nothing;
	return a;
	
}
