
#ifndef PREFLOP_STATE
#define PREFLOP_STATE

#include "game_state.hpp"

class Presenter;


class FlopState: public GameState{
  public:
    FlopState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();

    void resetTableDeck();
    void drawPreflop();
};

#endif