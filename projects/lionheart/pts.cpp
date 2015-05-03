#include "pts.h"
#include <cmath>
#include <iostream>


void pts::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action pts::Recommendation(SitRep sitrep){
 
	Action a;
    
    //king should move away from enemy units and keep moving
    int tr=r;
    int tc=c;
    
    if(rank==crown){
        a.maxDist=HORSESPEED;
        if(dir==up){     //set it so the crown turns around after hitting the edge of the board
            a.action=fwd;
            return a;
            }
        else {
            a.action=turn;
            return a;
            }
        return a;
        }
//Infantry charge and attack enemy units
//Sometimes it seems my units like to attack our king...
    switch(dir){
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
    }
    if(rank==infantry){
        if(sitrep.thing[tr][tc].what==unit){
            if (sitrep.thing[tr][tc].tla!=tla){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
                }
            }
        }
   //knights should hunt down the enemy crown and attack enemy units in the way
// use nearestEnemyCrown function to figure out where the enemy king is and the follow him.
    if(rank==knight){
        a.maxDist=HORSESPEED;
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            if (sitrep.thing[tr][tc].tla!=tla){
                a.action=fwd;
            a.action=attack;
            return a;
            }
            
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemyCrown.dirFor;
            return a;
            }
        }
    if(sitrep.thing[tr][tc].what==unit){
        if (sitrep.thing[tr][tc].tla!=tla) {
            a.action=attack;
            return a;
            }
        }
    //archers
    if(rank==archer){
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            return a;
        } else {
            if (sitrep.thing[tr][tc].tla!=tla){
                a.action=turn;
            a.action=attack;
            a.dir=sitrep.nearestEnemyCrown.dirFor;
                return a;}
        }
    }
        if(sitrep.thing[tr][tc].what==unit){
            if (sitrep.thing[tr][tc].tla!=tla){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }
        
return a;}
