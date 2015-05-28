#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>
#include "lionheart.h"

// A few globals, just to be Old School

int numplayers;
int numTurns;
std::string winner;
			
void unit2thing(Unit *u, int r, int c,Board& board){
	if(!u){board.things[r][c].what=space; return;}
	if(u->getDead()){board.things[r][c].what=space; return;}
	board.things[r][c].what = unit;
	board.things[r][c].rank = u->getRank();
	board.things[r][c].tla = u->getTla();
	board.things[r][c].dir = u->getDir();
	board.things[r][c].hp = u->getHp();
}

void makeB(Unit *u[NUM],Board& board){
	int i,j;
	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			board.things[i][j].what=space;
			if(board.c[i][j]=='X')board.things[i][j].what = rock; 
		}
	}
			
	for(i=0;i<NUM;++i){
		if(u[i])unit2thing(u[i],u[i]->getR(),u[i]->getC(),board);
	}
}

bool nextToBarrier(Unit *u,Board const & board){
	int r,c;
	r=u->getR();
	c=u->getC();
	if(r-1>0     && c-1>0     && board.things[r-1][c-1].what == rock)return true;
	if(r-1>0                  && board.things[r-1][c  ].what == rock)return true;
	if(r-1>0     && c+1<=COLS && board.things[r-1][c+1].what == rock)return true;
	if(             c-1>0     && board.things[r  ][c-1].what == rock)return true;
	if(             c+1<=COLS && board.things[r  ][c+1].what == rock)return true;
	if(r+1<=ROWS && c-1>0     && board.things[r+1][c-1].what == rock)return true;
	if(r+1<=ROWS              && board.things[r+1][c  ].what == rock)return true;
	if(r+1<=ROWS && c+1<=COLS && board.things[r+1][c+1].what == rock)return true;
	return false;
}

bool localSearch(Dir map[ROWS][COLS], Dir map2[ROWS][COLS],int r, int c,Board const & board){
	if(map[r][c]!=none)return false;
	if(board.things[r][c].what==rock)return false;

	if(r-1>=0  &&map2[r-1][c  ]!=none){map[r][c]=up;return true;}
	if(c+1<COLS&&map2[r  ][c+1]!=none){map[r][c]=rt;return true;}
	if(r+1<ROWS&&map2[r+1][c  ]!=none){map[r][c]=dn;return true;}
	if(c-1>=0  &&map2[r  ][c-1]!=none){map[r][c]=lt;return true;}

	return false;
}



Dir pathDirFor(int sr, int sc, int er, int ec,Board const & board){
	Dir map[ROWS][COLS],map2[ROWS][COLS];
	
	int i,j;
	bool changes=true;

	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			map[i][j]=none;
			map2[i][j]=none;
		}
	}
	map[er][ec]=rt;
	map2[er][ec]=rt;
	

	while(changes){
		changes=false;

		for(i=0;i<ROWS;++i){
			for(j=0;j<COLS;++j){
				if(localSearch(map,map2,i,j,board))changes=true;
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


float getDist(int r,int c,int tr,int tc){
	return sqrt((double)(tr-r)*(tr-r)+(tc-c)*(tc-c));
}

Location getNearestEnemyCrown(Unit *u[], int m,Board const & board){
	int r,c;
	int tr,tc;
  std::string tla;
	int i;
	float minDist=ROWS*COLS;
	Location l;
	int mini=0;
	r=u[m]->getR();
	c=u[m]->getC();
	tla=u[m]->getTla();
	for(i=0;i<NUM;++i){
		if(i!=m&&u[i]&&!u[i]->getDead()&&u[i]->getTla()!=tla&&u[i]->getRank()==crown){
			tr=u[i]->getR();
			tc=u[i]->getC();
			if(getDist(r,c,tr,tc)<minDist){
				mini=i;
				minDist=getDist(r,c,tr,tc);
			}
		}
	}
	l.r=u[mini]->getR();	
	l.c=u[mini]->getC();	
	l.dirFor=pathDirFor(r,c,l.r,l.c,board);
	return l;
}

Location getNearestEnemy(Unit *u[], int m,Board& board){
	int r,c;
	int tr,tc;
  std::string tla;
	int i;
	float minDist=ROWS*COLS;
	Location l;
	int mini=0;
	r=u[m]->getR();
	c=u[m]->getC();
	tla=u[m]->getTla();
	for(i=0;i<NUM;++i){
		if(i!=m&&u[i]&&!u[i]->getDead()&&u[i]->getTla()!=tla){
			tr=u[i]->getR();
			tc=u[i]->getC();
			if(getDist(r,c,tr,tc)<minDist){
				mini=i;
				minDist=getDist(r,c,tr,tc);
			}
		}
	}
	l.r=u[mini]->getR();	
	l.c=u[mini]->getC();	
	l.dirFor=pathDirFor(r,c,l.r,l.c,board);
	return l;

}

Dir manhattenDirFor(Unit *u, int tr, int tc){
	int dr,dc;
	dr = tr-(u->getR());
	dc = tc-(u->getC());
	if(abs(dr)>abs(dc)){
		if(dr>=0)return dn;
		else     return up;
	}else{
		if(dc>=0)return rt;
		else     return lt;
	}
}

Dir anyDir(Unit *u,Board& board){
	int r,c;
	int tr,tc;
	r=u->getR();
	c=u->getC();
	tr=r-1;tc=c  ;if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS&&board.things[tr][tc].what==space)return up;
	tr=r+1;tc=c  ;if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS&&board.things[tr][tc].what==space)return dn;
	tr=r  ;tc=c-1;if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS&&board.things[tr][tc].what==space)return lt;
	tr=r  ;tc=c+1;if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS&&board.things[tr][tc].what==space)return rt;
	return none;
}
		
	

SitRep makeSitRep(Unit *u[NUM],int m,Board& board){
	if(!u[m])exit(5);
	SitRep s;
	int i,j;
	for(i=0;i<ROWS;++i)for(j=0;j<COLS;++j)s.thing[i][j]=board.things[i][j];
	s.nearestEnemyCrown = getNearestEnemyCrown(u,m,board);
	s.nearestEnemy = getNearestEnemy(u,m,board);
	s.anyOpenSpace = anyDir(u[m],board);
	s.turnNumber = numTurns;
	return s;
}

int totalHp(Unit *u[], int m,Board const & board){
	int i,sum=0;
	for(i=0;i<NUM;++i)if(u[i]&&u[i]->getTla()==board.tla[m]) sum+=u[i]->getHp();
	return sum;
}

void display(Unit *u[],Board& board,std::ostringstream& sout){
	int i,j;
	int lsize;
	int rsize;
	if(ANSI)lsize = (numplayers*3)+((numplayers-1)*5);
	else lsize = 29;
	rsize=(COLS-lsize)/2;
	if(!TINYMAP){rsize=(COLS*2-lsize)/2;}

	// don't display anything if we are doing the rankings
	if(AUTOTOURNEY)return;

	for(i=0;i<NUM;++i)if(u[i])unit2thing(u[i],u[i]->getR(),u[i]->getC(),board);

	// throw a legend out at the top
	sout << "\n";
	sout << "\n";
	board.color[0]="\033[0;31m";
	board.color[1]="\033[0;35m";
	board.color[2]="\033[0;36m";
	board.color[3]="\033[0;37m";
	sout<<"turn: "<<numTurns<<"  ";
	if(numTurns>9)rsize--;
	if(numTurns>99)rsize--;
	for(i=0;i<rsize-9;++i)sout<<" ";
	if(ANSI) for(i=0;i<numplayers;++i) sout <<board.color[i]<<board.tla[i]<<" "<<totalHp(u,i,board)<<"\033[0m     ";
	else     sout <<board.tla[0]<<" (lowercase) "<<totalHp(u,0,board)<<"   "<<board.tla[1]<<" (ALLCAPS) "<<totalHp(u,1,board);
	sout << "\n ";
	for(i=0;i<COLS;++i)sout<<"-";
	if(!TINYMAP) for(i=0;i<COLS;++i)sout<<"-";
	sout << "\n";

	// down to business
	for(i=0;i<ROWS;++i){
		sout<<"|";
		for(j=0;j<COLS;++j){
			// if it's open space
			if(board.things[i][j].what==space){
				if(DOTS) sout<<".";
				else     sout<<" ";
				if(!TINYMAP)sout<<" ";
				 continue;
			}
			
			// if it's a rock
			if(board.things[i][j].what==rock){
				sout<<"X";
				if(!TINYMAP)sout<<" ";
				continue;
			 }
			
			//else it's a unit
			//turn on some colors if ANSI set
			if(ANSI){
				if(board.things[i][j].tla==board.tla[0]) sout << "\033[0;31m";
				if(board.things[i][j].tla==board.tla[1]) sout << "\033[0;35m";
				if(board.things[i][j].tla==board.tla[2]) sout << "\033[0;36m";
				if(board.things[i][j].tla==board.tla[3]) sout << "\033[0;37m";
			}

			//spit out the appropriate unit character
			if(ANSI || board.things[i][j].tla==board.tla[0]){
				switch(board.things[i][j].rank){
				case infantry: sout<<"i";break;
				case archer:   sout<<"a";break;
				case knight:   sout<<"k";break;
				case crown:    sout<<"*";break;
				default:       sout<<"?";break;
				}
			}else{
				switch(board.things[i][j].rank){
				case infantry: sout<<"I";break;
				case archer:   sout<<"A";break;
				case knight:   sout<<"K";break;
				case crown:    sout<<"*";break;
				default:       sout<<"?";break;
				}
			}

			//indicate direction if there is space
			if(!TINYMAP){
				switch(board.things[i][j].dir){
				case up:  sout<<"^";break;
				case dn:  sout<<"v";break;
				case rt:  sout<<">";break;
				case lt:  sout<<"<";break;
				default: sout<<"?";break;
				}
			}

			//turn off the colors if we set them earlier
			if(ANSI)sout << "\033[0m";
		}
		sout<<"|";
		sout << "\n";
	}
	sout<<" ";
	for(i=0;i<COLS;++i)sout<<"-";
	if(!TINYMAP) for(i=0;i<COLS;++i)sout<<"-";
	sout << "\n";
	return;
}


void readMap(Board& board){
	int i,j,rows,cols;
	ifstream  fin;
	fin.open(INFILE);
	if (fin.fail()){
		cout << "error opening file: check to make sure the map file is in the same\n";
		cout << "directory as the executable.  exiting.\n";
		exit(3);
	}
	fin>>rows;
	fin>>cols;
	fin>>numplayers;
	if(rows!=ROWS || cols!=COLS){
		cout << "error reading map: ROW/COL mismatch with #define in unit.h.  exiting.\n";
		exit(1);
	}
	if(numplayers>4){
		cout << "error reading map: max 4 players (more requested).  exiting.\n";
		exit(2);
	}
	if(NUM%numplayers!=0){
		cout << "error reading map: total number of units can't be evenly divided.  exiting.\n";
		exit(3);
	}
	for(i=0;i<numplayers;++i){
		fin>>board.startBox[i].minr;
		fin>>board.startBox[i].maxr;
		fin>>board.startBox[i].minc;
		fin>>board.startBox[i].maxc;
	}
	
	// max 2 players for non-ANSI terminal
	if(numplayers>2&&!ANSI)numplayers=2;

	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			board.things[i][j].what=space;
			fin >> board.c[i][j];
			if(board.c[i][j]=='X'){
				board.things[i][j].dir = none; 
				board.things[i][j].what = rock; 
			}
		}
	//cout << endl;
	}
	fin.close();
}


void printTlaList(){
	int i;
	for(i=0;i<NUMTLAS;++i){
		cout << tlalist[i]<<" ";
		if((i+1)%11==0)cout<<endl;
	}
	cout<< endl;
}


bool checksOut(std::string tla){
	int i;
	for(i=0;i<NUMTLAS;++i){
		if(tlalist[i]==tla)return true;
	}
	return false;
}

Unit * newUnit(std::string tla, Rank rank){
	int hp;
	switch(rank){
	case infantry:	hp=INFANTRYHP;	break;
	case archer:	hp=ARCHERHP;	break;
	case knight:	hp=KNIGHTHP;	break;
	case crown:	hp=CROWNHP;	break;
	}

	if(tla=="xxx")return new Unit(0,0,hp,up,rank,false,tla);

  
if(tla=="adn") return new adn(0,0,hp,up,rank,false,tla);
if(tla=="alt") return new alt(0,0,hp,up,rank,false,tla);
if(tla=="ben") return new ben(0,0,hp,up,rank,false,tla);
if(tla=="bri") return new bri(0,0,hp,up,rank,false,tla);
if(tla=="dww") return new dww(0,0,hp,up,rank,false,tla);
if(tla=="ian") return new ian(0,0,hp,up,rank,false,tla);
if(tla=="jcl") return new jcl(0,0,hp,up,rank,false,tla);
if(tla=="jmh") return new jmh(0,0,hp,up,rank,false,tla);
if(tla=="oss") return new oss(0,0,hp,up,rank,false,tla);
if(tla=="pld") return new pld(0,0,hp,up,rank,false,tla);
if(tla=="sll") return new sll(0,0,hp,up,rank,false,tla);
if(tla=="tbb") return new tbb(0,0,hp,up,rank,false,tla);

 	cout << "error making soldier.  quitting.\n";
	exit(0);
}

void updateB(Unit *u,Board& board){
	if(!u)exit(5);
	board.things[u->getR()][u->getC()].what=unit;
	board.things[u->getR()][u->getC()].rank=u->getRank();
	board.things[u->getR()][u->getC()].tla=u->getTla();
	board.things[u->getR()][u->getC()].dir=u->getDir();
	board.things[u->getR()][u->getC()].hp=u->getHp();
}



void checkPlacement(Unit *u,Unit t,int minr,int maxr,int minc,int maxc,Board& board){
	int tr, tc;
	tr=u->getR();
	tc=u->getC();
	int i;
	
	if(board.things[tr][tc].what==rock){
		cout << "error: "<<u->getTla()<<" placed unit on a rock. exiting.\n";
		exit (6);
	}
	if(board.things[tr][tc].what==unit){
		cout << "error: "<<u->getTla()<<" placed unit on another unit. exiting.\n";
		exit (6);
	}
	if(tr<minr||tr>maxr||tc<minc||tc>maxc){
		cout << "error: "<<u->getTla()<<" placed unit outside of box. exiting.\n";
		exit (6);
	}
        if(t.getHp()!=u->getHp()||t.getRank()!=u->getRank()
           ||t.getDead()!=u->getDead()||t.getTla()!=u->getTla()){
		cout << "error: "<<u->getTla()<<" performed illegal unit modification during placement. exiting.\n";
		exit (7);
	}

}


void checkNoMods(Unit *u,Unit t){
	int tr, tc;

        if(t.getHp()!=u->getHp()||t.getDir()!=u->getDir()||t.getRank()!=u->getRank()
           ||t.getDead()!=u->getDead()||t.getTla()!=u->getTla()
	   ||t.getR()!=u->getR()||t.getC()!=u->getC()){
		cout << "error: "<<u->getTla()<<" performed illegal unit modification during recommendation. exiting.\n";
		exit (8);
	}

}

void setUpBoard(Unit *u[NUM],Board& board){
	Unit t;
	readMap(board);
	bool gotNames=false;
	int i;
	int pnum;
	int minr,maxr,minc,maxc;

	for(i=0;i<NUM;++i)u[i]=0;

	if(!AUTOTOURNEY){
		for(i=0;i<numplayers;++i){
tryagain:
			cout<<"tla"<<i<<": ";
			cin >> board.tla[i];
			if(board.tla[i]=="?"){printTlaList();goto tryagain;}
			if(!checksOut(board.tla[i])){
				cout << "That tla is not in the list.\n";
				cout << "type '?' to see a full list.\n";
				goto tryagain;
			}
		}
	}

	// make all the crowns
	for(i=0;i<numplayers;++i){
		pnum=i%numplayers;
		minr=board.startBox[pnum].minr;
		maxr=board.startBox[pnum].maxr;
		minc=board.startBox[pnum].minc;
		maxc=board.startBox[pnum].maxc;
		u[i]=newUnit(board.tla[pnum],crown);
		t=*u[i];
		u[i]->Place(minr,maxr,minc,maxc,makeSitRep(u,i,board));
		checkPlacement(u[i],t,minr,maxr,minc,maxc,board);
		updateB(u[i],board);
	}
	// make all the knights
	for(;i<(numplayers+NUMKNIGHTS);++i){
		pnum=i%numplayers;
		pnum=i%numplayers;
		minr=board.startBox[pnum].minr;
		maxr=board.startBox[pnum].maxr;
		minc=board.startBox[pnum].minc;
		maxc=board.startBox[pnum].maxc;
		u[i]=newUnit(board.tla[pnum],knight);
		t=*u[i];
		u[i]->Place(minr,maxr,minc,maxc,makeSitRep(u,i,board));
		checkPlacement(u[i],t,minr,maxr,minc,maxc,board);
		updateB(u[i],board);
	}
	// make all the archers
	for(;i<(numplayers+NUMKNIGHTS+NUMARCHERS);++i){
		pnum=i%numplayers;
		minr=board.startBox[pnum].minr;
		maxr=board.startBox[pnum].maxr;
		minc=board.startBox[pnum].minc;
		maxc=board.startBox[pnum].maxc;
		u[i]=newUnit(board.tla[pnum],archer);
		t=*u[i];
		u[i]->Place(minr,maxr,minc,maxc,makeSitRep(u,i,board));
		checkPlacement(u[i],t,minr,maxr,minc,maxc,board);
		updateB(u[i],board);
	}
	// make all the infantry
	for(;i<NUM;++i){
		pnum=i%numplayers;
		minr=board.startBox[pnum].minr;
		maxr=board.startBox[pnum].maxr;
		minc=board.startBox[pnum].minc;
		maxc=board.startBox[pnum].maxc;
		u[i]=newUnit(board.tla[pnum],infantry);
		t=*u[i];
		u[i]->Place(minr,maxr,minc,maxc,makeSitRep(u,i,board));
		checkPlacement(u[i],t,minr,maxr,minc,maxc,board);
		updateB(u[i],board);
	}

	return;
}

//return the number of spaces the unit can move without hitting something,
//up to dist
int clear(Unit *u[], int m, int dist,Board const& board){
	if(!u[m])exit(5);
	int i;
	int goDist=0;
	//initialize x and y to the unit's location
	int tr=u[m]->getR();
	int tc=u[m]->getC();

	for(i=0;i<dist;++i){
		//move tr and tc to be in front of the unit's location
		switch(u[m]->getDir()){
		case up:tr--;break;
		case dn:tr++;break;
		case lt:tc--;break;
		case rt:tc++;break;
		case none:break;
		}
	
		// is that space off the board?
		if(tr<0||tr>=ROWS||tc<0||tc>=COLS)break;
	
		// is there a something there?
		if(board.things[tr][tc].what!=space)break;
	
		//nothing there?  bump the goDist
		++goDist;
	}
	
	return goDist;
}

void arrowSuffer(Unit *u[],int m,int ar,int ac,int hits){
	int sr,sc,er,ec;

	if(!u[m])exit(5);
	int i;
	//initialize x and y to the unit's location
	int tr=u[m]->getR();
	int tc=u[m]->getC();

	//find the box the archer can target
       	switch(u[m]->getDir()){
        case up: sr=tr-3;er=tr-1;sc=tc-1;ec=tc+1;break;
        case dn: sr=tr+1;er=tr+3;sc=tc-1;ec=tc+1;break;
        case lt: sr=tr-1;er=tr+1;sc=tc-3;ec=tc-1;break;
        case rt: sr=tr-1;er=tr+1;sc=tc+1;ec=tc+3;break;
        case none: return;
	}

        if(sr<0)sr=0;if(er>=ROWS)er=ROWS-1;
        if(sc<0)sc=0;if(ec>=COLS)ec=COLS-1;
	
	//return if the target is not in range
	if(ar<sr||ar>er||ac<sc||ac>ec)return;

 

	//check to see if any living unit occupies space [ar,ac]
	for(i=0;i<NUM;++i){
		if(u[i]&&!u[i]->getDead()&&u[i]->getR()==ar&&u[i]->getC()==ac){
			//if so, make it suffer
			u[i]->Suffer(hits);
			if(u[i]->getDead()){
				delete u[i];
				u[i]=0;
			}
		}
	}

	//nobody there? then just return
	return;
}



//make an attacked unit suffer hits
void makeSuffer(Unit *u[], int m, int hits){
	if(!u[m])exit(5);
	int i;
	//initialize x and y to the unit's location
	int tr=u[m]->getR();
	int tc=u[m]->getC();

	//move tr and tc to be in front of the unit's location
	switch(u[m]->getDir()){
	case up:tr--;break;
	case dn:tr++;break;
	case lt:tc--;break;
	case rt:tc++;break;
	case none:break;
	}

	//check to see if any living unit occupies space [x,y]
	for(i=0;i<NUM;++i){
		if(u[i]&&!u[i]->getDead()&&u[i]->getR()==tr&&u[i]->getC()==tc){
			//if so, make it suffer
			u[i]->Suffer(hits);
			if(u[i]->getDead()){
				delete u[i];
				u[i]=0;
			}
		}
	}

	//nobody there? then return false
	return;
}


bool oneLeft(Unit *u[NUM],Board& board){
	int i,j;
  std::string firstTla;
  std::string secondTla;
	int maxHp=0;
	int maxPlayer=0;
	int numWinners=0;

	// out of time?
	if(numTurns>MAXTURNS){
		for(i=0;i<numplayers;++i){
			if(totalHp(u,i,board)>maxHp){
				maxHp=totalHp(u,i,board);
				maxPlayer=i;
			}
		}
		for(i=0;i<numplayers;++i){
			if(totalHp(u,i,board)==maxHp){
				if(!AUTOTOURNEY)cout << board.tla[i]<<" has the most armies! ("<<totalHp(u,i,board)<<")\n";
				if(AUTOTOURNEY)winner=board.tla[i];
				numWinners++;
			}
		}
		if(numWinners>1){
			if(!AUTOTOURNEY)cout << "It's a TIE!\n";
			if(AUTOTOURNEY)winner="tie";
		}
		return true;
	}

	//get the first crown tla
	for(i=0;i<NUM;++i){
		if(u[i]&&u[i]->getRank()==crown){
			firstTla=u[i]->getTla();
			break;
		}
	}
	if(i==NUM){
		//both kings are dead
		if(!AUTOTOURNEY)cout << "All crowns die! Everyone wins. \n";
		if(AUTOTOURNEY)winner="nil";
		return true;
	}
	//get the second crown tla
	for(i=0;i<NUM;++i){
		if(u[i]&&u[i]->getRank()==crown&&u[i]->getTla()!=firstTla){
			secondTla=u[i]->getTla();
			break;
		}
	}
	if(i==NUM){
		//only one king lives
		if(!AUTOTOURNEY)cout << "The one true crown! "<<firstTla<<" wins. \n";
		if(AUTOTOURNEY)winner=firstTla;
		return true;
	}

	//get the first tla
	for(i=0;i<NUM;++i){
		if(u[i]){
			firstTla=u[i]->getTla();
			break;
		}
	}
	
	//look for a different tla
	for(i=0;i<NUM;++i){
		if(u[i]&&u[i]->getTla()!=firstTla){
			return false;
		}
	}
		
	if(!AUTOTOURNEY)cout<<firstTla<<" wins!\n";
	//there can be only one
	if(AUTOTOURNEY)winner=firstTla;
	return true;
}

	
void doTurn(Unit *u[NUM],Board& board){
	Unit tu;
	int m;
    	SitRep sitRep;
    	Action a;
    	int hits;
	int lr,lc;
	int i,j,t;
  std::array<int,NUM> next;

	//come up with a random ordering of pieces for this turn
	for(i=0;i<NUM;++i)next[i]=i;
  static std::random_device rd;
  static std::mt19937 engine(rd());
  std::shuffle(std::begin(next),std::end(next),engine);
	

	for(i=0;i<NUM;++i){
		m=next[i];
		if(oneLeft(u,board))return;;
        	if(u[m]&&!u[m]->getDead()){
			makeB(u,board);
            		sitRep=makeSitRep(u,m,board);
			tu=*u[m];
            		a=u[m]->Recommendation(sitRep);
			checkNoMods(u[m],tu);
            		switch(a.action){
				case turn:
					u[m]->Turn(a.dir);
					break;
				case fwd:
					lr=u[m]->getR();
					lc=u[m]->getC();
					if(!clear(u,m,a.maxDist,board))break;
					if(u[m]->getRank()==archer||u[m]->getRank()==infantry)
						a.maxDist=1;
					u[m]->Move(clear(u,m,a.maxDist,board));
					break;
				case attack:
					hits=u[m]->Attack();
					if(u[m]->getRank()==archer)
						arrowSuffer(u,m,a.ar,a.ac,hits);
					else
						makeSuffer(u,m,hits);
					break;
				case nothing: break;
            		}
        	}
	}
	return;
}


//run an automatic game.  tla1 and tla2 should be set up prior to calling
int autoGame(Unit *u[],Board& board){
	bool done=false;

	// set up the board
	setUpBoard(u,board);
	
	while(!done){
		// do a turn
		++numTurns;
		doTurn(u,board);	
		if(oneLeft(u,board))done=true;
	}
	if(AUTOTOURNEY){
		if(winner==board.tla[0])return 2;
		else if(winner=="tie")return 1;
	}
	return 0;
}

//run a whole tournament of each tla against AUTONUMMATCHES random others, output stats on each
void autoTourney(Unit *u[],Board& board){
	int i,j,k;
	int wins;
	int w;
	for(i=0;i<NUMTLAS;++i){
		if(noPlay[i])continue;
		wins=0;
		board.tla[0]=tlalist[i];	
		for(j=0;j<AUTONUMMATCHES;++j){
			numTurns=0;
			//k=rand()%NUMTLAS;
			//while(k==i || noPlay[k])k=rand()%NUMTLAS;
			k=79;
			board.tla[1]=tlalist[k];	
			w=autoGame(u,board);
			//cout << "\t"<<tla[0]<<" vs. "<<tla[1]<<": ";
			//cout << "winner: "<<winner<<"  -- ";
			//if(w==2)cout<<"win\n";
			//else if(w==1)cout<<"tie\n";
			//else cout<<"lose\n";
			wins+=w;
		}
		cout << i << ": "<<board.tla[0] << " ";
		cout << wins;
		cout << endl;
	}
	return;
}

int main()
{

  Board board;

  Unit* u[NUM];
  char line[1024];
  bool done = false;
  numTurns = 0;


  // if running an auto tourney, just do that and quit
  if (AUTOTOURNEY) {
    autoTourney(u,board);
    return 0;
  }

  // set up the board
  setUpBoard(u,board);
  std::ostringstream sout;
  display(u,board,sout);
  cin.getline(line, 1023);
  cout << sout.str();
  sout.str("");

  while (!done)
  {
    // do a turn
    ++numTurns;
    doTurn(u,board);
    display(u,board,sout);
    cin.getline(line, 1023);
    cout << sout.str();
    sout.str("");
    if (line[0] == 'q') done = true;
    if (oneLeft(u,board)) done = true;
  }
  return 0;
}

