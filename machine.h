#pragma once

#include "board.h"
#include "states.h"

const int WIN_WIDTH = 450;
const int WIN_HEIGHT = 550;
const int FRAMERATE = 60;

class machine
{

public:
  // constructor
  machine();

  // destructor
  ~machine(); 

  static machine& instance()
  {
    static machine instance_;
    return instance_;
  }

  // Initialise the starting state.
  // Open the app window and kick off the machine.
  void start(STATEID state);
  
  // Stop the machine (close the app window)
  void stop();

  // Return true if the game is running.
  // False otherwise.
  bool is_running();

  // Set the state to the given state
  void set_state(state* s);

  // Set the next state to the given state.
  // NB. Does not perform any state transition.
  void set_next_state(state* s);

  // Set the state to the previous state
  void set_prev_state();

  // Translates the latest key press and into an event
  void handle_key();

  // Handle the given event in the current state
  void handle_event(const event& e);

  // Calls the update function of the current state.
  void update();

  // Paint all the game objects to screen 
  void draw();

  // Transition to the currently stored "next state"
  void transition();

  // Return the current state name
  std::string current_state_name();

  state* current_state_;
  state* next_state_;
  state* prev_state_;
  bool running_;
};

// helpers
void SETNEXT(STATEID s);
void STOP();
std::string STATENAME(STATEID s);




