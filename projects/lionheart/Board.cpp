#include "Board.hpp"
#include "Map.hpp"
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

void readMap(Board &board)
{
  auto pMap = lionheart::makeMap(INFILE);
  auto &map = *pMap;
  for (int i = 0; i < ROWS; ++i)
  {
    for (int j = 0; j < COLS; ++j)
    {
      switch (map[map.at(i, j)])
      {
      case lionheart::Tile::SPACE:
        board.things[i][j].what = space;
        board.c[i][j] = '.';
        break;
      case lionheart::Tile::ROCK:
        board.things[i][j].what = rock;
        board.c[i][j] = 'X';
        break;
      }
      board.things[i][j].dir = none;
    }
  }
  auto boxes = map.getBoxes();
  numplayers = boxes.size();
  int i=0;
  for(auto&& box:boxes)
  {
    board.startBox[i].minr = box.minRow;
    board.startBox[i].maxr = box.maxRow;
    board.startBox[i].minc = box.minCol;
    board.startBox[i].maxc = box.maxCol;
    ++i;
  }


}
