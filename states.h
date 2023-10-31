#pragma once

#include "state.h"


class paused : public state
{
public:
  static paused* instance()
  {
    static paused instance_;
    return &instance_;
  }
  void enter_() override;
  void handle_event_(const event& e) override;
  void exit_() override;
private:
  paused() : state("PAUSED") {}
};



class gameover : public state
{
public:
  static gameover* instance()
  {
    static gameover instance_;
    return &instance_;
  }
  void enter_() override;
  void handle_event_(const event& e) override;
  void exit_() override;
private:
  gameover() : state("GAMEOVER") {}
};



class exiting : public state
{
public:
  static exiting* instance()
  {
    static exiting instance_;
    return &instance_;
  }
  void enter_() override;
private:
  exiting() : state("EXITING") {}
};



class navigating : public state
{
public:
  static navigating* instance() 
  {
    static navigating instance_;
    return &instance_;
  }
  void enter_() override;
  void handle_event_(const event& e) override;
  void update_() override;
  void hard_drop_();
private:
  void delay_drop_(float interval);
  bool trigger_drop_(float interval);
  navigating() : state("NAVIGATING") {}
  float elapsed_;
  float interval_;
};



class initialising : public state
{
public:
  static initialising* instance()
  {
    static initialising instance_;
    return &instance_; 
  }
  void enter_() override;

private:
  initialising() : state("INITIALISING") {}
};



class new_game : public state
{
public:
  static new_game* instance()
  {
    static new_game instance_;
    return &instance_; 
  }
  void enter_() override;
private:
  new_game() : state("NEW GAME") {}
};



class cementing : public state
{
public:
  static cementing* instance()
  {
    static cementing instance_;
    return &instance_; 
  }
  void enter_() override;
  void exit_() override;
private:
  cementing() : state("CEMENTING") {}
};


class calculating_score : public state
{
public:
  static calculating_score* instance()
  {
    static calculating_score instance_;
    return &instance_;
  }
  void enter_() override;
private:
  calculating_score() : state("CALCULATING SCORE") {}
};


class flashing : public state
{
public:
  static flashing* instance()
  {
    static flashing instance_;
    return &instance_;
  }
  void enter_() override;
  void update_() override;
private:
  bool flash_triggered_(float interval); 
  flashing() : state("FLASHING") {}
  float flash_interval_;
  float elapsed_;
  int flashes_;
};



class shuffling_down : public state
{
public:
  static shuffling_down* instance()
  {
    static shuffling_down instance_;
    return &instance_;
  }
  void enter_() override;
private:
  shuffling_down() : state("SHUFFLING DOWN") {}
};



enum STATEID : int
{
  PREVIOUS = -1,
  INITIALISING = 0,
  NEW_GAME,
  NAVIGATING,
  CEMENTING,
  CALCULATING_SCORE,
  FLASHING,
  SHUFFLING_DOWN,
  PAUSED,
  GAMEOVER,
  EXITING,
  NUM_STATES
};

state* get_state(STATEID s);

