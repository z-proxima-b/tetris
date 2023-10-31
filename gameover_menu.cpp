#include "gameover_menu.h"
#include "raylib.h"


void gameover_menu::drawspecial_(float x, float y)
{
  int length_title = MeasureText(TITLE, 24);  
  float title_x = x + (MENU_WIDTH/2) - (length_title/2);
  float title_y = y + 25;
  DrawText(TITLE, title_x, title_y, 24, DARKBLUE); 

  int length_yes = MeasureText(YES, 16);  
  float yes_x = x + (MENU_WIDTH/2) - (length_yes/2);
  float yes_y = title_y + 50;
  DrawText(YES, yes_x, yes_y, 16, DARKBLUE);

  int length_no = MeasureText(NO, 16);  
  float no_x = x + (MENU_WIDTH/2) - (length_no/2);
  float no_y = title_y + 100;
  DrawText(NO, no_x, no_y, 16, DARKBLUE);
}




