
#ifndef MENU_STATE
#define MENU_STATE

#include "state.hpp"


class MenuState: public State{
  public:
    MenuState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void handleInput();
    void update();
    void render();
};

#endif