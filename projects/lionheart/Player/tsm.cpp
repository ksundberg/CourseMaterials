#include "tsm.h"
#include "lionheart2.h"
#include <cmath>
#include <iostream>

//how any units are left

static bool crownPlaced=false;


bool checkForCrown(){
	int i, j;
	SitRep sitrep;
	
	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			if(sitrep.thing[i][j].tla=="tsm"){
				if(sitrep.thing[i][j].rank==crown){
				return crownPlaced=true;
			}else return crownPlaced=false;

		}
	}
   }
}

bool tsm::crownStuck(bool stuck){
	int crowC=0;
	int crowR=0;
	int i,j;
	SitRep sitrep;
	int loopCount=0;

		for(i=0;i<ROWS;++i){
			for(j=0;j<COLS;++j){
				if(sitrep.thing[i][j].tla==tla&&crowC){
					if(sitrep.thing[i][j].rank==crown){
						if(crowR==i&&crowC==j&&loopCount>=3)
						loopCount=0;
						return stuck=true;
						}
						crowR=i;
						crowC=j;
						loopCount++;
					}
				}
			}return stuck=false;
		}




void tsm::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;

	int tr=0;
	int tc=0;
	Dir td=none;

	

	checkForCrown();

	

	while(!done){
		while(!crownPlaced){
			
			if(c<10){
			tr=minR+(maxR-minR)%2;	
			tc=minC+5;
				crownPlaced=true;
			}
			if(c>10){
			tr=minR+(maxR-minR)%2;
			tc=maxR-5;
				crownPlaced=true;
			}
		}
		


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



Action tsm::Recommendation(SitRep sitrep){
	Action a; 
	int i, j;
	Dir td;
	int ai = r;
	int aj = c;
	int loopCount=0;
	bool move=false;
	int crowC=0, crowR=0;
	
	
	int firstCMOVE=2;

	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}

	


	switch(rank){
	case infantry: 
			
		//Go straight for their crown!
	while(sitrep.turnNumber>=5){	
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
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
	}

	break;
	
	case archer: 
		    
	
	switch(dir){
	
	case dn: ai+=2; break;
	case up: ai-=2; break;
	case rt: aj+=2; break;
	case lt: aj-=2; break;
	case none: break;
	}
	while(sitrep.turnNumber<10){
		a.action=nothing;
		return a;
	}
	//First off, if the crown is in your range, kill it.  
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
			if(sitrep.thing[ai+1][aj+1].rank==crown&&sitrep.thing[ai+1][aj+1].tla!=tla){
					a.action=attack;
					a.ar=ai+1;
					a.ac=aj+1;
				return a;
				}else if(sitrep.thing[ai+1][aj+1].what==unit&&sitrep.thing[ai+1][aj+1].tla!=tla){
					a.action=attack;
					a.ar=ai+1;
					a.ac=aj+1;
				return a;
			}

			if(sitrep.thing[ai][aj+1].rank==crown&&sitrep.thing[ai][aj+1].tla!=tla){
					a.action=attack;
					a.ar=ai;
					a.ac=aj+1;
				return a;
				}else if(sitrep.thing[ai][aj+1].what==unit&&sitrep.thing[ai][aj+1].tla!=tla){
					a.action=attack;
					a.ar=ai;
					a.ac=aj+1;
				return a;
			}

			if(sitrep.thing[ai+1][aj].rank==crown&&sitrep.thing[ai+1][aj].tla!=tla){
					a.action=attack;
					a.ar=ai+1;
					a.ac=aj;
				return a;
				}else if(sitrep.thing[ai+1][aj].what==unit&&sitrep.thing[ai+1][aj].tla!=tla){
					a.action=attack;
					a.ar=ai+1;
					a.ac=aj;
				return a;
			}

			if(sitrep.thing[ai][aj].rank==crown&&sitrep.thing[ai][aj].tla!=tla){
					a.action=attack;
					a.ar=ai;
					a.ac=aj;
				return a;
				}else if(sitrep.thing[ai][aj].what==unit&&sitrep.thing[ai][aj].tla!=tla){
					a.action=attack;
					a.ar=ai;
					a.ac=aj;
				return a;
			}

			if(sitrep.thing[ai-1][aj].rank==crown&&sitrep.thing[ai-1][aj].tla!=tla){
					a.action=attack;
					a.ar=ai-1;
					a.ac=aj;
				return a;
				}else if(sitrep.thing[ai-1][aj].what==unit&&sitrep.thing[ai-1][aj].tla!=tla){
					a.action=attack;
					a.ar=ai-1;
					a.ac=aj;
				return a;
			}

			if(sitrep.thing[ai][aj-1].rank==crown&&sitrep.thing[ai][aj-1].tla!=tla){
					a.action=attack;
					a.ar=ai;
					a.ac=aj-1;
				return a;
			}else if(sitrep.thing[ai][aj-1].what==unit&&sitrep.thing[ai][aj-1].tla!=tla){
					a.action=attack;
					a.ar=ai;
					a.ac=aj-1;
				return a;
			}

			if(sitrep.thing[ai-1][aj-1].rank==crown&&sitrep.thing[ai-1][aj-1].tla!=tla){
					a.action=attack;
					a.ar=ai-1;
					a.ac=aj-1;
				return a;
			}else if(sitrep.thing[ai-1][aj-1].what==unit&&sitrep.thing[ai-1][aj-1].tla!=tla){
					a.action=attack;
					a.ar=ai-1;
					a.ac=aj-1;
				return a;
			}
		
		
		}else if(sitrep.nearestEnemyCrown.dirFor){
						a.action=fwd;
						a.maxDist=1;
						return a;

	   }else{
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	   }break;//end archer statement

	case knight: 
		while(sitrep.turnNumber<10){
			a.action=nothing;
			return a;
		}
		if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
			if(sitrep.thing[tr][tc].what==unit&&sitrep.thing[tr][tc].rank==crown){
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					a.ar=tr;
					a.ac=tc;
				return a;
				}
			}
		}else if(sitrep.nearestEnemyCrown.dirFor){
						a.action=fwd;
						a.maxDist=1;
						return a;

	   }else{
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}break;

	case crown: 

		//gives me the location of my crown
		for(i=0;i<ROWS;++i){
			for(j=0;j<COLS;++j){
				if(sitrep.thing[i][j].tla==tla){
					if(sitrep.thing[i][j].rank==crown){
						crowC=j;
						crowR=i;
					}
				}
			}
		}
						// 
						
							if(sitrep.nearestEnemy.c<crowC+3||sitrep.nearestEnemy.c<crowC-3||sitrep.nearestEnemy.c>crowC-3||sitrep.nearestEnemy.c>crowC+3
								||sitrep.nearestEnemy.r<crowR+3||sitrep.nearestEnemy.r<crowR-3||sitrep.nearestEnemy.r>crowR-3||sitrep.nearestEnemy.r>crowR+3||sitrep.thing[tr][tc].what==rock&&move==false){
								a.action=turn;
								switch(dir){
								case up: td=dn; break;
								case dn: td=up; break;
								case lt: td=rt; break;
								case rt: td=lt; break;
								}
								a.dir=td;
								move=true;
								return a;
								
								
							}
				while(move==true){
					     if(sitrep.thing[tr][tc].what==space){
								a.action=fwd;
								a.maxDist=HORSESPEED;
							
								return a;
								
							
							 }else if(sitrep.thing[tr][tc].what==unit&&sitrep.thing[tr][tc].tla!=tla){
								a.action=turn;
								a.dir=dn;
								
								return a;
							}else if(sitrep.thing[tr][tc].what==unit&&sitrep.thing[tr][tc].tla!=tla&&dir==dn){
								a.action=turn;
								a.dir=up;
								
								return a;
							}else if(sitrep.thing[tr][tc].what==unit&&sitrep.thing[tr][tc].tla!=tla&&dir==up){
								a.action=turn;
								a.dir=lt;
								
								return a;
							}else if(sitrep.thing[tr][tc].what==unit&&sitrep.thing[tr][tc].tla!=tla&&dir==lt){
								a.action=turn;
								a.dir=rt;
								
								return a;
							
							}
						
							
				}break;
}//end of unit switch







//default movement of archers and knights
if(rank==archer||rank==knight){
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
		if(rank==knight)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemyCrown.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}

}
 

