#pragma once

// -------------------------------------------------------------
// A game object is a drawable object.
// It must define how to draw itself to the canvas instance().
// ------------------------------------------------------------- 
class gameobject 
{
  public:
    // reset me to my start values 
    virtual void reset(){}; 
    // draw me to the screen at the given x,y pos 
    virtual void draw(float x, float y){};
    // update my state 
    virtual void update(){}; 
};
