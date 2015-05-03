#include "boo.h"
#include <cmath>
#include <iostream>

static Location REY;
void boo::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{
	bool done=false;
	int tr,tc;
	Dir td;

	if(rank==crown)
	{
        if(minC-0<COLS-maxC)
        {
            for(tr = minR;tr <= maxR; tr++)
            {
                if(done)break;
                for(tc = minC;tc <= minC+2; tc++)
                {
                    if(sitrep.thing[tr][tc].what==space)
                    {
                    r = tr;
                    c = tc;
                    dir=dn;
                    done=true;
                    REY.r=tr;
                    REY.c=tc;
                    REY.dirFor=dn;
                    break;

                    }
                }
            }
        }
        else if(minC-0>=COLS-maxC)
        {
             for(tr = minR;tr <= maxR; tr++)
            {
                if(done)break;
                for(tc = maxC;tc >= maxC-2; tc--)
                {
                    if(sitrep.thing[tr][tc].what==space)
                    {
                    r = tr;
                    c = tc;
                    dir=dn;
                    done=true;
                    REY.r=tr;
                    REY.c=tc;
                    REY.dirFor=dn;
                    break;
                    }
                }
            }
        }
        else
        {
            while(!done)
            {
            tr=minR+rand()%(maxR-minR);
            tc=minC+rand()%(maxC-minC);
                if(sitrep.thing[tr][tc].what==space)
                {
                done=true;
                r=tr;
                c=tc;
                dir=dn;
                REY.r=tr;
                REY.c=tc;
                REY.dirFor=dn;
                }
            }
        }
	}
    else if(rank==knight)
    {
        if(minC-0<COLS-maxC)
        {
            for(tr = minR+1;tr <= maxR; tr++)
            {
                if(done)break;
                for(tc = minC;tc <= minC+3; tc++)
                {
                    if(sitrep.thing[tr][tc].what==space)
                    {
                    r = tr;
                    c = tc;
                    dir=dn;
                    break;
                    done=true;
                    }
                }
            }
        }
        else if(minC-0>=COLS-maxC)
        {
             for(tr = minR+1;tr <= maxR; tr++)
            {
                if(done)break;
                for(tc = maxC;tc >= maxC-3; tc--)
                {
                    if(sitrep.thing[tr][tc].what==space)
                    {
                    r = tr;
                    c = tc;
                    dir=dn;
                    break;
                    done=true;
                    }
                }
            }
        }
        else
        {
            while(!done)
            {
            tr=minR+rand()%(maxR-minR);
            tc=minC+rand()%(maxC-minC);
                if(sitrep.thing[tr][tc].what==space)
                {
                done=true;
                r=tr;
                c=tc;
                dir=dn;
                }
            }
        }
    }
     else if(rank==archer)
    {
        if(minC-0<COLS-maxC)
        {
            for(tr = minR;tr <= maxR; tr++)
            {
                if(done)break;
                for(tc = minC;tc <= minC+3; tc++)
                {
                    if(sitrep.thing[tr][tc].what==space)
                    {
                    r = tr;
                    c = tc;
                    dir=dn;
                    break;
                    done=true;
                    }
                }
            }
        }
        else if(minC-0>=COLS-maxC)
        {
             for(tr = minR;tr <= maxR; tr++)
            {
                if(done)break;
                for(tc = maxC;tc >= maxC-3; tc--)
                {
                    if(sitrep.thing[tr][tc].what==space)
                    {
                    r = tr;
                    c = tc;
                    dir=dn;
                    break;
                    done=true;
                    }
                }
            }
        }
        else
        {
            while(!done)
            {
            tr=minR+rand()%(maxR-minR);
            tc=minC+rand()%(maxC-minC);
                if(sitrep.thing[tr][tc].what==space)
                {
                done=true;
                r=tr;
                c=tc;
                dir=dn;
                }
            }
        }
    }
    else if(rank==infantry)
    {
        if(minC-0<COLS-maxC)
        {
            for(tr = minR;tr <= maxR; tr++)
            {
                if(done)break;
                for(tc = minC;tc <= maxC; tc++)
                {
                    if(sitrep.thing[tr][tc].what==space)
                    {
                    r = tr;
                    c = tc;
                    dir=dn;
                    break;
                    done=true;
                    }
                }
            }
        }
        else if(minC-0>=COLS-maxC)
        {
             for(tr = minR;tr <= maxR; tr++)
            {
                if(done)break;
                for(tc = maxC;tc >= maxC; tc--)
                {
                    if(sitrep.thing[tr][tc].what==space)
                    {
                    r = tr;
                    c = tc;
                    dir=dn;
                    break;
                    done=true;
                    }
                }
            }
        }
        else
        {
            while(!done)
            {
            tr=minR+rand()%(maxR-minR);
            tc=minC+rand()%(maxC-minC);
                if(sitrep.thing[tr][tc].what==space)
                {
                done=true;
                r=tr;
                c=tc;
                dir=dn;
                }
            }
        }
    }

else
    {
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
	dir=dn;
    }
}
/**********************************************************************************************************
**********************************************************************************************************/

Action boo::Recommendation(SitRep sitrep)
{
    Action a;
    int m, n, tr, tc;
    if(sitrep.turnNumber<250)
    {
 /********************************************************************
 *****************************************************************/
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



    if(rank==crown)
    {
        m = Unit::getC();
        n = Unit::getR();
        if(m*m+(n-ROWS)*(n-ROWS)<(m-COLS)*(m-COLS)+(n-ROWS)*(n-ROWS))
        {
            if(dir==sitrep.thing[tr=ROWS][tc==0].dir)
            {
            a.action=fwd;
            a.maxDist=1;
            return a;
            switch(Unit::getDir()){
        case up: n--; break;
        case dn: n++; break;
        case rt: m++; break;
        case lt: m--; break;
        case none: break;
        }
            REY.r=n;
            REY.c=m;
            REY.dirFor=dn;
            }
            else
            {
            a.action=turn;
            a.dir=sitrep.thing[tr==ROWS][tc==0].dir;
            return a;
            switch(Unit::getDir()){
        case up: n--; break;
        case dn: n++; break;
        case rt: m++; break;
        case lt: m--; break;
        case none: break;
        }
            REY.r=n;
            REY.c=m;
            REY.dirFor=sitrep.thing[tr==0][tc==0].dir;
            }
        }
        else
        {
            if(dir==sitrep.thing[tr==0][tc==COLS].dir)
            {
            a.action=fwd;
            a.maxDist=1;
            return a;
            REY.r=n;
            REY.c=m;
            REY.dirFor=dn;
            }
            else
            {
            a.action=turn;
            a.dir=sitrep.thing[tr==ROWS][tc==COLS].dir;
            return a;
            REY.r=n;
            REY.c=m;
            REY.dirFor=sitrep.thing[tr==ROWS][tc==COLS].dir;
            }
    }
    }
    else if(rank!=crown)
    {
        if(dir==sitrep.thing[tr==REY.r][tc==REY.c].dir)
        {
        a.action=fwd;
        a.maxDist=1;
        return a;
        }
        else
        {
        a.action=turn;
        a.dir=sitrep.thing[tr==REY.r][tc==REY.c].dir;
        return a;
    }





}
    else
    {
     if(rank!=crown)
    {

     	int tr=r,tc=c;
	switch(dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS)
    {
		if(sitrep.thing[tr][tc].what==unit)
		{
			if(sitrep.thing[tr][tc].tla!=tla)
            {
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}

	if(dir==sitrep.nearestEnemyCrown
    .dirFor){
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

}




    }
    }


}

