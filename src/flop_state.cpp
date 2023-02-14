
#include "flop_state.hpp"
#include "app_object.hpp"
#include <iostream>


FlopState::FlopState(Application *pApplication)
: State(pApplication){}


void FlopState::onEnter(){
  std::cout << "Entering flop state." << std::endl;
  return;
}


void FlopState::onExit(){
  std::cout << "Exiting flop state." << std::endl;
  return;
}


void FlopState::update(){}


void FlopState::render(){}
