#pragma once
#include "gameobject.h"
#include "coordinate.h"
#include <cstdint>

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

enum FlashType : int
{
  OFF = 0, 
  ON = 1
};

class board : public gameobject 
{
  public:
    // constructor and destructor
    board();
    ~board();
    // initialise the board, ready for a new game.
    void initialise();
    // a helper function to print a text version of the board.
    void print();
    // paint me to screen
    void draw(float x, float y) override;
    // update my state 
    void update() override; 
    // reset me
    void reset() override;
    // fill 4 cells with the given value
    void fill(const orientation& data, uint8_t value);
    // Return true if my cell at the given coordinate is filled or
    // is outside my walls. 
    bool is_collision_here(const coordinate& c);
    // Reset internals ready to search for completed rows
    void init_calculation();
    // find a "chunk" of completed rows 
    int find_completed_rows();
    // switch flashing rows ON or OFF (according to given FlashType)
    void flash(FlashType f);
    // Shuffle down all the rows into the gaps
    // left after removing the completed rows.
    void shuffle_everything_down();

private: 
    // fill my cell with the given value 
    void fill_(const coordinate c, uint8_t value);
    // Helper function to return the index of the row
    // to begin searching for completed rows from.
    int get_next_sentinel_pos_();
    // Return true if the given row is completed. False otherwise.
    bool is_row_completed_(int which);
    // Return true if the given row (index) is within 
    // the current chunk of completed rows. 
    bool within_completed_chunk_(int r);

    uint8_t cells_[BOARD_WIDTH*BOARD_HEIGHT];
    int first_;
    int count_;
    int next_sentinel_;
    bool flashing_;
};


