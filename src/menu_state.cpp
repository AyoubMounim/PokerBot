
#include <iostream>
#include "menu_state.hpp"
#include "pre_flop_state.hpp"


MenuState::MenuState(Application *pApplication)
: State(){
  mApplication = pApplication;
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
    onExit();
    changeState(new PreFlopState(mApplication));
  }
  return;
}


void MenuState::render(){
  return;
}


void MenuState::changeState(State *pState){
  mApplication->setState(pState);
  return;
}
