#pragma once
#include "gameobject.h"

class score : public gameobject 
{
  public:
    const int SCORE_PER_LINE = 100;
    const int SCORE_PER_BLOB = 0;
    const float SCORE_HEIGHT = 50;
    const float SCORE_WIDTH = 125;

    // constructor
    score();
    // destructor
    ~score();
    // a helper function to print a text version 
    void print();
    // paint me to screen
    void draw(float x, float y) override;
    // update my state 
    void update() override; 
    // reset me
    void reset() override;
    // adds the given number of lines to the count, and 
    // calculates a new score
    void add_lines(int count);
    // add a blob to the score, calculate a new score
    void add_blob();
  private:
    int score_;
};


