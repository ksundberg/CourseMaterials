#ifndef usu_H
#define usu_H
#define INFANTRYHP 10
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class usu:public Unit{
public:
	usu():Unit(){
	r=0;
	c=0;
	hp=INFANTRYHP;
	dir=up;
	rank=infantry;
	dead=false;
	tla= "usu";
	}

	usu(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):

	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	Action Recommendation(SitRep sitrep);
	

private:

};
#endif
