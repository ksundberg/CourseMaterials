#include "ike.h"
#include <cmath>
#include <iostream>
//#include "lionheart.cpp"

static int numarchers=0;
static int numinfantry=0;
static int numknights=0;
static int linesplaced=0;
static int counter=0;

void ike::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	//Direction of units
	int rdist=ROWS/2-(minR+(maxR-minR)/2);
	int cdist=COLS/2-(minC+(maxC-minC)/2);
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=up;
		else td=dn;
	}
	//Placement of units
	int qC=(maxC-minC)/4;
	int qR=(maxR-minR)/4;
	while(!done){
		
		//Infantry placement
		if(rank==infantry){
			++numinfantry;
			//Figure out which direction I'm coming from
			switch(td){
			case rt: int ir;
					for(ir=minR+qR; ir<=minR+qR+numinfantry; ++ir){
					//Switch to a new line if this one's filled up
						tr=ir;		
						tc=maxC;
/*						if(linesplaced>counter){
						ir=minR+qR;
						tr=ir;
						--tc;
						counter=linesplaced;
						}
						if(ir>=minR+3*qR){
							++linesplaced;
						}
	*/				 }	break;
			case lt: for(int ir=minR+qR; ir<minR+qR+numinfantry; ++ir){
						tc=minC;
						tr=ir;
						if(tr==minR+3*qR){
							tc++;
							tr=minR+qR;
							//linesplaced++;
						}
					 }	break;
			case up: for(int ic=minC+qC; ic<minC+qC+numinfantry; ++ic){
						tr=minR;
						tc=ic;
						if(tc==minC+3*qC){
							tr++;
							tc=minC+qC;
							//linesplaced++;
						}
					 }	break;
			case dn: for(int ic=minC+qC; ic<minC+qC+numinfantry; ic++){
						tr=maxR;
						tc=ic;
						if(tc==minC+3*qC){
							tr--;
							tc=minC+qC;
							//linesplaced++;
						}
					 }
			case none:	break;
			}
		}
		else{
		
		//Archer placement
		if(rank==archer){
			++numarchers;
			//Figure out which direction I'm coming from
			switch(td){
			case rt: for(int ir=minR+qR; ir<minR+qR+numarchers; ++ir){
						tc=maxC-2;
						tr=ir;
						//Switch to a new line if this one's filled up
						if(tr==minR+3*qR){
							tc--;
							tr=minR+qR;
							//linesplaced++;
						}
					 }	break;
			case lt: for(int ir=minR+qR; ir<minR+qR+numarchers; ++ir){
						tc=minC+2;
						tr=ir;
						if(tr==minR+3*qR){
							tc++;
							tr=minR+qR;
							//linesplaced++;
						}
					 }	break;
			case up: for(int ic=minC+qC; ic<minC+qC+numarchers; ++ic){
						tr=minR+2;
						tc=ic;
						if(tc==minC+3*qC){
							tr++;
							tc=minC+qC;
							//linesplaced++;
						}
					 }	break;
			case dn: for(int ic=minC+qC; ic<minC+qC+numarchers; ic++){
						tr=maxR-2;
						tc=ic;
						if(tc==minC+3*qC){
							tr--;
							tc=minC+qC;
							//linesplaced++;
						}
					 }
			case none:	break;
			}
		}	
		
			//Knight placement
			else{
				if(rank==knight){
				++numknights;
							//Figure out which direction I'm coming from
			switch(td){
			case rt: if(numknights%2){
						for(int ic=maxC; ic>maxC-numknights; --ic){
							tr=minR+qR-1;
							tc=ic;
							//Switch to a new column/row if this one's filled up
/*							if(tc==(minC+qC) || (maxC-tc)>=numknights/2){
								tc=maxC;
								tr--;
								//linesplaced++;
							}
*/						 }	break;
						}
						 else{
							for(int ic=maxC; ic>maxC-numknights; --ic){
								tr=minR+3*qR+1;
								tc=ic;
								//Switch to a new column/row if this one's filled up
								if(tc==(minC+qC) || (maxC-tc)>=numknights/2){
									tc=maxC;
									tr++;
									//linesplaced++;
								}
							 }	break;
							}
			case lt: for(int ir=minR+qR; ir<minR+qR+numknights; ++ir){
						tc=minC+2;
						tr=ir;
						if(tr==minR+3*qR){
							tc++;
							tr=minR+qR;
							//linesplaced++;
						}
					 }	break;
			case up: for(int ic=minC+qC; ic<minC+qC+numknights; ++ic){
						tr=minR+2;
						tc=ic;
						if(tc==minC+3*qC){
							tr++;
							tc=minC+qC;
							//linesplaced++;
						}
					 }	break;
			case dn: for(int ic=minC+qC; ic<minC+qC+numknights; ic++){
						tr=maxR-2;
						tc=ic;
						if(tc==minC+3*qC){
							tr--;
							tc=minC+qC;
							//linesplaced++;
						}
					 }
			case none:	break;
			}
		}
				//Where the king starts
				else{
					tr=minR+2*qR;	
					tc=minC+2*qC;
				}
			}
		}
		//Check for available spot & place the unit
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	r=tr;
	c=tc;
	dir=td;
}


// tell someone what you want to do
Action ike::Recommendation(SitRep sitrep){
	
	// this code is provided as an example only
	// use at your own risk
	Action a;
	Unit king;
	int numunits=numarchers+numinfantry+numknights+1;
	int kingpos;
	// first, try to attack in front of you
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
				//If the unit is an archer, attack first thing in range
				if(rank == archer){
					switch(dir){
					case up: tr--; break;
					case dn: tr++; break;
					case rt: tc++; break;
					case lt: tc--; break;
					case none: break;
					}
					for(int aar=tr-1; aar<tr+1; aar++){
						for(int aac=tc-1; aac<tc+1; aac++){
							a.action=attack;
							tc=aac;
							tr=aar;
							a.ar=tr;
							a.ac=tc;
							return a;
						}
					}
				}
				//Otherwise, attack what's in front of unit
				else{
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
				}
			}
		}
	}
	//Kill the king
	//getNearestEnemyCrown(king, kingpos);

	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}
