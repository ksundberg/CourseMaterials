#ifndef tgy_H
#define tgy_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#define CHEAT 1 //Hmm, to cheat or not to cheat . . .
                //Turn to 0 for a fair game. Turn to 1 for entertainment purposes.

using namespace std;

class tgy : public Unit {
public:
	tgy():Unit(){
	}

	tgy(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){}

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do
	static int side;
	static int archerC;
	static int infantryC;
	static int knightC;
	static int crownC;

private:
    Dir pathDir(int sr, int sc, int er, int ec, SitRep &sitrep, Dir d);
    float getDist(int r,int c,int tr,int tc);
    bool localSearch(Dir map[ROWS][COLS], Dir map2[ROWS][COLS],int r, int c, SitRep &sitrep);
    void map1(int minR,int maxR,int minC,int maxC, SitRep &sitrep);
    void map2(int minR,int maxR,int minC,int maxC, SitRep &sitrep);
    void map3(int minR,int maxR,int minC,int maxC, SitRep &sitrep);
    void map4(int minR,int maxR,int minC,int maxC, SitRep &sitrep);
    void defMap(int minR,int maxR,int minC,int maxC, SitRep &sitrep);
    void trollPlace(int minR,int maxR,int minC,int maxC, SitRep &sitrep);
    int idMap(SitRep &sr);
    Dir dfd;
    //Map 1
    Action infRec1(SitRep &sitrep);
    Action archRec1(SitRep &sitrep);
    Action kniRec1(SitRep &sitrep);
    Action crownRec1(SitRep &sitrep);
    //Map 2
    Action infRec2(SitRep &sitrep);
    Action archRec2(SitRep &sitrep);
    Action kniRec2(SitRep &sitrep);
    Action crownRec2(SitRep &sitrep);
    //Map 3
    Action infRec3(SitRep &sitrep);
    Action archRec3(SitRep &sitrep);
    Action kniRec3(SitRep &sitrep);
    Action crownRec3(SitRep &sitrep);
    //Map 4
    Action infRec4(SitRep &sitrep);
    Action archRec4(SitRep &sitrep);
    Action kniRec4(SitRep &sitrep);
    Action crownRec4(SitRep &sitrep);
    //Map Default
    Action infRecD(SitRep &sitrep);
    Action archRecD(SitRep &sitrep);
    Action kniRecD(SitRep &sitrep);
    Action crownRecD(SitRep &sitrep);

    Action trollRec(SitRep &sitrep);
    bool detectEnemies(SitRep &sitrep, Dir d, Location l);
    Rank highRank(SitRep &sitrep, Dir d, Location l);
    int knightID;
    static int *kingHp;
    static int *squireHp;
    static bool *lastDead;
    static int flagForDeath;
    void loading();
    static int loadingFlag;
    static int klr;
    static int klc;
};


#endif
