#ifndef tbb_H
#define tbb_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

class tbb : public Unit {
public:
	tbb():Unit(){}

	tbb(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
    Unit(ir,ic,ihp,idir,irank,idead,itla){}
    Location avgBox(int minR,int maxR,int minC,int maxC);
    Location unitWithin(int minR, int maxR, int minC, int maxC, SitRep sitrep, Location initial);
    Location closest(vector<Location> locList, Location initial);
    bool hostileUnit(int minR, int maxR, int minC, int maxC, SitRep sitrep, Location initial);
    bool localSearch(Dir map[ROWS][COLS], Dir map2[ROWS][COLS], int r, int c, const SitRep &sitrep);
    Dir pathDirFor(int sr, int sc, int er, int ec, const SitRep &sitrep);
    Dir armyDetect(int minR, int maxR, int minC, int maxC, SitRep sitrep);
	Location emptyFar(int minR,int maxR,int minC,int maxC, SitRep sitrep, int type);
	Location emptyClose(int minR,int maxR,int minC,int maxC, SitRep sitrep, int type);
	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do

private:
    bool bodyguard;
    Dir armyDir;

};
#endif
