#include "sd9.h"
#include <cmath>
#include <iostream>
//yup

void sd9::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr=0,tc=0;
    static int kr=0,kc=0;
	Dir td;
    
    if(rank==crown)//king in back
    {
        if(maxC<(COLS/2)){
            kr=maxR-minR;
            kr/=2;
            kr=minR+kr;
            kc=minC;
            int r1dist=ROWS/2-kr;
            int c1dist=COLS/2-kc;
        
            if(abs(r1dist)<abs(c1dist)){
                if(c1dist>0)td=rt;
                else td=lt;
            }else{
                if(r1dist>0)td=up;
                else td=dn;
            }
        }else{
            kr=maxR-minR;
            kr/=2;
            kr=minR+kr;
            kc=maxC;
            int r1dist=ROWS/2-kr;
            int c1dist=COLS/2-kc;
            
            if(abs(r1dist)<abs(c1dist)){
                if(c1dist>0)td=rt;
                else td=lt;
            }else{
                if(r1dist>0)td=up;
                else td=dn;
            }
        }
        
        
        r=kr;
        c=kc;
        dir=td;
    }else if (rank==knight){//knights in the front
        
        if(maxC<(COLS/2)){
            while(!done)
            {
            tr=minR+rand()%(maxR-minR);
            tc=maxC;
                if(sitrep.thing[tr][tc].what==space) done=true;
            }
            int r1dist=ROWS/2-kr;
            int c1dist=COLS/2-kc;
            
            if(abs(r1dist)<abs(c1dist)){
                if(c1dist>0)td=rt;
                else td=lt;
            }else{
                if(r1dist>0)td=up;
                else td=dn;
            }
        }else{
            while(!done)
            {
            tr=minR+rand()%(maxR-minR);
            tc=minC;
            if(sitrep.thing[tr][tc].what==space) done=true;
        }
            int r1dist=ROWS/2-tr;
            int c1dist=COLS/2-tc;
            
            if(abs(r1dist)<abs(c1dist)){
                if(c1dist>0)td=rt;
                else td=lt;
            }else{
                if(r1dist>0)td=up;
                else td=dn;
            }
        }
        
        
        r=tr;
        c=tc;
        dir=td;
        
       }else{
        while(!done)
        {
            tr=minR+rand()%(maxR-minR);
            tc=minC+rand()%(maxC-minC);
            if(sitrep.thing[tr][tc].what==space&&!(tr==kr &&tc==kc))done=true;
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
}

// tell someone what you want to do
Action sd9::Recommendation(SitRep sitrep){
	
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
    if(rank==crown){
        if(dir==sitrep.nearestEnemy.dirFor){
            a.action=nothing;
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemy.dirFor;
            return a;
        }
    }
    if(rank==knight){//nights go for crown
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=1;
            if(rank==knight)a.maxDist=HORSESPEED;
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemyCrown.dirFor;
            return a;
        }

        
    }
    
    
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
        return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}
