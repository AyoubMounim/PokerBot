
#ifndef FLOP_INPUT_STATE
#define FLOP_INPUT_STATE

#include "game_state.hpp"


class FlopInputState: public GameState{
  public:
    FlopInputState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();
    void resetTableDeck();
    void setTable();
};

#endif