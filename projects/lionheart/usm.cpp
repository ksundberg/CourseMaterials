#include "usm.h"
#include <cmath>
#include <iostream>


void usm::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	while(!done){
        while(minR>0&&maxR<ROWS&&minC>0&&maxC<COLS){
            if(maxR>ROWS/2){
                if(maxC>COLS/2){      //this case is for the lower half of the board and right hand side
                    //of the board
                    while(sitrep.thing[tr][tc].what==space)
                        if(rank==infantry){
                            tr=minR;
                            tc=minC;
                        }else if(rank==archer){
                            tr=minR+2;
                            tc=minC+2;
                        }else if(rank==knight){
                            tr=minR+3;
                            tc=minC+3;
                        }else{
                            tr=minR+4;
                            tc=minC+4;
                        }}else{              //lower half left side
                            while(sitrep.thing[tr][tc].what==space)
                                if(rank==infantry){
                                    tr=minR;
                                    tc=maxC;
                                }else if(rank==archer){
                                    tr=minR+2;
                                    tc=maxC-2;
                                }else if(rank==knight){
                                    tr=minR+3;
                                    tc=maxC-3;
                                }else{
                                    tr=minR+4;
                                    tc=maxC-4;
                                }}}else if(maxR<ROWS/2){
                                    if(maxC>COLS/2){        //upper right corner
                                        if(rank==infantry){
                                            tr=maxR;
                                            tc=minC;
                                        }else if(rank==archer){
                                            tr=maxR+2;
                                            tc=minC+2;
                                        }else if(rank==knight){
                                            tr=maxR+3;
                                            tc=minC+3;
                                        }else{
                                            tr=maxR+4;
                                            tc=minC+4;
                                        }}else{                  // upper left corner
                                            if(rank==infantry){
                                                tr=maxR;
                                                tc=maxC;
                                            }else if(rank==archer){
                                                tr=maxR-2;
                                                tc=maxC-2;
                                            }else if(rank==knight){
                                                tr=maxR-3;
                                                tc=maxC-3;
                                            }else{
                                                tr=maxR-4;
                                                tc=maxC-4;
                                            }}}}}}



// tell someone what you want to do
Action usm::Recommendation(SitRep sitrep){
	// first, try to attack in front of you
    Action a;
    int tr=r;
    int tc=c;
    {switch(dir){
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: exit(42); break;
    }}
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){     //am I on the board?
        if(sitrep.thing[tr][tc].what==unit){        //is the thing in front of me a unit?
            while(sitrep.thing[tr][tc].tla!=tla){   //is that unit mine?
                a.action=attack;        //no? attack it.
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }else if(dir!=sitrep.nearestEnemy.dirFor){
            a.action = turn;        // makes sure there is a space and turned towards enemy
            dir=sitrep.nearestEnemyCrown.dirFor;
            return a;
        }else if(sitrep.thing[tr][tc].what==space&&dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
    }
    a.action = turn;
    switch(dir){
        case up: a.dir=dn; break;
        case dn: a.dir=up; break;
        case rt: a.dir=lt; break;
        case lt: a.dir=rt; break;
        case none: exit(42); break;
    }
    return a;
    
	
}