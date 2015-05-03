#include "mad.h"
#include <cmath>
#include <iostream>


Dir TurnSpace(SitRep, int, int);
Action King(SitRep, Dir, int, int, int, int);

void mad::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
Action mad::Recommendation(SitRep sitrep){
	

	Action a; 
	static bool protect = false;

	// first, try to attack in front of you
	int tr=r,tc=c;
	
	switch(dir){
	case up: tr--; 
		break;
	case dn: tr++; 
		break;
	case rt: tc++; 
		break;
	case lt: tc--; 
		break;
	case none: break;
	}

	if(rank == archer){
		int i, j;
		switch (dir)
		{
		case rt:{
			for(i = 0; i < 3; i ++){
				for(j = 0; j < 3; j++){
					if(sitrep.thing[(r-1+i)][(c+1+j)].what == unit){
						if(sitrep.thing[(r-1+i)][(c+1+j)].tla != tla){
							a.action = attack;
							a.ar = (r-1+i);
							a.ac = (c+1+j);
							return a;
						}
					}
				}
			}

				}
				break;
		case lt:{
			for(i = 0; i < 3; i ++){
				for(j = 0; j < 3; j++){
					if(sitrep.thing[(r-1+i)][(c-1-j)].what == unit){
						if(sitrep.thing[(r-1+i)][(c-1-j)].tla != tla){
							a.action = attack;
							a.ar = (r-1+i);
							a.ac = (c-1-j);
							return a;
						}
					}
				}
			}

				}
				break;
		case up:{
			for(i = 0; i < 3; i ++){
				for(j = 0; j < 3; j++){
					if(sitrep.thing[(r-1-i)][(c-1+j)].what == unit){
						if(sitrep.thing[(r-1-i)][(c-1+j)].tla != tla){
							a.action = attack;
							a.ar = (r-1-i);
							a.ac = (c-1+j);
							return a;
						}
					}
				}
			}

				}
				break;
		case dn:{
			for(i = 0; i < 3; i ++){
				for(j = 0; j < 3; j++){
					if(sitrep.thing[(r+1+i)][(c-1+j)].what == unit){
						if(sitrep.thing[(r+1+i)][(c-1+j)].tla != tla){
							a.action = attack;
							a.ar = (r+1+i);
							a.ac = (c-1+j);
							return a;
						}
					}
				}
			}

				}
						break;
		default:
			break;
		}


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
	
	if(rank == crown){
		a = King(sitrep, dir, r, c, tr, tc);
		protect = true;
		return a;
	}
	if(rank == archer && protect == true){
		protect = false;
		a = King(sitrep, dir, r, c, tr, tc);
		return a;
	}
	
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
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
	
}

Dir TurnSpace(SitRep sitrep, int r, int c){

	int trup = r - 1, tcup = c;
	int trdn = r + 1, tcdn = c;
	int trlt = r, tclt = c - 1;
	int trrt = r, tcrt = c + 1;
	if(sitrep.thing[trup][tcup].what == space){
		return up;
	}
	else if(sitrep.thing[trdn][tcdn].what == space){
		return dn;
	}
	else if(sitrep.thing[trlt][tclt].what == space){
		return lt;
	}
	else{
		return rt;
	}

}

Action King(SitRep sitrep, Dir dir, int r, int c, int tr, int tc){

	Action a;
	static bool kingTurn = false;
		if(kingTurn == true){

				a.action = fwd;
				a.dir = dir;
				a.maxDist = HORSESPEED;
				kingTurn = false;
				return a;
			}
			/*
		switch(sitrep.nearestEnemy.dirFor){
	case up:{
						a.action = fwd;
						a.dir = dn;
						a.maxDist = HORSESPEED;
						return a;}
		break;
	case dn:{
						a.action = fwd;
						a.dir = up;
						a.maxDist = HORSESPEED;
						return a;}
		break;
	case lt:{
					
						a.action = fwd;
						a.dir = rt;
						a.maxDist = HORSESPEED;
						return a;}
		break;
	case rt:{
						a.action = fwd;
						a.dir = lt;
						a.maxDist = HORSESPEED;
						return a;
					}
		break;
	case none:
		a.action = nothing;
		return a;
		break;
	}*/
		/*
	switch(sitrep.nearestEnemy.dirFor){
	case up:{
		if(sitrep.thing[(r+1)][c].what == space){
						a.action = fwd;
						a.dir = dn;
						a.maxDist = HORSESPEED;
						return a;
					}
		else{

						a.action = turn;
						kingTurn = true;
						a.dir = TurnSpace(sitrep, r, c);
						a.maxDist = HORSESPEED;
						return a;
					}}
		break;
	case dn:{
					if(sitrep.thing[(r-1)][c].what == space){
						a.action = fwd;
						a.dir = up;
						a.maxDist = HORSESPEED;
						return a;
					}
					else{

						a.action = turn;
						a.maxDist = HORSESPEED;
						kingTurn = true;
						a.dir = TurnSpace(sitrep, r, c);
						return a;
					}}
		break;
	case lt:{
					if(sitrep.thing[r][(c+1)].what == space){
						a.action = fwd;
						a.dir = rt;
						a.maxDist = HORSESPEED;
						return a;
					}
					else{

						a.action = turn;
						a.maxDist = HORSESPEED;
						kingTurn = true;
						a.dir = TurnSpace(sitrep, r, c);
						return a;
					}}
		break;
	case rt:{
					if(sitrep.thing[r][(c-1)].what == space){
						a.action = fwd;
						a.dir = lt;
						a.maxDist = HORSESPEED;
						return a;
					}
					else{

						a.action = turn;
						a.maxDist = HORSESPEED;
						kingTurn = true;
						a.dir = TurnSpace(sitrep, r, c);
						return a;
					}}
		break;
	case none:
		a.action = nothing;
		return a;
		break;
	}*/
	


	
/*	static bool kingTurn = false;
			if(kingTurn == true){

				a.action = fwd;
				a.dir = dir;
				a.maxDist = HORSESPEED;
				kingTurn = false;
				return a;
			}
			*/
			switch(sitrep.nearestEnemy.dirFor){
			case up:{
				if(dir == dn){
					if(sitrep.thing[tr][tc].what == space){
						a.action = fwd;
						a.dir = dn;
						a.maxDist = HORSESPEED;
						return a;
					}
					if(sitrep.thing[tr][tc].what != space){

						a.action = turn;
						kingTurn = true;
						a.dir = TurnSpace(sitrep, r, c);
						a.maxDist = HORSESPEED;
						return a;
					}

				 }
				else{
					a.action = turn;
					a.maxDist = HORSESPEED;
					kingTurn = true;
					if(sitrep.thing[(r+1)][c].what == space){
						a.dir = dn;
						return a;
					}
					a.dir = TurnSpace(sitrep, r, c);
					return a;
				}}
				break;
			case dn:{
				if(dir == up){
					if(sitrep.thing[tr][tc].what == space){
						a.action = fwd;
						a.dir = up;
						a.maxDist = HORSESPEED;
						return a;
					}
					if(sitrep.thing[tr][tc].what != space){

						a.action = turn;
						a.maxDist = HORSESPEED;
						kingTurn = true;
						a.dir = TurnSpace(sitrep, r, c);
						return a;
					}

				 }
				else{
					a.action = turn;
					a.maxDist = HORSESPEED;
					kingTurn = true;
					if(sitrep.thing[(r-1)][c].what == space){
						a.dir = up;
						return a;
					}
					a.dir = TurnSpace(sitrep, r, c);
					return a;
				}}
				break;
			case rt:{
				if(dir == lt){
					if(sitrep.thing[tr][tc].what == space){
						a.action = fwd;
						a.dir = lt;
						a.maxDist = HORSESPEED;
						return a;
					}
					if(sitrep.thing[tr][tc].what != space){

						a.action = turn;
						a.maxDist = HORSESPEED;
						kingTurn = true;
						a.dir = TurnSpace(sitrep, r, c);
						return a;
					}

				 }
				else{
					a.action = turn;
					a.maxDist = HORSESPEED;
					kingTurn = true;
					if(sitrep.thing[r][(c-1)].what == space){
						a.dir = lt;
						return a;
					}
					a.dir = TurnSpace(sitrep, r, c);
					return a;
				}}
				break;
			case lt:{
				if(dir == rt){
					if(sitrep.thing[tr][tc].what == space){
						a.action = fwd;
						a.dir = rt;
						a.maxDist = HORSESPEED;
						return a;
					}
					if(sitrep.thing[tr][tc].what != space){

						a.action = turn;
						a.maxDist = HORSESPEED;
						kingTurn = true;
						a.dir = TurnSpace(sitrep, r, c);
						return a;
					}

				 }
				else{
					a.action = turn;
					a.maxDist = HORSESPEED;
					kingTurn = true;
					if(sitrep.thing[r][(c+1)].what == space){
						a.dir = rt;
						return a;
					}
					a.dir = TurnSpace(sitrep, r, c);
					return a;
				}}
				break;
			case none:
				a.action = nothing;
				return a;
				break;
			}

			a.action = nothing;
			return a;
}
