#include "mtc.h"
#include <cmath>
#include <iostream>


void mtc::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action mtc::Recommendation(SitRep sitrep)
{
	
	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	int tr = r,tc = c;
	switch(dir)
	{
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
	}
	if(tr >= 0  &&  tr < ROWS  &&  tc >= 0  &&  tc < COLS)
	{
		if(sitrep.thing[tr][tc].what == unit)
		{
			if(sitrep.thing[tr][tc].tla != tla)
			{
				a.action = attack;  
				a.ar = tr;
				a.ac = tc;
				return a;
			}
		}
	}	
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir == sitrep.nearestEnemy.dirFor &&  rank != crown  &&  rank !=knight)
	{
		a.action = fwd;
		a.maxDist = 1;
		//if(rank == knight)a.maxDist=HORSESPEED;
		return a;
	} 
	else if(rank != crown && rank != knight)
	{
		a.action = turn;
		a.dir = sitrep.nearestEnemy.dirFor;
		return a;
	}
	if (rank == knight)
	{
		if(dir == sitrep.nearestEnemyCrown.dirFor)
		{
			a.action = fwd;
			a.maxDist = HORSESPEED;
			return a;
		}
		else
		{
			a.action = turn;
			a.dir = sitrep.nearestEnemyCrown.dirFor;
			return a;
		}
	}
	if(rank == crown)
	{
		if(dir == sitrep.nearestEnemy.dirFor)
		{
			switch(sitrep.nearestEnemy.dirFor)
			{
			case up: 
				a.action = turn;
				a.dir = dn;
				return a;
				break;
			case dn: 
				a.action = turn;
				a.dir = up;
				return a;
				break;
			case rt: 
				a.action = turn;
				a.dir = lt;	
				return a;
				break;
			case lt:
				a.action = turn;
				a.dir = rt;	
				return a;

				break;
			case none:
				a.action = nothing;
				return a;
				break;
			}
		}
		else 
		{
			//a.action = fwd;
			//a.maxDist = HORSESPEED;
			//return a;
			
			if(dir == up)
			{
				if(sitrep.thing[tr-1][tc].what != rock  && sitrep.thing[tr-1][tc].what != unit)
				{
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
				else
				{
					a.action = turn;
					a.dir = rt;
					return a;
				}
			}
			else if(dir == dn)
			{
				if(sitrep.thing[tr+1][tc].what != rock  && sitrep.thing[tr+1][tc].what != unit)
				{
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
				else
				{
					a.action = turn;
					a.dir = lt;
					return a;
				}
			}
			else if(dir == rt)
			{
				if(sitrep.thing[tr][tc+1].what != rock  && sitrep.thing[tr][tc+1].what != unit)
				{
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
				else
				{
					a.action = turn;
					a.dir = dn;
					return a;
				}
			}
			else if(dir == lt)
			{
				if(sitrep.thing[tr][tc-1].what != rock  &&  sitrep.thing[tr][tc-1].what != unit)
				{
					a.action = fwd;
					a.maxDist = HORSESPEED;
					return a;
				}
				else
				{
					a.action = turn;
					a.dir = up;
					return a;
				}
			}
			
		}
	}
	a.action = nothing;
	return a;
	
}