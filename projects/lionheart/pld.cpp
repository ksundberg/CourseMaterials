#include "pld.h"
#include <cmath>
#include <iostream>
//Functions for Paden Thompson: A01533872


//ACTION__________________________________
Action pld::Recommendation(SitRep sitrep){
    Action a;
    a.action=nothing;
    a.maxDist=1;
    a.dir=rt;
    a.ar=0;
    a.ac=0;
    
	int tr=r,tc=c;
    int ar=1,ac=1;
    int atr=r,atc=c;

    Dir td=rt;

    bool safety=true;
    bool col=true;
    bool archer=false;
    bool archer2=false;
 
    //COLUMN SAFETY
    for(int i=0;i<ROWS;++i){
        if(sitrep.thing[i][c].what==unit&&sitrep.thing[i][c].tla!=tla) col=false;
    }
    //TARGET ROW/COL
	switch(dir){
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
	}
    //AT ROW/COL
    switch(dir){
        case up: atr++; break;
        case dn: atr--; break;
        case lt: atc++; break;
        case rt: atc--; break;
        case none: break;
    }
    //TARGET DIR <50
    if(sitrep.turnNumber<50){
        switch(dir){
            case up: td=dn; break;
            case dn: td=up; break;
            case lt: td=rt; break;
            case rt: td=lt; break;
            case none: break;
        }
    }
    //TARGET DIR AFTER 50
    if(sitrep.turnNumber>=50){
        switch(bdir){
            case up: td=lt; break;
            case dn: td=rt; break;
            case lt: td=dn; break;
            case rt: td=up; break;
            case none: break;
        }
    }
    

    //ARCHER ATTACK
    switch(dir){
            int i;
            int j;
        case rt: for(i=c+1;i<=c+3;++i){
            for(j=r-1;j<=r+1;++j){
                if(i<0||j>=ROWS||j<0||i>=COLS) continue;
                if(sitrep.thing[j][i].what==unit&&sitrep.thing[j][i].tla!=tla&&archer2==false){
                    if(sitrep.thing[j][i].rank==crown){
                        ar=j;
                        ac=i;
                        archer=true;
                        archer2=true;
                    }
                    ar=j;
                    ac=i;
                    archer=true;
                }
            }
        }
            break;
        case lt: for(i=c-3;i<c;++i){
            for(j=r-1;j<=r+1;++j){
                if(i<0||j>=ROWS||j<0||i>=COLS) continue;
                if(sitrep.thing[j][i].what==unit&&sitrep.thing[j][i].tla!=tla&&archer2==false){
                    if(sitrep.thing[j][i].rank==crown){
                        ar=j;
                        ac=i;
                        archer=true;
                        archer2=true;
                    }
                    ar=j;
                    ac=i;
                    archer=true;
                }
            }
        }
            break;
        case up: for(i=r-1;i<=r-3;--i){
            for(j=c-1;j>=c+1;++j){
                if(i<0||i>=ROWS||j<0||j>=COLS) continue;
                if(sitrep.thing[j][i].what==unit&&sitrep.thing[j][i].tla!=tla&&archer2==false){
                    if(sitrep.thing[i][j].rank==crown){
                        ar=i;
                        ac=j;
                        archer=true;
                        archer2=true;
                    }
                    ar=i;
                    ac=j;
                    archer=true;
                }
            }
        }
            break;
        case dn: for(i=r+1;i<=r+3;++i){
            for(j=c-1;j<=c+1;++j){
                if(i<0||i>=ROWS||j<0||j>=COLS) continue;
                if(sitrep.thing[j][i].what==unit&&sitrep.thing[j][i].tla!=tla&&archer2==false){
                    if(sitrep.thing[i][j].rank==crown){
                        ar=i;
                        ac=j;
                        archer=true;
                        archer2=true;
                    }
                    ar=i;
                    ac=j;
                    archer=true;
                }
            }
        }
            break;
    }

    //SAFTEY CHECK
    for(int i=r-2;i<=r+2;++i){
        for(int j=c-2;j<=c+2;++j){
            if(i<0||i>=ROWS||j<0||j>=COLS) continue;
            if(sitrep.thing[i][j].what==unit&&sitrep.thing[i][j].tla!=tla){
                safety=false;
            }
        }
    }
    for(int i=r-5;i<=r+5;++i){
        for(int j=c-5;j<=c+5;++j){
            if(i<0||i>=ROWS||j<0||j>=COLS) continue;
            if(sitrep.thing[i][j].what==unit&&sitrep.thing[i][j].tla!=tla&&sitrep.thing[i][j].rank==knight){
                safety=false;
            }
        }
    }

    //BASIC-----------------------------------------
    
    //ATTACK IN FRONT
    if(tr>=0&&tc>=0&&tr<ROWS&&tc<COLS){
        if(sitrep.thing[tr][tc].what==unit){
            if(sitrep.thing[tr][tc].tla!=tla){
                if(group!=0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
            }
        }
    }
    if(group==3){
        if(archer==true){
            a.action=attack;
            a.ar=ar;
            a.ac=ac;
            return a;
        }
    }
    
    //PIECES-------------------------------------
    
    //PHALANX
    if(group<6&&group>2){
        if(sitrep.turnNumber<50){
            a.action=nothing;
            return a;
        }
    }

    //KNIGHT TASK FORCE
    if(group==2){
        if(r<ROWS-2&&sitrep.turnNumber<7&&r>1){
            if(tr>=0&&tc>=0&&tr<ROWS&&tc<COLS){
                if(sitrep.thing[tr][tc].what==space){
                    a.action=fwd;
                    a.maxDist=HORSESPEED;
                    return a;
                }else{
                    a.action=turn;
                    a.dir=sitrep.anyOpenSpace;
                    return a;
                }
            }else{
                a.action=turn;
                a.dir=sitrep.anyOpenSpace;
                return a;
            }
        }else{
            if(dir!=sitrep.nearestEnemyCrown.dirFor){
                a.action=turn;
                a.dir=sitrep.nearestEnemyCrown.dirFor;
                return a;
            }else{
                a.action=fwd;
                a.maxDist=HORSESPEED-rand()%4;
                return a;
            }
        }
    }

    //PHANLANX MOVE
    if(group==5){
        if(sitrep.turnNumber<75){
            if(sitrep.turnNumber%3==0){
            a.action=fwd;
            a.maxDist=1;
            return a;
            }
        }else{
            if(dir!=sitrep.nearestEnemyCrown.dirFor){
                a.action=turn;
                a.dir=sitrep.nearestEnemyCrown.dirFor;
                return a;
            }else{
                a.action=fwd;
                a.maxDist=1;
                return a;
            }
        }
    }
    
    if(group==4){
        if(sitrep.turnNumber<80){
            if(sitrep.turnNumber%3==1){
            a.action=fwd;
            a.maxDist=1;
            return a;
            }
        }else{
            if(dir!=sitrep.nearestEnemyCrown.dirFor){
                a.action=turn;
                a.dir=sitrep.nearestEnemyCrown.dirFor;
                return a;
            }else{
                a.action=fwd;
                a.maxDist=1;
                return a;
            }
        }
    }

    if(group==3){
        if(sitrep.turnNumber<100){
            if(sitrep.turnNumber%3==2){
            a.action=fwd;
            a.maxDist=1;
            return a;
            }
        }else{
            if(dir!=sitrep.nearestEnemyCrown.dirFor){
                a.action=turn;
                a.dir=sitrep.nearestEnemyCrown.dirFor;
                return a;
            }else{
                a.action=fwd;
                a.maxDist=1;
                return a;
            }
        }
    }

    //KING
    if(group==0){
        if(safety==false){
            if(tr>=0&&tc>=0&&tr<ROWS&&tc<COLS){
                if(sitrep.thing[tr][tc].what==space){
                    a.action=fwd;
                    a.maxDist=HORSESPEED;
                    return a;
                }else{
                    if(col==false&&sitrep.thing[tr][tc].what!=space){
                        a.action=turn;
                        a.dir=bdir;
                        return a;
                    }
                    if(sitrep.nearestEnemy.dirFor==sitrep.anyOpenSpace){
                        a.action=turn;
                        a.dir=td;
                        return a;
                    }else{
                        a.action=turn;
                        a.dir=sitrep.anyOpenSpace;
                        return a;
                    }
                }
            }else{
                if(col==false&&sitrep.thing[tr][tc].what!=space){
                    a.action=turn;
                    a.dir=bdir;
                    return a;
                }
                if(sitrep.nearestEnemy.dirFor==sitrep.anyOpenSpace){
                    a.action=turn;
                    a.dir=td;
                    return a;
                }else{
                    a.action=turn;
                    a.dir=sitrep.anyOpenSpace;
                    return a;
                }
            }
        }else{
            if(col==false&&sitrep.thing[tr][tc].what!=space){
                a.action=turn;
                a.dir=bdir;
                return a;
            }
            if(sitrep.nearestEnemy.dirFor==sitrep.anyOpenSpace&&dir!=bdir){
                a.action=turn;
                a.dir=td;
                return a;
            }else{
                if(dir==bdir&&sitrep.thing[atr][atc].what!=space){
                    a.action=nothing;
                    return a;
                }else{
                    a.action=turn;
                    a.dir=sitrep.anyOpenSpace;
                    return a;
                }
            }
        }
    }
    
    // there is not an enemy in front of me
	// so head to the nearest enemy
	/*if(dir==sitrep.nearestEnemy.dirFor){
     a.action=fwd;
     a.maxDist=1;
     if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
     return a;
     } else {
     a.action=turn;
     a.dir=sitrep.nearestEnemy.dirFor;
     return a;
     }*/
	a.action=nothing;
	return a;
}
































































//PLACE_____________________________________________________________(DONE)
void pld::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	//Variables
    bool done=false;
	int tr=-1,tc=-1;
	Dir td=rt;
    int change=0;
    //Choose Board-Direction
    if(minR-5<0) bdir=dn;
    if(maxR+5>=ROWS) bdir=up;
    if(minC-5<0) bdir=rt;
    if(maxC+5>=COLS) bdir=lt;
    //Switch
    switch(bdir){
        //RIGHT
        case rt:
            switch(rank){
                case infantry:
                    while(!done){
                        tc=minC+2+rand()%2;
                        tr=(maxR-minR)/2+minR+change;
                        if(sitrep.thing[tr][tc].what==space)done=true;
                        if(rand()%2==0) change++;
                        else change--;
                    }
                    if(tc==minC+3) group=5;
                    else group=4;
                    break;
                    
                case archer:
                    tc=minC+1;
                    while(!done){
                        tr=(maxR-minR)/2+minR+change;
                        if(sitrep.thing[tr][tc].what==space)done=true;
                        if(rand()%2==0) change++;
                        else change--;
                    }
                    group=3;
                    break;
                    
                case knight:
                    /*if(sitrep.thing[minR+(maxR-minR)/2+1][minC].what==space){
                        tr=minR+(maxR-minR)/2+1;
                        tc=minC;
                        group=1;
                    }else if(sitrep.thing[minR+(maxR-minR)/2-1][minC].what==space){
                        tr=minR+(maxR-minR)/2-1;
                        tc=minC;
                        group=-1;
                    }else{*/
                        tc=minC+4;
                        while(!done){
                            tr=(maxR-minR)/2+minR+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        group=2;
                    //}
                    break;
                    
                case crown:
                    tc=minC;
                    tr=minR+(maxR-minR)/2;
                    group=0;
                    break;
            }
            break;
            
        //LEFT
        case lt:
            switch(rank){
                case infantry:
                    while(!done){
                        tc=maxC-2-rand()%2;
                        tr=(maxR-minR)/2+minR+change;
                        if(sitrep.thing[tr][tc].what==space)done=true;
                        if(rand()%2==0) change++;
                        else change--;
                    }
                    if(tc==maxC-3) group=5;
                    else group=4;
                    break;
                    
                case archer:
                    tc=maxC-1;
                    while(!done){
                        tr=(maxR-minR)/2+minR+change;
                        if(sitrep.thing[tr][tc].what==space)done=true;
                        if(rand()%2==0) change++;
                        else change--;
                    }
                    group=3;
                    break;
                    
                case knight:
                    /*if(sitrep.thing[minR+(maxR-minR)/2+1][maxC].what==space){
                        tr=minR+(maxR-minR)/2+1;
                        tc=maxC;
                        group=1;
                    }else if(sitrep.thing[minR+(maxR-minR)/2-1][maxC].what==space){
                        tr=minR+(maxR-minR)/2-1;
                        tc=maxC;
                        group=-1;
                    }else{*/
                        tc=maxC-4;
                        while(!done){
                            tr=(maxR-minR)/2+minR+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        group=2;
                    //}
                    break;
                    
                case crown:
                    tc=maxC;
                    tr=minR+(maxR-minR)/2;
                    group=0;
                    break;
            }
            break;
            
        //DOWN
        case dn:
            switch(rank){
                case infantry:
                    while(!done){
                        tr=minR+2+rand()%2;
                        tc=(maxC-minC)/2+minC+change;
                        if(sitrep.thing[tr][tc].what==space)done=true;
                        if(rand()%2==0) change++;
                        else change--;
                    }
                    if(tr==maxR) group=5;
                    else group=4;
                    break;
                    
                case archer:
                    tr=minR+1;
                    while(!done){
                        tc=(maxC-minC)/2+minC+change;
                        if(sitrep.thing[tr][tc].what==space)done=true;
                        if(rand()%2==0) change++;
                        else change--;

                    }
                    group=3;
                    break;
                    
                case knight:
                    /*if(sitrep.thing[minR][minC+(maxC-minC)/2+1].what==space){
                        tr=minR;
                        tc=minC+(maxC-minC)/2+1;
                        group=1;
                    }else if(sitrep.thing[minR][minC+(maxC-minC)/2-1].what==space){
                        tr=minR;
                        tc=minC+(maxC-minC)/2-1;
                        group=1;
                    }else{*/
                        tr=minR+4;
                        while(!done){
                            tc=(maxC-minC)/2+minC+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;

                        }
                        group=2;
                    //}
                    break;
                    
                case crown:
                    tc=minC+(maxC-minC)/2;
                    tr=minR;
                    group=0;
                    break;
            }
            break;
            
        //UP
        case up:
            switch(rank){
                case infantry:
                    while(!done){
                        tr=maxR-2-rand()%2;
                        tc=(maxC-minC)/2+minC+change;
                        if(sitrep.thing[tr][tc].what==space)done=true;
                        if(rand()%2==0) change++;
                        else change--;
                    }
                    if(tr==minR) group=5;
                    else group=4;
                    break;
                    
                case archer:
                    tr=maxR-1;
                    while(!done){
                        tc=(maxC-minC)/2+minC+change;
                        if(sitrep.thing[tr][tc].what==space)done=true;
                        if(rand()%2==0) change++;
                        else change--;

                    }
                    group=3;
                    break;
                    
                case knight:
                    /*if(sitrep.thing[minR][minC+(maxC-minC)/2+1].what==space){
                        tr=maxR;
                        tc=minC+(maxC-minC)/2+1;
                        group=1;
                    }else if(sitrep.thing[minR][minC+(maxC-minC)/2-1].what==space){
                        tr=maxR;
                        tc=minC+(maxC-minC)/2-1;
                        group=1;
                    }else{*/
                        tr=maxR-4;
                        while(!done){
                            tc=(maxC-minC)/2+minC+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        group=2;
                    //}
                    break;
                    
                case crown:
                    tc=minC+(maxC-minC)/2;
                    tr=maxR;
                    group=0;
                    break;
            }
            break;
            
        //NONE
        case none:
            switch(rank){
            case infantry:
                while(!done){
                    tc=minC+rand()%2;
                    tr=minR+rand()%(maxR-minR);
                    if(sitrep.thing[tr][tc].what==space)done=true;
                }
                if(tc==minC) group=5;
                else group=4;
                break;
                
            case archer:
                tc=maxC-1;
                while(!done){
                    tr=minR+rand()%(maxR-minR);
                    if(sitrep.thing[tr][tc].what==space)done=true;
                }
                group=3;
                break;
                
            case knight:
                /*if(sitrep.thing[minR+(maxR-minR)/2+1][maxC].what==space){
                    tr=minR+(maxR-minR)/2+1;
                    tc=maxC;
                    group=1;
                }else if(sitrep.thing[minR+(maxR-minR)/2-1][maxC].what==space){
                    tr=minR+(maxR-minR)/2-1;
                    tc=maxC;
                    group=-1;
                }else{*/
                    tc=maxC-2;
                    while(!done){
                        tr=minR+rand()%(maxR-minR);
                        if(sitrep.thing[tr][tc].what==space)done=true;
                    }
                    group=2;
                //}
                break;
                
            case crown:
                tc=maxC;
                tr=minR+(maxR-minR)/2;
                group=0;
                break;
        }
            break;
    }
    //Direction
	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=up;
		else td=dn;
	}
    
    if(bdir==none){
        bdir=td;
        switch(bdir){
                //RIGHT
            case rt:
                switch(rank){
                    case infantry:
                        while(!done){
                            tc=minC+2+rand()%2;
                            tr=(maxR-minR)/2+minR+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        if(tc==minC+3) group=5;
                        else group=4;
                        break;
                        
                    case archer:
                        tc=minC+1;
                        while(!done){
                            tr=(maxR-minR)/2+minR+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        group=3;
                        break;
                        
                    case knight:
                        /*if(sitrep.thing[minR+(maxR-minR)/2+1][minC].what==space){
                         tr=minR+(maxR-minR)/2+1;
                         tc=minC;
                         group=1;
                         }else if(sitrep.thing[minR+(maxR-minR)/2-1][minC].what==space){
                         tr=minR+(maxR-minR)/2-1;
                         tc=minC;
                         group=-1;
                         }else{*/
                        tc=minC+4;
                        while(!done){
                            tr=(maxR-minR)/2+minR+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        group=2;
                        //}
                        break;
                        
                    case crown:
                        tc=minC;
                        tr=minR+(maxR-minR)/2;
                        group=0;
                        break;
                }
                break;
                
                //LEFT
            case lt:
                switch(rank){
                    case infantry:
                        while(!done){
                            tc=maxC-2-rand()%2;
                            tr=(maxR-minR)/2+minR+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        if(tc==maxC-3) group=5;
                        else group=4;
                        break;
                        
                    case archer:
                        tc=maxC-1;
                        while(!done){
                            tr=(maxR-minR)/2+minR+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        group=3;
                        break;
                        
                    case knight:
                        /*if(sitrep.thing[minR+(maxR-minR)/2+1][maxC].what==space){
                         tr=minR+(maxR-minR)/2+1;
                         tc=maxC;
                         group=1;
                         }else if(sitrep.thing[minR+(maxR-minR)/2-1][maxC].what==space){
                         tr=minR+(maxR-minR)/2-1;
                         tc=maxC;
                         group=-1;
                         }else{*/
                        tc=maxC-4;
                        while(!done){
                            tr=(maxR-minR)/2+minR+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        group=2;
                        //}
                        break;
                        
                    case crown:
                        tc=maxC;
                        tr=minR+(maxR-minR)/2;
                        group=0;
                        break;
                }
                break;
                
                //DOWN
            case dn:
                switch(rank){
                    case infantry:
                        while(!done){
                            tr=minR+2+rand()%2;
                            tc=(maxC-minC)/2+minC+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        if(tr==maxR) group=5;
                        else group=4;
                        break;
                        
                    case archer:
                        tr=minR+1;
                        while(!done){
                            tc=(maxC-minC)/2+minC+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                            
                        }
                        group=3;
                        break;
                        
                    case knight:
                        /*if(sitrep.thing[minR][minC+(maxC-minC)/2+1].what==space){
                         tr=minR;
                         tc=minC+(maxC-minC)/2+1;
                         group=1;
                         }else if(sitrep.thing[minR][minC+(maxC-minC)/2-1].what==space){
                         tr=minR;
                         tc=minC+(maxC-minC)/2-1;
                         group=1;
                         }else{*/
                        tr=minR+4;
                        while(!done){
                            tc=(maxC-minC)/2+minC+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                            
                        }
                        group=2;
                        //}
                        break;
                        
                    case crown:
                        tc=minC+(maxC-minC)/2;
                        tr=minR;
                        group=0;
                        break;
                }
                break;
                
                //UP
            case up:
                switch(rank){
                    case infantry:
                        while(!done){
                            tr=maxR-2-rand()%2;
                            tc=(maxC-minC)/2+minC+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        if(tr==minR) group=5;
                        else group=4;
                        break;
                        
                    case archer:
                        tr=maxR-1;
                        while(!done){
                            tc=(maxC-minC)/2+minC+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                            
                        }
                        group=3;
                        break;
                        
                    case knight:
                        /*if(sitrep.thing[minR][minC+(maxC-minC)/2+1].what==space){
                         tr=maxR;
                         tc=minC+(maxC-minC)/2+1;
                         group=1;
                         }else if(sitrep.thing[minR][minC+(maxC-minC)/2-1].what==space){
                         tr=maxR;
                         tc=minC+(maxC-minC)/2-1;
                         group=1;
                         }else{*/
                        tr=maxR-4;
                        while(!done){
                            tc=(maxC-minC)/2+minC+change;
                            if(sitrep.thing[tr][tc].what==space)done=true;
                            if(rand()%2==0) change++;
                            else change--;
                        }
                        group=2;
                        //}
                        break;
                        
                    case crown:
                        tc=minC+(maxC-minC)/2;
                        tr=maxR;
                        group=0;
                        break;
                }
                break;
                
                //NONE
            case none:
                switch(rank){
                    case infantry:
                        while(!done){
                            tc=minC+rand()%2;
                            tr=minR+rand()%(maxR-minR);
                            if(sitrep.thing[tr][tc].what==space)done=true;
                        }
                        if(tc==minC) group=5;
                        else group=4;
                        break;
                        
                    case archer:
                        tc=maxC-1;
                        while(!done){
                            tr=minR+rand()%(maxR-minR);
                            if(sitrep.thing[tr][tc].what==space)done=true;
                        }
                        group=3;
                        break;
                        
                    case knight:
                        /*if(sitrep.thing[minR+(maxR-minR)/2+1][maxC].what==space){
                         tr=minR+(maxR-minR)/2+1;
                         tc=maxC;
                         group=1;
                         }else if(sitrep.thing[minR+(maxR-minR)/2-1][maxC].what==space){
                         tr=minR+(maxR-minR)/2-1;
                         tc=maxC;
                         group=-1;
                         }else{*/
                        tc=maxC-2;
                        while(!done){
                            tr=minR+rand()%(maxR-minR);
                            if(sitrep.thing[tr][tc].what==space)done=true;
                        }
                        group=2;
                        //}
                        break;
                        
                    case crown:
                        tc=maxC;
                        tr=minR+(maxR-minR)/2;
                        group=0;
                        break;
                }
                break;
        }
    }
    if(tr<minR||tr>maxR||tc>maxC||tc<minC) done=false;
    if(rank==crown){
        switch(bdir){
            case lt: tc=maxC; td=dn; done=true; break;
            case rt: tc=minC; td=up; done=true; break;
            case up: tr=maxR; done=true; break;
            case dn: tr=minR; done=true; break;
            case none: done=false; break;
        }
    }
    while(!done){
        tr=minR+rand()%(maxR=minR);
        tc=minC+rand()%(maxC-minC);
        if(sitrep.thing[tr][tc].what==space)done=true;
    }
    r=tr;
	c=tc;
	dir=td;
}


