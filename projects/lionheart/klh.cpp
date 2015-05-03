#include "klh.h"
#include <cmath>
#include <iostream>


void klh::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action klh::Recommendation(SitRep sitrep){
	
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

	// I am an archer and have greater range
	if (rank==archer){
		tr=r;
		tc=c;
		switch (dir)
		{
		case up: for(int i=-3; i>-1; i++){
			for (int j=-1; j<2; j++)
			{if (sitrep.thing[tr+i][tc+j].what==unit && sitrep.thing[tr+i][tc+j].tla!=tla){
				a.action=attack;
				a.ar=tr+i;
				a.ac=tc+j;
				return a;
			}
			}
				 }
		case dn: for(int i=3; i<1; i--){
			for (int j=-1; j<2; j++)
			{if (sitrep.thing[tr+i][tc+j].what==unit && sitrep.thing[tr+i][tc+j].tla!=tla){
				a.action=attack;
				a.ar=tr+i;
				a.ac=tc+j;
				return a;
			}
			}
				 }
		case rt: for(int j=3; j>1; j--){
			for (int i=-1; i<2; i++)
			{if (sitrep.thing[tr+i][tc+j].what==unit && sitrep.thing[tr+i][tc+j].tla!=tla){
				a.action=attack;
				a.ar=tr+i;
				a.ac=tc+j;
				return a;
			}
			}
				 }
		 case lt: for(int j=-3; j>-1; j++){
			for (int i=-1; i<2; i++)
			{if (sitrep.thing[tr+i][tc+j].what==unit && sitrep.thing[tr+i][tc+j].tla!=tla){
				a.action=attack;
				a.ar=tr+i;
				a.ac=tc+j;
				return a;
			}
			}
				 }
		}
	}
	// there is not an enemy in front of me
	// check to see if there is an enemy next to me
	// if so turn to face that enemy
	// first check above
	/*
	if (sitrep.thing[r-1][c].what==unit && sitrep.thing[r-1][c].tla!=tla){
		a.action=turn;
		a.dir=up;
		return a;
	// check right
	}else if (sitrep.thing[r][c+1].what==unit && sitrep.thing[r-1][c+1].tla!=tla){
		a.action=turn;
		a.dir=rt;
		return a;
	// check down
	}else if (sitrep.thing[r+1][c].what==unit && sitrep.thing[r+1][c].tla!=tla){
		a.action=turn;
		a.dir=dn;
		return a;
	// check left
	}else if (sitrep.thing[r][c-1].what==unit && sitrep.thing[r][c-1].tla!=tla){
		a.action=turn;
		a.dir=lt;
		return a;
	}
	*/

	// I am an infantry or archer
	// so head to the nearest enemy
	if(rank==infantry||rank==archer)
	{
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	}

	// I am a knight so hunt out the enemy
	else if(rank==knight)
	{
		if(dir==sitrep.nearestEnemyCrown.dirFor){
		a.action=fwd;
		//a.maxDist=1;
		switch (dir){
	case up: a.maxDist=3; break;
	case dn: a.maxDist=2; break;
	case rt: a.maxDist=3; break;
	case lt: a.maxDist=4; break;
		}
		
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
	}

	// I am the king so run away from enemies

	else if(rank==crown)
	{
		bool awayDir=false;
		switch(sitrep.nearestEnemy.dirFor){
	case up: if (dir==dn){awayDir=true;} break;
	case dn: if (dir==up){awayDir=true;} break;
	case lt: if (dir==rt){awayDir=true;} break;
	case rt: if (dir==lt){awayDir=true;} break;
	case none: break;
			}
		if(awayDir){
			a.action=fwd;
			a.maxDist=3;
			return a;
		}

		else{	

		switch(sitrep.nearestEnemy.dirFor){
	case up: a.dir=dn; break;
	case dn: a.dir=up; break;
	case lt: a.dir=rt; break;
	case rt: a.dir=lt; break;
}
	a.action=turn;
	return a;
}
}
}
/*	//	if (sitrep.anyOpenSpace!=none){

			if (dir==sitrep.anyOpenSpace){
			a.action=fwd;
			a.maxDist=1;
			return a;
			}else{
			a.action=turn;
			a.dir=sitrep.anyOpenSpace;
			
			dir=sitrep.nearestEnemy.dirFor;
			switch(dir){
			case up: dir=dn; break;
			case dn: dir=up; break;
			case lt: dir=rt; break;
			case rt: dir=lt; break;
			}
			a.dir=dir;
			a.action=turn;
			return a;
*/
		
	


