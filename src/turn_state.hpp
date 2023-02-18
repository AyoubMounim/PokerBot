
#ifndef TURN_STATE
#define TURN_STATE

#include "game_state.hpp"


class TurnState: public GameState{
  public:
    TurnState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();

    void drawTurn();
};

#endif