
#include "menu_state.hpp"
#include "presenter.hpp"
#include "draw_state.hpp"


MenuState::MenuState(Presenter *pPresenter)
: State(pPresenter){
  mStateId = "MENU";
}


void MenuState::onEnter(){
  State::onEnter();
  std::cout << "\n ======= " << mStateId << " =======" << std::endl;
  return;
}


void MenuState::onExit(){
  State::onExit();
  return;
}


void MenuState::handleInput(){
  std::string input;
  std::cout << "\nPress 'n' for new game." << std::endl;
  std::cout << "Press 'q' for exit." << std::endl;
  std::cin >> input;

  if (input == "n"){
    mPresenter->changeState(new DrawState(mPresenter));
  }
  else if (input == "q"){
    onExit();
    mPresenter->setRunning(false);
  }
  return;
}


void MenuState::update(){
  return;
}


void MenuState::render(){
  return;
}