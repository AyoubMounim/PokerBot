
#ifndef state
#define state

#include <vector>
#include "app_object.hpp"


class State{
  public:
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void changeState(State *pState) = 0;
  
  protected:
    State(){}

    std::vector<AppObject *> mObjects;    
};

#endif