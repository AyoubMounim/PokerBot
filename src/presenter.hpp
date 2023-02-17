
#ifndef PRESENTER
#define PRESENTER

#include "model.hpp"
#include "state.hpp"

struct Card;
class Viewer;


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
  
  private:
    Model *mModel;
    Viewer *mViewer;
    State *mState;
    bool mRunning;
};

#endif