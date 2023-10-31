#include <cstring>
#include <iostream>
#include "board.h"
#include "screen_positions.h"
#include "colours.h"
#include "raylib.h"

board::board(){}
board::~board(){}

void board::reset()
{
  std::memset(cells_, static_cast<uint8_t>(EMPTY), (BOARD_WIDTH*BOARD_HEIGHT));
  flashing_ = false;
}

void board::print()
{
  for(auto r = 0; r < BOARD_HEIGHT; r++)
  {
    for(auto c = 0; c < BOARD_WIDTH; c++)
    {
      std::cout << cells_[r*(BOARD_WIDTH)+BOARD_WIDTH] <<", ";
    }
    std::cout << std::endl;
  }
}

void board::draw(float x, float y)
{
  for(auto r = 0; r < BOARD_HEIGHT; r++)
  {
    for(auto c = 0; c < BOARD_WIDTH; c++)
    { 
      Color colour; 
      if(flashing_ && within_completed_chunk_(r))
        colour = flash_colour();
      else
        colour = int2Colour(cells_[r*(BOARD_WIDTH)+c]);

      DrawRectangle(x + (c*CELL_W), y + (r*CELL_W), CELL_FILL_W, CELL_FILL_W, colour);
    }
  }
}

bool board::within_completed_chunk_(int r)
{
  return (r > first_-count_ && r <= first_);
}

void board::fill_(const coordinate c, uint8_t value)
{
  cells_[(c.row*BOARD_WIDTH) + c.column] = value;
}


void board::fill(const orientation& data, uint8_t value)
{
  for(auto i = 0; i < 4; i++)
    fill_(data.cells[i], value);
}

bool board::is_collision_here(const coordinate& c)
{
  if(c.row < 0 || c.row >= BOARD_HEIGHT)
    return true;
  if(c.column < 0 || c.column >= BOARD_WIDTH) 
    return true;
  if(cells_[(c.row*BOARD_WIDTH) + c.column] != EMPTY) 
    return true;

  // otherwise
  return false;
}


bool board::is_row_completed_(int which)
{
  bool completed = true;
  int cell = BOARD_WIDTH*which;
  for(auto i = 0; i < BOARD_WIDTH; i++)
  {
    if(cells_[cell+i]==EMPTY)
    {
      completed = false; 
      break;
    }
  }
  return completed;
}




void board::init_calculation()
{
  first_ = 19;
  count_ = 0;
  next_sentinel_ = 19;
  flashing_ = false;
}


int board::get_next_sentinel_pos_()
{
  return next_sentinel_;
}

int board::find_completed_rows()
{
  count_ = 0;
  int sentinel = get_next_sentinel_pos_();
  TraceLog(LOG_DEBUG, "next sentinel = %d", next_sentinel_);
  // starting from sentinel, find a completed row
  bool found = false;
  while(sentinel >= 0) 
  {
    if(is_row_completed_(sentinel))
    {
      TraceLog(LOG_DEBUG, "row complete = %d", sentinel);
      if(found==false)
      {
        found = true; 
        // mark this as the first completed row of a chunk of completed rows
        first_ = sentinel;
      }
      // keep a count for consecutive completed rows
      count_++;
    }
    else 
    {
      // if we have previously found a completed row, 
      // and we've now found one that is non-complete,
      // then we must now stop counting. 
      if(found)
      {
        next_sentinel_ = first_-count_;
        break;
      }
    }
    sentinel--;
  }
  return count_;
}


void board::shuffle_everything_down()
{
  int start = get_next_sentinel_pos_();
  for(auto i = start; i >= 0; i--)
  {
    int src  = (i*BOARD_WIDTH);
    int dest = src+(count_*BOARD_WIDTH);
    for(auto c = 0; c < BOARD_WIDTH; c++)
    {
      cells_[dest+c] = cells_[src+c]; 
    }
  }
}


void board::flash(FlashType f)
{
  switch(f)
  {
    case ON:
      flashing_ = true;
      break;
    case OFF:
    default:
      flashing_ = false;
      break;
  }
}


void board::update() 
{

}


