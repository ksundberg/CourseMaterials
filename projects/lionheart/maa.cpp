#include "maa.h"
#include <cmath>
#include <iostream>


void maa::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;

	tr=minR;
	tc=minC;

	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=up;
		else td=dn;
	}

	while(!done){
		//crown
		if(rank==crown){
			tr=((maxR-minR)/2)+minR;
			tc=((maxC-minC)/2)+minC;
			if(sitrep.thing[tr][tc].what=space)done=true;
			else switch(td){
				case up: --tr; break;
				case dn: ++tr; break;
				case rt: ++tc; break;
				case lt: --tc; break;
				case none: exit(1); break;
			}
	}
	//not crown
		else{
			while(tr!=maxR){
			if(sitrep.thing[tr][tc].what==space){
				r=tr;
				c=tc;
				dir=sitrep.nearestEnemy.dirFor;
				done=true;
			}
			++tr;
		}
			if(tr==maxR){
			tr=minR;
			++tc;
			}
		if(sitrep.thing[tr][tc].what==space)done=true;
		}
	}
	r=tr;
	c=tc;
	dir=td;
}


// tell someone what you want to do
Action maa::Recommendation(SitRep sitrep){
	Action a; 

	//space in front of me
	int tr=r;
	int tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}

	//infantry
	if(rank==infantry){
	//find space 2 spaces ahead
	int dr=r,dc=c;
	switch(dir){
	case up: dr-=2; break;
	case dn: dr+=2; break;
	case rt: dc+=2; break;
	case lt: dc-=2; break;
	case none: break;
	}
	//attack the space in front of me
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
	//no one in front of me, check for crown
	if(sitrep.thing[dr][dc].rank==crown&&sitrep.thing[dr][dc].tla!=tla){
		a.action=fwd;
		a.maxDist=1;
		return a;
	}
	//facing the enemy, not the crown
	if(dir==sitrep.nearestEnemy.dirFor){
		//2 spaces away is not an enemy unit or is an archer
		if((sitrep.thing[dr][dc].what!=unit&&sitrep.thing[dr][dc].tla!=tla)||sitrep.thing[dr][dc].rank==archer){
		a.action=fwd;
		a.maxDist=1;
		return a;
		}
		//is an enemy, not an archer
		else{
			a.action=nothing;
			return a;
		}
		//not facing the enemy
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}

	}
	//archer
	if(rank==archer){
	//attack the space in front of me
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
	//find the 3x3 square in front of me, starting at left bottom coner
	bool enemy=false;
	int i, j;
	switch(dir){
		case up: for(i=tr;i<tr+4;--i){
					for(j=tc-1;i<tc+2;++j){
						if(sitrep.thing[i][j].what==unit&&sitrep.thing[i][j].tla!=tla){enemy=true;break;}
					}
				}
				break;
		case dn: for(i=tr;i<tr+4;++i){
					for(j=tc-1;i<tc+2;++j){
						if(sitrep.thing[i][j].what==unit&&sitrep.thing[i][j].tla!=tla){enemy=true;break;}
					}
				}
				break;
		case lt: for(j=tc;i<tc+4;--j){
					for(i=tr+1;i<tr-2;--i){
						if(sitrep.thing[i][j].what==unit&&sitrep.thing[i][j].tla!=tla){enemy=true;break;}
					}
				}
				break;
		case rt: for(j=tc;i<tc+4;++j){
					for(i=tr+1;i<tr-2;--i){
						if(sitrep.thing[i][j].what==unit&&sitrep.thing[i][j].tla!=tla){enemy=true;break;}
					}
				}
				break;
		}
	//if I found an enemy, attack it
	if(enemy){
		a.action=attack;
		a.ar=i;
		a.ac=j;
		return a;
	}
	//if I'm facing the enemy
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		return a;
	}
	//not facing the enemy
	else{
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
}
	//knight
	if(rank==knight){
	static int wait=0;
	++wait;
	//enemy in front of me
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
	//wait 3 turns
		if(wait>2){
		//go for crown
			if(dir==sitrep.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=HORSESPEED;
				return a;
			}
			else{
				a.action=turn;
				a.dir=sitrep.nearestEnemyCrown.dirFor;
				return a;
			}
		}
	}
	//crown
	if(rank==crown){
		//just run
		switch(sitrep.nearestEnemy.dirFor){
			case up: if(dir==up){a.action=turn; a.dir=sitrep.anyOpenSpace;}
						else{a.action=fwd; a.maxDist=HORSESPEED;}
						return a; break;
			case dn: if(dir==dn){a.action=turn; a.dir=sitrep.anyOpenSpace;}
						else{a.action=fwd; a.maxDist=HORSESPEED;}
						return a; break;
			case rt: if(dir==rt){a.action=turn; a.dir=sitrep.anyOpenSpace;}
						else{a.action=fwd; a.maxDist=HORSESPEED;}
						return a; break;
			case lt: if(dir==lt){a.action=turn; a.dir=sitrep.anyOpenSpace;}
						else{a.action=fwd; a.maxDist=HORSESPEED;}
						return a; break;
			case none: a.action=nothing; return a; break;
		}
	}

	//I don't know who you are or how you made it this far
	//so go attack the enemy
	//todo
}