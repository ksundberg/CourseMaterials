#include "m11.h"
#include <cmath>
#include <iostream>


void m11::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		//enum side{left, up, right down};

		if (rank == crown){
			tr = (maxR-minR)/2+minR;
			tc = (maxC-minC)/2+minC;
		}
		else if (rank == archer){
			for(int i = -1; i <= 2; i++){
				for(int j = -3; j <= 3; j++){
					while(sitrep.thing[tr][tc].what!=space){
						tr = (maxR-minR)/2+i;
						tc = (maxC-minC)/2+j;
						if(i >= 2&& j >= 3)break;
					}
				}
			}
		}
		else if (rank == infantry){
			for(int i = -2; i <= 4; i++){
				for(int j = -5; j <= 5; j++){
					while(sitrep.thing[tr][tc].what!=space){
						tr = (maxR-minR)/2+i;
						tc = (maxC-minC)/2+j;
						if(tr > maxR || tr < minR)break;
						if(tc > maxC || tc < minC)break;
						if(i >= 4 && j >= 5)break;
					}
				}
			}
		}
		else if (rank == knight){
			tr=minR+rand()%(maxR-minR);
			tc=minC+rand()%(maxC-minC);
		}

		//tr=minR+rand()%(maxR-minR);
		//tc=minC+rand()%(maxC-minC);
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=up;
		else td=dn;
	}
	r=tr;
	c=tc;
	dir=td;
}


// tell someone what you want to do
Action m11::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
if(unit == infantry || unit == crown){
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

else if(unit == archer){
	int tr=r,tc=c;

	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		for(int i = -1; i <= 1; i++){
			for(int j = 1; j <=4; j++){
					switch(dir){
					case up:
					if(sitrep.thing[tr-j][tc+i].what==unit){
						if(sitrep.thing[tr-j][tc+i].tla!=tla){
							a.action=attack;
							a.ar=tr-j;
							a.ac=tc+i;
							return a;
						}
					}
					break;
					case dn:
						if(sitrep.thing[tr+j][tc+i].what==unit){
							if(sitrep.thing[tr+j][tc+i].tla!=tla){
								a.action=attack;
								a.ar=tr+j;
								a.ac=tc+i;
								return a;
						}
					}
					break;
					case rt:
					if(sitrep.thing[tr+i][tc+j].what==unit){
						if(sitrep.thing[tr+i][tc+j].tla!=tla){
							a.action=attack;
							a.ar=tr+i;
							a.ac=tc+j;
							return a;
						}
					}
					break;
					case lt:
					if(sitrep.thing[tr+i][tc-j].what==unit){
						if(sitrep.thing[tr+i][tc-j].tla!=tla){
							a.action=attack;
							a.ar=tr+i;
							a.ac=tc-j;
							return a;
						}
					}
					break;
					case none: break;

				}
			}
		}
	}
}

if(unit == archer || unit == crown || unit == infantry){
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
}
else if(unit == knight){
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
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=HORSESPEED;
		return a;
		}

	 else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;

}
else{
a.action = nothing;
return a;
}
	
}
