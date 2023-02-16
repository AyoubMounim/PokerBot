
#ifndef RIVER_STATE
#define RIVER_STATE

#include "state.hpp"
#include <map>
#include <string>


class Application;
class AppObject;


class RiverState: public State{
  public:
    RiverState(
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