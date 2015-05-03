#include "kac.h"
#include <cmath>
#include <iostream>


void kac::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action kac::Recommendation(SitRep sitrep)
{

	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(rank == infantry || rank == knight || rank == crown)
	{														//want those three to check the dir,
		if(tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS)	//see if there's someone to attack,												
		{													//attack, and if there's no one there
			if (sitrep.thing[tr][tc].what == unit)			//then move									
			{
				if (sitrep.thing[tr][tc].tla != tla)
				{
					a.action=attack;
					a.ar=tr;	
					a.ac=tc;
					return a;	
				}
			}
			else if(dir==sitrep.nearestEnemy.dirFor)
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
		else
		{
			if(tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS)
			{
				int move = rand()%2+1;
				bool willMove = false;
				if (move == 1)
					willMove = true;
					
				if (sitrep.thing[tr][tc].what == space)
				{
					if (sitrep.thing[tr-2][tc].what == unit)
					{
						if (sitrep.thing[tr-2][tc].tla == tla)
						{
							if (dir == up)
							{
								if (rank == crown && willMove == true)
									tr--;
								else if (rank != crown)
									tr--;
							}
						}
					}
					else if (sitrep.thing[tr+2][tc].what == unit)
					{
						if (sitrep.thing[tr+2][tc].tla == tla)
						{
							if (dir == dn)
							{
								if (rank == crown && willMove == true)
									tr++;
								else if (rank != crown)
									tr++;
							}
						}
					}
					else if (sitrep.thing[tr][tc+2].what == unit)
					{
						if (sitrep.thing[tr][tc+2].tla == tla)
						{
							if (dir == rt)
							{
								if (rank == crown && willMove == true)
									tc++;
								else if (rank != crown)
									tc++;
							}
						}
					}
					else if (sitrep.thing[tr][tc-2].what == unit)
					{
						if (sitrep.thing[tr][tc-2].tla == tla)
						{
							if (dir == lt)
							{
								if (rank == crown && willMove == true)
									tc--;
								else if (rank != crown)
									tc--;
							}
						}
					}
				}

			}

		}

	}		


	else if (rank == archer)
	{	
		tr = r;
		tc = c;
		if(tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS)//want the archer to do the same thing as the others
		{												//but with longer range to attack
			switch(dir){
			case up: tr-=3; tc--; break;
			case dn: tr+=3; tc++; break;
			case rt: tr--; tc+=3; break;
			case lt: tr++; tc-=3; break;
			case none: break;
			}
			for(int i = 0; i < 3; i++,tr++)
			{
				for(int j = 0; j < 3; j++,tc++)
				{
					if (sitrep.thing[tr][tc].what == unit)	
					{
						if (sitrep.thing[tr][tc].tla != tla)
						{
							a.action=attack;
							a.ar=tr;
							a.ac=tc;
							return a;
						}
						else if(dir==sitrep.nearestEnemy.dirFor)
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
				}
			}
			tr = r;
			tc = c;
			switch(dir){
			case up: tr--; break;
			case dn: tr++; break;
			case rt: tc++; break;
			case lt: tc--; break;
			case none: break;
			}
			if(tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS)
			{
				if (sitrep.thing[tr][tc].what == space)
				{
					if (sitrep.thing[tr-2][tc].what == unit)
					{
						if (sitrep.thing[tr-2][tc].tla == tla)
						{
							if (dir == up)
								tr--;
						}
					}
					else if (sitrep.thing[tr+2][tc].what == unit)
					{
						if (sitrep.thing[tr+2][tc].tla == tla)
						{
							if (dir == dn)
								tr++;
						}
					}
					else if (sitrep.thing[tr][tc+2].what == unit)
					{
						if (sitrep.thing[tr][tc+2].tla == tla)
						{
							if (dir == rt)
								tc++;
						}
					}
					else if (sitrep.thing[tr][tc-2].what == unit)
					{
						if (sitrep.thing[tr][tc-2].tla == tla)
						{
							if (dir == lt)
								tc--;
						}
					}
				}

			}

		}	
	}	
	
}










/*if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
if(sitrep.thing[tr][tc].what==unit){
if(sitrep.thing[tr][tc].tla!=tla){
a.action=attack;
a.ar=tr;
a.ac=tc;
return a;
}
}
}*/	
// there is not an enemy in front of me
// so head to the nearest enemy
/*if(dir==sitrep.nearestEnemy.dirFor){
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

}*/

