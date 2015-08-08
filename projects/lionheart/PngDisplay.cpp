#include "PngDisplay.hpp"

#include <png.h>
#include <cstdio>

//resources
/*
#include "resources/archer-full.xpm"
#include "resources/archer-3.xpm"
#include "resources/archer-2.xpm"
#include "resources/archer-1.xpm"
*/

namespace
{
  const int TILE_HEIGHT = 32;
  const int TILE_WIDTH = 32;
}

void
drawRock(std::vector<std::vector<png_byte>> &data, int top, int left)
{
  //Start at 1 to show grid lines - 0 to hide them
  for(int i = 1;i<TILE_HEIGHT;++i)
    for(int j=1;j<TILE_WIDTH;++j)
    {
      data[top+i][left+j*3] = 135;
      data[top+i][left+j*3+1] = 113;
      data[top+i][left+j*3+2] = 99;
    }
}

void drawSpace(std::vector<std::vector<png_byte>> &data, int top, int left)
{
  //Start at 1 to show grid lines - 0 to hide them
  for(int i = 1;i<TILE_HEIGHT;++i)
    for(int j=1;j<TILE_WIDTH;++j)
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
        " .       ..... . ",
        " .      .....  . ",
        " .     .....   . ",
        " .    .....    . ",
        " ..  .....    .. ",
        "  . .....     .  ",
        "  ......     ..  ",
        "   ....      .   ",
        "   ...      ..   ",
        "    ..     ..    ",
        "     ..   ..     ",
        "      .. ..      ",
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
      " . .....       . ",
      " .  .....      . ",
      " .   .....     . ",
      " .    .....    . ",
      " ..    .....  .. ",
      "  .     ..... .  ",
      "  ..     ......  ",
      "   .      ....   ",
      "   ..      ...   ",
      "    ..     ..    ",
      "     ..   ..     ",
      "      .. ..      ",
      "       ...       ",
      "                 "};
      break;
    case  lionheart::Style::CHEVERON:
      image = {
      "                 ",
" ............... ",
" ...         ... ",
" ....       .... ",
" .....     ..... ",
" . ....   .... . ",
" .  .... ....  . ",
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
" .     ...     . ",
" .     ...     . ",
" .     ...     . ",
" ............... ",
" ............... ",
" ............... ",
" ............... ",
" ..    ...    .. ",
"  .    ...    .  ",
"  ..   ...   ..  ",
"   .   ...   .   ",
"   ..  ...  ..   ",
"    .. ... ..    ",
"     .......     ",
"      .....      ",
"       ...       ",
"                 "};    
            break;
    case  lionheart::Style::FESS:
            image = {
         "                 ",
" ............... ",
" .             . ",
" .             . ",
" .             . ",
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
"  . .... .... .  ",
"  .....   .....  ",
"   ...     ...   ",
"   ..       ..   ",
"    ..     ..    ",
"     ..   ..     ",
"      .. ..      ",
"       ...       ",
"                 "};      
                break;
    case  lionheart::Style::PALE:
                image = {
           "                 ",
" ............... ",
" .     ...     . ",
" .     ...     . ",
" .     ...     . ",
" .     ...     . ",
" .     ...     . ",
" .     ...     . ",
" .     ...     . ",
" ..    ...    .. ",
"  .    ...    .  ",
"  ..   ...   ..  ",
"   .   ...   .   ",
"   ..  ...  ..   ",
"    .. ... ..    ",
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
" . ...     ... . ",
" .  ...   ...  . ",
" .   ... ...   . ",
" .    .....    . ",
" .     ...     . ",
" ..   .....   .. ",
"  .  ... ...  .  ",
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

void drawThing(std::vector<std::vector<png_byte>>& data,
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
std::vector<std::vector<png_byte>>
drawReport(lionheart::SituationReport const &report,
           lionheart::Blazon const & p1,
           lionheart::Blazon const & p2)

{
  //Allocate adequate data
  std::vector<std::vector<png_byte>> data(report.things.size()*TILE_HEIGHT);
  for(auto&& row:data)
  {
    row.resize(report.things[0].size()*TILE_WIDTH*3);
  }
  for(size_t i=0;i<report.things.size();++i)
    for(size_t j=0;j<report.things[i].size();++j)
    {
      drawThing(data,i*TILE_HEIGHT,j*TILE_WIDTH*3,report.things[i][j],p1,p2);
    }

  return data;
}

void lionheart::PngDisplay::show(lionheart::SituationReport const& report, Blazon const& p1, Blazon const& p2)
{
  if (report.things.empty()) return;
  FILE * fp = nullptr;
  png_structp png_ptr = nullptr;
  png_infop info_ptr = nullptr;
  auto data = drawReport(report,p1,p2);
  fp = fopen("test.png","wb");
  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,nullptr,nullptr,nullptr);
  info_ptr = png_create_info_struct(png_ptr);
  if(setjmp(png_jmpbuf(png_ptr)))
  {
    goto finalize;
  }
  png_init_io(png_ptr,fp);
  png_set_IHDR(png_ptr,
               info_ptr,
               data[0].size()/3,
               data.size(),
               8,
               PNG_COLOR_TYPE_RGB,
               PNG_INTERLACE_NONE,
               PNG_COMPRESSION_TYPE_BASE,
               PNG_FILTER_TYPE_BASE);
  png_write_info(png_ptr,info_ptr);

  for(auto&& row:data)
  {
    png_write_row(png_ptr,row.data());
  }
  
  png_write_end(png_ptr,nullptr);
finalize:
  fclose(fp);
  png_free_data(png_ptr,info_ptr,PNG_FREE_ALL,-1);
  png_destroy_write_struct(&png_ptr,nullptr);
}
