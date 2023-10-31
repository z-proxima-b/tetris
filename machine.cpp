#include "machine.h"
#include "states.h"
#include "raylib.h"
 
machine::machine()
{
  running_ = false;
  SetTraceLogLevel(LOG_DEBUG);
  InitWindow(WIN_WIDTH, WIN_HEIGHT, "Tetris");
  SetTargetFPS(FRAMERATE);
}

machine::~machine() 
{
  CloseWindow();
}

bool machine::is_running()
{
  return (running_);
}

void machine::stop() 
{
  running_ = false;
}

std::string STATENAME(STATEID s)
{
  return get_state(s)->name_;
}



void SETNEXT(STATEID s) 
{
  if(s==PREVIOUS)
    machine::instance().set_next_state(machine::instance().prev_state_);
  else
    machine::instance().set_next_state(get_state(s));
}


void STOP()
{
    machine::instance().stop();
}

void machine::start(STATEID s)
{
  running_ = true;
  current_state_ = get_state(s);
  next_state_ = current_state_;
  current_state_->do_entry();
}


void machine::set_next_state(state* s)
{
  next_state_ = s; 
}


void machine::transition()
{
  if(next_state_ != current_state_)
    machine::instance().set_state(next_state_);
}

void machine::set_state(state* s)
{
  prev_state_ = current_state_;
  current_state_->do_exit();
  current_state_ = s;
  current_state_->do_entry();
}


void machine::handle_key()
{  
  if(WindowShouldClose())
  {
    handle_event(EVENT_QUIT);
    return;
  }
  int keydown = GetKeyPressed();
  switch(keydown)
  {
    case KEY_SPACE:
      handle_event(EVENT_SPACE); 
    break;
    case KEY_LEFT:
      handle_event(EVENT_LEFT);
    break;
    case KEY_RIGHT:
      handle_event(EVENT_RIGHT);
    break;
    case KEY_UP:
      handle_event(EVENT_UP);
    break;
    default:
      break;
  }
}


void machine::set_prev_state()
{
  set_state(prev_state_);
}

void machine::update()
{
  current_state_->do_update();
}


void machine::handle_event(const event& e)
{
  current_state_->do_handle_event(e);
}


void machine::draw()
{
  BeginDrawing();
  ClearBackground(DARKGRAY); 
  current_state_->do_draw();
  EndDrawing();
}


std::string machine::current_state_name()
{
  return current_state_->name_;
}


