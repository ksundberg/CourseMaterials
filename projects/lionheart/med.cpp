#include "med.h"
#include <cmath>
#include <iostream>


void med::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc,i,j;
	Dir td;
	static int num=1;
	if (maxR<(ROWS/2)){						//if i am on the top of the screen
		td=dn;
		switch(num){
		case 1: tr=minR;tc=(minC+maxC)/2;break;
		case 2:	
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
					tr=(minR+3);
					for(i=(maxC+minC)/2+3;i>=minC;--i){
						tc=i;
						if(sitrep.thing[tr][tc].what==space) break;
					}
					break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
					tr=minR+2;
					for(i=(maxC+minC)/2+4;i>=minC;--i){
						tc=i;
						if(sitrep.thing[tr][tc].what==space) break;
					}
					break;
		default:		for (i=minR;i<=minR+1;++i){
						tr=i;
						for (j=(maxC+minC)/2+4;j>=(maxC+minC)/2-3;--j){
							tc=j;
							if(sitrep.thing[tr][tc].what==space) break;
						}
						if(sitrep.thing[tr][tc].what==space) break;
					}
		}
		num=num+1;
	}


	if (minR>(ROWS/2)){						//if i am on the bottom of the screen
		td=up;
		switch(num){
		case 1: tr=maxR;tc=(minC+maxC)/2;break;
		case 2:		
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
					tr=(maxR-3);
					for(i=(maxC+minC)/2+3;i>=minC;--i){
						tc=i;
						if(sitrep.thing[tr][tc].what==space) break;
					}
					break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
					tr=maxR-2;
					for(i=(maxC+minC)/2+4;i>=minC;--i){
						tc=i;
						if(sitrep.thing[tr][tc].what==space) break;
					}
					break;
		default:	for (i=maxR;i>=maxR-1;--i){
						tr=i;
						for (j=(maxC+minC)/2+4;j>=(maxC+minC)/2-3;--j){
							tc=j;
							if(sitrep.thing[tr][tc].what==space) break;
						}
					if(sitrep.thing[tr][tc].what==space) break;
					} 
		}
		num=num+1;
	}
	if (maxC<(COLS/2)){						//if i am on the left of the screen
		td=rt;
		switch(num){
		case 1: tc=minC;tr=(minR+maxR)/2;break;
		case 2:	
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
					tc=(minC+3);
					for(i=(maxR+minR)/2+3;i>=minR;--i){
						tr=i;
						if(sitrep.thing[tr][tc].what==space) break;
					}
					break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
					tc=minC+2;
					for(i=(maxR+minR)/2+4;i>=minR;--i){
						tr=i;
						if(sitrep.thing[tr][tc].what==space) break;
					}
					break;
		default:		for (i=minC;i<=minC+1;++i){
						tc=i;
						for (j=(maxR+minR)/2+4;j>=(maxR+minR)/2-3;--j){
							tr=j;
							if(sitrep.thing[tr][tc].what==space) break;
						}
						if(sitrep.thing[tr][tc].what==space) break;
					}
		}
		num=num+1;
	}


	else{						//if i am not on the top, left or bottom of the screen
		td=lt;
		switch(num){
		case 1: tc=maxC;tr=(minR+maxR)/2;break;
		case 2:		
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
					tc=(maxC-3);
					for(i=(maxR+minR)/2+3;i>=minR;--i){
						tr=i;
						if(sitrep.thing[tr][tc].what==space) break;
					}
					break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
					tc=maxC-2;
					for(i=(maxR+minR)/2+4;i>=minR;--i){
						tr=i;
						if(sitrep.thing[tr][tc].what==space) break;
					}
					break;
		default:	for (i=maxC;i>=maxC-1;--i){
						tc=i;
						for (j=(maxR+minR)/2+4;j>=(maxR+minR)/2-3;--j){
							tr=j;
							if(sitrep.thing[tr][tc].what==space) break;
						}
					if(sitrep.thing[tr][tc].what==space) break;
					} 
		}
		num=num+1;
	}

	r=tr;
	c=tc;
	dir=td;
}


// tell someone what you want to do
Action med::Recommendation(SitRep sitrep){
	static int turns=0;	
	Action a;
	int tr, tc, i, j;
	tr=r;
	tc=c;
	++turns;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case lt: tr--; break;
	case rt: tr++; break;
	case none: exit(42); break;
	}
											//what king does
if(rank==crown){				
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
					a.maxDist=1;
					a.dir=dir;
					a.ar=tr;
					a.ac=tc;
				return a;
			}
		}
	}	 
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
}
											//what archer does
else if (rank==archer){
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		int i, j;
		for(i=tr-1; i<=tr+1; i++){
			for(j=tc-1; j<=tc+1; j++){
				if(sitrep.thing[i][j].what==unit){
					if(sitrep.thing[i][j].tla!=tla){
						a.action=attack;
						a.ar=i;
						a.ac=j;
						return a;
					}
				}
			}
		}
	}
	if(turns>900&&dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		return a;
	} 
	else{
		if(turns>800){
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
	}
	a.action=nothing;
	return a;
	
}
											//what knight and infantry does
else{
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
	
	if(turns>900&&dir==sitrep.nearestEnemy.dirFor){
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
}