#pragma once

#include "gameobject.h"
#include "raylib.h"

class menu : public gameobject
{
  public:
    const float MENU_HEIGHT = 175; 
    const float MENU_WIDTH = 370; 
    const float MENU_BORDER_THICKNESS = 4.0; 
    const int MENU_SEGMENTS = 10; 
    const float MENU_ROUNDNESS = 0.2; 

    menu(){}
    ~menu(){}
    void draw(float x, float y) override;
  protected:
    // children can use this to draw any specialised 
    // text or shapes
    virtual void drawspecial_(float x, float y){};
};

