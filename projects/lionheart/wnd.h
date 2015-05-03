#ifndef WND_H
#define WND_H

#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class wnd : public Unit {
public:
	wnd():Unit(){}

	wnd(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do


private:
	Dir startDir;
	static int crownR;
	static int crownC;
	static bool crownSafe;
	static int wndKnights;
	static int wndArchers;
	int knightId;
	int archerId;
	bool crownsPersonalGuard;
	bool squadRight;
	bool squadLeft;
};
#endif