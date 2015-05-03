#ifndef ipm_H
#define ipm_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class ipm : public Unit {
public:
	ipm():Unit(){numTurns=0;}

	ipm(int ir,int ic,int ihp,Dir idir,Rank irank, bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){rank=irank; numTurns=0;} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	Action Recommendation(SitRep sitrep);

private:
	Rank rank;
	int numTurns;

};
#endif