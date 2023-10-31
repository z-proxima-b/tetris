#pragma once
#include "gameobject.h"

class lines : public gameobject 
{
  public:
    const float LINES_HEIGHT = 50;
    const float LINES_WIDTH = 125;

    // constructor
    lines();
    // destructor
    ~lines();
    // a helper function to print a text version 
    void print();
    // paint me to screen
    void draw(float x, float y) override;
    // update my state 
    void update() override; 
    // reset me
    void reset() override;
    // adds the given number of lines to total 
    void add_lines(int count);
  private:
    int lines_;
};


