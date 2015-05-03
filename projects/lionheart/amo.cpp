#include "amo.h"
#include <cmath>
#include <iostream>


void amo::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;


	while(!done)
  {
    if (rank==crown) 
    {
      tr=(minR+maxR/2);
      tc=(minC+maxC/2);
      done=true;
    }
    else if (rank!=crown)
    {
		  tr=minR+rand()%(maxR-minR);	
		  tc=minC+rand()%(maxC-minC);	
		  if(sitrep.thing[tr][tc].what==space)done=true;
    }
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


Action amo::Recommendation(SitRep sitrep){

	Action a; 

	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
        if(rank==crown)
        {
          switch(dir)
          {
	          case up: 
              a.action=turn; 
              a.dir= dn; 
              break;
	          case dn:
              a.action=turn; 
              a.dir= up;
              break;
	          case rt: 
              a.action=turn; 
              a.dir= lt; 
              break;
	          case lt: 
              a.action=turn; 
              a.dir= rt; 
              break;
          }
          return a;
        }
        else
        {
				  a.action=attack;
				  a.ar=tr;
				  a.ac=tc;
				  return a;
        }
			}
		}
	}	

	if(dir==sitrep.nearestEnemyCrown.dirFor && rank!=crown)
  {
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight)a.maxDist=HORSESPEED;
		return a;
	}
  else if (dir==sitrep.nearestEnemy.dirFor && rank==crown)
  {
    switch(dir)
      {
	      case up: 
          a.action=turn; 
          a.dir= dn; 
          break;
	      case dn: 
          a.action=turn; 
          a.dir= up; 
          break;
	      case rt: 
          a.action=turn; 
          a.dir= lt; 
          break;
	      case lt: 
          a.action=turn; 
          a.dir= rt; 
          break;
      }
    return a;
  }
  else if (rank!=crown)
  {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
  else 
  {
    switch(sitrep.nearestEnemy.dirFor)
    {
      case up: 
        if (dir=dn)
        {
          a.action=fwd;
          a.maxDist=HORSESPEED; 
          break;
        } 
        else 
        {
          a.action=turn; 
          a.dir = dn; 
          break;
        }
	    case dn: 
        if (dir=up)
        {
          a.action=fwd;
          a.maxDist=HORSESPEED; 
          break;
        } 
        else 
        {
          a.action=turn;
          a.dir = up; 
          break;
        }
	    case rt: 
        if (dir=lt)
        {
          a.action=fwd; 
          a.maxDist=HORSESPEED; 
          break;
        } 
        else 
        {
          a.action=turn; 
          a.dir = lt; 
          break;
        }
	    case lt: 
        if (dir=rt)
        {
          a.action=fwd;
          a.maxDist=HORSESPEED; 
          break;
        }
        else 
        {
          a.action=turn; 
          a.dir = rt;
          break;
        }
    }
    return a;
  }
	a.action=nothing;
	return a;
}
