//Assignment 12
//CS 1400-001
//Steven Ban

#ifndef bos_H
#define bos_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;



class bos : public Unit {
public:
	bos():Unit(){}

	bos(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){}

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do

    //My Functions
    Location arRange(int r, int c, Dir Dir, SitRep sitrep);
	bool isRange(int r, int c, Dir Dir, SitRep sitrep);
	int distanceTo(int row, int col, int tr, int tc);
    Location miniMap(int minR, int maxR, int minC, int maxC, SitRep sitrep);


private:


};
#endif
