#pragma once
#include "gameobject.h"
#include "blob.h"
#include <cstdint> 

class next : public gameobject 
{
  public:
    const float NEXT_HEIGHT = 100;
    const float NEXT_WIDTH = 150;

     // constructor
    next();
    // destructor
    ~next();
    // a helper function to print a text version 
    void print();
    // paint me to screen
    void draw(float x, float y) override;
    // update my state 
    void update() override; 
    // reset me
    void reset() override;
    // set me to a particular blob 
    void set(const blob& blb);
    // return my blob value
    blob get();
  private:
    blob blb_;
};


