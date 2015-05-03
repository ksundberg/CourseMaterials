#include "tas.h"
#include <cmath>
#include <iostream>
using namespace std;

void tas::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action tas::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a; 
	if(rank==infantry || rank==knight || rank==crown)
	{
		int tr=r,tc=c;
		switch(dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
			tr=r;
			tc=c;
			if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
				if(dir==rt){
				tr=r;
				tc=c;
				tc++;
				if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				}
				tr=r;
				tc=c;
				tc--;
				if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
				a.action=fwd;
				}
				tr=r;
				tc=c;
				tr++;
				if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
				a.action=fwd;
				}
				tr=r;
				tc=c;
				tr--;
				if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
				a.action=fwd;
				}
				tr=r;
				tc=c;
				tc++;
				if(sitrep.thing[tr][tc].what==rock){
						a.action=turn;
						if(sitrep.thing[tr][tc].what==space){
							a.action=fwd;
						}
					}
				if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					tr=r;
					tc=c;
					tr--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
					{
						tr=r;
						tc=c;
						tr++;
						if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
						{
							tr=r;
							tc=c;
							tc--;
							if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
							{
								a.action=nothing;
							}
						}
					}
				}
				}
				else if(dir==dn)
				{
					tr=r;
					tc=c;
					tr++;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					}
					tr=r;
					tc=c;
					tc++;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					tr=r;
					tc=c;
					tr--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					tr=r;
					tc=c;
					tc--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					if(sitrep.thing[tr][tc].what==rock){
						a.action=turn;
						if(sitrep.thing[tr][tc].what==space){
							a.action=fwd;
						}
					}
					tr=r;
				tc=c;
				tc++;
				if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					tr=r;
					tc=c;
					tr--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
					{
						tr=r;
						tc=c;
						tr++;
						if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
						{
							tr=r;
							tc=c;
							tc--;
							if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
							{
								a.action=nothing;
							}
						}
					}
				}
				}
				else if(dir==lt)
				{
					tr=r;
					tc=c;
					tc--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					}
					tr=r;
					tc=c;
					tr++;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					tr=r;
					tc=c;
					tr--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					tr=r;
					tc=c;
					tc++;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					if(sitrep.thing[tr][tc].what==rock){
						a.action=turn;
						if(sitrep.thing[tr][tc].what==space){
							a.action=fwd;
						}
					}
					tr=r;
				tc=c;
				tc++;
				if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					tr=r;
					tc=c;
					tr--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
					{
						tr=r;
						tc=c;
						tr++;
						if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
						{
							tr=r;
							tc=c;
							tc--;
							if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
							{
								a.action=nothing;
							}
						}
					}
				}
				}
				else if(dir=up)
				{
					tr=r;
					tc=c;
					tr--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
						a.action=attack;
					}
					tc++;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					tr=r;
					tc=c;
					tc--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					tr=r;
					tc=c;
					tr++;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					a.action=fwd;
					}
					if(sitrep.thing[tr][tc].what==rock){
						a.action=turn;
						if(sitrep.thing[tr][tc].what==space){
							a.action=fwd;
						}
					}
					tr=r;
				tc=c;
				tc++;
				if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla){
					tr=r;
					tc=c;
					tr--;
					if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
					{
						tr=r;
						tc=c;
						tr++;
						if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
						{
							tr=r;
							tc=c;
							tc--;
							if(sitrep.thing[tr][tc].what==unit && sitrep.thing[tr][tc].tla!=tla)
							{
								a.action=nothing;
							}
						}
					}
				}
			}
		}
	}
	// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(rank==archer){
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
			}
		}	
		else if(sitrep.thing[tr][tc].what==space || sitrep.thing[tr][tc].what==rock){
			a.action=nothing;
		}
	}
}
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=2;
			if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
	}
	a.action=nothing;
	return a;
}
