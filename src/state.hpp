
#ifndef STATE
#define STATE

#include "application.hpp"
#include <vector>
#include <string>


class State{
  public:
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void update() = 0;
    virtual void handleInput() = 0;

    virtual void render(){
      TheApplication::getInstance()->getRenderer()->renderState(state_id);
      return;
    }
  
  protected:
    State(Application *pApplication){mApplication = pApplication;}

    Application *mApplication;
    std::string state_id;
};

#endif