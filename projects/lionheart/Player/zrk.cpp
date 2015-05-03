#include "zrk.h"
#include <cmath>
#include <iostream>

Dir enemySpawn;

void zrk::Place(int minR,int maxR,
        int minC,int maxC, SitRep sitrep){ 

			int tr,tc,spawnR=1,spawnC=1,unitCount=1;
			bool success=0;

			enemySpawn=sitrep.nearestEnemy.dirFor;

			if(enemySpawn==rt){
				while(!success){
					tr=minR+rand()%(1+maxR-minR);
					tc=minC+spawnR;
					if(sitrep.thing[tr][tc].what==space)success=true;
					++unitCount;
					if(unitCount==6)++spawnR;
					unitCount=1;
				}
				r=tr;
				c=tc;
			}
			if(enemySpawn==lt){
				while(!success){
					tr=minR+rand()%(1+maxR-minR);
					tc=maxC-spawnR;
					if(sitrep.thing[tr][tc].what==space)success=true;
					++unitCount;
					if(unitCount==6)++spawnR;
					unitCount=1;
				}
				r=tr;
				c=tc;
			}
			if (enemySpawn==up){
				while(!success){
					tr=maxR-spawnC;
					tc=minC+rand()%(1+maxC-minC);
					if(sitrep.thing[tr][tc].what==space)success=true;
					++unitCount;
					if(unitCount==6)++spawnC;
					unitCount=1;
				}
				r=tr;
				c=tc;
			}
			if (enemySpawn==dn){
				while(!success){
					tr=maxR+spawnC;
					tc=minC+rand()%(1+maxC-minC);
					if(sitrep.thing[tr][tc].what==space)success=true;
					++unitCount;
					if(unitCount==6)++spawnC;
					unitCount=1;
				}
				r=tr;
				c=tc;
			}
}

Action zrk::Recommendation(SitRep sitrep){

Action a;
int tr,tc;
tr=r;
tc=c;

if (sitrep.thing[r][c].rank==infantry||sitrep.thing[r][c].rank==knight){
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: exit(42); break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				return a;
			}
		}
	}
	if(dir==sitrep.nearestEnemy.dirFor&&sitrep.thing[tr][tc].what!=unit){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;

	} else {
		if(dir==sitrep.nearestEnemy.dirFor&&sitrep.thing[tr][tc].what==unit){
				a.dir=dn;
				if(a.dir==sitrep.thing[tr][tc].what!=unit){
					a.action=turn;
					return a;
				}else if(a.dir==sitrep.thing[tr][tc].what==unit){
					a.dir=up;
					a.action=turn;
					return a;
				} else if(a.dir==sitrep.thing[tr][tc].what==unit){
					a.dir=enemySpawn;
					a.action=turn;
					return a;
				}
		}
		a.action=turn;
		return a;
	}

}

if (sitrep.thing[r][c].rank==archer){
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: exit(42); break;
	}
	if(dir==sitrep.nearestEnemy.dirFor){
		a.ar=sitrep.nearestEnemy.r;
		a.ac=sitrep.nearestEnemy.c;
			if(abs(a.ar-r)>3 && abs(a.ac-c)>3){
				a.action=fwd;
				return a;
			}
		a.action=attack;
		return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
	}
}

if (sitrep.thing[r][c].rank==crown){
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: exit(42); break;
	}
	if(sitrep.thing[tr][tc].dir==sitrep.nearestEnemy.dirFor){
		switch(dir){
		case up: a.dir=dn; break;
		case dn: a.dir=up; break;
		case rt: a.dir=lt; break;
		case lt: a.dir=rt; break;
		}
		a.action=turn;
		return a;
	} else {
			if(sitrep.thing[tr][tc].dir!=sitrep.thing[tr][tc].what){
			a.dir=up;
			a.action=turn;
			return a;
			}
		a.action=fwd;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	}
}
}

