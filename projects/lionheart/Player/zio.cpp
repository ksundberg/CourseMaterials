#include "zio.h"
#include <cmath>
#include <iostream>


void zio::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist<0)td=up;
		else td=dn;
	}

	if(rank==crown){
		switch(dir){
		case up: if(tr!=maxR) done=false; break;
		case dn: if(tr!=minR) done=false; break;
		case rt: if(tc!=minC) done=false; break;
		case lt: if(tc!=maxC) done=false; break;
		case none: break;
		}

		while(!done){
			int cc;
			int tempR=tr,
				tempC=tc;
			switch(td){
			case up: 
				for(cc=minC;cc<maxC;++cc){
					tempR=maxR;
					tempC++;
					if(tempC>maxC)tempC=minC;
					if(sitrep.thing[tempR][tempC].what==space){
						tc=tempC; tr=tempR; break;
					}
				} 
				break;

			case dn:
				for(cc=minC;cc<maxC;++cc){
					tempR=minR;
					tempC++;
					if(tempC>maxC)tempC=minC;
					if(sitrep.thing[tempR][tempC].what==space){
						tc=tempC; tr=tempR; break;
					}
				}
				break;

			case rt:
				for(cc=minR;cc<maxR;++cc){
					tempC=minC;
					tempR++;
					if(tempR>maxR)tempR=minR;
					if(sitrep.thing[tempR][tempC].what==space){
						tr=tempR; tc=tempC; break;
					}
				}
				break;

			case lt:
				for(cc=minR;cc<maxR;++cc){
					tempC=maxC;
					tempR++;
					if(tempR>maxR)tempR=minR;
					if(sitrep.thing[tempR][tempC].what==space){
						tr=tempR; tc=tempC; break;
					}
				}
				break;
			case none: break;
			}

			done=true;

		}
	}
	r=tr;
	c=tc;
	dir=td;
}


// tell someone what you want to do
Action zio::Recommendation(SitRep sitrep){
	
	//Action that will be returned
	Action a; 

	//What target the row and column
	int tr=r,tc=c;
	
//What the king shall do this turn
	if(rank==crown){						
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
			a.action=turn;
			switch(sitrep.nearestEnemy.dirFor){
			case up: 
				if(sitrep.thing[r-1][c].what==space){
					a.dir=dn; break;
				}
				if(sitrep.thing[r][c-1].what==space){
					a.dir=lt; break;
				}
				if(sitrep.thing[r][c+1].what==space){
					a.dir=rt; break;
				}
				else{a.dir=sitrep.nearestEnemy.dirFor; break;}

			case dn:
				if(sitrep.thing[r+1][c].what==space){
					a.dir=up; break;
				}
				if(sitrep.thing[r][c-1].what==space){
					a.dir=lt; break;
				}
				if(sitrep.thing[r][c+1].what==space){
					a.dir=rt; break;
				}
				else{a.dir=sitrep.nearestEnemy.dirFor; break;}

			case rt:
				if(sitrep.thing[r][c-1].what==space){
					a.dir=lt; break;
				}
				if(sitrep.thing[r-1][c].what==space){
					a.dir=dn; break;
				}
				if(sitrep.thing[r+1][c].what==space){
					a.dir=up; break;
				}
				else{a.dir=sitrep.nearestEnemy.dirFor; break;}

			case lt:
				if(sitrep.thing[r][c+1].what==space){
					a.dir=lt; break;
				}
				if(sitrep.thing[r-1][c].what==space){
					a.dir=dn; break;
				}
				if(sitrep.thing[r+1][c].what==space){
					a.dir=up; break;
				}
				else{a.dir=sitrep.nearestEnemy.dirFor; break;}

			case none: a.dir=none; break;
			}
			return a;

		} else if (sitrep.thing[tr][tc].what==unit||
				   sitrep.thing[tr][tc].what==rock||
				   tr<=0||tr>ROWS||tc<=0||tc>COLS){
			a.action=turn;
			int direction;
			direction=rand()%4;
			if(direction==0)a.dir=up;
			if(direction==1)a.dir=dn;
			if(direction==2)a.dir=rt;
			if(direction==3)a.dir=lt;
			return a;
		} else {
			a.action=fwd;
			a.maxDist=HORSESPEED;
			return a;
		}
	} 
	
//What the knights will do
	else if (rank==knight){	
		if(hp!=1){
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
		} else {
			if(dir==sitrep.nearestEnemy.dirFor){
				a.action=turn;
				switch (sitrep.nearestEnemy.dirFor)
				{
				case up: a.dir=dn; break;
				case dn: a.dir=up; break;
				case rt: a.dir=lt; break;
				case lt: a.dir=rt; break;
				case none: break;
				}
			}
		}


		if(rand()%2){
			if(dir==sitrep.nearestEnemy.dirFor){
				a.action=fwd;
				a.maxDist=HORSESPEED;
			return a;
			} else {
				a.action=turn;
				a.dir=sitrep.nearestEnemy.dirFor;
				return a;
			}
		} else {
			if(dir==sitrep.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=HORSESPEED;
			return a;
			} else {
				a.action=turn;
				a.dir=sitrep.nearestEnemyCrown.dirFor;
				return a;
			} 
		}
	}
		
//What the archers will do
	else if(rank==archer){		
		for(int counter=1;counter<10;++counter){
			switch(dir){
			case up: 
				if(counter>=1&&counter<4){
					tr--;
				} else if(counter>=4&&counter<7){
					if(counter==4){tc--;tr+=3;}
					tr--;
				} else {
					if(counter==7){tc+=2;tr+=3;}
					tr--;
				} break;
			case dn: 
				if(counter>=1&&counter<4){
					tr++;
				} else if(counter>=4&&counter<7){
					if(counter==4){tc++;tr-=3;}
					tr++;
				} else {
					if(counter==7){tc-=2;tr-=3;}
					tr++;
				} break;
			case rt: 
				if(counter>=1&&counter<4){
					tc++;
				} else if(counter>=4&&counter<7){
					if(counter==4){tc-=3;tr--;}
					tc++;
				} else {
					if(counter==7){tc-=3;tr+=2;}
					tc++;
				} break;
			case lt: 
				if(counter>=1&&counter<4){
					tc--;
				} else if(counter>=4&&counter<7){
					if(counter==4){tc+=3;tr--;}
					tc--;
				} else {
					if(counter==7){tc+=3;tr+=2;}
				} break;
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

		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
	} 
	
//What the infantry will do
	else if(rank==infantry){				
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
			a.maxDist=1;
			a.maxDist=HORSESPEED;
			return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
	}
	a.action=nothing;
	return a;
}
