#include "knk.h"
#include <cmath>
#include <iostream>

Dir facing;

void knk::Place(int minR, int maxR, int minC, int maxC, SitRep sitrep){
	bool done = false;
	int tr = 0, tc = 0, i;
	Dir td;
	if (rank == crown){
		if (minC < 4){	//left side of board
			facing = rt;
			tr = minR; tc = minC;
			for (i = 0; i < maxR - minR; i++){
				if (sitrep.thing[tr + i][tc].what == space){
					tr += i;
					break;
				}
			}
		}
		else if (maxC > COLS - 4) {	//right side of board
			facing = lt;
			tr = minR; tc = maxC;
			for (i = 0; i < maxR - minR; i++){
				if (sitrep.thing[tr + i][tc].what == space){
					tr += i;
					break;
				}
			}
		}
		else if (minR < 1) {	//top side of board
			facing = dn;
			tr = minR; tc = minC;
			for (i = 0; i < maxC - minC; i++){
				if (sitrep.thing[tr][tc + i].what == space){
					tc += i;
					break;
				}
			}
		}
		else {	//bottom side of board
			facing = up;
			tr = maxR; tc = maxC;
			for (i = 0; i < maxC - minC; i++){
				if (sitrep.thing[tr][tc - i].what == space){
					tc -= i;
					break;
				}
			}
		}
	}
	else if (rank == knight){
		if (minC < 4){	//left side of board
			tr = minR; tc = maxC;
			for (i = 0; i < maxR - minR; i++){
				if (sitrep.thing[tr + i][tc].what == space){
					tr += i;
					break;
				}
			}
		}
		else if (maxC > COLS - 4) {	//right side of board
			tr = minR; tc = minC;
			for (i = 0; i < maxR - minR; i++){
				if (sitrep.thing[tr + i][tc].what == space){
					tr += i;
					break;
				}
			}
		}
		else if (minR < 1) {	//top side of board
			tr = maxR; tc = minC;
			for (i = 0; i < maxC - minC; i++){
				if (sitrep.thing[tr][tc + i].what == space){
					tc += i;
					break;
				}
			}
		}
		else {	//bottom side of board
			tr = minR; tc = maxC;
			for (i = 0; i < maxC - minC; i++){
				if (sitrep.thing[tr][tc - i].what == space){
					tc -= i;
					break;
				}
			}
		}
	}
	
	else if (rank == infantry){
		if (minC < 4){	//left side of board
			tr = minR + 1; tc = minC;
			if (sitrep.thing[tr][tc].what != space){
				tc += 1;
				if (sitrep.thing[tr][tc].what != space){
					tr -= 1;
					if (sitrep.thing[tr][tc].what != space){
						tr = minR; tc = maxC - 1;
						for (i = 0; i < maxR - minR; i++){
							if (tr + i == (maxR - 1) && sitrep.thing[tr + i][tc].what != space) goto Larcher;
							if (sitrep.thing[tr + i][tc].what == space){
								tr += i;
								break;
							}
						}
					}
				}
			}
		}
		else if (maxC > COLS - 4) {	//right side of board
			tr = minR + 1; tc = maxC;
			if (sitrep.thing[tr][tc].what != space){
				tc -= 1;
				if (sitrep.thing[tr][tc].what != space){
					tr -= 1;
					if (sitrep.thing[tr][tc].what != space){
						tr = minR; tc = minC + 1;
						for (i = 0; i < maxR - minR; i++){
							if (tr + i == (maxR - 1) && sitrep.thing[tr + i][tc].what != space) goto Rarcher;
							if (sitrep.thing[tr + i][tc].what == space){
								tr += i;
								break;
							}
						}
					}
				}
			}
		}
		else if (minR < 1) {	//top side of board
			tr = minR + 1; tc = minC;
			if (sitrep.thing[tr][tc].what != space){
				tc += 1;
				if (sitrep.thing[tr][tc].what != space){
					tr -= 1;
					if (sitrep.thing[tr][tc].what != space){
						tr = maxR - 1; tc = minC;
						for (i = 0; i < maxC - minC; i++){
							if (tc + i == (maxC - 1) && sitrep.thing[tr][tc + i].what != space) goto Tarcher;
							if (sitrep.thing[tr][tc + i].what == space){
								tc += i;
								break;
							}
						}
					}
				}
			}
		}
		else {	//bottom side of board
			tr = maxR - 1; tc = maxC;
			if (sitrep.thing[tr][tc].what != space){
				tc -= 1;
				if (sitrep.thing[tr][tc].what != space){
					tr += 1;
					if (sitrep.thing[tr][tc].what != space){
						tr = minR + 1; tc = maxC;
						for (i = 0; i < maxC - minC; i++){
							if (tc + i == (maxC - 1) && sitrep.thing[tr][tc + i].what != space) goto Barcher;
							if (sitrep.thing[tr][tc - i].what == space){
								tc -= i;
								break;
							}
						}
					}
				}
			}
		}
	}

	else {
		if (minC < 4){	//left side of board
Larcher:	tr = minR; tc = maxC - 2;
			for (i = 0; i < maxR - minR; i++){
				if (sitrep.thing[tr + i][tc].what == space){
					tr += i;
					break;
				}
			}
		}
		else if (maxC > COLS - 4) {	//right side of board
Rarcher:	tr = minR; tc = minC + 2;
			for (i = 0; i < maxR - minR; i++){
				if (sitrep.thing[tr + i][tc].what == space){
					tr += i;
					break;
				}
			}
		}
		else if (minR < 1) {	//top side of board
Tarcher:	tr = maxR - 2; tc = minC + 2;
			for (i = 0; i < maxC - minC; i++){
				if (sitrep.thing[tr][tc + i].what == space){
					tc += i;
					break;
				}
			}
		}
		else {	//bottom side of board
Barcher:	tr = minR + 2; tc = maxC - 2;
			for (i = 0; i < maxC - minC; i++){
				if (sitrep.thing[tr][tc - i].what == space){
					tc -= i;
					break;
				}
			}
		}
	}
	int rdist = ROWS / 2 - tr;
	int cdist = COLS / 2 - tc;
	if (abs(rdist)<abs(cdist)){
		if (cdist>0)td = rt;
		else td = lt;
	}
	else{
		if (rdist > 0)td = dn;
		else td = up;
	}
	r = tr;
	c = tc;
	dir = td;
}

Action knk::Recommendation(SitRep sitrep){
	Action a; 
	int tr = r, tc = c;
	if (rank == crown) {
		Dir td;
		int ctr, ctc;
		switch (facing){
		case rt: ctr = 0; ctc = 0; break;
		case lt: ctr = 0; ctc = COLS; break;
		case dn: ctr = 0; ctc = 0; break;
		case up: ctr = ROWS; ctc = COLS; break;
		}
		if (r == ctr && c == ctc){
			tr = r; tc = c;
			switch (dir){
			case up: tr--; break;
			case dn: tr++; break;
			case rt: tc++; break;
			case lt: tc--; break;
			case none: break;
			}
			if ((sitrep.thing[tr][tc].what == unit) && (sitrep.thing[tr][tc].tla != "knk")){
				a.action = attack;
				return a;
			}
			else {
				a.action = turn;
				a.dir = sitrep.nearestEnemy.dirFor;
			}
		}
		if (r != ctr || c != ctc){
			if (ctr < r) td = up;
			else if (ctr > r) td = dn;
			else {
				if (ctc < c) td = lt;
				else if (ctc > c) td = rt;
				else td = none;
			}
			if (dir == td){
				a.action = fwd;
				a.maxDist = 1;
				return a;
			}
			else{
				a.action = turn;
				a.dir = td;
				return a;
			}
		}

	}
	if(dir==sitrep.nearestEnemyCrown.dirFor){
		switch (dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
		if (rank != archer) {
			if ((sitrep.thing[tr][tc].what == unit) && (sitrep.thing[tr][tc].tla != "knk")){
				a.action = attack;
				return a;
			}
			else {
				a.action = fwd;
				a.maxDist = 1;
//				if (rank == knight) a.maxDist = HORSESPEED;
				return a;
			}
			
		}
		else {
			bool aEnemy = false;
			int i, j, tar = r, tac = c, lastr = 0, lastc = 0;
			switch (dir){
			case up: tar-=3; tac--; break;
			case dn: tar++; tac--; break;
			case rt: tar--; tac++; break;
			case lt: tar--; tac-=3; break;
			case none: break;
			}
			for (i = 0; i < 3; ++i){
				for (j = 0; j < 3; ++j){
					if ((sitrep.thing[tar + i][tac + j].what == unit) && (sitrep.thing[tar + i][tac + j].tla != "knk")){
						aEnemy = true;
						lastr = tar + i; lastc = tac + j;
					}
				}
			}
			if (aEnemy == true){
				a.action = attack;
				a.ar = lastr; a.ac = lastc;
				return a;
			}
			else {
				a.action = fwd;
				a.maxDist = 1;
				return a;
			}
		}
	}
	else {
		a.action = turn;
		a.dir = sitrep.nearestEnemyCrown.dirFor;
		return a;
	}	
}
