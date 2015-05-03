//Bryant Nielson
//A01770570	

#ifndef CLU_H
#define CLU_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;



class clu : public Unit {
public:
	clu():Unit(){}

	clu(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do
	
	
	// the royal guard and the decoy unit(s?)
	void setRoyal(){
		royal=false;
		if(rank==knight&&royalknit<1){
			royal=true;
			royalknit++;
			return;
		}
		else if(rank==archer&&royalknit<2){
			royal=true;
			royalarcs++;
			return;
		}
		return; 
	};
	
	void setDecoy(){
		decoy=false;
		if(decoys>=1){return;}
		if(rank==crown||rank==archer){return;}
		decoy=true;
		decoys++;
		return;
	};
	//accessors
	int getRoyalarcs(){};
	int getRoyalknits(){};
	int getDecoys(){};
	bool getRoyal(){};
	bool getDecoy(){};
	
private:
	static int royalarcs;
	static int royalknit;
	static int decoys;
	static int rdest;
	static int cdest;	
	bool royal;
	bool decoy;
};
int clu::rdest=0;
int clu::cdest=0;
int clu::royalarcs=0;
int clu::royalknit=0;
int clu::decoys=0;


void clu::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
		if(rdist>0)td=up;
		else td=dn;
	}
	r=tr;
	c=tc;
	dir=td;
}



Dir Wayto(int Rr, int Rc,int Cr,int Cc, SitRep sitrep,int &speed){
	int i,j,k;
	Dir daway[ROWS][COLS];
	int numRocks=0, numNones=0,counter=0;
	bool found;
	
	
	
	for(i=0;i<ROWS;i++){
		for(k=0;k<COLS;k++){
			daway[i][k]=none;
			if(sitrep.thing[i][k].what==rock){numRocks++;}
			if(i==ROWS)cout<<k<<endl;
		}
	}
	
	
	do{

		
		counter++;
		numNones=0;
		
		for(i=0;i<ROWS;i++){
			for(k=0;k<COLS;k++){
				//check on board, check on rocks,check for direction,check for rally point
				if(daway[i][k]!=none)continue;
					 if((sitrep.thing[i][k+1].what!=rock&&k+1<COLS&&daway[i][k+1]!=none)||(Rr==i&&Rc==k+1)){daway[i][k]=rt;}
				else if((sitrep.thing[i][k-1].what!=rock&&k-1>0   &&daway[i][k-1]!=none)||(Rr==i&&Rc==k-1)){daway[i][k]=lt;}
				else if((sitrep.thing[i+1][k].what!=rock&&i+1<ROWS&&daway[i+1][k]!=none)||(Rr==i+1&&Rc==k)){daway[i][k]=dn;}
				else if((sitrep.thing[i-1][k].what!=rock&&i-1>0   &&daway[i-1][k]!=none)||(Rr==i-1&&Rc==k)){daway[i][k]=up;}
				if(daway[i][k]==none)numNones++;
				
			}
		}
		
	}while(numNones>numRocks+1);
	
	found=false;
	for(j=1;!found;j++){
		switch(daway[Cr][Cc]){
			case up: 	if(daway[Cr][Cc]!=daway[Cr-j][Cc]){
						found=true;
						speed=j;
						}
						break;
			
			case dn: 	if(daway[Cr][Cc]!=daway[Cr+j][Cc]){
						found=true;
						speed=j;
						}
						break;
			case lt: 	if(daway[Cr][Cc]!=daway[Cr][Cc-j]){
						found=true;
						speed=j;
						}
						break;
			
			case rt: 	if(daway[Cr][Cc]!=daway[Cr][Cc+j]){
						found=true;
						speed=j;
						}
						break;
			default:	found=true;
						speed=1;
		}
	}
	if(speed>HORSESPEED)speed=5;
	return daway[Cr][Cc];
	
}

Dir CWayto(int Rr, int Rc,int Cr,int Cc, SitRep sitrep,int &speed){
	int i,j,k,w;
	Dir daway[ROWS][COLS];
	int numRocks=0, numNones=0,counter=0;
	bool found;
	
	
	
	for(i=0;i<ROWS;i++){
		for(k=0;k<COLS;k++){
			daway[i][k]=none;
			if(sitrep.thing[i][k].what==rock){numRocks++;}
			if(i==ROWS)cout<<k<<endl;
		}
	}
	
	
	do{

		
		counter++;
		numNones=0;
		
		for(i=0;i<ROWS;i++){
			for(k=0;k<COLS;k++){
				//check on board, check on rocks,check for direction,check for rally point
				if(daway[i][k]!=none)continue;
					 if((sitrep.thing[i][k+1].what==space&&k+1<COLS&&daway[i][k+1]!=none)||(Rr==i&&Rc==k+1)){daway[i][k]=rt;}
				else if((sitrep.thing[i][k-1].what==space&&k-1>0   &&daway[i][k-1]!=none)||(Rr==i&&Rc==k-1)){daway[i][k]=lt;}
				else if((sitrep.thing[i+1][k].what==space&&i+1<ROWS&&daway[i+1][k]!=none)||(Rr==i+1&&Rc==k)){daway[i][k]=dn;}
				else if((sitrep.thing[i-1][k].what==space&&i-1>0   &&daway[i-1][k]!=none)||(Rr==i-1&&Rc==k)){daway[i][k]=up;}
				if(daway[i][k]==none)numNones++;
				
			}
		}
		
		if(counter>200)break;
	}while(numNones>numRocks+1);
	
	found=false;
	for(j=1;!found;j++){
		if(daway[Cr][Cc]==none){
			found=true;
			speed=1;}
		switch(daway[Cr][Cc]){
			case up: 	if(daway[Cr][Cc]!=daway[Cr-j][Cc]){
						found=true;
						speed=j;
						}
						break;
			
			case dn: 	if(daway[Cr][Cc]!=daway[Cr+j][Cc]){
						found=true;
						speed=j;
						}
						break;
			case lt: 	if(daway[Cr][Cc]!=daway[Cr][Cc-j]){
						found=true;
						speed=j;
						}
						break;
			
			case rt: 	if(daway[Cr][Cc]!=daway[Cr][Cc+j]){
						found=true;
						speed=j;
						}
						break;
			default:	found=true;
						speed=1;
		}
	}
	return daway[Cr][Cc];
	
}

Dir Whirlwind(int r, int c, SitRep sitrep,int &speed){
	int tr,tc;

	if(r<ROWS/3&&c<COLS/3){
	tr=5*ROWS/6;
	tc=COLS/6;
	}
	if(r<ROWS/3&&(c>COLS/3&&c<2*COLS/3)){
	tr=ROWS/6;
	tc=COLS/6;
	}
	if(r<ROWS/3&&(c>2*COLS/3&&c<COLS)){
	tr=ROWS/6;
	tc=COLS/6;
	}
	if((r>ROWS/3&&r<2*ROWS/3)&&c<COLS/3){
	tr=5*ROWS/6;
	tc=COLS/6;
	}
	if((r>ROWS/3&&r<2*ROWS/3)&&(c>COLS/3&&c<2*COLS/3)){
	tr=ROWS/2;
	tc=5*COLS/6;
	}
	if((r>ROWS/3&&r<2*ROWS/3)&&(c>2*COLS/3&&c<COLS)){
	tr=ROWS/6;
	tc=5*COLS/6;
	}
	if((r>2*ROWS/3&&r<ROWS)&&c<COLS/3){
	tr=5*ROWS/6;
	tc=5*COLS/6;
	}
	if((r>2*ROWS/3&&r<ROWS)&&(c>COLS/3&&c<2*COLS/3)){
	tr=5*ROWS/6;
	tc=5*COLS/6;
	}
	if((r>2*ROWS/3&&r<ROWS)&&(c>2*COLS/3&&c<COLS)){
	tr=ROWS/6;
	tc=5*COLS/6;
	}
	
	return CWayto(tr,tc,r,c,sitrep,speed);


}


int dista(int sr,int sc,int er,int ec){

return sqrt(((sr-er)*(sr-er))+((sc-ec)*(sc-ec)));

}


// tell someone what you want to do
Action clu::Recommendation(SitRep sitrep){
	
	
	Action a; 
	int i,j,k,w;
	int speed;
	
	int enmUn=0,freUn=0;
	int CposC,CposR,ECposC,ECposR;
	bool redAlarm,ongAlarm,yelAlarm;
	int popE[9],popF[9],popEa[9],popEb[9];
	
	Dir temmp;
	int tr=r,tc=c;
	int Mtc=c,Mtr=r,mtc=c,mtr=r;
	
	

	//find the crown
	
	for(i=0;i<ROWS;i++){
		for(k=0;k<COLS;k++){
			if(sitrep.thing[i][k].rank==crown){
				if(sitrep.thing[i][k].tla==tla){
					CposC=k;
					CposR=i;
				}
				if(sitrep.thing[i][k].tla!=tla){
					ECposC=k;
					ECposR=i;
				}
			}
		}
	}
	for(i=0;i<9;i++){
	popE[i]=0;
	popF[i]=0;
	
	}
	
	//check for enemy units distance from my crown.
	//check for my pieces outnumbering my opponents
	//check for population of each square
	for(i=0;i<ROWS;i++){
		for(k=0;k<COLS;k++){
			//check if it is enemy or friendly
			if(sitrep.thing[i][k].what==unit){
				//enemy unit
				if(sitrep.thing[i][k].tla!=tla){
					enmUn++;
					//throw in the correct square
					//and in the correct array
					if(i<ROWS/3&&k<COLS/3)popE[0]++;
					if(i<ROWS/3&&(k>COLS/3&&k<2*COLS/3))popE[1]++;
					if(i<ROWS/3&&(k>2*COLS/3&&k<COLS))popE[2]++;
					if((i>ROWS/3&&i<2*ROWS/3)&&k<COLS/3)popE[3]++;
					if((i>ROWS/3&&i<2*ROWS/3)&&(k>COLS/3&&k<2*COLS/3))popE[4]++;
					if((i>ROWS/3&&i<2*ROWS/3)&&(k>2*COLS/3&&k<COLS))popE[5]++;
					if((i>2*ROWS/3&&i<ROWS)&&k<COLS/3)popE[6]++;
					if((i>2*ROWS/3&&i<ROWS)&&(k>COLS/3&&k<2*COLS/3))popE[7]++;
					if((i>2*ROWS/3&&i<ROWS)&&(k>2*COLS/3&&k<COLS))popE[8]++;
					
					//calculate distance from the crown
					//if to close ring the alarms
					if(abs(CposR-i)+abs(CposC-k)<=5){
					redAlarm=true;
					yelAlarm=false;
					}
					else if(abs(CposR-i)+abs(CposC-k)>5&&abs(CposR-i)+abs(CposC-k)<=15){
					redAlarm=false;
					yelAlarm=true;
					}
					else{
					redAlarm=false;
					yelAlarm=false;
					}
				}else{
				//friendly
				freUn++;
				}
			}else{
			//something needs to go here like defining path to it's formation
			
			}
		
		
		}
	}
	//sound the orange alarm if they outnumber us by 6
	if(enmUn-6>freUn){ongAlarm=true;}
	else{ongAlarm=false;}
	
	
	
	
//	Formation
//	check to make sure king is well guarded by troops
//	make sure that at least a 2 archers beside the king
//	make sure king is as far away as possible a wall
//	give at least 1 knight to the king, in front of king facing the same direction of the king
//	designate these units as king's royal guard
	
//	if time write a separate function for their movements


	//implement these better if have time
	
// all units will prioritize attack over movement
//	if(getRoyalarcs()<2||getRoyalknits()<1){setRoyal();}
	if(getDecoys()<1){setDecoy();}
//also units will turn to the nearest enemy unit if within 3 radius
	
	
	if(rank==infantry||rank==knight){
	//melee units attack
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
		/*temmp=none;
		for(i=1;i<3;i++){
			if(c+i>COLS||c-i<0||r+i>ROWS||r-i<0)continue;
				 if(sitrep.thing[c-i][r].what==unit&&sitrep.thing[c-i][r].tla!=tla){temmp=lt;}
			else if(sitrep.thing[c+i][i].what==unit&&sitrep.thing[c+i][r].tla!=tla){temmp=rt;}
			else if(sitrep.thing[c][r+i].what==unit&&sitrep.thing[c][r+i].tla!=tla){temmp=dn;}
			else if(sitrep.thing[c][r-i].what==unit&&sitrep.thing[c][r-i].tla!=tla){temmp=up;}
		}
		if(temmp!=none){
			a.action=turn;
			a.dir=temmp;
			return a;
		}*/
	}else if(rank==archer){
	//archers command
		switch(dir){
			case up:	Mtr-=3;
						Mtc--;
						mtr--;
						mtc++; break;
			case dn: 	Mtr++;
						Mtc--;
						mtr+=3;
						mtc++; break;
			case rt:	Mtr--;
						Mtc++;
						mtr++;
						mtc+=3; break;
			case lt:	Mtr--;
						Mtc-=3;
						mtr++;
						mtc--; break;
			case none: break;
		}
	//search the sit rep for enemies
		for(i=Mtr;i<=mtr;i++){
			for(k=Mtc;k<=mtc;k++){
				if(i>=0&&i<ROWS&&k>=0&&k<COLS){
					if(sitrep.thing[i][k].what==unit){
						if(sitrep.thing[i][k].tla!=tla){
							a.action=attack;
							a.ar=tr;
							a.ac=tc;
							return a;
						}
					}
				}
			}
		}
	}
	
	//royal guard ignores all alarms and will always protect the king
	//form a formation around the king so that enemy units cannot attack
	//     a>
	//     *> K>
	//	   a>
	// if king moves move with him
	//face archers either to the left or right depending on where enemies are
	//group will only move as fast as archers can move, however if pursued by the enemy, king wil drop archers and run with knight.
/*	if(royal){
		temmp=Wayto(CposR,CposC,r,c,sitrep,speed);
		if(dir==temmp){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight||rank==crown)a.maxDist=speed;
			return a;
		} else {
			a.action=turn;
			a.dir=temmp;
			return a;
		}
	}*/
	
	int posivmoves[10][10];
	int maxj=0,maxw=0;
	if(rank==crown){
		//needs to move according to units
		//nope ran out of time, now just going in circles
		
		//face up, go up, face right, go right, face down, go down, face left, go left
		
		switch(sitrep.turnNumber%8){
			case 0:a.action=turn;
					a.dir=up;
					break;
			case 2:a.action=turn;
					a.dir=rt;
					break;
			case 4:a.action=turn;
					a.dir=dn;
					break;
			case 6:a.action=turn;
					a.dir=lt;
					break;
			case 1:
			case 3:
			case 5:
			case 7: a.action=fwd;
					a.maxDist=3;
					break;
		}
		
		return a;
		
		
		/*
		if(sitrep.turnNumber<=1){
			for(j=r-5;j<r+5;j++){
				if(r+j>ROWS||r-j<0)continue;
				for(w=c-5;w<c+5;w++){
					if(c+w>COLS||c-w<0)continue;
					for(i=0;i<ROWS;i++){
						for(k=0;k<COLS;k++){
							if(sitrep.thing[i][k].what==unit&&sitrep.thing[i][k].tla!=tla){
							posivmoves[j+5-r][w+5-c]+=dista(j,w,i,k);
							}
						}
					}
				}
			}
			
		
			
			for(j=r-5;j<r+5;j++){
				if(r+j>ROWS||r-j<0)continue;
				for(w=c-5;w<c+5;w++){
					if(c+w>COLS||c-w<0)continue;			
					if(posivmoves[maxj][maxw]<posivmoves[j+5-r][w+5-c]){
						maxj=j+5-r;
						maxw=w+5-c;
					}
					
				}
			}
			rdest=maxj-5+r;
			cdest=maxw-5+c;
		}
		
		temmp=none;
		for(i=1;i<4;i++){
			if(c+i>COLS||c-i<0||r+i>ROWS||r-i<0)continue;
				 if(sitrep.thing[c-i][r].what==unit&&sitrep.thing[c-i][r].tla!=tla){temmp=rt;}
			else if(sitrep.thing[c+i][i].what==unit&&sitrep.thing[c+i][r].tla!=tla){temmp=lt;}
			else if(sitrep.thing[c][r+i].what==unit&&sitrep.thing[c][r+i].tla!=tla){temmp=up;}
			else if(sitrep.thing[c][r-i].what==unit&&sitrep.thing[c][r-i].tla!=tla){temmp=dn;}
		}
		if(temmp!=none){
			if(dir==temmp){
				a.action=fwd;
				a.maxDist=1;
				if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
				return a;
			} else {
				a.action=turn;
				a.dir=temmp;
				return a;
			}
		}
		
		
		temmp=Wayto(rdest,cdest,r,c,sitrep,speed);
		if(dir==temmp){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight||rank==crown)a.maxDist=speed;
			return a;
		} else {
			a.action=turn;
			a.dir=temmp;
			return a;
		}
		*/
	}
	
	if(decoy){
		
		
		temmp=Whirlwind(tr,tc,sitrep,speed);
		if(dir==temmp){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight||rank==crown)a.maxDist=speed;
			return a;
		} else {
			a.action=turn;
			a.dir=temmp;
			return a;
		}
		
		
	}
	
	
	/*offensive strategy*/
	//no alarms are on, then attack the enemy king
	//decoy knight approach from the rear right and lower the number of enemy unitson the right.
	/*
	if(sitrep.turnNumber%4==0||sitrep.turnNumber<=1){
		rdest=ECposC;
		cdest=ECposR;
	}*/
	temmp=sitrep.nearestEnemy.dirFor;
	if(dir==temmp){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=temmp;
		return a;
	}
	
	

	/*Orange alarm, Yellow alarm*/
	//do not send any more troops to attack the enemy king, but keep front lines stable, retreat reinforcements to king to prepare for final stand
	//else if(ongAlarm||yelAlarm){}
	
	
	/*Red alarm*/
	// King is in serious danger, so final stand, archers in back firing arrows, infantry in front, and knights behind the king
	
	

	
	//default attack
	//default move
	/*if(rank==infantry||rank==crown||rank==knight){
	//melee units attack
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
	
	}else{
	//archers command
		switch(dir){
			case up:	Mtr-=3;
						Mtc--;
						mtr--;
						mtc++; break;
			case dn: 	Mtr++;
						Mtc--;
						mtr+=3;
						mtc++; break;
			case rt:	Mtr--;
						Mtc++;
						mtr++;
						mtc+=3; break;
			case lt:	Mtr--;
						Mtc-=3;
						mtr++;
						mtc--; break;
			case none: break;
		}
	//search the sit rep for enemies
		for(i=Mtr;i<=mtr;i++){
			for(k=Mtc;k<=mtc;k++){
				if(i>=0&&i<ROWS&&k>=0&&k<COLS){
					if(sitrep.thing[i][k].what==unit){
						if(sitrep.thing[i][k].tla!=tla){
							a.action=attack;
							a.ar=tr;
							a.ac=tc;
							return a;
						}
					}
				}
			}
		}
	}
	
	temmp=Wayto();
	if(dir==temmp){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=speed;
		return a;
	} else {
		a.action=turn;
		a.dir=temmp;
		return a;
	}
*/
}
#endif