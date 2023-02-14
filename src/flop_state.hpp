
#ifndef FLOP_STATE
#define FLOP_STATE

#include "state.hpp"
#include "application.hpp"
#include <string>
#include <map>


class AppObject;


class FlopState: public State{
  public:
    FlopState(Application *pApplication);
    void onEnter();
    void onExit();
    void update();
    void render();

  private:
    std::map<std::string, AppObject *> mObjects;
};

#endif