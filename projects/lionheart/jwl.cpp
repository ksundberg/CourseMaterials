#include "jwl.h"
#include <cmath>
#include <iostream>


void jwl::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
    

    while(!done){
        if(rank==crown){
            tc=minC;
            tr=minR;
        }else{
		tr=minR+rand()%(maxR-minR);
		tc=minC+rand()%(maxC-minC);
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

Action jwl::Recommendation(SitRep sitrep){
    Action a;
    SitRep s;
    
    a.dir=sitrep.nearestEnemy.dirFor;

	if(rank==crown){
            a.action=nothing;
            return a;
    }else if(rank==archer){
        a.action=attack;
        return a;
    }else if(rank==knight){
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
            if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemy.dirFor;
            return a;
        }
        a.action=nothing;
        return a;
    }else if(rank==infantry){
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
            if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemy.dirFor;
            return a;
        }
        a.action=nothing;
        return a;
    }else{
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
	
}
