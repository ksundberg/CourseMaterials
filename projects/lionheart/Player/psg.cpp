#include "psg.h"
#include <cmath>
#include <iostream>


void psg::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action psg::Recommendation(SitRep sitrep){
	
	Action a;
    
    if(rank==crown){
        
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
        
        //if nothing in front of you turn and run away from the nearest enemy
        if(!(sitrep.nearestEnemy.dirFor==dir || sitrep.thing[tr][tc].what==rock || sitrep.thing[tr][tc].what==unit)){
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        }else{
            if(sitrep.thing[tr][tc].what==rock || sitrep.thing[tr][tc].what==unit){
                /*a.action=turn;
                a.dir=sitrep.anyOpenSpace;
                return a;*/
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
                    case rt:
                        a.action=turn;
                        a.dir=up;
                        return a;
                        break;
                    case lt:
                        a.action=turn;
                        a.dir=dn;
                        return a;
                        break;
                    case none: break;
                }
                
                }else{
                    switch(sitrep.nearestEnemy.dirFor){
                        case up:
                            a.action=turn;
                            a.dir=dn;
                            return a;
                            break;
                        case dn:
                            a.action=turn;
                            a.dir=up;
                            return a;
                            break;
                        case rt:
                            a.action=turn;
                            a.dir=lt;
                            return a;
                            break;
                        case lt:
                            a.action=turn;
                            a.dir=rt;
                            return a;
                            break;
                        case none: break;
                    }
                }
            }
        }
    
    if(rank==archer){
        
        // try to attack grid of nine squares ahead of you starting with the lower left from direction facing
        int tr=r,tc=c,i,j;
        switch(dir){
            case up:
                tr--;
                tc--;
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
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
                        tc++;
                    }
                    tr--;
                }
                break;
            case dn:
                tr++;
                tc++;
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
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
                        tc--;
                    }
                    tr++;
                }
                break;
            case rt:
                tc++;
                tr--;
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
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
                        tr++;
                    }
                    tc++;
                }
                break;
            case lt:
                tc--;
                tr++;
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
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
                        tr--;
                    }
                    tc--;
                }
                break;
            case none: break;
        }
        
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=1;
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemyCrown.dirFor;
            return a;
        }
 
    }
    
    if(rank==knight){
        
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
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemyCrown.dirFor;
            return a;
        }
        
    }
    
    if(rank==infantry){
        
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
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=1;
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemyCrown.dirFor;
            return a;
        }
        
    }
	a.action=nothing;
	return a;
	
}
