#include "mlg.h"
#include <cmath>
#include <iostream>
#include <vector>
#include "unit.h"
#include "lionheart2.h"

int crow, ccol;
Dir cdir;
int knights, archers, infantrys;

int ca = 0;

void mlg::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep) {
    // this is the place function; it will get called once per unit
    // at board setup and never again
    // crown, knights, archers, infantry
    bool done = false;
    int tr, tc;
    Dir td;

    if (INFILE == "navy.in") {
        if (rank == crown) {
            // place crown
            r = minR + ((maxR - minR) / 2);
            c = minC + ((maxC - minC) / 2);

            int rdist = ROWS / 2 - r;
            int cdist = COLS / 2 - c;
            if ( abs(rdist) < abs(cdist)) {
                if ( cdist > 0) td = rt;
                else td = lt;
            } else {
                if ( rdist > 0) td = dn;
                else td = up;
            }
            dir = td;

            crow = r;
            ccol = c;
            cdir = dir;

            knights = 0;
            archers = 0;
            infantrys = 0;
            hg = false;
        }
        else if (rank == knight) {
            // place knights [6]
            int oh, ov;
            int d = 3, s = 5;
            switch (cdir) {
                case up: ov = -d; oh =  0; break;
                case dn: ov =  d; oh =  0; break;
                case rt: ov =  0; oh =  d; break;
                case lt: ov =  0; oh = -d; break;
                case none: break;  // handled in crown placement
                default: break;  // should never occur
            }
            if (oh == 0) {
                    // horizontal
                r = crow + ov;
                if (sitrep.thing[r][ccol - s].what == space) {
                    c = ccol-s;
                }
                else if (sitrep.thing[r][ccol - s].what == unit) {
                    c = (ccol-s)+(2*knights);
                }
            }
            else if (ov == 0) {
                //  vertical
                c = ccol + oh;
                if (sitrep.thing[crow-s][c].what == space) {
                    r = crow-s;
                }
                else if (sitrep.thing[crow-s][c].what == unit) {
                    r = (crow-s)+(2*knights);
                }
            }

            dir = cdir;
            knights++;
            hg = false;
        }
        else if (rank == archer) {
            // place archers [8]
            int oh, ov;
            int d = 3, s = 4;
            switch (cdir) {
                case up: ov = -d; oh =  0; break;
                case dn: ov =  d; oh =  0; break;
                case rt: ov =  0; oh =  d; break;
                case lt: ov =  0; oh = -d; break;
                case none: break;  // handled in crown placement
                default: break;  // should never occur
            }
            if (oh == 0) {
                // horizontal
                if (archers < 5) {
                    r = crow + ov;
                    if (sitrep.thing[r][ccol - s].what == space) {
                        c = ccol-s;
                    }
                    else if (sitrep.thing[r][ccol - s].what == unit) {
                        c = (ccol-s)+(2*archers);
                    }
                    hg = false;
                }
                else if (archers >= 5) {
                    r = (crow+(ov/d));
                    c = (ccol-1)+ca;
                    ca++;
                    hg = true;
                }
            }
            else if (ov == 0) {
                //  vertical
                if (archers < 5) {
                    c = ccol + oh;
                    if (sitrep.thing[crow-s][c].what == space) {
                        r = crow-s;
                    }
                    else if (sitrep.thing[crow-s][c].what == unit) {
                        r = (crow-s)+(2*archers);
                    }
                    hg = false;
                }
                else if (archers >= 5) {
                    r = (crow-1)+ca;
                    c = (ccol+(oh/d));
                    ca++;
                    hg = true;
                }
            }

            dir = cdir;
            if (archers == 5) dir = up;
            if (archers == 7) dir = dn;
            archers++;
        }
        else if (rank == infantry) {
            //  place infantry
            int oh, ov;
            int d = 4, s = 5;
            switch (cdir) {
                case up: ov = -d; oh =  0; break;
                case dn: ov =  d; oh =  0; break;
                case rt: ov =  0; oh =  d; break;
                case lt: ov =  0; oh = -d; break;
                case none: break;  // handled in crown placement
                default: break;  // should never occur
            }
            if (oh == 0) {
                // horizontal
                if (infantrys < 10) {
                    r = crow + ov;
                    if (sitrep.thing[r][ccol - s].what == space) {
                        c = ccol-s;
                    }
                    else if (sitrep.thing[r][ccol - s].what == unit) {
                        c = (ccol-s)+(infantrys);
                    }
                    dir = cdir;
                    hg = false;
                }
                else {
                    switch(infantrys) {
                        case 11: r = crow+1; c = ccol; dir = dn; break;
                        case 12: r = crow-1; c = ccol; dir = up; break;
                        case 13: r = crow+1; c = ccol-(oh/d); dir = dn; break;
                        case 14: r = crow-1; c = ccol-(oh/d); dir = up; break;
                    }
                    hg = true;
                }
            }

            else if (ov == 0) {
                //  vertical
                if (infantrys < 11) {
                    c = ccol + oh;
                    if (sitrep.thing[crow-s][c].what == space) {
                        r = crow-s;
                    }
                    else if (sitrep.thing[crow-s][c].what == unit) {
                        r = (crow-s)+(infantrys);
                    }
                    dir = cdir;
                    hg = false;
                }
                else {
                    switch(infantrys) {
                        case 11: r = crow+1; c = ccol; dir = dn; break;
                        case 12: r = crow-1; c = ccol; dir = up; break;
                        case 13: r = crow+1; c = ccol-(oh/d); dir = dn; break;
                        case 14: r = crow-1; c = ccol-(oh/d); dir = up; break;
                    }
                    hg = true;
                }
            }
            infantrys++;
        }
        else {
            while ( !done ) {
                    tr = minR + rand()%(maxR - minR);
                    tc = minC + rand()%(maxC - minC);
                    if(sitrep.thing[tr][tc].what==space)done=true;
                }
                int rdist = ROWS / 2 - tr;
                int cdist = COLS / 2 - tc;
                if ( abs(rdist) < abs(cdist)) {
                    if ( cdist > 0) td = rt;
                    else td = lt;
                } else {
                    if ( rdist > 0) td = dn;
                    else td = up;
                }
                r   = tr;
                c   = tc;
                dir = td;
        }
    }
    else if (INFILE == "map2.in") {
        int kminC, kmaxC, aminC, amaxC;

        if (rank == crown) {
            // place crown
            r = minR + ((maxR - minR) / 2);
            c = minC + ((maxC - minC) / 2);

            int rdist = ROWS / 2 - r;
            int cdist = COLS / 2 - c;
            if ( abs(rdist) < abs(cdist)) {
                if ( cdist > 0) td = rt;
                else td = lt;
            } else {
                if ( rdist > 0) td = dn;
                else td = up;
            }
            dir = td;

            if (dir == rt) { c--; }
            if (dir == lt) { c++; }

            crow = r;
            ccol = c;
            cdir = dir;

            knights = 0;
            archers = 0;
            infantrys = 0;
            hg = false;
            //std::cout << "crown placed\n";
            //std::cout << "crown direction: ";
/*
            switch(dir) {
                case up: std::cout << "up \n"; break;
                case dn: std::cout << "dn \n"; break;
                case rt: std::cout << "rt \n"; break;
                case lt: std::cout << "lt \n"; break;
            }
*/
        }
        else if (rank == knight) {
            kminC = minC; kmaxC = maxC;
            if (cdir == lt) { kmaxC = ccol; }
            if (cdir == rt) { kminC = ccol; }
            while ( !done ) {
                    tr = minR + rand()%(maxR - minR);
                    tc = kminC + rand()%(kmaxC - kminC);
                    if(sitrep.thing[tr][tc].what==space)done=true;
                }
                int rdist = ROWS / 2 - tr;
                int cdist = COLS / 2 - tc;
                if ( abs(rdist) < abs(cdist)) {
                    if ( cdist > 0) td = rt;
                    else td = lt;
                } else {
                    if ( rdist > 0) td = dn;
                    else td = up;
                }
                r   = tr;
                c   = tc;
                dir = td;
                //std::cout << "knight placed\n";
        }
        else if (rank == archer) {
            if (cdir == lt) { amaxC=maxC-1; aminC=minC+1; }
            if (cdir == rt) { aminC=minC+1; amaxC=maxC-1; }
            while ( !done ) {
                    tr = minR + rand()%(maxR - minR);
                    tc = aminC + rand()%(amaxC - aminC);
                    if(sitrep.thing[tr][tc].what==space)done=true;
                }
                int rdist = ROWS / 2 - tr;
                int cdist = COLS / 2 - tc;
                if ( abs(rdist) < abs(cdist)) {
                    if ( cdist > 0) td = rt;
                    else td = lt;
                } else {
                    if ( rdist > 0) td = dn;
                    else td = up;
                }
                r   = tr;
                c   = tc;
                dir = td;
                //std::cout << "archer placed\n";
        }
        else {
            if (cdir == lt) { maxC-=2; }
            if (cdir == rt) { minC+=2; }
            while ( !done ) {
                    tr = minR + rand()%(maxR - minR);
                    tc = minC + rand()%(maxC - minC);
                    if(sitrep.thing[tr][tc].what==space)done=true;
                }
                int rdist = ROWS / 2 - tr;
                int cdist = COLS / 2 - tc;
                if ( abs(rdist) < abs(cdist)) {
                    if ( cdist > 0) td = rt;
                    else td = lt;
                } else {
                    if ( rdist > 0) td = dn;
                    else td = up;
                }
                r   = tr;
                c   = tc;
                dir = td;
                //std::cout << "infantry placed\n";
        }
        hg = false;
    }
    else {
        while ( !done ) {
                    tr = minR + rand()%(maxR - minR);
                    tc = minC + rand()%(maxC - minC);
                    if(sitrep.thing[tr][tc].what==space)done=true;
                }
                int rdist = ROWS / 2 - tr;
                int cdist = COLS / 2 - tc;
                if ( abs(rdist) < abs(cdist)) {
                    if ( cdist > 0) td = rt;
                    else td = lt;
                } else {
                    if ( rdist > 0) td = dn;
                    else td = up;
                }
                r   = tr;
                c   = tc;
                dir = td;
    }
}
Thing mlg::beforeMe(SitRep sitrep) {
    int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
        return sitrep.thing[tr][tc];
	}

	Thing blank;
	blank.what = rock;
	return blank;
}

bool mlg::inRange(Thing enemy, int ec, int er) {
    if (enemy.rank == archer) {
        if (er - r <= 4 && ec - c <= 4)
            return true;
    }
    else if (enemy.rank == knight) {
        if (er - r <= 5 && ec - c <= 5)
            return true;
    }
    else if (enemy.rank == infantry) {
        if (er - r <= 2 && ec - c <= 2)
            return true;
    }
    return false;
}

bool mlg::validTarget(SitRep sitrep) {
    int fr=r, fc=c;
    switch(dir) {
    case up: fr-=3; break;
    case dn: fr+=3; break;
    case rt: fc=+3; break;
    case lt: fc-=3; break;
    case none: break;
    }
}

// tell someone what you want to do
Action mlg::Recommendation(SitRep sitrep) {
	Action a;
	int tr=r, tc=c;
	if (rank == archer) {
        a.action = attack;
        a.ar = sitrep.nearestEnemy.r;
        a.ac = sitrep.nearestEnemy.c;
        return a;
	}
	else if (rank == crown) {
        a.action = nothing;
        return a;
	}
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
		if(sitrep.thing[tr][tc].what==unit || hg) {
			if(sitrep.thing[tr][tc].tla!=tla) {
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
		if(rank==knight) {
            switch (dir){
            case up: a.maxDist = r - sitrep.nearestEnemy.r; break;
            case dn: a.maxDist = sitrep.nearestEnemy.r - r; break;
            case rt: a.maxDist = sitrep.nearestEnemy.c - c; break;
            case lt: a.maxDist = c - sitrep.nearestEnemy.c; break;
            case none: break;
            }
		    if (a.maxDist > HORSESPEED){a.maxDist=HORSESPEED;}
		}
		return a;
	} else {
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;

}
