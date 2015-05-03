#include "cmd.h"
#include <cmath>
#include <iostream>


void cmd::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		if(rank==crown){
			if(maxR<ROWS/2){
				tr=minR;
				tc=minC+((maxC-minC+1)/2);
			}else if(minR>ROWS/2){
				tr=maxR;
				tc=minC+((maxC-minC+1)/2);
			} else if (maxC<COLS/2){
				tr=minR+((maxR-minR+1)/2);
				tc=minC;
			}else if (minC>COLS/2){
				tr=minR+((maxR-minR+1)/2);
				tc=maxC;
			}else{
				tr=minR+((maxR-minR+1)/2);
				tc=minC+((maxC-minC+1)/2);
			}
			if(sitrep.thing[tr][tc].what==space)done=true;}
		if(rank==knight||rank==infantry||rank==archer){
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
}

// tell someone what you want to do
Action cmd::Recommendation(SitRep sitrep){
	
	Action a; 

	if(rank==crown){
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
	//face nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=nothing;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	//do nothing
	a.action=nothing;
	return a;
}


	if(rank==archer){
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
	//go after a square
	switch(dir){
	case up: (tr-3&&(tc++||tc||tc--)); break;
	case dn: (tr+3&&(tc++||tc||tc--)); break;
	case rt: (tc+3&&(tr++||tr||tr--)); break;
	case lt: (tc-3&&(tr++||tr||tr--)); break;
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

	//go after the crown
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;}
	}
		
	
	if(rank==knight){
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
	//go after other knights
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
	return a;
}


	if(rank==infantry){
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

}