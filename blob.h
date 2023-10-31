#pragma once
#include <cstdint>
#include "gameobject.h"
#include "coordinate.h"

enum blob_type : uint8_t
{
  S_BLOB = 0,
  T_BLOB,
  Z_BLOB,
  I_BLOB,
  BOX_BLOB,
  L_BLOB,
  R_BLOB,
  NUM_BLOBS,
  NO_BLOB = NUM_BLOBS
};

class blob : public gameobject
{
 public:
    // constructor and destructor
    blob(blob_type type = NO_BLOB);
    ~blob();
    // paint me to screen
    void draw(float x, float y) override;
    // reset me to my start values
    void reset() override; 
    // add the given offsets to my relative coordinates
    void move(int row_offset, int column_offset);
    // rotate my current cells, by 90 degrees anti-clockwise
    void rotate();
   // set the relative (to 0,0) board coordinates that I fill 
    void set_cell_data(const orientation orients[4]);
    // return the absolute board coordinates that I fill
    // at my particular orientation, given my row and col offsets
    const orientation get_absolute_cells();
     // Return my type
    blob_type get_type();
 protected:
    blob_type type_;
    int column_offset_;
    int row_offset_;
    int current_orient_;
    orientation orients[4];
};

