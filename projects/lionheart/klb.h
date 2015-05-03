#ifndef klb_H
#define klb_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
//#include "lionheart.cpp"

using namespace std;

class klb : public Unit {
public:
	klb():Unit(){}

	klb(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){
	if(rank==archer){numArchers++; enumArchers++;  eunitNumber=enumArchers; unitNumber=numArchers;
	}else if(rank==infantry){numInfantry++; enumInfantry++; eunitNumber=enumInfantry;  unitNumber=numInfantry;
	}else if(rank==knight){numKnights++; enumKnights++; eunitNumber=enumKnights; unitNumber=numKnights;
	}
	}

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do


	void ePlace(int minR,int maxR,int minC,int maxC, SitRep sitrep);
private:
	static int numArchers;
	static int numInfantry;
	static int numKnights;
	static int enumArchers;
	static int enumInfantry;
	static int enumKnights;
	int unitNumber;
	int eunitNumber;
	static int numTurn;


};

#endif
