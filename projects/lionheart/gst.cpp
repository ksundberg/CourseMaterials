#include "gst.h"
#include <cmath>
#include <iostream>


void gst::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	
	int crownRow, crownCol;
	

	Dir td;

	if(rank==crown){
		crownCol=minC+maxC/6;
		crownRow=minR+maxR/6;
		while(sitrep.thing[crownCol][crownRow].what!=space){
			if(crownCol+1 < maxC && crownRow+1 < maxR){
				crownCol++;
				crownRow++;
			}else if(crownCol-1 < maxC){
				crownCol--;
			}
		}
	
		r=crownRow;
		c=crownCol;
		dir=up;

		if(rank ==knight){
			r= crownRow+1;
			c= crownCol+1;
			dir=sitrep.anyOpenSpace;
		}

		if(rank == infantry){
			r=crownRow+2;
			c=crownCol+4;
			dir=sitrep.nearestEnemy.dirFor;
		}

		
		
	
	

		}else{


	while(!done){
		tr=minR+rand()%(maxR-minR)+1;	
		tc=minC+rand()%(maxC-minC)+1;	
		if(sitrep.thing[tr][tc].what==space)done=true;
		int rdist=ROWS/7-tr;
	int cdist=COLS/7-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=sitrep.anyOpenSpace;
		else td=sitrep.nearestEnemy.dirFor;
	}
	}
	
	r=tr;
	c=tc;
	dir=td;
	
	}
}
	
	

// tell someone what you want to do
Action gst::Recommendation(SitRep sitrep){

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

 //there is not an enemy in front of me
	// so head to the nearest enemy
if(rank == infantry || rank == knight){
		if(sitrep.nearestEnemy.dirFor!=none){
			if(dir==sitrep.thing[tr][tc].what != space){
				a.dir=sitrep.anyOpenSpace;
				a.action=fwd;
				a.maxDist=1;
				if(rank == knight){
					a.maxDist=HORSESPEED;
					}
				if(sitrep.thing[tr][tc].what ==unit){
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
				}

				if(sitrep.thing[tr][tc].what ==rock){
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
				}

				if(sitrep.thing[1][tc].what !=space){
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
				}

			

				



				return a;
				
				
					
					}else{
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
			}
	}
	
	} 
	
	if(sitrep.nearestEnemyCrown.dirFor!=none && rank == archer){
		if(sitrep.nearestEnemy.dirFor!=none){
			if(dir==sitrep.thing[tr][tc].what != space){
				a.dir=sitrep.anyOpenSpace;
				a.action=fwd;
				a.maxDist=1;
				if(rank == knight){
					a.maxDist=HORSESPEED;
					}
				if(sitrep.thing[tr][tc].what ==rock){
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
				}

			if(sitrep.thing[tr][tc].what ==unit){
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
				}

			if(sitrep.thing[1][tc].what !=space){
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
				}
				return a;
					}else{
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
			}
	}
	
	} 

	if(sitrep.nearestEnemyCrown.dirFor!=none && rank == crown){
		a.action=fwd;
		return a;

		if(sitrep.thing[1][tc].what !=space){
			a.dir=dn;
			return a;
		}

		if(sitrep.thing[1][tc].what ==rock){
			if(sitrep.anyOpenSpace){
			a.dir=sitrep.nearestEnemy.dirFor;
			a.action=nothing;
			return a;
			}
		}
	}
}