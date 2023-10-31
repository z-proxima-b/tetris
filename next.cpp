#include "next.h"
#include "screen_positions.h"
#include "colours.h"
#include "raylib.h"

next::next()
{
  reset();
}

next::~next()
{}

void next::print()
{
  TraceLog(LOG_DEBUG, "NEXT = %d", static_cast<uint8_t>(blb_.get_type()));
}

void next::draw(float x, float y)
{
  DrawText("next: ", x, y-27, 24, LIGHTGRAY);       

  // draw a 4 x 2 background grid
  for(auto r = 0; r < 2; r++)
  {
    for(auto c = 0; c < 4; c++)
    {
      DrawRectangle(x + 25 + (c*CELL_W), y + 25 + (r*CELL_W),
                             CELL_FILL_W, CELL_FILL_W, int2Colour(EMPTY));
    }
  }
  blb_.draw(x,y);
}

void next::update(){} 


void next::reset()
{
}

void next::set(const blob& blb)
{
  blb_ = blb;
  switch(blb_.get_type())
  {
    case S_BLOB:
    case T_BLOB:
    case Z_BLOB:
      blb_.move(1,1);
      break;
    case I_BLOB:
      blb_.rotate();
      blb_.move(1,1);
      break;
    case BOX_BLOB:
      blb_.move(0,1);
      break;
    case L_BLOB:
      blb_.rotate();
      blb_.rotate();
      blb_.rotate();
      blb_.move(0,1);
      break;
    case R_BLOB:
      blb_.rotate();
      blb_.move(1,1);
      break;
    default:
      break;
  }
}


blob next::get()
{
  return blb_;
}
