#ifndef god_H
#define god_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class god : public Unit {
public:
	god():Unit(){}

	god(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);

	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do

private:

};
#endif
