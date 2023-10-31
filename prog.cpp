#include "machine.h"

int main()
{
  machine& fsm = machine::instance();
  fsm.start(INITIALISING);
  while(fsm.is_running())
  {
    fsm.handle_key();
    fsm.update();
    fsm.draw();

    fsm.transition();
  }
  fsm.stop();
}
