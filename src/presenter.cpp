
#include "presenter.hpp"
#include "model.hpp"
#include "console_viewer.hpp"
#include "console_reader.hpp"
#include "menu_state.hpp"
#include <iostream>
#include <string>
#include "brute_rater.hpp"
#include "smart_rater.hpp"
#include "effective_rater.hpp"
#include "range_rater.hpp"
#include <stdexcept>
#include "preflop_input_state.hpp"


Presenter::Presenter(){
  mState = nullptr;
}


bool Presenter::init(){
  mModel = new Model(new RangeRater());
  mViewer = new ConsoleViewer();
  mInputReader = new ConsoleReader();
  changeState(new MenuState(this));
  mRunning = true;
  return true;
}


void Presenter::handleInput(){
  mState->handleInput();
  return;
}


void Presenter::update(){
  mState->update();
  return;
}


void Presenter::render(){
  mState->render();
  return;
}


void Presenter::changeState(State *pState){
  if (mState != nullptr){
    mState->onExit();
  }
  mState = pState;
  mState->onEnter();
}

void Presenter::setNumOpponents(){
  int n_opponents = mInputReader->readNumOpponents();
  mModel->setNumOpponents(n_opponents);
  return;
}


void Presenter::rateHand(std::string stateId){
  if (stateId == "PREFLOP"){
    mModel->ratePreFlop();
  }
  else if (stateId == "FLOP"){
    mModel->rateFlop();
  }
  else if (stateId == "TURN"){
    mModel->rateFlop();
  }
  else if (stateId == "RIVER"){
    mModel->rateRiver();
  }
  else{
    throw std::invalid_argument("Invalid game phase");
  }
  return;
}


void Presenter::goToPreflop(){
  changeState(new PreflopInputState(this));
  return;
}

