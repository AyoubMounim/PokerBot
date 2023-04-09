
#ifndef PREFLOP_INPUT_STATE
#define PREFLOP_INPUT_STATE

#include "game_state.hpp"


class PreflopInputState: public GameState{
  public:
    PreflopInputState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();
    void resetPlayerDeck();
    void resetTableDeck();
    void setHand();
};

#endif