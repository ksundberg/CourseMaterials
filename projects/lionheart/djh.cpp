#include "djh.h"
#include <cmath>
#include <iostream>


void djh::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{
	bool finished=false;
	int tr,tc;
	Dir td;
	while(!finished)
	{
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		if(sitrep.thing[tr][tc].what==space)finished=true;
	}
	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(unit==crown)
	{
		sitrep.nearestEnemy;
		tr=maxR;
		tc=maxC;
	}
	if(unit!=crown)
	{ 
		tr=maxR-1;
		tc=maxC-1;
	}
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


Action djh::Recommendation(SitRep s){
	
	Action a;
	int tr,tc;
	tr=r;
	tc=c;
	switch(dir){
	case up: tr--; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case dn: tr++; break;
	case none: exit(0); break;
	}
	
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(s.thing[tr][tc].what==unit&&s.thing[tr][tc].tla!=tla){
			a.action=attack;
			a.ar=tr;
			a.ac=tc;
			a.maxDist=1;
			a.dir=dir;
			return a;
		}
		if(unit==crown){
		a.action=nothing;
		tr=dn;
		tc=lt;

	}
		else if(s.nearestEnemyCrown.dirFor==dir){
			a.action=attack;
			a.action=fwd;
			a.maxDist=5;
			return a;
		}
		else if(s.nearestEnemy.dirFor==dir){
			a.action=attack;
			a.action=fwd;
			a.maxDist=5;
			return a;
		}
		else if(unit!=crown){
			a.action=turn;
			switch(s.nearestEnemy.dirFor){
			case up: a.dir=up; break;
			case dn: a.dir=dn; break;
			case lt: a.dir=lt; break;
			case rt: a.dir=rt; break;
			return a;
		}
		}
			else
			{
			a.action=turn;
			switch(s.nearestEnemyCrown.dirFor){
			case up: a.dir=up; break;
			case dn: a.dir=dn; break;
			case lt: a.dir=lt; break;
			case rt: a.dir=rt; break;
			return a;
		}
	}	
	a.action=nothing;
	return a;
}
}