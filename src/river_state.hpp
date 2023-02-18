
#ifndef RIVER_STATE
#define RIVER_STATE

#include "game_state.hpp"


class RiverState: public GameState{
  public:
    RiverState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();

    void drawRiver();
};

#endif