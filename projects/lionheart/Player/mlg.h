#ifndef mlg_H
#define mlg_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


class mlg : public Unit {
public:
	mlg():Unit(){}

	mlg(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){}

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do
    Thing beforeMe(SitRep sitrep);
    bool inRange(Thing enemy, int, int);
    bool validTarget(SitRep);
private:
    bool hg;
};

#endif
