#include "tgy.h"
#include "lionheart2.h"
#include <cmath>
#include <iostream>
#include <string>
//#include <windows.h>

using namespace std;

int tgy::side = 0;
int * tgy::kingHp = 0;
int * tgy::squireHp = 0;
bool * tgy::lastDead = 0;
int tgy::flagForDeath = 0;
int tgy::loadingFlag = 0;
int tgy::klr = 0;
int tgy::klc = 0;

//Place functions
void tgy::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
    int m;
    m = idMap(sitrep);
    if(CHEAT == 0) {
        switch(m) {
        case 1:
            map1(minR, maxR, minC, maxC, sitrep);
            break;
        case 2:
            map2(minR, maxR, minC, maxC, sitrep);
            break;
        case 3:
            map3(minR, maxR, minC, maxC, sitrep);
            break;
        case 4:
            map4(minR, maxR, minC, maxC, sitrep);
            break;
        default:
            defMap(minR, maxR, minC, maxC, sitrep);
            break;
        }
    } else {
        if(loadingFlag == 0) {
            loadingFlag = 1;
            loading();
        }
        trollPlace(minR, maxR, minC, maxC, sitrep);
    }

}

void tgy::trollPlace(int minR, int maxR, int minC, int maxC, SitRep &sitrep) {
    bool done=false;
	int tr,tc;
	Dir td;
	if(rank == crown) {
        kingHp = &hp;
	} else {
	    squireHp = &hp;
        if(flagForDeath == 1) {
            *lastDead = 1;
        }
        lastDead = &dead;
        flagForDeath = 1;
	}
	if(rank == crown) {
        r = maxR / 2;
        c = maxC / 2;
	}
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

void tgy::map1(int minR,int maxR,int minC,int maxC, SitRep &sitrep) {
    int i, j, tc, tr;
    Location l;
    bool done=false;
	Dir td;
    float f1, f2;
    l.r = minR;
    l.c = minC;
    f1 = getDist(l.r, l.c, 14, 0);
    f2 = getDist(l.r, l.c, 14, COLS);
    if(f1 < f2 && side == 0) {
        side = 1;
        //The army spawned on the left side of the map.
    } else if(f2 > f1 && side == 0) {
        side = 2;
        //The army spawned on the right side of the map.
    }
    if(rank == crown) {
        if(side == 1) {
            r = 6;
            c = 2;
            dir = dn;
        } else {
            r = 23;
            c = 27;
            dir = up;
        }
    } else if(rank == infantry) {
        if(side == 1) {
            //1
            if(sitrep.thing[9][13].what == space) {
                r = 9;
                c = 13;
                dir = dn;
                return;
            }
            //2
            if(sitrep.thing[10][12].what == space) {
                r = 10;
                c = 12;
                dir = rt;
                return;
            }
            //3
            if(sitrep.thing[11][13].what == space) {
                r = 11;
                c = 13;
                dir = up;
                return;
            }
            //4
            if(sitrep.thing[13][13].what == space) {
                r = 13;
                c = 13;
                dir = dn;
                return;
            }
            //5
            if(sitrep.thing[14][12].what == space) {
                r = 14;
                c = 12;
                dir = rt;
                return;
            }
            //6
            if(sitrep.thing[15][12].what == space) {
                r = 15;
                c = 12;
                dir = rt;
                return;
            }
            //7
            if(sitrep.thing[16][13].what == space) {
                r = 16;
                c = 13;
                dir = up;
                return;
            }
            //8
            if(sitrep.thing[18][13].what == space) {
                r = 18;
                c = 13;
                dir = dn;
                return;
            }
            //9
            if(sitrep.thing[19][12].what == space) {
                r = 19;
                c = 12;
                dir = rt;
                return;
            }
            //10
            if(sitrep.thing[20][13].what == space) {
                r = 20;
                c = 13;
                dir = up;
                return;
            }
            //11
            if(sitrep.thing[10][11].what == space) {
                r = 10;
                c = 11;
                dir = rt;
                return;
            }
            //12
            if(sitrep.thing[14][11].what == space) {
                r = 14;
                c = 11;
                dir = rt;
                return;
            }
            //13
            if(sitrep.thing[15][11].what == space) {
                r = 15;
                c = 11;
                dir = rt;
                return;
            }
            //14
            if(sitrep.thing[19][11].what == space) {
                r = 19;
                c = 11;
                dir = rt;
                return;
            }
            //15
            if(sitrep.thing[14][10].what == space) {
                r = 14;
                c = 10;
                dir = rt;
                return;
            }
        } else {
            //1
            if(sitrep.thing[9][16].what == space) {
                r = 9;
                c = 16;
                dir = dn;
                return;
            }
            //2
            if(sitrep.thing[10][17].what == space) {
                r = 10;
                c = 17;
                dir = lt;
                return;
            }
            //3
            if(sitrep.thing[11][16].what == space) {
                r = 11;
                c = 16;
                dir = up;
                return;
            }
            //4
            if(sitrep.thing[13][16].what == space) {
                r = 13;
                c = 16;
                dir = dn;
                return;
            }
            //5
            if(sitrep.thing[14][17].what == space) {
                r = 14;
                c = 17;
                dir = lt;
                return;
            }
            //6
            if(sitrep.thing[15][17].what == space) {
                r = 15;
                c = 17;
                dir = lt;
                return;
            }
            //7
            if(sitrep.thing[16][16].what == space) {
                r = 16;
                c = 16;
                dir = up;
                return;
            }
            //8
            if(sitrep.thing[18][16].what == space) {
                r = 18;
                c = 16;
                dir = dn;
                return;
            }
            //9
            if(sitrep.thing[19][17].what == space) {
                r = 19;
                c = 17;
                dir = lt;
                return;
            }
            //10
            if(sitrep.thing[20][16].what == space) {
                r = 20;
                c = 16;
                dir = up;
                return;
            }
            //11
            if(sitrep.thing[10][18].what == space) {
                r = 10;
                c = 18;
                dir = lt;
                return;
            }
            //12
            if(sitrep.thing[14][18].what == space) {
                r = 14;
                c = 18;
                dir = lt;
                return;
            }
            //13
            if(sitrep.thing[15][18].what == space) {
                r = 15;
                c = 18;
                dir = lt;
                return;
            }
            if(sitrep.thing[19][18].what == space) {
                r = 19;
                c = 18;
                dir = lt;
                return;
            }
            //15
            if(sitrep.thing[14][19].what == space) {
                r = 14;
                c = 19;
                dir = lt;
                return;
            }
        }
    } else if(rank == archer) {
        if(side == 1) {
            //1
            if(sitrep.thing[8][13].what == space) {
                r = 8;
                c = 13;
                dir = rt;
                return;
            }
            //2
            if(sitrep.thing[12][13].what == space) {
                r = 12;
                c = 13;
                dir = rt;
                return;
            }
            //3
            if(sitrep.thing[17][13].what == space) {
                r = 17;
                c = 13;
                dir = rt;
                return;
            }
            //4
            if(sitrep.thing[21][13].what == space) {
                r = 21;
                c = 13;
                dir = rt;
                return;
            }
            //5
            if(sitrep.thing[9][12].what == space) {
                r = 9;
                c = 12;
                dir = rt;
                return;
            }
            //6
            if(sitrep.thing[13][12].what == space) {
                r = 13;
                c = 12;
                dir = rt;
                return;
            }
            //7
            if(sitrep.thing[16][12].what == space) {
                r = 16;
                c = 12;
                dir = rt;
                return;
            }
            //8
            if(sitrep.thing[20][12].what == space) {
                r = 20;
                c = 12;
                dir = rt;
                return;
            }
        } else {
        //1
            if(sitrep.thing[8][16].what == space) {
                r = 8;
                c = 16;
                dir = lt;
                return;
            }
            //2
            if(sitrep.thing[12][16].what == space) {
                r = 12;
                c = 16;
                dir = lt;
                return;
            }
            //3
            if(sitrep.thing[17][16].what == space) {
                r = 17;
                c = 16;
                dir = lt;
                return;
            }
            //4
            if(sitrep.thing[21][16].what == space) {
                r = 21;
                c = 16;
                dir = lt;
                return;
            }
            //5
            if(sitrep.thing[9][17].what == space) {
                r = 9;
                c = 17;
                dir = lt;
                return;
            }
            //6
            if(sitrep.thing[13][17].what == space) {
                r = 13;
                c = 17;
                dir = lt;
                return;
            }
            //7
            if(sitrep.thing[16][17].what == space) {
                r = 16;
                c = 17;
                dir = lt;
                return;
            }
            //8
            if(sitrep.thing[20][17].what == space) {
                r = 20;
                c = 17;
                dir = lt;
                return;
            }
        }
    } else if(rank == knight) {
        if(side == 1) {
            //1
            if(sitrep.thing[6][13].what == space) {
                r = 6;
                c = 13;
                dir = dn;
                return;
            }
            //2
            if(sitrep.thing[7][12].what == space) {
                r = 7;
                c = 12;
                dir = rt;
                return;
            }
            //3
            if(sitrep.thing[7][11].what == space) {
                r = 7;
                c = 11;
                dir = rt;
                return;
            }
            //4
            if(sitrep.thing[23][13].what == space) {
                r = 23;
                c = 13;
                dir = up;
                return;
            }
            //5
            if(sitrep.thing[22][12].what == space) {
                r = 22;
                c = 12;
                dir = rt;
                return;
            }
            //6
            if(sitrep.thing[22][11].what == space) {
                r = 22;
                c = 11;
                dir = rt;
                return;
            }
         } else {
            //1
            if(sitrep.thing[6][16].what == space) {
                r = 6;
                c = 16;
                dir = dn;
                return;
            }
            //2
            if(sitrep.thing[7][17].what == space) {
                r = 7;
                c = 17;
                dir = lt;
                return;
            }
            //3
            if(sitrep.thing[7][18].what == space) {
                r = 7;
                c = 18;
                dir = lt;
                return;
            }
            //4
            if(sitrep.thing[23][16].what == space) {
                r = 23;
                c = 16;
                dir = up;
                return;
            }
            //5
            if(sitrep.thing[22][17].what == space) {
                r = 22;
                c = 17;
                dir = lt;
                return;
            }
            //6
            if(sitrep.thing[22][18].what == space) {
                r = 22;
                c = 18;
                dir = lt;
                return;
            }
        }
    }
}

void tgy::map2(int minR,int maxR,int minC,int maxC, SitRep &sitrep) {
    int i, j, tc, tr;
    Location l;
    float f1, f2;
    l.r = minR;
    l.c = minC;
    f1 = getDist(l.r, l.c, 27, 0);
    f2 = getDist(l.r, l.c, 3, 29);
    if(f1 < f2 && side == 0) {
        side = 1;
        //The army spawned on the left side of the map.
    } else if(f2 > f1 && side == 0) {
        side = 2;
        //The army spawned on the right side of the map.
    }
    if(rank == crown) {
        if(side == 1) {
                r = maxR - 1;
                c = maxC - 1;
                dir = rt;
        } else {
            r = minR;
            c = minC + 1;
            dir = lt;
        }

    } else if(rank == infantry) {
        if(side == 1) {
			i = minR + 3;
			for(j = maxC - 1; j > maxC - 4; j--) {
				if(sitrep.thing[i][j].what == space) {
                        if(i != minR - 1 && j != minC - 1) {
                            r = i;
                            c = j;
							dir = rt;
							return;
                        }
                    }
			}
            i = minR + 4;
                for(j = maxC - 1; j >= minC; j--) {
                    if(sitrep.thing[i][j].what == space) {
                        if(i != minR - 1 && j != minC - 1) {
                            r = i;
                            c = j;
							dir = rt;
							return;
                        }
                    }
                }
            i = minR + 5;
                for(j = maxC - 1; j >= minC + 1; j--) {
                    if(sitrep.thing[i][j].what == space) {
                        if(i != minR - 1 && j != minC - 1) {
                            r = i;
                            c = j;
							dir = rt;
							return;
                        }
                    }
                }
			i = minR + 6;
			for(j = maxC - 1; j > maxC - 5; j--) {
				if(sitrep.thing[i][j].what == space) {
                        if(i != minR - 1 && j != minC - 1) {
                            r = i;
                            c = j;
							dir = rt;
							return;
                        }
				}
			}
        } else {
			i = minR + 3;
			for(j = minC + 1; j < minC + 4; j++) {
				if(sitrep.thing[i][j].what == space) {
                        if(i != minR - 1 && j != minC - 1) {
                            r = i;
                            c = j;
							dir = lt;
							return;
                        }
                    }
			}
			i = minR + 4;
            for(j = minC + 1; j <= maxC; j++) {
                if(sitrep.thing[i][j].what == space) {
                    if(i != minR - 1 && j != minC - 1) {
                        r = i;
                        c = j;
                        dir = lt;
                        return;
                    }
                }
            }
            i = minR + 5;
            for(j = minC + 1; j <= maxC - 1; j++) {
                if(sitrep.thing[i][j].what == space) {
                    if(i != minR - 1 && j != minC - 1) {
                        r = i;
                        c = j;
                        dir = lt;
                        return;
                    }
                }
            }
			i = minR + 6;
			for(j = minC + 1; j < minC + 5; j++) {
				if(sitrep.thing[i][j].what == space) {
                        if(i != minR - 1 && j != minC - 1) {
                            r = i;
                            c = j;
							dir = lt;
							return;
                        }
				}
			}
        }
    } else if(rank == archer) {
		if(side == 1) {
			i = maxR - 3;
			for(j = maxC - 1; j > maxC - 5; j--) {
				if(sitrep.thing[i][j].what == space) {
					r = i;
					c = j;
					dir = rt;
					return;
				}
			}
		    i = minR + 2;
		    for(j = maxC - 1; j > maxC - 6; j--) {
				if(sitrep.thing[i][j].what == space) {
					r = i;
					c = j;
					dir = rt;
					return;
            }
        }

        } else {
			i = maxR - 3;
            for(j = minC + 1; j < minC + 5; j++) {
                if(sitrep.thing[i][j].what == space) {
                    r = i;
                    c = j;
					dir = lt;
					return;
                }
            }
            i = minR + 2;
            for(j = minC + 1; j < minC + 5; j++) {
                if(sitrep.thing[i][j].what == space) {
                    r = i;
                    c = j;
					dir = lt;
					return;
                }
            }

        }
    } else if(rank == knight) {
        if(side == 1) {
            i = maxR - 2;
            for(j = maxC - 1; j > maxC - 4; j--) {
                if(sitrep.thing[i][j].what == space) {
                    r = i;
                    c = j;
					dir = rt;
					return;
                }
            }
            i = minR + 1;
            for(j = maxC - 1; j > maxC - 4; j--) {
                if(sitrep.thing[i][j].what == space) {
                    r = i;
                    c = j;
					dir = rt;
					return;
                }
            }

        } else {
            i = maxR - 2;
            for(j = minC + 1; j < minC + 4; j++) {
                if(sitrep.thing[i][j].what == space) {
                    r = i;
                    c = j;
					dir = lt;
					return;
                }
            }
            i = minR + 1;
            for(j = minC + 1; j < minC + 4; j++) {
                if(sitrep.thing[i][j].what == space) {
                    r = i;
                    c = j;
					dir = lt;
					return;
                }
            }

        }
	}
}

void tgy::map3(int minR,int maxR,int minC,int maxC, SitRep &sitrep) {
    int i, j, tc, tr;
    Location l;
    bool done=false;
	Dir td;
    float f1, f2;
    l.r = minR;
    l.c = minC;
    f1 = getDist(l.r, l.c, 14, 0);
    f2 = getDist(l.r, l.c, 14, COLS);
    if(f1 < f2 && side == 0) {
        side = 1;
        //The army spawned on the left side of the map.
    } else if(f2 > f1 && side == 0) {
        side = 2;
        //The army spawned on the right side of the map.
    }
    if(rank == crown) {
        if(side == 1) {
            if(sitrep.thing[13][4].what == space) {
                r = 13;
                c = 4;
                dir = rt;
                return;
            }
        } else {
            if(sitrep.thing[13][25].what == space) {
                r = 13;
                c = 25;
                dir = lt;
                return;
            }
        }
    } else if(rank == archer) {
        if(side == 1) {
            //1
            if(sitrep.thing[10][6].what == space) {
                    r = 10;
                    c = 6;
                    dir = up;
                    return;
            }
            //2
            if(sitrep.thing[10][7].what == space) {
                    r = 10;
                    c = 7;
                    dir = up;
                    return;
            }
            //3
            if(sitrep.thing[11][7].what == space) {
                    r = 11;
                    c = 7;
                    dir = rt;
                    return;
            }
            //4
            if(sitrep.thing[12][7].what == space) {
                    r = 12;
                    c = 7;
                    dir = rt;
                    return;
            }
            //5
            if(sitrep.thing[17][7].what == space) {
                    r = 17;
                    c = 7;
                    dir = rt;
                    return;
            }
            //6
            if(sitrep.thing[18][7].what == space) {
                    r = 18;
                    c = 7;
                    dir = rt;
                    return;
            }
            //7
            if(sitrep.thing[19][7].what == space) {
                    r = 19;
                    c = 7;
                    dir = dn;
                    return;
            }
            //8
            if(sitrep.thing[19][6].what == space) {
                    r = 19;
                    c = 6;
                    dir = dn;
                    return;
            }
        } else {
            //1
            if(sitrep.thing[10][23].what == space) {
                    r = 10;
                    c = 23;
                    dir = up;
                    return;
            }
            //2
            if(sitrep.thing[10][22].what == space) {
                    r = 10;
                    c = 22;
                    dir = up;
                    return;
            }
            //3
            if(sitrep.thing[11][22].what == space) {
                    r = 11;
                    c = 22;
                    dir = lt;
                    return;
            }
            //4
            if(sitrep.thing[12][22].what == space) {
                    r = 12;
                    c = 22;
                    dir = lt;
                    return;
            }
            //5
            if(sitrep.thing[17][22].what == space) {
                    r = 17;
                    c = 22;
                    dir = lt;
                    return;
            }
            //6
            if(sitrep.thing[18][22].what == space) {
                    r = 18;
                    c = 22;
                    dir = lt;
                    return;
            }
            //7
            if(sitrep.thing[19][22].what == space) {
                    r = 19;
                    c = 22;
                    dir = dn;
                    return;
            }
            //8
            if(sitrep.thing[19][23].what == space) {
                    r = 19;
                    c = 23;
                    dir = dn;
                    return;
            }
        }
    } else if(rank == knight) {
        if(side == 1) {
            //1
            if(sitrep.thing[11][3].what == space) {
                r = 11;
                c = 3;
                dir = dfd = up;
                return;
            }
            //2
            if(sitrep.thing[12][4].what == space) {
                    r = 12;
                    c = 4;
                    dir = dfd = up;
                    return;
            }
            //3
            if(sitrep.thing[11][5].what == space) {
                    r = 11;
                    c = 5;
                    dir = up;
                    return;
            }
            //4
            if(sitrep.thing[18][3].what == space) {
                    r = 18;
                    c = 3;
                    dir = dfd = dn;
                    return;
            }
            //5
            if(sitrep.thing[17][4].what == space) {
                    r = 17;
                    c = 4;
                    dir = dfd = dn;
                    return;
            }
            //6
            if(sitrep.thing[18][5].what == space) {
                    r = 18;
                    c = 5;
                    dir = dfd = dn;
                    return;
            }
        } else {
            //1
            if(sitrep.thing[11][24].what == space) {
                r = 11;
                c = 24;
                dir = dfd = up;
                return;
            }
            //2
            if(sitrep.thing[12][25].what == space) {
                    r = 12;
                    c = 25;
                    dir = dfd = up;
                    return;
            }
            //3
            if(sitrep.thing[11][26].what == space) {
                    r = 11;
                    c = 26;
                    dir = dfd = up;
                    return;
            }
            //4
            if(sitrep.thing[18][24].what == space) {
                    r = 18;
                    c = 24;
                    dir = dfd = dn;
                    return;
            }
            //5
            if(sitrep.thing[17][25].what == space) {
                    r = 17;
                    c = 25;
                    dir = dfd = dn;
                    return;
            }
            //6
            if(sitrep.thing[18][26].what == space) {
                    r = 18;
                    c = 26;
                    dir = dfd = dn;
                    return;
            }
        }
    } else if(rank == infantry) {
        if(side == 1) {
            //1
            if(sitrep.thing[10][3].what == space) {
                        r = 10;
                        c = 3;
                        dir = rt;
                        return;
            }
            //2
            if(sitrep.thing[11][4].what == space) {
                        r = 11;
                        c = 4;
                        dir = up;
                        return;
            }
            //3
            if(sitrep.thing[10][5].what == space) {
                        r = 10;
                        c = 5;
                        dir = lt;
                        return;
            }
            //4
            if(sitrep.thing[19][3].what == space) {
                    r = 19;
                    c = 3;
                    dir = rt;
                    return;
            }
            //5
            if(sitrep.thing[18][4].what == space) {
                    r = 18;
                    c = 4;
                    dir = dn;
                    return;
            }
            //6
            if(sitrep.thing[19][5].what == space) {
                    r = 19;
                    c = 5;
                    dir = lt;
                    return;
            }
            //7
            if(sitrep.thing[13][7].what == space) {
                    r = 13;
                    c = 7;
                    dir = dn;
                    return;
            }
            //8
            if(sitrep.thing[13][6].what == space) {
                    r = 13;
                    c = 6;
                    dir = rt;
                    return;
            }
            //9
            if(sitrep.thing[16][7].what == space) {
                    r = 16;
                    c = 7;
                    dir = up;
                    return;
            }
            //10
            if(sitrep.thing[16][6].what == space) {
                    r = 16;
                    c = 6;
                    dir = rt;
                    return;
            }
            //11, 12, 13
            for(i = 4; i < 7; i++) {
                if(sitrep.thing[14][i].what == space) {
                    r = 14;
                    c = i;
                    dir = rt;
                    return;
                }
            }
            //14, 15
            for(i = 5; i < 7; i++) {
                if(sitrep.thing[15][i].what == space) {
                    r = 15;
                    c = i;
                    dir = rt;
                    return;
                }
            }
        } else {
            //1
            if(sitrep.thing[10][24].what == space) {
                        r = 10;
                        c = 24;
                        dir = rt;
                        return;
            }
            //2
            if(sitrep.thing[11][25].what == space) {
                        r = 11;
                        c = 25;
                        dir = up;
                        return;
            }
            //3
            if(sitrep.thing[10][26].what == space) {
                        r = 10;
                        c = 26;
                        dir = lt;
                        return;
            }
            //4
            if(sitrep.thing[19][26].what == space) {
                    r = 19;
                    c = 26;
                    dir = lt;
                    return;
            }
            //5
            if(sitrep.thing[18][25].what == space) {
                    r = 18;
                    c = 25;
                    dir = dn;
                    return;
            }
            //6
            if(sitrep.thing[19][24].what == space) {
                    r = 19;
                    c = 24;
                    dir = rt;
                    return;
            }
            //7
            if(sitrep.thing[13][22].what == space) {
                    r = 13;
                    c = 22;
                    dir = dn;
                    return;
            }
            //8
            if(sitrep.thing[13][23].what == space) {
                    r = 13;
                    c = 23;
                    dir = lt;
                    return;
            }
            //9
            if(sitrep.thing[16][22].what == space) {
                    r = 16;
                    c = 22;
                    dir = up;
                    return;
            }
            //10
            if(sitrep.thing[16][23].what == space) {
                    r = 16;
                    c = 23;
                    dir = lt;
                    return;
            }
            //11, 12, 13
            for(i = 23; i < 26; i++) {
                if(sitrep.thing[14][i].what == space) {
                    r = 14;
                    c = i;
                    dir = lt;
                    return;
                }
            }
            //14, 15
            for(i = 23; i < 26; i++) {
                if(sitrep.thing[15][i].what == space) {
                    r = 15;
                    c = i;
                    dir = lt;
                    return;
                }
            }
        }
    }
}

void tgy::map4(int minR,int maxR,int minC,int maxC, SitRep &sitrep) {
    int i, j, tc, tr;
    Location l;
    bool done=false;
	Dir td;
    float f1, f2;
    l.r = minR;
    l.c = minC;
    f1 = getDist(l.r, l.c, 0, 14);
    f2 = getDist(l.r, l.c, ROWS, 14);
    if(f1 < f2 && side == 0) {
        side = 1;
        //The army spawned on the left side of the map.
    } else if(f2 > f1 && side == 0) {
        side = 2;
        //The army spawned on the right side of the map.
    }
    if(rank == crown) {
        if(side == 1) {
            dir = dn;
            if(sitrep.thing[0][15].what == space) {
                r = 0;
                c = 15;
                return;
            }
        } else {
            dir = up;
            if(sitrep.thing[29][15].what == space) {
                r = 29;
                c = 15;
                return;
            }
        }
    } else if(rank == infantry) {
        if(side == 1) {
            dir = dn;
            for(i = 0; i < 3; i++) {
                for(j = 11; j < 19; j++) {
                    if(sitrep.thing[i][j].what == space) {
                        r = i;
                        c = j;
                        return;
                    }
                }
            }
        } else {
            dir = up;
            for(i = 27; i < 30; i++) {
                for(j = 11; j < 19; j++) {
                    if(sitrep.thing[i][j].what == space) {
                        r = i;
                        c = j;
                        return;
                    }
                }
            }
        }
    } else if(rank == archer) {
        if(side == 1) {
            dir = dn;
            if(sitrep.thing[1][15].what == space) {
                r = 1;
                c = 15;
                return;
            }
            for(j = 11; j < 19; j++) {
                if(sitrep.thing[0][j].what == space) {
                    r = 0;
                    c = j;
                    return;
                }
            }
        } else {
            dir = up;
            if(sitrep.thing[28][15].what == space) {
                r = 28;
                c = 15;
                return;
            }
            for(j = 11; j < 19; j++) {
                if(sitrep.thing[29][j].what == space) {
                    r = 29;
                    c = j;
                    return;
                }
            }
        }
    } else if(rank == knight) {
        if(side == 1) {
            dir = dn;
            if(sitrep.thing[0][10].what == space) {
                r = 0;
                c = 10;
                return;
            }
            if(sitrep.thing[1][10].what == space) {
                r = 1;
                c = 10;
                return;
            }
            if(sitrep.thing[2][10].what == space) {
                r = 2;
                c = 10;
                return;
            }
            if(sitrep.thing[0][19].what == space) {
                r = 0;
                c = 19;
                return;
            }
            if(sitrep.thing[1][19].what == space) {
                r = 1;
                c = 19;
                return;
            }
            if(sitrep.thing[2][19].what == space) {
                r = 2;
                c = 19;
                return;
            }
        } else {
            dir = up;
            if(sitrep.thing[27][10].what == space) {
                r = 27;
                c = 10;
                return;
            }
            if(sitrep.thing[28][10].what == space) {
                r = 28;
                c = 10;
                return;
            }
            if(sitrep.thing[29][10].what == space) {
                r = 29;
                c = 10;
                return;
            }
            if(sitrep.thing[27][19].what == space) {
                r = 27;
                c = 19;
                return;
            }
            if(sitrep.thing[28][19].what == space) {
                r = 28;
                c = 19;
                return;
            }
            if(sitrep.thing[29][19].what == space) {
                r = 29;
                c = 19;
                return;
            }
        }
    }
}

void tgy::defMap(int minR,int maxR,int minC,int maxC, SitRep &sitrep) {
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


int tgy::idMap(SitRep &sr) {
    int i;
    bool flag;
    flag = true;
    //Check if the map is Navy
    flag = true;
    for(i = 0; i < ROWS; i++) {
        if(sr.thing[0][i].what != rock) {
            flag = false;
            break;
        }
    }
    if(flag == true) {
        return 1;
    }
    //Check if the map is map 2
    flag = true;
    for(i = 0; i < ROWS; i++) {
        if(i == 12 || i == 13 || i == 14 || i == 15 || i == 16 || i == 17) {
            if(sr.thing[13][i].what != rock) {
                flag = false;
                break;
            }
        }
    }
    if(flag == true) {
        return 2;
    }
    //Check if the map is forts
    flag = true;
    for(i = 0; i < ROWS; i++) {
        if(i < 4) {
            if(sr.thing[0][i].what == rock) {
                flag = false;
                break;
            }
        } else if(i < 26) {

            if(sr.thing[0][i].what != rock) {
                flag = false;
                break;
            }
        } else if(i < COLS) {

            if(sr.thing[0][i].what == rock) {
                flag = false;
                break;
            }
        }
    }
    if(flag == true) {
        return 3;
    }
    flag = true;
    for(i = 0; i < ROWS; i++) {
        if(i < 5) {
            if(sr.thing[5][i].what == rock) {
                flag = false;
                break;
            }
        } else if(i < 13) {
            if(sr.thing[5][i].what != rock) {
                flag = false;
                break;
            }
        } else if(i < 17) {
            if(sr.thing[5][i].what == rock) {
                flag = false;
                break;
            }
        } else if(i < 25) {
            if(sr.thing[5][i].what != rock) {
                flag = false;
                break;
            }
        } else if(i < COLS) {
            if(sr.thing[5][i].what == rock) {
                flag = false;
                break;
            }
        }

    }
    if(flag == true) {
        return 4;
    }
    return 5;
}

Action tgy::Recommendation(SitRep sitrep) {
	Action a;
	Location l;
	Dir d;
	int m;
	float f1, f2;
	l.r = getR();
	l.c = getC();
	f1 = getDist(l.r, l.c, 27, 0);
	f2 = getDist(l.r, l.c, 3, 29);
	Rank  enR[4];
	bool options[4] = {0,0,0,0};
	m = idMap(sitrep);
	if(CHEAT == 1) {
        return trollRec(sitrep);
	}
    switch(m) {
    case 1:
        switch(rank) {
        case crown:
            return crownRec1(sitrep);
            break;
        case infantry:
            return infRec1(sitrep);
            break;
        case archer:
            return archRec1(sitrep);
            break;
        case knight:
            return kniRec1(sitrep);
            break;
        }
        break;
    case 2:
        switch(rank) {
        case crown:
            return crownRec2(sitrep);
            break;
        case infantry:
            return infRec2(sitrep);
            break;
        case archer:
            return archRec2(sitrep);
            break;
        case knight:
            return kniRec2(sitrep);
            break;
        }
        break;
    case 3:
        switch(rank) {
        case crown:
            return crownRec3(sitrep);
            break;
        case infantry:
            return infRec3(sitrep);
            break;
        case archer:
            return archRec3(sitrep);
            break;
        case knight:
            return kniRec3(sitrep);
            break;
        }
        break;
    default:
        switch(rank) {
        case crown:
            return crownRec4(sitrep);
            break;
        case infantry:
            return infRec4(sitrep);
            break;
        case archer:
            return archRec4(sitrep);
            break;
        case knight:
            return kniRec4(sitrep);
            break;
        }
        break;
    }
}
//Recommendation functions for map 1.
Action tgy::infRec1(SitRep &sitrep) {
    Action a;
    Location l;
    Dir d;
    int i;
    Rank hr;
    Rank  enR[4];
    bool options[4] = {0,0,0,0};
    int tr=r,tc=c;
    l.r = getR();
    l.c = getC();
    //If an enemy is in front of the unit, it gets attacked.
    switch(dir){
    case up: tr--; break;
    case dn: tr++; break;
    case rt: tc++; break;
    case lt: tc--; break;
    case none: break;
    }
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
            if(sitrep.thing[tr][tc].tla!="tgy"){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }
    }
    //Otherwise, if there is a unit next to the unit, it turns to attack it.
    if(getDist(sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, l.r, l.c) == 1) {
        d = pathDir(l.r, l.c, sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, sitrep, lt);
        if(dir != d) {
            a.action = turn;
            a.dir = d;
            return a;
        }
    }
    if(side == 1) {
        if(l.r == 9 && l.c == 13) {
            if(dir != rt) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 10 && l.c == 12) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 11 && l.c == 13) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 13 && l.c == 13) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 14 && l.c == 12) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 15 && l.c == 12) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 16 && l.c == 13) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 18 && l.c == 13) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 19 && l.c == 12) {
            if(dir != dn) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 20 && l.c == 13) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(dir != rt) {
            a.action = turn;
            a.dir = rt;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
    //Side 2
    } else{
        if(l.r == 9 && l.c == 16) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 10 && l.c == 17) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 11 && l.c == 16) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 13 && l.c == 16) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 14 && l.c == 17) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 15 && l.c == 17) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 16 && l.c == 16) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 18 && l.c == 16) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 19 && l.c == 17) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 20 && l.c == 16) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(dir != lt) {
            a.action = turn;
            a.dir = lt;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
    }
}

Action tgy::archRec1(SitRep &sitrep) {
    Action a;
	Location l;
	int i, j;
	bool flag;
	int ar, ac;
	Rank hr, tr;
	int sr, sc, er, ec;
	l.r = getR();
	l.c = getC();
	hr = knight;
	bool dirs[5] = {false, false, false, false, false};
	Dir d;
	if(detectEnemies(sitrep, dir, l)) {
        dirs[0] = true;
	} else {
        dirs[0] = false;
	}
	if(detectEnemies(sitrep, up, l)) {
        dirs[1] = true;
	} else {
        dirs[1] = false;
	}
	if(detectEnemies(sitrep, dn, l)) {
        dirs[2] = true;
	} else {
        dirs[2] = false;
	}
	if(detectEnemies(sitrep, lt, l)) {
        dirs[3] = true;
	} else {
        dirs[3] = false;
	}
	if(detectEnemies(sitrep, rt, l)) {
        dirs[4] = true;
	} else {
        dirs[4] = false;
	}

	//If there is something in range in the direction the archer is pointing, shoot it.
	//If there are multiple targets, shoot the crown first, the archers second, the infantry third, and the knights last.
	if(dirs[0]) {
        switch(dir){
        case up:
            sr = l.r - 3;
            er = l.r - 1;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case dn:
            sr = l.r + 1;
            er = l.r + 3;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case lt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c - 3;
            ec = l.c - 1;
            break;
        case rt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c + 1;
            ec = l.c + 3;
            break;
    }
    if(sr<0)sr=0;if(er>=ROWS)er=ROWS-1;
    if(sc<0)sc=0;if(ec>=COLS)ec=COLS-1;
	for(i = sr; i < er; i++) {
        for(j = sc; j < ec; j++) {
            if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].tla != tla) {
                tr = sitrep.thing[i][j].rank;
                switch(tr) {
                case knight:
                    if(hr == knight) {
                        ar = i;
                        ac = j;
                    }
                    break;
                case infantry:
                    if(hr == knight) {
                        hr = infantry;
                        ar = i;
                        ac = j;
                        break;
                    }
                case archer:
                    if(hr == infantry || hr == knight) {
                        hr = archer;
                        ar = i;
                        ac = j;
                        break;
                    }
                case crown:
                    hr = crown;
                    ar = i;
                    ac = j;
                    break;
                }
            }
        }
	}
    ar = i;
    ac = j;
    a.action = attack;
    a.ar = ar;
    a.ac = ac;
    return a;
	}

	//If there is something in range above the archer, turn to attack it.
	hr = knight;
	flag = false;
    if(dirs[1]) {
        flag = true;
        tr = highRank(sitrep, up, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = up;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = up;
            }
            break;
        case crown:
            hr = crown;
            d = up;
            break;
        }
    }
    if(dirs[2]) {
        flag = true;
        tr = highRank(sitrep, dn, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = dn;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = dn;
            }
            break;
        case crown:
            hr = crown;
            d = dn;
            break;
        }
    }
    if(dirs[3]) {
        flag = true;
        tr = highRank(sitrep, lt, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = lt;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = lt;
            }
            break;
        case crown:
            hr = crown;
            d = lt;
            break;
        }

    }
    if(dirs[4]) {
        flag = true;
        tr = highRank(sitrep, rt, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = rt;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = rt;
            }
            break;
        case crown:
            hr = crown;
            d = rt;
            break;
        }
    }
    if(flag) {
        a.action = turn;
        a.dir = d;
        return a;
    }
    if(side == 1) {
        if(dir != rt) {
            a.action = turn;
            a.dir = rt;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
    } else {
        if(dir != lt) {
            a.action = turn;
            a.dir = lt;
            return a;
        } else {
            a.action = nothing;
            return a;
        }
    }
}

Action tgy::kniRec1(SitRep &sitrep) {
    Action a;
    Location l;
    Dir d;
    int i;
    Rank hr;
    Rank  enR[4];
    bool options[4] = {0,0,0,0};
    int tr=r,tc=c;
    l.r = getR();
    l.c = getC();
    //If an enemy is in front of the unit, it gets attacked.
    switch(dir){
    case up: tr--; break;
    case dn: tr++; break;
    case rt: tc++; break;
    case lt: tc--; break;
    case none: break;
    }
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
            if(sitrep.thing[tr][tc].tla!="tgy"){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }
    }
    //Otherwise, if there is a unit next to the unit, it turns to attack it.
    if(getDist(sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, l.r, l.c) == 1) {
        d = pathDir(l.r, l.c, sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, sitrep, lt);
        if(dir != d) {
            a.action = turn;
            a.dir = d;
            return a;
        }
    }
    if(side == 1) {
        if(l.r == 6 && l.c == 13) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 7 && l.c == 12) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 22 && l.c == 12) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 23 && l.c == 13) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(dir != rt) {
            a.action = turn;
            a.dir = rt;
        } else {
            a.action = fwd;
            return a;
        }
    } else {
        if(l.r == 6 && l.c == 16) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 7 && l.c == 17) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 22 && l.c == 17) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 23 && l.c == 16) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(dir != lt) {
            a.action = turn;
            a.dir = lt;
        } else {
            a.action = fwd;
            return a;
        }
    }
}

Action tgy::crownRec1(SitRep &sitrep) {
    Action a;
    Location l;
    int m;
    l.r = getR();
    l.c = getC();
    if(side == 1) {
        if(dir == dn) {
            if(l.r != 27 || l.c != 2) {
                a.action = fwd;
                a.maxDist = 5;
                return a;
            } else {
                a.action = turn;
                a.dir = up;
                return a;
            }
        } else {
            if(l.r != 6 ||
                l.c != 2) {
                a.action = fwd;
                a.maxDist = 5;
                return a;
            } else {
                a.action = turn;
                a.dir = dn;
                return a;
            }
        }
    } else {
        if(dir == dn) {
        if(l.r != 27 || l.c != 28) {
            a.action = fwd;
            a.maxDist = 5;
            return a;
        } else {
            a.action = turn;
            a.dir = up;
            return a;
        }
    } else {
        if(l.r != 6 ||
            l.c != 2) {
            a.action = fwd;
            a.maxDist = 5;
            return a;
        } else {
            a.action = turn;
            a.dir = dn;
            return a;
        }
    }
    }
}

//Recommendation functions for map 2.

//Infantry recommendations
Action tgy::infRec2(SitRep &sitrep){
        Action a;
        Location l;
        Dir d;
        int i;
        Rank hr;
        Rank  enR[4];
        bool options[4] = {0,0,0,0};
        int tr=r,tc=c;
        l.r = getR();
        l.c = getC();
        //If an enemy is in front of the unit, it gets attacked.
        switch(dir){
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
        }

        if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
            if(sitrep.thing[tr][tc].what==unit){
                if(sitrep.thing[tr][tc].tla!="tgy"){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
            }
        }
        //Otherwise, if there is a unit next to the unit, it turns to attack it.
        if(getDist(sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, l.r, l.c) == 1) {
            d = pathDir(l.r, l.c, sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, sitrep, lt);
            if(dir != d) {
                a.action = turn;
                a.dir = d;
                return a;
            }
		}
        if(side == 1 && dir != rt && (l.r != 13 && l.c != 11) && (l.r != 10 && l.c != 11)) {
            a.action = turn;
            a.dir = rt;
            return a;
        } else if (side == 2 && dir != lt && (l.r != 13 && l.c != 18) && (l.r != 16 && l.c != 18)) {
            a.action = turn;
            a.dir = lt;
            return a;
        }
		if((l.r == 13 && l.c == 11) && (dir != dn) && (side == 1)) {
			a.action = turn;
			a.dir = dn;
			return a;
		}
		if((l.r == 14 && l.c == 10) && (dir != rt) && (side == 1)) {
			a.action = turn;
			a.dir = rt;
			return a;
		}
		if((l.r == 15 && l.c == 10) && (dir != rt) && (side == 1)) {
			a.action = turn;
			a.dir = rt;
			return a;
		}
		if((l.r == 16 && l.c == 11) && (dir != up) && (side == 1)) {
			a.action = turn;
			a.dir = up;
			return a;
		}
		if((l.r == 13 && l.c == 18) && (dir != dn) && (side == 2)) {
			a.action = turn;
			a.dir = dn;
			return a;
		}
		if((l.r == 14 && l.c == 19) && (dir != lt) && (side == 2)) {
			a.action = turn;
			a.dir = lt;
			return a;
		}
		if((l.r == 15 && l.c == 19) && (dir != lt) && (side == 2)) {
			a.action = turn;
			a.dir = lt;
			return a;
		}
		if((l.r == 16 && l.c == 18) && (dir != up) && (side == 2)) {
			a.action = turn;
			a.dir = up;
			return a;
        }
		//Go to rally point

		//Side 1
        if(side == 1) {
            if(l.r == 13 && l.c == 11) {
               if(dir != dn) {
                    a.action = turn;
                    a.dir = dn;
                } else {
                    a.action = nothing;
                    return a;
                }
            } else if(l.r == 14 && l.c == 10) {
                if(dir != rt) {
                    a.action = turn;
                    a.dir = rt;
                } else {
                    a.action = nothing;
                    return a;
                }
            } else if(l.r == 15 && l.c == 10) {
                if(dir != rt) {
                    a.action = turn;
                    a.dir = rt;
                } else {
                    a.action = nothing;
                    return a;
                }
            } else if(l.r == 16 && l.c == 11) {
                if(dir != up) {
                    a.action = turn;
                    a.dir = up;
                    return a;
                } else {
                    a.action = nothing;
                    return a;
                }
            } else if(dir != rt) {
                a.action = turn;
                a.dir = rt;
            } else {
                a.action = fwd;
                return a;
            }
        //Side 2
        } else{
            if(l.r == 13 && l.c == 18) {
               if(dir != dn) {
                    a.action = turn;
                    a.dir = dn;
                } else {
                    a.action = nothing;
                    return a;
                }
            } else if(l.r == 14 && l.c == 19) {
                if(dir != lt) {
                    a.action = turn;
                    a.dir = lt;
                } else {
                    a.action = nothing;
                    return a;
                }
            } else if(l.r == 15 && l.c == 19) {
                if(dir != lt) {
                    a.action = turn;
                    a.dir = lt;
                } else {
                    a.action = nothing;
                    return a;
                }
            } else if(l.r == 16 && l.c == 18) {
                if(dir != up) {
                    a.action = turn;
                    a.dir = up;
                    return a;
                } else {
                    a.action = nothing;
                    return a;
                }
            } else if(dir != lt) {
                a.action = turn;
                a.dir = lt;
            } else {
                a.action = fwd;
                return a;
            }
        }
        a.action = nothing;
        return a;
    }

//Archer recommendation and subfunctions.
Action tgy::archRec2(SitRep &sitrep) {
	Action a;
	Location l;
	int i, j;
	bool flag;
	int ar, ac;
	Rank hr, tr;
	int sr, sc, er, ec;
	l.r = getR();
	l.c = getC();
	hr = knight;
	bool dirs[5] = {false, false, false, false, false};
	Dir d;
	if(detectEnemies(sitrep, dir, l)) {
        dirs[0] = true;
	} else {
        dirs[0] = false;
	}
	if(detectEnemies(sitrep, up, l)) {
        dirs[1] = true;
	} else {
        dirs[1] = false;
	}
	if(detectEnemies(sitrep, dn, l)) {
        dirs[2] = true;
	} else {
        dirs[2] = false;
	}
	if(detectEnemies(sitrep, lt, l)) {
        dirs[3] = true;
	} else {
        dirs[3] = false;
	}
	if(detectEnemies(sitrep, rt, l)) {
        dirs[4] = true;
	} else {
        dirs[4] = false;
	}

	//If there is something in range in the direction the archer is pointing, shoot it.
	//If there are multiple targets, shoot the crown first, the archers second, the infantry third, and the knights last.
	if(dirs[0]) {
        switch(dir){
        case up:
            sr = l.r - 3;
            er = l.r - 1;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case dn:
            sr = l.r + 1;
            er = l.r + 3;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case lt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c - 3;
            ec = l.c - 1;
            break;
        case rt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c + 1;
            ec = l.c + 3;
            break;
    }
    if(sr<0)sr=0;if(er>=ROWS)er=ROWS-1;
    if(sc<0)sc=0;if(ec>=COLS)ec=COLS-1;
	for(i = sr; i < er; i++) {
        for(j = sc; j < ec; j++) {
            if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].tla != tla) {
                tr = sitrep.thing[i][j].rank;
                switch(tr) {
                case knight:
                    if(hr == knight) {
                        ar = i;
                        ac = j;
                    }
                    break;
                case infantry:
                    if(hr == knight) {
                        hr = infantry;
                        ar = i;
                        ac = j;
                        break;
                    }
                case archer:
                    if(hr == infantry || hr == knight) {
                        hr = archer;
                        ar = i;
                        ac = j;
                        break;
                    }
                case crown:
                    hr = crown;
                    ar = i;
                    ac = j;
                    break;
                }
            }
        }
	}
    ar = i;
    ac = j;
    a.action = attack;
    a.ar = ar;
    a.ac = ac;
    return a;
	}

	//If there is something in range above the archer, turn to attack it.
	hr = knight;
	flag = false;
    if(dirs[1]) {
        flag = true;
        tr = highRank(sitrep, up, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = up;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = up;
            }
            break;
        case crown:
            hr = crown;
            d = up;
            break;
        }
    }
    if(dirs[2]) {
        flag = true;
        tr = highRank(sitrep, dn, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = dn;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = dn;
            }
            break;
        case crown:
            hr = crown;
            d = dn;
            break;
        }
    }
    if(dirs[3]) {
        flag = true;
        tr = highRank(sitrep, lt, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = lt;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = lt;
            }
            break;
        case crown:
            hr = crown;
            d = lt;
            break;
        }

    }
    if(dirs[4]) {
        flag = true;
        tr = highRank(sitrep, rt, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = rt;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = rt;
            }
            break;
        case crown:
            hr = crown;
            d = rt;
            break;
        }
    }
    if(flag) {
        a.action = turn;
        a.dir = d;
        return a;
    }
    if(side == 1) {
        if(dir != rt) {
            a.action = turn;
            a.dir = rt;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
    } else {
        if(dir != lt) {
            a.action = turn;
            a.dir = lt;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
    }
}

bool tgy::detectEnemies(SitRep &sitrep, Dir d, Location l) {
    int sr, sc, er, ec;
    int i, j;
    bool flag;
    flag = false;
    switch(d){
        case up:
            sr = l.r - 3;
            er = l.r - 1;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case dn:
            sr = l.r + 1;
            er = l.r + 3;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case lt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c - 3;
            ec = l.c - 1;
            break;
        case rt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c + 1;
            ec = l.c + 3;
            break;
	}
	if(sr<0)sr=0;if(er>=ROWS)er=ROWS-1;
    if(sc<0)sc=0;if(ec>=COLS)ec=COLS-1;
	for(i = sr; i < er; i++) {
        for(j = sc; j < ec; j++) {
            if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].tla != "tgy") {
                flag = true;
                return flag;
            }
        }
	}
	return flag;
}

Rank tgy::highRank(SitRep &sitrep, Dir d, Location l) {
    int i, j;
    int sr, sc, er, ec;
    Rank hr, tr;
    switch(d){
        case up:
            sr = l.r - 3;
            er = l.r - 1;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case dn:
            sr = l.r + 1;
            er = l.r + 3;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case lt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c - 3;
            ec = l.c - 1;
            break;
        case rt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c + 1;
            ec = l.c + 3;
            break;
    }
    if(sr<0)sr=0;if(er>=ROWS)er=ROWS-1;
    if(sc<0)sc=0;if(ec>=COLS)ec=COLS-1;
    for(i = sr; i < er; i++) {
        for(j = sc; j < ec; j++) {
            if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].tla != tla) {
                tr = sitrep.thing[i][j].rank;
                switch(tr) {
                case knight:
                    break;
                case infantry:
                    if(hr == knight) {
                        hr = infantry;
                    }
                    break;
                case archer:
                    if(hr == infantry || hr == knight) {
                        hr = archer;
                    }
                    break;
                case crown:
                    hr = crown;
                    break;
                }
            }
        }
    }
    return hr;
}

//Knight Recommendations.
Action tgy::kniRec2(SitRep &sitrep) {
	Action a;
	Dir d;
	Location l, kl;
	int tr, tc;
	l.r = tr = getR();
	l.c = tc = getC();
	kl.r = sitrep.nearestEnemyCrown.r;
	kl.c = sitrep.nearestEnemyCrown.c;

	switch(dir){
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
    }
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
            if(sitrep.thing[tr][tc].tla!="tgy"){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }
    }
    if(side == 1) {
        if(l.c < 12 && l.r < 14) {
            d = pathDir(l.r, l.c, 3, 12, sitrep, up);
        } else if(l.c < 16 && l.r > 14) {
            d = pathDir(l.r, l.c, 26, 16, sitrep, rt);
        } else {
            d = pathDir(l.r, l.c, kl.r, kl.c, sitrep, rt);
        }
    } else {
        if(l.c > 16 && l.r < 16) {
            d = pathDir(l.r, l.c, 3, 12, sitrep, lt);
        } else if(l.c > 12 && l.r > 16) {
            d = pathDir(l.r, l.c, 26, 16, sitrep, dn);
        } else {
            d = pathDir(l.r, l.c, kl.r, kl.c, sitrep, lt);
        }
    }

    if(dir != d) {
        a.action = turn;
        a.dir = d;
        return a;
    } else {
        a.action = fwd;

        return a;
    }
}

//Crown recommendations
Action tgy::crownRec2(SitRep &sitrep) {
    //If the king is in the safe location, he does nothing.
	//Otherwise, he moves to the closest of the two safe locations
    Action a;
	Location l;
	Dir d;
	l.r = getR();
	l.c = getC();
    if((l.r == 27 && l.c == 0) || (l.r == 3 && l.c == 29)) {
			a.action = nothing;
			return a;
		} else if(side == 1) {
			d = pathDir(l.r, l.c, 27, 1, sitrep, rt);
		} else {
			d = pathDir(l.r, l.c, 3, 29, sitrep, rt);
		}
		if(d == getDir()) {
			a.action = fwd;
			return a;
		} else {
			a.action = turn;
			a.dir = d;
			return a;
		}
}

Action tgy::infRec3(SitRep &sitrep) {
    Action a;
    Location l;
    Dir d;
    int i;
    Rank hr;
    Rank  enR[4];
    bool options[4] = {0,0,0,0};
    int tr=r,tc=c;
    l.r = getR();
    l.c = getC();
    //If an enemy is in front of the unit, it gets attacked.
    switch(dir){
    case up: tr--; break;
    case dn: tr++; break;
    case rt: tc++; break;
    case lt: tc--; break;
    case none: break;
    }
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
            if(sitrep.thing[tr][tc].tla!="tgy"){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }
    }
    //Otherwise, if there is a unit next to the unit, it turns to attack it.
    if(getDist(sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, l.r, l.c) == 1) {
        d = pathDir(l.r, l.c, sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, sitrep, lt);
        if(dir != d) {
            a.action = turn;
            a.dir = d;
            return a;
        }
    }
    if(side == 1) {
        if(l.r == 10 && l.c == 3) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 11 && l.c == 4) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 10 && l.c == 5) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 13 && l.c == 7) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 14 && l.c == 6) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 15 && l.c == 6) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 16 && l.c == 7) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 19 && l.c == 3) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 18 && l.c == 4) {
            if(dir != dn) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 19 && l.c == 5) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(dir != rt) {
            a.action = turn;
            a.dir = rt;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
    //Side 2
    } else {
        if(l.r == 10 && l.c == 26) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 11 && l.c == 25) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 10 && l.c == 24) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 13 && l.c == 22) {
            if(dir != dn) {
                a.action = turn;
                a.dir = dn;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 14 && l.c == 23) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 15 && l.c == 23) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 16 && l.c == 22) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 19 && l.c == 26) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 18 && l.c == 25) {
            if(dir != dn) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 19 && l.c == 24) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(dir != lt) {
            a.action = turn;
            a.dir = lt;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
    }
}

Action tgy::archRec3(SitRep &sitrep) {
    Action a;
	Location l;
	int i, j;
	bool flag;
	int ar, ac;
	Rank hr, tr;
	int sr, sc, er, ec;
	l.r = getR();
	l.c = getC();
	hr = knight;
	bool dirs[5] = {false, false, false, false, false};
	Dir d;
	if(detectEnemies(sitrep, dir, l)) {
        dirs[0] = true;
	} else {
        dirs[0] = false;
	}
	if(detectEnemies(sitrep, up, l)) {
        dirs[1] = true;
	} else {
        dirs[1] = false;
	}
	if(detectEnemies(sitrep, dn, l)) {
        dirs[2] = true;
	} else {
        dirs[2] = false;
	}
	if(detectEnemies(sitrep, lt, l)) {
        dirs[3] = true;
	} else {
        dirs[3] = false;
	}
	if(detectEnemies(sitrep, rt, l)) {
        dirs[4] = true;
	} else {
        dirs[4] = false;
	}

	//If there is something in range in the direction the archer is pointing, shoot it.
	//If there are multiple targets, shoot the crown first, the archers second, the infantry third, and the knights last.
	if(dirs[0]) {
        switch(dir){
        case up:
            sr = l.r - 3;
            er = l.r - 1;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case dn:
            sr = l.r + 1;
            er = l.r + 3;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case lt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c - 3;
            ec = l.c - 1;
            break;
        case rt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c + 1;
            ec = l.c + 3;
            break;
    }
    if(sr<0)sr=0;if(er>=ROWS)er=ROWS-1;
    if(sc<0)sc=0;if(ec>=COLS)ec=COLS-1;
	for(i = sr; i < er; i++) {
        for(j = sc; j < ec; j++) {
            if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].tla != tla) {
                tr = sitrep.thing[i][j].rank;
                switch(tr) {
                case knight:
                    if(hr == knight) {
                        ar = i;
                        ac = j;
                    }
                    break;
                case infantry:
                    if(hr == knight) {
                        hr = infantry;
                        ar = i;
                        ac = j;
                        break;
                    }
                case archer:
                    if(hr == infantry || hr == knight) {
                        hr = archer;
                        ar = i;
                        ac = j;
                        break;
                    }
                case crown:
                    hr = crown;
                    ar = i;
                    ac = j;
                    break;
                }
            }
        }
	}
    ar = i;
    ac = j;
    a.action = attack;
    a.ar = ar;
    a.ac = ac;
    return a;
	}

	//If there is something in range above the archer, turn to attack it.
	hr = knight;
	flag = false;
    if(dirs[1]) {
        flag = true;
        tr = highRank(sitrep, up, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = up;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = up;
            }
            break;
        case crown:
            hr = crown;
            d = up;
            break;
        }
    }
    if(dirs[2]) {
        flag = true;
        tr = highRank(sitrep, dn, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = dn;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = dn;
            }
            break;
        case crown:
            hr = crown;
            d = dn;
            break;
        }
    }
    if(dirs[3]) {
        flag = true;
        tr = highRank(sitrep, lt, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = lt;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = lt;
            }
            break;
        case crown:
            hr = crown;
            d = lt;
            break;
        }

    }
    if(dirs[4]) {
        flag = true;
        tr = highRank(sitrep, rt, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = rt;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = rt;
            }
            break;
        case crown:
            hr = crown;
            d = rt;
            break;
        }
    }
    if(flag) {
        a.action = turn;
        a.dir = d;
        return a;
    }
    if(side == 1) {
        if(dir != rt) {
            a.action = turn;
            a.dir = rt;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
    } else {
        if(dir != lt) {
            a.action = turn;
            a.dir = lt;
            return a;
        } else {
            a.action = nothing;
            return a;
        }
    }
}

Action tgy::kniRec3(SitRep &sitrep) {
    Action a;
	Dir d;
	Location l, kl;
	int tr, tc;
	l.r = tr = getR();
	l.c = tc = getC();

	switch(dir){
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
    }
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
            if(sitrep.thing[tr][tc].tla!="tgy"){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }
    }
    if(side == 1) {
        if(l.r == 10 && l.c == 3) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 11 && l.c == 4) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 10 && l.c == 5) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        }
        if(dir != dfd) {
            a.action = turn;
            a.dir = dfd;
            return a;
        }
    } else {
        if(l.r == 10 && l.c == 26) {
            if(dir != rt) {
                a.action = turn;
                a.dir = rt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 11 && l.c == 25) {
            if(dir != up) {
                a.action = turn;
                a.dir = up;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        } else if(l.r == 10 && l.c == 24) {
            if(dir != lt) {
                a.action = turn;
                a.dir = lt;
                return a;
            } else {
                a.action = nothing;
                return a;
            }
        }
        if(dir != dfd) {
            a.action = turn;
            a.dir = dfd;
            return a;
        } else {
            a.action = fwd;
            return a;
        }
        a.action = nothing;
        return a;
    }
}

Action tgy::crownRec3(SitRep &sitrep) {
    Action a;
    a.action = nothing;
    return a;
}

Action tgy::infRec4(SitRep &sitrep) {
    Action a;
    Location l;
    Dir d;
    int i;
    Rank hr;
    Rank  enR[4];
    bool options[4] = {0,0,0,0};
    int tr=r,tc=c;
    l.r = getR();
    l.c = getC();
    //If an enemy is in front of the unit, it gets attacked.
    switch(dir){
    case up: tr--; break;
    case dn: tr++; break;
    case rt: tc++; break;
    case lt: tc--; break;
    case none: break;
    }
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
            if(sitrep.thing[tr][tc].tla!="tgy"){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }
    }
    //Otherwise, if there is a unit next to the unit, it turns to attack it.
    if(getDist(sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, l.r, l.c) == 1) {
        d = pathDir(l.r, l.c, sitrep.nearestEnemy.r, sitrep.nearestEnemy.c, sitrep, lt);
        if(dir != d) {
            a.action = turn;
            a.dir = d;
            return a;
        }
    } else {
        if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
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

Action tgy::archRec4(SitRep &sitrep) {
    Action a;
	Location l;
	int i, j;
	bool flag;
	int ar, ac;
	Rank hr, tr;
	int sr, sc, er, ec;
	l.r = getR();
	l.c = getC();
	hr = knight;
	bool dirs[5] = {false, false, false, false, false};
	Dir d;
	if(detectEnemies(sitrep, dir, l)) {
        dirs[0] = true;
	} else {
        dirs[0] = false;
	}
	if(detectEnemies(sitrep, up, l)) {
        dirs[1] = true;
	} else {
        dirs[1] = false;
	}
	if(detectEnemies(sitrep, dn, l)) {
        dirs[2] = true;
	} else {
        dirs[2] = false;
	}
	if(detectEnemies(sitrep, lt, l)) {
        dirs[3] = true;
	} else {
        dirs[3] = false;
	}
	if(detectEnemies(sitrep, rt, l)) {
        dirs[4] = true;
	} else {
        dirs[4] = false;
	}

	//If there is something in range in the direction the archer is pointing, shoot it.
	//If there are multiple targets, shoot the crown first, the archers second, the infantry third, and the knights last.
	if(dirs[0]) {
        switch(dir){
        case up:
            sr = l.r - 3;
            er = l.r - 1;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case dn:
            sr = l.r + 1;
            er = l.r + 3;
            sc = l.c - 1;
            ec = l.c + 1;
            break;
        case lt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c - 3;
            ec = l.c - 1;
            break;
        case rt:
            sr = l.r - 1;
            er = l.r + 1;
            sc = l.c + 1;
            ec = l.c + 3;
            break;
    }
    if(sr<0)sr=0;if(er>=ROWS)er=ROWS-1;
    if(sc<0)sc=0;if(ec>=COLS)ec=COLS-1;
	for(i = sr; i < er; i++) {
        for(j = sc; j < ec; j++) {
            if(sitrep.thing[i][j].what == unit && sitrep.thing[i][j].tla != tla) {
                tr = sitrep.thing[i][j].rank;
                switch(tr) {
                case knight:
                    if(hr == knight) {
                        ar = i;
                        ac = j;
                    }
                    break;
                case infantry:
                    if(hr == knight) {
                        hr = infantry;
                        ar = i;
                        ac = j;
                        break;
                    }
                case archer:
                    if(hr == infantry || hr == knight) {
                        hr = archer;
                        ar = i;
                        ac = j;
                        break;
                    }
                case crown:
                    hr = crown;
                    ar = i;
                    ac = j;
                    break;
                }
            }
        }
	}
    ar = i;
    ac = j;
    a.action = attack;
    a.ar = ar;
    a.ac = ac;
    return a;
	}

	//If there is something in range above the archer, turn to attack it.
	hr = knight;
	flag = false;
    if(dirs[1]) {
        flag = true;
        tr = highRank(sitrep, up, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = up;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = up;
            }
            break;
        case crown:
            hr = crown;
            d = up;
            break;
        }
    }
    if(dirs[2]) {
        flag = true;
        tr = highRank(sitrep, dn, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = dn;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = dn;
            }
            break;
        case crown:
            hr = crown;
            d = dn;
            break;
        }
    }
    if(dirs[3]) {
        flag = true;
        tr = highRank(sitrep, lt, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = lt;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = lt;
            }
            break;
        case crown:
            hr = crown;
            d = lt;
            break;
        }

    }
    if(dirs[4]) {
        flag = true;
        tr = highRank(sitrep, rt, l);
        switch(tr) {
        case knight:
            break;
        case infantry:
            if(hr == knight) {
                hr = infantry;
                d = rt;
            }
            break;
        case archer:
            if(hr == infantry || hr == knight) {
                hr = archer;
                d = rt;
            }
            break;
        case crown:
            hr = crown;
            d = rt;
            break;
        }
    }
    if(flag) {
        a.action = turn;
        a.dir = d;
        return a;
    }
        if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
}

Action tgy::kniRec4(SitRep &sitrep) {
    Action a;
	Dir d;
	Location l, kl;
	int tr, tc;
	l.r = tr = getR();
	l.c = tc = getC();

	switch(dir){
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
    }
    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
            if(sitrep.thing[tr][tc].tla!="tgy"){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
                return a;
            }
        }
    }
        if(dir==sitrep.nearestEnemy.dirFor){
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
}

Action tgy::trollRec(SitRep &sitrep) {
    Action a;
    int tr=r,tc=c;
    Dir d;
	// first, try to attack in front of you
	if(rank == crown) {
        *squireHp = 100;
        klr = r;
        klc = c;
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
	} else {
        *kingHp = 8651;
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
        d = pathDir(r, c, klr - 1, klc - 1, sitrep, dn);
        if(dir != d) {
            a.action = turn;
            a.dir = d;
            return a;
        } else {
            a.action = fwd;
            return a;
        }

	}
}

Action tgy::crownRec4(SitRep &sitrep) {
    Action a;
    a.action = nothing;
    return a;
}

//Other functions
Dir tgy::pathDir(int sr, int sc, int er, int ec, SitRep &sitrep, Dir d) {
    Dir map[ROWS][COLS],map2[ROWS][COLS];

	int i,j;
	bool changes=true;

	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			map[i][j]=none;
			map2[i][j]=none;
		}
	}
	map[er][ec]=d;
	map2[er][ec]=d;


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

float tgy::getDist(int r,int c,int tr,int tc){
	return sqrt((double)(tr-r)*(tr-r)+(tc-c)*(tc-c));
}

bool tgy::localSearch(Dir map[ROWS][COLS], Dir map2[ROWS][COLS],int r, int c, SitRep &sr){

	if(map[r][c]!=none)return false;
	if(sr.thing[r][c].what==rock)return false;
	if(r-1>=0  &&map2[r-1][c  ]!=none){map[r][c]=up;return true;}
	if(c+1<COLS&&map2[r  ][c+1]!=none){map[r][c]=rt;return true;}
	if(r+1<ROWS&&map2[r+1][c  ]!=none){map[r][c]=dn;return true;}
	if(c-1>=0  &&map2[r  ][c-1]!=none){map[r][c]=lt;return true;}

	return false;
}

void tgy::loading() {
    if(AUTOTOURNEY)return;
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\tLoading invincibility mode";
    system("sleep 1");
    cout << " .";
    system("sleep 1");
    cout << " .";
    system("sleep 1");
    cout << " .";
    system("sleep 1");
    cout << endl;
    system("sleep 1");
    cout << "\t\t\tEntering game";
    system("sleep 1");
    cout << " .";
    system("sleep 1");
    cout << " .";
    system("sleep 1");
    cout << " .";
    system("sleep 1");
}
