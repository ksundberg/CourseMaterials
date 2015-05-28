#include "adn.h"
#include <cmath>
#include <iostream>
#include "lionheart2.h"

int adn::infStart=0;
int adn::numAttacks=0;
bool adn::inCombat=false;

void adn::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;

	if (maxC < COLS / 2){
	if (rank == crown){
		while (!done){
			tr = minR/2+minR;
			tc = minC;

			if (sitrep.thing[tr][tc].what == space)done = true;
		}
		td = dn;
		r = tr;
		c = tc;
		dir = td;
	}
	if (rank == knight){
		while (!done){
			tr = minR + rand()%(maxR - minR);
			tc = minC +5;

			if (sitrep.thing[tr][tc].what == space)done = true;
		}
		int rdist = ROWS / 2 - tr;
		int cdist = COLS / 2 - tc;
		if (abs(rdist) < abs(cdist)){
			if (cdist>0)td = rt;
			else td = lt;
		}
		else{
			if (rdist > 0)td = up;
			else td = dn;
		}
		r = tr;
		c = tc;
		dir = td;

	}
	if (rank == archer){
		while (!done){
			tr = minR + 3 + rand()%(5);
			tc = minC + rand()%(2);

			if (sitrep.thing[tr][tc].what == space)done = true;
		}
		int rdist = ROWS / 2 - tr;
		int cdist = COLS / 2 - tc;
		if (abs(rdist) < abs(cdist)){
			if (cdist>0)td = rt;
			else td = lt;
		}
		else{
			if (rdist > 0)td = up;
			else td = dn;
		}
		r = tr;
		c = tc;
		dir = td;
	}
	if (rank == infantry){
		while (!done){
			tr = minR + 2 + rand()%(7);
			tc = minC + rand()%(4);

			if (sitrep.thing[tr][tc].what == space)done = true;
		}
		int rdist = ROWS / 2 - tr;
		int cdist = COLS / 2 - tc;
		if (abs(rdist) < abs(cdist)){
			if (cdist>0)td = rt;
			else td = lt;
		}
		else{
			if (rdist > 0)td = up;
			else td = dn;
		}
		r = tr;
		c = tc;
		dir = td;
	}

	}
else{
		if (rank == crown){
			while (!done){
				tr = minR / 2 + minR;
				tc = maxC;

				if (sitrep.thing[tr][tc].what == space)done = true;
			}
			int rdist = ROWS / 2 - tr;
			int cdist = COLS / 2 - tc;
			if (abs(rdist) < abs(cdist)){
				if (cdist>0)td = rt;
				else td = lt;
			}
			else{
				if (rdist > 0)td = up;
				else td = dn;
			}
			r = tr;
			c = tc;
			dir = td;
		}
		if (rank == knight){
			while (!done){
				tr = minR + rand()%(maxR - minR);
				tc = minC;

				if (sitrep.thing[tr][tc].what == space)done = true;
			}
			int rdist = ROWS / 2 - tr;
			int cdist = COLS / 2 - tc;
			if (abs(rdist) < abs(cdist)){
				if (cdist>0)td = rt;
				else td = lt;
			}
			else{
				if (rdist > 0)td = up;
				else td = dn;
			}
			r = tr;
			c = tc;
			dir = td;

		}
		if (rank == archer){
			while (!done){
				tr = minR + 3 + rand()%(5);
				tc = maxC - rand()%(2);

				if (sitrep.thing[tr][tc].what == space)done = true;
			}
			int rdist = ROWS / 2 - tr;
			int cdist = COLS / 2 - tc;
			if (abs(rdist) < abs(cdist)){
				if (cdist>0)td = rt;
				else td = lt;
			}
			else{
				if (rdist > 0)td = up;
				else td = dn;
			}
			r = tr;
			c = tc;
			dir = td;
		}
		if (rank == infantry){
			while (!done){
				tr = minR + 2 + rand()%(7);
				tc = maxC - rand()%(4);

				if (sitrep.thing[tr][tc].what == space)done = true;
			}
			int rdist = ROWS / 2 - tr;
			int cdist = COLS / 2 - tc;
			if (abs(rdist) < abs(cdist)){
				if (cdist>0)td = rt;
				else td = lt;
			}
			else{
				if (rdist > 0)td = up;
				else td = dn;
			}
			r = tr;
			c = tc;
			dir = td;
		}

	}

}



// tell someone what you want to do
Action adn::Recommendation(SitRep sitrep){
	
	Action a;

	if(rank==infantry&&hp<INFANTRYHP&&!inCombat&&sitrep.turnNumber>MAXTURNS*(1/5)){
		inCombat=true;
	}
	if(rank==knight&&hp<KNIGHTHP&&!inCombat&&sitrep.turnNumber>MAXTURNS*(1/5)){
		inCombat=true;
	}
	if(rank==archer&&hp<ARCHERHP&&!inCombat&&sitrep.turnNumber>MAXTURNS*(1/5)){
		inCombat=true;
	}
	if(rank==crown&&hp<CROWNHP&&!inCombat&&sitrep.turnNumber>MAXTURNS*(1/5)){
		inCombat=true;
	}//see if combat has started

	//try to attack in front of you
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
				numAttacks++;
				if(numAttacks>20){
					inCombat=true;
				}
				return a;
			}
		}
	}//basic melee attack

	//make sure you're facing the nearest enemy
	if(dir!=sitrep.nearestEnemy.dirFor){
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
		}

	//start archer attack
	if(rank==archer){
		tr=r;
		tc=c;
		int i, j;
		if(dir==up){
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==crown){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy crown
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}
		}//attack anyone
		//end up
		if(dir==dn){
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr-i>=0&&tr-i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr-i][tc+j].what==unit&&sitrep.thing[tr-i][tc+j].tla!=tla&&sitrep.thing[tr-i][tc+j].rank==crown){
						a.action=attack;
						a.ar=tr-i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy crown
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr-i>=0&&tr-i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr-i][tc+j].what==unit&&sitrep.thing[tr-i][tc+j].tla!=tla){
						a.action=attack;
						a.ar=tr-i;
						a.ac=tc+j;
						return a;
					}
				}
			}
		}//attack anyone
		//end down
		if(dir==lt){
			for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc-j>=0&&tc-j<COLS&&sitrep.thing[tr+i][tc-j].what==unit&&sitrep.thing[tr+i][tc-j].tla!=tla&&sitrep.thing[tr+i][tc-j].rank==crown){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc-j;
						return a;
					}
				}
			}//check for enemy crown
			for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc-j>=0&&tc-j<COLS&&sitrep.thing[tr+i][tc-j].what==unit&&sitrep.thing[tr+i][tc-j].tla!=tla){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc-j;
						return a;
					}
				}
			}
		}//attack anyone
		//end left
		if(dir==rt){
		for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==crown){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy crown
		for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}
		}//attack anyone
		//end right
	}//end archer


	if(!inCombat&&sitrep.turnNumber<(MAXTURNS*1.5/5)){a.action=nothing; return a;}//if not in combat and turns less than 3/5 over, wait
	if(rank==crown||rank==knight&&sitrep.turnNumber<MAXTURNS*1/5){a.action=nothing; return a;}
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(rank==crown){a.action=nothing; return a;}
	if(rank==knight){
		if(dir==sitrep.nearestEnemyCrown.dirFor){
			a.action=fwd;
			a.maxDist=1+rand()%HORSESPEED;
			return a;
		
		}else{
			a.action=turn;
			a.dir=sitrep.nearestEnemyCrown.dirFor;
			return a;
		}
	}
	if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
			return a;
		
	}else{
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	
	a.action=nothing;
	return a;
}
