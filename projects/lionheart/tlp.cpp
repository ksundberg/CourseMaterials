#include "tlp.h"
#include <cmath>
#include <iostream>


void tlp::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action tlp::Recommendation(SitRep sitrep){
	
	Action a; 

	// first, try to attack in front of you
	int tr=r,tc=c;
	if(rank!=archer){
		switch(dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){ //iS IN FRONT OF YOU IT ON THE BOARD?
			if(sitrep.thing[tr][tc].what==unit){ //IF YOUR LOOKING AT A UNIT...
				if(sitrep.thing[tr][tc].tla!=tla){ //IF THAT UNIT IS NOT ONE OF YOURS...
					a.action=attack; // KILL IT!
					a.ar=tr;
					a.ac=tc;
					return a;
				}
			}
		}	
	}else{ //Special case with archers
		switch(dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
		int i,j,ar=tr,ac=tc;
		for (int i=-1; i<2; i++)
		{for(int j=0; j<3; j++){
		
			switch(dir){
			case up: 
				ar=tr+i;
				ac=tc+j;
				break;
			case dn: 
				ar=tr+i;
				ac=tc-j;
				break;
			case rt: 
				ar=tr+j;
				ac=tc+i;
				break;
			case lt: 
				ar=tr-j;
				ac=tc+i;
				break;
			case none: break;
			}
			if(ar>=0&&ar<ROWS&&ac>=0&&ac<COLS){ //iS the spot ON THE BOARD?
			if(sitrep.thing[ar][ac].what==unit){ //IF it A UNIT...
				if(sitrep.thing[ar][ac].tla!=tla){ //is it ONE OF YOURS...
					a.action=attack; //send info to attack function
					a.ar=ar;
					a.ac=ac;
					return a;
				}
			}
		}
		
		}

		}
}
	// there is not an enemy in front of me
	// so head to the nearest enemy
	static int hide=0;
	switch(rank){
		case crown:
			/*if(sitrep.thing[tr][tc].what==rock){//if your looking at a rock		
			*/if(dir!=sitrep.nearestEnemy.dirFor){ //if your not facing the nearest enimy, run away!!!
						if(sitrep.thing[tr][tc].what==space){//if your looking at a space
						a.action=fwd;
						a.maxDist=1;
							if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
							//run off the board failsafe
							switch(dir){
							case up: tr-=HORSESPEED; break;
							case dn: tr+=HORSESPEED; break;
							case rt: tc+=HORSESPEED; break;
							case lt: tc-=HORSESPEED; break;
							case none: break;}
							if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS)
							{return a;}else{
							a.action=turn;
							switch (dir){
							case up:
							a.dir=rt;
							break;
							case rt:
							a.dir=dn;
							break;
							case dn:
							a.dir=lt;
							break;
							case lt:
							a.dir=up;
							break;}
							return a;
							}}else{a.action=turn;//if you not looking domewhere you can run to
							switch (dir){
							case up:
							a.dir=rt;
							break;
							case rt:
							a.dir=dn;
							break;
							case dn:
							a.dir=lt;
							break;
							case lt:
							a.dir=up;
							break;}
							return a;
							}

							
							
					} else { //Turn towards away from nearest enimy!
					a.action=turn;
					//a.dir=sitrep.nearestEnemy.dirFor;
					switch (dir){
							case up:
							a.dir=rt;
							break;
							case rt:
							a.dir=dn;
							break;
							case dn:
							a.dir=lt;
							break;
							case lt:
							a.dir=up;
							break;}
					return a;
			}
				a.action=nothing;
				return a;
			break;
	
		case archer:

			if(dir==sitrep.nearestEnemy.dirFor){//if your facing the nearest enimy, run twoards him!!!
				a.action=fwd;
				a.maxDist=1;
				if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
			
				return a;
			
			
			
			
			
			} else {//Turn towards your nearest enimy!
				a.action=turn;
				a.dir=sitrep.nearestEnemy.dirFor;
				return a;
			}
			a.action=nothing;
			return a;
			break;
		
		
		
		case knight: 
				if(dir==sitrep.nearestEnemy.dirFor){//if your facing the nearest enimy, run twoards him!!!
					a.action=fwd;
					a.maxDist=1;
						if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
						//however! if our running towards a a unit
						if(sitrep.thing[tr][tc].what==unit)
						{a.action=turn;
					//a.dir=sitrep.nearestEnemy.dirFor;
					switch (dir){
							case up:
							a.dir=rt;
							break;
							case rt:
							a.dir=dn;
							break;
							case dn:
							a.dir=lt;
							break;
							case lt:
							a.dir=up;
							break;}
					return a;}
						return a;
						
						
					} else {
						//Turn towards your nearest enimy!
					//if you turn what would you be facing?
						tr=r,tc=c;
						switch(sitrep.nearestEnemy.dirFor){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
						if(sitrep.thing[tr][tc].what==unit){ //IF YOU would be LOOKING AT A UNIT...
				if(sitrep.thing[tr][tc].tla==tla){ //IF THAT UNIT IS NOT ONE OF YOURS...
					a.action=fwd; // move foreward one!
					a.maxDist=1;
					return a;
				}
			}
						
						a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
					}
				a.action=nothing;
				return a;
			break;
		
		
		
		
		
		case infantry: 
				if(dir==sitrep.nearestEnemy.dirFor){ //if your facing the nearest enimy, run towards it!!!
						a.action=fwd;
						a.maxDist=1;
							if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
							return a;
					} else { //Turn towards your nearest enimy!
					a.action=turn;
					a.dir=sitrep.nearestEnemy.dirFor;
					return a;
			}
				a.action=turn;
				return a;
			break;
		
		}
	
	
}
