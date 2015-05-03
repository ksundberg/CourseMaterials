#include "dos.h"
#include <cmath>
#include <iostream>


void dos::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool openSpace=false;
	int randomRow,randomColumn;
	Dir startingDirection; // creates a variable for the directions to store the place (lt,rt,up,dn)
	while(!openSpace){
		randomRow=minR+rand()%(maxR-minR);	//chooses a random row within the board boundries (max/min) lt/rt
		randomColumn=minC+rand()%(maxC-minC);	//chooses a random column within board boundired (max/min) up/dn
		if(sitrep.thing[randomRow][randomColumn].what==space)openSpace=true; //if the thing in the block is an open space
	}
	int rowdist = ROWS / 2 - randomRow; //rowdist is the number of rows, divided by two, and subtract the random row chosen (to see what side of board unit is on)
	int columndist=COLS/2-randomColumn; //same as above only for column (this is to see what side of the board the unit is on)
	if(abs(rowdist)<abs(columndist)){  //if the absolute value of row is less than absolute of column 
		if (columndist>0){ startingDirection = rt; }//if on the left side of the board
		else { startingDirection = lt;} //else if their on the right side of the board
	}else{
		if (rowdist > 0){ startingDirection = up; }//if their on the bottom of the board
		else { startingDirection = dn;}//if their on the top of the board
	}
	r=randomRow; //set row to where the unit was placed
	c=randomColumn; //set column to where the unit was placed
	dir=startingDirection;
}


// tell someone what you want to do
Action dos::Recommendation(SitRep sitrep){

	// this code is provided as an example only
	// use at your own risk
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




		if (rRow >= 0 && rRow < ROWS&&rColumn >= 0 && rColumn < COLS){ //if on the board
			if (sitrep.thing[rRow][rColumn].what == unit){ //if its a unit
				if (sitrep.thing[rRow][rColumn].tla != tla){
					a.action = attack;
					return a;
				}
			}
		}

		if (dir == sitrep.nearestEnemy.dirFor){
			a.action = fwd;
			a.maxDist = 1;
			a.maxDist = HORSESPEED;
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

	/*recommendations for the crown*/
	if (getRank() == crown){

		/*bool turned = false;
		for (int i = 0; turned; i++){
			a.action = turn;
			a.dir = lt;
			if (i > 1)turned = true;
		}
		a.action = fwd;
	
		return a;
		*/
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
					a.action = turn;
					tempDir = sitrep.nearestEnemy.dirFor;
					//Dir{up = 1,dn = 2,lt = 3,rt = 4,none}
					switch (tempDir){
					case up: tempDir = dn; break;
					case dn: tempDir = up; break;
					case lt: tempDir = rt; break;
					case rt: tempDir = lt; break;
					default: tempDir = none; break;
					}
					a.dir = tempDir;
					return a;
				}

				
			}
		}

	
			if (rRow >= 0 && rRow < ROWS&&rColumn >= 0 && rColumn < COLS){ //if on the board
				if (getDir() == sitrep.nearestEnemy.dirFor){

				a.action = turn;
				tempDir = sitrep.nearestEnemy.dirFor;
				//Dir{up = 1,dn = 2,lt = 3,rt = 4,none}
				switch (tempDir){
				case up: tempDir = dn; break;
				case dn: tempDir = up; break;
				case lt: tempDir = rt; break;
				case rt: tempDir = lt; break;
				default: tempDir = none; break;
				}
				a.dir = tempDir;
				return a;
			}
		}
		a.maxDist = HORSESPEED;
		a.action = fwd;
		return a;
	
	/*
	if (dir == sitrep.nearestEnemy.dirFor){
	a.action = fwd;
	a.maxDist = 1;
	if (rank == knight || rank == crown)a.maxDist = HORSESPEED;
	return a;
	}
	else {
	a.action = turn;
	a.dir = sitrep.nearestEnemy.dirFor;
	return a;
	}
	a.action = nothing;
	return a;
	*/
	}
}
