#pragma once

#include "menu.h"
#include "raylib.h"

class gameover_menu : public menu
{
  public:
    const char* TITLE = "GAME OVER!";
    const char* YES = "Press SPACE to play again";
    const char* NO = "Press Esc to exit";
  protected:
    virtual void drawspecial_(float x, float y) override;
};

