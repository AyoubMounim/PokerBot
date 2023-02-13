
#ifndef APPLICATION
#define APPLICATION

#include "renderer.hpp"
#include "console_renderer.hpp"
#include "state.hpp"


class Application{
  public:
    void initialize();
    static Application * getInstance();
    void update();
    void render();

    void setRunning(bool is_running){mRunning = is_running;}
    bool getRunning(){return mRunning;}
    void setRenderer(Renderer *pRenderer){mRenderer = pRenderer;}
    Renderer * getRenderer(){return mRenderer;}
    void setState(State *pState){mState = pState;}
    
  private:
    Application(){}

    bool mRunning;
    static Application *sInstance;
    Renderer *mRenderer;
    State *mState;
};

typedef Application TheApplication;

#endif