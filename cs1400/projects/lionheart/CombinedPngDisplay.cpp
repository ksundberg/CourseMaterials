#include "CombinedPngDisplay.hpp"
#include "PngUtils.hpp"

#include <png.h>
#include <cstdio>

namespace
{
void drawReport(std::vector<std::vector<png_byte>> data,
                int top,
                int left,
                lionheart::SituationReport const &report,
                lionheart::Blazon const &p1,
                lionheart::Blazon const &p2)

{
  for(size_t i=0;i<report.things.size();++i)
    for(size_t j=0;j<report.things[i].size();++j)
    {
      lionheart::drawThing(data,
                           i * lionheart::TILE_HEIGHT + top,
                           j * lionheart::TILE_WIDTH * 3 + left,
                           report.things[i][j],
                           p1,
                           p2);
    }
}

std::vector<std::vector<png_byte>>
drawFrame(std::array<std::vector<lionheart::Frame>::iterator, 4> const &games)

{
  std::vector<std::vector<png_byte>> data(games[0]->report.things.size() * 2 *
                                          lionheart::TILE_HEIGHT);
  for (auto &&row : data)
  {
    row.resize(games[0]->report.things[0].size() * 2 * lionheart::TILE_WIDTH *
               3);
  }
  drawReport(data, 0, 0, games[0]->report, games[0]->p1, games[0]->p2);
  drawReport(data,
             0,
             games[0]->report.things.size(),
             games[1]->report,
             games[1]->p1,
             games[1]->p2);
  drawReport(data,
             games[0]->report.things[0].size() * 3,
             0,
             games[2]->report,
             games[2]->p1,
             games[2]->p2);
  drawReport(data,
             games[0]->report.things[0].size() * 3,
             games[0]->report.things.size(),
             games[3]->report,
             games[3]->p1,
             games[3]->p2);

  return data;
}

}

void lionheart::CombinedPngDisplay::show(lionheart::SituationReport const& report, Blazon const& p1, Blazon const& p2)
{
  frames[output].push_back({report,p1,p2});
}

void lionheart::CombinedPngDisplay::writeFrames()
{
  //@TODO the static here is to make the longjump later happy
  static int slideNumber = 0;
  auto cur = frames.begin();
  std::array<std::vector<Frame>::iterator,4> games;
  std::array<std::vector<Frame>::iterator,4> ends;
  for(int i=0;i<4;++i)
  {
  games[i] = cur->second.begin();
  ends[i] = cur->second.end();
  ++cur;
  }

  while ((cur != frames.end()) && (games[0] != ends[0]) &&
         (games[1] != ends[1]) && (games[2] != ends[2]) &&
         (games[3] != ends[3]))
  {

    ++slideNumber;
    auto data = drawFrame(games);
    for (int i = 0; i < 4; ++i)
    {
      if (games[i] == ends[i])
      {
        games[i] = cur->second.begin();
        ends[i] = cur->second.end();
        ++cur;
      }
    }
    FILE *fp = nullptr;
    png_structp png_ptr = nullptr;
    png_infop info_ptr = nullptr;
    auto filename = std::string("combined_frame") + std::to_string(slideNumber) + ".png";
    fp = fopen(filename.c_str(), "wb");
    png_ptr = png_create_write_struct(
        PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    info_ptr = png_create_info_struct(png_ptr);
    if (setjmp(png_jmpbuf(png_ptr)))
    {
      goto finalize;
    }
    png_init_io(png_ptr, fp);
    png_set_IHDR(png_ptr,
                 info_ptr,
                 data[0].size() / 3,
                 data.size(),
                 8,
                 PNG_COLOR_TYPE_RGB,
                 PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE,
                 PNG_FILTER_TYPE_BASE);
    png_write_info(png_ptr, info_ptr);

    for (auto &&row : data)
    {
      png_write_row(png_ptr, row.data());
    }

    png_write_end(png_ptr, nullptr);
  finalize:
    fclose(fp);
    png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
    png_destroy_write_struct(&png_ptr, nullptr);
  }
}
