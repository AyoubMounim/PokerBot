
#ifndef PRESENTER
#define PRESENTER

#include "model.hpp"
#include "state.hpp"

struct Card;
class Viewer;
class InputReader;


class Presenter{
  public:
    Presenter();

    bool init();
    void handleInput();
    void update();
    void render();

    void setRunning(bool running){mRunning = running;}
    bool getRunning(){return mRunning;}
    void changeState(State *pState);
    Model * getModel(){return mModel;}
    Viewer * getViewer(){return mViewer;}
    InputReader * getInputReader(){return mInputReader;}

    void rateHand(){mModel->rateHand();}
    void rateHandTable(){mModel->rateHandTable();}
    float getRating(){return mModel->getRating();}
  
  private:
    Model *mModel;
    Viewer *mViewer;
    State *mState;
    InputReader *mInputReader;
    bool mRunning;
  
  friend State;
};

#endif