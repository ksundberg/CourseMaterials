#ifndef YHG_H
#define YHG_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class yhg : public Unit {
public:
	yhg():Unit(){}

	yhg(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do
	Dir archerCheck(SitRep sitrep);
	bool dangerCheck(SitRep sitrep);
	Dir archerDir(SitRep sitrep);

private:
	static int aR, aC;
	static bool inCombat;
	static bool crownThreat;
	static Dir threatDir;
	static int infStart;
	static int numAttacks;
	int cR, cC;
	int time;
	bool guarded;
};
#endif YHG_H