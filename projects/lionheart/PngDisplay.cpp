#include "PngDisplay.hpp"
#include "PngUtils.hpp"

#include <png.h>
#include <cstdio>



std::vector<std::vector<png_byte>>
drawReport(lionheart::SituationReport const &report,
           lionheart::Blazon const & p1,
           lionheart::Blazon const & p2)

{
  //Allocate adequate data
  std::vector<std::vector<png_byte>> data(report.things.size()*lionheart::TILE_HEIGHT);
  for(auto&& row:data)
  {
    row.resize(report.things[0].size()*lionheart::TILE_WIDTH*3);
  }
  for(size_t i=0;i<report.things.size();++i)
    for(size_t j=0;j<report.things[i].size();++j)
    {
      lionheart::drawThing(data,i*lionheart::TILE_HEIGHT,j*lionheart::TILE_WIDTH*3,report.things[i][j],p1,p2);
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
  auto filename = output + "turn" + std::to_string(report.turns) + ".png";
  fp = fopen(filename.c_str(),"wb");
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
