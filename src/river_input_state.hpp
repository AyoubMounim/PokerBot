
#ifndef RIVER_INPUT_STATE
#define RIVER_INPUT_STATE

#include "game_state.hpp"


class RiverInputState: public GameState{
  public:
    RiverInputState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();
    void setRiver();
};

#endif