//Assignment 12
//CS 1400-001
//Steven Ban
//Note: It may still say there's an infinite loop, but it compiles and runs just fine (at least, when I'm the first TLA)

#include "bos.h"
#include <cmath>
#include <iostream>
#include <time.h>

static Location kingPos;

//MY FUNCTIONS
Location bos::arRange(int r, int c, Dir Dir, SitRep sitrep) //Tells if a unit is in archer's range
{
    Location target;
    target.r = r;
    target.c = c;
    target.dirFor = Dir;
    bool success;
    if (rank == archer)
    {
        if (Dir == rt)
        {
            for(int ttr = r - 1; ttr <= r+1;ttr ++)
            {
                for(int ttc = c + 1; ttc <= c+3;ttc ++)
                {

                    if(sitrep.thing[ttr][ttc].what == unit)
                    {
                        if(sitrep.thing[ttr][ttc].tla!=tla){success = true; target.c = ttc; target.r = ttr;}
                    }

                }
            }
        }

        if (Dir == lt)
        {
            for(int ttr = r - 1; ttr <= r+1;ttr ++)
            {
                for(int ttc = c + 1; ttc <= c+3;ttc ++)
                {
                    if(sitrep.thing[ttr][ttc].what == unit)
                    {
                        if(sitrep.thing[ttr][ttc].tla!=tla){success = true; target.c = ttc; target.r = ttr;}
                    }                }
            }
        }
        if (Dir == dn)
        {
            for(int ttr = r + 1; ttr <= r+3;ttr ++)
            {
                for(int ttc = c - 1; ttc <= c+1;ttc ++)
                {
                    if(sitrep.thing[ttr][ttc].what == unit)
                    {
                        if(sitrep.thing[ttr][ttc].tla!=tla){success = true; target.c = ttc; target.r = ttr;}
                    }                }
            }
        }
        if (Dir == up)
        {
            for(int ttr = r - 3; ttr <= r-1;ttr ++)
            {
                for(int ttc = c - 1; ttc <= c+1;ttc ++)
                {
                    if(sitrep.thing[ttr][ttc].what == unit)
                    {
                        if(sitrep.thing[ttr][ttc].tla!=tla){success = true; target.c = ttc; target.r = ttr;}
                    }
                }
            }
        }
    if(success) return target;
    else exit(0);
    }
}

bool bos::isRange(int r, int c, Dir Dir, SitRep sitrep)
{
    bool success = false;
    if (rank == archer)
    {
        if (Dir == rt)
        {
            for(int ttr = r - 1; ttr <= r+1;ttr ++)
            {
                for(int ttc = c + 1; ttc <= c+3;ttc ++)
                {
                    if(sitrep.thing[ttr][ttc].what == unit && sitrep.thing[ttr][ttc].tla!=tla){success = true;}                }
            }
        }

        if (Dir == lt)
        {
            for(int ttr = r - 1; ttr <= r+1;ttr ++)
            {
                for(int ttc = c + 1; ttc <= c+3;ttc ++)
                {
                    if(sitrep.thing[ttr][ttc].what == unit && sitrep.thing[ttr][ttc].tla!=tla){success = true;}                }
            }
        }
        if (Dir == dn)
        {
            for(int ttr = r + 1; ttr <= r+3;ttr ++)
            {
                for(int ttc = c - 1; ttc <= c+1;ttc ++)
                {
                    if(sitrep.thing[ttr][ttc].what == unit && sitrep.thing[ttr][ttc].tla!=tla){success = true;}               }

            }
        }
        if (Dir == up)
        {
        for(int ttr = r - 3; ttr <= r-1;ttr ++)
        {
            for(int ttc = c - 1; ttc <= c+1;ttc ++)
            {
                if(sitrep.thing[ttr][ttc].what == unit && sitrep.thing[ttr][ttc].tla!=tla){success = true;}
            }
        }
        }
    }
    return success;
}

Location bos::miniMap(int minR, int maxR, int minC, int maxC, SitRep sitrep)
{
    Location kingSpace;
        int mapTest[maxR-minR+1][maxC-minC+1];
    int dummy = 0;
    for (int row = 0; row < maxR-minR+1; row++)
    {
        for(int col = 0; col < maxC-minC+1;col++)
        {
            if( row ==0 || col == 0 || row == (maxR-minR+1) || col == (maxC-minC+1) /*|| sitrep.thing[row][col].what == rock*/) mapTest[row][col] = 0;
            else mapTest[row][col] = 1000;
        }
    }



    for (dummy=0; dummy < 40; dummy++)
    {
        for (int row = 0;row <maxR-minR+1;row++)
        {
            for(int col = 0;col <maxC-minC+1;col++)
            {
                if (mapTest[row][col] == 1000)
                {
                    if(mapTest[row+1][col] == dummy || mapTest[row-1][col] == dummy || mapTest[row][col-1] == dummy || mapTest[row][col+1] == dummy) mapTest[row][col] = dummy+1;
                    else mapTest[row][col] = mapTest[row][col];
                }
            }
        }
    }
    //END THE ARRAY
    //FIND THE KINGS POSITION
    int num = mapTest[0][0];
    int kingRow, kingCol;
    for(int row=0; row < maxR-minR+1; row++)
    {
        for(int col = 0; col < maxC-minC+1; col++)
        {
            if(num < mapTest[row][col]){kingRow = row; kingCol = col; num = mapTest[row][col];}
        }
    }
    kingSpace.r = kingRow + minR + 1 ;
    kingSpace.c = kingCol + minC + 1;
    kingSpace.dirFor = none;

    return kingSpace;
}


int bos::distanceTo(int row, int col ,int tr, int tc)
{
    int dc = tc - col; if(dc < 0) dc *= -1;
    int dr = tr - row; if(dr < 0) dr *= -1;
    return dr+dc;
}
































Action bos::Recommendation(SitRep sitrep)
{
    Action a;

    int tr = r;
    int tc = c;
    int rr = r;
    int cc = c;

    if (rank ==infantry || rank==knight)
    {
        switch(dir)
        {
            case up: tr--; break;
            case dn: tr++; break;
            case rt: tc++; break;
            case lt: tc--; break;
            case none: break;
        }

        if(tr>=0 && tr<ROWS && tc>=0 && tc<COLS) //Attack what's in front of you
        {
            if(sitrep.thing[tr][tc].what==unit)
            {
                if(sitrep.thing[tr][tc].tla != tla)
                {
                    a.action=attack;
                    a.ar = tr;
                    a.ac = tc;
                    return a;
                }
            }
            else //Movement Function
            {


                if(distanceTo(sitrep.nearestEnemy.r,sitrep.nearestEnemy.c,r,c) < 5) //Go for nearest enemy if they're less than 5 spots
                {
                    if(dir == sitrep.nearestEnemy.dirFor) //If they're facing in same direction and they're less than 20 units away from king, then go towards them
                    {
                        if(distanceTo(kingPos.r,kingPos.c,r,c) < 10)
                        {
                            a.action=fwd; a.maxDist = 1; return a;
                        }
                        else a.action = nothing; return a;

                    }
                    else{a.action=turn; a.dir=sitrep.nearestEnemy.dirFor; return a;}
                }
                else
                {
                    if(dir==sitrep.nearestEnemyCrown.dirFor) //If not, then go for the nearest enemy crown
                    {
                        if(distanceTo(kingPos.r,kingPos.c,r,c) < 10)
                        {
                            a.action=fwd; a.maxDist = 1; return a;
                        }
                        else a.action = nothing; return a;
                    }
                    else{a.action=turn;a.dir=sitrep.nearestEnemyCrown.dirFor; return a;}
                }
            }
        }
    }

    if (rank == archer)
    {
        if(isRange(r,c,dir,sitrep)){a.action = attack; a.ar = arRange(r,c,dir,sitrep).r; a.ac = arRange(r,c,dir,sitrep).c;return a;}
        else
        {
            if (isRange(r,c,up,sitrep)){a.action = turn; a.dir = up;return a;}
            else if (isRange(r,c,dn,sitrep)){a.action = turn; a.dir = dn;return a;}
            else if (isRange(r,c,lt,sitrep)){a.action = turn; a.dir = lt;return a;}
            else if (isRange(r,c,rt,sitrep)){a.action = turn; a.dir = rt;return a;}

            else //Movement Function
            {
                if(distanceTo(sitrep.nearestEnemy.r,sitrep.nearestEnemy.c,r,c) < 5)
                {
                    if(dir == sitrep.nearestEnemy.dirFor)
                    {
                        if(distanceTo(kingPos.r,kingPos.c,r,c) < 10)
                        {
                            a.action=fwd; a.maxDist = 1; return a;
                        }
                        else a.action = nothing; return a;

                    }
                    else{a.action=turn;a.dir=sitrep.nearestEnemy.dirFor; return a;}
                }
                else
                {
                    if(dir==sitrep.nearestEnemyCrown.dirFor)
                    {
                        if(distanceTo(kingPos.r,kingPos.c,r,c) < 10)
                        {
                            a.action=fwd; a.maxDist = 1; return a;
                        }
                        else a.action = nothing; return a;
                    }
                    else{a.action=turn;a.dir=sitrep.nearestEnemyCrown.dirFor; return a;}
                }
            }
        }
    }

    if(rank == crown)
    {
        if(distanceTo(r,c,sitrep.nearestEnemy.r, sitrep.nearestEnemy.c) < 5) //Run away
        {
            switch(sitrep.nearestEnemy.dirFor)
            {

                case up: if (dir == dn){a.action = fwd;kingPos.r++;return a;} else {a.action = turn; a.dir = dn; return a;break;}
                case dn: if (dir == up){a.action = fwd;kingPos.r--;return a;} else {a.action = turn; a.dir = up; return a;break;}
                case rt: if (dir == lt){a.action = fwd;kingPos.c--;return a;} else {a.action = turn; a.dir = lt; return a;break;}
                case lt: if (dir == rt){a.action = fwd;kingPos.c++;return a;} else {a.action = turn; a.dir = rt; return a;break;}
                case none: a.action = nothing; return a; break;
            }
        }
        else //Get closer to army
        {
            if(distanceTo(sitrep.nearestEnemy.r,sitrep.nearestEnemy.c,r,c) <10)
            {
                if(dir==sitrep.nearestEnemy.dirFor)
                {
                    switch(sitrep.nearestEnemy.dirFor)
                    {
                        case up: if (dir == dn){a.action = fwd;a.maxDist = 1;++kingPos.r;return a;}
                        case dn: if (dir == up){a.action = fwd;a.maxDist = 1;--kingPos.r;return a;}
                        case rt: if (dir == lt){a.action = fwd;a.maxDist = 1;--kingPos.c;return a;}
                        case lt: if (dir == rt){a.action = fwd;a.maxDist = 1;++kingPos.c;return a;}
                        case none: a.action = nothing; return a; break;
                    }

                }
                else{a.action=turn;a.dir=sitrep.nearestEnemy.dirFor; return a;}
            }
            else
            {
                if(dir==sitrep.nearestEnemyCrown.dirFor)
                {
                    switch(sitrep.nearestEnemyCrown.dirFor)
                    {
                        case up: if (dir == dn){a.action = fwd;kingPos.r++; return a;} else {a.action = turn; a.dir = dn; return a;break;}
                        case dn: if (dir == up){a.action = fwd;kingPos.r--; return a;} else {a.action = turn; a.dir = up; return a;break;}
                        case rt: if (dir == lt){a.action = fwd;kingPos.c--; return a;} else {a.action = turn; a.dir = lt; return a;break;}
                        case lt: if (dir == rt){a.action = fwd;kingPos.c++; return a;} else {a.action = turn; a.dir = rt; return a;break;}
                        case none: a.action = nothing; return a; break;
                    }
                }
                else{a.action=turn;a.dir=sitrep.nearestEnemyCrown.dirFor; return a;}

            }
        }
    }
}



























void bos::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{

    srand(time(NULL));
	int ttr,ttc;

    if (rank==crown)
    {
        r = miniMap(minR, maxR, minC, maxC, sitrep).r;
        c = miniMap(minR, maxR, minC, maxC, sitrep).c;
        kingPos.r = r; kingPos.c = c;
    }
    else
    {

        if (rank == archer)
        {
            bool done=false;
            while (!done)
            {
                ttr=minR+rand()%(maxR-minR);
                ttc=minC+rand()%(maxC-minC);
                if(sitrep.thing[ttr][ttc].what==space && distanceTo(ttr, ttc, kingPos.r, kingPos.c) > 3 && distanceTo(ttr, ttc, kingPos.r, kingPos.c) < 5)
                {
                    if(kingPos.c < ROWS / 2)
                    {
                        if(ttc >= kingPos.c) done = true;
                    }
                    else
                    {
                        if(ttc <= kingPos.c) done = true;
                    }
                }
            }
            r = ttr;
            c = ttc;


        }
        else if (rank == knight)
        {

            bool done=false;
            while (!done)
            {
                ttr=minR+rand()%(maxR-minR);
                ttc=minC+rand()%(maxC-minC);
                if(sitrep.thing[ttr][ttc].what==space && distanceTo(ttr, ttc, kingPos.r, kingPos.c) < 3)
                {
                    if(kingPos.c < ROWS / 2)
                    {
                        if(ttc >= kingPos.c) done = true;
                    }
                    else
                    {
                        if(ttc <= kingPos.c) done = true;
                    }
                }
            }
            r = ttr;
            c = ttc;

        }
        else if (rank == infantry)
        {

            bool done=false;
            while (!done)
            {
                ttr=minR+rand()%(maxR-minR);
                ttc=minC+rand()%(maxC-minC);
                if(sitrep.thing[ttr][ttc].what==space && distanceTo(ttr, ttc, kingPos.r, kingPos.c) > 5 && distanceTo(ttr, ttc, kingPos.r, kingPos.c) < 8)
                {


                    if(kingPos.c < ROWS / 2)
                    {
                        if(ttc >= kingPos.c) done = true;
                    }
                    else
                    {
                        if(ttc <= kingPos.c) done = true;
                    }
                }
            }
            r = ttr;
            c = ttc;
        }
    }

if(kingPos.c < ROWS / 2) dir = rt;
else dir = lt;

}





