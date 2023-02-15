
#ifndef FLOP_STATE
#define FLOP_STATE

#include "state.hpp"
#include "application.hpp"
#include <string>
#include <map>


class AppObject;


class FlopState: public State{
  public:
    FlopState(
      Application *pApplication,
      std::map<std::string, AppObject *> objects
    );
    void onEnter();
    void onExit();
    void render();
    void update();
    void handleInput();

  private:
    std::map<std::string, AppObject *> mObjects;
};

#endif