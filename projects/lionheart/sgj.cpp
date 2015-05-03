#include "sgj.h"
#include <cmath>
#include <iostream>

class myUnit{

public:
	myUnit(){
		row = 0;
		colum = 0;
		direction = up;
	}
	myUnit(int ir, int ic, Dir idir);

	//accessor functions
	int getRow(){ return row; }
	int getCol(){ return colum;}
	Dir getDir(){ return direction;}

	void assigner(int ir, int ic, Dir idir){
		row = ir;
		colum = ic;
		direction = idir;
	}
	
	void printer(){
		//cout << "Row: " << row;
		//cout << "  Colum: " << colum;
		//cout << "  Direction: " << direction;
		//cout << endl;
	}
	void newStandCord(Dir newDirection){
		if (newDirection == rt)
			row += 1;
		if (newDirection == lt)
			row -= 1;
		if (newDirection == up)
			colum -= 1;
		if (newDirection == dn)
			colum += 1;
		if (row > 0){
			row = 0;
		}
		if (colum > 0){
			colum = 0;
		}
	}
	void newKnightOrCrownCords(Dir newDirection){
		if (newDirection == rt)
			row += 5;
		if (newDirection == lt)
			row -= 5;
		if (newDirection == up)
			colum -= 5;
		if (newDirection == dn)
			colum += 5;
		if (row > 0){
			row = 0;
		}
		if (colum > 0){
			colum = 0;
		}
	}

private:
	int row;
	int colum;
	Dir direction;

};

void sgj::unitPlacement(int row, int colum, Dir direction){
   static myUnit Crown;
   static myUnit Knight1;
   static myUnit Knight2;
   static myUnit Knight3;
   static myUnit Knight4;
   static myUnit Knight5;
   static myUnit Knight6;
   static myUnit Archer1;
   static myUnit Archer2;
   static myUnit Archer3;
   static myUnit Archer4;
   static myUnit Archer5;
   static myUnit Archer6;
   static myUnit Archer7;
   static myUnit Archer8;
   static myUnit Infantry1;
   static myUnit Infantry2;
   static myUnit Infantry3;
   static myUnit Infantry4;
   static myUnit Infantry5;
   static myUnit Infantry6;
   static myUnit Infantry7;
   static myUnit Infantry8;
   static myUnit Infantry9;
   static myUnit Infantry10;
   static myUnit Infantry11;
   static myUnit Infantry12;
   static myUnit Infantry13;
   static myUnit Infantry14;
   static myUnit Infantry15;
	
   static int functoinCallAmount = 0;

	//May not need
	/*static int rowArrayCount = 0;
	static int colArrayCount = 0;
	static int dirArrayCount = 0;
	static int rowArray[30];
	static int colArray[30];
	static Dir dirArray[30];

	rowArray[rowArrayCount++] = row;
	colArray[colArrayCount++] = colum;
	dirArray[dirArrayCount++] = direction;
	*/
	functoinCallAmount++;
		switch (functoinCallAmount){
		case 1: Crown.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Crown ";
			Crown.printer();
			break;
		case 2: Knight1.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Knight ";
			Knight1.printer();
			break;
		case 3: Knight2.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Knight ";
			Knight2.printer();
			break;
		case 4: Knight3.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Knight ";
			Knight3.printer();
			break;
		case 5: Knight4.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Knight ";
			Knight4.printer();
			break;
		case 6: Knight5.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Knight ";
			Knight5.printer();
			break;
		case 7:	Knight6.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Knight ";
			Knight6.printer();
			break;
		case 8: Archer1.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Archer ";
			Archer1.printer();
			break;
		case 9: Archer2.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Archer ";
			Archer2.printer();
			break;
		case 10: Archer3.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Archer ";
			Archer3.printer();
			break;
		case 11: Archer4.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Archer ";
			Archer4.printer();
			break;
		case 12: Archer5.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Archer ";
			Archer5.printer();
			break;
		case 13: Archer6.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Archer ";
			Archer6.printer();
			break;
		case 14: Archer7.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Archer ";
			Archer7.printer();
			break;
		case 15: Archer8.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Archer ";
			Archer8.printer();
			break;
		case 16: Infantry1.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry1.printer();
			break;
		case 17: Infantry2.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry2.printer();
			break;
		case 18: Infantry3.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry3.printer();
			break;
		case 19: Infantry4.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry4.printer();
			break;
		case 20: Infantry5.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry5.printer();
			break;
		case 21: Infantry6.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry6.printer();
			break;
		case 22: Infantry7.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry7.printer();
			break;
		case 23: Infantry8.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry8.printer();
			break;
		case 24: Infantry9.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry9.printer();
			break;
		case 25: Infantry10.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry10.printer();
			break;
		case 26: Infantry11.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry11.printer();
			break;
		case 27: Infantry12.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry12.printer();
			break;
		case 28: Infantry13.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry13.printer();
			break;
		case 29: Infantry14.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry14.printer();
			break;
		case 30: Infantry15.assigner(row, colum, direction);
			//cout << functoinCallAmount << " Ifantry ";
			Infantry15.printer();
			break;
		}	
}


void sgj::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
	unitPlacement(r, c, dir);
}


// tell someone what you want to do
Action sgj::Recommendation(SitRep sitrep){
	
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

void sgj::update(){
	
}
