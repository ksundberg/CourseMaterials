#include "jmf.h"
#include <cmath>
#include <iostream>


void jmf::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr=0,tc=0;
	Dir td;

	while(!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);
		if(sitrep.thing[tr][tc].what==unit){
			if(rank==crown){
				if(sitrep.thing[tr-1][tc].what==space){
					tr=tr-1;
					tc=tc;
					done=true;
				}
				if(sitrep.thing[tr-1][tc+1].what==space){
					tr=tr-1;
					tc=tc+1;
					done=true;
				}
				if(sitrep.thing[tr][tc+1].what==space){
					tr=tr;
					tc=tc+1;
					done=true;
				}
				if(sitrep.thing[tr+1][tc+1].what==space){
					tr=tr+1;
					tc=tc+1;
					done=true;
				}
				if(sitrep.thing[tr+1][tc].what==space){
					tr=tr+1;
					tc=tc;
					done=true;
				}
				if(sitrep.thing[tr+1][tc-1].what==space){
					tr=tr+1;
					tc=tc-1;
					done=true;
				}
				if(sitrep.thing[tr][tc-1].what==space){
					tr=tr;
					tc=tc-1;
					done=true;
				}
				if(sitrep.thing[tr-1][tc-1].what==space){
					tr=tr-1;
					tc=tc-1;
					done=true;
				}
			}
		}
		else{
			if(tr==minR+((maxR-minR)/2)&&tc==minC+((maxC-minC)/2)){
				sitrep.thing[tr][tc].what=unit;
				//rank=crown;
				done=true;
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
}

	Action jmf::Recommendation(SitRep sitrep){

		Action a; 

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
				if(rank==crown){
					if(dir!=up){
						a.action=turn;
						a.dir=up;
						return a;
					}
					else{a.action=fwd; return a;}
				}
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					a.ar=tr;
					a.ac=tc;
					return a;
				}
			}
		}	
		if(dir==sitrep.nearestEnemyCrown.dirFor){
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

	//Jaedon Flake, A01689259, Section 002