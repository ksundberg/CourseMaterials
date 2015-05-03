#ifndef jmh_H
#define jmh_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class jmh : public Unit {
public:
	jmh():Unit(){}

	jmh(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){}

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do

	void setUnitid(int newUnitid){
	    unitid=newUnitid;
	}

	void setUnitorder(int newUnitorder){
        unitorder=newUnitorder;
    }

void archeryPriorityCheck(int& tr,int& tc,int& pr,int& pc,int&pl,SitRep sitrep){
if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
    if(sitrep.thing[tr][tc].what==unit){
        if(sitrep.thing[tr][tc].tla!=tla){
            if(sitrep.thing[tr][tc].rank==crown){
                pl=4;
                pr=tr;
                pc=tc;}
            if(sitrep.thing[tr][tc].rank==archer&&pl<3){
                pl=3;
                pr=tr;
                pc=tc;}
            if(sitrep.thing[tr][tc].rank==knight&&pl<2){
                pl=2;
                pr=tr;
                pc=tc;}
            if(sitrep.thing[tr][tc].rank==infantry&&pl<1){
                pl=1;
                pr=tr;
                pc=tc;}
        }
    }
}
}

void archeryAttack(int& tr,int& tc, SitRep sitrep, Dir dir,int& pl){

    int pr=tr;
    int pc=tc;
    switch(dir){
	case up:
	    tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        tr++;
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc--;
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
	break;
	case dn:
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr--;
        tr--;
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc--;
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        break;
	case rt:
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc--;
        tc--;
        tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr--;
        tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        break;
	case lt:
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc++;
        tc++;
        tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr--;
        tr--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tc--;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        tr++;
        tr++;
        archeryPriorityCheck(tr,tc,pr,pc,pl,sitrep);
        break;
	case none: break;
	}
	tr=pr;
	tc=pc;
}

int enemyCount(SitRep sitrep){
int r,c;
int ec=0;
r=0;
c=0;
for(r=0;r<30;++r){
    for(c=0;c<30;++c){
        if(sitrep.thing[r][c].what==unit){
            if(sitrep.thing[r][c].tla!=tla){
                ec++;
            }
        }
    }
}
return ec;
}

int getOrders(){
    return unitorder;}

int armyCount(SitRep sitrep){
int r,c;
int ac=0;
r=0;
c=0;
for(r=0;r<30;++r){
    for(c=0;c<30;++c){
        if(sitrep.thing[r][c].what==unit){
            if(sitrep.thing[r][c].tla==tla){
                ac++;
            }
        }
    }
}
return ac;
}

int getside(){
    return sideofmap;
}

void setside(int newside){
    sideofmap=newside;
}

Action crownhunting(int r,int c,Dir dir, SitRep sitrep){
Action a;

	// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemyCrown.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
}

Action hunting(int r,int c,Dir dir, SitRep sitrep){
Action a;

	// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
}

Action archerhunting(int r,int c,Dir dir, SitRep sitrep){
Action a;

	// first, try to attack in front of you
	//ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
}

Action guard(int r,int c,Dir dir,SitRep sitrep){
Action a;
// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				return a;
			}
		}
	}
	// there is not an enemy in front of me
	// so turn
	a.action=turn;
	a.dir=sitrep.nearestEnemy.dirFor;
	return a;
}

int totalcount(SitRep sitrep){
    int r,c;
    int totalc=0;
    r=0;
    c=0;
    for(r=0;r<30;++r){
        for(c=0;c<30;++c){
            if(sitrep.thing[r][c].what==unit){
                totalc++;
        }
    }
}
return totalc;
}



private:
    int unitid;
    int unitorder;//1=advance 2=seek and destroy 3=king's guard
    int sideofmap;//1 is left, 2 is right, 3 is top, 4 is bottom
};
#endif
