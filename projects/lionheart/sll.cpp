#include "sll.h"
#include <cmath>
#include <iostream>

int sll::crowncol = 0;
int sll::crownrow = 0;

void sll::Place(int minR, int maxR, int minC, int maxC, SitRep sitrep){
	bool done = false;
	int tr, tc;
	Dir td;
	int crc;
	if (minC < (COLS / 2)){
		crc = minC + 1;
	}
	else{
		crc = maxC - 1;
	}
	int crr = minR + ((maxR - minR) / 2);
	crowncol = crc;
	crownrow = crr;
	if (rank == crown){
		tc = crc;
		tr = crr;
		r = tr;
		c = tc;
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
		return;
	}
	if (rank == knight){
		while (!done){
			if (minC < (COLS / 2)){
				tc = minC + 1 + rand() % 2;
			}
			else{
				tc = maxC - 1 - rand() % 2;
			}
			tr = maxR - ((maxR - minR) / 2) - rand() % 3 + rand() % 3;
			if ((sitrep.thing[tr][tc].what == space) && (((tr == crr) && (tc == crc)) != 1))done = true;
		}
	}
	if (rank == infantry){
		while (!done){
			if (minC < (COLS / 2)){
				tc = maxC - rand() % 2;
			}
			else{
				tc = minC + rand() % 2;
			}
			tr = minR + (rand()%(maxR - minR));
			if ((sitrep.thing[tr][tc].what == space))done = true;
		}
	}
	if (rank == archer){
		while (!done){
			if (minC < (COLS / 2)){
				tc = minC;
			}
			else{
				tc = maxC;
			}
			tr = minR + (rand()%(maxR - minR));
			if ((sitrep.thing[tr][tc].what == space))done = true;
		}
	}
	while (!done){
		tr = minR + rand()%(maxR - minR);
		tc = minC + rand()%(maxC - minC);
		if ((sitrep.thing[tr][tc].what == space) && (((tr == crr) && (tc == crc)) != 1))done = true;
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


// tell someone what you want to do

Action sll::Recommendation(SitRep sitrep){
	Action a;

	char map[ROWS][COLS];
	char move[ROWS][COLS];

	int test1;
	int test2;
	int test3;
	int test4;
	for (int d = 0; d < (COLS); d++){
		for (int v = 0; v < (ROWS); v++){
			test1 = (sitrep.thing[v - 1][d].what == rock);
			test2 = (sitrep.thing[v][d - 1].what == rock);
			test3 = (sitrep.thing[v][d + 1].what == rock);
			test4 = (sitrep.thing[v + 1][d].what == rock);
			if (((test1 + test2 + test3 + test4) >= 3) && (sitrep.thing[v][d].what != rock)){
				map[v][d] = '*';

			}
			else{
				map[v][d] = ' ';
			}
		}
	}

	bool change;
	do{
		change = false;
		for (int v = 0; v < ROWS; v++){
			for (int d = 0; d < COLS; d++){
				if ((map[v][d] != '*') && (map[v][d] != '^') && (map[v][d] != '<') && (map[v][d] != '>') && (map[v][d] != 'v') && (sitrep.thing[v][d].what != rock) && ((sitrep.thing[v][d].what != unit) || ((v == r) && (d == c)))){
					if (((map[v - 1][d] == '*') || (map[v - 1][d] == '^') || (map[v - 1][d] == '<') || (map[v - 1][d] == '>')) && (d >= 1)){
						map[v][d] = '^';
						change = true;
					}
					if (((map[v + 1][d] == '*') || (map[v + 1][d] == '<') || (map[v + 1][d] == '>') || (map[v + 1][d] == 'v')) && (v <= COLS)){
						map[v][d] = 'v';
						change = true;
					}
					if (((map[v][d - 1] == '*') || (map[v][d - 1] == '^') || (map[v][d - 1] == '<') || (map[v][d - 1] == 'v')) && (d >= 1)){
						map[v][d] = '<';
						change = true;
					}
					if (((map[v][d + 1] == '*') || (map[v][d + 1] == '^') || (map[v][d + 1] == '>') || (map[v][d + 1] == 'v')) && (d <= ROWS)){
						map[v][d] = '>';
						change = true;
					}
					move[v][d] = ' ';
				}
			}
		}
	} while (change == true);


	//Do not block the king's path!

	int x = 0;
	int y = 0;
	do{
		change = false;
		switch (map[crownrow + x][crowncol + y]){
		case '^':
			x = x - 1;
			change = true;
			break;
		case '<':
			y = y - 1;
			change = true;
			break;
		case 'v':
			x = x + 1;
			change = true;
			break;
		case '>':
			y = y + 1;
			change = true;
			break;
		}
		if ((map[crownrow + x][crowncol + y]) != '*'){
			move[crownrow + x][crowncol + y] = 'X';
		}

	} while (change == true);

	// first, try to attack in front of you
	int tr = r, tc = c;
	if (rank != archer){
		switch (dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
	}
	else{
		//archer attack
		//directly in front of you
		switch (dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		// one space diagonally from you (left)
		switch (dir){
		case up: tc--; break;
		case dn: tc++; break;
		case rt: tr++; break;
		case lt: tr--; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		// one space diagonally from you (right)
		switch (dir){
		case up: tc = tc + 2; break;
		case dn: tc = tc - 2; break;
		case rt: tr = tr - 2; break;
		case lt: tr = tr + 2; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		switch (dir){
		case up: tc--; break;
		case dn: tc++; break;
		case rt: tr++; break;
		case lt: tr--; break;
		case none: break;
		}
		//two spaces directly in front of you
		switch (dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		// two space diagonally from you (left)
		switch (dir){
		case up: tc--; break;
		case dn: tc++; break;
		case rt: tr++; break;
		case lt: tr--; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		// two space diagonally from you (right)
		switch (dir){
		case up: tc = tc + 2; break;
		case dn: tc = tc - 2; break;
		case rt: tr = tr - 2; break;
		case lt: tr = tr + 2; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		switch (dir){
		case up: tc--; break;
		case dn: tc++; break;
		case rt: tr++; break;
		case lt: tr--; break;
		case none: break;
		}
		//three spaces directly in front of you
		switch (dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		// three space diagonally from you (left)
		switch (dir){
		case up: tc--; break;
		case dn: tc++; break;
		case rt: tr++; break;
		case lt: tr--; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		// three space diagonally from you (right)
		switch (dir){
		case up: tc = tc + 2; break;
		case dn: tc = tc - 2; break;
		case rt: tr = tr - 2; break;
		case lt: tr = tr + 2; break;
		case none: break;
		}
		if (tr >= 0 && tr < ROWS && tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
		//end of archer attack
	}




	if (rank == crown){
		//face the correct direction
		if ((map[r][c] != '^') && (map[r][c] != '<') && (map[r][c] != '>') && (map[r][c] != 'v') && (map[r][c] != '*')){
		}
		if ((map[r][c] == '^') && (dir != up)){
			a.dir = up;
			a.action = turn;
			return a;
		}
		if ((map[r][c] == '<') && (dir != lt)){
			a.dir = lt;
			a.action = turn;
			return a;
		}
		if ((map[r][c] == '>') && (dir != rt)){
			a.dir = rt;
			a.action = turn;
			return a;
		}
		if ((map[r][c] == 'v') && (dir != dn)){
			a.dir = dn;
			a.action = turn;
			return a;
		}
		//move if you are facing the correct direction
		if ((map[r][c] == '^') && (dir == up)){
			a.maxDist = 1;
			a.action = fwd;
			if (rank == crown){
				crownrow--;
			}
			return a;
		}
		if ((map[r][c] == '<') && (dir == lt)){
			a.maxDist = 1;
			a.action = fwd;
			if (rank == crown){
				crowncol--;
			}
			return a;
		}
		if ((map[r][c] == '>') && (dir == rt)){
			a.maxDist = 1;
			a.action = fwd;
			if (rank == crown){
				crowncol++;
			}
			return a;
		}
		if ((map[r][c] == 'v') && (dir == dn)){
			a.maxDist = 1;
			a.action = fwd;
			if (rank == crown){
				crownrow++;
			}
			return a;
		}
		//else, do nothing
		a.action = nothing;
		return a;
	}
	// change the map to be for knights
	for (int v = 0; v < ROWS; v++){
		for (int d = 0; d < COLS; d++){
			map[v][d] = ' ';
			if ((v == crownrow) && (d == crowncol)){
				map[v][d] = '*';
			}
		}
	}
	do{
		change = false;
		for (int v = 0; v < ROWS; v++){
			for (int d = 0; d < COLS; d++){
				if ((map[v][d] != '*') && (map[v][d] != '^') && (map[v][d] != '<') && (map[v][d] != '>') && (map[v][d] != 'v') && (sitrep.thing[v][d].what != rock) && ((sitrep.thing[v][d].what != unit) || ((v == r) && (d == c)))){
					if (((map[v - 1][d] == '*') || (map[v - 1][d] == '^') || (map[v - 1][d] == '<') || (map[v - 1][d] == '>')) && (d >= 1) && (move[v - 1][d] != 'X')){
						map[v][d] = '^';
						change = true;
					}
					if (((map[v + 1][d] == '*') || (map[v + 1][d] == '<') || (map[v + 1][d] == '>') || (map[v + 1][d] == 'v')) && (v <= COLS) && (move[v + 1][d] != 'X')){
						map[v][d] = 'v';
						change = true;
					}
					if (((map[v][d - 1] == '*') || (map[v][d - 1] == '^') || (map[v][d - 1] == '<') || (map[v][d - 1] == 'v')) && (d >= 1) && (move[v][d - 1] != 'X')){
						map[v][d] = '<';
						change = true;
					}
					if (((map[v][d + 1] == '*') || (map[v][d + 1] == '^') || (map[v][d + 1] == '>') || (map[v][d + 1] == 'v')) && (d <= ROWS) && (move[v][d + 1] != 'X')){
						map[v][d] = '>';
						change = true;
					}
					move[v][d] = ' ';
				}
			}
		}
	} while (change == true);

	//if you are a knight
	if (rank == knight){
		//face the correct direction
		if ((map[r][c] == '^') && (dir != up)){
			a.dir = up;
			a.action = turn;
			return a;
		}
		if ((map[r][c] == '<') && (dir != lt)){
			a.dir = lt;
			a.action = turn;
			return a;
		}
		if ((map[r][c] == '>') && (dir != rt)){
			a.dir = rt;
			a.action = turn;
			return a;
		}
		if ((map[r][c] == 'v') && (dir != dn)){
			a.dir = dn;
			a.action = turn;
			return a;
		}
		//else
		tr = r;
		tc = c;
		if ((map[r][c] == ' ')){
			if (dir == sitrep.nearestEnemy.dirFor){
				for (int v = 1; v <= HORSESPEED; v++){
					switch (dir){
					case up: tc = tc - 1; break;
					case dn: tc = tc + 1; break;
					case rt: tr = tr + 1; break;
					case lt: tr = tr - 1; break;
					case none: break;
					}
					if (sitrep.thing[tr][tc].what == unit){
						if (sitrep.thing[tr][tc].tla != "sll"){
							a.maxDist = v;
							a.action = fwd;
						}
					}
				}
				tr = r;
				tc = c;
				for (int v = 1; v < HORSESPEED; v++){
					switch (dir){
					case up: tc = tc - 1; break;
					case dn: tc = tc + 1; break;
					case rt: tr = tr + 1; break;
					case lt: tr = tr - 1; break;
					case none: break;
					}
					if (sitrep.thing[tr + 1][tc + 1].what == unit){
						if (sitrep.thing[tr + 1][tc + 1].tla != "sll"){
							a.maxDist = v + 1;
							a.action = fwd;
						}
					}
				}
				tr = r;
				tc = c;
				for (int v = 1; v < HORSESPEED; v++){
					switch (dir){
					case up: tc = tc - 1; break;
					case dn: tc = tc + 1; break;
					case rt: tr = tr + 1; break;
					case lt: tr = tr - 1; break;
					case none: break;
					}
					if (sitrep.thing[tr - 1][tc - 1].what == unit){
						if (sitrep.thing[tr - 1][tc - 1].tla != "sll"){
							a.maxDist = v + 1;
							a.action = fwd;
						}
					}
				}
				if (a.maxDist < 1){
					a.maxDist = 1;
					a.action = fwd;
				}
				return a;
			}
			else {
				a.action = turn;
				a.dir = sitrep.nearestEnemy.dirFor;
				return a;
			}
			a.action = nothing;
			return a;
		}
		//move if you are facing the correct direction
		if ((map[r][c] == '^') && (dir == up)){
			a.maxDist = 1;
			a.action = fwd;
			return a;
		}
		if ((map[r][c] == '<') && (dir == lt)){
			a.maxDist = 1;
			a.action = fwd;
			return a;
		}
		if ((map[r][c] == '>') && (dir == rt)){
			a.maxDist = 1;
			a.action = fwd;
			return a;
		}
		if ((map[r][c] == 'v') && (dir == dn)){
			a.maxDist = 1;
			a.action = fwd;
			return a;
		}
		//else, do nothing
		a.action = nothing;
		return a;
	}
	// change the map to be for all other pieces
	for (int v = 0; v < ROWS; v++){
		for (int d = 0; d < COLS; d++){
			map[v][d] = ' ';
			if (sitrep.thing[v][d].what == unit){
				if (sitrep.thing[v][d].tla != "sll"){
					map[v][d] = '*';
				}
			}
		}
	}
	do{
		change = false;
		for (int v = 0; v < ROWS; v++){
			for (int d = 0; d < COLS; d++){
				if ((map[v][d] != '*') && (map[v][d] != '^') && (map[v][d] != '<') && (map[v][d] != '>') && (map[v][d] != 'v') && (sitrep.thing[v][d].what != rock) && ((sitrep.thing[v][d].what != unit) || ((v == r) && (d == c)))){
					if (((map[v - 1][d] == '*') || (map[v - 1][d] == '^') || (map[v - 1][d] == '<') || (map[v - 1][d] == '>')) && (d >= 1) && (move[v - 1][d] != 'X')){
						map[v][d] = '^';
						change = true;
					}
					if (((map[v + 1][d] == '*') || (map[v + 1][d] == '<') || (map[v + 1][d] == '>') || (map[v + 1][d] == 'v')) && (v <= COLS) && (move[v + 1][d] != 'X')){
						map[v][d] = 'v';
						change = true;
					}
					if (((map[v][d - 1] == '*') || (map[v][d - 1] == '^') || (map[v][d - 1] == '<') || (map[v][d - 1] == 'v')) && (d >= 1) && (move[v][d - 1] != 'X')){
						map[v][d] = '<';
						change = true;
					}
					if (((map[v][d + 1] == '*') || (map[v][d + 1] == '^') || (map[v][d + 1] == '>') || (map[v][d + 1] == 'v')) && (d <= ROWS) && (move[v][d + 1] != 'X')){
						map[v][d] = '>';
						change = true;
					}
					move[v][d] = ' ';
				}
			}
		}
	} while (change == true);

	//if you are not a crown or a knight, this is how you will move...
	if (rank != archer){
		if (dir == sitrep.nearestEnemy.dirFor){
			a.action = fwd;
			a.maxDist = 1;
			if (rank == knight)a.maxDist = 1;  //HORSESPEED;
			return a;
		}
		else {
			a.action = turn;
			a.dir = sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action = nothing;
		return a;
	}


	if (rank == archer){
		if (dir == sitrep.nearestEnemy.dirFor){
			a.action = fwd;
			a.maxDist = 1;
			return a;
		}
		else {
			a.action = turn;
			a.dir = sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action = nothing;
		return a;
	}
}