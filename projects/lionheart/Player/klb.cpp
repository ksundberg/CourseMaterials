#include "klb.h"
#include <cmath>
#include <iostream>

#include "xxx.h"

int klb::numArchers=0;
int klb::numInfantry=0;
int klb::numKnights=0;
int klb::enumArchers=0;
int klb::enumInfantry=0;
int klb::enumKnights=0;
int klb::numTurn=0;


void klb::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		if(rank==crown){
			unitNumber=10;
			tr=(minR+maxR)/2;
			tc=minC;
	int crdist=ROWS/2-tr;
	int ccdist=COLS/2-tc;
	if(abs(crdist)<abs(ccdist)&&ccdist<0)tc=maxC;

		}else if(rank==archer){
			tr=((minR+maxR)/2)-3+unitNumber;
			tc=minC+1;
	int crdist=ROWS/2-tr;
	int ccdist=COLS/2-tc;
	if(abs(crdist)<abs(ccdist)&&ccdist<0)tc=maxC-1;
	if(sitrep.thing[tr][tc].what!=space){tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		}
		}else if(rank==knight){
			tr=minR+2+unitNumber;
			tc=minC+4;
	int crdist=ROWS/2-tr;
	int ccdist=COLS/2-tc;
	if(abs(crdist)<abs(ccdist)&&ccdist<0)tc=maxC-4;
	if(sitrep.thing[tr][tc].what!=space){tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		}

		}else{

		tr=minR+rand()%(maxR-minR);	
		if(tr<=minR||tr>=maxR)tr=minR-2+rand()%(maxR-minR);
		if(tr<=minR||tr>=maxR)tr=minR+rand()%(maxR-minR);
		tc=minC+rand()%(maxC-minC);	
		}
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
	if(rank==crown)td=up;
	r=tr;
	c=tc;
	dir=td;
}



// tell someone what you want to do
Action klb::Recommendation(SitRep sitrep){
	bool crownPeril = false;
if(rank==crown){numTurn++;}
	// this code is provided as an example only
	// use at your own risk
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

	
	
	if(rank==crown){a.action=nothing; return a;}//crown does nothing for 5 turns
	if(rank==crown&&dir==none){a.action=turn; a.dir=sitrep.anyOpenSpace; return a;}
	if(rank==crown&&unitNumber<=5&&unitNumber>0&&dir==sitrep.nearestEnemy.dirFor){a.action=turn;//crown avoids enemies
		switch(dir){
	case up: a.dir=dn; break;
	case dn: a.dir=up; break;
	case rt: a.dir=lt; break;
	case lt: a.dir=rt; break;
	case none: a.dir=dn; break;
	}
		

		if(sitrep.thing[tr][tc].what==unit||sitrep.thing[tr][tc].what==rock){a.dir=sitrep.anyOpenSpace; }
		unitNumber*=-1;
	return a;
	}
	if(rank==crown&&unitNumber<0&&10<abs(sitrep.nearestEnemy.r-r)){a.action=fwd; a.maxDist=HORSESPEED; unitNumber*=-1; return a;}
	
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
	//cout<<"attacking!!! ";
				return a;
			}
		}
	}//not on the board

	//else the crown should move forward
	if(rank==crown){a.action=fwd; a.maxDist=HORSESPEED; return a;}

	if(rank==archer&&numTurn<200){
	switch(dir){
		case up: for (int i = 3; i>0; --i){
					for (int j=-1; j<2; ++j){
						tr=r-i;
						tc=c+j;
						if(sitrep.thing[tr][tc].what==unit){
							if(sitrep.thing[tr][tc].tla!=tla){
								a.action = attack;
								a.ar=tr;
								a.ac=tc;
								return a;
							}
						}
					}
				} break;
		case dn: for (int i = 3; i>0; --i){
					for (int j=-1; j<2; ++j){
						tr=r+i;
						tc=c+j;
						if(sitrep.thing[tr][tc].what==unit){
							if(sitrep.thing[tr][tc].tla!=tla){
								a.action = attack;
								a.ar=tr;
								a.ac=tc;
								return a;
							}
						}
					}
				} break;
		case rt: for (int i = 1; i>-2; --i){
					for (int j=1; j<4; ++j){
						tr=r-i;
						tc=c+j;
						if(sitrep.thing[tr][tc].what==unit){
							if(sitrep.thing[tr][tc].tla!=tla){
								a.action = attack;
								a.ar=tr;
								a.ac=tc;
								return a;
							}
						}
					}
				} break;
		case lt: for (int i = 1; i>-2; --i){
					for (int j=1; j<4; ++j){
						tr=r-i;
						tc=c-j;
						if(sitrep.thing[tr][tc].what==unit){
							if(sitrep.thing[tr][tc].tla!=tla){
								a.action = attack;
								a.ar=tr;
								a.ac=tc;
								return a;
							}
						}
					}
				} break;
		case none: a.action=nothing; return a; break;
		}
		if(!crownPeril){
			a.action=nothing;
			return a;
		}else{
			if(dir==sitrep.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=1;
				return a;
			} else {
				a.action=turn;
				a.dir=sitrep.nearestEnemyCrown.dirFor;
				return a;
			}
		}}

	//the enemy is more than 10 units away
	if(rank!=crown&&10>abs(sitrep.nearestEnemy.r-r)&&unitNumber>0){
	a.action=fwd;
	a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		if(dir==up||dir==dn&&rank==knight||rank==crown&&HORSESPEED>abs(sitrep.nearestEnemy.r-r))a.maxDist=abs(sitrep.nearestEnemy.r-r);
		unitNumber*=-1;
		//cout<<unitNumber<<" is advancing! ";
		return a;
	}

	

	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemyCrown.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		if(dir==up||dir==dn&&rank==knight||rank==crown&&HORSESPEED>abs(sitrep.nearestEnemy.r-r))a.maxDist=abs(sitrep.nearestEnemy.r-r);
		cout<<unitNumber<<" is going to attack their crown! ";
		return a;
	} else if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		if(dir==up||dir==dn&&rank==knight||rank==crown&&HORSESPEED>abs(sitrep.nearestEnemy.r-r))a.maxDist=abs(sitrep.nearestEnemy.r-r);
		//cout<<unitNumber<<" is going to attack that unit! ";
		return a;
	}else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
}
