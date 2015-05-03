#include "the.h"
#include <cmath>
#include <iostream>

void the::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	int tr, tc;
	int counter=0;
    bool success=false;
    switch(rank){
        case crown:
            tc=(maxC-minC)/2+minC;
            tr=(maxR-minR)/2+minR;
            if(sitrep.thing[tr][tc].what==space) success=true;
            while(success!=true){
            tr=tr++;
            if(tr>maxR){
              tr=minR;
              counter=counter+1;
              if(counter>1){
                counter=0;
                tc=tc-1;
              }
            }
            if(sitrep.thing[tr][tc].what==space) success=true;
            }
            c=tc;
            r=tr;
            break;
        case knight:
            static int called;
            called++;
            if(called%2==0){
                tc=(maxC-minC)/2+minC;
                tr=((maxR-minR)/2-1)+minR;
                if(sitrep.thing[tr][tc].what==space) success=true;
                while(success!=true){
                    tr--;
                    if(tr<minR){
                        tr=maxR;
                        counter=counter+1;
                        if(counter>1){
                        counter=0;
                        tc=tc+1;
                    }}
                    if(sitrep.thing[tr][tc].what==space) success=true;
                }
            }else if(called%2!=0){
                tc=(maxC-minC)/2+minC;
                tr=((maxR-minR)/2+1)+minR;
                if(sitrep.thing[tr][tc].what==space) success=true;
                while(success!=true){
                    tr++;
                    if(tr>maxR){
                        tr=minR;
                        counter=counter+1;
                        if(counter>1){
                        counter=0;
                        tc=tc+1;
                    }}
                    if(sitrep.thing[tr][tc].what==space) success=true;
                }
            }
            c=tc;
            r=tr;
            break;
        case archer:
            while(success!=true){
                tc=maxC-rand()%(((maxC-minC)/2)+1);
                tr=minR+rand()%(maxR-minR);
                if(sitrep.thing[tr][tc].what==space)success=true;
            }
            c=tc;
            r=tr;
            break;
        case infantry:
            while(success!=true){
                tc=minC+rand()%(maxC-minC);
                tr=minR+rand()%(maxR-minR);
                if(sitrep.thing[tr][tc].what==space)success=true;
            }
            r=tr;
            c=tc;
            break;
}}

Action the::Recommendation(SitRep sitrep){
	Action a;
    int tr=r,tc=c,ftr=r,ftc=c;
    bool p1=false, p2=false, p3=false, p4=false;
    switch(rank){
    case crown:
        for(int i=1;i<=4;i++){
                switch (i){
                    case 1:
                        if(sitrep.thing[tr-1][tc].what==unit||sitrep.thing[tr-1][tc].what==rock) p1=true;
                        tr=r;
                    break;
                    case 2:
                        if(sitrep.thing[tr][tc+1].what==unit||sitrep.thing[tr][tc+1].what==rock) p2=true;
                        tc=c;
                    break;
                    case 3:
                        if(sitrep.thing[tr+1][tc].what==unit||sitrep.thing[tr+1][tc].what==rock) p3=true;
                        tr=r;
                    break;
                    case 4:
                        if(sitrep.thing[tr][tc-1].what==unit||sitrep.thing[tr][tc-1].what==rock) p4=true;
                        tc=c;
                    break;
            }}
            if(p1==true&&p2==true&&p3==true&&p4==true){
                switch(dir){
                    case up: tr--; break;
                    case dn: tr++; break;
                    case rt: tc++; break;
                    case lt: tc--; break;
                    case none: break;
                }
                if(sitrep.thing[tr][tc].what==unit){
                    if(sitrep.thing[tr][tc].tla!=tla){
                        a.action=attack;
                        a.ar=tr;
                        a.ac=tc;
                        return a;
                    }
                    tr=r;
                    tc=c;
                }
                a.action=turn;
                a.dir=sitrep.nearestEnemy.dirFor;
                return a;
            }
            if(p1==true||p2==true||p3==true||p4==true){
                int way;
                switch(dir){
                    case up: tr--; break;
                    case dn: tr++; break;
                    case rt: tc++; break;
                    case lt: tc--; break;
                    case none: break;
                }
                if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
                    if(sitrep.thing[tr][tc].what==space){
                        a.action=fwd;
                        a.maxDist=HORSESPEED;
                        return a;
                    }
                    a.action=turn;
                    switch(dir){
                    case up: a.dir=dn; break;
                    case dn: a.dir=up; break;
                    case rt: a.dir=lt; break;
                    case lt: a.dir=rt; break;
                    case none: break;
                    }
                    return a;
                }
                tr=r;
                tc=c;
                switch(p1){
                    case true: break;
                    case false: way=1; break;
                }
                switch(p2){
                    case true: break;
                    case false: way=2; break;
                }
                switch(p3){
                    case true: break;
                    case false: way=3; break;
                }
                switch(p4){
                    case true: break;
                    case false: way=4; break;
                }
                a.action=turn;
                switch(way){
                    case 1: a.dir=up; break;
                    case 2: a.dir=lt; break;
                    case 3: a.dir=dn; break;
                    case 4: a.dir=lt; break;
                }
                return a;
            }
            int k;
            k=rand()%2;
            if(k==0){
                if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
                    a.action=fwd;
                    a.maxDist=HORSESPEED;
                    return a;
                }
            }else if(k==1){
                a.action=turn;
                switch(dir){
                    case up: a.dir=rt; break;
                    case dn: a.dir=up; break;
                    case lt: a.dir=dn; break;
                    case rt: a.dir=lt; break;
                }
                return a;
            }
    break;
    case archer:
            switch(dir){
                case up:
                    for(int i=1;i<=9;i++){
                        switch(i){
                            case 1:
                                tr=tr-1;
                            break;
                            case 2:
                                tr=tr-2;
                            break;
                            case 3:
                                tr=tr-3;
                            break;
                            case 4:
                                tr=tr-1;
                                tc=tc-1;
                            break;
                            case 5:
                                tr=tr-2;
                                tc=tc-1;
                            break;
                            case 6:
                                tr=tr-3;
                                tc=tc-1;
                            break;
                            case 7:
                                tr=tr-1;
                                tc=tc+1;
                            break;
                            case 8:
                                tr=tr-2;
                                tc=tc+1;
                            break;
                            case 9:
                                tr=tr-3;
                                tc=tc+1;
                            break;
                break;
                }
                if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
                    if(sitrep.thing[tr][tc].what==unit){
                        if(sitrep.thing[tr][tc].tla!=tla){
                            a.action=attack;
                            a.ar=tr; a.ac=tc;
                            return a;
                }}}
                tr=r;
                tc=c;
                }
                case rt:
                    for(int i=1;i<=9;i++){
                        switch(i){
                            case 1:
                                tc=tc+1;
                            break;
                            case 2:
                                tc=tc+2;
                            break;
                            case 3:
                                tc=tc+3;
                            break;
                            case 4:
                                tr=tr-1;
                                tc=tc+1;
                            break;
                            case 5:
                                tr=tr-1;
                                tc=tc+2;
                            break;
                            case 6:
                                tr=tr-1;
                                tc=tc+3;
                            break;
                            case 7:
                                tr=tr+1;
                                tc=tc+1;
                            break;
                            case 8:
                                tr=tr+1;
                                tc=tc+2;
                            break;
                            case 9:
                                tr=tr+1;
                                tc=tc+3;
                            break;
                break;
            }
            if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
                    if(sitrep.thing[tr][tc].what==unit){
                        if(sitrep.thing[tr][tc].tla!=tla){
                            a.action=attack;
                            a.ar=tr; a.ac=tc;
                            return a;
                }}}
                tr=r;
                tc=c;
            }
            case dn:
                    for(int i=1;i<=9;i++){
                        switch(i){
                            case 1:
                                tr=tr+1;
                            break;
                            case 2:
                                tr=tr+2;
                            break;
                            case 3:
                                tr=tr+3;
                            break;
                            case 4:
                                tr=tr+1;
                                tc=tc-1;
                            break;
                            case 5:
                                tr=tr+2;
                                tc=tc-1;
                            break;
                            case 6:
                                tr=tr+3;
                                tc=tc-1;

                            break;
                            case 7:
                                tr=tr+1;
                                tc=tc+1;
                            break;
                            case 8:
                                tr=tr+2;
                                tc=tc+1;
                            break;
                            case 9:
                                tr=tr+3;
                                tc=tc+1;

                            break;
                    break;
                    }
                    if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
                        if(sitrep.thing[tr][tc].what==unit){
                            if(sitrep.thing[tr][tc].tla!=tla){
                                a.action=attack;
                                a.ar=tr; a.ac=tc;
                                return a;
                    }}}
                    tr=r;
                    tc=c;
                    }
                case lt:
                    for(int i=1;i<=9;i++){
                        switch(i){
                            case 1:
                                tc=tc-1;
                            break;
                            case 2:
                                tc=tc-2;
                            break;
                            case 3:
                                tc=tc-3;
                            break;
                            case 4:
                                tr=tr-1;
                                tc=tc-1;
                            break;
                            case 5:
                                tr=tr-1;
                                tc=tc-2;
                            break;
                            case 6:
                                tr=tr-1;
                                tc=tc-3;
                            break;
                            case 7:
                                tr=tr+1;
                                tc=tc-1;
                            break;
                            case 8:
                                tr=tr+1;
                                tc=tc-2;
                            break;
                            case 9:
                                tr=tr+1;
                                tc=tc-3;
                            break;
                    break;
                }
                if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
                    if(sitrep.thing[tr][tc].what==unit){
                        if(sitrep.thing[tr][tc].tla!=tla){
                            a.action=attack;
                            a.ar=tr; a.ac=tc;
                            return a;
                }}}
                tr=r;
                tc=c;
                }
            }
            if(dir==sitrep.nearestEnemy.dirFor){
                a.action=fwd;
                a.maxDist=1;
                return a;
            }else {
                a.action=turn;
                a.dir=sitrep.nearestEnemy.dirFor;
                return a;
            }
            a.action=nothing;
            return a;

    break;
    case knight:
    case infantry:
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
            }}}
            tr=r; tc=c;
            for(int i=1;i<=4;i++){
                switch (i){
                    case 1:
                        if(tr>0){
                            if(sitrep.thing[tr-1][tc].what==unit){
                                if(sitrep.thing[tr-1][tc].tla!=tla){
                                    a.action=turn;
                                    a.dir=up;
                                    return a;
                            }}}
                        tr=r;
                    break;
                    case 2:
                        if(tc+1<COLS){
                            if(sitrep.thing[tr][tc+1].what==unit){
                                if(sitrep.thing[tr][tc+1].tla!=tla){
                                    a.action=turn;
                                    a.dir=rt;
                                    return a;
                        }}}
                        tc=c;
                    break;
                    case 3:
                        if(tr+1<ROWS){
                            if(sitrep.thing[tr+1][tc].what==unit){
                                if(sitrep.thing[tr+1][tc].tla!=tla){
                                    a.action=turn;
                                    a.dir=dn;
                                    return a;
                        }}}
                        tr=r;
                    break;
                    case 4:
                        if(tc>0){
                            if(sitrep.thing[tr][tc-1].what==unit){
                                if(sitrep.thing[tr][tc-1].tla!=tla){
                                    a.action=turn;
                                    a.dir=lt;
                                    return a;
                        }}}
                        tc=c;
                    break;
            }}
            if(dir==sitrep.nearestEnemy.dirFor){
                a.action=fwd;
                a.maxDist=1;
                return a;
            }else {
                a.action=turn;
                a.dir=sitrep.nearestEnemy.dirFor;
                return a;
            }
            a.action=nothing;
            return a;
        break;
    }}
