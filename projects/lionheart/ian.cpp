// Ian Wells
// 11/27/2013
// ian.cpp 
// This is my class definition for my units in the Lionheart game

#include "ian.h"
#include <cmath>
#include <iostream>

void ian::Place(int minR,int maxR,int minC,int maxC, SitRep $sitrep){
	bool success = false;
	int testRow, testCol;
	static int crownRow, crownCol;
	Dir forward = rt;

	// Find forward direction based on what location our units start in
	if((maxR+minR)/2>=(maxC+minC)/2){
		if((maxC+minC)/2<COLS/3){forward=rt;}
		else{forward=up;}
	}
	if((maxR+minR)/2<=(maxC+minC)/2){
		if((maxR+minR)/2>ROWS/3){forward=lt;}
		else{forward=dn;}
	}
	dir = forward;

	// Set testRow and testCol based on which dir forward is
	if(rank == crown){
		switch(forward){
		case up: testCol = (minC+maxC)/2;
			testRow = maxR;
			break;
		case dn: testCol = (minC+maxC)/2;
			testRow = minR;
			break;
		case lt: testRow = (minR+maxR)/2;
			testCol = maxC;
			break;
		case rt: testRow = (minR+maxR)/2;
			testCol = minC;
			break;
		case none:
			break;
		}

		// Attempt to place the crown in testRow, testCol
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
			crownRow = r;
			crownCol = c;
		}
		// If that spot was not open for the crown then look nearby
		if(!success){
			if(forward == dn || forward == up){
				testCol ++;
				if($sitrep.thing[testRow][testCol].what==space && !success){
					success=true;
					r = testRow;
					c = testCol;
					crownRow = r;
					crownCol = c;
				}
				testCol = testCol-2;
				if($sitrep.thing[testRow][testCol].what==space && !success){
					success=true;
					r = testRow;
					c = testCol;
					crownRow = r;
					crownCol = c;
				}
			}
			if(forward == lt || forward == rt){
				testRow ++;
				if($sitrep.thing[testRow][testCol].what==space && !success){
					success=true;
					r = testRow;
					c = testCol;
					crownRow = r;
					crownCol = c;
				}
				testRow = testRow-2;
				if($sitrep.thing[testRow][testCol].what==space && !success){
					success=true;
					r = testRow;
					c = testCol;
					crownRow = r;
					crownCol = c;
				}
			}
			// If a space for the crown was not found then place it in a random spot
			while(!success){
				testRow = minR + rand()%(maxR-minR+1);
				testCol = minC + rand()%(maxC-minC+1);
				if($sitrep.thing[testRow][testCol].what==space){
				success=true;
				r = testRow;
				c = testCol;
				crownRow = r;
				crownCol = c;
				}
			}
		}
	}

	int a,b;
	switch(forward){
	case up: b=-1;
		break;
	case dn: b=1;
		break;
	case lt: a=-1;
		break;
	case rt: a=1;
		break;
	case none:
		break;
	}

	// Atempt to place all the knights in formation
	if(rank==knight && (forward==rt || forward==lt)){ // Facing right or left
		success = false;
		testRow = crownRow -2;
		testCol = crownCol +4*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -1;
		testCol = crownCol +4*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow;
		testCol = crownCol +4*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1;
		testCol = crownCol +4*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2;
		testCol = crownCol +4*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2;
		testCol = crownCol +3*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
	}
	if(rank==knight && (forward==up || forward==dn)){ // Facing up or down
		success = false;
		testRow = crownRow +4*b;
		testCol = crownCol -2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +4*b;
		testCol = crownCol -1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +4*b;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +4*b;
		testCol = crownCol +1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +4*b;
		testCol = crownCol +2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +3*b;
		testCol = crownCol +2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
	}

	// Atempt to place all the archers in formation
	if(rank==archer && (forward==rt || forward==lt)){ // Facing right or left
		success = false;
		testRow = crownRow -1;
		testCol = crownCol +3*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow;
		testCol = crownCol +3*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1;
		testCol = crownCol +3*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1;
		testCol = crownCol +1*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -1;
		testCol = crownCol +1*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow;
		testCol = crownCol +2*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
	}
	if(rank==archer && (forward==up || forward==dn)){ // Facing up or down
		success = false;
		testRow = crownRow +3*b;
		testCol = crownCol -1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +3*b;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +3*b;
		testCol = crownCol +1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1*b;
		testCol = crownCol +1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1*b;
		testCol = crownCol -1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2*b;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
	}

	// Atempt to place all the infantry in formation
	if(rank==infantry && (forward==rt || forward==lt)){ // Facing left or right
		success = false;
		testRow = crownRow +3;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -1;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -2;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -3;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +3;
		testCol = crownCol +1*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2;
		testCol = crownCol +1*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -3;
		testCol = crownCol +1*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -2;
		testCol = crownCol +1*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow;
		testCol = crownCol +1*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2;
		testCol = crownCol +2*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1;
		testCol = crownCol +2*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -1;
		testCol = crownCol +2*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -2;
		testCol = crownCol +2*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -3;
		testCol = crownCol +2*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow -2;
		testCol = crownCol +3*a;
		if($sitrep.thing[testRow][testCol].what==space && !success){
		success=true;
			r = testRow;
			c = testCol;
		}
	}
	if(rank==infantry && (forward==up || forward==dn)){ // Facing up or down
		success = false;
		testRow = crownRow;
		testCol = crownCol +3;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow;
		testCol = crownCol +2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow;
		testCol = crownCol +1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		} 
		testRow = crownRow;
		testCol = crownCol -1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		} 
		testRow = crownRow;
		testCol = crownCol -2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow;
		testCol = crownCol -3;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1*b;
		testCol = crownCol +3;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1*b;
		testCol = crownCol +2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1*b;
		testCol = crownCol -3;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1*b;
		testCol = crownCol -2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +1*b;
		testCol = crownCol;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2*b;
		testCol = crownCol +2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2*b;
		testCol = crownCol +1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2*b;
		testCol = crownCol -1;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2*b;
		testCol = crownCol -2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +2*b;
		testCol = crownCol -3;
		if($sitrep.thing[testRow][testCol].what==space && !success){
			success=true;
			r = testRow;
			c = testCol;
		}
		testRow = crownRow +3*b;
		testCol = crownCol -2;
		if($sitrep.thing[testRow][testCol].what==space && !success){
		success=true;
			r = testRow;
			c = testCol;
		}
	}
	// If no location is found in formation then place the unit randomly
	while(!success){
		testRow = minR + rand()%(maxR-minR+1);
		testCol = minC + rand()%(maxC-minC+1);
		if($sitrep.thing[testRow][testCol].what==space){
			success=true;
			r = testRow;
			c = testCol;
		}
	}	
}	


// Tell the game what the unit wants to do
Action ian::Recommendation(SitRep $sitrep){
	Action a;
	// A bunch of static variables to keep track of things...
	static int turnCount = 0;
	static int lastNearestDistance = 30, thisNearestDistance = 30;
	static bool theyAttack = true;
	static bool defensiveFormation = true;
	static int sinceLastMoved = 0;
	static bool crownProtected = true;
	static int crownRow = 0, crownCol = 0;
	static int protectRUp = 0, protectCUp = 0;
	static int protectRDn = 0, protectCDn = 0;
	static int protectRRt = 0, protectCRt = 0;
	static int protectRLt = 0, protectCLt = 0;
	static Dir forward;
	static int archerAttackTime = 0;
	static bool archerAttack = false;

	// Increment turnCount each time the crown is called by Recomendation
	if(rank==crown){
		turnCount++;
	}

	// Find the total hp of both teams
	int ourHp = 0, theirHp = 0;
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			if($sitrep.thing[i][j].what==unit){
				if($sitrep.thing[i][j].tla==tla){ourHp = ourHp + $sitrep.thing[i][j].hp;}
				if($sitrep.thing[i][j].tla!=tla){theirHp = theirHp + $sitrep.thing[i][j].hp;}
			}
		}
	}
	
	// Find out if the enemy is advancing by comparing nearest enemy from this turn with last turn
	if(turnCount==1 && rank==crown){
		lastNearestDistance = abs($sitrep.nearestEnemy.r-r) + abs($sitrep.nearestEnemy.c-c);
		forward=dir;
	}
	if(turnCount>1 && rank==crown){
		thisNearestDistance = abs($sitrep.nearestEnemy.r-r) + abs($sitrep.nearestEnemy.c-c);
		if(thisNearestDistance < lastNearestDistance){
			thisNearestDistance = lastNearestDistance;
			theyAttack = true;
			defensiveFormation = true;
			sinceLastMoved = 0;
		}
	}

	// Find out if enemy units are no longer advancing on us
	if(turnCount>1 && rank==crown){
		if(thisNearestDistance=lastNearestDistance){
			sinceLastMoved ++;
			if(sinceLastMoved==5){
				theyAttack = false;
				defensiveFormation = false;
			}
		}
	}

	// Check to see if our crown is protected
	if(rank==crown){
		crownRow = r;
		crownCol = c;
		if($sitrep.thing[r+1][c].what==space && (r+1)<ROWS){
			crownProtected = false;
			protectRDn = (r+1);
			protectCDn = c;
		}
		if($sitrep.thing[r-1][c].what==space && (r-1)>0){
			crownProtected = false;
			protectRUp = (r-1);
			protectCUp = c;
		}
		if($sitrep.thing[r][c+1].what==space && (c+1)<COLS){
			crownProtected = false;
			protectRRt = r;
			protectCRt = (c+1);
		}
		if($sitrep.thing[r][c-1].what==space && (c-1)>0){
			crownProtected = false;
			protectRLt = r;
			protectCLt = (c-1);
		}
		if($sitrep.thing[r][c-1].what!=space && $sitrep.thing[r][c+1].what!=space &&
			$sitrep.thing[r+1][c].what!=space && $sitrep.thing[r-1][c].what!=space){
				crownProtected = true;}
	}

	// Move units in front of the crown if he is unprotected and we are on defense
	// More than one unit will move in the same turn if more than one side of the crown is open 
	if(defensiveFormation && !crownProtected && rank != crown){ //Dn
		if(r==protectRDn && (c==(protectCDn-1) || c==(protectCDn+1))){
			if(c==protectCDn-1){
				if(dir==rt){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = rt;
					return a;
				}
			}
			else{
				if(dir==lt){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = lt;
					return a;
				}
			}
		}
		if(c==protectCDn && (r==(protectRDn-1) || r==(protectRDn+1))){
			if(r==protectRDn-1){
				if(dir==up){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = up;
					return a;
				}
			}
			else{
				if(dir==dn){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = dn;
					return a;
				}
			}
		}
	}
	if(defensiveFormation && !crownProtected && rank != crown){ //Up
		if(r==protectRUp && (c==(protectCUp-1) || c==(protectCUp+1))){
			if(c==protectCUp-1){
				if(dir==rt){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = rt;
					return a;
				}
			}
			else{
				if(dir==lt){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = lt;
					return a;
				}
			}
		}
		if(c==protectCUp && (r==(protectRUp-1) || r==(protectRUp+1))){
			if(r==protectRUp-1){
				if(dir==up){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = up;
					return a;
				}
			}
			else{
				if(dir==dn){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = dn;
					return a;
				}
			}
		}
	}
	if(defensiveFormation && !crownProtected && rank != crown){ //Rt
		if(r==protectRRt && (c==(protectCRt-1) || c==(protectCRt+1))){
			if(c==protectCRt-1){
				if(dir==rt){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = rt;
					return a;
				}
			}
			else{
				if(dir==lt){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = lt;
					return a;
				}
			}
		}
		if(c==protectCRt && (r==(protectRRt-1) || r==(protectRRt+1))){
			if(r==protectRRt-1){
				if(dir==up){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = up;
					return a;
				}
			}
			else{
				if(dir==dn){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = dn;
					return a;
				}
			}
		}
	}
	if(defensiveFormation && !crownProtected && rank != crown){ //Lt
		if(r==protectRLt && (c==(protectCLt-1) || c==(protectCLt+1))){
			if(c==protectCLt-1){
				if(dir==rt){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = rt;
					return a;
				}
			}
			else{
				if(dir==lt){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = lt;
					return a;
				}
			}
		}
		if(c==protectCLt && (r==(protectRLt-1) || r==(protectRLt+1))){
			if(r==protectRLt-1){
				if(dir==up){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = up;
					return a;
				}
			}
			else{
				if(dir==dn){
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
				else{
					a.action = turn;
					a.dir = dn;
					return a;
				}
			}
		}
	}

	int tr=r,tc=c;
	// Archers try to attack in a 3x3 box in front of them
	// Attempt to attack the enemy crown first
	if(rank==archer){
		tr=r;
		tc=c;
		switch(dir){
		case up: tr=tr-3; tc=tc-1;
			break;
		case dn: tr=tr+1; tc=tc-1;
			break;
		case rt: tr=tr-1; tc=tc+1;
			break;
		case lt: tr=tr-1; tc=tc-3;
			break;
		case none: 
			break;
		}
		for(int i=0;i<3;i++){ // Scan a 3x3 box for enemy units
			for(int j=0;j<3;j++){
				if($sitrep.thing[tr+i][tc+j].what == unit){
					if($sitrep.thing[tr+i][tc+j].tla != tla){
						if($sitrep.thing[tr+i][tc+j].rank == crown){
							a.action=attack;
							a.ar=tr+i;
							a.ac=tc+j;
							return a;
						}
					}
				}
			}
		}
	}

	// Archers try to attack in a 3x3 box in front of them
	// If the crown isn't found then look for archers next
	if(rank==archer){
		tr=r;
		tc=c;
		switch(dir){
		case up: tr=tr-3; tc=tc-1;
			break;
		case dn: tr=tr+1; tc=tc-1;
			break;
		case rt: tr=tr-1; tc=tc+1;
			break;
		case lt: tr=tr-1; tc=tc-3;
			break;
		case none: 
			break;
		}
		for(int i=0;i<3;i++){ // Scan a 3x3 box for enemy units
			for(int j=0;j<3;j++){
				if($sitrep.thing[tr+i][tc+j].what == unit){
					if($sitrep.thing[tr+i][tc+j].tla != tla){
						if($sitrep.thing[tr+i][tc+j].rank == archer){
							a.action=attack;
							a.ar=tr+i;
							a.ac=tc+j;
							return a;
						}
					}
				}
			}
		}
	}

	// Archers try to attack in a 3x3 box in front of them
	// If we can't find the enemy crown or archers then attack any enemy unit
	if(rank==archer){
		tr=r;
		tc=c;
		switch(dir){
		case up: tr=tr-3; tc=tc-1;
			break;
		case dn: tr=tr+1; tc=tc-1;
			break;
		case rt: tr=tr-1; tc=tc+1;
			break;
		case lt: tr=tr-1; tc=tc-3;
			break;
		case none: 
			break;
		}
		for(int i=0;i<3;i++){ // Scan a 3x3 box for enemy units
			for(int j=0;j<3;j++){
				if($sitrep.thing[tr+i][tc+j].what == unit){
					if($sitrep.thing[tr+i][tc+j].tla != tla){
					a.action=attack;
					a.ar=tr+i;
					a.ac=tc+j;
					return a;
					}
				}
			}
		}
	}

	// All units try to attack one space in front
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0 && tr<ROWS && tc>=0 && tc<COLS){
		if($sitrep.thing[tr][tc].what==unit){
			if($sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}

	// Turn to face closest enemy unit if it is within 3 spaces of my unit
	tr=r-3;
	tc=c-3;
	int eRow=4, eCol=4;
	int eRowAbs=4, eColAbs=4;
	bool foundEnemy = false;
	Dir testDir = dir;
	for(int i=0;i<7;i++){ // Scan an area 3 spaces around my unit in each direction
		for(int j=0;j<7;j++){
			if((tr+i>=0 && tr+i<ROWS) && (tc+j>=0 && tc+j<COLS)){
				if($sitrep.thing[tr+i][tc+j].what == unit){
					if($sitrep.thing[tr+i][tc+j].tla != tla){
						if((abs(r-(tr+i))+abs(c-(tc+j)))<(abs(eRowAbs+eColAbs))){ // Look for closest enemy
							foundEnemy = true;
							eRowAbs = abs(r-(tr+i)); // Each time a closer enemy is found
							eColAbs = abs(c-(tc+j)); // reset these to the new enemy location
							eRow=(tr+i);
							eCol=(tc+j);
						}
					}
				}
			}
		}
	}
	if(foundEnemy && eRow==r && eCol>c){testDir=rt;}
	if(foundEnemy && eRow==r && eCol<c){testDir=lt;}
	if(foundEnemy && eCol==c && eRow<r){testDir=up;}
	if(foundEnemy && eCol==c && eRow>r){testDir=dn;}
	if(rank==archer && foundEnemy && (eRow==r || eRow==(r-1) || eRow==(r+1)) && eCol>c){testDir=rt;} // Archers face
	if(rank==archer && foundEnemy && (eRow==r || eRow==(r-1) || eRow==(r+1)) && eCol<c){testDir=lt;} // enemies within
	if(rank==archer && foundEnemy && (eCol==c || eCol==(c-1) || eCol==(c+1)) && eRow<r){testDir=up;} // their 3x3
	if(rank==archer && foundEnemy && (eCol==c || eCol==(c-1) || eCol==(c+1)) && eRow>r){testDir=dn;} // attack area
	if(foundEnemy && testDir!=dir){ // Only turn if my unit isn't already facing that direction
		a.action = turn;
		a.dir = testDir;
		return a;
	}

	// Don't move the units that are protecting our crown
	if((r+1)==crownRow && c==crownCol){
		a.action=nothing;
		return a;
	}
	if((r-1)==crownRow && c==crownCol){
		a.action=nothing;
		return a;
	}
	if(r==crownRow && (c+1)==crownCol){
		a.action=nothing;
		return a;
	}
	if(r==crownRow && (c-1)==crownCol){
		a.action=nothing;
		return a;
	}
	if((r-1)==crownRow && (c+1)==crownCol){
		a.action=nothing;
		return a;
	}
	if((r-1)==crownRow && (c-1)==crownCol){
		a.action=nothing;
		return a;
	}
	if((r+1)==crownRow && (c+1)==crownCol){
		a.action=nothing;
		return a;
	}
	if((r+1)==crownRow && (c-1)==crownCol){
		a.action=nothing;
		return a;
	}
	if(((r-2)==crownRow && c==crownCol) && theirHp>20){ // Keep fewer units on defense if their hp is low
		a.action=nothing;
		return a;
	}
	if(((r+2)==crownRow && c==crownCol) && theirHp>20){
		a.action=nothing;
		return a;
	}
	if((r==crownRow && (c-2)==crownCol) && theirHp>20){
		a.action=nothing;
		return a;
	}
	if((r==crownRow && (c+2)==crownCol) && theirHp>20){
		a.action=nothing;
		return a;
	}

	// If the enemy doesn't attack after a certain number of turns we will attack
	// Send in archers first to attack at range then the rest of our units follow
	if((turnCount>20 && !defensiveFormation)){
		if(!archerAttack){archerAttackTime = turnCount;}
		archerAttack = true;
		if(forward==up && turnCount<(archerAttackTime+6)){
			if(rank==knight || rank==infantry){ // Move units out of the way of archers
				if(c<15){
					if(dir==lt){
						a.action=fwd;
						a.maxDist=1; 
					return a;
					}
					else{
						a.action=turn;
						a.dir=lt;
						return a;
					}
				}
				if(c>=15){
					if(dir==rt){
						a.action=fwd;
						a.maxDist=1;
					return a;
					}
					else{
						a.action=turn;
						a.dir=rt;
						return a;
					}
				}
			}
		}
		if(forward==dn && turnCount<(archerAttackTime+6)){
			if(rank==knight || rank==infantry){
				if(c<15){
					if(dir==lt){
						a.action=fwd;
						a.maxDist=1; 
					return a;
					}
					else{
						a.action=turn;
						a.dir=lt;
						return a;
					}
				}
				if(c>=15){
					if(dir==rt){
						a.action=fwd;
						a.maxDist=1; 
					return a;
					}
					else{
						a.action=turn;
						a.dir=rt;
						return a;
					}
				}
			}
		}
		if(forward==lt && turnCount<(archerAttackTime+6)){
			if(rank==knight || rank==infantry){
				if(r<15){
					if(dir==up){
						a.action=fwd;
						a.maxDist=1; 
					return a;
					}
					else{
						a.action=turn;
						a.dir=up;
						return a;
					}
				}
				if(r>=15){
					if(dir==dn){
						a.action=fwd;
						a.maxDist=1; 
					return a;
					}
					else{
						a.action=turn;
						a.dir=dn;
						return a;
					}
				}
			}
		}
		if(forward==rt&& turnCount<(archerAttackTime+6)){
			if(rank==knight || rank==infantry){
				if(r<15){
					if(dir==up){
						a.action=fwd;
						a.maxDist=1; 
					return a;
					}
					else{
						a.action=turn;
						a.dir=up;
						return a;
					}
				}
				if(r>=15){
					if(dir==dn){
						a.action=fwd;
						a.maxDist=1; 
					return a;
					}
					else{
						a.action=turn;
						a.dir=dn;
						return a;
					}
				}
			}
		}
		if(rank==archer && turnCount<(archerAttackTime+8)){
			if(dir==$sitrep.nearestEnemy.dirFor){
				a.action=fwd;
				a.maxDist=1;
				if(rank==knight){a.maxDist=5;} 
				return a;
			}
			else{
				a.action=turn;
				a.dir=$sitrep.nearestEnemy.dirFor;
				return a;
			}
		}
	}

	// Figure out how far knights need to travel to not overshoot
	// the enemy positions or gaps in the rocks
	int knightDist=5;
	if(forward==rt && c<17){
		knightDist=1;
	}
	if(forward==lt && c<12){
		knightDist=1;
	}
	if(forward==dn && r<17){
		knightDist=1;
	}
	if(forward==up && r>12){
		knightDist=1;
	}
	if(rank==knight && (abs($sitrep.nearestEnemy.r)+(abs($sitrep.nearestEnemy.c))<9)){
		if(($sitrep.nearestEnemy.dirFor==up || $sitrep.nearestEnemy.dirFor==dn) && $sitrep.nearestEnemy.c!=c){
			if(abs($sitrep.nearestEnemy.r-r)<5){
				knightDist=abs($sitrep.nearestEnemy.r-r);
			}
		}
		if(($sitrep.nearestEnemy.dirFor==lt || $sitrep.nearestEnemy.dirFor==rt) && $sitrep.nearestEnemy.r!=r){
			if(abs($sitrep.nearestEnemy.c-c)<5){
				knightDist=abs($sitrep.nearestEnemy.c-c);
			}
		}
	}
	
	// If enemy archers advance within 4 units of my formation then send units to attack them
	int enemyR, enemyC;
	if(rank!=crown && (abs($sitrep.nearestEnemy.r-r)+abs($sitrep.nearestEnemy.c-c)<4)){
		enemyR=$sitrep.nearestEnemy.r;
		enemyC=$sitrep.nearestEnemy.c;
		if($sitrep.thing[enemyR][enemyC].rank==archer){
			if(dir==$sitrep.nearestEnemy.dirFor){
				a.action=fwd;
				a.maxDist=1;
				if(rank==knight){
					a.maxDist=knightDist;}
				return a;
			} 			
			else{
				a.action=turn;
				a.dir=$sitrep.nearestEnemy.dirFor;
				return a;
			}
		}
	}

	// If the enemy hp total drops below a certain level and they stop attacking or
	// we are through the first phase of our archer attack then we go on full offense
	if((rank!=crown && archerAttack==true && turnCount>(archerAttackTime+8)) || 
		(rank!=crown && !defensiveFormation && ourHp>(theirHp*1.5)) || (ourHp>(theirHp*3))){
		if(dir==$sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight){
				a.maxDist=knightDist;}
			return a;
		} 			
		else{
			a.action=turn;
			a.dir=$sitrep.nearestEnemy.dirFor;
			return a;
		}
	}

	// If there is nothing worth doing...
	a.action=nothing;
	return a;	
}