#include "dss.h"
#include <cmath>
#include <iostream>


void dss::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+        rand()%(maxC-minC);	
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
Action dss::Recommendation(SitRep sitrep){
	
	Action a; 
	int arr,arc;
	int tr=r,tc=c;
	switch(dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: break;
	}



	if(rank==crown){
		a.action=nothing;
		return a;
	}



	if(rank==archer){
		if(sitrep.thing[r][c].dir==up){
			for(arr=r-3;arr<3;arr++){
				for(arc=c-1;arc<3;arc++){
					if(sitrep.thing[arr][arc].what==unit){
						if(sitrep.thing[arr][arc].tla!=tla){
							a.action=attack;
							a.ar=arr;
							a.ac=arc;
							return a;
						}
						else if(dir==sitrep.nearestEnemyCrown.dirFor){
							a.action=fwd;
							a.maxDist=1;
							return a;
						}
						else{
							a.action=turn;
							a.dir=sitrep.nearestEnemyCrown.dirFor;
							return a;
						}
					}
				}
			}
		}
		if(sitrep.thing[r][c].dir==dn){
			for(arr=r+1;arr<3;arr++){
				for(arc=c-1;arc<3;arc++){
					if(sitrep.thing[arr][arc].what==unit){
						if(sitrep.thing[arr][arc].tla!=tla){
							a.action=attack;
							a.ar=arr;
							a.ac=arc;
							return a;
						}
						else if(dir==sitrep.nearestEnemyCrown.dirFor){
							a.action=fwd;
							a.maxDist=1;
							return a;
						}
						else{
							a.action=turn;
							a.dir=sitrep.nearestEnemyCrown.dirFor;
							return a;
						}
					}
				}
			}
		}
		if(sitrep.thing[r][c].dir==lt){
			for(arr=r-1;arr<3;arr++){
				for(arc=c-3;arc<3;arc++){
					if(sitrep.thing[arr][arc].what==unit){
						if(sitrep.thing[arr][arc].tla!=tla){
							a.action=attack;
							a.ar=arr;
							a.ac=arc;
							return a;
						}
						else if(dir==sitrep.nearestEnemyCrown.dirFor){
							a.action=fwd;
							a.maxDist=1;
							return a;
						}
						else{
							a.action=turn;
							a.dir=sitrep.nearestEnemyCrown.dirFor;
							return a;
						}
					}
				}
			}
		}
		if(sitrep.thing[r][c].dir==rt){
			for(arr=r-1;arr<3;arr++){
				for(arc=c+1;arc<3;arc++){
					if(sitrep.thing[arr][arc].what==unit){
						if(sitrep.thing[arr][arc].tla!=tla){
							a.action=attack;
							a.ar=arr;
							a.ac=arc;
							return a;
						}
						else if(dir==sitrep.nearestEnemyCrown.dirFor){
							a.action=fwd;
							a.maxDist=1;
							return a;
						}
						else{
							a.action=turn;
							a.dir=sitrep.nearestEnemyCrown.dirFor;
							return a;
						}
					}
				}
			}
		}
	}



	if(rank==infantry){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
			else if(sitrep.thing[r][c].dir==sitrep.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=1;
				return a;
			}
			else{
				a.action=turn;
				a.dir=sitrep.nearestEnemyCrown.dirFor;
				return a;
			}
		}
	}



	if(rank==knight){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
			else if(sitrep.thing[r][c].dir==sitrep.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=1;
				return a;
			}
			else{
				a.action=turn;
				a.dir=sitrep.nearestEnemyCrown.dirFor;
				return a;
			}
		}
	}

a.action=fwd;
return a;

}
//