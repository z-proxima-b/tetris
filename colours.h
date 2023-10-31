#pragma once
#include <cstdint>
#include "raylib.h"

enum colours : uint8_t 
{
  HOTPINK=0, NEONGREEN=1, SATSUMA=2, ROSERED=3, INDIGO=4, AQUAMARINE=5, LEMONYELLOW=6, EMPTY=7
}; 

Color int2Colour(uint8_t i);
Color flash_colour();

