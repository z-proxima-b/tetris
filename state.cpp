#include "state.h"
#include "game.h"

void state::state::do_entry()
{
  enter_();
}


void state::do_exit()
{
  exit_();
}


void state::do_update()
{
  update_();
}


void state::do_handle_event(const event& e)
{
  handle_event_(e);
}


void state::do_draw()
{
  game::instance()->draw(ALL);  
}


