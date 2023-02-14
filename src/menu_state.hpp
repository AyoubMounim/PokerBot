
#ifndef MENU_STATE
#define MENU_STATE

#include "state.hpp"
#include "application.hpp"


class MenuState: public State{
  public:
    MenuState(Application *pApplication);
    virtual void onEnter();
    virtual void onExit();
    virtual void update();
    virtual void render();
};

#endif