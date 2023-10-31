#include "states.h"
#include "machine.h"
#include "raylib.h"
#include "game.h"

void initialising::enter_()
{
  SETNEXT(NEW_GAME);
}


void new_game::enter_() 
{
  // reset all objects, regardless of whether visible 
  game::instance()->reset(ALL);
  SETNEXT(NAVIGATING);
}


void navigating::enter_()
{
  interval_ = 0.2;
  elapsed_ = 0;
  game::instance()->show(BOARD);
  game::instance()->show(BLOB);
  game::instance()->show(NEXT);
  game::instance()->show(SCORE);
  game::instance()->show(LINES);
  handle_event_(EVENT_DO_RESPAWN);
}


void navigating::update_() 
{
  if(trigger_drop_(interval_))
    handle_event_(EVENT_DOWN);
}


void navigating::handle_event_(const event& e) 
{
  switch(e)
  {
    case EVENT_QUIT:
      SETNEXT(PAUSED);
      break;
    case EVENT_LEFT:
      game::instance()->move_left();
      delay_drop_(0.2);
      break;
    case EVENT_RIGHT:
      game::instance()->move_right();
      delay_drop_(0.2);
      break;
    case EVENT_DOWN:
      if(false==game::instance()->move_down())
        SETNEXT(CEMENTING);
      break;
    case EVENT_UP:
      game::instance()->rotate();
      delay_drop_(0.2);
      break;
    case EVENT_SPACE:
      hard_drop_();
      break;
    case EVENT_DO_RESPAWN:
      if(false==game::instance()->respawn())
        SETNEXT(GAMEOVER);
      break;
    default:
      TraceLog(LOG_DEBUG, "Unknown Event %d", e);
      break;
  }
}

void navigating::delay_drop_(float interval)
{
  elapsed_ -= interval;
}

bool navigating::trigger_drop_(float interval)
{
  elapsed_ += GetFrameTime();
  if(elapsed_ > interval)
  {
    elapsed_ = 0;
    return true;
  }
  return false;
}

void cementing::enter_()
{
  game::instance()->cement();
  game::instance()->hide(BLOB);
  SETNEXT(CALCULATING_SCORE);
}



void cementing::exit_()
{
  game::instance()->clear_scoring();
}



void navigating::hard_drop_()
{
  interval_ = 0.001;
}


void paused::enter_()
{
  game::instance()->show(BOARD);
  game::instance()->show(EXIT_MENU);
}



void paused::handle_event_(const event& e)  
{
  switch(e)
  {
    case EVENT_SPACE:
      SETNEXT(PREVIOUS); 
      break;
    case EVENT_QUIT:
      SETNEXT(EXITING);
      break;
    default:
      break;
  }
}



void paused::exit_()
{
  game::instance()->hide(EXIT_MENU);
}



void exiting::enter_()
{
  STOP();
}

void gameover::enter_()
{
  game::instance()->show(BOARD);
  game::instance()->show(SCORE);
  game::instance()->show(GAMEOVER_MENU);
}

void gameover::handle_event_(const event& e)
{
  switch(e)
  {
    case EVENT_SPACE:
      SETNEXT(NEW_GAME); 
      break;
    case EVENT_QUIT:
      SETNEXT(EXITING);
      break;
    default:
      break;
  }
}

void gameover::exit_()
{
  game::instance()->hide(GAMEOVER_MENU);
}


void calculating_score::enter_()
{
  if(game::instance()->get_next_chunk_of_rows_completed())
    SETNEXT(FLASHING);
  else
  { 
    SETNEXT(NAVIGATING);
  }
}

void flashing::enter_()
{
  flash_interval_ = 0.05;
  elapsed_ = 0;
  flashes_ = 10;
}

void flashing::update_()
{
  if(flashes_== 0)
    SETNEXT(SHUFFLING_DOWN);
  else
  {
    if(flash_triggered_(flash_interval_))
    {
      game::instance()->flash();
      flashes_--;
    }
  }
}

bool flashing::flash_triggered_(float interval)
{
  elapsed_ += GetFrameTime();
  if(elapsed_ > interval)
  {
    elapsed_ = 0;
    return true;
  }
  return false;
}


void shuffling_down::enter_()
{
  game::instance()->shuffle_down();
  SETNEXT(CALCULATING_SCORE);
}



state* get_state(STATEID s)
{
  state* the_states[NUM_STATES] =  
  {
    initialising::instance(),
    new_game::instance(),
    navigating::instance(),
    cementing::instance(),
    calculating_score::instance(),
    flashing::instance(),
    shuffling_down::instance(), 
    paused::instance(),
    gameover::instance(),
    exiting::instance()
  };
 
  return the_states[s];  
}



