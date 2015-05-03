#include "jen.h"
#include "unit.h"
#include <cmath>
#include <iostream>

Action jen::archerRange(int tc, int tr, SitRep sitrep)
{
	Action a;
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
			int i, j;
			for(i=tr-1; i<=tr+1; i++)
			{
				for(j=tc-1; j<=tc+1; j++)
				{
					if(sitrep.thing[i][j].what==unit)
					{
						if(sitrep.thing[i][j].tla!=tla)
						{
							a.action=attack;
							a.ar=tr;
							a.ac=tc;
							return a;
						}
					}
				}
			}
				
			if(dir==sitrep.nearestEnemy.dirFor)
			{
				a.action=fwd;
				a.maxDist=1;
			}
			else 
			{
				a.action=turn;
				a.dir=sitrep.nearestEnemy.dirFor;
			}
		}
	
		return a;
	}

sideOfBoard jen::findSide (int minR,int maxR,int minC,int maxC)
{
	
	if(minC==0)
	{
		return blt;
	}
	else if(maxC==(COLS-1))
	{
		return brt;
	}
	else if(minR==0)
	{
		return bup;
	}
	else if(maxR==(ROWS-1))
	{
		return bdn;
	}
	else
	{
		if(COLS/2> maxC)
		{
			return blt;
		}
		else if(COLS/2< minC)
		{
			return brt;
		}
	}
}
void jen::setRand(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{
	bool done=false;
	int tr,tc;
	while(!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	/*int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=up;
		else td=dn;
	}*/
	r=tr;
	c=tc;
	dir=up;
}
void jen::Strat(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{
	
	dir = lt;
	if(rank == crown)
	{	
		r = minR;
		c = minC;
		return;
	}

	if(rank == knight)
	{
		if(sitrep.thing[(((maxR -minR)/2 + minR))+1][((maxC -minC)/2 + minC)].rank!=knight)
		{
			r = (((maxR -minR)/2 + minR))+1;
			c = ((maxC -minC)/2 + minC);
			return;
		}		
		else if(sitrep.thing[(((maxR -minR)/2 + minR))-1][((maxC -minC)/2 + minC)].rank!=knight)
		{
			r = (((maxR -minR)/2 + minR))-1;
			c = ((maxC -minC)/2 + minC);
			return;
		}
		else if(sitrep.thing[(((maxR -minR)/2 + minR))][(((maxC -minC)/2 + minC))+1].rank!=knight)
		{
			r = (((maxR -minR)/2 + minR));
			c = (((maxC -minC)/2 + minC))+1;
			return;
		}
		else if(sitrep.thing[(((maxR -minR)/2 + minR))][(((maxC -minC)/2 + minC))-1].rank!=knight)
		{
			r = (((maxR -minR)/2 + minR));
			c = (((maxC -minC)/2 + minC))-1;
			return;
		}
		else
		{
			setRand(minR, maxR, minC, maxC, sitrep);
			return;
		}
			

	}

	else if(rank == archer)
	{
		if(sitrep.thing[(((maxR -minR)/2 + minR))+1][(((maxC -minC)/2 + minC))+1].rank!=archer)
		{
			r = (((maxR -minR)/2 + minR))+1;
			c = (((maxC -minC)/2 + minC))+1;
			return;
		}		
		else if(sitrep.thing[(((maxR -minR)/2 + minR))+1][(((maxC -minC)/2 + minC))-1].rank!=archer)
		{
			r = (((maxR -minR)/2 + minR))+1;
			c = (((maxC -minC)/2 + minC))-1;
			return;
		}		
		else if(sitrep.thing[(((maxR -minR)/2 + minR))-1][(((maxC -minC)/2 + minC))-1].rank!=archer)
		{
			r = (((maxR -minR)/2 + minR))-1;
			c = (((maxC -minC)/2 + minC))-1;
			return;
		}
		else if(sitrep.thing[(((maxR -minR)/2 + minR))-1][(((maxC -minC)/2 + minC))+1].rank!=archer)
		{
			r = (((maxR -minR)/2 + minR))-1;
			c = (((maxC -minC)/2 + minC))+1;
			return;
		}		
		if(sitrep.thing[(((maxR -minR)/2 + minR))+2][(((maxC -minC)/2 + minC))+1].rank!=archer)
		{
			r = (((maxR -minR)/2 + minR))+2;
			c = (((maxC -minC)/2 + minC))+1;
			return;
		}		
		else if(sitrep.thing[(((maxR -minR)/2 + minR))+2][(((maxC -minC)/2 + minC))-1].rank!=archer)
		{
			r = (((maxR -minR)/2 + minR))+2;
			c = (((maxC -minC)/2 + minC))-1;
			return;
		}		
		else if(sitrep.thing[(((maxR -minR)/2 + minR))-2][(((maxC -minC)/2 + minC))-1].rank!=archer)
		{
			r = (((maxR -minR)/2 + minR))-2;
			c = (((maxC -minC)/2 + minC))-1;
			return;
		}
		else if(sitrep.thing[(((maxR -minR)/2 + minR))-2][(((maxC -minC)/2 + minC))-1].rank!=archer)
		{
			r = (((maxR -minR)/2 + minR))-2;
			c = (((maxC -minC)/2 + minC))+1;
			return;
		}
		else
		{
			setRand(minR, maxR, minC, maxC, sitrep);
			return;
		}
	}
	else if (rank==infantry)
	{
		sideOfBoard loca = findSide(minR, maxR, minC, maxC);
		if(loca==brt)
		{
			int i, j; 
			for(j=minC; j<maxC;j++)
			{
				for(i=minR; i<maxR; i++)
				{
					if(sitrep.thing[i][j].what==space)
					{
						r=i;
						c=j;
						return;
					}
				}
			}
		}
		if(loca==blt)
		{
			int i, j; 
			
			for(j=maxC; j>minC;j--)
			{
				for(i=maxR; i>minR; i--)
				{
					if(sitrep.thing[i][j].what==space)
					{
						r=i;
						c=j;
						return;
					}
				}
			}
		}
	}
}
void jen::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	
	sideOfBoard loca = findSide(minR, maxR, minC, maxC);
	dir=up;
	Strat(minR, maxR, minC, maxC, sitrep);
	if(loca == bup)
	{
		dir=dn;
	}
	else if(loca == bdn)
	{
		dir=up;
	}
	else if(loca == brt)
	{
		dir=lt;
	}
	else if(loca == blt)
	{
		dir=rt;
	}
	return;
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
Action jen::Recommendation(SitRep sitrep)
{	
	// this code is provided as an example only
	// use at your own risk
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
	if(rank==crown)
	{
		
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS)
		{
			if(sitrep.nearestEnemy.dirFor==up)
			{
				if(dir==dn)
				{
					a.action=fwd;
					a.maxDist=5;
				}
				else
				{
					a.action=turn;
					a.dir=dn;
				}
			}
			else if(sitrep.nearestEnemy.dirFor==dn)
			{
				if(dir==up)
				{
					a.action=fwd;
					a.maxDist=5;
				}
				else
				{
					a.action=turn;
					a.dir=up;
				}
			}
			if(sitrep.nearestEnemy.dirFor==lt)
			{
				if(dir==rt)
				{
					a.action=fwd;
					a.maxDist=5;
				}
				else
				{
					a.action=turn;
					a.dir=rt;
				}
			}
			if(sitrep.nearestEnemy.dirFor==rt)
			{
				if(dir==lt)
				{
					a.action=fwd;
					a.maxDist=5;
				}
				else
				{
					a.action=turn;
					a.dir=lt;
				}
			}
		}
		return a;
	}
	// first, try to attack in front of you
	if(rank!= archer)
	{
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
	}
	else if(rank==archer)
	{
		return archerRange(tc, tr, sitrep);
	}
			
	/*if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS)
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
	}	*/
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor)
	{
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} 
	else 
	{
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}

