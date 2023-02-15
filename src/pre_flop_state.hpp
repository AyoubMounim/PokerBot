
#ifndef PRE_FLOP_STATE
#define PRE_FLOP_STATE

#include "state.hpp"
#include "application.hpp"
#include <map>
#include <string>


class AppObject;


class PreFlopState: public State{
  public:
    PreFlopState(Application *pApplication);
    virtual void onEnter();
    virtual void onExit();
    virtual void render();
    virtual void update();
    virtual void handleInput();
  
  private:
    std::map<std::string, AppObject *> mObjects;
};

#endif