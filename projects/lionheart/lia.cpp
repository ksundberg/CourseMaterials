#include "lia.h"
#include <cmath>
#include <iostream>


void lia::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool openSpace=false;
	int randomRow, randomColumn;
	Dir startingDirection;
	while(!openSpace){
		randomRow=minR+rand()%(maxR-minR);	//chooses a random row within the board boundries (max/min) lt/rt
		randomColumn=minC+rand()%(maxC-minC);	//chooses a random column within board boundired (max/min) up/dn
		//if the thing in the block is an open space, set open space to true
		if(sitrep.thing[randomRow][randomColumn].what==space)openSpace=true; 
	}
	int rowdist = ROWS / 2 - randomRow; //rowdist is the number of rows, divided by two, and subtract the random row chosen (to see what side of board unit is on)
	int columndist=COLS/2-randomColumn; //same as above only for column (this is to see what side of the board the unit is on)
	if(abs(rowdist)<abs(columndist)){  //if the absolute value of row is less than absolute of column 
		if (columndist>0){ startingDirection = rt; }//if on the left side of the board
		else { startingDirection = lt;} //else if they're on the right side of the board
	}
	else{
		if (rowdist > 0){//if they're on the bottom of the board
			startingDirection = up; 
		}
		else { startingDirection = dn;}//if they're on the top of the board
	}
	r=randomRow; //set row to where the unit was placed
	c=randomColumn; //set column to where the unit was placed
	dir=startingDirection;
}


// tell someone what you want to do
Action lia::Recommendation(SitRep sitrep){
	
	Action a;

	// first, try to attack in front of you
	int rRow = r, rColumn = c;
	Dir tempDir;

	/*infantry recommendations*/
	if (rank == infantry){

		//moves in dir
		switch (dir){
		case up: rRow--; break;
		case dn: rRow++; break;
		case rt: rColumn++; break;
		case lt: rColumn--; break;
		case none: break;
		}


		if (rRow >= 0 && rRow < ROWS&&rColumn >= 0 && rColumn < COLS){ //if on the board
			if (sitrep.thing[rRow][rColumn].what == unit){ //if its a unit
				if (sitrep.thing[rRow][rColumn].tla != tla){
					a.action = attack;
					a.ar = rRow;
					a.ac = rColumn;
					return a;
				}
			}
		}

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

	/*infantry recommendations*/
	if (rank == knight){

		//moves in dir
		switch (dir){
		case up: rRow--; break;
		case dn: rRow++; break;
		case rt: rColumn++; break;
		case lt: rColumn--; break;
		case none: break;
		}


		if (rRow >= 0 && rRow < ROWS&&rColumn >= 0 && rColumn < COLS){ // if on the board
			if (sitrep.thing[rRow][rColumn].what == unit){ // if its a unit
				if (sitrep.thing[rRow][rColumn].tla != tla){
					a.action = attack;
					return a;
				}
			}
		}

		if (dir == sitrep.nearestEnemy.dirFor){
			a.action = fwd;
			a.maxDist = 1;
			a.maxDist = HORSESPEED;  // make knights move further
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

	/*infantry recommendations*/
	if (rank == archer){

		//moves row/column in dir
		switch (dir){
		case up: rRow--; break;
		case dn: rRow++; break;
		case rt: rColumn++; break;
		case lt: rColumn--; break;
		case none: break;
		}


		if (rRow >= 0 && rRow < ROWS&&rColumn >= 0 && rColumn < COLS){ //if on the board
			if (sitrep.thing[rRow][rColumn].what == unit){ //if its a unit
				if (sitrep.thing[rRow][rColumn].tla != tla){
					a.action = attack;
					a.ar = rRow;
					a.ac = rColumn;
					return a;
				}
			}
		}
		//moves row/column in dir
		switch (dir){
		case up: rRow--; break;
		case dn: rRow++; break;
		case rt: rColumn++; break;
		case lt: rColumn--; break;
		case none: break;
		}

		if (rRow >= 0 && rRow < ROWS&&rColumn >= 0 && rColumn < COLS){ //if on the board
			if (sitrep.thing[rRow][rColumn].what == unit){ //if its a unit
				if (sitrep.thing[rRow][rColumn].tla != tla){
					a.action = attack;
					a.ar = rRow;
					a.ac = rColumn;
					return a;
				}
			}
		}
		//moves row/column in dir
		switch (dir){
		case up: rRow--; break;
		case dn: rRow++; break;
		case rt: rColumn++; break;
		case lt: rColumn--; break;
		case none: break;
		}

		if (rRow >= 0 && rRow < ROWS&&rColumn >= 0 && rColumn < COLS){ //if on the board
			if (sitrep.thing[rRow][rColumn].what == unit){ //if its a unit
				if (sitrep.thing[rRow][rColumn].tla != tla){
					a.action = attack;
					a.ar = rRow;
					a.ac = rColumn;
					return a;
				}
			}
		}

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

/* crown recommendation */
	if (getRank() == crown){
		a.action = fwd;
		a.dir = dn;
		return a;
	}
/*  OLD CODE
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
	// there is not an enemy in front of me
	// so head to the nearest enemy

	if(rank == infantry || rank == knight){
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight)a.maxDist=HORSESPEED; // took out ||rank==crown
			return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
		a.action=nothing;
	}	

	if(rank == archer){
		a.action = fwd;
		a.maxDist=1;
		return a;
	}

	if(rank == crown){
		if(dir==sitrep.nearestEnemy.dirFor){

			switch(dirVariable){ 
				case lt: 
					dirVariable = rt;
					break;
				case rt:
					dirVariable = lt;
					break;
				case up:
					dirVariable = dn;
					break;
				case dn: 
					dirVariable = up;
					break;
			}
		a.action = turn;
		a.dir = dirVariable;
		return a;

		} else {
			a.action=fwd;
			a.maxDist = HORSESPEED;
			return a;
		}
	}
	return a;
	*/
	
}
