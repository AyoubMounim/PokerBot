
#ifndef PRE_FLOP_STATE
#define PRE_FLOP_STATE

#include "state.hpp"
#include "application.hpp"


class PreFlopState: public State{
  public:
    PreFlopState(Application *pApplication);
    virtual void onEnter();
    virtual void onExit();
    virtual void update();
    virtual void render();
    virtual void changeState(State *pState);

  private:
    Application *mApplication;
};

#endif