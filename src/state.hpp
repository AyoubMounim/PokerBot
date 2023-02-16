
#ifndef STATE
#define STATE

#include "application.hpp"
#include <iostream>
#include <vector>
#include <string>


class State{
  public:
    virtual void update() = 0;
    virtual void handleInput() = 0;

    virtual void render(){
      TheApplication::getInstance()->getRenderer()->renderState(state_id);
      return;
    }
    virtual void onEnter(){
      std::cout << "\nEntering " << state_id << std::endl;
      return;
    } 
    virtual void onExit(){
      std::cout << "\nExiting " << state_id << std::endl;
      return;
    }
  
  protected:
    State(Application *pApplication){mApplication = pApplication;}

    Application *mApplication;
    std::string state_id;
};

#endif