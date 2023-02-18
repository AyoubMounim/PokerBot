
#ifndef DRAW_STATE
#define DRAW_STATE

#include "game_state.hpp"

class Presenter;


class DrawState: public GameState{
  public:
    DrawState(Presenter *pPresenter);
    void onEnter();
    void onExit();
    void update();
    void render();
    void resetPlayerDeck();
    void drawHand();
    Hand * getHand();
};

#endif