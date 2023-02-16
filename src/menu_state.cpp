
#include <iostream>
#include "menu_state.hpp"
#include "pre_flop_state.hpp"


MenuState::MenuState(Application *pApplication)
: State(pApplication){
  state_id = "MENU";
}


void MenuState::onEnter(){
  State::onEnter();
  return;
}


void MenuState::onExit(){
  State::onExit();
  return;
}


void MenuState::update(){
  return;
}


void MenuState::render(){
  State::render();
  return;
}


void MenuState::handleInput(){
  std::string user_input;
  std::cout
    << "\nPress 'n' for new game."
    << "\nPress 'q' for exit." 
    << std::endl;

  std::cin >> user_input;

  if (user_input == "q"){
    onExit();
    TheApplication::getInstance()->setRunning(false);
  }
  else if (user_input == "n"){
    mApplication->changeState(new PreFlopState(mApplication));
  }
  return;
}