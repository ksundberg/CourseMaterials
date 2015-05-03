#ifndef dih_H
#define dih_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class dih : public Unit {
public:
	dih():Unit(){}

	dih(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);

	// put unit on board
	
	
	Action Recommendation(SitRep sitrep);
	
	// tell someone what you want to do

private:

};
#endif
