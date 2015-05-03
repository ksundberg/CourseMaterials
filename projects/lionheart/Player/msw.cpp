#include "msw.h"
#include <cmath>
#include <iostream>


void msw::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{
	//cout << "minRow: " << minR << endl;
	//cout << "maxRow: " << maxR << endl;
	//cout << "minCol: " << minC << endl;
	//cout << "maxCol: " << maxC << endl;
bool done=false;
int tr,tc;
Dir td;

if(rank==crown)
{
	if (minC==0)
	{
		g_mySide=lt;
	}
	else 
	{
		g_mySide=rt;
	}

	tr=15;//(maxR-minR)/2;

	if (g_mySide==lt)
	{
		tc=minC;
		td=rt;
	}
	else 
	{
		tc=maxC;
		td=lt;
	}
}
else
{
	while(!done)
	{
	tr=minR+rand()%(maxR-minR);
	tc=minC+rand()%(maxC-minC);
	if(sitrep.thing[tr][tc].what==space)done=true;
	}

	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;

	if(abs(rdist)<abs(cdist))
	{
		if(cdist>0)td=rt;
		else td=lt;
	}
	else
	{
		if(rdist>0)td=up;
		else td=dn;
	}

}
r=tr;
c=tc;
dir=td;
}

// tell someone what you want to do
Action msw::Recommendation(SitRep sitrep)
{
// this code is provided as an example only
// use at your own risk
Action myAction;

// first, try to attack in front of you
int tr=r,tc=c;
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
myAction.action=attack;
myAction.ar=tr;
myAction.ac=tc;
return myAction;
}
}
}
// there is not an enemy in front of me

// try to hunt down the enemy crown
if (rank==archer || rank==infantry || rank==knight)
{
if(sitrep.nearestEnemyCrown.dirFor!=none){
if(dir==sitrep.nearestEnemyCrown.dirFor){
myAction.action=fwd;
myAction.maxDist=1;
return myAction;
}else{
myAction.action=turn;
myAction.dir=sitrep.nearestEnemyCrown.dirFor;
return myAction;
}
}


//else hunt down nearest enemy
if(sitrep.nearestEnemy.dirFor!=none){
if(dir==sitrep.nearestEnemy.dirFor){
myAction.action=fwd;
myAction.maxDist=1;
return myAction;
}else{
myAction.action=turn;
myAction.dir=sitrep.nearestEnemy.dirFor;
return myAction;
}
}

//else turn toward any free space
if(sitrep.anyOpenSpace!=none){
myAction.action=turn;
myAction.dir=sitrep.anyOpenSpace;
return myAction;
}
}
//else do nothing
if (rank==crown){
myAction.action=nothing;
return myAction;
}
}

