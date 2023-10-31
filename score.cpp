#include "score.h"
#include "colours.h"
#include "screen_positions.h"
#include "raylib.h"

score::score()
{
  reset();
}

score::~score()
{}

void score::print()
{
  TraceLog(LOG_DEBUG, "SCORE = %d", score_);
}

void score::draw(float x, float y)
{
  DrawText("score: ", x, y-27, 24, LIGHTGRAY);       
  int length = MeasureText(TextFormat("%d", score_), 24);
  DrawText(TextFormat("%d", score_),x+SCORE_WIDTH-length, y+(SCORE_HEIGHT/2)-12, 24, LIGHTGRAY);       
}

void score::update()
{

} 

void score::reset()
{
  score_ = 0;
}

void score::add_lines(int lines)
{
  int add = lines * SCORE_PER_LINE;
  TraceLog(LOG_DEBUG, "add: %d", add);
  score_ += add;
}

void score::add_blob()
{
  score_ += SCORE_PER_BLOB;
}
