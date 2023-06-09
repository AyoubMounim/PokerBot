
#ifndef PRESENTER
#define PRESENTER

#include "model.hpp"
#include "state.hpp"
#include "menu_state.hpp"

struct Card;
class Viewer;
class InputReader;


enum GameMode{
  play,
  assist
};


class Presenter{
  public:
    Presenter();

    bool init();
    void handleInput();
    void update();
    void render();

    void setNumOpponents();

    void setRunning(bool running){mRunning = running;}
    bool getRunning(){return mRunning;}
    void changeState(State *pState);
    Model * getModel(){return mModel;}
    Viewer * getViewer(){return mViewer;}
    InputReader * getInputReader(){return mInputReader;}

    void resetPlayerDeck(){mModel->resetPlayerDeck();}
    void resetTableDeck(){mModel->resetTableDeck();}
    void clearTable(){mModel->clearTable();}
    void goToPreflop();
    void goToPreflopInput();

    void rateHand(std::string stateId);
    float getRating(){return mModel->getRating();}

    void nameHand(){mModel->nameHand();}
    Point * getPoint(){return mModel->getPoint();}

    GameMode getGameMode(){return mGameMode;}

  
  private:
    Model *mModel;
    Viewer *mViewer;
    State *mState;
    InputReader *mInputReader;
    bool mRunning;
    GameMode mGameMode;
  
  friend MenuState;
};

#endif