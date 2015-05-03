#include "tbb.h"
#include <cmath>
#include <iostream>
#include <vector>

Location tbb::emptyFar(int minR,int maxR,int minC,int maxC, SitRep sitrep, int type){
	//returns farthest open space from nearest enemy or crown (0 for enemy, 1 for crown)
	Location dang, temp;
	double dist, maxDist=0;
	if(type==0){ dang=sitrep.nearestEnemy; }
	if(type==1){ dang=sitrep.nearestEnemyCrown; }
	//Go through bounding box and see if the distance from space to nearest enemy is the largest
	for(int i = minR; i <= maxR; i++){
		for(int j = minC; j<=maxC; j++){
			if(sitrep.thing[i][j].what==space){
			//If maxDist hasn't been determined yet, set it as the first space in the box
				if(maxDist==0) maxDist=sqrt((double)((i-dang.r)*(i-dang.r)+(j-dang.c)*(j-dang.c)));
				dist=sqrt((double)((i-dang.r)*(i-dang.r)+(j-dang.c)*(j-dang.c)));
				if(dist>=maxDist){
					temp.r=i;
					temp.c=j;
				}
			}
		}
	}
	return temp;
}
Location tbb::emptyClose(int minR,int maxR,int minC,int maxC, SitRep sitrep, int type){
	Location dang, temp;
	double dist, maxDist=0;
	if(type==0){ dang=sitrep.nearestEnemy; }
	if(type==1){ dang = sitrep.nearestEnemyCrown; }
	//Go through bounding box and see if the distance from space to nearest crown is smallest
	for(int i = minR; i <= maxR; i++){
		for(int j = minC; j<=maxC; j++){
			if(sitrep.thing[i][j].what==space){
			//If maxDist hasn't been determined yet, set it as the first space in the box
				if(maxDist==0) maxDist=sqrt((double)((i-dang.r)*(i-dang.r)+(j-dang.c)*(j-dang.c)));
				dist=sqrt((double)((i-dang.r)*(i-dang.r)+(j-dang.c)*(j-dang.c)));
				if(dist<=maxDist){
					temp.r=i;
					temp.c=j;
				}
			}
		}
	}
	return temp;
}
//Stole these two functions from Dr. Watson - very expensive to run...
bool tbb::localSearch(Dir map[ROWS][COLS], Dir map2[ROWS][COLS],int r, int c, const SitRep& sitrep){
    if(map[r][c]!=none)return false;
    if(sitrep.thing[r][c].what==rock)return false;

    if(r-1>=0  &&map2[r-1][c  ]!=none){map[r][c]=up;return true;}
    if(c+1<COLS&&map2[r  ][c+1]!=none){map[r][c]=rt;return true;}
    if(r+1<ROWS&&map2[r+1][c  ]!=none){map[r][c]=dn;return true;}
    if(c-1>=0  &&map2[r  ][c-1]!=none){map[r][c]=lt;return true;}

    return false;
}
Dir tbb::pathDirFor(int sr, int sc, int er, int ec,const SitRep& sitrep){
    Dir map[ROWS][COLS],map2[ROWS][COLS];

    int i,j;
    bool changes=true;

    for(i=0;i<ROWS;++i){
        for(j=0;j<COLS;++j){
            map[i][j]=none;
            map2[i][j]=none;
        }
    }
    map[er][ec]=rt;
    map2[er][ec]=rt;


    while(changes){
        changes=false;

        for(i=0;i<ROWS;++i){
            for(j=0;j<COLS;++j){
                if(localSearch(map,map2,i,j,sitrep))changes=true;
            }
        }
        for(i=0;i<ROWS;++i){
            for(j=0;j<COLS;++j){
                map2[i][j]=map[i][j];
            }
        }
    }
    return map[sr][sc];
}

bool tbb::hostileUnit(int minR, int maxR, int minC, int maxC, SitRep sitrep, Location initial){
    if(minR<0) minR=0;
    if(maxR>=ROWS) maxR=ROWS-1;
    if(minC<0) minC=0;
    if(maxC>=COLS) maxC=COLS-1;
    for(int i = minR; i <= maxR; i++){
        for(int j=minC;j<=maxC;j++){
            if(sitrep.thing[i][j].what==unit && sitrep.thing[i][j].tla!="tbb"){
                //we found a hostile unit in our midst
                return true;
            }
        }
    }
    return false;
}

Location tbb::unitWithin(int minR,int maxR,int minC,int maxC, SitRep sitrep, Location initial){
    vector<Location> locList;
    if(minR<0) minR=0;
    if(maxR>=ROWS) maxR=ROWS-1;
    if(minC<0) minC=0;
    if(maxC>=COLS) maxC=COLS-1;
    for(int i = minR; i <= maxR; i++){
        for(int j=minC;j<=maxC;j++){
            if(sitrep.thing[i][j].what==unit && sitrep.thing[i][j].tla!="tbb"){
                //we found a hostile unit in our midst...but is it the closest? put it on a list of places to check and find out
                Location q;
                q.r=i;
                q.c=j;
                locList.push_back(q);
            }
        }
    }
    return closest(locList,initial);
}
Location tbb::closest(vector<Location> locList, Location initial){
    Location thisOne = locList[0];
    double minDist=sqrt((thisOne.r-initial.r)*(thisOne.r-initial.r)+(thisOne.c-initial.c)*(thisOne.c-initial.c));
    for(Location i : locList){
        double dist=sqrt((i.r-initial.r)*(i.r-initial.r)+(i.c-initial.c)*(i.c-initial.c));
        if(dist<minDist){
            minDist=dist;
            thisOne=i;
        }
    }
    return thisOne;
}

Location tbb::avgBox(int minR, int maxR, int minC, int maxC){
    Location avg;
    avg.r=(minR+maxR)/2.0;
    avg.c=(minC+maxC)/2.0;
    return avg;
}

Dir tbb::armyDetect(int minR,int maxR,int minC,int maxC, SitRep sitrep){
    //Calculate whether enemy army is generally left, right, above, or below a box
    int numLeft=0, numRight=0, numAb=0, numBel=0;
    //First, calc average location of box
    Location avg=avgBox(minR,maxR,minC,maxC);
    //Then, find num of army to left of, to right of, etc.
    for(int i=0; i < ROWS; i++){
        for(int j=0; j < COLS;j++){
            if(sitrep.thing[i][j].tla!="tbb"){
                if(avg.r-i>0) numAb++;
                else numBel++;
                if(avg.c-j>0) numLeft++;
                else numRight++;
            }
        }
    }

    //Find biggest of nums
    if(numLeft>numRight&&numLeft>numAb&&numLeft>numBel){ armyDir=lt; return armyDir; }
    if(numRight>numAb&&numRight>numBel){ armyDir=rt; return armyDir; }
    if(numAb>numBel){ armyDir=up; return armyDir; }
    armyDir=dn; return armyDir;
}

// place your pieces on the board
void tbb::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
    bodyguard=false;
	static Location crownLoc;
    bool placed = false;
    if(rank==crown){//Place king farthest from enemy direction
        int i,j;
        switch(armyDetect(minR,maxR,minC,maxC,sitrep)){
        case lt: //Army is left of me, place king in middle of far right wall
                 //Iterate from top to bottom starting on maxC (i=cols, j=rows
            for(i=maxC; i>=minC; i--){
                for(j=minR; j<=maxR; j++){
                    if(j>=(avgBox(minR,maxR,minC,maxC).r-1))
                        if(sitrep.thing[j][i].what==space&&!placed){
                            r=j;
                            c=i;
                            placed=true;
                        }
                }
            }
            break;
        case rt: //Iterate from top to bottom starting at minC (i=cols, j=rows
            for(i=minC; i<=maxC; i++){
                for(j=minR; j<=maxR; j++){
                    if(j>=(avgBox(minR,maxR,minC,maxC).r-1))
                        if(sitrep.thing[j][i].what==space&&!placed){
                            r=j;
                            c=i;
                            placed=true;
                        }
                }
            }
            break;
        case up: //Iterate from left to right starting at maxR (i=rows, j=cols
            for(i=maxR; i>=minR; i--){
                for(j=minC; j<=maxC; j++){
                    if(i>=(avgBox(minR,maxR,minC,maxC).c-1))
                        if(sitrep.thing[i][j].what==space&&!placed){
                            r=i;
                            c=j;
                            placed=true;
                        }
                }
            }
            break;
        case dn:
            for(i=minR; i<=maxR; i++){
                for(j=minC; j<=maxC; j++){
                    if(i>=(avgBox(minR,maxR,minC,maxC).c-1))
                        if(sitrep.thing[i][j].what==space&&!placed){
                            r=i;
                            c=j;
                            placed=true;
                        }
                }
            }
            break;
        }

		crownLoc.r=r;
		crownLoc.c=c;
	}
	
    if(rank==knight){//Surround king with knights to defend it then close to enemy
		//find the king
		int i=crownLoc.r;
		int j=crownLoc.c;
		if(i-1>=minR && sitrep.thing[i-1][j].what==space){
			r=i-1;
			c=j;
            dir=up;
            bodyguard = true;
			placed = true;
		}else if(j-1>=minC && sitrep.thing[i][j-1].what==space){
			r=i;
			c=j-1;
            dir=lt;
            bodyguard = true;
			placed = true;
		}else if(i+1<=maxR && sitrep.thing[i+1][j].what==space){
			r=i+1;
			c=j;
            dir=dn;
            bodyguard = true;
			placed = true;
		}else if(j+1<=maxC && sitrep.thing[i][j+1].what==space){
			r=i;
			c=j+1;
            dir=rt;
            bodyguard = true;
			placed = true;
		}
		if(!placed){//get close to enemy crown
			r=emptyClose(minR,maxR,minC,maxC,sitrep,1).r;
			c=emptyClose(minR,maxR,minC,maxC,sitrep,1).c;
            dir=armyDetect(minR,maxR,minC,maxC,sitrep);
			placed = true;
		}
	}
	
    if(rank==archer){//Put archers in corners of crown then align them with enemy king; good luck remembering how it works when you look back at this
        //find the king
		int i=crownLoc.r;
		int j=crownLoc.c;
		if(i-1>=minR && j-1>=minC && sitrep.thing[i-1][j-1].what==space){
			r=i-1;
			c=j-1;
            dir=armyDir;
            bodyguard = true;
			placed = true;
		}else if(i+1<=maxR && j-1>=minC && sitrep.thing[i+1][j-1].what==space){
			r=i+1;
			c=j-1;
            dir=armyDir;
            bodyguard = true;
			placed = true;
		}else if(i+1<=maxR && j+1<=maxC && sitrep.thing[i+1][j+1].what==space){
			r=i+1;
			c=j+1;
            dir=armyDir;
            bodyguard = true;
			placed = true;
		}else if(i-1>=minR && j+1<=maxC && sitrep.thing[i-1][j+1].what==space){
			r=i-1;
            c=j+1;dir=armyDir;
            dir=armyDir;
            bodyguard = true;
			placed = true;
        }
	
        if(!placed){//Line the rest of the archers up 3 rows thick in front of king
            //First, locate the king and place an archer in front of him but back 2 rows (infantry protection)
            Location q;
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    if(sitrep.thing[i][j].rank==crown && sitrep.thing[i][j].tla!="tbb"){
                        q.r=i;
                        q.c=j;
                    }
                }
            }
            switch(armyDetect(minR,maxR,minC,maxC,sitrep)){
            case lt: for(int j=minC+2; j<=maxC && !placed; j++){
                        if(q.r <=maxR && q.r >= minR && sitrep.thing[q.r][j].what==space){
                            r=q.r;
                            c=j;
                            dir=lt;
                            placed = true;
                        }
                        if(q.r-1 <= maxR && q.r-1 >=minR && sitrep.thing[q.r-1][j].what==space){
                            r=q.r-1;
                            c=j;
                            dir=lt;
                            placed = true;
                        }
                        if(q.r+1 <=maxR && q.r+1 >= minR && sitrep.thing[q.r+1][j].what==space){
                            r=q.r+1;
                            c=j;
                            dir=lt;
                            placed = true;
                        }
                     }break;
            case rt: for(int j=maxC-2; j>=minC && !placed; j--){
                    if(q.r <=maxR && q.r >= minR && sitrep.thing[q.r][j].what==space){
                        r=sitrep.nearestEnemyCrown.r;
                        c=j;
                        dir=rt;
                        placed = true;
                    }
                    if(q.r-1 <=maxR && q.r-1 >= minR && sitrep.thing[q.r-1][j].what==space){
                        r=q.r-1;
                        c=j;
                        dir=rt;
                        placed = true;
                    }
                    if(q.r+1 <=maxR && q.r+1 >= minR &&  sitrep.thing[q.r+1][j].what==space){
                        r=q.r+1;
                        c=j;
                        dir=rt;
                        placed = true;
                    }
                 }break;
            case up: for(int i=minR+2; i<=maxR && !placed;i++){
                    if(q.c <=maxC && q.c >= minC && sitrep.thing[i][q.c].what==space){
                        r=i;
                        c=q.c;
                        dir=up;
                        placed = true;
                    }
                    if(q.c-1 <=maxC && q.c-1 >= minC && sitrep.thing[i][q.c-1].what==space){
                        r=i;
                        c=q.c-1;
                        dir=up;
                        placed = true;
                    }
                    if(q.c+1 <=maxC && q.c+1 >= minC && sitrep.thing[i][q.c+1].what==space){
                        r=i;
                        c=q.c+1;
                        dir=up;
                        placed = true;
                    }
                }break;
            case dn: for(int i=maxR-2; i>=minR && !placed;i--){
                    if(q.c <=maxC && q.c >= minC && sitrep.thing[i][q.c].what==space){
                        r=i;
                        c=q.c;
                        dir=dn;
                        placed = true;
                    }
                    if(q.c-1 <=maxC && q.c-1 >= minC && sitrep.thing[i][q.c-1].what==space){
                        r=i;
                        c=q.c-1;
                        dir=dn;
                        placed = true;
                    }
                    if(q.c+1 <=maxC && q.c+1 >= minC && sitrep.thing[i][q.c+1].what==space){
                        r=i;
                        c=q.c+1;
                        dir=dn;
                        placed = true;
                    }
                }break;
            }
        }

        while(!placed){ //inelegant, but just in case of failure of primary methods
            int tr, tc;
            tr=rand()%(maxR-minR+1)+minR;
            tc=rand()%(maxC-minC+1)+minC;
            if(sitrep.thing[tr][tc].what==space){
                r=tr;
                c=tc;
                dir=up;
                placed=true;
            }
        }
    }

    if(rank==infantry){//Surround archers with infantry
        Location q = sitrep.nearestEnemyCrown;
        switch(armyDetect(minR,maxR,minC,maxC,sitrep)){
        case lt: for(int j=minC; j<=maxC && !placed; j++){
                    if(q.r <=maxR && q.r >= minR && sitrep.thing[q.r][j].what==space){
                        r=q.r;
                        c=j;
                        dir=lt;
                        placed = true;
                    }
                    if(q.r-1 <= maxR && q.r-1 >=minR && sitrep.thing[q.r-1][j].what==space){
                        r=q.r-1;
                        c=j;
                        dir=lt;
                        placed = true;
                    }
                    if(q.r+1 <=maxR && q.r+1 >= minR && sitrep.thing[q.r+1][j].what==space){
                        r=q.r+1;
                        c=j;
                        dir=lt;
                        placed = true;
                    }
                 }break;
        case rt: for(int j=maxC; j>=minC && !placed; j--){
                if(q.r <=maxR && q.r >= minR && sitrep.thing[q.r][j].what==space){
                    r=sitrep.nearestEnemyCrown.r;
                    c=j;
                    dir=rt;
                    placed = true;
                }
                if(q.r-1 <=maxR && q.r-1 >= minR && sitrep.thing[q.r-1][j].what==space){
                    r=q.r-1;
                    c=j;
                    dir=rt;
                    placed = true;
                }
                if(q.r+1 <=maxR && q.r+1 >= minR &&  sitrep.thing[q.r+1][j].what==space){
                    r=q.r+1;
                    c=j;
                    dir=rt;
                    placed = true;
                }
             }break;
        case up: for(int i=minR; i<=maxR && !placed;i++){
                if(q.c <=maxC && q.c >= minC && sitrep.thing[i][q.c].what==space){
                    r=i;
                    c=q.c;
                    dir=up;
                    placed = true;
                }
                if(q.c-1 <=maxC && q.c-1 >= minC && sitrep.thing[i][q.c-1].what==space){
                    r=i;
                    c=q.c-1;
                    dir=up;
                    placed = true;
                }
                if(q.c+1 <=maxC && q.c+1 >= minC && sitrep.thing[i][q.c+1].what==space){
                    r=i;
                    c=q.c+1;
                    dir=up;
                    placed = true;
                }
            }break;
        case dn: for(int i=maxR; i>=minR && !placed;i--){
                if(q.c <=maxC && q.c >= minC && sitrep.thing[i][q.c].what==space){
                    r=i;
                    c=q.c;
                    dir=dn;
                    placed = true;
                }
                if(q.c-1 <=maxC && q.c-1 >= minC && sitrep.thing[i][q.c-1].what==space){
                    r=i;
                    c=q.c-1;
                    dir=dn;
                    placed = true;
                }
                if(q.c+1 <=maxC && q.c+1 >= minC && sitrep.thing[i][q.c+1].what==space){
                    r=i;
                    c=q.c+1;
                    dir=dn;
                    placed = true;
                }
            }break;
        }
        while(!placed){ //inelegant, but just in case of failure of primary methods
            int tr, tc;
            tr=rand()%(maxR-minR+1)+minR;
            tc=rand()%(maxC-minC+1)+minC;
            if(sitrep.thing[tr][tc].what==space){
                r=tr;
                c=tc;
                dir=up;
                placed=true;
            }
        }
	}
}

// tell someone what you want to do
	Action tbb::Recommendation(SitRep sitrep){
	
    Action a;
    Location crownLoc;
    Location target;
    target.r=0;
    target.c=0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(sitrep.thing[i][j].rank==crown && sitrep.thing[i][j].tla=="tbb"){
                crownLoc.r=i;
                crownLoc.c=j;
            }
        }
    }

    // first, try to attack in front of you
    int tr=r,tc=c;
    if(rank!=archer){
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
        switch(dir){
        case up: for(tr=r-1;tr>=r-3;tr--){
                    for(tc=c-1;tc<=c+1;tc++){
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
                    }
                }break; //not really necessary, but why not?
        case dn: for(tr=r+1;tr<=r+3;tr++){
                for(tc=c-1;tc<=c+1;tc++){
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
                }
            }break;
        case rt: for(tc=c+1;tc<=c+3;tc++){
                for(tr=r-1;tr<=r+1;tr++){
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
                }
            }break;
        case lt: for(tc=c-1;tc>=c-3;tc--){
                for(tr=r-1;tr<=r+1;tr++){
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
                }
            }break;
        case none: break;
        }
    }

    // next, if you are a bodyguard, search for and destroy enemies within area
    if(bodyguard){
        //pursuit (MESSY CODE! Bleh...)
        bool somethingToPursue;
        switch(armyDir){
        case rt: somethingToPursue = hostileUnit(crownLoc.r-6,crownLoc.r+6,crownLoc.c,crownLoc.c+6,sitrep,crownLoc);
                 if(somethingToPursue) target=unitWithin(crownLoc.r-6,crownLoc.r+6,crownLoc.c,crownLoc.c+6,sitrep,crownLoc);break;
        case lt: somethingToPursue = hostileUnit(crownLoc.r-6,crownLoc.r+6,crownLoc.c-6,crownLoc.c,sitrep,crownLoc);
                 if(somethingToPursue)target=unitWithin(crownLoc.r-6,crownLoc.r+6,crownLoc.c-6,crownLoc.c,sitrep,crownLoc);break;
        case up: somethingToPursue = hostileUnit(crownLoc.r-6,crownLoc.r,crownLoc.c-6,crownLoc.c+6,sitrep,crownLoc);
                 if(somethingToPursue)target=unitWithin(crownLoc.r-6,crownLoc.r,crownLoc.c-6,crownLoc.c+6,sitrep,crownLoc);break;
        case dn: somethingToPursue = hostileUnit(crownLoc.r,crownLoc.r+6,crownLoc.c-6,crownLoc.c+6,sitrep,crownLoc);
                 if(somethingToPursue)target=unitWithin(crownLoc.r,crownLoc.r+6,crownLoc.c-6,crownLoc.c+6,sitrep,crownLoc);break;
        }

        if(somethingToPursue){
            //Expensive statement
            target.dirFor=pathDirFor(r,c,target.r,target.c,sitrep);
            if(dir==target.dirFor){
                a.action=fwd;
                a.maxDist=1;
                if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
                return a;
            } else {
                a.action=turn;
                a.dir=target.dirFor;
                return a;
            }
        }
    }

	// there is not an enemy in front of me
    // so head to the crown!
    // FOR SPARTA!
    if(!bodyguard){
        if(dir==sitrep.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=1;
            if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
            return a;
        } else {
            a.action=turn;
            a.dir=sitrep.nearestEnemyCrown.dirFor;
            return a;
        }
    }

	a.action=nothing;
	return a;
}
