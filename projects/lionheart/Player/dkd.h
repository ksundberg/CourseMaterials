#ifndef dkd_H
#define dkd_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class dkd : public Unit {
public:
	dkd():Unit(){}

	dkd(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);

	Action Recommendation(SitRep sitrep);

private:

};
#endif
