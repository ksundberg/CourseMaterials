#include "usu.h"
#include <cmath>
#include <iostream>


void usu::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool dead=false;
	int tr,tc;
	Dir td;
	while(!dead){
		tr=minR+rand()%(1+maxR-minR);	
		tc=minC+rand()%(1+maxC-minC);	
		if(sitrep.thing[tr][tc].what==space)
			dead=true;
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

Action usu::Recommendation(SitRep ususitrep){
	
	Action usuAction; 

	//try to attack in front of me
	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: exit (15); break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(ususitrep.thing[tr][tc].what==unit){
			if(ususitrep.thing[tr][tc].tla!=tla){
				usuAction.action=attack;
				usuAction.ar=tr;
				usuAction.ac=tc;
				return usuAction;
			}
		}
	}	
	
	//if a unit is a knight go straight for crown
	if(rank==knight){
		if(ususitrep.nearestEnemyCrown.dirFor!=none){
			if(dir==ususitrep.nearestEnemyCrown.dirFor){
			usuAction.action=fwd;
			usuAction.maxDist=HORSESPEED;
			return usuAction;	
		}else{
			usuAction.action=turn;
			usuAction.dir=ususitrep.nearestEnemyCrown.dirFor;
			return usuAction;
			}
	}
		
}

	//if unit if crown, run away
	if(rank==crown){
		if(ususitrep.nearestEnemy.dirFor==rt){
			if(dir==lt){
				usuAction.action=fwd;
				usuAction.maxDist=1;
				return usuAction;
			}
			else{
				usuAction.action=turn;
				usuAction.dir=lt;
				return usuAction;
			}
		}
		if(ususitrep.nearestEnemy.dirFor==lt){
			if(dir==rt){
				usuAction.action=fwd;
				usuAction.maxDist=1;
				return usuAction;
			}
			else{
				usuAction.action=turn;
				usuAction.dir=rt;
				return usuAction;
			}
		}
		if(ususitrep.nearestEnemy.dirFor==up){
			if(dir==dn){
				usuAction.action=fwd;
				usuAction.maxDist=1;
				return usuAction;
			}
			else{
				usuAction.action=turn;
				usuAction.dir=dn;
				return usuAction;
			}
		}
		if(ususitrep.nearestEnemy.dirFor==dn){
			if(dir==up){
				usuAction.action=fwd;
				usuAction.maxDist=1;
				return usuAction;
			}
			else{
				usuAction.action=turn;
				usuAction.dir=up;
				return usuAction;
			}
		}
		if(dir==ususitrep.nearestEnemy.dirFor){
		usuAction.action=fwd;
		usuAction.maxDist=1;
		if(rank==knight||rank==crown)usuAction.maxDist=HORSESPEED;
		return usuAction;
	} 
}
	 else {
		usuAction.action=turn;
		usuAction.dir=ususitrep.nearestEnemy.dirFor;
		return usuAction;
		}

	//if unit if infantry, stand in front and protect archers
	if(rank==infantry){
		if(dir=ususitrep.nearestEnemy.dirFor){
		usuAction.action=fwd;
		usuAction.maxDist=1;
		if(rank==knight||rank==crown)usuAction.maxDist=HORSESPEED;
		return usuAction;
	} 
}
	else {
		usuAction.action=turn;
		usuAction.dir=ususitrep.nearestEnemy.dirFor;
		return usuAction;
		}

	//if unit if archer, stand in front and protect crown
	if(rank==archer){
		if(dir=ususitrep.nearestEnemy.dirFor){
		usuAction.action=fwd;
		usuAction.maxDist=1;
		if(rank==knight||rank==crown)usuAction.maxDist=HORSESPEED;
		return usuAction;
	} 
}
	else {
		usuAction.action=turn;
		usuAction.dir=ususitrep.nearestEnemy.dirFor;
		return usuAction;
		}

	// there is no one in front of me, charge closest enemy
	if(dir=ususitrep.nearestEnemy.dirFor){
		usuAction.action=fwd;
		usuAction.maxDist=1;
		if(rank==knight||rank==crown)usuAction.maxDist=HORSESPEED;
		return usuAction;
	} else {
		usuAction.action=turn;
		usuAction.dir=ususitrep.nearestEnemy.dirFor;
		return usuAction;
	}
	usuAction.action=fwd;
	return usuAction;
	
}
