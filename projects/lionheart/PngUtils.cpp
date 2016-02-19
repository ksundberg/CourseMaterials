#include "PngUtils.hpp"

void
drawRock(std::vector<std::vector<png_byte>> &data, int top, int left)
{
  //Start at 1 to show grid lines - 0 to hide them
  for(int i = 1;i<lionheart::TILE_HEIGHT;++i)
    for(int j=1;j<lionheart::TILE_WIDTH;++j)
    {
      data[top+i][left+j*3] = 135;
      data[top+i][left+j*3+1] = 113;
      data[top+i][left+j*3+2] = 99;
    }
}

void drawSpace(std::vector<std::vector<png_byte>> &data, int top, int left)
{
  //Start at 1 to show grid lines - 0 to hide them
  for(int i = 1;i<lionheart::TILE_HEIGHT;++i)
    for(int j=1;j<lionheart::TILE_WIDTH;++j)
    {
      data[top+i][left+j*3] = 121;
      data[top+i][left+j*3+1] = 197;
      data[top+i][left+j*3+2] = 0;
    }
}

void drawPixel(std::vector<std::vector<png_byte>>& data,int i,int j,lionheart::Color c)
{
  switch(c)
  {
  case lionheart::Color::OR:
    data[i][j] = 243;
    data[i][j + 1] = 224;
    data[i][j + 2] = 12;
    return;
  case lionheart::Color::ARGENT:
    data[i][j] = 255;
    data[i][j + 1] = 255;
    data[i][j + 2] = 255;
    return;
  case lionheart::Color::GULES:
    data[i][j] = 229;
    data[i][j + 1] = 13;
    data[i][j + 2] = 13;
    return;
  case lionheart::Color::VERT:
    data[i][j] = 27;
    data[i][j + 1] = 204;
    data[i][j + 2] = 27;
    return;
  case lionheart::Color::AZURE:
    data[i][j] = 13;
    data[i][j + 1] = 59;
    data[i][j + 2] = 229;
    return;
  case lionheart::Color::SABLE:
    data[i][j] = 0;
    data[i][j + 1] = 0;
    data[i][j + 2] = 0;
    return;
  }
}

void drawImage(std::vector<std::vector<png_byte>> & data,
                int top,
                int left,
                lionheart::Blazon const & blazon,
                std::vector<std::string> const & image)
{
  for(size_t i =0;i<image.size();++i)
    for(size_t j=0;j<image[0].size();j++)
      if(image[i][j]=='.')
      {
        drawPixel(data,top+i,left+j*3,blazon.primary);
      }
      else
      {
        drawPixel(data,top+i,left+j*3,blazon.secondary);
      }
}

void drawBlazon(std::vector<std::vector<png_byte>>& data,
              int top,
              int left,
              lionheart::Blazon const& blazon)
{
  std::vector<std::string> image;

  switch(blazon.style)
  {
    case lionheart::Style::BEND:
      image = {
        "                 ",
        " ............... ",
        " .          .... ",
        " .         ..... ",
        " .        ...... ",
        " .       .....+. ",
        " .      .....++. ",
        " .     .....+++. ",
        " .    .....++++. ",
        " ..  .....++++.. ",
        "  . .....+++++.  ",
        "  ......+++++..  ",
        "   ....++++++.   ",
        "   ...++++++..   ",
        "    ..+++++..    ",
        "     ..+++..     ",
        "      ..+..      ",
        "       ...       ",
        "                 "};
      break;
    case  lionheart::Style::BEND_SINISTER:
      image = {
      "                 ",
      " ............... ",
      " ....          . ",
      " .....         . ",
      " ......        . ",
      " .+.....       . ",
      " .++.....      . ",
      " .+++.....     . ",
      " .++++.....    . ",
      " ..++++.....  .. ",
      "  .+++++..... .  ",
      "  ..+++++......  ",
      "   .++++++....   ",
      "   ..++++++...   ",
      "    ..+++++..    ",
      "     ..+++..     ",
      "      ..+..      ",
      "       ...       ",
      "                 "};
      break;
    case  lionheart::Style::CHEVERON:
      image = {
      "                 ",
" ............... ",
" ...+++++++++... ",
" ....+++++++.... ",
" .....+++++..... ",
" . ....+++.... . ",
" .  ....+....  . ",
" .   .......   . ",
" .    .....    . ",
" ..    ...    .. ",
"  .     .     .  ",
"  ..         ..  ",
"   .         .   ",
"   ..       ..   ",
"    ..     ..    ",
"     ..   ..     ",
"      .. ..      ",
"       ...       ",
"                 "};
        break;
    case  lionheart::Style::CHIEF:
        image = {
       "                 ",
" ............... ",
" ............... ",
" ............... ",
" ............... ",
" ............... ",
" .             . ",
" .             . ",
" .             . ",
" ..           .. ",
"  .           .  ",
"  ..         ..  ",
"   .         .   ",
"   ..       ..   ",
"    ..     ..    ",
"     ..   ..     ",
"      .. ..      ",
"       ...       ",
"                 "};   
          break;
    case  lionheart::Style::CROSS:
          image = {
        "                 ",
" ............... ",
" .     ...+++++. ",
" .     ...+++++. ",
" .     ...+++++. ",
" ............... ",
" ............... ",
" ............... ",
" ............... ",
" ..++++...    .. ",
"  .++++...    .  ",
"  ..+++...   ..  ",
"   .+++...   .   ",
"   ..++...  ..   ",
"    ..+... ..    ",
"     .......     ",
"      .....      ",
"       ...       ",
"                 "};    
            break;
    case  lionheart::Style::FESS:
            image = {
         "                 ",
" ............... ",
" .+++++++++++++. ",
" .+++++++++++++. ",
" .+++++++++++++. ",
" ............... ",
" ............... ",
" ............... ",
" ............... ",
" ..           .. ",
"  .           .  ",
"  ..         ..  ",
"   .         .   ",
"   ..       ..   ",
"    ..     ..    ",
"     ..   ..     ",
"      .. ..      ",
"       ...       ",
"                 "};     
              break;
    case  lionheart::Style::INVERTED_CHEVERON:
              image = {
          "                 ",
" ............... ",
" .             . ",
" .             . ",
" .             . ",
" .             . ",
" .      .      . ",
" .     ...     . ",
" .    .....    . ",
" ..  .......  .. ",
"  . ....+.... .  ",
"  .....+++.....  ",
"   ...+++++...   ",
"   ..+++++++..   ",
"    ..+++++..    ",
"     ..+++..     ",
"      ..+..      ",
"       ...       ",
"                 "};      
                break;
    case  lionheart::Style::PALE:
                image = {
           "                 ",
" ............... ",
" .     ...+++++. ",
" .     ...+++++. ",
" .     ...+++++. ",
" .     ...+++++. ",
" .     ...+++++. ",
" .     ...+++++. ",
" .     ...+++++. ",
" ..    ...++++.. ",
"  .    ...++++.  ",
"  ..   ...+++..  ",
"   .   ...+++.   ",
"   ..  ...++..   ",
"    .. ...+..    ",
"     .......     ",
"      .....      ",
"       ...       ",
"                 "};       
                  break;
    case  lionheart::Style::PER_BEND:
                  image = {
            "                 ",
" ............... ",
" .            .. ",
" .           ... ",
" .          .... ",
" .         ..... ",
" .        ...... ",
" .       ....... ",
" .      ........ ",
" ..    ......... ",
"  .   .........  ",
"  .. ..........  ",
"   ...........   ",
"   ...........   ",
"    .........    ",
"     .......     ",
"      .....      ",
"       ...       ",
"                 "};        
                    break;
    case  lionheart::Style::PER_BEND_SINISTER:
                    image = {
             "                 ",
" ............... ",
" ..            . ",
" ...           . ",
" ....          . ",
" .....         . ",
" ......        . ",
" .......       . ",
" ........      . ",
" .........    .. ",
"  .........   .  ",
"  .......... ..  ",
"   ...........   ",
"   ...........   ",
"    .........    ",
"     .......     ",
"      .....      ",
"       ...       ",
"                 "};         
                      break;
    case  lionheart::Style::PER_FESS:
                      image = {
              "                 ",
" ............... ",
" .             . ",
" .             . ",
" .             . ",
" .             . ",
" .             . ",
" .             . ",
" ............... ",
" ............... ",
"  .............  ",
"  .............  ",
"   ...........   ",
"   ...........   ",
"    .........    ",
"     .......     ",
"      .....      ",
"       ...       ",
"                 "};          
                        break;
    case  lionheart::Style::PER_PALE:
                        image = {
               "                 ",
" ............... ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" ..     ........ ",
"  .     .......  ",
"  ..    .......  ",
"   .    ......   ",
"   ..   ......   ",
"    ..  .....    ",
"     .. ....     ",
"      .....      ",
"       ...       ",
"                 "};           
                          break;
    case  lionheart::Style::QUARTERLY:
                          image = {
                "                 ",
" ............... ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" .      ........ ",
" ............... ",
" ........     .. ",
"  .......     .  ",
"  .......    ..  ",
"   ......    .   ",
"   ......   ..   ",
"    .....  ..    ",
"     .... ..     ",
"      .....      ",
"       ...       ",
"                 "};            
                            break;
    case  lionheart::Style::SALTIRE:
                            image = {
                 "                 ",
" ............... ",
" ...         ... ",
" ....       .... ",
" .+...     ...+. ",
" .++...   ...++. ",
" .+++... ...+++. ",
" .++++.....++++. ",
" .+++++...+++++. ",
" ..+++.....+++.. ",
"  .++... ...++.  ",
"  .....   .....  ",
"   ...     ...   ",
"   ..       ..   ",
"    ..     ..    ",
"     ..   ..     ",
"      .. ..      ",
"       ...       ",
"                 "};             
                              break;

  }
  drawImage(data,top,left,blazon,image);
}

void drawFacing(std::vector<std::vector<png_byte>> & data,
                int top,
                int left,
                lionheart::Blazon const & blazon,
                lionheart::Direction d)
{

  std::vector<std::string> image;
  switch(d)
  {
    case lionheart::Direction::NORTH:
      image = {
        "                 ",
        "                 ",
        "        .        ",
        "       ...       ",
        "      .....      ",
        "     .......     ",
        "    .........    ",
        "   ...........   ",
        "  ...  ...  ...  ",
        " ..    ...    .. ",
        "       ...       ",
        "       ...       ",
        "                 "};
      break;
    case lionheart::Direction::SOUTH:
      image = {
        "                 ",
        "       ...       ",
        "       ...       ",
        " ..    ...    .. ",
        "  ...  ...  ...  ",
        "   ...........   ",
        "    .........    ",
        "     .......     ",
        "      .....      ",
        "       ...       ",
        "        .        ",
        "                 ",
        "                 "};
      break;
    case lionheart::Direction::EAST:
      image = {
        "                 ",
        "          .      ",
        "          ..     ",
        "          ...    ",
        "          ....   ",
        "   ............  ",
        "   ............. ",
        "   ............  ",
        "          ....   ",
        "          ...    ",
        "          ..     ",
        "          .      ",
        "                 "};
      break;
    case lionheart::Direction::WEST:
      image = {
        "                 ",
        "      .          ",
        "     ..          ",
        "    ...          ",
        "   ....          ",
        "  .............  ",
        " ..............  ",
        "  .............  ",
        "   ....          ",
        "    ...          ",
        "     ..          ",
        "      .          ",
        "                 "};
      break;
    default:break;
  }
  drawImage(data,top,left,blazon,image);
}

void drawInfantry(std::vector<std::vector<png_byte>> & data,
                int top,
                int left,
                int hp,
                lionheart::Blazon const & blazon)
{
  std::vector<std::string> image;
  switch(hp)
  {
    case 4:
image = {
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"   ...    ...   ",
"  .....  .....  ",
"  .....  .....  ",
"  .....  .....  ",
"   ...    ...   ",
"                ",
"                ",
"   ...    ...   ",
"  .....  .....  ",
"  .....  .....  ",
"  .....  .....  ",
"   ...    ...   ",
"                ",
"                "};
break;
    case 3:
image = {
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"   ...          ",
"  .....         ",
"  .....         ",
"  .....         ",
"   ...          ",
"                ",
"                ",
"   ...    ...   ",
"  .....  .....  ",
"  .....  .....  ",
"  .....  .....  ",
"   ...    ...   ",
"                ",
"                "};
break;
    case 2:
image = {
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"   ...          ",
"  .....         ",
"  .....         ",
"  .....         ",
"   ...          ",
"                ",
"                ",
"          ...   ",
"         .....  ",
"         .....  ",
"         .....  ",
"          ...   ",
"                ",
"                "
};
break;
    case 1:
image = {
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"          ...   ",
"         .....  ",
"         .....  ",
"         .....  ",
"          ...   ",
"                ",
"                "
};
break;
    default:
image = {
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               "};
break;






  }
  drawImage(data,top,left,blazon,image);
}


void drawArcher(std::vector<std::vector<png_byte>> & data,
                int top,
                int left,
                int hp,
                lionheart::Blazon const & blazon)
{
  std::vector<std::string> image;
  switch(hp)
  {
    case 4:
image = {
"               ",
"    .     .    ",
"    .     .    ",
"   ...   ...   ",
"   ...   ...   ",
"  ..... .....  ",
"  . . . . . .  ",
"    .     .    ",
"    .     .    ",
"    .     .    ",
"   ...   ...   ",
"    .     .    ",
"   ...   ...   ",
"   . .   . .   ",
"   . .   . .   ",
"               ",
"    .     .    ",
"    .     .    ",
"   ...   ...   ",
"   ...   ...   ",
"  ..... .....  ",
"  . . . . . .  ",
"    .     .    ",
"    .     .    ",
"    .     .    ",
"   ...   ...   ",
"    .     .    ",
"   ...   ...   ",
"   . .   . .   ",
"   . .   . .   ",
"               ",
"               "};
break;
    case 3:
image = {
"               ",
"    .          ",
"    .          ",
"   ...         ",
"   ...         ",
"  .....        ",
"  . . .        ",
"    .          ",
"    .          ",
"    .          ",
"   ...         ",
"    .          ",
"   ...         ",
"   . .         ",
"   . .         ",
"               ",
"    .     .    ",
"    .     .    ",
"   ...   ...   ",
"   ...   ...   ",
"  ..... .....  ",
"  . . . . . .  ",
"    .     .    ",
"    .     .    ",
"    .     .    ",
"   ...   ...   ",
"    .     .    ",
"   ...   ...   ",
"   . .   . .   ",
"   . .   . .   ",
"               ",
"               "};
break;
    case 2:
image = {
"               ",
"    .          ",
"    .          ",
"   ...         ",
"   ...         ",
"  .....        ",
"  . . .        ",
"    .          ",
"    .          ",
"    .          ",
"   ...         ",
"    .          ",
"   ...         ",
"   . .         ",
"   . .         ",
"               ",
"          .    ",
"          .    ",
"         ...   ",
"         ...   ",
"        .....  ",
"        . . .  ",
"          .    ",
"          .    ",
"          .    ",
"         ...   ",
"          .    ",
"         ...   ",
"         . .   ",
"         . .   ",
"               ",
"               "};
break;
    case 1:
image = {
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"          .    ",
"          .    ",
"         ...   ",
"         ...   ",
"        .....  ",
"        . . .  ",
"          .    ",
"          .    ",
"          .    ",
"         ...   ",
"          .    ",
"         ...   ",
"         . .   ",
"         . .   ",
"               ",
"               "};
break;
    default:
image = {
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               "};
break;






  }
  drawImage(data,top,left,blazon,image);
}

void drawKnight(std::vector<std::vector<png_byte>> & data,
                int top,
                int left,
                int hp,
                lionheart::Blazon const & blazon)
{
  std::vector<std::string> image;
  switch(hp)
  {
    case 2:
image = {
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"   ..........   ",
"  ............  ",
"  ............  ",
"  ............  ",
"  ............  ",
"  ............  ",
"   ..........   ",
"                ",
"                ",
"                ",
"   ..........   ",
"  ............  ",
"  ............  ",
"  ............  ",
"  ............  ",
"  ............  ",
"   ..........   ",
"                "};
break;
    case 1:
image = {

"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"   ..........   ",
"  ............  ",
"  ............  ",
"  ............  ",
"  ............  ",
"  ............  ",
"   ..........   ",
"                "};
break;
    default:
image = {
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               "};
break;






  }
  drawImage(data,top,left,blazon,image);
}

void drawCrown(std::vector<std::vector<png_byte>> & data,
                int top,
                int left,
                int hp,
                lionheart::Blazon const & blazon)
{
  std::vector<std::string> image;
  switch(hp)
  {
    case 1:
image = {
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"       ...      ",
"      .....     ",
"      .....     ",
"      .....     ",
"       ...      ",
"   ...  .  ...  ",
"  ..... . ..... ",
"  ..... . ..... ",
"  ..... . ..... ",
"   ...  .  ...  ",
"   ..  ...  ..  ",
"   ... ... ...  ",
"   ...........  ",
"   ...........  ",
"   ...........  ",
"   ...........  ",
"     .......    ",
"       ...      ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                "};
break;
    default:
image = {
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               ",
"               "};
break;
  }
  drawImage(data,top,left,blazon,image);
}


void drawHealth(std::vector<std::vector<png_byte>> & data,
                int top,
                int left,
                lionheart::SituationReport::Thing const & thing,
                lionheart::Blazon const & blazon)
{
  switch(thing.unit)
  {
    case lionheart::UnitType::ARCHER:
      drawArcher(data,top,left,thing.hp,blazon);
      break;
    case lionheart::UnitType::INFANTRY:
      drawInfantry(data,top,left,thing.hp,blazon);
      break;
    case lionheart::UnitType::KNIGHT:
      drawKnight(data,top,left,thing.hp,blazon);
      break;
    case lionheart::UnitType::CROWN:
      drawCrown(data,top,left,thing.hp,blazon);
      break;

    default:break;
  }
}

void drawUnit(std::vector<std::vector<png_byte>> &data,
                                     int top,
                                     int left,
                                     lionheart::SituationReport::
                                         Thing const & thing,
                                     lionheart::Blazon const &blazon)
{
  drawBlazon(data,top,left,blazon);
  drawFacing(data,top+19,left,blazon,thing.direction);
  drawHealth(data,top,left+17*3,thing,blazon);
}

void lionheart::drawThing(std::vector<std::vector<png_byte>>& data,
              int top,
              int left,
              lionheart::SituationReport::Thing const& thing,
              lionheart::Blazon const& ally,
              lionheart::Blazon const& enemy)
{
    switch (thing.type)
    {
    case lionheart::SituationReport::ROCK:
      drawRock(data,top,left);
      break;
    case lionheart::SituationReport::SPACE:
      drawSpace(data,top,left);
      break;
    case lionheart::SituationReport::ALLY:
      drawUnit(data,top,left,thing, ally);
      break;
    case lionheart::SituationReport::ENEMY:
      drawUnit(data,top,left,thing, enemy);
      break;
    }
}
