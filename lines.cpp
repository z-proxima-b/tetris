#include "lines.h"
#include "screen_positions.h"
#include "colours.h"
#include "raylib.h"

lines::lines()
{
  reset();
}

lines::~lines()
{}

void lines::print()
{
  TraceLog(LOG_DEBUG, "LINES = %d", lines_);
}

void lines::draw(float x, float y)
{
  DrawText("lines: ", x, y-27, 24, LIGHTGRAY);       
  int length = MeasureText(TextFormat("%d", lines_), 24);
  DrawText(TextFormat("%d", lines_),x+LINES_WIDTH-length, y+(LINES_HEIGHT/2)-12, 24, LIGHTGRAY);       
}

void lines::update()
{

} 

void lines::reset()
{
  lines_ = 0;
}

void lines::add_lines(int lines)
{
  lines_ += lines;
}
