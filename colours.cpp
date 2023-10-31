#include "colours.h"

const Color hotpink = {255,69,181,255};
const Color neongreen = {124,243,160,255};
const Color satsuma = {255,69,0,255};
const Color rosered = {245,23,32,255};
const Color indigo = {0,0,200,255};
const Color aquamarine = {47,243,224,255};
const Color lemonyellow = {254,222,0,255};
const Color empty = {133, 133, 133, 255 };
const Color flashing = {255, 255, 255, 0 };

const Color COLOURS[8] = {hotpink, neongreen, satsuma, rosered, indigo, aquamarine, lemonyellow, empty}; 

Color int2Colour(uint8_t i)
{
  return COLOURS[i%8]; 
}

Color flash_colour()
{
  return flashing;
}
