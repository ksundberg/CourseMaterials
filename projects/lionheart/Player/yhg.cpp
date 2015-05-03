#include "yhg.h"
#include <cmath>
#include <iostream>
#include "lionheart2.h"

int yhg::infStart=0;
int yhg::numAttacks=0;
bool yhg::inCombat=false;
Dir yhg::threatDir=none;
bool yhg::crownThreat=false;
int yhg::aC=0;
int yhg::aR=0;

const char WALL  ='X';
const char TARGET='O';
const char EMPTY ='.';
const char UP    ='^';
const char DOWN  ='v';
const char LEFT  ='<';
const char RIGHT ='>';

class Tile{
public:
	//constructors
	Tile();
	Tile(bool, bool, char, char, char);
	//destructor
	~Tile();
	//accessors
	bool getOccupied();
	bool getAllied();
	char getOnTile();
	char getPath();
	char getFloorPath();

	//actions
	void fillOnTile(char);
	void fillPath(char);
	void fillFloorPath(char);
	void setOccupied(bool);
	void setAllied(bool);


	bool occupied;
	bool allied;
	char onTile;		//what you would actually see
	char path;		//path for the floor
	char floorPath;	//finished floor with path
};
	//constructors
Tile::Tile(){
	occupied=true;
	allied=false;
	onTile=WALL;
	path=EMPTY;
	floorPath=EMPTY;

}

Tile::Tile(bool ioccupied, bool iallied, char iOnTile, char ipath, char ifloorPath){
	occupied=ioccupied;
	allied=iallied;

	fillOnTile(iOnTile);

	fillPath(ipath);

	fillFloorPath(ifloorPath);
}

	//destructor
Tile::~Tile(){}

	//accessors
bool Tile::getOccupied(){
	return occupied;
}

bool Tile::getAllied(){
	return allied;
}

char Tile::getOnTile(){
	return onTile;
}

char Tile::getPath(){
	return path;
}

char Tile::getFloorPath(){
	return floorPath;
}

	//actions
void Tile::fillOnTile(char iOnTile){
	if(iOnTile!=WALL && iOnTile!=EMPTY && iOnTile!=TARGET && iOnTile!='H' && iOnTile!=' ')iOnTile=WALL;
	onTile=iOnTile;
	if(onTile==WALL)occupied=true;
}

void Tile::fillPath(char ipath){
	if(ipath!=EMPTY && ipath!=UP && ipath!=DOWN && ipath!=LEFT && ipath!=RIGHT && ipath!=TARGET)ipath=EMPTY;
	path=ipath;
	if(path==EMPTY)occupied=true;
}

void Tile::fillFloorPath(char ifloorPath){
	if(ifloorPath!=WALL && ifloorPath!=EMPTY && ifloorPath!=TARGET && ifloorPath!=UP && ifloorPath!=DOWN && ifloorPath!=LEFT && ifloorPath!=RIGHT)ifloorPath=WALL;
	floorPath=ifloorPath;
	if(floorPath==WALL)occupied=true;
}

void Tile::setOccupied(bool ioccupied){
	occupied=ioccupied;
}

void Tile::setAllied(bool iallied){
	allied=iallied;
}

class Floor{
public:
	//constructors

	Floor();
	Floor(int ier, int iec);
	//destructor

	~Floor();
	//accessors
	int getER();
	int getEC();

	//actions

	void readFloor(SitRep sitrep);
	void printOnTile();
	void printPath();
	void printFloorPath();
	bool localSearch(int r, int c);
	void makePath();
	void makeFloorPath();
	void setEC(int x);
	void setER(int y);

	int sr, sc, er, ec;
	Tile tile[ROWS][COLS];
};

//constructors
Floor::Floor(){
	sr=1;
	sc=0;
	er=ROWS-2;
	ec=COLS-1;
	
	Tile tile[ROWS][COLS];
}
Floor::Floor(int ier, int iec){
	if(ier<0)ier=0;
	if(ier>ROWS)ier=ROWS;
	er=ier;

	if(iec<0)iec=0;
	if(iec>COLS)iec=COLS;
	ec=iec;

	Tile tile[ROWS][COLS];
}
//deconstructor
Floor::~Floor(){
	return;
}

//accessors
int Floor::getEC(){
	return ec;
}

int Floor::getER(){
	return er;
}

//controls
void Floor::setEC(int x){//sets x coordinate for the target

	if(x<0)x=0;
	if(x>=COLS)x=COLS-1;
	ec=x;
}

void Floor::setER(int y){//sets y coordinate for the target

	if(y<0)y=0;
	if(y>=ROWS)y=ROWS-1;

	er=y;
}
//print commands
void Floor::printOnTile(){//prints the walls, empty spaces, and anythings else that is on the floor itself
	int i,j;

	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			cout << tile[i][j].getOnTile()<< " ";
		}
		cout << endl;
	}
	//cin>>i;
	cout<<endl;
}

void Floor::printPath(){//prints just the path
	int i,j;

	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			cout << tile[i][j].getPath()<< " ";
		}
		cout << endl;
	}
	//cin>>i;
	cout<<endl;
}

void Floor::printFloorPath(){//
	int i,j;

	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			cout << tile[i][j].getFloorPath()<< " ";
		}
		cout << endl;
	}
	//cin>>i;
	cout<<endl;
}

//initialization commands
void Floor::readFloor(SitRep sitrep){
	int i,j;
	char c;

	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			if(sitrep.thing[i][j].what==rock)c=WALL;
			if(sitrep.thing[i][j].what==space)c=EMPTY;
			if(sitrep.thing[i][j].what==unit)c=WALL;
			tile[i][j].fillOnTile(c);
			if(tile[i][j].getOnTile()==TARGET){
				er=i;
				ec=j;

				tile[i][j].fillOnTile(EMPTY);
			
			}
		}
	}
}

bool Floor::localSearch(int r, int c){
	if(tile[r][c].getPath()!=EMPTY)return false;
	if(tile[r][c].getOnTile()!=EMPTY)return false;

	if(r-1>=0  &&tile[r-1][c].getPath()!=EMPTY){tile[r][c].fillPath(UP);return true;}
	if(r+1<ROWS&&tile[r+1][c].getPath()!=EMPTY){tile[r][c].fillPath(DOWN);return true;}
	if(c-1>=0  &&tile[r][c-1].getPath()!=EMPTY){tile[r][c].fillPath(LEFT);return true;}
	if(c+1<COLS&&tile[r][c+1].getPath()!=EMPTY){tile[r][c].fillPath(RIGHT);return true;}

	return false;
}

void Floor::makePath(){
	bool changes = true;
	int i,j;
	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			tile[i][j].fillPath(EMPTY);
		}
	}
	tile[er][ec].fillPath(TARGET);
	//cout<<tile[er][ec].getPath();
	

	while(changes){
		changes=false;
		for(i=0;i<ROWS;++i){
			for(j=0;j<COLS;++j){
				if(localSearch(i,j))changes=true;
			}
		}
		//printPath(); // prints the newly updated path
	}// end while loop
}

void Floor::makeFloorPath(){
	int i,j;

	for(i=0; i<ROWS; i++){
		for(j=0; j<ROWS; j++){
			if(tile[i][j].getPath()!=EMPTY)tile[i][j].fillFloorPath(tile[i][j].getPath());//makes th epath
			if(tile[i][j].getOnTile()==WALL)tile[i][j].fillFloorPath(WALL);//makes the walls
		}
	}
}


Dir yhg::archerCheck(SitRep sitrep){
	Dir aDir=dir;
	int i, j, tr, tc;
	//check for archers
	tr=r;
	tc=c;
	for(i=1; i<4; i++){
		for(j=-1; j<2; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla){
				aDir=up;
				return aDir;
			}
		}
	}//check up for enemy archer
	for(i=1; i<4; i++){
		for(j=-1; j<2; j++){
			if(tr-i>=0&&tr-i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr-i][tc+j].what==unit&&sitrep.thing[tr-i][tc+j].tla!=tla){
				aDir=dn;
				return aDir;
			}
		}
	}//check down for enemy archer
	for(i=-1; i<2; i++){
		for(j=1; j<4; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc-j>=0&&tc-j<COLS&&sitrep.thing[tr+i][tc-j].what==unit&&sitrep.thing[tr+i][tc-j].tla!=tla){
				aDir=lt;
				return aDir;
			}
		}
	}//check left for enemy archer
	for(i=-1; i<2; i++){
		for(j=1; j<4; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla){
				aDir=rt;
				return aDir;
			}
		}
	}//check right for enemy archer
	 //end archer check
	return aDir;
}
bool yhg::dangerCheck(SitRep sitrep){
	bool inDanger=false;
	int i, j, tr, tc;
	//check for archers
	tr=r;
	tc=c;
	for(i=1; i<5; i++){
		for(j=-1; j<2; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==archer){
				inDanger=true;
				return inDanger;
			}
		}
	}//check for enemy archer
	for(i=1; i<5; i++){
		for(j=-1; j<2; j++){
			if(tr-i>=0&&tr-i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr-i][tc+j].what==unit&&sitrep.thing[tr-i][tc+j].tla!=tla&&sitrep.thing[tr-i][tc+j].rank==archer){
				inDanger=true;
				return inDanger;
			}
		}
	}//check for enemy archer
	for(i=-1; i<2; i++){
		for(j=1; j<5; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc-j>=0&&tc-j<COLS&&sitrep.thing[tr+i][tc-j].what==unit&&sitrep.thing[tr+i][tc-j].tla!=tla&&sitrep.thing[tr+i][tc-j].rank==archer){
				inDanger=true;
				return inDanger;
			}
		}
	}//check for enemy archer
	for(i=-1; i<2; i++){
		for(j=1; j<5; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==archer){
				inDanger=true;
				return inDanger;
			}
		}
	}//check for enemy archer
	 //end archer check
	return inDanger;
}
Dir yhg::archerDir(SitRep sitrep){
	Dir aDir=dir;
	int i, j, tr, tc;
	//check for archers
	tr=r;
	tc=c;
	for(i=1; i<5; i++){
		for(j=-1; j<2; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==archer){
				aDir=up;
				aR=i;
				aC=j;
				return aDir;
			}
		}
	}//check up for enemy archer
	for(i=1; i<5; i++){
		for(j=-1; j<2; j++){
			if(tr-i>=0&&tr-i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr-i][tc+j].what==unit&&sitrep.thing[tr-i][tc+j].tla!=tla&&sitrep.thing[tr-i][tc+j].rank==archer){
				aDir=dn;
				aR=i;
				aC=j;
				return aDir;
			}
		}
	}//check down for enemy archer
	for(i=-1; i<2; i++){
		for(j=1; j<5; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc-j>=0&&tc-j<COLS&&sitrep.thing[tr+i][tc-j].what==unit&&sitrep.thing[tr+i][tc-j].tla!=tla&&sitrep.thing[tr+i][tc-j].rank==archer){
				aDir=lt;
				aR=i;
				aC=j;
				return aDir;
			}
		}
	}//check left for enemy archer
	for(i=-1; i<2; i++){
		for(j=1; j<5; j++){
			if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==archer){
				aDir=rt;
				aR=i;
				aC=j;
				return aDir;
			}
		}
	}//check right for enemy archer
	 //end archer check
	return aDir;
}

void yhg::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	int k=0;
	bool placed=false;
	int changed=0;

	if(INFILE=="navy.in"){
	//if in the right side
	if(minR<ROWS/2&&maxR>ROWS/2&&minC>COLS/2){
		int tr, tc;
		int average;
		average=(minR+maxR)/2;
		tc=minC+1;
		tr=average;
		dir=lt;

		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr--;
				if(tr>=minR&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				average++;
				if(average<=maxR&&sitrep.thing[average][tc].what==space){
					r=average;
					c=tc;
					placed=true;
					return;
				}
				k++;
				if(average>maxR&&tr<minR&&changed<2){
					k=0;
					tc++;
					average=(minR+maxR)/2;
					tr=(minR+maxR)/2;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement

		if(rank==archer){
			while(!placed&&k<50){
				if(sitrep.thing[8][18].what==space){r=8;c=18;placed=true;return;}
				if(sitrep.thing[9][18].what==space){r=9;c=18;placed=true;return;}
				if(sitrep.thing[11][18].what==space){r=11;c=18;placed=true;return;}
				if(sitrep.thing[13][18].what==space){r=13;c=18;placed=true;return;}
				if(sitrep.thing[16][18].what==space){r=16;c=18;placed=true;return;}
				if(sitrep.thing[18][18].what==space){r=18;c=18;placed=true;return;}
				if(sitrep.thing[20][18].what==space){r=20;c=18;placed=true;return;}
				if(sitrep.thing[21][18].what==space){r=21;c=18;placed=true;return;}

				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=minC+1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=maxC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}				
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement		

	}//end right side

	//if in the left side
	if(minR<ROWS/2&&maxR>ROWS/2&&maxC<COLS/2){
		int tr, tc;
		int average;
		average=(minR+maxR)/2;
		tc=maxC-1;
		tr=average;
		dir=rt;

		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr--;
				if(tr>=minR&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				average++;
				if(average<=maxR&&sitrep.thing[average][tc].what==space&&average<24){
					r=average;
					c=tc;
					placed=true;
					return;
				}
				k++;
				if(average>maxR&&tr<minR&&changed<2){
					k=0;
					tc--;
					average=(minR+maxR)/2;
					tr=(minR+maxR)/2;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2-1;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2-1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				if(sitrep.thing[8][12].what==space){r=8;c=12;placed=true;return;}
				if(sitrep.thing[9][12].what==space){r=9;c=12;placed=true;return;}
				if(sitrep.thing[11][12].what==space){r=11;c=12;placed=true;return;}
				if(sitrep.thing[13][12].what==space){r=13;c=12;placed=true;return;}
				if(sitrep.thing[16][12].what==space){r=16;c=12;placed=true;return;}
				if(sitrep.thing[18][12].what==space){r=18;c=12;placed=true;return;}
				if(sitrep.thing[20][12].what==space){r=20;c=12;placed=true;return;}
				if(sitrep.thing[21][12].what==space){r=21;c=12;placed=true;return;}
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=maxC-1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=minC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}				
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement	
	}//end left
	}

	if(INFILE=="forts.in"){
	//if in the right side
	if(minR<ROWS/2&&maxR>ROWS/2&&minC>COLS/2){
		int tr, tc;
		int average;
		average=(minR+maxR)/2;
		tc=minC+2;
		tr=average;
		dir=lt;

		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr--;
				if(tr>=minR&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				average++;
				if(average<=maxR&&sitrep.thing[average][tc].what==space){
					r=average;
					c=tc;
					placed=true;
					return;
				}
				k++;
				if(average>maxR&&tr<minR&&changed<2){
					k=0;
					tc++;
					average=(minR+maxR)/2;
					tr=(minR+maxR)/2;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2+2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2+2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement

		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=minC+3;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=maxC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}				
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement		

	}//end right side

		//if in the left side
	if(minR<ROWS/2&&maxR>ROWS/2&&maxC<COLS/2){
		int tr, tc;
		int average;
		average=(minR+maxR)/2;
		tc=maxC-2;
		tr=average;
		dir=rt;

		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr--;
				if(tr>=minR&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				average++;
				if(average<=maxR&&sitrep.thing[average][tc].what==space){
					r=average;
					c=tc;
					placed=true;
					return;
				}
				k++;
				if(average>maxR&&tr<minR&&changed<2){
					k=0;
					tc--;
					average=(minR+maxR)/2;
					tr=(minR+maxR)/2;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2-2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2-2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=maxC-3;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=minC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}				
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement	
	}//end left
	}//end forts placement

	//if in the lower right
	if(minR>ROWS/2&&minC>COLS/2){
		int tr, tc;
		tr=minR;
		tc=minC;
		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					dir=up;
					placed=true;
					return;
				}
				tr++;
				if(tr<=maxR&&sitrep.thing[tr][minC].what==space){
					r=tr;
					c=minC;
					dir=lt;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=minR;
					c=tc;
					dir=up;
					placed=true;
					return;
				}
				k++;
				if(tr>maxR&&tc>maxC&&changed<2){
					k=0;
					tr=minR=minR+1;
					tc=minC=minC+1;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement
		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				dir=up;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc+1;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[startR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				dir=up;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=minC+1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tc=maxC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			dir=up;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement		

	}//end lower right

	//if in the lower left
	if(minR>ROWS/2&&maxC<COLS/2){
		int tr, tc;
		tr=minR;
		tc=maxC;
		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					dir=up;
					placed=true;
					return;
				}
				tr++;
				if(tr<=maxR&&sitrep.thing[tr][maxC].what==space){
					r=tr;
					c=maxC;
					dir=rt;
					placed=true;
					return;
				}
				tc--;
				if(tc>=minC&&sitrep.thing[minR][tc].what==space){
					r=minR;
					c=tc;
					dir=up;
					placed=true;
					return;
				}
				k++;
				if(tr>maxR&&tc<minC&&changed<2){
					k=0;
					tr=minR=minR+1;
					tc=maxC=maxC-1;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(tr>=minR&&tr<=maxR&&tc>=minC&&tc<=maxC&&sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}// end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				dir=up;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(tr<=maxR&&sitrep.thing[tr][minC].what==space){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				dir=up;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=maxC-1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=minC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			dir=up;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement			

	}//end lower left

	//if in the lower middle
	if(minR>ROWS/2&&minC<COLS/2&&maxC>COLS/2){
		int tr, tc;
		int average;
		average=(minC+maxC)/2;
		tc=average;
		tr=minR;
		dir=up;

		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tc--;
				if(sitrep.thing[tr][tc].what==space&&tc>=minC){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				average++;
				if(sitrep.thing[tr][average].what==space&&average<=maxC){
					r=tr;
					c=average;
					placed=true;
					return;
				}
				k++;
				if(average>maxC&&tr<minC&&changed<2){
					k=0;
					tr++;
					average=(minC+maxC)/2;
					tc=(minC+maxC)/2;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(tr<=maxR&&sitrep.thing[tr][minC].what==space){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=minC+1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=maxC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement		

	}//end lower mid

	//if in the upper right
	if(maxR<ROWS/2&&minC>COLS/2){
		int tr, tc;
		tr=maxR;
		tc=minC;
		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					dir=dn;
					placed=true;
					return;
				}
				tr--;
				if(sitrep.thing[tr][minC].what==space&&tr>=minR){
					r=tr;
					c=minC;
					dir=lt;
					placed=true;
					return;
				}
				tc++;
				if(sitrep.thing[maxR][tc].what==space&&tc<=maxC){
					r=maxR;
					c=tc;
					dir=dn;
					placed=true;
					return;
				}
				k++;
				if(tr<minR&&tc>maxC&&changed<2){
					k=0;
					tr=maxR=maxR-1;
					tc=minC=minC+1;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				dir=dn;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(tr<=maxR&&sitrep.thing[tr][minC].what==space){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=minC+1;
					i++;
				}
				dir=dn;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=maxC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			dir=dn;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement			

	}//end upper right

	//if in the upper left
	if(maxR<ROWS/2&&maxC<COLS/2){
		int tr, tc;
		tr=maxR;
		tc=maxC;
		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					dir=dn;
					placed=true;
					return;
				}
				tr--;
				if(sitrep.thing[tr][maxC].what==space&&tr>=minR){
					r=tr;
					c=maxC;
					dir=rt;
					placed=true;
					return;
				}
				tc--;
				if(sitrep.thing[maxR][tc].what==space&&tc>=minC){
					r=maxR;
					c=tc;
					dir=dn;
					placed=true;
					return;
				}
				k++;
				if(tr<minR&&tc<minC&&changed<2){
					k=0;
					tr=maxR=maxR-1;
					tc=maxC=maxC-1;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				dir=dn;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=maxC-1;
					i++;
				}
				dir=dn;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=minC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			dir=dn;
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement		

	}//end upper left

	//if in the upper middle
	if(maxR<ROWS/2&&minC<COLS/2&&maxC>COLS/2){
		int tr, tc;
		int average;
		average=(minC+maxC)/2;
		tc=average;
		tr=maxR;
		dir=dn;

		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tc--;
				if(sitrep.thing[tr][tc].what==space&&tc>=minC){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				average++;
				if(sitrep.thing[tr][average].what==space&&average<=maxC){
					r=tr;
					c=average;
					placed=true;
					return;
				}
				k++;
				if(average>maxC&&tr<minC&&changed<2){
					k=0;
					tr--;
					average=(minC+maxC)/2;
					tc=(minC+maxC)/2;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(sitrep.thing[startR][tc].what==space&&tc<maxC){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=minC+1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=maxC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement			

	}//end upper mid

	//if in the right side
	if(minR<ROWS/2&&maxR>ROWS/2&&minC>COLS/2){
		int tr, tc;
		int average;
		average=(minR+maxR)/2;
		tc=minC;
		tr=average;
		dir=lt;

		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr--;
				if(tr>=minR&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				average++;
				if(average<=maxR&&sitrep.thing[average][tc].what==space){
					r=average;
					c=tc;
					placed=true;
					return;
				}
				k++;
				if(average>maxR&&tr<minR&&changed<2){
					k=0;
					tc++;
					average=(minR+maxR)/2;
					tr=(minR+maxR)/2;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement

		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=minC+1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=maxC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}				
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement		

	}//end right side

	//if in the left side
	if(minR<ROWS/2&&maxR>ROWS/2&&maxC<COLS/2){
		int tr, tc;
		int average;
		average=(minR+maxR)/2;
		tc=maxC;
		tr=average;
		dir=rt;

		if(rank==infantry){
			while(!placed&&k<50){
				if(k==0&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr--;
				if(tr>=minR&&sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				average++;
				if(average<=maxR&&sitrep.thing[average][tc].what==space){
					r=average;
					c=tc;
					placed=true;
					return;
				}
				k++;
				if(average>maxR&&tr<minR&&changed<2){
					k=0;
					tc--;
					average=(minR+maxR)/2;
					tr=(minR+maxR)/2;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					startR=tr=(minR+maxR)/2;
					startC=tc=maxC-1;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}else tc=minC;
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][startC].what==space&&tr<maxR){
					r=tr+k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][startC].what==space&&tr-k>minR){
					r=tr-k;
					c=startC;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc+k].what==space&&tc+k<maxC){
					r=startR;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[startR][tc-k].what==space&&tc-k>minC){
					r=startR;
					c=tc-k;
					placed=true;
					return;
				}				
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement	
	}//end left
	
	//start center
	if(minR<ROWS/2&&maxR>ROWS/2&&minC<COLS/2&&maxC>COLS/2){
		int tr, tc;
		int average;
		average=(minR+maxR)/2;
		tc=maxC;
		tr=average;
		dir=rt;

		if(rank==infantry){
			int x, y;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						tr=y;
						tc=x;
						break;
					}
				}
			}//find crown
			while(!placed&&k<50){
				if(sitrep.thing[tr+infStart][tc+k].what==space){
					r=tr+infStart;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+infStart][tc-k].what==space){
					r=tr+infStart;
					c=tc-k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-infStart][tc+k].what==space){
					r=tr-infStart;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-infStart][tc-k].what==space){
					r=tr-infStart;
					c=tc-k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][tc+infStart].what==space){
					r=tr+k;
					c=tc+infStart;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][tc+infStart].what==space){
					r=tr-k;
					c=tc+infStart;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][tc-infStart].what==space){
					r=tr+k;
					c=tc-infStart;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][tc-infStart].what==space){
					r=tr-k;
					c=tc-infStart;
					placed=true;
					return;
				}
				
				k++;
				if(k>infStart&&changed<2){
					k=0;
					infStart+=1;
					changed++;
				}
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end infantry placement

		if(rank==crown){
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(i==0){
					tr=(minR+maxR)/2;
					tc=(minC+maxC)/2;
					startR=(minR+maxR)/2;
					startC=(minC+maxC)/2;
					i++;
				}
				if(sitrep.thing[tr][tc].what==space){
					r=tr;
					c=tc;
					placed=true;
					return;
				}
				tr++;
				if(sitrep.thing[tr][startC].what==space&&tr<maxR){
					r=tr;
					c=startC;
					placed=true;
					return;
				}
				tc++;
				if(tc<=maxC&&sitrep.thing[minR][tc].what==space){
					r=startR;
					c=tc;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end crown placement
		if(rank==archer){
			int x, y;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						tr=y;
						tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
				int i=0;
				int startR, startC;
				if(sitrep.thing[tr+k][tc].what==space){
					r=tr+k;
					c=tc;
					infStart=k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][tc].what==space){
					r=tr-k;
					c=tc;
					placed=true;
					return;
				}	
				if(sitrep.thing[tr][tc+k].what==space){
					r=tr;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr][tc-k].what==space){
					r=tr;
					c=tc-k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr+k][tc+k].what==space){
					r=tr+k;
					c=tc+k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][tc+k].what==space){
					r=tr-k;
					c=tc+k;
					placed=true;
					return;
				}if(sitrep.thing[tr+k][tc-k].what==space){
					r=tr+k;
					c=tc-k;
					placed=true;
					return;
				}
				if(sitrep.thing[tr-k][tc-k].what==space){
					r=tr-k;
					c=tc-k;
					placed=true;
					return;
				}
				k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end archer placement
		if(rank==knight){
			int x, y, startC, startR;
			for(y=minR;y<=maxR; y++){
				for(x=minC;x<=maxC; x++){
					if(sitrep.thing[y][x].what==unit&&sitrep.thing[y][x].rank==crown&&sitrep.thing[y][x].tla==tla){
						startR=tr=y;
						startC=tc=x;
						break;
					}
				}
			}
			while(!placed&&k<50){
			if(sitrep.thing[startR][tc-1].what==space){
				r=startR;
				c=tc-1;
				return;
			}
			if(sitrep.thing[startR][tc+1].what==space){
				r=startR;
				c=tc+1;
				return;
			}			
			if(sitrep.thing[tr+1][startC].what==space){
				r=tr+1;
				c=startC;
				return;
			}
			if(sitrep.thing[tr-1][startC].what==space){
				r=tr-1;
				c=startC;
				return;
			}		
			if(sitrep.thing[tr-1][tc+1].what==space){
				r=tr-1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc+1].what==space){
				r=tr+1;
				c=tc+1;
				return;
			}
			if(sitrep.thing[tr+1][tc-1].what==space){
				r=tr+1;
				c=tc-1;
				return;
			}
			if(sitrep.thing[tr-1][tc-1].what==space){
				r=tr-1;
				c=tc-1;
				return;
			}
			k++;
			}
			while(!placed){
			tr=minR+rand()%(1+maxR-minR);
			tc=minC+rand()%(1+maxC-minC);
			if(sitrep.thing[tr][tc].what==space)r=tr;c=tc;placed=true;return;
			}
		}//end knight placement	
	}//end center
} //end of placement

// tell someone what you want to do
Action yhg::Recommendation(SitRep sitrep){
	Action a;
	a.action=nothing;

	if (rank==crown){
		cR=r;
		cC=c;
		crownThreat=dangerCheck(sitrep);
		if(crownThreat)threatDir=archerDir(sitrep);
	}
	bool inDanger;	

	if(rank==infantry&&hp<INFANTRYHP&&!inCombat&&sitrep.turnNumber>MAXTURNS*(2/5)){
		inCombat=true;
	}
	if(rank==knight&&hp<KNIGHTHP&&!inCombat&&sitrep.turnNumber>MAXTURNS*(2/5)){
		inCombat=true;
	}
	if(rank==archer&&hp<ARCHERHP&&!inCombat&&sitrep.turnNumber>MAXTURNS*(2/5)){
		inCombat=true;
	}
	if(rank==crown&&hp<CROWNHP&&!inCombat&&sitrep.turnNumber>MAXTURNS*(2/5)){
		inCombat=true;
	}//see if combat has started

	//try to attack in front of you
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
				if(numAttacks>20){
					inCombat=true;
				}
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				numAttacks++;				
				return a;
			}
		}
	}//basic melee attack

	//make sure you're facing the nearest enemy
	if(dir!=sitrep.nearestEnemy.dirFor&&rank!=archer){
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
		}
	//check if you can shoot anyone
	if(rank==archer){
		a.dir=archerCheck(sitrep);
		if(dir!=a.dir&&a.dir!=none){
			a.action=turn;
			return a;
		}
	}

	//start archer attack
	if(rank==archer){
		tr=r;
		tc=c;
		int i, j;
		if(dir==up){
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==crown){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy crown
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==archer){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy archer
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}
		}//attack anyone
		//end up
		if(dir==dn){
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr-i>=0&&tr-i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr-i][tc+j].what==unit&&sitrep.thing[tr-i][tc+j].tla!=tla&&sitrep.thing[tr-i][tc+j].rank==crown){
						a.action=attack;
						a.ar=tr-i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy crown
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr-i>=0&&tr-i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr-i][tc+j].what==unit&&sitrep.thing[tr-i][tc+j].tla!=tla&&sitrep.thing[tr-i][tc+j].rank==archer){
						a.action=attack;
						a.ar=tr-i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy archer
			for(i=1; i<4; i++){
				for(j=-1; j<2; j++){
					if(tr-i>=0&&tr-i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr-i][tc+j].what==unit&&sitrep.thing[tr-i][tc+j].tla!=tla){
						a.action=attack;
						a.ar=tr-i;
						a.ac=tc+j;
						return a;
					}
				}
			}
		}//attack anyone
		//end down
		if(dir==lt){
			for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc-j>=0&&tc-j<COLS&&sitrep.thing[tr+i][tc-j].what==unit&&sitrep.thing[tr+i][tc-j].tla!=tla&&sitrep.thing[tr+i][tc-j].rank==crown){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc-j;
						return a;
					}
				}
			}//check for enemy crown
			for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc-j>=0&&tc-j<COLS&&sitrep.thing[tr+i][tc-j].what==unit&&sitrep.thing[tr+i][tc-j].tla!=tla&&sitrep.thing[tr+i][tc-j].rank==archer){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc-j;
						return a;
					}
				}
			}//check for enemy archer
			for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc-j>=0&&tc-j<COLS&&sitrep.thing[tr+i][tc-j].what==unit&&sitrep.thing[tr+i][tc-j].tla!=tla){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc-j;
						return a;
					}
				}
			}
		}//attack anyone
		//end left
		if(dir==rt){
			for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==crown){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy crown
			for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla&&sitrep.thing[tr+i][tc+j].rank==archer){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}//check for enemy archer
		for(i=-1; i<2; i++){
				for(j=1; j<4; j++){
					if(tr+i>=0&&tr+i<ROWS&&tc+j>=0&&tc+j<COLS&&sitrep.thing[tr+i][tc+j].what==unit&&sitrep.thing[tr+i][tc+j].tla!=tla){
						a.action=attack;
						a.ar=tr+i;
						a.ac=tc+j;
						return a;
					}
				}
			}
		}//attack anyone
		//end right
	}//end archer
	if(rank==crown||rank==knight){
		if(crownThreat){
			if(dir!=threatDir&&threatDir!=none)a.action=turn;a.dir=threatDir;return a;
		}
	}

	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(rank==knight&&crownThreat){
			Floor f;
		f.setEC(aC);
		f.setER(aR);
		f.readFloor(sitrep);
		switch(f.tile[r][c].path){
		case LEFT: 
			if(dir==lt){
				a.action=fwd;
				a.maxDist=2+rand()%HORSESPEED-1;
				return a;
			}else{
			   a.action=turn;
			   a.dir=lt;
			   return a;
			}
			break;
		case RIGHT:
			if(dir==rt){
				a.action=fwd;
				a.maxDist=2+rand()%HORSESPEED-1;
				return a;
			}else{
			   a.action=turn;
			   a.dir=rt;
			   return a;
			}
			break;
		case UP:
			if(dir==up){
				a.action=fwd;
				a.maxDist=2+rand()%HORSESPEED-1;
				return a;
			}else{
			   a.action=turn;
			   a.dir=up;
			   return a;
			}
			break;
		case DOWN:
			if(dir==dn){
				a.action=fwd;
				a.maxDist=2+rand()%HORSESPEED-1;
				return a;
			}else{
			   a.action=turn;
			   a.dir=dn;
			   return a;
			}
			break;

		}
	}
	if(!guarded){
		Floor f;
		f.setEC(cC);
		f.setER(cR);
		f.readFloor(sitrep);
		switch(f.tile[r][c].path){
		case LEFT: 
			if(dir==lt){
				a.action=fwd;
				a.maxDist=2+rand()%HORSESPEED-1;
				return a;
			}else{
			   a.action=turn;
			   a.dir=lt;
			   return a;
			}
			break;
		case RIGHT:
			if(dir==rt){
				a.action=fwd;
				a.maxDist=2+rand()%HORSESPEED-1;
				return a;
			}else{
			   a.action=turn;
			   a.dir=rt;
			   return a;
			}
			break;
		case UP:
			if(dir==up){
				a.action=fwd;
				a.maxDist=2+rand()%HORSESPEED-1;
				return a;
			}else{
			   a.action=turn;
			   a.dir=up;
			   return a;
			}
			break;
		case DOWN:
			if(dir==dn){
				a.action=fwd;
				a.maxDist=2+rand()%HORSESPEED-1;
				return a;
			}else{
			   a.action=turn;
			   a.dir=dn;
			   return a;
			}
			break;

		}
	}
	if(r-1==cR&&c==cC)guarded=true;time=0;
	if(r-1==cR&&c-1==cC)guarded=true;time=0;
	if(r-1==cR&&c+1==cC)guarded=true;time=0;
	if(r+1==cR&&c==cC)guarded=true;time=0;
	if(r+1==cR&&c-1==cC)guarded=true;time=0;
	if(r+1==cR&&c+1==cC)guarded=true;time=0;
	if(r==cR&&c-1==cC)guarded=true;time=0;
	if(r==cR&&c+1==cC)guarded=true;time=0;

	if(r-2==cR&&c==cC)guarded=true;time=0;
	if(r-2==cR&&c-2==cC)guarded=true;time=0;
	if(r-2==cR&&c+2==cC)guarded=true;time=0;
	if(r+2==cR&&c==cC)guarded=true;time=0;
	if(r+2==cR&&c-2==cC)guarded=true;time=0;
	if(r+2==cR&&c+2==cC)guarded=true;time=0;
	if(r==cR&&c-2==cC)guarded=true;time=0;
	if(r==cR&&c+2==cC)guarded=true;time=0;

	if(rank==knight)a.action=nothing; return a;

	if(rank==crown&&crownThreat){
		if(dir!=threatDir)a.action=fwd;a.maxDist=3+rand()%(HORSESPEED-2); return a;
		if(dir==threatDir&&threatDir==dn)a.action=turn;a.dir=up; return a;
		if(dir==threatDir)a.action=turn;a.dir=dn; return a;
	}
	if(rank==crown)a.action=nothing; return a;

	if(!inCombat&&sitrep.turnNumber<(MAXTURNS*3/5)){a.action=nothing; return a;}//if not in combat and turns less than 3/5 over, wait

	if(dir==sitrep.nearestEnemy.dirFor){
			a.action=fwd;
			a.maxDist=1;
			if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
			return a;
		
	}else{
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	
	a.action=nothing;
	return a;
}//end reccomendation