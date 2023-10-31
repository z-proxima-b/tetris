#pragma once

#include "menu.h"
#include "raylib.h"

class exit_menu : public menu
{
  public:
    const char* TITLE = "EXIT THE GAME?";
    const char* YES = "Press Esc to exit";
    const char* NO = "Press SPACE to return to the game";
  protected:
    virtual void drawspecial_(float x, float y) override;
};

