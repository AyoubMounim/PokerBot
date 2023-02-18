
#ifndef PREFLOP_STATE
#define PREFLOP_STATE

#include "game_state.hpp"

class Presenter;


class PreflopState: public GameState{
  public:
    PreflopState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();

    void resetTableDeck();
    void drawPreflop();
};

#endif