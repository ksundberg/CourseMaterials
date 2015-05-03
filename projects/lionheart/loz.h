#ifndef loz_H
#define loz_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class loz : public Unit {
public:
	loz():Unit(){}

	loz(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do
	Action archerAttack(SitRep sitrep);
	//archers attack so they do the 3x3 square up left down and right, looking for enemies to attack
	Action kingMove(SitRep sitrep);
	//The king will randomly move to an open space
private:

};
#endif
