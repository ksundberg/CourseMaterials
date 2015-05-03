#include "phx.h"
#include <cmath>
#include <iostream>

using namespace std;

void phx::Place(int minR,int maxR,int minC,int maxC, SitRep s){
	int tr;
	int tc;
	int kr,kc;
	kr=(minR+((maxR-minR)/2));
	kc=(minC+((maxC-minC)/2));
	bool done=false;
	if(rank==crown){
		tr=kr;
		tc=kc;
	}
	if(rank==knight){//from the outside in
		if(!done){
			tr=minR;
			tc=minC;
			//first layer
			while(!done && tc<=maxC){
				if(s.thing[tr][tc].what==space)done=true;
				tc++;
			}tc--;}
		if(!done){
			while(!done && tr<=maxR){
				if(s.thing[tr][tc].what==space)done=true;
				tr++;				
			}tr--;}
		if(!done){
			while(!done && tc>=minC){
				if(s.thing[tr][tc].what==space)done=true;
				tc--;
			}tc++;}
		if(!done){
			while(!done && tr>=minR){				
				if(s.thing[tr][tc].what==space)done=true;
				tr--;
			}tr++;}
		if(!done){
			//second layer
			tc++;
			tr++;}
		if(!done){
			while(!done && tc<maxC){				
				if(s.thing[tr][tc].what==space)done=true;
				tc++;
			}tc--;}
		if(!done){
			while(!done && tr<maxR){				
				if(s.thing[tr][tc].what==space)done=true;
				tr++;
			}tr--;}
		if(!done){
			while(!done && tc>minC){				
				if(s.thing[tr][tc].what==space)done=true;
				tc--;
			}tc++;}
		if(!done){
			while(!done && tr>minR){				
				if(s.thing[tr][tc].what==space)done=true;
				tr--;
			}tr++;}

		if(!done){
			//last resort
			tr=minR+rand()%(maxR-minR);	
			tc=minC+rand()%(maxC-minC);	
			if(s.thing[tr][tc].what==space)done=true;
		}
	}
	if(rank==archer){
		while(!done){
		if(!done){
			tr=(kr-1);
			tc=(kc-1);}
			//first layer
		if(!done){
			while(!done && tc<=(kc+1)){
				if(s.thing[tr][tc].what==space)done=true;
				tc++;
			}tc--;}
		if(!done){
			while(!done && tr<=(kr+1)){
				if(s.thing[tr][tc].what==space)done=true;
				tr++;				
			}tr--;}
		if(!done){
			while(!done && tc>=(kc-1)){
				if(s.thing[tr][tc].what==space)done=true;
				tc--;
			}tc++;}
		if(!done){
			while(!done && tr>=(kr-1)){				
				if(s.thing[tr][tc].what==space)done=true;
				tr--;
			}tr++;}

		if(!done){
			tr=(kr-3);
			tc=(kc-3);
		}
			//second layer
		if(!done){
			while(!done && tc<=(kc+3)){
				if(s.thing[tr][tc].what==space)done=true;
				tc++;
			}tc--;}
		if(!done){
			while(!done && tr<=(kr+3)){
				if(s.thing[tr][tc].what==space)done=true;
				tr++;				
			}tr--;}
		if(!done){
			while(!done && tc>=(kc-3)){
				if(s.thing[tr][tc].what==space)done=true;
				tc--;
			}tc++;}
		if(!done){
			while(!done && tr>=(kr-3)){				
				if(s.thing[tr][tc].what==space)done=true;
				tr--;
			}tr++;}

		if(!done){
			//last resort
			tr=minR+rand()%(maxR-minR);	
			tc=minC+rand()%(maxC-minC);	
			if(s.thing[tr][tc].what==space)done=true;
			}
		}
	}
	if(rank==infantry){
		while(!done){
		if(!done){
			tr=(kr-2);
			tc=(kc+2);}
			//first layer
		if(!done){
			while(!done && tc>=(kc-2)){
				if(s.thing[tr][tc].what==space)done=true;
				tc--;
			}tc++;}
		if(!done){
			while(!done && tr<=(kr+2)){
				if(s.thing[tr][tc].what==space)done=true;
				tr++;				
			}tr--;}
		if(!done){
			while(!done && tc<=(kc+2)){
				if(s.thing[tr][tc].what==space)done=true;
				tc++;
			}tc--;}
		if(!done){
			while(!done && tr>=(kr-2)){				
				if(s.thing[tr][tc].what==space)done=true;
				tr--;
			}tr++;}

		if(!done){
			//last resort
			tr=minR+rand()%(maxR-minR);	
			tc=minC+rand()%(maxC-minC);	
			if(s.thing[tr][tc].what==space)done=true;
			}
		}
	}	

	r=tr;
	c=tc;
	
	//this is where we decide how to point 'em
	if(c>kc){
		dir=rt;
	}else if(c<kc){
		dir=lt;
	}else if((kr-r)>(kc-c)){
		dir=up;
	}else if((r-kr)>(c-kc)){
		dir=dn;
	}
	if(rank==crown){
		dir=rt;
	}
} // put unit on board


Action phx::Recommendation(SitRep s){
	Action a;
	int tr,tc;
	tr=r;
	tc=c;
	bool crownPeril = false;	
	if(rank!=archer){//if I am not an archer, look one space ahead
		switch(dir){
		case up: tr--; break;
		case dn: tr++; break;
		case rt: tc++; break;
		case lt: tc--; break;
		case none: exit(5); break;
		}
		if (rank==knight){

			if(s.nearestEnemyCrown.dirFor!=none){

			if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
				if(s.thing[tr][tc].what==unit){
					if(s.thing[tr][tc].tla!=tla){//the thing in front of me is a unit that is not mine					
						if(s.thing[tr][tc].rank==crown){
							a.action=attack; return a;
						}else if(s.thing[tr][tc].rank==archer){//the unit in front of me is an enemy archer
							a.action=attack; return a;						
						}else if(s.thing[tr][tc].rank==knight){//the unit in front of me is an enemy knight
							if(dir==s.nearestEnemyCrown.dirFor){
								a.action=attack;
								return a;
							} else {
								if(s.nearestEnemyCrown.dirFor!=none){
									a.action=turn;
									a.dir=s.nearestEnemyCrown.dirFor;
									return a;
								}else{
									a.action = nothing;
									return a;
								}
							}						
						}else {//the unit in front of me is an enemy infantry
							if(dir==s.nearestEnemyCrown.dirFor){
								a.action=attack;
								return a;
							} else {
								if(s.nearestEnemyCrown.dirFor!=none){
									a.action=turn;
									a.dir=s.nearestEnemyCrown.dirFor;
									return a;
								}else{
									a.action = nothing;
									return a;
								}
							}
						}
					}else {//HERE
						if(dir==s.nearestEnemyCrown.dirFor){
							a.action=fwd;
							a.maxDist=HORSESPEED-1;
							return a;
						} else {
							if(s.nearestEnemyCrown.dirFor!=none){
								a.action=turn;
								a.dir=s.nearestEnemyCrown.dirFor;
								return a;
							}else{
								a.action = nothing;
								return a;
							}
						}
					}
				}else{//HERE
					if(dir==s.nearestEnemyCrown.dirFor){
						a.action=fwd;
						a.maxDist=HORSESPEED-1;
						return a;
					}else{
						if(s.nearestEnemyCrown.dirFor!=none){
							a.action=turn;
							a.dir=s.nearestEnemyCrown.dirFor;
							return a;
						}else{
							a.action = fwd;
							a.maxDist=HORSESPEED-1;//THISISTHEONE
							return a;
						}
					}
				}
			}
			if(dir==s.nearestEnemyCrown.dirFor){//and HERE
				a.action=fwd;
				a.maxDist=HORSESPEED-1;
				return a;
			} else {
				if(s.nearestEnemyCrown.dirFor!=none){
					a.action=turn;
					a.dir=s.nearestEnemyCrown.dirFor;
					return a;
				}else{
					a.action = nothing;
					return a;
				}
			}
		
			if(dir==s.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=HORSESPEED-1;
				return a;
			} else {
				a.action=turn;
				a.dir=s.nearestEnemyCrown.dirFor;
				return a;
			}
			a.action=nothing;

			}else{
				if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
				if(s.thing[tr][tc].what==unit){
					if(s.thing[tr][tc].tla!=tla){//the thing in front of me is a unit that is not mine					
						if(s.thing[tr][tc].rank==crown){
							a.action=attack; return a;
						}else if(s.thing[tr][tc].rank==archer){//the unit in front of me is an enemy archer
							a.action=attack; return a;						
						}else if(s.thing[tr][tc].rank==knight){//the unit in front of me is an enemy knight
							if(dir==s.nearestEnemyCrown.dirFor){
								a.action=attack;
								return a;
							} else {
								if(s.nearestEnemyCrown.dirFor!=none){
									a.action=turn;
									a.dir=s.nearestEnemyCrown.dirFor;
									return a;
								}else{
									a.action = nothing;
									return a;
								}
							}						
						}else {//the unit in front of me is an enemy infantry
							if(dir==s.nearestEnemyCrown.dirFor){
								a.action=attack;
								return a;
							} else {
								if(s.nearestEnemyCrown.dirFor!=none){
									a.action=turn;
									a.dir=s.nearestEnemyCrown.dirFor;
									return a;
								}else{
									a.action = nothing;
									return a;
								}
							}
						}
					}else {//HERE
						if(dir==s.nearestEnemy.dirFor){
							a.action=fwd;
							a.maxDist=HORSESPEED-1;
							return a;
						} else {
							if(s.nearestEnemy.dirFor!=none){
								a.action=turn;
								a.dir=s.nearestEnemy.dirFor;
								return a;
							}else{
								a.action = nothing;
								return a;
							}
						}
					}
				}else{//HERE
					if(dir==s.nearestEnemy.dirFor){
						a.action=fwd;
						a.maxDist=HORSESPEED-1;
						return a;
					}else{
						if(s.nearestEnemy.dirFor!=none){
							a.action=turn;
							a.dir=s.nearestEnemy.dirFor;
							return a;
						}else{
							a.action = fwd;
							a.maxDist=HORSESPEED-1;//THISISTHEONE
							return a;
						}
					}
				}
			}
			if(dir==s.nearestEnemy.dirFor){//and HERE
				a.action=fwd;
				a.maxDist=HORSESPEED-1;
				return a;
			} else {
				if(s.nearestEnemy.dirFor!=none){
					a.action=turn;
					a.dir=s.nearestEnemy.dirFor;
					return a;
				}else{
					a.action = nothing;
					return a;
				}
			}
		
			if(dir==s.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=HORSESPEED-1;
				return a;
			} else {
				a.action=turn;
				a.dir=s.nearestEnemyCrown.dirFor;
				return a;
			}
			a.action=nothing;
			}


		}else if(rank==infantry){
			if(!crownPeril){
				if(s.thing[tr][tc].what==unit){
					if(s.thing[tr][tc].tla!=tla){
						a.action=attack; return a;
					}else{
						a.action=nothing; return a;
					}
				}else{
					a.action=nothing; return a;
				}
			}else{//crown is in peril
				if(s.thing[tr][tc].what==unit){
					if(s.thing[tr][tc].tla!=tla){
						a.action=attack; return a;
					}else{
						if(dir==s.nearestEnemyCrown.dirFor){
							a.action=fwd;
							a.maxDist=1;
							return a;
						} else {
							a.action=turn;
							a.dir=s.nearestEnemyCrown.dirFor;
							return a;
						}
					}
				}else{
					if(dir==s.nearestEnemyCrown.dirFor){
						a.action=fwd;
						a.maxDist=1;
						return a;
					}else{
						a.action=turn;
						a.dir=s.nearestEnemyCrown.dirFor;
						return a;
					}
				}	
			}
		}else if(rank==crown){
			if(s.thing[r-1][c-1].what==unit){
				if(s.thing[r-1][c-1].tla!=tla){
					crownPeril = true;
				}
			}else{
				if(s.thing[r-1][c-1].what!=unit)crownPeril = true;
			}
			if(s.thing[r+1][c+1].what==unit){
				if(s.thing[r-1][c-1].tla!=tla){
					crownPeril = true;
				}
			}else{
				if(s.thing[r-1][c-1].what!=unit)crownPeril = true;
			}
			if(s.thing[r+1][c-1].what==unit){
				if(s.thing[r-1][c-1].tla!=tla){
					crownPeril = true;
				}
			}else{
				if(s.thing[r-1][c-1].what!=unit)crownPeril = true;
			}
			if(s.thing[r-1][c+1].what==unit){
				if(s.thing[r-1][c-1].tla!=tla){
					crownPeril = true;
				}
			}else{
				if(s.thing[r-1][c-1].what!=unit)crownPeril = true;
			}
			if(crownPeril){//RUUUUUUNNNNNN!!!!!!
				switch(s.nearestEnemy.dirFor){
				case up: 
					if(dir==dn){
						a.action=fwd;
						a.maxDist=HORSESPEED;
						return a;
					}else{
						a.action=turn;
						a.dir = dn;
						return a;
					}   break;
				case dn: 
					if(dir==up){
						a.action=fwd;
						a.maxDist=HORSESPEED;
						return a;
					}else{
						a.action=turn;
						a.dir = up;
						return a;
					}   break;
				case rt: 
					if(dir==lt){
						a.action=fwd;
						a.maxDist=HORSESPEED;
						return a;
					}else{
						a.action=turn;
						a.dir = lt;
						return a;
					}   break;
				case lt: 
					if(dir==rt){
						a.action=fwd;
						a.maxDist=HORSESPEED;
						return a;
					}else{
						a.action=turn;
						a.dir = rt;
						return a;
					}   break;
				case none: a.action=nothing; return a; break;
				}		
			}else{//we're safe for now
				a.action=nothing; return a;
			}
		}
	}else{//I am an archer
		switch(dir){
		case up: for (int i = 3; i>0; --i){
					for (int j=-1; j<2; ++j){
						tr=r-i;
						tc=c+j;
						if(s.thing[tr][tc].what==unit){
							if(s.thing[tr][tc].tla!=tla){
								a.action = attack;
								a.ar=tr;
								a.ac=tc;
								return a;
							}
						}
					}
				} break;
		case dn: for (int i = 3; i>0; --i){
					for (int j=-1; j<2; ++j){
						tr=r+i;
						tc=c+j;
						if(s.thing[tr][tc].what==unit){
							if(s.thing[tr][tc].tla!=tla){
								a.action = attack;
								a.ar=tr;
								a.ac=tc;
								return a;
							}
						}
					}
				} break;
		case rt: for (int i = 1; i>-2; --i){
					for (int j=1; j<4; ++j){
						tr=r-i;
						tc=c+j;
						if(s.thing[tr][tc].what==unit){
							if(s.thing[tr][tc].tla!=tla){
								a.action = attack;
								a.ar=tr;
								a.ac=tc;
								return a;
							}
						}
					}
				} break;
		case lt: for (int i = 1; i>-2; --i){
					for (int j=1; j<4; ++j){
						tr=r-i;
						tc=c-j;
						if(s.thing[tr][tc].what==unit){
							if(s.thing[tr][tc].tla!=tla){
								a.action = attack;
								a.ar=tr;
								a.ac=tc;
								return a;
							}
						}
					}
				} break;
		case none: a.action=nothing; return a; break;
		}
		if(!crownPeril){
			a.action=nothing;
			return a;
		}else{
			if(dir==s.nearestEnemyCrown.dirFor){
				a.action=fwd;
				a.maxDist=1;
				return a;
			} else {
				a.action=turn;
				a.dir=s.nearestEnemyCrown.dirFor;
				return a;
			}
		}
	}
	a.action=nothing;
	return a;
} // tell someone what you want to do

/*
void phx::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
*/