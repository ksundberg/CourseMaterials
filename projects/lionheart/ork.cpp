#include "ork.h"
#include <cmath>
#include <iostream>
	
void ork::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	static int arcR=maxR;
	static int arcC;
	static int infR=maxR;
	static int infC;
	static int kniR=maxR;
	static int kniC;
	static float facingArmy; //0=left, 1=right
	int rdist, cdist;
	
	rdist=ROWS/2-minR;
	cdist=COLS/2-minC;
	if(abs(rdist)<abs(cdist))
		if(cdist>0)facingArmy=1;
		else facingArmy=-1;
	else
		facingArmy=0;
		if(facingArmy==1){
			arcC=maxC-2;
			infC=maxC-1;
			kniC=maxC-5;
			if(kniC<minC)kniC=minC;
		}
		if(facingArmy==0){
			arcC=minC+2;
			infC=minC+1;
			kniC=minC+5;
		}
	while(!done){
		if(rank==crown){
			if(facingArmy==1){
				tr=minR;
				tc=minC;
			
			}else{
				tr=maxR;
				tc=maxC;
			}
	
			}else{
				if(rank==knight){
					tr=kniR--;
					tc=kniC;
				}else{
					if(rank==archer){
						tr=arcR--;
						tc=arcC;
					}else{
						if(rank==infantry){
							tr=infR--;
							tc=infC;
						}
					}
				}
							if(tr<minR||tr>maxR||tc<minC||tc>maxC){
								tr=minR+rand()%(maxR-minR);	
								tc=minC+rand()%(maxC-minC);	
							}
		}
		if(sitrep.thing[tr][tc].what==space)done=true;
			}
	rdist=ROWS/2-tr;
	cdist=COLS/2-tc;
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


Action ork::Recommendation(SitRep sitrep){
	int ro=0, co=0;
	int selfR;
	int selfC;
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
	
		
		if(rank==archer){
			
		selfR=r;
		selfC=c;
		ro=sitrep.nearestEnemy.r;
		co=sitrep.nearestEnemy.c;
	switch(dir){
	
			case up:     
				if(selfR-ro<=3 && selfR>ro){
					if(selfC==co || selfC-1==co || selfC+1==co){
						tr=ro;
						tc=co;
						a.action=attack;
						a.ar=tr;
						a.ac=tc;
						return a;
					}
				}
				break;
			case dn: 
				if(ro-selfR<=3 && selfR<ro){
					if(selfC==co || selfC-1==ro || selfC+1==co){	
						tr=ro;
						tc=co;
						a.action=attack;
						a.ar=tr;
						a.ac=tc;
						return a;
					}
				}
				break;
			case lt: sitrep.nearestEnemy; 
				if(co+3 >=selfC && selfC>co){
					if(selfR==ro || selfR-1==ro || selfR+1==ro){
					
						tr=ro;
						tc=co;
						a.action=attack;
						a.ar=tr;
						a.ac=tc;
						return a;
					}
				}
				
				break;
			
			//done
			case rt: 
				if(selfC+3 >=co && selfC<co){
					if(selfR==ro || selfR-1==ro || selfR+1==ro){
						tr=ro;
						tc=co;
						a.action=attack;
						a.ar=tr;
						a.ac=tc;
						return a;
					}
				}
				break;
	}
		}
	}
		
	// there is not an enemy in front of me
	// so head to the nearest enemy
	
	if(rank==crown){ 
		if(abs(r-sitrep.nearestEnemy.r)<=6 && abs(c-sitrep.nearestEnemy.c)<=6){
			if(dir==sitrep.nearestEnemy.dirFor){
				a.action=turn;
				a.dir=dn;
					if(dn==sitrep.nearestEnemy.dirFor){
						a.dir=up;
					}
				return a;
			}
			a.action=fwd;
			a.maxDist=1;
			return a;
		}
	}

	/*
	if(rank==crown){
		a.action=nothing;
		return a;
	}
	*/
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}