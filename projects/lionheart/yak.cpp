#include "yak.h"
#include <cmath>
#include <iostream>


void yak::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action yak::Recommendation(SitRep sitrep)
{
    
Action a;
    //make the king run into a corner
    if(rank==crown)
    {
        int tr=r, tc=c;
        if(dir==up)
        {
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        }
        if(dir==dn)
        {
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        }
        if(dir==lt)
        {
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(dir==rt)
        {
            a.action=turn;
            a.dir=dn;
            return a;
        }
        else if(sitrep.thing[tr][tc].what==unit)
        {
            a.action=turn;
            a.dir=sitrep.anyOpenSpace;
            return a;
        }
        
    }
    
//archer, knight, infantry, attack in front of them
else if(rank==archer || knight || infantry)
{
	int tr=r,tc=c;
	switch(dir)
    {
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
    
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS)
    {
		if(sitrep.thing[tr][tc].what==unit)
        {
			if(sitrep.thing[tr][tc].tla!=tla)
            {
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
                return a;
			}
		}
	}
    //if no attack, move to enemy crown
	if(dir==sitrep.nearestEnemyCrown.dirFor)
    {
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight)a.maxDist=HORSESPEED;
		return a;
	}
    else
    {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
}
    return a;
}
