
#ifndef GAME_STATE
#define GAME_STATE

#include "state.hpp"
#include "presenter.hpp"
#include "menu_state.hpp"
#include <iostream>


class GameState: public State{
  public:
    virtual void handleInput(){
      std::string input;
      std::cout << "\nPress 'n' to go to next phase." << std::endl;
      std::cout << "Press 'q' to go to main menu." << std::endl;
      std::cin >> input;

      if (input == "n"){
        if (mNextState == nullptr){
          std::cout << "\nNo next state to go to. Going to menu." << std::endl;
          mPresenter->changeState(new MenuState(mPresenter));
        }
        else{
          mPresenter->changeState(mNextState);
        }
      }
      else if (input == "q"){
        mPresenter->changeState(new MenuState(mPresenter));
      }
      return;
    }
    virtual void onEnter(){
      std::cout << "\n======= " << mStateId << " =======" << std::endl;
      return;
    }
    virtual void update(){}
    virtual void render(){}

  protected:
    GameState(Presenter *pPresenter)
    : State(pPresenter){}

    State *mNextState;
};

#endif