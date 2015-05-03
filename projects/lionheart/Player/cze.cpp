//Fabio Gottlicher, A01647928, tla: CZE

#include "cze.h"
#include <cmath>
#include <iostream>


void cze::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
int pr,pc;
bool check=0;

while(!check){
   static bool crplaced = false;

   if(crplaced==false){
    if(minC<COLS/2) pc=minC+2;  //place crown 2 cols from back
    else pc=maxC-2;
    pr=(minR+((maxR-minR)/2));
    if(sitrep.thing[pr][pc].what==space) check=1;
    crplaced=true;
    r=pr;
    c=pc;
    return;
   }

   if(minC<COLS/2){     //everything else in front 3 rows
    pc=maxC-rand()%3;
    pr=minR+rand()%(1+maxR-minR);
    if(sitrep.thing[pr][pc].what==space) check=1;
   }
   if(minC>COLS/2){     //everything else in front 3 rows
    pc=minC+rand()%3;
    pr=minR+rand()%(1+maxR-minR);
    if(sitrep.thing[pr][pc].what==space) check=1;
   }
r=pr;
c=pc;
}
}

// tell someone what you want to do
Action cze::Recommendation(SitRep sitrep){

	Action a;

        static Location crloc;
		if(rank==crown&&tla==tla){      //crown location
        crloc.r=r;
        crloc.c=c;
		}



	if(rank==archer){       //archer attack
    int atr=r,atc=c; //archer target r and c
	switch(dir){
	case up: atr=atr-2; break;
	case dn: atr=atr+2; break;
	case rt: atc=atc+2; break;
	case lt: atc=atc-2; break;
	case none: break;
	}
		if(atr>=0&&atr<ROWS&&atc>=0&&atc<COLS){
		if(sitrep.thing[atr-1][atc-1].what==unit&&sitrep.thing[atr-1][atc-1].tla!=tla){
        a.action=attack;
				a.ar=atr-1;
				a.ac=atc-1;
				return a;
		}
				if(sitrep.thing[atr-1][atc].what==unit&&sitrep.thing[atr-1][atc].tla!=tla){
        a.action=attack;
				a.ar=atr-1;
				a.ac=atc;
				return a;
		}

					if(sitrep.thing[atr-1][atc+1].what==unit&&sitrep.thing[atr-1][atc+1].tla!=tla){
        a.action=attack;
				a.ar=atr-1;
				a.ac=atc+1;
				return a;
		}

					if(sitrep.thing[atr][atc-1].what==unit&&sitrep.thing[atr][atc-1].tla!=tla){
        a.action=attack;
				a.ar=atr;
				a.ac=atc-1;
				return a;
		}

					if(sitrep.thing[atr][atc].what==unit&&sitrep.thing[atr][atc].tla!=tla){
        a.action=attack;
				a.ar=atr;
				a.ac=atc;
				return a;
		}

					if(sitrep.thing[atr][atc+1].what==unit&&sitrep.thing[atr][atc+1].tla!=tla){
        a.action=attack;
				a.ar=atr;
				a.ac=atc+1;
				return a;
		}

					if(sitrep.thing[atr+1][atc-1].what==unit&&sitrep.thing[atr+1][atc-1].tla!=tla){
        a.action=attack;
				a.ar=atr+1;
				a.ac=atc-1;
				return a;
		}

					if(sitrep.thing[atr+1][atc].what==unit&&sitrep.thing[atr+1][atc].tla!=tla){
        a.action=attack;
				a.ar=atr+1;
				a.ac=atc;
				return a;
		}

					if(sitrep.thing[atr+1][atc+1].what==unit&&sitrep.thing[atr+1][atc+1].tla!=tla){
        a.action=attack;
				a.ar=atr+1;
				a.ac=atc+1;
				return a;
		}

		}

    }else{      //else rank is not archer, attack in front of you
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
    }
	if(rank==crown){        //stay back, crown!
        Location loc;
        loc.r=sitrep.nearestEnemy.r;
        loc.c=sitrep.nearestEnemy.c;
        if(loc.r-r<3&&loc.r-r>0&&dir!=up){ a.action=turn; a.dir=up; return a ; }      //if enemy is below, turn up
        if(r-loc.r<3&&r-loc.r>0&&dir!=dn){ a.action=turn; a.dir=dn; return a ;  }      //if enemy is above, turn down
        if(loc.c-c<3&&loc.c-c>0&&dir!=lt) { a.action=turn; a.dir=lt; return a ; }      //if enemy is to right, turn left
        if(c-loc.c<3&&c-loc.c>0&&dir!=rt){   a.action=turn; a.dir=rt; return a ; }      //if enemy is to left, turn right
        if(loc.r-r<3&&loc.r-r>0&&dir==up){ a.action=fwd; a.maxDist=2; return a ; }      //if enemy is below, run up
        if(r-loc.r<3&&r-loc.r>0&&dir==dn){  a.action=fwd; a.maxDist=2; return a ;   }     //if enemy is above, run down
        if(loc.c-c<3&&loc.c-c>0&&dir==lt){   a.action=fwd; a.maxDist=2; return a ;  }     //if enemy is to right, run left
        if(c-loc.c<3&&c-loc.c>0&&dir==rt){  a.action=fwd; a.maxDist=2; return a ;   }     //if enemy is to left, run right



	}
    if(rank!=crown){
        if(abs(crloc.r-r)<2&&abs(crloc.c-c)<2){a.action=nothing; return a;} //stay where you are if you are close to crown
    }


	if(dir==sitrep.nearestEnemy.dirFor&&rank!=crown){       //everyone else move forward
		a.action=fwd;
		a.maxDist=1;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;



}
