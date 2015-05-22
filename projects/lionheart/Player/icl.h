#ifndef icl_H
#define icl_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "lionheart2.h"

using namespace std;

class icl : public Unit {
public:
	icl():Unit(){}

	icl(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){}
	
	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	Action Recommendation(SitRep sitrep);
	

private:

};
#endif
