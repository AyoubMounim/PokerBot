
#ifndef TURN_INPUT_STATE
#define TURN_INPUT_STATE

#include "game_state.hpp"


class TurnInputState: public GameState{
  public:
    TurnInputState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();
    void setTurn();
};

#endif
