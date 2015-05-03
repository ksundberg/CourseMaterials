#include "thl.h"
#include <cmath>
#include <iostream>


void thl::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{
	int tr,tc;
	Dir td;
	bool done=false;
	
	while(!done)
	{
		tr=minR+rand()%(5);	
		tc=minC+rand()%(6);	
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist))
	{
		if(cdist>0)td=rt;
		else td=lt;
	}
	else
	{
		if(rdist>0)td=up;
		else td=dn;
	}

	r=tr;
	c=tc;
	dir=td;
}



Action thl::Recommendation(SitRep sitrep)
{
	
	
	Action a; 

	
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
	
	if(rank==crown)
	{

			a.dir=up;
			a.action=fwd;
			return a;
	}
	
	if(rank==knight || rank==infantry || rank==archer)
	{
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

		if(dir==sitrep.nearestEnemy.dirFor)
		{
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight)a.maxDist=HORSESPEED;
			return a;
		} 
		else 
		{
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
	}

	a.action=nothing;
	return a;
	
}
