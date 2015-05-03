#include "kfc.h"
#include <cmath>
#include <iostream>


void kfc::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	/*bool done=false;
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
		if(rdist>0)td=up;
		else td=dn;
	}
	r=tr;
	c=tc;
	dir=td;*/
	int nextrow=0;
	int nextcol=0;
	int tempr, tempc;
	bool canplace=false;
	

	
		/*while(rank==crown&&canplace==false){
			tempr=(minR+maxR)/2;
			tempc=minC;
				if(sitrep.thing[tempr][tempc].what==space){
					canplace=true;
				}
		}*/
	
		
		while(canplace==false){
			
			tempr=minR+nextrow;
			tempc=minC+nextcol;
				if(sitrep.thing[tempr][tempc].what==space){
					canplace=true;
				}
				nextrow++;
				if(minR+nextrow==maxR){
					nextcol=1;
					nextrow=0;
				}
		}
			

		
		nextrow=0;
		nextcol=0;

		/*while(rank==archer&&canplace==false){
			tempr=minR+nextspot;
			tempc=minC+2;
				if(sitrep.thing[tempr][tempc].what==space){
					canplace=true;
				}
				nextspot++;
		}
		nextspot=0;
		while(rank==infantry&&canplace==false){
			tempr=minR+nextspot;
			tempc=minC+3;
				if(sitrep.thing[tempr][tempc].what==space){
					canplace=true;
				}
		}*/
		
		r=tempr;
		c=tempc;
}


// tell someone what you want to do
Action kfc::Recommendation(SitRep sitrep){
	
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
	if(rank!=archer){
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

	int tr1=r,tr2=r,tr3=r,tr4=r,tr5=r,tr6=r,tr7=r,tr8=r,tr9=r,tc1=c,tc2=c,tc3=c,tc4=c,tc5=c,tc6=c,tc7=c,tc8=c,tc9=c;
	switch(dir){
	case up:
		tr1--;
		tr2--;
		tr3--;
		tr4-2;
		tr5-2;
		tr6-2;
		tr7-3;
		tr8-3;
		tr9-3;
		tc1--;
		tc3++;
		tc4--;
		tc6++;
		tc7--;
		tc9++;
		break;
	case dn:
		tr1++;
		tr2++;
		tr3++;
		tr4+2;
		tr5+2;
		tr6+2;
		tr7+3;
		tr8+3;
		tr9+3;
		tc1++;
		tc3--;
		tc4++;
		tc6--;
		tc7++;
		tc9--;
		break;
	case rt:
		tr1--;
		tr3++;
		tr4--;
		tr6++;
		tr7--;
		tr9++;
		tc1++;
		tc2++;
		tc3++;
		tc4+2;
		tc5+2;
		tc6+2;
		tc7+3;
		tc8+3;
		tc9+3;
		break;
	case lt:
		tr1++;
		tr3--;
		tr4++;
		tr6--;
		tr7++;
		tr9--;
		tc1--;
		tc2--;
		tc3--;
		tc4-2;
		tc5-2;
		tc6-2;
		tc7-3;
		tc8-3;
		tc9-3;
		break;
	case none: break;
	}

	if(rank==archer){
		if(tr1>=0&&tr1<ROWS&&tc1>=0&&tc1<COLS){
		if(sitrep.thing[tr1][tc1].what==unit){
			if(sitrep.thing[tr1][tc1].tla!=tla){
				a.action=attack;
				a.ar=tr1;
				a.ac=tc1;
				return a;
			}
		}
	}
		if(tr2>=0&&tr2<ROWS&&tc2>=0&&tc2<COLS){
		if(sitrep.thing[tr2][tc2].what==unit){
			if(sitrep.thing[tr2][tc2].tla!=tla){
				a.action=attack;
				a.ar=tr2;
				a.ac=tc2;
				return a;
			}
		}
	}
		if(tr3>=0&&tr3<ROWS&&tc3>=0&&tc3<COLS){
		if(sitrep.thing[tr3][tc3].what==unit){
			if(sitrep.thing[tr3][tc3].tla!=tla){
				a.action=attack;
				a.ar=tr3;
				a.ac=tc3;
				return a;
			}
		}
	}
		if(tr4>=0&&tr4<ROWS&&tc4>=0&&tc4<COLS){
		if(sitrep.thing[tr4][tc4].what==unit){
			if(sitrep.thing[tr4][tc4].tla!=tla){
				a.action=attack;
				a.ar=tr4;
				a.ac=tc4;
				return a;
			}
		}
	}
		if(tr5>=0&&tr5<ROWS&&tc5>=0&&tc5<COLS){
		if(sitrep.thing[tr5][tc5].what==unit){
			if(sitrep.thing[tr5][tc5].tla!=tla){
				a.action=attack;
				a.ar=tr5;
				a.ac=tc5;
				return a;
			}
		}
	}
		if(tr6>=0&&tr6<ROWS&&tc6>=0&&tc6<COLS){
		if(sitrep.thing[tr6][tc6].what==unit){
			if(sitrep.thing[tr6][tc6].tla!=tla){
				a.action=attack;
				a.ar=tr6;
				a.ac=tc6;
				return a;
			}
		}
	}
		if(tr7>=0&&tr7<ROWS&&tc7>=0&&tc7<COLS){
		if(sitrep.thing[tr7][tc7].what==unit){
			if(sitrep.thing[tr7][tc7].tla!=tla){
				a.action=attack;
				a.ar=tr7;
				a.ac=tc7;
				return a;
			}
		}
	}
		if(tr8>=0&&tr8<ROWS&&tc8>=0&&tc8<COLS){
		if(sitrep.thing[tr8][tc8].what==unit){
			if(sitrep.thing[tr8][tc8].tla!=tla){
				a.action=attack;
				a.ar=tr8;
				a.ac=tc8;
				return a;
			}
		}
	}
		if(tr9>=0&&tr9<ROWS&&tc9>=0&&tc9<COLS){
		if(sitrep.thing[tr9][tc9].what==unit){
			if(sitrep.thing[tr9][tc9].tla!=tla){
				a.action=attack;
				a.ar=tr9;
				a.ac=tc9;
				return a;
			}
		}
	}


	}
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(rank==crown){
		if(dir==sitrep.nearestEnemy.dirFor){
			a.action=turn;
			a.dir=sitrep.anyOpenSpace;
			
			return a;
		}else if(dir!=sitrep.anyOpenSpace){
			a.action=turn;
			a.dir=sitrep.anyOpenSpace;
			return a;
		}else {
			a.action=fwd;
			a.maxDist=HORSESPEED;
			return a;
		}
	}
	
	if(rank==knight){
		if(sitrep.thing[tr][tc].what==unit||sitrep.thing[tr][tc].what==rock){
		
			a.action=turn;
			a.dir=sitrep.nearestEnemyCrown.dirFor;
			return a;

		}else{
			a.action=fwd;
			a.maxDist=HORSESPEED;
			return a;
		
		} 
		
	}
	/*
	if(rank=archer){
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
	}*/
		
	if(rank==infantry){
	/*if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
			return a;
		} else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}*/
		if(sitrep.thing[tr][tc].what==unit||sitrep.thing[tr][tc].what==rock){
		
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;

		}else{
			a.action=fwd;
			a.maxDist=1;
			return a;
		
		} 
	}
		//a.action=nothing;
		//return a;
	

	
		else if(dir==sitrep.nearestEnemy.dirFor){
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
