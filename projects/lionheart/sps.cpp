#include "sps.h"
#include <cmath>
#include <iostream>


void sps::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false; //Is the space open?
	int tr,tc; //Coordinates
	Dir td; ;//Dir (direction) = an enum, specifies where the units should go (up, down, etc.),  td=current direction?
	int radius=1;



	


   while(!done){
		 tr=minR+rand()%(maxR-minR);	//This makes the players go into random spaces
		tc=minC+rand()%(maxC-minC);

		if(sitrep.thing[tr][tc].what==space)done=true;
   }
   if (rank==crown){

tr=minR+10;
tc=minC;

   }
   int rdist=ROWS/2-tr; //The distance from the center (Because of Rows/2) then subtract coordinants 
	int cdist=COLS/2-tc;  //The distance from the center (Because Rows/2) then subtract coordinants 
	if(abs(rdist)<abs(cdist)){   //dist=how far to go; the abs=absolute value, thus making what ever distance is inputed positve
		if(cdist>0)td=rt;    //...if the distance (column wise) is greater than zero (the end of the game board), then current direction is right 
		else td=lt;   //...Otherwise go left 
	}else{
		if(rdist>0)td=up;  //...if the distance (row wise) is greater than zero (bottom end of the game board), then current direction is up
		else td=dn;       //...Otherwise go down
	}
	r=tr;    //tr=current row
	c=tc;    //tc=current column
	dir=td;  //td=current direction
}





		//---------------------------------------------------------------------------------------------------------------------------------------

Action sps::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	
	if (rank==crown){	
	
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
		a.action=nothing;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.anyOpenSpace;
		return a;
	}
	a.action=nothing;
	return a;
	
}
	//----------------------------------------------------------------------------------------------------------------

	if (rank==knight){	
	
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
	
	
	
	if(dir==sitrep.anyOpenSpace){
		a.action=fwd;
		a.maxDist=1;
		return a;
		
		a.action=fwd;
		return a;
		
	} else {
		a.action=turn;
		a.dir=sitrep.anyOpenSpace;
		return a;

		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
}

	//------------------------------------------------------------------------------------------------------------------
if (rank==archer){	
	
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
		a.action=nothing;
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
	
	
	

//-------------------------------------------------------------------------------------------------------------------------------------
if (rank==infantry){
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
	
	if(dir==sitrep.nearestEnemyCrown.dirFor){
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
}




	
	// this code is provided as an example only
	// use at your own risk
	// first, try to attack in front of you
	//int tr=r,tc=c;
	//switch(dir){
	//case up: tr--; break;
	//case dn: tr++; break;
	//case rt: tc++; break;
	//case lt: tc--; break;
	//case none: break;
	//}
	//if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
	//	if(sitrep.thing[tr][tc].what==unit){
	//		if(sitrep.thing[tr][tc].tla!=tla){
	//			a.action=attack;
	//			a.ar=tr;
	//			a.ac=tc;
	//			return a;
	//		}
	//	}
	//}	
	//// there is not an enemy in front of me
	//// so head to the nearest enemy
	//if(dir==sitrep.nearestEnemy.dirFor){
	//	a.action=fwd;
	//	a.maxDist=1;
	//	if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
	//	return a;
	//} else {
	//	a.action=turn;
	//	a.dir=sitrep.nearestEnemy.dirFor;
	//	return a;
	//}
	//a.action=nothing;
	//return a;
	//