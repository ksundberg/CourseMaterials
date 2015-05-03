#include "jmh.h"
#include "lionheart2.h"
#include <cmath>
#include <iostream>


//PLACEMENT
void jmh::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr,tc;
	Dir td;
	static int icount=0;
	static int acount=0;
	static int kcount=0;
	string mapname=INFILE;

	//ASSIGN SIDE
	if(minC<15){
	jmh::setside(1);}
	if(minC>13){
    jmh::setside(2);}
    if(mapname=="4player.in"){
        if(minR==0&&minC==4)jmh::setside(1);
        if(minR==27&&minC==4)jmh::setside(2);
        if(minR==4&&minC==0)jmh::setside(3);
        if(minR==4&&minC==27)jmh::setside(4);
    }

	//ASSIGN UNIT IDs
	if(rank==crown){
        jmh::setUnitid(0);
	}
	if(rank==infantry){
        ++icount;
        jmh::setUnitid(icount);
	}
	if(rank==archer){
        ++acount;
        jmh::setUnitid(acount+30);
	}
	if(rank==knight){
        ++kcount;
        jmh::setUnitid(kcount+50);
	}
	//SET UNIT ORDERS
	if(unitid>0&&unitid<7){
        jmh::setUnitorder(1);}
    if(unitid>6&&unitid<13){
        jmh::setUnitorder(3);}
	if(unitid>12&&unitid<60){
        jmh::setUnitorder(1);}
    //PLACEMENT BEGINS
    while(!done){
		tr=minR+rand()%(maxR+1-minR);
		tc=minC+rand()%(maxC+1-minC);
		if(sitrep.thing[tr][tc].what==space)done=true;
		if(tr<minR+(maxR-minR)/2+2&&tr>minR+(maxR-minR)/2-2&&tc<minC+(maxC-minC)/2+2&&tc>minC+(maxC-minC)/2-2)done=false;
	}
	if(rank==crown){
        tr=minR+(maxR-minR)/2;
        tc=minC+(maxC-minC)/2;
        jmh::setUnitorder(0);
    }
    if(unitid==1){
        tr=minR+(maxR-minR)/2+1;
        tc=minC+(maxC-minC)/2;
        jmh::setUnitorder(1);
    }
    if(unitid==2){
        tr=minR+(maxR-minR)/2-1;
        tc=minC+(maxC-minC)/2;
        jmh::setUnitorder(1);
    }
    if(unitid==3){
        tr=minR+(maxR-minR)/2;
        tc=minC+(maxC-minC)/2+1;
        jmh::setUnitorder(1);
    }
    if(unitid==4){
        tr=minR+(maxR-minR)/2;
        tc=minC+(maxC-minC)/2-1;
        jmh::setUnitorder(1);
    }
    if(unitid==31){
        tr=minR+(maxR-minR)/2+1;
        tc=minC+(maxC-minC)/2+1;
        jmh::setUnitorder(3);
    }
    if(unitid==32){
        tr=minR+(maxR-minR)/2-1;
        tc=minC+(maxC-minC)/2+1;
        jmh::setUnitorder(3);
    }
    if(unitid==33){
        tr=minR+(maxR-minR)/2+1;
        tc=minC+(maxC-minC)/2-1;
        jmh::setUnitorder(3);
    }
    if(unitid==34){
        tr=minR+(maxR-minR)/2-1;
        tc=minC+(maxC-minC)/2-1;
        jmh::setUnitorder(3);
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

    if(mapname=="map2.in"){
	//PLACEMENT ON WEST SIDE OF MAP2.IN
	if(sideofmap==1){
	//START of Crown placement on West side of Map2.in
	if(rank==crown){
        tr=20,tc=5, dir=rt;
        done=true;
	}
	//END of Crown placement on West side of Map2.in
    //START of Knight placement on West side of Map2.in
    if(unitid==51){
        tr=10,tc=5,dir=up;
        done=true;
    }
    if(unitid==54){
        tr=19,tc=5,dir=rt;
        done=true;
    }
    if(unitid==56){
        tr=20,tc=4,dir=rt;
        done=true;
    }
    if(unitid==52){
        tr=10,tc=4,dir=up;
        done=true;
    }
    if(unitid==55){
        tr=19,tc=4,dir=rt;
        done=true;
    }
    if(unitid==53){
        tr=10,tc=0,dir=up;
        done=true;
    }
    //END of Knight placement on West side of Map2.in
    //START of Infantry placement on West side of Map2.in
        //Central force
    if(unitid==1){
        tr=14,tc=5,dir=rt;
        done=true;
    }
    if(unitid==2){
        tr=15,tc=5,dir=rt;
        done=true;
    }
    if(unitid==3){
        tr=14,tc=4,dir=rt;
        done=true;
    }
    if(unitid==4){
        tr=15,tc=4,dir=rt;
        done=true;
    }
    if(unitid==5){
        tr=14,tc=1,dir=rt;
        done=true;
    }
    if(unitid==6){
        tr=15,tc=1,dir=rt;
        done=true;
    }
        //End central force
        //King's guard
    if(unitid==7){
        tr=18,tc=5,dir=rt;
        done=true;
    }
    if(unitid==8){
        tr=18,tc=4,dir=rt;
        done=true;
    }
    if(unitid==9){
        tr=17,tc=5,dir=rt;
        done=true;
    }
    if(unitid==10){
        tr=17,tc=4,dir=rt;
        done=true;
    }
    if(unitid==11){
        tr=16,tc=5,dir=rt;
        done=true;
    }
    if(unitid==12){
        tr=16,tc=4,dir=rt;
        done=true;
    }
        //End king's guard
        //King hunters
    if(unitid==13){
        tr=11,tc=5,dir=up;
        done=true;
    }
    if(unitid==14){
        tr=11,tc=4,dir=up;
        done=true;
    }
    if(unitid==15){
        tr=11,tc=3,dir=up;
        done=true;
    }
    if(unitid==16){
        tr=11,tc=2,dir=up;
        done=true;
    }
    if(unitid==17){
        tr=11,tc=1,dir=up;
        done=true;
    }
    if(unitid==18){
        tr=11,tc=0,dir=up;
        done=true;
    }
    if(unitid==19){
        tr=10,tc=0,dir=up;
        done=true;
    }
    if(unitid==20){
        tr=10,tc=1,dir=up;
        done=true;
    }
    //START Archer placement on West side of Map2.in
        //Central force
    if(unitid==31){
        tr=14,tc=3,dir=rt;
        jmh::setUnitorder(1);
        done=true;
    }
    if(unitid==32){
        tr=15,tc=3,dir=rt;
        jmh::setUnitorder(1);
        done=true;
    }
    if(unitid==33){
        tr=14,tc=2,dir=rt;
        jmh::setUnitorder(1);
        done=true;
    }
    if(unitid==34){
        tr=15,tc=2,dir=rt;
        jmh::setUnitorder(1);
        done=true;
    }
        //End central force
        //King hunters
     if(unitid==35){
        tr=10,tc=3,dir=up;
        done=true;
    }
    if(unitid==36){
        tr=10,tc=2,dir=up;
        done=true;
    }
    if(unitid==37){
        tr=10,tc=1,dir=up;
        done=true;
    }
        //End king hunters
        //King guard
    if(unitid==38){
        tr=20,tc=3,dir=rt;
        done=true;
    }
    if(unitid==39){
        tr=20,tc=2,dir=rt;
        done=true;
    }
    if(unitid==40){
        tr=20,tc=1,dir=rt;
        done=true;
    }
        //End king guard
    //END Archer placement on West side of Map2.in
}
    //PLACEMENT ON EAST SIDE OF MAP2.IN
	if(sideofmap==2){
	if(rank==crown){
        tr=10,tc=24, dir=lt;
        done=true;
	}
	//END of Crown placement on West side of Map2.in
    //START of Knight placement on West side of Map2.in
    if(unitid==51){
        tr=20,tc=24,dir=dn;
        done=true;
    }
    if(unitid==54){
        tr=11,tc=24,dir=lt;
        done=true;
    }
    if(unitid==56){
        tr=10,tc=25,dir=lt;
        done=true;
    }
    if(unitid==52){
        tr=20,tc=25,dir=dn;
        done=true;
    }
    if(unitid==55){
        tr=11,tc=25,dir=lt;
        done=true;
    }
    if(unitid==53){
        tr=20,tc=29,dir=dn;
        done=true;
    }
    //END of Knight placement on West side of Map2.in
    //START of Infantry placement on West side of Map2.in
        //Central force
    if(unitid==1){
        tr=15,tc=24,dir=lt;
        done=true;
    }
    if(unitid==2){
        tr=14,tc=24,dir=lt;
        done=true;
    }
    if(unitid==3){
        tr=15,tc=25,dir=lt;
        done=true;
    }
    if(unitid==4){
        tr=14,tc=25,dir=lt;
        done=true;
    }
    if(unitid==5){
        tr=15,tc=28,dir=lt;
        done=true;
    }
    if(unitid==6){
        tr=14,tc=28,dir=lt;
        done=true;
    }
        //End central force
        //King's guard
    if(unitid==7){
        tr=12,tc=24,dir=lt;
        done=true;
    }
    if(unitid==8){
        tr=12,tc=25,dir=lt;
        done=true;
    }
    if(unitid==9){
        tr=13,tc=24,dir=lt;
        done=true;
    }
    if(unitid==10){
        tr=13,tc=25,dir=lt;
        done=true;
    }
    if(unitid==11){
        tr=16,tc=24,dir=lt;
        done=true;
    }
    if(unitid==12){
        tr=16,tc=25,dir=lt;
        done=true;
    }
        //End king's guard
        //King hunters
    if(unitid==13){
        tr=19,tc=24,dir=dn;
        done=true;
    }
    if(unitid==14){
        tr=19,tc=25,dir=dn;
        done=true;
    }
    if(unitid==15){
        tr=19,tc=26,dir=dn;
        done=true;
    }
    if(unitid==16){
        tr=19,tc=27,dir=dn;
        done=true;
    }
    if(unitid==17){
        tr=19,tc=28,dir=dn;
        done=true;
    }
    if(unitid==18){
        tr=19,tc=29,dir=dn;
        done=true;
    }
    if(unitid==19){
        tr=20,tc=29,dir=dn;
        done=true;
    }
    if(unitid==20){
        tr=20,tc=28,dir=dn;
        done=true;
    }
    //START Archer placement on West side of Map2.in
        //Central force
    if(unitid==31){
        tr=14,tc=26,dir=lt;
        jmh::setUnitorder(1);
        done=true;
    }
    if(unitid==32){
        tr=15,tc=26,dir=lt;
        jmh::setUnitorder(1);
        done=true;
    }
    if(unitid==33){
        tr=14,tc=27,dir=lt;
        jmh::setUnitorder(1);
        done=true;
    }
    if(unitid==34){
        tr=15,tc=27,dir=lt;
        jmh::setUnitorder(1);
        done=true;
    }
        //End central force
        //King hunters
     if(unitid==35){
        tr=20,tc=26,dir=dn;
        done=true;
    }
    if(unitid==36){
        tr=20,tc=27,dir=dn;
        done=true;
    }
    if(unitid==37){
        tr=20,tc=28,dir=dn;
        done=true;
    }
        //End king hunters
        //King guard
    if(unitid==38){
        tr=10,tc=26,dir=lt;
        done=true;
    }
    if(unitid==39){
        tr=10,tc=27,dir=lt;
        done=true;
    }
    if(unitid==40){
        tr=10,tc=28,dir=lt;
        done=true;
    }
        //End king guard
    //END Archer placement on West side of Map2.in

}
r=tr;
c=tc;
}
	if(mapname=="navy.in"){
        if(sideofmap==1){
        if(unitid==31){
            tr=6;
            tc=13;
            dir=rt;}
        if(unitid==32){
            tr=8;
            tc=13;
            dir=rt;}
        if(unitid==33){
            tr=9;
            tc=13;
            dir=rt;}
        if(unitid==34){
            tr=11;
            tc=13;
            dir=rt;}
        if(unitid==35){
            tr=13;
            tc=13;
            dir=rt;}
        if(unitid==36){
            tr=16;
            tc=13;
            dir=rt;}
        if(unitid==37){
            tr=18;
            tc=13;
            dir=rt;}
        if(unitid==38){
            tr=20;
            tc=13;
            dir=rt;}
        if(rank==crown){
            tr=6;
            tc=7;
            dir=up;}
        if(unitid==51){
            tr=22;
            tc=13;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==52){
            tr=22;
            tc=12;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==53){
            tr=22;
            tc=11;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==54){
            tr=22;
            tc=10;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==55){
            tr=22;
            tc=9;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==56){
            tr=22;
            tc=8;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==1){
            tr=7;
            tc=13;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==2){
            tr=10;
            tc=13;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==3){
            tr=14;
            jmh::setUnitorder(1);
            tc=13;
            dir=rt;}
        if(unitid==4){
            tr=15;
            tc=13;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==5){
            tr=19;
            tc=13;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==6){
            tr=7;
            tc=12;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==7){
            tr=10;
            tc=12;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==8){
            tr=14;
            tc=12;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==9){
            tr=15;
            tc=12;
            jmh::setUnitorder(1);
            dir=rt;}
        if(unitid==10){
            tr=7;
            tc=10;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==11){
            tr=7;
            tc=9;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==12){
            tr=7;
            tc=5;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==13){
            tr=7;
            tc=6;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==14){
            tr=7;
            tc=7;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==15){
            tr=7;
            tc=8;
            jmh::setUnitorder(1);
            dir=up;}
        }
        if(sideofmap==2){
        if(unitid==31){
            tr=23;
            tc=16;
            dir=lt;}
        if(unitid==32){
            tr=21;
            tc=16;
            dir=lt;}
        if(unitid==33){
            tr=20;
            tc=16;
            dir=lt;}
        if(unitid==34){
            tr=18;
            tc=16;
            dir=lt;}
        if(unitid==35){
            tr=16;
            tc=16;
            dir=lt;}
        if(unitid==36){
            tr=13;
            tc=16;
            dir=lt;}
        if(unitid==37){
            tr=11;
            tc=16;
            dir=lt;}
        if(unitid==38){
            tr=9;
            tc=16;
            dir=lt;}
        if(rank==crown){
            tr=23;
            tc=22;
            dir=dn;}
        if(unitid==51){
            tr=7;
            tc=16;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==52){
            tr=7;
            tc=17;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==53){
            tr=7;
            tc=18;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==54){
            tr=7;
            tc=19;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==55){
            tr=7;
            tc=20;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==56){
            tr=7;
            tc=21;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==1){
            tr=22;
            tc=16;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==2){
            tr=19;
            tc=16;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==3){
            tr=15;
            jmh::setUnitorder(1);
            tc=16;
            dir=lt;}
        if(unitid==4){
            tr=14;
            tc=16;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==5){
            tr=10;
            tc=16;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==6){
            tr=22;
            tc=17;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==7){
            tr=19;
            tc=17;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==8){
            tr=15;
            tc=17;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==9){
            tr=14;
            tc=17;
            jmh::setUnitorder(1);
            dir=lt;}
        if(unitid==10){
            tr=22;
            tc=19;
            jmh::setUnitorder(1);
            dir=dn;}
        if(unitid==11){
            tr=22;
            tc=20;
            jmh::setUnitorder(1);
            dir=dn;}
        if(unitid==12){
            tr=22;
            tc=24;
            jmh::setUnitorder(1);
            dir=dn;}
        if(unitid==13){
            tr=22;
            tc=23;
            jmh::setUnitorder(1);
            dir=dn;}
        if(unitid==14){
            tr=22;
            tc=22;
            jmh::setUnitorder(1);
            dir=dn;}
        if(unitid==15){
            tr=22;
            tc=21;
            jmh::setUnitorder(1);
            dir=dn;}
        }
	r=tr;
	c=tc;
	}
    if(mapname=="forts.in"){
        if(sideofmap==1){
        if(unitid==31){
            tr=10;
            tc=3;
            jmh::setUnitorder(3);
            dir=up;}
        if(unitid==32){
            tr=10;
            tc=5;
            jmh::setUnitorder(3);
            dir=up;}
        if(unitid==33){
            tr=19;
            tc=3;
            jmh::setUnitorder(3);
            dir=dn;}
        if(unitid==34){
            tr=19;
            tc=5;
            jmh::setUnitorder(3);
            dir=dn;}
        if(unitid==35){
            tr=13;
            tc=7;
            jmh::setUnitorder(3);
            dir=rt;}
        if(unitid==36){
            tr=16;
            tc=7;
            jmh::setUnitorder(3);
            dir=rt;}
        if(unitid==37){
            tr=14;
            tc=6;
            jmh::setUnitorder(4);
            dir=rt;}
        if(unitid==38){
            tr=15;
            tc=6;
            jmh::setUnitorder(4);
            dir=rt;}
        if(rank==crown){
            tr=15;
            tc=5;
            jmh::setUnitorder(0);
            dir=rt;}
        if(unitid==51){
            tr=10;
            tc=4;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==52){
            tr=11;
            tc=4;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==53){
            tr=12;
            tc=4;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==54){
            tr=19;
            tc=4;
            jmh::setUnitorder(10);
            dir=dn;}
        if(unitid==55){
            tr=18;
            tc=4;
            jmh::setUnitorder(10);
            dir=dn;}
        if(unitid==56){
            tr=17;
            tc=4;
            jmh::setUnitorder(10);
            dir=dn;}
        if(unitid==1){
            tr=13;
            tc=4;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==2){
            tr=14;
            tc=4;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==3){
            tr=16;
            jmh::setUnitorder(10);
            tc=4;
            dir=dn;}
        if(unitid==4){
            tr=15;
            tc=4;
            jmh::setUnitorder(10);
            dir=dn;}
        if(unitid==5){
            tr=14;
            tc=7;
            jmh::setUnitorder(4);
            dir=rt;}
        if(unitid==6){
            tr=15;
            tc=7;
            jmh::setUnitorder(4);
            dir=rt;}
        if(unitid==7){
            tr=11;
            tc=3;
            jmh::setUnitorder(5);
            dir=rt;}
        if(unitid==8){
            tr=12;
            tc=3;
            jmh::setUnitorder(5);
            dir=rt;}
        if(unitid==9){
            tr=13;
            tc=3;
            jmh::setUnitorder(5);
            dir=rt;}
        if(unitid==10){
            tr=18;
            tc=3;
            jmh::setUnitorder(6);
            dir=rt;}
        if(unitid==11){
            tr=17;
            tc=3;
            jmh::setUnitorder(6);
            dir=rt;}
        if(unitid==12){
            tr=11;
            tc=5;
            jmh::setUnitorder(7);
            dir=lt;}
        if(unitid==13){
            tr=12;
            tc=5;
            jmh::setUnitorder(7);
            dir=lt;}
        if(unitid==14){
            tr=18;
            tc=5;
            jmh::setUnitorder(8);
            dir=lt;}
        if(unitid==15){
            tr=17;
            tc=5;
            jmh::setUnitorder(8);
            dir=lt;}
        }
        if(sideofmap==2){
            if(unitid==31){
            tr=10;
            tc=26;
            jmh::setUnitorder(3);
            dir=up;}
        if(unitid==32){
            tr=10;
            tc=24;
            jmh::setUnitorder(3);
            dir=up;}
        if(unitid==33){
            tr=19;
            tc=26;
            jmh::setUnitorder(3);
            dir=dn;}
        if(unitid==34){
            tr=19;
            tc=24;
            jmh::setUnitorder(3);
            dir=dn;}
        if(unitid==35){
            tr=13;
            tc=22;
            jmh::setUnitorder(3);
            dir=lt;}
        if(unitid==36){
            tr=16;
            tc=22;
            jmh::setUnitorder(3);
            dir=lt;}
        if(unitid==37){
            tr=14;
            tc=23;
            jmh::setUnitorder(4);
            dir=lt;}
        if(unitid==38){
            tr=15;
            tc=23;
            jmh::setUnitorder(4);
            dir=lt;}
        if(rank==crown){
            tr=15;
            tc=24;
            jmh::setUnitorder(0);
            dir=lt;}
        if(unitid==51){
            tr=10;
            tc=25;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==52){
            tr=11;
            tc=25;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==53){
            tr=12;
            tc=25;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==54){
            tr=19;
            tc=25;
            jmh::setUnitorder(10);
            dir=dn;}
        if(unitid==55){
            tr=18;
            tc=25;
            jmh::setUnitorder(10);
            dir=dn;}
        if(unitid==56){
            tr=17;
            tc=25;
            jmh::setUnitorder(10);
            dir=dn;}
        if(unitid==1){
            tr=13;
            tc=25;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==2){
            tr=14;
            tc=25;
            jmh::setUnitorder(1);
            dir=up;}
        if(unitid==3){
            tr=16;
            jmh::setUnitorder(10);
            tc=25;
            dir=dn;}
        if(unitid==4){
            tr=15;
            tc=25;
            jmh::setUnitorder(10);
            dir=dn;}
        if(unitid==5){
            tr=14;
            tc=22;
            jmh::setUnitorder(4);
            dir=lt;}
        if(unitid==6){
            tr=15;
            tc=22;
            jmh::setUnitorder(4);
            dir=lt;}
        if(unitid==7){
            tr=11;
            tc=26;
            jmh::setUnitorder(5);
            dir=lt;}
        if(unitid==8){
            tr=12;
            tc=26;
            jmh::setUnitorder(5);
            dir=lt;}
        if(unitid==9){
            tr=13;
            tc=26;
            jmh::setUnitorder(5);
            dir=lt;}
        if(unitid==10){
            tr=18;
            tc=26;
            jmh::setUnitorder(6);
            dir=lt;}
        if(unitid==11){
            tr=17;
            tc=26;
            jmh::setUnitorder(6);
            dir=lt;}
        if(unitid==12){
            tr=11;
            tc=24;
            jmh::setUnitorder(7);
            dir=rt;}
        if(unitid==13){
            tr=12;
            tc=24;
            jmh::setUnitorder(7);
            dir=rt;}
        if(unitid==14){
            tr=18;
            tc=24;
            jmh::setUnitorder(8);
            dir=rt;}
        if(unitid==15){
            tr=17;
            tc=24;
            jmh::setUnitorder(8);
            dir=rt;}
	}
	done=false;
	if(sitrep.thing[tr][tc].what==space)done=true;
    while(!done){
		tr=minR+rand()%(maxR+1-minR);
		tc=minC+rand()%(maxC+1-minC);
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	r=tr;
	c=tc;
}

 /*   if(mapname=="4player.in"){
        if(sideofmap==1){
            if(rank==crown){
                tr=0;
                tc=11;
                dir=dn;
            }
            if(unitid==1){
                tr=1;
                tc=5;   //left rearguard
                jmh::setUnitorder(1);
                dir=lt;
            }
            if(unitid==2){
                tr=0;
                tc=10;
                jmh::setUnitorder(1);
                dir=lt;
            }
            if(unitid==3){
                tr=2;
                tc=6;  //left guard
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==4){
                tr=1;
                tc=10;
                jmh::setUnitorder(1);
                dir=lt;
            }
            if(unitid==5){
                tr=2;
                tc=13;  //left van
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==6){
                tr=2;
                tc=14;  //midleft van
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==7){
                tr=2;
                tc=15;  //midright van
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==8){
                tr=2;
                tc=16;  //right van
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==9){
                tr=1;
                tc=14;  //left rearvan
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==10){
                tr=1;
                tc=15;  //right rearvan
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==11){
                tr=1;
                tc=24;  //right rearguard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==12){
                tr=1;
                tc=11;
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==13){
                tr=2;
                tc=23;  //right guard
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==14){
                tr=0;
                tc=12;
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==15){
                tr=1;
                tc=12;
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==31){
                tr=1;
                tc=6;   //left rearguard
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==32){
                tr=2;
                tc=5;   //left midguard
                jmh::setUnitorder(1);
                dir=lt;
            }
            if(unitid==33){
                tr=2;
                tc=7;   //left frontguard
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==34){
                tr=1;
                tc=23;  //right rearguard
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==35){
                tr=2;
                tc=24;  //right midguard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==36){
                tr=2;
                tc=22;  //right frontguard
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==37){
                tr=1;
                tc=13;  //left rearvan
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==38){
                tr=1;
                tc=16;  //right rearvan
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==51){
                tr=2;
                tc=4;   //left flank front
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==52){
                tr=1;
                tc=4;   //left flank middle
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==53){
                tr=0;
                tc=4;   //left flank rear
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==54){
                tr=2;
                tc=25;  //right flank front
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==55){
                tr=1;
                tc=25;  //right flank middle
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==56){
                tr=0;
                tc=25;  //right flank rear
                jmh::setUnitorder(1);
                dir=dn;
            }


        }//end side
        if(sideofmap==2){
            if(rank==crown){
                tr=29;
                tc=11;
                dir=up;
            }
            if(unitid==1){
                tr=28;
                tc=5;   //left rearguard
                jmh::setUnitorder(1);
                dir=lt;
            }
            if(unitid==2){
                tr=29;
                tc=10;
                jmh::setUnitorder(1);
                dir=lt;
            }
            if(unitid==3){
                tr=27;
                tc=6;  //left guard
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==4){
                tr=28;
                tc=10;
                jmh::setUnitorder(1);
                dir=lt;
            }
            if(unitid==5){
                tr=27;
                tc=13;  //left van
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==6){
                tr=27;
                tc=14;  //midleft van
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==7){
                tr=27;
                tc=15;  //midright van
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==8){
                tr=27;
                tc=16;  //right van
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==9){
                tr=28;
                tc=14;  //left rearvan
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==10){
                tr=28;
                tc=15;  //right rearvan
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==11){
                tr=28;
                tc=24;  //right rearguard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==12){
                tr=28;
                tc=11;
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==13){
                tr=27;
                tc=23;  //right guard
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==14){
                tr=29;
                tc=12;
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==15){
                tr=28;
                tc=12;
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==31){
                tr=28;
                tc=6;   //left rearguard
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==32){
                tr=27;
                tc=5;   //left midguard
                jmh::setUnitorder(1);
                dir=lt;
            }
            if(unitid==33){
                tr=27;
                tc=7;   //left frontguard
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==34){
                tr=28;
                tc=23;  //right rearguard
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==35){
                tr=27;
                tc=24;  //right midguard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==36){
                tr=27;
                tc=22;  //right frontguard
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==37){
                tr=28;
                tc=13;  //left rearvan
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==38){
                tr=28;
                tc=16;  //right rearvan
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==51){
                tr=27;
                tc=4;   //left flank front
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==52){
                tr=28;
                tc=4;   //left flank middle
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==53){
                tr=29;
                tc=4;   //left flank rear
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==54){
                tr=27;
                tc=25;  //right flank front
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==55){
                tr=28;
                tc=25;  //right flank middle
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==56){
                tr=29;
                tc=25;  //right flank rear
                jmh::setUnitorder(1);
                dir=up;
            }
        }//end side
   /*     if(sideofmap==3){
            if(rank==crown){
                tr=11;
                tc=0;
                dir=rt;
            }
            if(unitid==1){
                tr=5;
                tc=1;   //left rearguard
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==2){
                tr=10;
                tc=0;
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==3){
                tr=6;
                tc=2;  //left guard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==4){
                tr=10;
                tc=1;
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==5){
                tr=13;
                tc=2;  //left van
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==6){
                tr=14;
                tc=2;  //midleft van
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==7){
                tr=15;
                tc=2;  //midright van
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==8){
                tr=16;
                tc=2;  //right van
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==9){
                tr=14;
                tc=1;  //left rearvan
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==10){
                tr=15;
                tc=1;  //right rearvan
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==11){
                tr=24;
                tc=1;  //right rearguard
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==12){
                tr=11;
                tc=1;
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==13){
                tr=23;
                tc=2;  //right guard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==14){
                tr=12;
                tc=0;
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==15){
                tr=12;
                tc=1;
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==31){
                tr=6;
                tc=1;   //left rearguard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==32){
                tr=5;
                tc=2;   //left midguard
                jmh::setUnitorder(1);
                dir=up;
            }
            if(unitid==33){
                tr=7;
                tc=2;   //left frontguard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==34){
                tr=23;
                tc=1;  //right rearguard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==35){
                tr=24;
                tc=2;  //right midguard
                jmh::setUnitorder(1);
                dir=dn;
            }
            if(unitid==36){
                tr=22;
                tc=2;  //right frontguard
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==37){
                tr=13;
                tc=1;  //left rearvan
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==38){
                tr=16;
                tc=1;  //right rearvan
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==51){
                tr=4;
                tc=2;   //left flank front
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==52){
                tr=4;
                tc=1;   //left flank middle
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==53){
                tr=4;
                tc=0;   //left flank rear
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==54){
                tr=25;
                tc=2;  //right flank front
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==55){
                tr=25;
                tc=1;  //right flank middle
                jmh::setUnitorder(1);
                dir=rt;
            }
            if(unitid==56){
                tr=25;
                tc=0;  //right flank rear
                jmh::setUnitorder(1);
                dir=rt;
            }
        }//end side
    r=tr;
    c=tc;
    }//END 4PLAYER.IN
*/
    r=tr;
    c=tc;


}//END PLACEMENT
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//ACTIONS
Action jmh::Recommendation(SitRep sitrep){
static int sidedeclared=0;
Action a;
static int population=60;
static int peacefulturns=0;
    int tr=r;
    int tc=c;
    int postc;
    int postr;
    string mapname=INFILE;
    if(rank==crown){
        if(jmh::totalcount(sitrep)==population){
            peacefulturns++;
        }
        if(jmh::totalcount(sitrep)!=population){
            peacefulturns=0;
            population=jmh::totalcount(sitrep);
        }
    }
    if(rank==infantry||rank==knight){
        if(peacefulturns>200){
            return jmh::crownhunting(r,c,dir,sitrep);
        }
    }
    if(rank==archer){
        if(peacefulturns>200){
            return jmh::archerhunting(r,c,dir,sitrep);
        }
    }
if(mapname=="map2.in"){
if(sideofmap==1){
//    if(rank==archer||rank==infantry){
//        if(jmh::armyCount(sitrep)<12){
//            jmh::setUnitorder(2);
//        }
//    }
//Crown Actions
	if(rank==crown){
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
				a.action=attack;
				return a;
			}
		}
	}
            a.action=nothing;
        if(r==20&&c==5&&dir==rt){
            a.action=fwd;
            a.maxDist=2;}
        if(r==20&&c==7&&dir==rt){
            a.action=turn;
            a.dir=dn;}
        if(r==20&&c==7&&dir==dn){
            a.action=fwd;
            a.maxDist=7;}
        if(r==25&&c==7&&dir==dn){
            a.action=fwd;
            a.maxDist=2;}
        if(r==27&&c==7&&dir==dn){
            a.action=turn;
            a.dir=lt;}
        if(r==27&&c==7&&dir==lt){
            a.action=fwd;
            a.maxDist=1;}
        if(r==27&&c==6&&dir==lt){
            a.action=turn;
            a.dir=dn;}
        if(r==27&&c==6&&dir==dn){
            a.action=fwd;
            a.maxDist=1;}
        if(r==28&&c==6&&dir==dn){
            a.action=turn;
            a.dir=lt;}
        if(r==28&&c==6&&dir==lt){
            a.action=fwd;
            a.maxDist=5;}
        if(r==28&&c==1&&dir==lt){
            a.action=turn;
            a.dir=dn;}
        if(r==28&&c==1&&dir==dn){
            a.action=fwd;
            a.maxDist=1;}
        if(r==29&&c==1&&dir==dn){
            a.action=turn;
            a.dir=rt;}
        return a;}
//Northern King Hunter Knight Actions
    if(unitid>50&&unitid<54){
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
				a.action=attack;
				return a;
			}
		}
	}
       if(unitorder==1){
        int rr=3;
        int rc=14;
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
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}
        if(r>rr){
            if(dir!=up){
                a.action=turn;
                a.dir=up;
                return a;}
            a.action=fwd;
            a.maxDist=r-rr;
            if(a.maxDist>5)a.maxDist=5;
            return a;
            }
        if(c<rc){
            if(dir!=rt){
                a.action=turn;
                a.dir=rt;
                return a;}
            a.action=fwd;
            a.maxDist=rc-c;
            if(a.maxDist>5)a.maxDist=5;
            return a;
        }
        jmh::setUnitorder(2);
    }
    if(unitorder==2){
        return jmh::hunting(r,c,dir,sitrep);
    }
    }
//Southern King Hunter Knight Actions
    if(unitid>53&&unitid<60){
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
				a.action=attack;
				return a;
			}
		}
	}
       if(unitorder==1){
        int rr=26;
        int rc=18;
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
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}
        if(sitrep.thing[r][c+1].what==space){
        if(c<rc){
            if(dir!=rt){
                a.action=turn;
                a.dir=rt;
                return a;}
            a.action=fwd;
            a.maxDist=rc-c;
            if(a.maxDist>5)a.maxDist=5;
            return a;
        }}
        if(r<rr){
            if(dir!=dn){
                a.action=turn;
                a.dir=dn;
                return a;}
            a.action=fwd;
            a.maxDist=rr-r;
            if(a.maxDist>5)a.maxDist=5;
            return a;
            }
        jmh::setUnitorder(2);
    }
    //Order 2
    if(unitorder==2){
        return jmh::hunting(r,c,dir,sitrep);
    }
    }
//Kinghunter Infantry Actions
if(unitid>12&&unitid<31){
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
				a.action=attack;
				return a;
			}
		}
	}
        //Order 1
        if(unitorder==1){
        int rr=3;
        int rc=19;
        if(r>rr){
            if(dir!=up){
                a.action=turn;
                a.dir=up;
                return a;}
            a.action=fwd;
            a.maxDist=r-rr;
            if(a.maxDist>1)a.maxDist=1;
            return a;
            }
        if(c<rc){
            if(dir!=rt){
                a.action=turn;
                a.dir=rt;
                return a;}
            a.action=fwd;
            a.maxDist=rc-c;
            if(a.maxDist>1)a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(2);
    }
    //Order 2
    if(unitorder==2){
        return jmh::hunting(r,c,dir,sitrep);
    }
}
//Central Infantry Actions
        if(unitid>0&&unitid<7){
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
				a.action=attack;
				return a;
			}
		}
	}
    //Set Order 2
            if(c>17){
                    jmh::setUnitorder(2);}
    //Order 1
            if(unitorder==1){
                int tr=r;
                int tc=c+1;
                if(sitrep.thing[tr][tc].what==unit){
                    if(sitrep.thing[tr][tc].tla!=tla){
                        a.action=attack;
                        return a;}
                    a.action=nothing;
                    return a;
                }
                if(sitrep.thing[tr][tc].what==space){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;}
                a.action=nothing;
                return a;
            }
    //Order 2
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
            }
        }
//King's Guard Infantry Actions
        if(unitid>6&&unitid<13){
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
				a.action=attack;
				return a;
			}
		}
	}
    //Setting Order 4
           if(r==27&&c==7)jmh::setUnitorder(4);
           if(sitrep.thing[27][7].what==unit&&sitrep.thing[27][7].tla==tla){
                if(r==26&&c==7)jmh::setUnitorder(4);
                if(sitrep.thing[26][7].what==unit&&sitrep.thing[26][7].tla==tla){
                    if(r==25&&c==7)jmh::setUnitorder(4);
                    if(sitrep.thing[25][7].what==unit&&sitrep.thing[25][7].tla==tla){
                        if(r==26&&c==17)jmh::setUnitorder(4);
                        if(sitrep.thing[26][17].what==unit&&sitrep.thing[27][7].tla==tla){
                            if(r==26&&c==16)jmh::setUnitorder(4);
                            if(sitrep.thing[26][16].what==unit&&sitrep.thing[27][7].tla==tla){
                                if(r==26&&c==15)jmh::setUnitorder(4);}}}}}
            if(jmh::enemyCount(sitrep)<6){
                jmh::setUnitorder(2);}
    //Order 2
            if(unitorder==2){
                return jmh::hunting(r,c,dir,sitrep);
            }
    //Order 3
            if(unitorder==3){
            int dr,dc;
            if(sitrep.thing[27][7].what!=unit||sitrep.thing[27][7].tla!=tla){
                dr=27;
                dc=7;
            }
            else if(sitrep.thing[26][7].what!=unit||sitrep.thing[26][7].tla!=tla){
                dr=26;
                dc=7;
            }
            else if(sitrep.thing[25][7].what!=unit||sitrep.thing[25][7].tla!=tla){
                dr=25;
                dc=7;
            }
            else if(sitrep.thing[26][17].what!=unit||sitrep.thing[26][17].tla!=tla){
                dr=26;
                dc=17;
            }
            else if(sitrep.thing[26][16].what!=unit||sitrep.thing[26][16].tla!=tla){
                dr=26;
                dc=16;
            }
            else if(sitrep.thing[26][15].what!=unit||sitrep.thing[26][15].tla!=tla){
                dr=26;
                dc=15;
            }
            if(c<dc){
                if(sitrep.thing[r][c+1].what==space){
                if(dir!=rt){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
                a.action=fwd;
                a.maxDist=1;
                return a;}
            }
            if(r<dr){
                if(dir!=dn){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
                if(sitrep.thing[r+1][c].what==space){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;}
                if(sitrep.thing[r+1][c].what==unit&&sitrep.thing[r+1][c].tla!=tla){
                    a.action=attack;
                    return a;}
            }
            }
    //Order 4
            if(unitorder==4){
            //Attack an enemy in front of me
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
                        a.action=attack;
                        return a;
                    }
                }
            }
            //Turn to enemy
            if(dir!=sitrep.nearestEnemy.dirFor){
                a.action=turn;
                a.dir=sitrep.nearestEnemy.dirFor;
                return a;
                }
            }
        }
//Kinghunter Archer Actions
    if(unitid>34&&unitid<38){
        if(jmh::enemyCount(sitrep)<6){
                jmh::setUnitorder(2);}
        //Order 1
        if(unitorder==1){
            if(r==1){
                jmh::setUnitorder(3);
                a.action=turn;
                a.dir=rt;
                return a;
            }
            int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        int rr=3;
        int rc=19;
        if(r>rr){
            if(dir!=up){
                a.action=turn;
                a.dir=up;
                return a;}
            a.action=fwd;
            a.maxDist=r-rr;
            if(a.maxDist>1)a.maxDist=1;
            return a;
            }
        if(c<rc){
            if(dir!=rt){
                a.action=turn;
                a.dir=rt;
                return a;}
            a.action=fwd;
            a.maxDist=rc-c;
            if(a.maxDist>1)a.maxDist=1;
            return a;
        }
        if(r-1>=0&&r-1<ROWS&&c>=0&&tc<COLS){
        if(sitrep.thing[r-1][c].what==space){
            if(dir!=up){
                a.action=turn;
                a.dir=up;
                return a;
            }
            a.action=fwd;
            a.maxDist=1;
            return a;
        }}
        if(r-1>=0&&r-1<ROWS&&c>=0&&tc<COLS){
        if(sitrep.thing[r-1][c].what==unit){
            if(sitrep.thing[r-1][c].tla==tla){
            if(dir!=rt){
                a.action=turn;
                a.dir=rt;
                return a;
            }
            jmh::setUnitorder(3);
        }}}
        if(r-1<0){
            jmh::setUnitorder(3);
        }
    }
        //Order 2
        if(unitorder==2){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                //MOVE TOWARD ENEMY CODE
                if(dir==sitrep.nearestEnemy.dirFor){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;
                } else {
                    a.action=turn;
                    a.dir=sitrep.nearestEnemy.dirFor;
                    return a;
                }
                a.action=nothing;
                return a;
            }
        //Order 3
        if(unitorder==3){
            int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
            if(dir==rt){
                a.action=turn;
                a.dir=dn;
                return a;
            }
            if(dir==dn){
                a.action=turn;
                a.dir=rt;
                return a;
            }
        }
    }
//Central Archer Actions
            if(unitid>30&&unitid<35){
            //if advanced beyond the bridge, set unitorder to 2
            if(c>17){
                    jmh::setUnitorder(2);}
            //if unitorder is 1 (advance), check for attack, advance if possible, or nothing
            if(unitorder==1){
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
              tr=r;
                tc=c+1;
                if(sitrep.thing[tr][tc].what==space){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;}
                a.action=nothing;
                return a;
            }
            //if unitorder is 2 (seek and destroy), check for attack, move to closest enemy
            if(unitorder==2){
                //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                //MOVE TOWARD ENEMY CODE
                if(dir==sitrep.nearestEnemy.dirFor){
                    a.action=fwd;
                    a.maxDist=1;
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
//Kinguard Archer Actions
    if(unitid>37&&unitid<50){
        if(jmh::enemyCount(sitrep)<6){
                jmh::setUnitorder(2);}
        //Order 1
        if(unitorder==1){
            if(r==26&&c==8){
            jmh::setUnitorder(3);}
            int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        int rr=26;
        int rc=8;
        if(c<rc){
            if(dir!=rt){
                a.action=turn;
                a.dir=rt;
                return a;}
            a.action=fwd;
            a.maxDist=rc-c;
            if(a.maxDist>1)a.maxDist=1;
            return a;
        }
        if(r<rr){
            if(dir!=dn){
                a.action=turn;
                a.dir=dn;
                return a;}
            a.action=fwd;
            a.maxDist=rr-r;
            if(a.maxDist>1)a.maxDist=1;
            return a;
            }

        if(c==6){
        if(sitrep.thing[r+1][c].what==unit){
            if(sitrep.thing[r+1][c].tla==tla){
                if(sitrep.thing[r+1][c].rank==archer){
                    jmh::setUnitorder(3);
            if(dir!=rt){
                a.action=turn;
                a.dir=rt;
                return a;
            }}}}}
            }
        //Order 2
        if(unitorder==2){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                //MOVE TOWARD ENEMY CODE
                if(dir==sitrep.nearestEnemy.dirFor){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;
                } else {
                    a.action=turn;
                    a.dir=sitrep.nearestEnemy.dirFor;
                    return a;
                }
                a.action=nothing;
                return a;
            }
        //Order 3
        if(unitorder==3){
            int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
            if(dir==rt){
                a.action=turn;
                a.dir=dn;
                return a;
            }
            if(dir==dn){
                a.action=turn;
                a.dir=up;
                return a;
            }
            if(dir==up){
                a.action=turn;
                a.dir=rt;
                return a;
            }
        }
    }

	a.action=nothing;
	return a;
}
if(sideofmap==2){
   //Crown Actions
	if(rank==crown){
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
				a.action=attack;
				return a;
			}
		}
	}
            a.action=nothing;
        if(r==10&&c==24&&dir==lt){
            a.action=fwd;
            a.maxDist=2;}
        if(r==10&&c==22&&dir==lt){
            a.action=turn;
            a.dir=up;}
        if(r==10&&c==22&&dir==up){
            a.action=fwd;
            a.maxDist=5;}
        if(r==5&&c==22&&dir==up){
            a.action=fwd;
            a.maxDist=3;}
        if(r==2&&c==22&&dir==up){
            a.action=turn;
            a.dir=rt;}
        if(r==2&&c==22&&dir==rt){
            a.action=fwd;
            a.maxDist=1;}
        if(r==2&&c==23&&dir==rt){
            a.action=turn;
            a.dir=up;}
        if(r==2&&c==23&&dir==up){
            a.action=fwd;
            a.maxDist=1;}
        if(r==1&&c==23&&dir==up){
            a.action=turn;
            a.dir=rt;}
        if(r==1&&c==23&&dir==rt){
            a.action=fwd;
            a.maxDist=5;}
        if(r==1&&c==28&&dir==rt){
            a.action=turn;
            a.dir=up;}
        if(r==1&&c==28&&dir==up){
            a.action=fwd;
            a.maxDist=1;}
        if(r==0&&c==28&&dir==up){
            a.action=turn;
            a.dir=lt;}
        return a;}
//Northern King Hunter Knight Actions
    if(unitid>50&&unitid<54){
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
				a.action=attack;
				return a;
			}
		}
	}
       if(unitorder==1){
        int rr=26;
        int rc=15;
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
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}
        if(r<rr){
            if(dir!=dn){
                a.action=turn;
                a.dir=dn;
                return a;}
            a.action=fwd;
            a.maxDist=rr-r;
            if(a.maxDist>5)a.maxDist=5;
            return a;
            }
        if(c>rc){
            if(dir!=lt){
                a.action=turn;
                a.dir=lt;
                return a;}
            a.action=fwd;
            a.maxDist=c-rc;
            if(a.maxDist>5)a.maxDist=5;
            return a;
        }
        jmh::setUnitorder(2);
    }
    if(unitorder==2){
        return jmh::hunting(r,c,dir,sitrep);
    }
    }
//Southern King Hunter Knight Actions
    if(unitid>53&&unitid<60){
       if(unitorder==1){
        int rr=3;
        int rc=11;
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
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}
        if(sitrep.thing[r][c-1].what==space){
        if(c>rc){
            if(dir!=lt){
                a.action=turn;
                a.dir=lt;
                return a;}
            a.action=fwd;
            a.maxDist=c-rc;
            if(a.maxDist>5)a.maxDist=5;
            return a;
        }}
        if(r>rr){
            if(dir!=up){
                a.action=turn;
                a.dir=up;
                return a;}
            a.action=fwd;
            a.maxDist=r-rr;
            if(a.maxDist>5)a.maxDist=5;
            return a;
            }
        jmh::setUnitorder(2);
    }
    //Order 2
    if(unitorder==2){
        return jmh::hunting(r,c,dir,sitrep);
    }
    }
//Kinghunter Infantry Actions
if(unitid>12&&unitid<31){
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
				a.action=attack;
				return a;
			}
		}
	}
        //Order 1
        if(unitorder==1){
        int rr=26;
        int rc=10;
        if(r<rr){
            if(dir!=dn){
                a.action=turn;
                a.dir=dn;
                return a;}
            a.action=fwd;
            a.maxDist=rr-r;
            if(a.maxDist>1)a.maxDist=1;
            return a;
            }
        if(c>rc){
            if(dir!=lt){
                a.action=turn;
                a.dir=lt;
                return a;}
            a.action=fwd;
            a.maxDist=c-rc;
            if(a.maxDist>1)a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(2);
    }
    //Order 2
    if(unitorder==2){
        return jmh::hunting(r,c,dir,sitrep);
    }
}
//Central Infantry Actions
        if(unitid>0&&unitid<7){
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
				a.action=attack;
				return a;
			}
		}
	}
    //Set Order 2
            if(c<17){
                    jmh::setUnitorder(2);}
    //Order 1
            if(unitorder==1){
                int tr=r;
                int tc=c-1;
                if(sitrep.thing[tr][tc].what==unit){
                    if(sitrep.thing[tr][tc].tla!=tla){
                        a.action=attack;
                        return a;}
                    a.action=nothing;
                    return a;
                }
                if(sitrep.thing[tr][tc].what==space){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;}
                a.action=nothing;
                return a;
            }
    //Order 2
            if(unitorder==2){
                return jmh::hunting(r,c,dir,sitrep);
            }
        }
//King's Guard Infantry Actions
        if(unitid>6&&unitid<13){
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
				a.action=attack;
				return a;
			}
		}
	}
    //Setting Order 4
           if(r==2&&c==22)jmh::setUnitorder(4);
           if(sitrep.thing[2][22].what==unit&&sitrep.thing[2][22].tla==tla){
                if(r==3&&c==22)jmh::setUnitorder(4);
                if(sitrep.thing[3][22].what==unit&&sitrep.thing[3][22].tla==tla){
                    if(r==4&&c==22)jmh::setUnitorder(4);
                    if(sitrep.thing[4][22].what==unit&&sitrep.thing[4][22].tla==tla){
                        if(r==3&&c==12)jmh::setUnitorder(4);
                        if(sitrep.thing[3][12].what==unit&&sitrep.thing[2][22].tla==tla){
                            if(r==3&&c==13)jmh::setUnitorder(4);
                            if(sitrep.thing[3][13].what==unit&&sitrep.thing[2][22].tla==tla){
                                if(r==3&&c==14)jmh::setUnitorder(4);}}}}}
            if(jmh::enemyCount(sitrep)<6){
                jmh::setUnitorder(2);}
    //Order 2
            if(unitorder==2){
                return jmh::hunting(r,c,dir,sitrep);
            }
    //Order 3
            if(unitorder==3){
            int dr,dc;
            if(sitrep.thing[2][22].what!=unit||sitrep.thing[2][22].tla!=tla){
                dr=2;
                dc=22;
            }
            else if(sitrep.thing[3][22].what!=unit||sitrep.thing[3][22].tla!=tla){
                dr=3;
                dc=22;
            }
            else if(sitrep.thing[4][22].what!=unit||sitrep.thing[4][22].tla!=tla){
                dr=4;
                dc=22;
            }
            else if(sitrep.thing[3][12].what!=unit||sitrep.thing[3][12].tla!=tla){
                dr=3;
                dc=12;
            }
            else if(sitrep.thing[3][13].what!=unit||sitrep.thing[3][13].tla!=tla){
                dr=3;
                dc=13;
            }
            else if(sitrep.thing[3][14].what!=unit||sitrep.thing[3][14].tla!=tla){
                dr=3;
                dc=14;
            }
            if(c>dc){
                if(sitrep.thing[r][c-1].what==space){
                if(dir!=lt){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
                a.action=fwd;
                a.maxDist=1;
                return a;}
            }
            if(r>dr){
                if(dir!=up){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
                if(sitrep.thing[r-1][c].what==space){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;}
                if(sitrep.thing[r-1][c].what==unit&&sitrep.thing[r-1][c].tla!=tla){
                    a.action=attack;
                    return a;}
            }
            }
    //Order 4
            if(unitorder==4){
            //Attack an enemy in front of me
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
                        a.action=attack;
                        return a;
                    }
                }
            }
            //Turn to enemy
            if(dir!=sitrep.nearestEnemy.dirFor){
                a.action=turn;
                a.dir=sitrep.nearestEnemy.dirFor;
                return a;
                }
            }
        }
//Kinghunter Archer Actions
    if(unitid>34&&unitid<38){
        if(jmh::enemyCount(sitrep)<8){
                jmh::setUnitorder(2);}
        //Order 1
        if(unitorder==1){
            if(r==28){
                jmh::setUnitorder(3);
                a.action=turn;
                a.dir=lt;
                return a;
            }
            int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        int rr=26;
        int rc=10;
        if(r<rr){
            if(dir!=dn){
                a.action=turn;
                a.dir=dn;
                return a;}
            a.action=fwd;
            a.maxDist=rr-r;
            if(a.maxDist>1)a.maxDist=1;
            return a;
            }
        if(c>rc){
            if(dir!=lt){
                a.action=turn;
                a.dir=lt;
                return a;}
            a.action=fwd;
            a.maxDist=c-rc;
            if(a.maxDist>1)a.maxDist=1;
            return a;
        }
        if(r+1>=0&&r+1<ROWS&&c>=0&&tc<COLS){
        if(sitrep.thing[r+1][c].what==space){
            if(dir!=dn){
                a.action=turn;
                a.dir=dn;
                return a;
            }
            a.action=fwd;
            a.maxDist=1;
            return a;
        }}
        if(r+1>=0&&r+1
           <ROWS&&c>=0&&tc<COLS){
        if(sitrep.thing[r+1][c].what==unit){
            if(sitrep.thing[r+1][c].tla==tla){
            if(dir!=lt){
                a.action=turn;
                a.dir=lt;
                return a;
            }
            jmh::setUnitorder(3);
        }}}
        if(r+1>29){
            jmh::setUnitorder(3);
        }
    }
        //Order 2
        if(unitorder==2){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                //MOVE TOWARD ENEMY CODE
                if(dir==sitrep.nearestEnemy.dirFor){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;
                } else {
                    a.action=turn;
                    a.dir=sitrep.nearestEnemy.dirFor;
                    return a;
                }
                a.action=nothing;
                return a;
            }
        //Order 3
        if(unitorder==3){
            int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
            if(dir==lt){
                a.action=turn;
                a.dir=up;
                return a;
            }
            if(dir==up){
                a.action=turn;
                a.dir=lt;
                return a;
            }
        }
    }
//Central Archer Actions
            if(unitid>30&&unitid<35){
            //if advanced beyond the bridge, set unitorder to 2
            if(c<17){
                    jmh::setUnitorder(2);}
            //if unitorder is 1 (advance), check for attack, advance if possible, or nothing
            if(unitorder==1){
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
              tr=r;
                tc=c-1;
                if(sitrep.thing[tr][tc].what==space){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;}
                a.action=nothing;
                return a;
            }
            //if unitorder is 2 (seek and destroy), check for attack, move to closest enemy
            if(unitorder==2){
                //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                //MOVE TOWARD ENEMY CODE
                if(dir==sitrep.nearestEnemy.dirFor){
                    a.action=fwd;
                    a.maxDist=1;
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
//Kinguard Archer Actions
    if(unitid>37&&unitid<50){
        if(jmh::enemyCount(sitrep)<8){
                jmh::setUnitorder(2);}
        //Order 1
        if(unitorder==1){
            if(r==3&&c==21){
            jmh::setUnitorder(3);}
            int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        int rr=3;
        int rc=21;
        if(c>rc){
            if(dir!=lt){
                a.action=turn;
                a.dir=lt;
                return a;}
            a.action=fwd;
            a.maxDist=c-rc;
            if(a.maxDist>1)a.maxDist=1;
            return a;
        }
        if(r>rr){
            if(dir!=up){
                a.action=turn;
                a.dir=up;
                return a;}
            a.action=fwd;
            a.maxDist=r-rr;
            if(a.maxDist>1)a.maxDist=1;
            return a;
            }

        if(c==23){
        if(sitrep.thing[r-1][c].what==unit){
            if(sitrep.thing[r-1][c].tla==tla){
                if(sitrep.thing[r-1][c].rank==archer){
                    jmh::setUnitorder(3);
            if(dir!=lt){
                a.action=turn;
                a.dir=lt;
                return a;
            }}}}}
            }
        //Order 2
        if(unitorder==2){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                //MOVE TOWARD ENEMY CODE
                if(dir==sitrep.nearestEnemy.dirFor){
                    a.action=fwd;
                    a.maxDist=1;
                    return a;
                } else {
                    a.action=turn;
                    a.dir=sitrep.nearestEnemy.dirFor;
                    return a;
                }
                a.action=nothing;
                return a;
            }
        //Order 3
        if(unitorder==3){
            int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
            if(dir==lt){
                a.action=turn;
                a.dir=up;
                return a;
            }
            if(dir==up){
                a.action=turn;
                a.dir=dn;
                return a;
            }
            if(dir==dn){
                a.action=turn;
                a.dir=lt;
                return a;
            }
        }
    }

	a.action=nothing;
	return a;
}
a.action=nothing;
return a;
}
if(mapname=="navy.in"){
    if(sideofmap==1){
    if(rank==crown){
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
				a.action=attack;
				return a;
			}
		}
	}
        a.action=fwd;
        a.maxDist=5;
        return a;}
    if(unitid>9&&unitid<16){
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
				a.action=attack;
				return a;
			}
		}
	}
        //line broken
            int li,lj;
            for(li=0;li<4;++li){
                for(lj=6;lj<12;++lj){
                    if(sitrep.thing[li][lj].what==unit&&sitrep.thing[li][lj].tla!=tla){
                        jmh::setUnitorder(2);
                    }
                }
            }
        if(unitorder==1){
        if(r>3){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(dir!=dn){
            a.action=turn;
            a.dir=dn;
            return a;
        }
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
                    a.action=attack;
                    return a;
                }
            }
        }
        a.action=nothing;
        return a;
    }//end order 1
    if(unitorder==2){
        jmh::hunting(r,c,dir,sitrep);
    }
    }
    if(rank==archer){
        if(unitorder==1){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(unitid==31||unitid==33||unitid==35||unitid==37||unitid==38){
                if(dir==rt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }}
                if(unitid==32||unitid==34||unitid==36){
                if(dir==rt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }}
                if(dir==dn){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
        }
    }
    if(rank==knight){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(c>16){jmh::setUnitorder(2);}
        if(unitorder==1){
            if(unitid==55){
                if(c==15){
                    if(sitrep.thing[r][c+1].what==unit&&sitrep.thing[r][c+1].tla!=tla){
                    a.action=attack;
                    return a;}
                    a.action=nothing;
                    return a;
                }
            }
            if(unitid==56){
                if(c==14){
                    if(sitrep.thing[r][c+1].what==unit&&sitrep.thing[r][c+1].tla!=tla){
                    a.action=attack;
                    return a;}
                    a.action=nothing;
                    return a;
                }
            }
            if(sitrep.thing[r][c+1].what==unit&&sitrep.thing[r][c+1].tla!=tla){
                a.action=attack;
                return a;}
            if(sitrep.thing[r][c+1].what==space){
                a.action=fwd;
                a.maxDist=5;
                return a;}
            a.action=nothing;
            return a;
        }
        if(unitorder==2){
            return jmh::crownhunting(r,c,dir,sitrep);
        }
    }
    if(unitid>0&&unitid<9){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(jmh::enemyCount(sitrep)<10){
                jmh::setUnitorder(2);}
        if(unitorder==1){
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
                    a.action=attack;
                    return a;
                }
            }
        }
        a.action=nothing;
        return a;}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
    }
    }
    if(sideofmap==2){
    if(rank==crown){
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
				a.action=attack;
				return a;
			}
		}
	}
        a.action=fwd;
        a.maxDist=5;
        return a;}
    if(unitid>9&&unitid<16){
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
				a.action=attack;
				return a;
			}
		}
	}
            //line broken
            int li,lj;
            for(li=0;li<4;++li){
                for(lj=6;lj<12;++lj){
                    if(sitrep.thing[li][lj].what==unit&&sitrep.thing[li][lj].tla!=tla){
                        jmh::setUnitorder(2);
                    }
                }
            }
        if(unitorder==1){
        if(r<26){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(dir!=up){
            a.action=turn;
            a.dir=up;
            return a;
        }
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
                    a.action=attack;
                    return a;
                }
            }
        }
        a.action=nothing;
        return a;
    }//end order 1
    if(unitorder==2){
        jmh::hunting(r,c,dir,sitrep);
    }
    }
    if(rank==archer){
        if(unitorder==1){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(unitid==32||unitid==34||unitid==36){
                if(dir==lt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }}
                if(unitid==31||unitid==33||unitid==35||unitid==37||unitid==38){
                if(dir==lt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }}
                if(dir==dn){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
        }
    }
    if(rank==knight){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(c<13){jmh::setUnitorder(2);}
        if(unitorder==1){
            if(unitid==55){
                if(c==14){
                    if(sitrep.thing[r][c-1].what==unit&&sitrep.thing[r][c-1].tla!=tla){
                    a.action=attack;
                    return a;}
                    a.action=nothing;
                    return a;
                }
            }
            if(unitid==56){
                if(c==15){
                    if(sitrep.thing[r][c-1].what==unit&&sitrep.thing[r][c-1].tla!=tla){
                    a.action=attack;
                    return a;}
                    a.action=nothing;
                    return a;
                }
            }
            if(sitrep.thing[r][c-1].what==unit&&sitrep.thing[r][c-1].tla!=tla){
                a.action=attack;
                return a;}
            if(sitrep.thing[r][c-1].what==space){
            a.action=fwd;
            a.maxDist=5;
            return a;}
            a.action=nothing;
            return a;
        }
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
    }
    if(unitid>0&&unitid<9){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(jmh::enemyCount(sitrep)<10){
                jmh::setUnitorder(2);}
        if(unitorder==1){
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
                    a.action=attack;
                    return a;
                }
            }
        }
        a.action=nothing;
        return a;}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
			}
		}
        }
a.action=nothing;
return a;
}//end navy
if(mapname=="forts.in"){
    if(sideofmap==1){
    if(rank==crown){
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
				a.action=attack;
				return a;
			}
		}
	}
        a.action=nothing;
        return a;
    }
    if(unitorder==1){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==8){
            jmh::setUnitorder(2);
            a.action=turn;
            a.dir=rt;
            return a;}
        a.action=fwd;
        a.maxDist=5;
        if(rank==infantry){
            a.maxDist=1;
        }
        return a;
    }
    if(unitorder==2){
        return jmh::hunting(r,c,dir,sitrep);
    }
    if(unitorder==3){
        //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                a.action=nothing;
                return a;
    }
    if(unitorder==4){
        if(rank==infantry){
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
				a.action=attack;
				return a;
			}
		}
	}
        }
            if(rank==archer&&c==8){
                jmh::setUnitorder(3);
                a.action=nothing;
                return a;
            }
            if(rank==infantry&&c==9){
                a.action=turn;
                if(unitid==5){
                    a.dir=up;
                }
                if(unitid==6){
                   a.dir=dn;
                }
                jmh::setUnitorder(9);
                return a;
            }
        a.action=fwd;
        a.maxDist=1;
        return a;
    }
    if(unitorder==5){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==8){
            jmh::setUnitorder(2);
            a.action=turn;
            a.dir=rt;
            return a;
        }
        if(c==4&&dir!=up){
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(c==4&&dir==up){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(sitrep.thing[8][4].tla==tla&&sitrep.thing[8][4].rank==infantry){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        a.action=nothing;
        return a;
    }
    if(unitorder==6){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==21){
            jmh::setUnitorder(2);
            a.action=turn;
            a.dir=rt;
            return a;
        }
        if(c==4&&dir!=dn){
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(c==4&&dir==dn){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(sitrep.thing[21][4].tla==tla&&sitrep.thing[21][4].rank==infantry){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        a.action=nothing;
        return a;
    }
    if(unitorder==7){
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
				a.action=attack;
				return a;
			}
		}
	}
         if(r==10&&unitid==12){
            jmh::setUnitorder(9);
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(r==9&&unitid==13){
            jmh::setUnitorder(9);
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(c==4&&dir!=up){
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(c==4&&dir==up){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(sitrep.thing[13][3].what==space&&sitrep.thing[13][4].what==space&&sitrep.thing[12][4].what==space){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        a.action=nothing;
        return a;
    }
    if(unitorder==8){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==19&&unitid==15){
            jmh::setUnitorder(9);
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(r==20&&unitid==14){
            jmh::setUnitorder(9);
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(c==4&&dir!=dn){
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(c==4&&dir==dn){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(sitrep.thing[17][3].what==space&&sitrep.thing[17][4].what==space&&sitrep.thing[18][4].what==space){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        a.action=nothing;
        return a;
    }
    if(unitorder==9){
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
				a.action=attack;
				return a;
			}
		}
	}
            if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitorder==10){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==21){
            jmh::setUnitorder(2);
            a.action=turn;
            a.dir=rt;
            return a;}
        a.action=fwd;
        a.maxDist=5;
        if(rank==infantry){
            a.maxDist=1;
        }
        return a;
    }
    a.action=nothing;
    return a;
    }
    if(sideofmap==2){
        if(rank==crown){
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
				a.action=attack;
				return a;
			}
		}
	}
        a.action=nothing;
        return a;
    }
    if(unitorder==1){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==8){
            jmh::setUnitorder(2);
            a.action=turn;
            a.dir=lt;
            return a;}
        a.action=fwd;
        a.maxDist=5;
        if(rank==infantry){
            a.maxDist=1;
        }
        return a;
    }
    if(unitorder==2){
        return jmh::hunting(r,c,dir,sitrep);
    }
    if(unitorder==3){
        //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                a.action=nothing;
                return a;
    }
    if(unitorder==4){
        if(rank==infantry){
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
				a.action=attack;
				return a;
			}
		}
	}
        }
            if(rank==archer&&c==21){
                jmh::setUnitorder(3);
                a.action=nothing;
                return a;
            }
            if(rank==infantry&&c==20){
                a.action=turn;
                if(unitid==5){
                    a.dir=up;
                }
                if(unitid==6){
                   a.dir=dn;
                }
                jmh::setUnitorder(9);
                return a;
            }
        a.action=fwd;
        a.maxDist=1;
        return a;
    }
    if(unitorder==5){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==8){
            jmh::setUnitorder(2);
            a.action=turn;
            a.dir=lt;
            return a;
        }
        if(c==25&&dir!=up){
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(c==25&&dir==up){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(sitrep.thing[8][25].tla==tla&&sitrep.thing[8][25].rank==infantry){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        a.action=nothing;
        return a;
    }
    if(unitorder==6){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==21){
            jmh::setUnitorder(2);
            a.action=turn;
            a.dir=lt;
            return a;
        }
        if(c==25&&dir!=dn){
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(c==25&&dir==dn){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(sitrep.thing[21][25].tla==tla&&sitrep.thing[21][25].rank==infantry){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        a.action=nothing;
        return a;
    }
    if(unitorder==7){
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
				a.action=attack;
				return a;
			}
		}
	}
         if(r==10&&unitid==12){
            jmh::setUnitorder(9);
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(r==9&&unitid==13){
            jmh::setUnitorder(9);
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(c==25&&dir!=up){
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(c==25&&dir==up){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(sitrep.thing[13][26].what==space&&sitrep.thing[13][25].what==space&&sitrep.thing[12][25].what==space){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        a.action=nothing;
        return a;
    }
    if(unitorder==8){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==19&&unitid==15){
            jmh::setUnitorder(9);
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(r==20&&unitid==14){
            jmh::setUnitorder(9);
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(c==25&&dir!=dn){
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(c==25&&dir==dn){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(sitrep.thing[17][26].what==space&&sitrep.thing[17][25].what==space&&sitrep.thing[18][25].what==space){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        a.action=nothing;
        return a;
    }
    if(unitorder==9){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitorder==10){
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
				a.action=attack;
				return a;
			}
		}
	}
        if(r==21){
            jmh::setUnitorder(2);
            a.action=turn;
            a.dir=lt;
            return a;}
        a.action=fwd;
        a.maxDist=5;
        if(rank==infantry){
            a.maxDist=1;
        }
        return a;
    }
    a.action=nothing;
    return a;
    }
}
 /*if(mapname=="4player.in"){
    if(sideofmap==1){
    if(rank==crown){
        a.action=nothing;
        return a;
    }
    if(unitid==1){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(c!=2){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==3){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(r!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(r==4&&dir!=lt){
            a.action=turn;
            a.dir=lt;
            return a;
        }
        if(r==4&&c!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==31){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==lt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
        }
        if (r!=3){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(r==3&&dir!=lt){
            a.action=turn;
            a.dir=lt;
            return a;
        }
        if (c!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==32){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==lt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
        }
        if (c!=3){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==33){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==lt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
        }
        if (r!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if (r==4&&dir!=lt){
            a.action=turn;
            a.dir=lt;
            return a;
        }
        if(r==4&&c!=5){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==11){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(c!=27){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==13){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(r!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(r==4&&dir!=rt){
            a.action=turn;
            a.dir=rt;
            return a;
        }
        if(r==4&&c!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==34){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
        }
        if (r!=3){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(r==3&&dir!=rt){
            a.action=turn;
            a.dir=rt;
            return a;
        }
        if (c!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==35){
        //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
        }
        if (c!=26){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==36){
        //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
        }
        if (r!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if (r==4&&dir!=rt){
            a.action=turn;
            a.dir=rt;
            return a;
        }
        if(r==4&&c!=24){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid>4&&unitid<11){
        if(jmh::enemyCount(sitrep)<10){
            jmh::setUnitorder(2);
        }
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(r!=5){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==37||unitid==38){
         //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                a.action=nothing;
                return a;
                }
            if(r!=4){
                a.action=fwd;
                a.maxDist=1;
                return a;
            }
            jmh::setUnitorder(3);
    }
    if(unitid>50&&unitid<57){
        if(r>5){
            jmh::setUnitorder(2);
        }
        if(unitorder==2){
            return jmh::crownhunting(r,c,dir,sitrep);
        }
        a.action=fwd;
        a.maxDist=5;
        return a;
    }
    if(unitid==2||unitid==4||unitid==12||unitid==14||unitid==15){
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        int checki,checkj;
        for(checki=0;checki<5;++checki){
            for(checkj=4;checkj<26;++checkj){
                if(sitrep.thing[checki][checkj].tla!=tla&&sitrep.thing[checki][checkj].what==unit){
                    jmh::setUnitorder(2);
                }
            }
        }
        a.action=nothing;
        return a;
    }
    }//end side of map
   /* if(sideofmap==2){
        if(rank==crown){
            a.action=nothing;
            return a;
        }
        if(unitid==1){
            if(jmh::enemyCount(sitrep)<6){
                jmh::setUnitorder(2);}
            if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(c!=2){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==3){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(r!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(r==25&&dir!=lt){
            a.action=turn;
            a.dir=lt;
            return a;
        }
        if(r==25&&c!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==31){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==lt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
        }
        if (r!=26){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(r==26&&dir!=lt){
            a.action=turn;
            a.dir=lt;
            return a;
        }
        if (c!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==32){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==lt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
        }
        if (c!=3){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==33){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
     if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==lt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=lt;
                    return a;
                }
    }
       if (r!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if (r==25&&dir!=lt){
            a.action=turn;
            a.dir=lt;
            return a;
        }
        if(r==25&&c!=5){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);

    if(unitid==11){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(c!=27){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==13){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(r!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(r==25&&dir!=rt){
            a.action=turn;
            a.dir=rt;
            return a;
        }
        if(r==25&&c!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==34){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
        }
        if (r!=26){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(r==26&&dir!=rt){
            a.action=turn;
            a.dir=rt;
            return a;
        }
        if (c!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==35){
        //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
        }
        if (c!=26){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==36){
        //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
        }
        if (r!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if (r==25&&dir!=rt){
            a.action=turn;
            a.dir=rt;
            return a;
        }
        if(r==25&&c!=24){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid>4&&unitid<11){
        if(jmh::enemyCount(sitrep)<10){
            jmh::setUnitorder(2);
        }
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(r!=24){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==37||unitid==38){
         //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                a.action=nothing;
                return a;
                }
            if(r!=25){
                a.action=fwd;
                a.maxDist=1;
                return a;
            }
            jmh::setUnitorder(3);
    }
    if(unitid>50&&unitid<57){
        if(r<24){
            jmh::setUnitorder(2);
        }
        if(unitorder==2){
            return jmh::crownhunting(r,c,dir,sitrep);
        }
        a.action=fwd;
        a.maxDist=5;
        return a;
    }
    if(unitid==2||unitid==4||unitid==12||unitid==14||unitid==15){
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        int checki,checkj;
        for(checki=24;checki<30;++checki){
            for(checkj=4;checkj<26;++checkj){
                if(sitrep.thing[checki][checkj].tla!=tla&&sitrep.thing[checki][checkj].what==unit){
                    jmh::setUnitorder(2);
                }
            }
        }
        a.action=nothing;
        return a;
    }
    }//end side of map

    if(rank==crown){
        a.action=nothing;
        return a;
    }
    if(unitid==1){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(r!=2){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==3){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(c!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(c==4&&dir!=up){
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(c==4&&r!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==31){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
        }
        if (c!=3){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(c==3&&dir!=up){
            a.action=turn;
            a.dir=up;
            return a;
        }
        if (r!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==32){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
        }
        if (r!=3){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==33){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
            if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==up){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=up;
                    return a;
                }
        }
        if (c!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if (c==4&&dir!=up){
            a.action=turn;
            a.dir=up;
            return a;
        }
        if(c==4&&r!=5){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==11){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(r!=27){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==13){
        if(jmh::enemyCount(sitrep)<6){
            jmh::setUnitorder(2);}
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(c!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(c==4&&dir!=dn){
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(c==4&&r!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==34){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
        }
        if (c!=3){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if(c==3&&dir!=dn){
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if (r!=25){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==35){
        //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
        }
        if (r!=26){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid==36){
        //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                if(dir==dn){
                    a.action=turn;
                    a.dir=rt;
                    return a;
                }
                if(dir==rt){
                    a.action=turn;
                    a.dir=dn;
                    return a;
                }
        }
        if (c!=4){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        if (c==4&&dir!=dn){
            a.action=turn;
            a.dir=dn;
            return a;
        }
        if(c==4&&r!=24){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        jmh::setUnitorder(3);
    }
    if(unitid>4&&unitid<11){
        if(jmh::enemyCount(sitrep)<10){
            jmh::setUnitorder(2);
        }
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        if(c!=5){
            a.action=fwd;
            a.maxDist=1;
            return a;
        }
        return jmh::guard(r,c,dir,sitrep);
    }
    if(unitid==37||unitid==38){
         //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
        if(unitorder==3){
            //ARCHER ATTACK CODE
                int tr=r;
                int tc=c;
                int pl=0;
                jmh::archeryAttack(tr,tc,sitrep,dir,pl);
                if(pl>0){
                    a.action=attack;
                    a.ar=tr;
                    a.ac=tc;
                    return a;
                }
                a.action=nothing;
                return a;
                }
            if(c!=4){
                a.action=fwd;
                a.maxDist=1;
                return a;
            }
            jmh::setUnitorder(3);
    }
    if(unitid>50&&unitid<57){
        if(c>5){
            jmh::setUnitorder(2);
        }
        if(unitorder==2){
            return jmh::crownhunting(r,c,dir,sitrep);
        }
        a.action=fwd;
        a.maxDist=5;
        return a;
    }
    if(unitid==2||unitid==4||unitid==12||unitid==14||unitid==15){
        if(unitorder==2){
            return jmh::hunting(r,c,dir,sitrep);
        }
        int checki,checkj;
        for(checki=4;checki<26;++checki){
            for(checkj=0;checkj<25;++checkj){
                if(sitrep.thing[checki][checkj].tla!=tla&&sitrep.thing[checki][checkj].what==unit){
                    jmh::setUnitorder(2);
                }
            }
        }
        a.action=nothing;
        return a;
    }
    }//end side of map
 }*/
        if(rank==knight){
            return jmh::crownhunting(r,c,dir,sitrep);
        }
        if(rank==crown){
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
				a.action=attack;
				return a;
			}
		}
	}
            a.action=nothing;
            return a;
        }
        if(rank==archer){
            int pl=0;
            int tr=r;
            int tc=c;
            jmh::archeryAttack(tr,tc,sitrep,dir,pl);
            if(pl>0){
                a.action=attack;
                a.ar=tr;
                a.ac=tc;
            }
            if(dir==rt){
                a.action=turn;
                a.dir=up;
                return a;
            }
            if(dir==up){
                a.action=turn;
                a.dir=lt;
                return a;
            }
            if(dir==lt){
                a.action=turn;
                a.dir=dn;
                return a;
            }
            if(dir==dn){
                a.action=turn;
                a.dir=rt;
                return a;
            }
            a.action=nothing;
            return a;
        }
    if(unitid>0&&unitid<5){
        return jmh::guard(r,c,dir,sitrep);
    }
    if(rank==infantry){
        return jmh::hunting(r,c,dir,sitrep);
    }

a.action=nothing;
return a;
}
