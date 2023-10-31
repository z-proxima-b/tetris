#pragma once
#include "board.h"
#include "blob.h"
#include "next.h"
#include "score.h"
#include "lines.h"
#include "exit_menu.h"
#include "gameover_menu.h"
  
enum GAMEOBJECT : int 
{
  BOARD = 0,
  BLOB = 1,
  NEXT = 2,
  SCORE = 3,
  LINES = 4,
  EXIT_MENU = 5,
  GAMEOVER_MENU = 6,
  NUM_OBJECTS,
  ALL = NUM_OBJECTS  
};

class game
{
public:

  // Constructor
  game();
  // Destructor
  ~game();

  static game* instance()
  {
    static game instance_;
    return &instance_;
  }

  // Marks the given game object as "in play", so updateable, and 
  // drawable. ALL marks everything as in play.
  void show(GAMEOBJECT id);  

  // Clears the given object from being "in play"
  // ALL clears everything.
  void hide(GAMEOBJECT id);

  // Updates the given object.
  // ALL updates everything marked "in play".
  void update(GAMEOBJECT id);

  // Draws the given object.
  // ALL draws everything marked "in play".
  void draw(GAMEOBJECT id);

  // Reset the given object. 
  void reset(GAMEOBJECT id);

  // Try to move the blob left, without collision  
  void move_left();

  // Try to move the blob right, without collision  
  void move_right();

  // Return true if blob can move down, without collision.  
  // Return false otherwise. 
  bool move_down();

  // Try to rotate the blob, once anti-clockwise, without collision
  void rotate();

  // Generate a new random blob, and place it at the 
  // top of the board.
  // Return true if no collision. False otherwise.
  bool respawn();

  // Fix the blob to the grid in its current position. 
  void cement(); 

  // Clear all variables for calculating and 
  // animating the score 
  void clear_scoring();

  // Return true if a chunk of completed rows was found. 
  // False otherwise.
  bool get_next_chunk_of_rows_completed();

  // Flash the completed rows
  void flash();

  // shuffle down all the rows into the gap created by removing 
  // completed rows.
  void shuffle_down();

  // add the latest lines scored to the total score
  void add_score();
private:
  // clear the "in play" array, set all to nullptr. 
  void clear_objects_in_play_();
  // set up the object pointers 
  void set_up_object_ptrs_();
  // return a random blob  
  blob get_random_blob_();
  // Return true any of the given coordinates are outside 
  // the grid, or are filled in the grid.
  bool collision_(const orientation& cells);
  board brd_;
  blob blb_;
  next nxt_;
  score sco_;
  lines lin_;
  exit_menu emenu_;
  gameover_menu gomenu_;
  gameobject* objects_in_play[NUM_OBJECTS];
  gameobject* object_ptrs[NUM_OBJECTS];
  Vector2 pos[NUM_OBJECTS];

  int chosen;
  int blob_choice[7];
  int flash_duration_;
  bool flash_rows_;
};
