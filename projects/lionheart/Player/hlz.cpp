#include "hlz.h"
#include <cmath>
#include <iostream>


void hlz::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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



Action hlz::Recommendation(SitRep sitrep){
	

	Action a; 

	int tr=r,tc=c;
	int count=1;
	int tempDir=0;
	switch(rank){
	case infantry:
		
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
			a.action=fwd;
			a.maxDist=1;
			return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action=nothing;
			break;
			
	case archer:

			
		while (count<=9){
			switch(dir){
			case up: tr--; break;
			case dn: tr++; break;
			case rt: tc++; break;
			case lt: tc--; break;
			case none: break;
			}
			count++;
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
			return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action=nothing;
		break;

	case knight:
	
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
			a.action=fwd;
			a.maxDist=HORSESPEED;
			return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action=nothing;
		break;

	case crown:
	
		
		switch(dir){
		case up: tr--; tempDir=1; break;
		case dn: tr++; tempDir=2; break;
		case rt: tc++; tempDir=3; break;
		case lt: tc--; tempDir=4; break;
		default: tempDir=2; break;
		}
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
			if(sitrep.thing[tr][tc].what==unit){
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=turn;
					switch(tempDir){
					case 1: a.dir=rt; break;
					case 2: a.dir=lt; break;
					case 3: a.dir=dn; break;
					case 4: a.dir=up; break;
					default: a.dir=dn; break;
					}
					return a;
				}
				else if(sitrep.thing[tr][tc].tla==tla){
					a.action=turn;
					switch(tempDir){
					case 1: a.dir=lt; break;
					case 2: a.dir=rt; break;
					case 3: a.dir=up; break;
					case 4: a.dir=dn; break;
					default: a.dir=up; break;
					}
					return a;
				}
				
				
			}
		}	
		
		if(dir!=sitrep.nearestEnemy.dirFor&&sitrep.thing[tr][tc].what==space){
			a.action=fwd;
			a.maxDist=HORSESPEED;
			return a;
		} else if(dir!=sitrep.nearestEnemy.dirFor&&sitrep.thing[tr][tc].what==rock){
			a.action=turn;
			switch(dir){
			case up: a.dir=rt; break;
			case dn: a.dir=lt; break;
			case rt: a.dir=dn; break;
			case lt: a.dir=up; break;
			case none: a.dir=up; break;
			}
		} else if(dir!=sitrep.nearestEnemy.dirFor&&sitrep.thing[tr][tc].what==unit){
			a.action=turn;
			switch(dir){
			case up: a.dir=rt; break;
			case dn: a.dir=lt; break;
			case rt: a.dir=dn; break;
			case lt: a.dir=up; break;
			case none: a.dir=dn; break;
			}
		} else {
			a.action=turn;
			switch(sitrep.nearestEnemy.dirFor){
			case up: a.dir=dn; break;
			case dn: a.dir=up; break;
			case rt: a.dir=lt; break;
			case lt: a.dir=rt; break;
			case none: a.dir=up; break;
			}
			return a;
		}
		a.action=nothing;
			break;
	}
	
}
