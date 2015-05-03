#include "wmf.h"
#include <cmath>
#include <iostream>

void wmf::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	int tr=(maxR-minR+1)/2;
	int tc=(maxC-minC+1)/2;
	double offset=0;
	Dir td = sitrep.nearestEnemy.dirFor;
	if(td==none){
        int rdist=ROWS/2-tr;
        int cdist=COLS/2-tc;
        if(abs(rdist)<abs(cdist)){
            if(cdist>0)td=rt;
            else td=lt;
        }else{
            if(rdist>0)td=up;
            else td=dn;
        }
	}
	Dir nextDir=td;
	while(sitrep.thing[tr][tc].what!=space){
        switch(nextDir){
            case up: tr-=offset; nextDir=rt; break;
            case rt: tc+=offset; nextDir=dn; break;
            case dn: tr+=offset; nextDir=lt; break;
            case lt: tc-=offset; nextDir=up; break;
            case none: break;
        }
        if(tr>maxR)tr=maxR;
        if(tr<minR)tr=minR;
        if(tc>maxC)tc=maxC;
        if(tc<minC)tc=minC;
        offset+=.5;
	}
	r=tr;
	c=tc;
	dir=td;
}


// tell someone what you want to do
Action wmf::Recommendation(SitRep sitrep){

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
	if(rank==crown){
        if(dir==sitrep.nearestEnemy.dirFor){
            a.action=turn;
            switch(sitrep.nearestEnemy.dirFor){
                case up: a.dir=dn;break;
                case dn: a.dir=up;break;
                case rt: a.dir=lt;break;
                case lt: a.dir=rt;break;
            }
        } else {
            a.action=fwd;
        }
        return a;
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
