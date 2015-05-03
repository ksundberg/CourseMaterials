#include "icl.h"
#include <cmath>
#include <iostream>


void icl::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	if (rank == crown)
	{
		if (sitrep.thing[minR][minC].what == space)
		{

			tr = minR;
			tc = minC;
			td = dn;
		}
	}
	else{
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
	dir=td;

}
}



Action icl::Recommendation(SitRep sitrep){
	
	Action a; 


	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		
		if(sitrep.thing[tr][tc].what==infantry){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				return a;
			}
		}
		if(sitrep.thing[tr][tc].what==archer){
			if(sitrep.thing[tr][tc].tla!=tla){
				if(sitrep.thing[tr][tc].what==rank && INFANTRYHP<=3 || ARCHERHP<=3 || KNIGHTHP<=3){
			a.action=turn;
			a.ar=tr;
			a.ac=tc;
			return a;
			}	
			if(sitrep.thing[tr][tc].what==rank && INFANTRYHP>3 || ARCHERHP>3 || KNIGHTHP>3)
			{
			a.action=attack;
			a.ar=tr;
			a.ac=tc;
			return a;
			}
		}
		if(sitrep.thing[tr][tc].what==crown){
			if(sitrep.thing[tr][tc].tla!=tla){
				if(sitrep.thing[tr][tc].what && INFANTRYHP>2 || ARCHERHP>2 || KNIGHTHP>2){
				a.action=turn;
				return a;
				}
		
	}	
	}
		if(sitrep.thing[tr][tc].what==knight){
			if(sitrep.thing[tr][tc].tla!=tla){
				if(sitrep.thing[tr][tc].what && INFANTRYHP>=3 || ARCHERHP>=3 || KNIGHTHP>=3){
					a.action=attack;
					return a;
				}
				if(sitrep.thing[tr][tc].what && INFANTRYHP<3 || ARCHERHP<3 || KNIGHTHP<3){
					a.action=turn;
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
		if(sitrep.nearestEnemy.dirFor<=5){
			if(rank==archer){
				a.action=attack;
				return a;
			}
			else if(sitrep.nearestEnemy.dirFor>5){
				if(rank==archer){
					a.action=fwd;
				return a;
				}
		}
			else if(sitrep.nearestEnemyCrown.dirFor<7){
				if(rank=archer, infantry, crown){
				a.action=attack;
				return a;
			}
			}
			if(sitrep.nearestEnemy.dirFor<10){
				if(rank==infantry){
					a.action=fwd;
					return a;
				}
			}
			else if(sitrep.nearestEnemy.dirFor>=10){
				if(rank==infantry){
					a.action=turn;
					return a;
			}
		}
			if(sitrep.nearestEnemy.dirFor>=10){
			if(rank==crown)
				a.action=turn;
			}
			if(sitrep.anyOpenSpace>10){
				if(rank==infantry, archer, knight){
					a.action=fwd;
					return a;
				}
				else if(rank==crown){
					a.action=nothing;
					return a;
				}
			}
			if(hp<5){
				(rank==infantry, archer, knight);
				{
					a.action=attack;
					return a;
				}
			}
			else if(hp>5){
				(rank==infantry || knight);
				{
					a.action=attack;
					return a;
				}
			}
			else(hp>5);{
				(rank==archer);{
					a.action=turn;
					return a;
				}
			}
			if(rank=knight){
				a.dir==sitrep.nearestEnemy.dirFor==(infantry+5);
	} 
		else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}
}
}
}
}