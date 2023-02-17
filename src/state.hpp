
#ifndef STATE
#define STATE

#include <string>
#include <iostream>

class Presenter;


class State{
  public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual void onEnter(){
      std::cout << "\nEntering " << mStateId << " state." << std::endl;
      return;
    }
    virtual void onExit(){
      std::cout << "\nExiting " << mStateId << " state."<< std::endl;
      return;
    }

  protected:
    State(Presenter *pPresenter){mPresenter = pPresenter;}

    std::string mStateId;
    Presenter *mPresenter;
};

#endif