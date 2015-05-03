#include "ctu.h"
#include <cmath>
#include <iostream>


void ctu::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action ctu::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a;
    int dist;
    
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
        if(sitrep.thing[tr][tc].tla==tla){
            tr = rock;
            tc = rock;
        }
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
    /*
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
     */
    if(rank==crown && !dir==sitrep.nearestEnemyCrown.dirFor){
        a.action=fwd;
        a.maxDist = HORSESPEED;
    }if(rank==knight && dir==sitrep.nearestEnemyCrown.dirFor){
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            if(abs(sitrep.nearestEnemyCrown.r - r) || abs(sitrep.nearestEnemyCrown.r - r)){
                switch (dist){
                        
                        /*
                         
                         # of steps
                         loop
                       
                Dir pathDirFor(int sr, int sc, int er, int ec){
                         
                    int i,j;
                    bool changes=true;
                         
                    for(i=0;i<ROWS;++i){
                        for(j=0;j<COLS;++j){
                            map [i][j]=none;
                            map2[i][j]=none;
                            map3[i][j]=none;
                            map4[i][j]=none;
                            map5[i][j]=none;
                            map6[i][j]=none;
                        }
                    }
                    map [er][ec]=rt;
                    map2[er][ec]=rt;
                    map3[er][ec]=rt;
                    map4[er][ec]=rt;
                    map5[er][ec]=rt;
                    map6[er][ec]=rt;
                         
                };
                  */
                        
                    case 1:
                        a.maxDist=1;
                        break;
                    case 2:
                        a.maxDist=2;
                        break;
                    case 3:
                        a.maxDist=3;
                        break;
                    case 4:
                        a.maxDist=4;
                        break;
                    default:
                        break;
                }
 
 
            }else{
                a.maxDist=HORSESPEED;
            }
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemyCrown.dirFor;
            return a;
        }
    }
    
    if(rank==archer && dir==sitrep.nearestEnemyCrown.dirFor){
		a.action=fwd;
		a.maxDist=1;
		return a;
    }else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
    }
    if(rank==infantry && dir==sitrep.nearestEnemyCrown.dirFor){
		a.action=fwd;
		a.maxDist=1;
		return a;
    }else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
    }
	a.action=nothing;
	return a;
	
}
