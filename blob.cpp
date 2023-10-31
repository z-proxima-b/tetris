#include <cstring>
#include "blob.h"
#include "colours.h"
#include "screen_positions.h"

blob::blob(blob_type type)
:type_(type)
,column_offset_(0)
,row_offset_(0)
,current_orient_(0) {}


blob::~blob() {}



void blob::draw(float x, float y)
{
  //TraceLog(LOG_DEBUG, "blob origin = 0.2f, 0.2f (offset x = %d, offset y = %d", x, y, column_offset_, row_offset_);
  orientation orient = get_absolute_cells();
  for(auto c : orient.cells)
    DrawRectangle(x + ((c.column)*CELL_W), y + ((c.row)*CELL_W), CELL_FILL_W, CELL_FILL_W, int2Colour(type_));
}



void blob::reset() 
{
  row_offset_ = 0;
  column_offset_ = 0;
  switch(type_)
  {
    case I_BLOB: 
      move(0, 3);
      break;
    case BOX_BLOB:
      move(-1, 3);
    default: 
      move(0, 4);
      break;
  }
  current_orient_ = 0;
}



void blob::move(int row_offset, int column_offset)
{
  row_offset_ += row_offset;
  column_offset_ += column_offset;
}



void blob::rotate()
{
  current_orient_++;
  if(current_orient_ == 4)
    current_orient_ = 0;
}



const orientation blob::get_absolute_cells()
{
  orientation ret;
  for(auto i=0; i < 4; i++)
  {
    ret.cells[i] = {orients[current_orient_].cells[i].row+row_offset_,
                    orients[current_orient_].cells[i].column+column_offset_};
  }
  return ret;
}


void blob::set_cell_data(const orientation data[4])
{
  for(auto i=0; i < 4; i++)
  {
    for(auto c=0; c<4; c++)
    {
      orients[i].cells[c] = data[i].cells[c];
    }
  }
}


blob_type blob::get_type()
{
  return type_;
}
