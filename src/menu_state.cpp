
#include <iostream>
#include "menu_state.hpp"


MenuState::MenuState()
: State(){
  onEnter();
}


void MenuState::onEnter(){
  std::cout << "\nEntering menu state." << std::endl;
  return;
}


void MenuState::onExit(){
  std::cout << "Exiting menu state." << std::endl;
  return;
}


void MenuState::update(){
  std::string user_input;
  std::cout << "\nPress 'q' for exit." << std::endl;
  std::cin >> user_input;

  if (user_input == "q"){
    onExit();
    TheApplication::getInstance()->setRunning(false);
  }
  return;
  return;
}


void MenuState::render(){
  return;
}


void MenuState::changeState(State *pState){
  return;
}
