#include "state.h"

void state::do_entry()
{
  gameobjects::clear_all();
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
  handle_event_();
}


void state::do_draw()
{
  gameobjects::draw_all();
}

