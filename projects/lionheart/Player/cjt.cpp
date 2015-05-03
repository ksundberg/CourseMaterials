#include "cjt.h"
#include <cmath>
#include <iostream>


void cjt::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	
	//king's placement
	while (!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		if (sitrep.thing[tr][tc].what == space)done = true;

		if (getRank() == crown){ 
			tr = minR; tc = minC;
		}

			
		//knight's placement
	
	if (getRank() == knight){		
			tr = maxR-4;
			tc = maxC;
			if (sitrep.thing[tr][tc].what == unit){
				tr = maxR-5;
				tc = maxC;
				if (sitrep.thing[tr][tc].what == unit){
					tr = maxR - 5;
					tc = maxC-1;
					if (sitrep.thing[tr][tc].what == unit){
						tr = maxR-4;
						tc = maxC-1;
						if (sitrep.thing[tr][tc].what == unit){
							tr = maxR-6;
							tc = maxC;
							if (sitrep.thing[tr][tc].what == unit){
								tr = maxR - 6;
								tc = maxC-1;
							}
						}
					}
				}
			}
			
		
	}
		//archer placement
		if (getRank() == archer){
			tr = minR;
			tc = maxC;
			if (sitrep.thing[tr][tc].what == unit){
				tr = minR+2 ;
				tc = maxC;
				if (sitrep.thing[tr][tc].what == unit){
					tr = minR+3;
					tc = maxC;
					if (sitrep.thing[tr][tc].what == unit){
						tr = minR+5;
						tc = maxC;
						if (sitrep.thing[tr][tc].what == unit){
							tr = minR+7;
							tc = maxC;
							if (sitrep.thing[tr][tc].what == unit){
								tr = minR+8;
								tc = maxC;
								if (sitrep.thing[tr][tc].what == unit){
									tr = minR+9;
									tc = maxC;
									if (sitrep.thing[tr][tc].what == unit){
										tr = minR+10;
										tc = maxC;
									}
								}
							}
						}
					}
				}
			}
		}

		if (getRank() == infantry){
			tr = minR;
			tc = minC+1;
			if (sitrep.thing[tr][tc].what == unit){
				tr = minR;
				tc = minC+2;
				if (sitrep.thing[tr][tc].what == unit){
					tr = minR;
					tc = minC+3;
					if (sitrep.thing[tr][tc].what == unit){
						tr = minR+1;
						tc = minC;
						if (sitrep.thing[tr][tc].what == unit){
							tr = minR+1;
							tc = minC+1;
							if (sitrep.thing[tr][tc].what == unit){
								tr = minR + 1;
								tc = minC+2;
								if (sitrep.thing[tr][tc].what == unit){
									tr = minR + 1;
									tc = minC+3;
									if (sitrep.thing[tr][tc].what == unit){
										tr = minR + 2;
										tc = minC;
										if (sitrep.thing[tr][tc].what == unit){
											tr = minR + 2;
											tc = minC+1;
											if (sitrep.thing[tr][tc].what == unit){
												tr = minR +2;
												tc = minC+2;
												if (sitrep.thing[tr][tc].what == unit){
													tr = minR + 2;
													tc = minC+3;
													if (sitrep.thing[tr][tc].what == unit){
														tr = minR + 3;
														tc = minC;
														if (sitrep.thing[tr][tc].what == unit){
															tr = minR + 3;
															tc = minC+1;
														}
													}
												}

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} // end of while loop


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


// tell someone what you want to do
Action cjt::Recommendation(SitRep sitrep){
	
	
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
	//Everyone tries to attack except the king
	if(getRank()!=crown&&tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit){
			if(sitrep.thing[tr][tc].tla!=tla){
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
		//if no unit in front of you
		else{
			//archers don't move position
			if (getRank() == archer){
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = nothing;
				}
				else{
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
			//knights move behind enemy lines
			if (getRank() == knight){
				if (dir == sitrep.anyOpenSpace){
					a.action = fwd;
					a.maxDist = HORSESPEED;
				}
			}

		}
	}	
	//kings movement patterns
	else if (getRank() == crown) {		
		if (getDir() != up){
			a.action = turn;
			a.dir = up;
			return a;
		}
		else{ 
			a.action = nothing;
			return a;
		}
	}
	if (getRank() == crown){
		a.action = nothing;
		return a;
	}
	
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor){
		if (getRank() == archer){ 			
			a.action = nothing; return a;
		}
		else{
			a.action = fwd;
			a.maxDist = 1;
			if (rank == knight || rank == crown)a.maxDist = HORSESPEED;
			return a;
		}
	}
	else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}

