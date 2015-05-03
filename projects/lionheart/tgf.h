#ifndef tgf_H
#define tgf_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class tgf : public Unit {
public:
	tgf():Unit(){}

	tgf(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
//dww
/*
	{
	int tr,tc;
	bool success=false;

		while(!success){
		tr=minR+rand()%(1+maxR-minR);
		tc=minC+rand()%(1+maxC-minC);
		if(sitrep.thing[tr][tc].what==space)success=true;
		}
	}
*/
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do

private:

};
#endif
