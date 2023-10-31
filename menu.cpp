#include "menu.h"
#include "raylib.h"

void menu::draw(float x, float y)
{
  float roundness = MENU_ROUNDNESS;
  int segments = MENU_SEGMENTS;
  float thickness = MENU_BORDER_THICKNESS;
  
  DrawRectangleRoundedLines({x, y, MENU_WIDTH, MENU_HEIGHT}, roundness, segments, thickness, DARKBLUE); 
  DrawRectangleRounded({x, y, MENU_WIDTH, MENU_HEIGHT}, roundness, segments, RAYWHITE); 
  
  // draw any objects defined by children  
  drawspecial_(x, y);
}


