#include "dnd.h"
#include <cmath>
#include <iostream>


void dnd::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr=0,tc=0;
	static int times;
	Dir td;
		if((((maxC-minC)/2)+minC)<=(COLS/2)){//ON LEFT SIDE
			if(times==0){
				tr=(((maxR-minR)/2)+minR);
				tc=minC;
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else tr++;
				}
			}
			else if(times>=1&&times<=3){
				tr=maxR;
				tc=maxC-minC;
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else tc--;
				}
			}
			else if(times>=4&&times<=6){
				tr=minR;
				tc=maxC-minC;
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else tc--;
				}
			}
			else if(times>=7&&times<=14){
				tc=maxC-minC-2;
				tr=(((maxR-minR)/2)+minR);
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else {
						if(times%2==0)tr--;
						else tr++;
					}
				}
			}
			else if(times>=15&&times<=22){
				tc=maxC-minC;
				tr=(((maxR-minR)/2)+minR);
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else {
						if(times%2==0)tr--;
						else tr++;
					}
				}
			}
			else if(times>=23&&times<=30){
				tc=maxC-minC-1;
				tr=(((maxR-minR)/2)+minR);
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else {
						if(times%2==0)tr--;
						else tr++;
					}
				}
			}
		}//Left
		else{
			if(times==0){
				tr=(((maxR-minR)/2)+minR);
				tc=maxC;
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else tc--;
				}
			}
			else if(times>=1&&times<=3){
				tr=maxR;
				tc=minC;
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else tc++;
				}
			}
			else if(times>=4&&times<=6){
				tr=minR;
				tc=minC;
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else tc++;
				}
			}
			else if(times>=7&&times<=14){
				tc=minC+2;
				tr=(((maxR-minR)/2)+minR);
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else {
						if(times%2==0)tr--;
						else tr++;
					}
				}
			}
			else if(times>=15&&times<=22){
				tc=minC;
				tr=(((maxR-minR)/2)+minR);
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else {
						if(times%2==0)tr--;
						else tr++;
					}
				}
			}
			else if(times>=23&&times<=30){
				tc=minC+1;
				tr=(((maxR-minR)/2)+minR);
				while(!done){
					if(sitrep.thing[tr][tc].what==space)done=true;
					else {
						if(times%2==0)tr--;
						else tr++;
					}
				}
			}
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
	times++;
	//cout<<times;


}


// tell someone what you want to do - 9:06 - FINiSHED
Action dnd::Recommendation(SitRep sitrep){
	
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

	if(rank==archer){//**WHAT TO DO IF ARCHER
		switch(dir){//LOOK IN DIRECTION, CHECK IF VALID TARGET IS PRESENT
		case up:
			{
				int i=tr-2;
				while(i!=tr+1){
					int k=tc-1;
					while(k!=tc+2){
						if(sitrep.thing[i][k].what==unit){
							if(sitrep.thing[i][k].tla!=tla){
								a.action=attack;
								a.ar=i;
								a.ac=k;
								return a;
							}
						}
						k++;
					}
					i++;
				}
			}
			break;
		break;
		case dn:
			{
				int i=tr;
				while(i!=tr+3){
					int k=tc-1;
					while(k!=tc+2){
						if(sitrep.thing[i][k].what==unit){
							if(sitrep.thing[i][k].tla!=tla){
								a.action=attack;
								a.ar=i;
								a.ac=k;
								return a;
							}
						}
						k++;
					}
					i++;
				}
			}
			break;
		case rt:
			{
				int i=tr-1;
				while(i!=tr+2){
					int k=tc;
					while(k!=tc+3){
						if(sitrep.thing[i][k].what==unit){
							if(sitrep.thing[i][k].tla!=tla){
								a.action=attack;
								a.ar=i;
								a.ac=k;
								return a;
							}
						}
						k++;
					}
					i++;
				}
			}
			break;
		case lt:
			{
				int i=tr-1;
				while(i!=tr+2){
					int k=tc-2;
					while(k!=tc+1){
						if(sitrep.thing[i][k].what==unit){
							if(sitrep.thing[i][k].tla!=tla){
								a.action=attack;
								a.ar=i;
								a.ac=k;
								return a;
							}
						}
						k++;
					}
					i++;
				}
			}
			break;
		}
		if(dir==sitrep.nearestEnemy.dirFor){//IF NO TARGET, IF LOOKING TOWARDS NEAREST ENEMY, MOVE TO NEAREST ENEMY
			a.action=fwd;
			a.maxDist=1;
			return a;
		}
		else {//ELSE LOOK FOR NEAREST ENEMY
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
		}
	}
	if(rank==knight){//WHAT TO DO IF KNIGHT
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){//iF ENEMY IN FRONT, ATTACK
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
		if(dir==sitrep.nearestEnemyCrown.dirFor){//IF DIRECTION IS TOWARDS KING
			a.action=fwd;
			switch(dir){
			case up://IF KNIGHT IS LOOKING UP OR DOWN:
			case dn:
				if(abs(sitrep.nearestEnemyCrown.r-r)>=HORSESPEED) a.maxDist=HORSESPEED;//IS THE DISTANCE (ROWS) TO THE TARGET SQUARE FARTHER THAN THE KNIGHT CAN MOVE? IF YES, MOVE AT MAX SPEED
				else a.maxDist=abs(sitrep.nearestEnemyCrown.r-r);//IF NO, MOVE NUMBER OF UNITS TO GET TO TARGET SQUARE
				break;
			case rt://LEFT OR RIGHT
			case lt:
				if(abs(sitrep.nearestEnemyCrown.c-c)>=HORSESPEED) a.maxDist=HORSESPEED;//SEE ABOVE, WITH COLUMNS
				else 	a.maxDist=abs(sitrep.nearestEnemyCrown.c-c);
				break;
			case none: break;
			}
			return a;
		} else {//ELSE LOOK FOR PATH TO KING
			a.action=turn;
			a.dir=sitrep.nearestEnemyCrown.dirFor;
			return a;
		}
	}
	if(rank==crown){//**WHAT DO TO DO IF KING
		Dir opDir;
		switch(dir){
		case up: opDir=dn; break;
		case dn: opDir=up; break;
		case rt: opDir=lt; break;
		case lt: opDir=rt; break;
		case none: break;
		}
		if(opDir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=HORSESPEED;
			return a;
		}
		else{
			opDir=sitrep.nearestEnemy.dirFor;
			switch(opDir){
			case up: opDir=dn; break;
			case dn: opDir=up; break;
			case rt: opDir=lt; break;
			case lt: opDir=rt; break;
			case none: break;
			}
			a.action=turn;
			a.dir=opDir;
			return a;
		}
	}
		/*
		*/
	else{
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){//IF ENEMY IN FRONT
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
