#ifndef oss_H
#define oss_H
#include "unit.h"
#include <time.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class oss : public Unit {
public:
	oss():Unit(){}
	oss(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do
bool dangerCalculator(SitRep sitrep, int ir, int ic){
	int irows=-1;
	int icols=-1;
	if (initialized==sitrep.turnNumber){
	return dangerZoneGeneral[ir][ic];
	}else{while(irows<ROWS){icols=-1;irows=irows+1;
	while(icols<=COLS){icols=icols+1;
	dangerZoneArcher[irows][icols]=dangerZoneInfantry[irows][icols]=dangerZoneKnightCrown[irows][icols]=dangerZoneGeneral[irows][icols]=false;
	}}
		while(irows<ROWS){icols=-1;irows=irows+1;
	while(icols<=COLS){icols=icols+1;
		if(sitrep.thing[irows][icols].what==unit){
			if(sitrep.thing[irows][icols].rank==archer&&sitrep.thing[irows][icols].tla!="oss"){
			int leftDanger=irows-3;
			int rightDanger=irows+3;
			int upDanger=icols-3;
			int downDanger=icols+4;
			if(leftDanger<0){leftDanger=0;}
			if(rightDanger>ROWS){rightDanger=ROWS;}
			if(upDanger<0){upDanger=0;}
			if(downDanger>COLS){downDanger==COLS;}
			int ltor=leftDanger-1;
			int dtou=downDanger;
			while (ltor!=rightDanger){ltor=ltor+1;
				dangerZoneArcher[ltor][icols]=dangerZoneGeneral[ltor][icols]=true;
			if(icols+1<=COLS){
				dangerZoneArcher[ltor][icols+1]=dangerZoneGeneral[ltor][icols+1]=true;}
			if(icols-1>=0){
				dangerZoneArcher[ltor][icols-1]=dangerZoneGeneral[ltor][icols-1]=true;}
			}
			while(dtou!=upDanger){dtou=dtou-1;
			dangerZoneArcher[irows][dtou]=dangerZoneGeneral[irows][dtou]=true;
			if(irows+1<=COLS){
			dangerZoneArcher[irows+1][dtou]=dangerZoneGeneral[irows+1][dtou]=true;}
			if(irows-1>=0){
			dangerZoneArcher[irows-1][dtou]=dangerZoneGeneral[irows-1][dtou]=true;}
			}
			}
			if(sitrep.thing[irows][icols].rank==infantry&&sitrep.thing[irows][icols].tla!="oss"){
			int leftDanger=irows-1;
			if(leftDanger>=0){
			dangerZoneInfantry[leftDanger][icols]=dangerZoneGeneral[leftDanger][icols]=true;}
			int rightDanger=irows+1;
			if(rightDanger<=ROWS){dangerZoneInfantry[rightDanger][icols]=dangerZoneGeneral[rightDanger][icols]=true;}
			int upDanger=icols-1;
			if(upDanger>=0){dangerZoneInfantry[irows][upDanger]=dangerZoneGeneral[irows][upDanger]=true;}
			int downDanger=icols+1;
			if(downDanger>COLS){dangerZoneInfantry[irows][downDanger]=dangerZoneGeneral[irows][downDanger]=true;}
			

			}
			if(sitrep.thing[irows][icols].rank==knight||sitrep.thing[irows][icols].rank==crown&&sitrep.thing[irows][icols].tla!="oss"){
			int leftDanger=irows-1;
			if(leftDanger>=0){
				dangerZoneKnightCrown[leftDanger][icols]=dangerZoneGeneral[leftDanger][icols]=true;}
			int rightDanger=irows+1;
			if(rightDanger<=ROWS){dangerZoneKnightCrown[rightDanger][icols]=dangerZoneGeneral[rightDanger][icols]=true;}
			int upDanger=icols-1;
			if(upDanger>=0){dangerZoneKnightCrown[irows][upDanger]=dangerZoneGeneral[irows][upDanger]=true;}
			int downDanger=icols+1;
			if(downDanger>COLS){dangerZoneKnightCrown[irows][downDanger]=dangerZoneGeneral[irows][downDanger]=true;}
			int temp;
			if(sitrep.thing[irows][icols].dir==up){temp=icols;upDanger=icols-6;if(upDanger<0){upDanger=0;}
			while(temp!=upDanger){temp=temp-1;if(temp<0){temp=0;}if(sitrep.thing[irows][temp].what==unit){upDanger=temp;if(sitrep.thing[irows][temp].tla=="oss"){dangerZoneKnightCrown[irows][temp]==true;}}}}
			if(sitrep.thing[irows][icols].dir==dn){temp=icols;upDanger=icols+6;if(downDanger>COLS){downDanger=COLS;}
			while(temp!=downDanger){temp=temp+1;if(temp>COLS){temp=COLS;}if(sitrep.thing[irows][temp].what==unit){downDanger=temp;if(sitrep.thing[irows][temp].tla=="oss"){dangerZoneKnightCrown[irows][temp]==true;}}}}
			if(sitrep.thing[irows][icols].dir==lt){temp=irows;leftDanger=irows-6;if(leftDanger<0){leftDanger=0;}
			while(temp!=leftDanger){temp=temp-1;if(temp<0){temp=0;}if(sitrep.thing[temp][icols].what==unit){leftDanger=temp;if(sitrep.thing[temp][icols].tla=="oss"){dangerZoneKnightCrown[temp][icols]==true;}}}}
			if(sitrep.thing[irows][icols].dir==rt){temp=irows;rightDanger=irows+6;if(rightDanger>ROWS){rightDanger=ROWS;}
			while(temp!=rightDanger){temp=temp+1;if(temp>COLS){temp=COLS;}if(sitrep.thing[temp][icols].what==unit){downDanger=temp;if(sitrep.thing[temp][icols].tla=="oss"){dangerZoneKnightCrown[temp][icols]==true;}}}}
			}
		}
	}initialized==sitrep.turnNumber;
	}
	
return dangerZoneGeneral[ir][ic];

	}
}
bool attackFinder(SitRep sitrep, int ir, int ic){
	int irows=-1;
	int icols=-1;
	if (initializedabc==sitrep.turnNumber){
	return dangerZoneGeneral[ir][ic];
	}else{infantryAttackDirNeeded='o';archerAttackDirNeeded='o';kingAttackDirNeeded='o';knightAttackDirNeeded='o';assassinOption=false;infantryAttackOption=false;knightAttackOption=false;archerAttackOption=false;infantryAssassinationTargetHP=10000;archerAssassinationTargetHP=10000;knightAssassinationTargetHP=10000;knightAssassinationTargetHP=10000;while(irows<ROWS){icols=-1;irows=irows+1;
	while(icols<=COLS){icols=icols+1;
	canAttackArcher[irows][icols]=canAttackCrown[irows][icols]=canAttackKnight[irows][icols]=canAttackInfantry[irows][icols]=false;
	}}
		while(irows<ROWS){icols=-1;irows=irows+1;
	while(icols<=COLS){icols=icols+1;
		if(sitrep.thing[irows][icols].what==unit){
			if(sitrep.thing[irows][icols].rank==archer&&sitrep.thing[irows][icols].tla=="oss"){
			int leftDanger=irows-3;
			int rightDanger=irows+3;
			int upDanger=icols-3;
			int downDanger=icols+4;
			if(leftDanger<0){leftDanger=0;}
			if(rightDanger>ROWS){rightDanger=ROWS;}
			if(upDanger<0){upDanger=0;}
			if(downDanger>COLS){downDanger==COLS;}
			int ltor=leftDanger-1;
			int dtou=downDanger;
			while (ltor!=rightDanger){ltor=ltor+1;if(sitrep.thing[ltor][icols].what==unit&&sitrep.thing[ltor][icols].tla!="oss"){
			
	switch(rank){
	case infantry: {canAttackInfantry[irows][icols]=true;if(sitrep.thing[ltor][icols].hp<=infantryAssassinationTargetHP){infantryAttackOption=true;infantryAssassinationTargetCol=icols;infantryAssassinationTargetRow=ltor;
		infantryAssassinRow=irows;infantryAssassinCol=icols;
		if(ltor<irows){infantryAttackDirNeeded='l';}if(ltor>irows){infantryAttackDirNeeded='r';}infantryAttackOption=true;} break;}
	case knight: {canAttackKnight[irows][icols]=true;if(sitrep.thing[ltor][icols].hp<=knightAssassinationTargetHP){knightAttackOption=true;knightAssassinationTargetCol=icols;knightAssassinationTargetRow=ltor;
		knightAssassinRow=irows;knightAssassinCol=icols;
		if(ltor<irows){knightAttackDirNeeded='l';}if(ltor>irows){knightAttackDirNeeded='r';}knightAttackOption=true;} break;}
	case crown: {canAttackCrown[irows][icols]=true;assassinOption=true;kingAssassinationTargetCol=icols;kingAssassinationTargetRow=ltor;
		kingAssassinRow=irows;kingAssassinCol=icols;
		if(ltor<irows){kingAttackDirNeeded='l';}if(ltor>irows){kingAttackDirNeeded='r';}; break;}
	case archer: {canAttackArcher[irows][icols]=true;if(sitrep.thing[ltor][icols].hp<=archerAssassinationTargetHP){archerAttackOption=true;archerAssassinationTargetCol=icols;archerAssassinationTargetRow=ltor;
		archerAssassinRow=irows;archerAssassinCol=icols;
		if(ltor<irows){archerAttackDirNeeded='l';}if(ltor>irows){archerAttackDirNeeded='r';}archerAttackOption=true;} break;}}
				
			if(icols+1<=COLS){
				if(sitrep.thing[ltor][icols].what==unit&&sitrep.thing[ltor][icols+1].tla!="oss"){
		switch(rank){
	case infantry: {canAttackInfantry[irows][icols+1]=true;if(sitrep.thing[ltor][icols+1].hp<=infantryAssassinationTargetHP){infantryAttackOption=true;infantryAssassinationTargetCol=icols+1;infantryAssassinationTargetRow=ltor;
		infantryAssassinRow=irows;infantryAssassinCol=icols;
		if(ltor<irows){infantryAttackDirNeeded='l';}if(ltor>irows){infantryAttackDirNeeded='r';}infantryAttackOption=true;} break;}
	case knight: {canAttackKnight[irows][icols]=true;if(sitrep.thing[ltor][icols+1].hp<=knightAssassinationTargetHP){knightAttackOption=true;knightAssassinationTargetCol=icols+1;knightAssassinationTargetRow=ltor;
		knightAssassinRow=irows;knightAssassinCol=icols;
		if(ltor<irows){knightAttackDirNeeded='l';}if(ltor>irows){knightAttackDirNeeded='r';}knightAttackOption=true;} break;}
	case crown: {canAttackCrown[irows][icols]=true;assassinOption=true;kingAssassinationTargetCol=icols+1;kingAssassinationTargetRow=ltor;
		kingAssassinRow=irows;kingAssassinCol=icols;
		if(ltor<irows){kingAttackDirNeeded='l';}if(ltor>irows){kingAttackDirNeeded='r';}assassinOption=true; break;}
	case archer: {canAttackArcher[irows][icols]=true;if(sitrep.thing[ltor][icols+1].hp<=archerAssassinationTargetHP){archerAttackOption=true;archerAssassinationTargetCol=icols+1;archerAssassinationTargetRow=ltor;
		archerAssassinRow=irows;archerAssassinCol=icols;
		if(ltor<irows){archerAttackDirNeeded='l';}if(ltor>irows){archerAttackDirNeeded='r';}archerAttackOption=true;} break;}}}}
	
			if(icols-1>=0){
				if(sitrep.thing[ltor][icols].what==unit&&sitrep.thing[ltor][icols-1].tla!="oss"){
			
		switch(rank){
	case infantry: {canAttackInfantry[irows][icols-1]=true;if(sitrep.thing[ltor][icols-1].hp<=infantryAssassinationTargetHP){infantryAttackOption=true;infantryAssassinationTargetCol=icols-1;infantryAssassinationTargetRow=ltor;
		infantryAssassinRow=irows;infantryAssassinCol=icols;
		if(ltor<irows){infantryAttackDirNeeded='l';}if(ltor>irows){infantryAttackDirNeeded='r';}infantryAttackOption=true;} break;}
	case knight: {canAttackKnight[irows][icols]=true;if(sitrep.thing[ltor][icols-1].hp<=knightAssassinationTargetHP){knightAttackOption=true;knightAssassinationTargetCol=icols-1;knightAssassinationTargetRow=ltor;
		knightAssassinRow=irows;knightAssassinCol=icols;
		if(ltor<irows){knightAttackDirNeeded='l';}if(ltor>irows){knightAttackDirNeeded='r';}knightAttackOption=true;} break;}
	case crown: {canAttackCrown[irows][icols]=true;assassinOption=true;kingAssassinationTargetCol=icols-1;kingAssassinationTargetRow=ltor;
		kingAssassinRow=irows;kingAssassinCol=icols;
		if(ltor<irows){kingAttackDirNeeded='l';}if(ltor>irows){kingAttackDirNeeded='r';}assassinOption=true; break;}
	case archer: {canAttackArcher[irows][icols]=true;if(sitrep.thing[ltor][icols-1].hp<=archerAssassinationTargetHP){archerAttackOption=true;archerAssassinationTargetCol=icols-1;archerAssassinationTargetRow=ltor;
		archerAssassinRow=irows;archerAssassinCol=icols;
		if(ltor<irows){archerAttackDirNeeded='l';}if(ltor>irows){archerAttackDirNeeded='r';}archerAttackOption=true;} break;}}}}}}
			
			while (dtou!=upDanger){dtou=dtou-1;if(sitrep.thing[irows][dtou].what==unit&&sitrep.thing[irows][dtou].tla!="oss"){
			
	switch(rank){
	case infantry: {canAttackInfantry[irows][icols]=true;if(sitrep.thing[irows][dtou].hp<=infantryAssassinationTargetHP){infantryAttackOption=true;infantryAssassinationTargetCol=dtou;infantryAssassinationTargetRow=irows;
		infantryAssassinRow=irows;infantryAssassinCol=icols;
		if(dtou>icols){if(infantryAttackDirNeeded=='r'&&sitrep.thing[irows][icols].dir=='r'||infantryAttackDirNeeded=='l'&&sitrep.thing[irows][icols].dir=='l'){}else {infantryAttackDirNeeded='d';}if(ltor>irows){infantryAttackDirNeeded='u';}infantryAttackOption=true;} break;}}
	case knight: {canAttackKnight[irows][icols]=true;if(sitrep.thing[ltor][icols].hp<=knightAssassinationTargetHP){knightAttackOption=true;knightAssassinationTargetCol=icols;knightAssassinationTargetRow=ltor;
		knightAssassinRow=irows;knightAssassinCol=icols;
		if(ltor<irows){knightAttackDirNeeded='l';}if(ltor>irows){knightAttackDirNeeded='r';}knightAttackOption=true;} break;}
	case crown: {canAttackCrown[irows][icols]=true;assassinOption=true;kingAssassinationTargetCol=icols;kingAssassinationTargetRow=ltor;
		kingAssassinRow=irows;kingAssassinCol=icols;
		if(ltor<irows){kingAttackDirNeeded='l';}if(ltor>irows){kingAttackDirNeeded='r';}; break;}
	case archer: {canAttackArcher[irows][icols]=true;if(sitrep.thing[ltor][icols].hp<=archerAssassinationTargetHP){archerAttackOption=true;archerAssassinationTargetCol=icols;archerAssassinationTargetRow=ltor;
		archerAssassinRow=irows;archerAssassinCol=icols;
		if(ltor<irows){archerAttackDirNeeded='l';}if(ltor>irows){archerAttackDirNeeded='r';}archerAttackOption=true;} break;}}
				
			if(icols+1<=COLS){
				if(sitrep.thing[ltor][icols].what==unit&&sitrep.thing[ltor][icols+1].tla!="oss"){
		switch(rank){
	case infantry: {canAttackInfantry[irows][icols+1]=true;if(sitrep.thing[ltor][icols+1].hp<=infantryAssassinationTargetHP){infantryAttackOption=true;infantryAssassinationTargetCol=icols+1;infantryAssassinationTargetRow=ltor;
		infantryAssassinRow=irows;infantryAssassinCol=icols;
		if(ltor<irows){infantryAttackDirNeeded='l';}if(ltor>irows){infantryAttackDirNeeded='r';}infantryAttackOption=true;} break;}
	case knight: {canAttackKnight[irows][icols]=true;if(sitrep.thing[ltor][icols+1].hp<=knightAssassinationTargetHP){knightAttackOption=true;knightAssassinationTargetCol=icols+1;knightAssassinationTargetRow=ltor;
		knightAssassinRow=irows;knightAssassinCol=icols;
		if(ltor<irows){knightAttackDirNeeded='l';}if(ltor>irows){knightAttackDirNeeded='r';}knightAttackOption=true;} break;}
	case crown: {canAttackCrown[irows][icols]=true;assassinOption=true;kingAssassinationTargetCol=icols+1;kingAssassinationTargetRow=ltor;
		kingAssassinRow=irows;kingAssassinCol=icols;
		if(ltor<irows){kingAttackDirNeeded='l';}if(ltor>irows){kingAttackDirNeeded='r';}assassinOption=true; break;}
	case archer: {canAttackArcher[irows][icols]=true;if(sitrep.thing[ltor][icols+1].hp<=archerAssassinationTargetHP){archerAttackOption=true;archerAssassinationTargetCol=icols+1;archerAssassinationTargetRow=ltor;
		archerAssassinRow=irows;archerAssassinCol=icols;
		if(ltor<irows){archerAttackDirNeeded='l';}if(ltor>irows){archerAttackDirNeeded='r';}archerAttackOption=true;} break;}}}}
	
			if(icols-1>=0){
				if(sitrep.thing[ltor][icols].what==unit&&sitrep.thing[ltor][icols-1].tla!="oss"){
			
		switch(rank){
	case infantry: {canAttackInfantry[irows][icols-1]=true;if(sitrep.thing[ltor][icols-1].hp<=infantryAssassinationTargetHP){infantryAttackOption=true;infantryAssassinationTargetCol=icols-1;infantryAssassinationTargetRow=ltor;
		infantryAssassinRow=irows;infantryAssassinCol=icols;
		if(ltor<irows){infantryAttackDirNeeded='l';}if(ltor>irows){infantryAttackDirNeeded='r';}infantryAttackOption=true;} break;}
	case knight: {canAttackKnight[irows][icols]=true;if(sitrep.thing[ltor][icols-1].hp<=knightAssassinationTargetHP){knightAttackOption=true;knightAssassinationTargetCol=icols-1;knightAssassinationTargetRow=ltor;
		knightAssassinRow=irows;knightAssassinCol=icols;
		if(ltor<irows){knightAttackDirNeeded='l';}if(ltor>irows){knightAttackDirNeeded='r';}knightAttackOption=true;} break;}
	case crown: {canAttackCrown[irows][icols]=true;assassinOption=true;kingAssassinationTargetCol=icols-1;kingAssassinationTargetRow=ltor;
		kingAssassinRow=irows;kingAssassinCol=icols;
		if(ltor<irows){kingAttackDirNeeded='l';}if(ltor>irows){kingAttackDirNeeded='r';}assassinOption=true; break;}
	case archer: {canAttackArcher[irows][icols]=true;if(sitrep.thing[ltor][icols-1].hp<=archerAssassinationTargetHP){archerAttackOption=true;archerAssassinationTargetCol=icols-1;archerAssassinationTargetRow=ltor;
		archerAssassinRow=irows;archerAssassinCol=icols;
		if(ltor<irows){archerAttackDirNeeded='l';}if(ltor>irows){archerAttackDirNeeded='r';}archerAttackOption=true;} break;}}}}}}

			
			while(dtou!=upDanger){dtou=dtou-1;
			dangerZoneArcher[irows][dtou]=dangerZoneGeneral[irows][dtou]=true;
			if(irows+1<=COLS){
			dangerZoneArcher[irows+1][dtou]=dangerZoneGeneral[irows+1][dtou]=true;}
			if(irows-1>=0){
			dangerZoneArcher[irows-1][dtou]=dangerZoneGeneral[irows-1][dtou]=true;}
			}
			}
			if(sitrep.thing[irows][icols].rank==infantry&&sitrep.thing[irows][icols].tla!="oss"){
			int leftDanger=irows-1;
			if(leftDanger>=0){
			dangerZoneInfantry[leftDanger][icols]=dangerZoneGeneral[leftDanger][icols]=true;}
			int rightDanger=irows+1;
			if(rightDanger<=ROWS){dangerZoneInfantry[rightDanger][icols]=dangerZoneGeneral[rightDanger][icols]=true;}
			int upDanger=icols-1;
			if(upDanger>=0){dangerZoneInfantry[irows][upDanger]=dangerZoneGeneral[irows][upDanger]=true;}
			int downDanger=icols+1;
			if(downDanger>COLS){dangerZoneInfantry[irows][downDanger]=dangerZoneGeneral[irows][downDanger]=true;}
			

			}
			if(sitrep.thing[irows][icols].rank==knight||sitrep.thing[irows][icols].rank==crown&&sitrep.thing[irows][icols].tla!="oss"){
			int leftDanger=irows-1;
			if(leftDanger>=0){
				dangerZoneKnightCrown[leftDanger][icols]=dangerZoneGeneral[leftDanger][icols]=true;}
			int rightDanger=irows+1;
			if(rightDanger<=ROWS){dangerZoneKnightCrown[rightDanger][icols]=dangerZoneGeneral[rightDanger][icols]=true;}
			int upDanger=icols-1;
			if(upDanger>=0){dangerZoneKnightCrown[irows][upDanger]=dangerZoneGeneral[irows][upDanger]=true;}
			int downDanger=icols+1;
			if(downDanger>COLS){dangerZoneKnightCrown[irows][downDanger]=dangerZoneGeneral[irows][downDanger]=true;}
			int temp;
			if(sitrep.thing[irows][icols].dir==up){temp=icols;upDanger=icols-6;if(upDanger<0){upDanger=0;}
			while(temp!=upDanger){temp=temp-1;if(temp<0){temp=0;}if(sitrep.thing[irows][temp].what==unit){upDanger=temp;if(sitrep.thing[irows][temp].tla=="oss"){dangerZoneKnightCrown[irows][temp]==true;}}}}
			if(sitrep.thing[irows][icols].dir==dn){temp=icols;upDanger=icols+6;if(downDanger>COLS){downDanger=COLS;}
			while(temp!=downDanger){temp=temp+1;if(temp>COLS){temp=COLS;}if(sitrep.thing[irows][temp].what==unit){downDanger=temp;if(sitrep.thing[irows][temp].tla=="oss"){dangerZoneKnightCrown[irows][temp]==true;}}}}
			if(sitrep.thing[irows][icols].dir==lt){temp=irows;leftDanger=irows-6;if(leftDanger<0){leftDanger=0;}
			while(temp!=leftDanger){temp=temp-1;if(temp<0){temp=0;}if(sitrep.thing[temp][icols].what==unit){leftDanger=temp;if(sitrep.thing[temp][icols].tla=="oss"){dangerZoneKnightCrown[temp][icols]==true;}}}}
			if(sitrep.thing[irows][icols].dir==rt){temp=irows;rightDanger=irows+6;if(rightDanger>ROWS){rightDanger=ROWS;}
			while(temp!=rightDanger){temp=temp+1;if(temp>COLS){temp=COLS;}if(sitrep.thing[temp][icols].what==unit){downDanger=temp;if(sitrep.thing[temp][icols].tla=="oss"){dangerZoneKnightCrown[temp][icols]==true;}}}}
			}
		}
	}initialized==sitrep.turnNumber;
	}
	
return dangerZoneGeneral[ir][ic];

		}
}

private:
	int initialized;
	bool dangerZoneArcher[ROWS][COLS];
	bool dangerZoneInfantry[ROWS][COLS];
	bool dangerZoneKnightCrown[ROWS][COLS];
	bool dangerZoneGeneral[ROWS][COLS];
	bool canAttackCrown[ROWS][COLS];
	bool canAttackArcher[ROWS][COLS];
	bool canAttackKnight[ROWS][COLS];
	bool canAttackInfantry[ROWS][COLS];
	int initializedabc;
	int kingAssassinCol;
	int kingAssassinRow;
	int kingAssassinationTargetRow;
	int kingAssassinationTargetCol;
	int kingAssassinationTargetHP;
	char kingAttackDirNeeded;
	bool assassinOption;
	bool attackOption;
	int knightAssassinRow;
	int knightAssassinCol;
	int knightAssassinationTargetRow;
	int knightAssassinationTargetCol;
	int knightAssassinationTargetHP;
	char knightAttackDirNeeded;
	bool knightAttackOption;
	int archerAssassinRow;
	int archerAssassinCol;
	int archerAssassinationTargetRow;
	int archerAssassinationTargetCol;
	int archerAssassinationTargetHP;
	char archerAttackDirNeeded;
	bool archerAttackOption;
	int infantryAssassinRow;
	int infantryAssassinCol;
	int infantryAssassinationTargetRow;
	int infantryAssassinationTargetCol;
	int infantryAssassinationTargetHP;
	char infantryAttackDirNeeded;
	bool infantryAttackOption;
};
#endif
