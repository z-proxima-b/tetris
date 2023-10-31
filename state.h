#pragma once
#include "event.h"
#include <string>
#include "raylib.h"

class state
{
public:
  state(const char* name)
    :name_(name){}

  void do_entry();
  void do_exit();
  void do_update();
  void do_handle_event(const event& e);
  void do_draw();

  std::string name_;

protected:
  virtual void enter_(){}
  virtual void exit_(){ } 
  virtual void update_(){ }
  virtual void handle_event_(const event& e){ TraceLog(LOG_DEBUG, "%s: default", __FUNCTION__);}  
  virtual void draw_(){ } 

};

