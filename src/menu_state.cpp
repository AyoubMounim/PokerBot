
#include "menu_state.hpp"
#include "presenter.hpp"
#include "preflop_state.hpp"
#include "preflop_input_state.hpp"


MenuState::MenuState(Presenter *pPresenter)
: State(pPresenter){
  mStateId = "MENU";
}


void MenuState::onEnter(){
  // State::onEnter();
  std::cout << "\n ======= " << mStateId << " =======" << std::endl;
  return;
}


void MenuState::onExit(){
  // State::onExit();
  return;
}


void MenuState::handleInput(){
  std::string input;
  std::cout << "\nPress 'p' for play mode.";
  std::cout << "\nPress 'a' for assist mode.";
  std::cout << "\nPress 'q' for exit." << std::endl;
  std::cin >> input;

  if (input == "p"){
    mPresenter->resetPlayerDeck();
    mPresenter->resetTableDeck();
    mPresenter->changeState(new PreflopState(mPresenter));
  }
  else if (input == "a"){
    mPresenter->resetPlayerDeck();
    mPresenter->resetTableDeck();
    mPresenter->changeState(new PreflopInputState(mPresenter));
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