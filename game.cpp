#include <cstring>
#include "game.h"
#include "colours.h"
#include "raylib.h"
#include "blob_factory.h"
#include "screen_positions.h"

game::game()
:chosen(0)
,flash_rows_(true)
{
  clear_objects_in_play_();
  set_up_object_ptrs_();
  std::memset(blob_choice, 0xff, sizeof(int)*7); 
  nxt_.set(get_random_blob_());
}

game::~game()
{

}

void game::clear_objects_in_play_()
{
  std::memset(objects_in_play, 0, NUM_OBJECTS*sizeof(gameobject*));
}


void game::set_up_object_ptrs_()
{
  // ----------------------------------------
  object_ptrs[BOARD] = &brd_; 
  pos[BOARD] = {BOARD_TOPLEFT_X, BOARD_TOPLEFT_Y};
  // ----------------------------------------
  object_ptrs[BLOB] = &blb_; 
  pos[BLOB] = {BOARD_TOPLEFT_X, BOARD_TOPLEFT_Y};
  // ----------------------------------------
  object_ptrs[EXIT_MENU] = &emenu_;
  pos[EXIT_MENU] = {MENU_TOPLEFT_X, MENU_TOPLEFT_Y};
  // ----------------------------------------
  object_ptrs[GAMEOVER_MENU] = &gomenu_;
  pos[GAMEOVER_MENU] = {MENU_TOPLEFT_X, MENU_TOPLEFT_Y};
  // ----------------------------------------
  object_ptrs[NEXT] = &nxt_; 
  pos[NEXT] = {NEXT_TOPLEFT_X, NEXT_TOPLEFT_Y};
  // ----------------------------------------
  object_ptrs[SCORE] = &sco_;
  pos[SCORE] = {SCORE_TOPLEFT_X, SCORE_TOPLEFT_Y};
  // ----------------------------------------
  object_ptrs[LINES] = &lin_;
  pos[LINES] = {LINES_TOPLEFT_X, LINES_TOPLEFT_Y};
}

blob game::get_random_blob_()
{
  if(chosen==7)
  {
    std::memset(blob_choice, 0xff, sizeof(int)*7); 
    chosen = 0;
  } 

  int random = 0;
  do
  {
    // keep choosing until blob_choice[random] is a zero
    random = GetRandomValue(0,6);
  } while(blob_choice[random]==0);  

  // mark as chosen
  chosen++;    
  blob_choice[random] = 0;
  return make_blob(static_cast<blob_type>(random));
}

void game::show(GAMEOBJECT id)  
{
  objects_in_play[id] = object_ptrs[id];
}


void game::hide(GAMEOBJECT id)
{
  objects_in_play[id] = nullptr;
}



void game::move_left()
{
  blob trial = blb_;
  trial.move(0,-1);
  if(collision_(trial.get_absolute_cells()) == false)
    blb_ = trial;
}



void game::move_right()
{
  blob trial = blb_;
  trial.move(0,1);
  if(collision_(trial.get_absolute_cells()) == false)
    blb_ = trial;
}



bool game::move_down()
{
  blob trial = blb_;
  trial.move(1,0);
  if(collision_(trial.get_absolute_cells()))
    return false;
   
  blb_ = trial;
  return true;
}



void game::rotate()
{
  blob trial = blb_;
  trial.rotate();
  if(collision_(trial.get_absolute_cells()) == false)
    blb_ = trial;
}



bool game::collision_(const orientation& cells)
{
  for(auto c = 0; c < 4; c++)
  {
    if(brd_.is_collision_here(cells.cells[c]))
      return true;
  }
  return false;
}



bool game::respawn()
{
  blb_ = nxt_.get();
  blb_.reset();
  nxt_.set(get_random_blob_());

  if(collision_(blb_.get_absolute_cells()))
  {
    TraceLog(LOG_DEBUG, "Collision on respawn!!");
    return false;
  }
  return true;
}



void game::cement() 
{
  brd_.fill(blb_.get_absolute_cells(), static_cast<uint8_t>(blb_.get_type()));
  sco_.add_blob();
}



void game::update(GAMEOBJECT id)
{
  if(id==ALL)
  {
    for(auto gameobject : objects_in_play) 
    {
      if(gameobject != nullptr)
        gameobject->update();    
    }
  }
  else
  {
    objects_in_play[id]->update();
  }
}


void game::draw(GAMEOBJECT id)
{
  if(id==ALL)
  {
    for(auto i=0; i<NUM_OBJECTS; i++)
    {
      if(objects_in_play[i] != nullptr)
      {
        objects_in_play[i]->draw(pos[i].x, pos[i].y);
      }
    }
  }
  else
  {
    objects_in_play[id]->draw(pos[id].x, pos[id].y);
  }
}

void game::reset(GAMEOBJECT id)
{
  if(id==ALL)
  {
    // reset all objects, regardless of whether marked "in play"
    for(auto gameobject : object_ptrs) 
    {
        gameobject->reset();    
    }
  }
  else
  {
    TraceLog(LOG_DEBUG, "0x%x, objects_in_play[%d]",objects_in_play[id], id); 
    objects_in_play[id]->reset();
  }
}


bool game::get_next_chunk_of_rows_completed()
{
  int lines_found = brd_.find_completed_rows(); 
  sco_.add_lines(lines_found);
  lin_.add_lines(lines_found);
  return (lines_found > 0);
}

void game::clear_scoring()
{
  brd_.init_calculation();
}



void game::flash()
{
  if(flash_rows_==false)
  {
    flash_rows_ = true;
    brd_.flash(ON);
  }
  else
  {
    flash_rows_ = false;
    brd_.flash(OFF);
  }
}

void game::shuffle_down()
{
  brd_.shuffle_everything_down();
}

