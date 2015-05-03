/********************************************************************************************************
 *                              ASSIGNMENT 11, LION HEART			                        			*
 *					                    hoe.cpp								                            *
 *  Zachariah Yoshikawa                                                            			            *
 *  A01417300                                                                    			            *
 *  CS1400 - 003 w/ Dan Watson                                                                          *
 ********************************************************************************************************/
#include "hoe.h"
#include <cmath>
#include <iostream>

void hoe::Place(int minR,int maxR,int minC,int maxC, SitRep s)
{
    static int archerCount=1;
	bool done=false;
	int tr,tc;
	Dir td;

    //set fwd direction dependent on location
    if((maxR+minR)/2>=(maxC+minC)/2)
    {
        if((maxC+minC)/2<COLS/3)
        {
            td=rt;
        }else
        {
            td=up;
        }
    }
    if((maxR+minR)/2<=(maxC+minC)/2)
    {
        if((maxR+minR)/2>ROWS/3)
        {
            td=lt;
        }else
        {
            td=dn;
        }
    }

	if(rank==crown)
	{//place crown first
		switch(td)
		{//td direction will indicate to place on min or max for tr and tc
		case up:
            tr = maxR;
            tc=(minC+maxC)/2;
			break;
		case dn:
			tr = minR;
			tc=(minC+maxC)/2;
			break;
		case lt:
            tr=(minR+maxR)/2;
			tc = maxC;
			break;
		case rt:
            tr=(minR+maxR)/2;
			tc = minC;
			break;
		}
	}else if(rank==archer&&archerCount<=8)
	{//place archers next to crown
        switch(td)
        {
        case up:
            while(!done)
            {
                tr=minR+rand()%(3);
                tc=(((minC+maxC)/2)-1)+rand()%(3);
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case dn:
            while(!done)
            {
                tr=maxR-rand()%(3);
                tc=(((minC+maxC)/2)-1)+rand()%(3);
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case lt:
            while(!done)
            {
                tr=(((minR+maxR)/2)-1)+rand()%(3);
                tc=maxC-rand()%(3);
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case rt:
            while(!done)
            {
                tr=(((minR+maxR)/2)-1)+rand()%(3);
                tc=minC+rand()%(3);
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        }
        ++archerCount;
	}else if(rank==infantry)
	{
        switch(td)
        {
        case up:
            while(!done)
            {
                tr=maxR-3;
                tc=minC+rand()%(maxC-minC);
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case dn:
            while(!done)
            {
                tr=minR+3;
                tc=minC+rand()%(maxC-minC);
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case lt:
            while(!done)
            {
                tr=minR+rand()%(maxR-minR);
                tc=maxC-3;
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case rt:
            while(!done)
            {
                tr=minR+rand()%(maxR-minR);
                tc=minC+3;
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        }



    }else
	{
        switch(td)
        {
        case up:
            while(!done)
            {
                tr=maxR-4;
                tc=minC+rand()%(maxC-minC);
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case dn:
            while(!done)
            {
                tr=minR+4;
                tc=minC+rand()%(maxC-minC);
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case lt:
            while(!done)
            {
                tr=minR+rand()%(maxR-minR);
                tc=maxC-4;
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        case rt:
            while(!done)
            {
                tr=minR+rand()%(maxR-minR);
                tc=minC+4;
                if(s.thing[tr][tc].what==space)done=true;
            }
            break;
        }
	}



    //direction of unit
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

Action hoe::Recommendation(SitRep s){
	Action a;
    int tr=r,tc=c;



    if(rank==crown){
        a.action=nothing;
        return a;
/*
        if(rand()%6<4){
            if(s.nearestEnemy.dirFor==up){
                a.action=turn;
                a.dir=dn;
            }else if(s.nearestEnemy.dirFor==dn){
                a.action=turn;
                a.dir=up;
            }else if(s.nearestEnemy.dirFor==lt){
                a.action=turn;
                a.dir=rt;
            }else if(s.nearestEnemy.dirFor==rt){
                a.action=turn;
                a.dir=lt;
            }
            if(s.thing[tr][tc].what!=space){
                a.action=turn;
                a.dir=s.anyOpenSpace;
            }
            return a;
        }else{
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        }
*/
    }//end crown



    if(rank==knight){
        switch(dir)
        {
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
        }
        //if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
            if(s.thing[tr][tc].what==unit){
                if(s.thing[tr][tc].tla!=tla){
                    a.action=attack;
                    return a;
                }
            }
        //}
        if(dir==s.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        }else{
            a.action=turn;
            a.dir=s.nearestEnemyCrown.dirFor;
            return a;
            a.action=fwd;
            a.maxDist=HORSESPEED;
            return a;
        }
        //if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
            if(s.thing[tr][tc].what==unit){
                if(s.thing[tr][tc].tla!=tla){
                    a.action=attack;
                    return a;
                }
            }
        //}
    }//end knight



	if(rank==archer){
		switch(dir)
		{
		case up: tr=tr-3; tc=tc-1;
			break;
		case dn: tr=tr+1; tc=tc-1;
			break;
		case rt: tr=tr-1; tc=tc+1;
			break;
		case lt: tr=tr-1; tc=tc-3;
			break;
		case none:
			break;
		}
		for(int i=0;i<3;i++)
		{ // Scan a 3x3 box for enemy units
			for(int j=0;j<3;j++)
			{
				if(s.thing[tr+i][tc+j].what==unit)
				{
					if(s.thing[tr+i][tc+j].tla!=tla)
					{
					a.action=attack;
					a.ar=tr+i;
					a.ac=tc+j;
					return a;
					}
				}
			}
		}

		a.action=turn;
		a.dir=s.nearestEnemy.dirFor;
		return a;

		for(int i=0;i<3;i++)
		{ // Scan a 3x3 box for enemy units
			for(int j=0;j<3;j++)
			{
				if(s.thing[tr+i][tc+j].what==unit)
				{
					if(s.thing[tr+i][tc+j].tla!=tla)
					{
					a.action=attack;
					a.ar=tr+i;
					a.ac=tc+j;
					return a;
					}
				}
			}
		}

	}


/*
        if(dir==s.nearestEnemyCrown.dirFor){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }else{
            a.action=turn;
            a.dir=s.nearestEnemyCrown.dirFor;
            return a;
            a.action=fwd;
            a.maxDist=1;
            return a;
        }



            if(s.thing[tr][tc].what==unit){
                if(s.thing[tr][tc].tla!=tla){
                    if(s.thing[tr][tc].rank==crown){
                        a.action=attack;
                        a.ar=s.nearestEnemyCrown.r;
                        a.ac=s.nearestEnemyCrown.c;
                        return a;
                    }else{
                        a.action=attack;
                        a.ar=s.nearestEnemy.r;
                        a.ac=s.nearestEnemy.c;
                        return a;
                    }
                }
            }
*/



    if(rank==infantry){
        switch(dir)
        {
        case up: tr--; break;
        case dn: tr++; break;
        case rt: tc++; break;
        case lt: tc--; break;
        case none: break;
        }


        //if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
            if(s.thing[tr][tc].what==unit){
                if(s.thing[tr][tc].tla!=tla){
                    a.action=attack;
                    return a;
                }
            }
        //}
    	if(dir==s.nearestEnemy.dirFor){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }else{
            a.action=turn;
            a.dir=s.nearestEnemy.dirFor;
            return a;
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        //if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
            if(s.thing[tr][tc].what==unit){
                if(s.thing[tr][tc].tla!=tla){
                    a.action=attack;
                    return a;
                }
            }
        //}
    }//end infantry



}//end recommendation function






