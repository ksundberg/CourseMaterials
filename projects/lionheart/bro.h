#ifndef bro_H
#define bro_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class bro : public Unit {
public:
	bro():Unit(){}

	bro(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// insert piece
	Action Recommendation(SitRep sitrep);
	// input commands

private:

};
#endif
