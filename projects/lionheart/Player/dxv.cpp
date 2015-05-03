#include "dxv.h"
#include <cmath>
#include <iostream>


void dxv::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){

            if(rank==crown)
            {
                    if(minC < 10)
                        {
		tr=minR+(maxR-minR)/2;
		tc=minC;
                    }
                    else
                    {
                       tr=minR+(maxR-minR)/2;
                        tc=maxC;
                    }
		}
		else if(rank==knight)
          {
               if(minC < 10){
            tr=minR+rand()%(maxR-minR);
            tc=minC+1;
               }
 else
    {
         tr=minR+rand()%(maxR-minR);
            tc=maxC-1;
    }
		}
		else if(rank==archer)
          {
               if(minC < 10){
            tr=minR+rand()%(maxR-minR);
            tc=minC+2;
               }
 else
    {
         tr=minR+rand()%(maxR-minR);
            tc=maxC-2;
    }
		}
		else if(rank==infantry)
           {
               if(minC < 10){
            tr=minR+rand()%(maxR-minR);
            tc=minC+3;
               }
 else
    {
         tr=minR+rand()%(maxR-minR);
            tc=maxC-3;
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
Action dxv::Recommendation(SitRep sitrep){

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
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
            if(rank==crown)
                {
                    a.action=nothing;

                }
            else
                {
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
            }
		return a;
	} else {
	     if(rank==crown)
                {
                    a.action=nothing;

                }
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;

}
