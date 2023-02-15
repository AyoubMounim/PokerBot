
#ifndef STATE
#define STATE

#include <vector>
#include "app_object.hpp"


class Application;


class State{
  public:
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void handleInput() = 0;
  
  protected:
    State(Application *pApplication){mApplication = pApplication;}

    Application *mApplication;
};

#endif