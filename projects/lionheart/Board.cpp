#include "Board.hpp"
#include "lionheart2.h"
#include <fstream>
#include <iostream>
#include <cmath>

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

void readMap(Board& board){
	int i,j,rows,cols;
  std::ifstream  fin;
	fin.open(INFILE);
	if (fin.fail()){
    std::cout << "error opening file: check to make sure the map file is in the same\n";
    std::cout << "directory as the executable.  exiting.\n";
		exit(3);
	}
	fin>>rows;
	fin>>cols;
	fin>>numplayers;
	if(rows!=ROWS || cols!=COLS){
    std::cout << "error reading map: ROW/COL mismatch with #define in unit.h.  exiting.\n";
		exit(1);
	}
	if(numplayers>4){
    std::cout << "error reading map: max 4 players (more requested).  exiting.\n";
		exit(2);
	}
	if(NUM%numplayers!=0){
    std::cout << "error reading map: total number of units can't be evenly divided.  exiting.\n";
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
	//std::cout << std::endl;
	}
	fin.close();
}
