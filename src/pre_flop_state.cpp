
#include "pre_flop_state.hpp"
#include <iostream>


PreFlopState::PreFlopState(Application *pApplication)
: State(){
  mApplication = pApplication;
  onEnter();
}


void PreFlopState::onEnter(){
  std::cout << "Entering pre-flop state." << std::endl;
  return;
}


void PreFlopState::onExit(){
  std::cout << "Exiting pre-flop state." << std::endl;
  return;
}


void PreFlopState::update(){

}

void PreFlopState::render(){

}


void PreFlopState::changeState(State *pState){
  mApplication->setState(pState);
  return;
}