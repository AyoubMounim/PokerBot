
#ifndef TURN_STATE
#define TURN_STATE

#include "state.hpp"
#include <map>
#include <string>


class Application;
class AppObject;


class TurnState: public State{
  public:
    TurnState(
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