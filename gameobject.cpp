#include "gameobject.h"
#include "canvas.h"

gameobject::gameobject(float screenx, 
                       float screeny,
                       float width,
                       float height,
                       const Color& colour)
:x_(screenx)
,y_(screeny)
,w_(width)
,h_(height)
,col_(colour)
{
  rec = Rectangle{x_,y_,w_,h_};
}

void gameobject::draw()
{
  canvas::instance().draw_rectangle(rec_,col_);
}

void gameobject::set_color(const Color& col)
{
  col_ = col;
}

void gameobject::set_xy(const float x, const float y)
{
  x_ = x;
  y_ = y;
  rec = Rectangle{x_,y_,w_,h_};
}


