//Austin Derbique
//A01967241
//11-29-13
#include "win.h":
#include <cmath>
#include <iostream>
#define c1
#define r1
#define c2
#define r2
#define c3
#define r3
#define c4
#define r4
int win::cmknight=0;
int win::cmarcher=0;
int win::cminfantry=0;
int win::cmcrown=0;

void win::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;


	if(rank==crown){
		if(minC<COLS/2){
	                tr=minR;
	                tc=minC;
	          
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
        	if(minC>COLS/2){
        	        tr=maxR;
        	        tc=maxC;
	
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
	if(rank==knight){
		if(minC<COLS/2){
	                tr=minR+rand()%(maxR-minR);
	                tc=maxC;
	          
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
        	if(minC>COLS/2){
        	        tr=minR+rand()%(maxR-minR);
        	        tc=minC;
	
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
	if(rank==archer){
		if(minC<COLS/2){
	                tr=minR+rand()%(maxR-minR);
	                tc=maxC-1;
	          
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
        	if(minC>COLS/2){
        	        tr=minR+rand()%(maxR-minR);
        	        tc=minC+1;
	
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


// tell someone what you want to do
Action win::Recommendation(SitRep sitrep){
	
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
	
	if(rank==crown){
		if(c<COLS/2){
			if(r>0){
				if(dir=up){
					a.action=fwd;
					return a;
				}
				else{
					a.dir=up;
					return a;
				}
			}
			else if(r=1&&c!=1){
				if(dir=lt){
					a.action=fwd;
					return a;
				}
				else{
					a.dir=lt;
					return a;
				}
			}
		/*	else{
			        if(dir==sitrep.nearestEnemy.dirFor){
        		        	a.action=fwd;
      			        	a.maxDist=1;
               				a.maxDist=HORSESPEED;
        				return a;
     				 }
				else{
  				 	a.action=turn;
 			                a.dir=sitrep.nearestEnemy.dirFor;
        			        return a;
      				  }


			}*/
		}
		
		else if(c>COLS/2){
			if(r<ROWS-1){
				if(dir=dn){
					a.action=fwd;
					return a;
				}
				else{
					a.dir=dn;
					return a;
				}
			}
			else{
				if(dir=rt){
					a.action=fwd;
					return a;
				}
				else{
					a.dir=rt;
					return a;
				}
			}

		}

	}
	
	if(rank==knight||rank==infantry){
		if((c<(COLS/2)+1)&&cmknight==0){
			if(sitrep.thing[tr][tc].what==unit){
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					a.ar=tr;
					a.ac=tc;
					return a;
				}
			}
		
			if(r<(ROWS/2)){
				if(dir=dn){
					a.action=fwd;
					return a;
				}
				else{
					a.dir=dn;
					return a;
				}
			}else if(r>(ROWS/2)){
				if(dir=up){
					a.action=fwd;
					return a;
				}
				else{
					a.dir=up;
					return a;
				}
			}
			else if(r=(ROWS/2)){
				if(dir=rt){
					if(c<(COLS/2)){
					a.action=fwd;
					return a;
					}
					else{
						cmknight++;
					}					
				}
				else{
					a.dir=rt;
					return a;
				}
			}
		}
		if((c>(COLS/2)-1)&&cmknight==0){
			if(sitrep.thing[tr][tc].what==unit){
				if(sitrep.thing[tr][tc].tla!=tla){
					a.action=attack;
					a.ar=tr;
					a.ac=tc;
					return a;
				}
			}
		
			if(r<(ROWS/2)){
				if(dir=dn){
					a.action=fwd;
					return a;
				}
				else{
					a.dir=dn;
					return a;
				}
			}else if(r>(ROWS/2)){
				if(dir=up){
					a.action=fwd;
					return a;
				}
				else{
					a.dir=up;
					return a;
				}
			}
			else if(r=(ROWS/2)){
				if(dir=lt){
					if(c>(COLS/2)){
						a.action=fwd;
						return a;
					}
					else{
						cmknight++;
					}
				}
				else{
					a.dir=lt;
					return a;
				}
			}
		}
		else if(cmknight=1){
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
				a.maxDist=3;
				a.maxDist=HORSESPEED;
				return a;
			}
			else {
			a.action=turn;
			a.dir=sitrep.nearestEnemy.dirFor;
			return a;
			}
		}
	
	}
/*	if(rank==archer){
		int archr;
		int archc;
	//	archc=
		if(c<COLS/2){
			a.ar=30;
			a.ac=30;
		



			if(cmarcher=0){
				//move to [][]
				//cmarcher++
			if(cmarcher=1){}		




		
			}
		}
	}

*/
	if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=3;
		a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
//cout << "Archer cm" << cmarcher << endl;
//cout << "King cm" << cmcrown << endl;
}
