#include "jrw.h"
#include <cmath>
#include <iostream>


void jrw::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action jrw::Recommendation(SitRep sitrep){
	Action a;
	int tr=r,tc=c;
	// first, try to attack in front of you


	switch(rank){
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
		int col1, col2, col3, row1, row2, row3;
		switch(dir){
			case up: row1=tr-3;row2=tr-2;row3=tr-1;col1=tc-1;col2=tc;col3=tc+1;break;
			case dn: row1=tr+3;row2=tr+2;row3=tr+1;col1=tc-1;col2=tc;col3=tc+1;break;
			case lt: row1=tr-1;row2=tr;row3=tr+1;col1=tc-1;col2=tc-2;col3=tc-3;break;
			case rt: row1=tr-1;row2=tr;row3=tr+1;col1=tc+1;col2=tc+2;col3=tc+3;break;
			case none: break;
		}
		if(isEnemy(col1, row1, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row1; //Set the attack location to the value of tr
			a.ac=col1; 
		}
		if(isEnemy(col2, row1, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row1; //Set the attack location to the value of tr
			a.ac=col2;
		}
		if(isEnemy(col3, row1, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row1; //Set the attack location to the value of tr
			a.ac=col3; 
		}
		if(isEnemy(col1, row2, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row2; //Set the attack location to the value of tr
			a.ac=col1; 
		}
		if(isEnemy(col2, row2, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row2; //Set the attack location to the value of tr
			a.ac=col2; 
		}
		if(isEnemy(col3, row2, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row2; //Set the attack location to the value of tr
			a.ac=col3; 
		}
		if(isEnemy(col1, row3, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row3; //Set the attack location to the value of tr
			a.ac=col1; 
		}
		if(isEnemy(col3, row3, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row3; //Set the attack location to the value of tr
			a.ac=col3; 
		}
		if(isEnemy(col2, row3, sitrep)){
			a.action=attack; //Set the recommended action to attack
			a.ar=row3; //Set the attack location to the value of tr
			a.ac=col2; 
			return a;
		}
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			return a;
		}
		else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action=nothing;
			break;
		case crown:
			if (sitrep.nearestEnemy.dirFor == up){
				a.dir = dn;
			}
			else if (sitrep.nearestEnemy.dirFor == dn){
				a.dir = up;
			}
			else if (sitrep.nearestEnemy.dirFor == lt){
				a.dir = rt;
			}
			else if (sitrep.nearestEnemy.dirFor == rt){
				a.dir = lt;
			}
			a.action = fwd;
			a.maxDist = HORSESPEED;
			return a;
			break;
	}
	return a;
}

bool jrw::isEnemy(int tr, int tc, SitRep sitrep){
	if (sitrep.thing[tr][tc].what==unit){
		if (sitrep.thing[tr][tc].tla!=tla){
			return true;
		}
	}
	return false;
}
