#include "zmk.h"
#include <cmath>
#include <iostream>


void zmk::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done = false;
	int td;

	static bool findcrown;
	static int csr, csc;
	int i, j, cr, cc;
	int tr = r;
	int tc = c;
	

	csr = (minR - ((maxR - minR) / 2));
		if(((maxR - minR) % 2) != 0) csr+=.5;
	csc = (minC - ((maxC - minC) / 2));
		if(((maxC - minC) % 2) != 0) csc+=.5;


	if(rank==crown){
	cr = (minR - ((maxR - minR) / 2));
		if(((maxR - minR) % 2) != 0) csr+=.5;
	cc = (minC - ((maxC - minC) / 2));
		if(((maxC - minC) % 2) != 0) csc+=.5;

	r = cr;
	c = cc;
	}

	if(rank==knight){

	cr = (minR - ((maxR - minR) / 2));
		if(((maxR - minR) % 2) != 0) csr+=.5;
	cc = (minC - ((maxC - minC) / 2));
		if(((maxC - minC) % 2) != 0) csc+=.5;

	r = (cr + 3);
	c = (cc + 3);
	}
	
	if(rank==archer){

	cr = (minR - ((maxR - minR) / 2));
		if(((maxR - minR) % 2) != 0) csr+=.5;
	cc = (minC - ((maxC - minC) / 2));
		if(((maxC - minC) % 2) != 0) csc+=.5;

	r = (cr + 2);
	c = (cc + 2);
	}


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


}

// tell someone what you want to do
Action zmk::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	int tr=r,tc=c;
	if(rank==archer){
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
	}
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
