#include "jfr.h"
#include <cmath>
#include <iostream>
 
 
void jfr::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
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
 
 
// tell someone what you want to do
Action jfr::Recommendation(SitRep sitrep){
      
       Action a;
 
       // Attack in front
       int tr=r,tc=c;
       switch(dir){
       case up: tr--; break;
       case dn: tc++; break;
       case rt: tr++; break;
       case lt: tc--; break;
       case none: break;
       }
       if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
              if(sitrep.thing[tr][tc].what==unit){
                     if(sitrep.thing[tr][tc].tla!=tla){
                           a.action=attack;
                           a.ar=tr;
                           a.ac=tc;
                           a.maxDist=HORSESPEED;
                           a.dir=dir;
                           return a;
                     }
              }
       }     
if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS){
              if(sitrep.thing[tr][tc].what==rock){
                     if(sitrep.thing[tr][tc].tla!=tla){
                           a.action=turn;
                           a.maxDist=HORSESPEED;
                           a.dir=dir;
                           return a;
                     }
              }
       }     
 
       // no enemy in front of me-head to nearest enemy
       if(dir==sitrep.nearestEnemy.dirFor){
              a.action=fwd;
              a.maxDist=1;
              if(rank==infantry||rank==crown)a.maxDist=HORSESPEED;
              return a;
       } else{
              a.action=turn;
              a.dir=sitrep.nearestEnemy.dirFor;
              return a;
       }
 
       // try to hunt down the enemy crown
if(sitrep.nearestEnemyCrown.dirFor!=none){
if(dir==sitrep.nearestEnemyCrown.dirFor){
a.action=fwd;
a.maxDist=2;
return a;
}else{
a.action=turn;
a.dir=sitrep.nearestEnemyCrown.dirFor;
return a;
}
 
if(rank==infantry&& dir==sitrep.nearestEnemy.dirFor){
       a.action=attack;
       return a;
}
}
//Attack Enemy crown if above
if(sitrep.nearestEnemyCrown.dirFor=up){
if(dir==sitrep.nearestEnemyCrown.dirFor){
       a.action=attack;
       return a;
}
}
 
//Attack Enemy crown if left
if(sitrep.nearestEnemyCrown.dirFor=lt){
if(dir==sitrep.nearestEnemyCrown.dirFor){
       a.action=attack;
       return a;
}
}
 
//Attack Enemy crown if rt
if(sitrep.nearestEnemyCrown.dirFor=rt){
if(dir==sitrep.nearestEnemyCrown.dirFor){
       a.action=attack;
       return a;
}
}
 
//Attack Enemy crown if dn
if(sitrep.nearestEnemyCrown.dirFor=dn){
if(dir==sitrep.nearestEnemyCrown.dirFor){
       a.action=attack;
       return a;
}
}
 
//else turn toward any free space
if(sitrep.anyOpenSpace!=none){
a.action=turn;
a.dir=sitrep.anyOpenSpace;
return a;
}
       a.action=nothing;
       return a;
      
}