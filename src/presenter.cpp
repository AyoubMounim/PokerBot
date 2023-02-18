
#include "presenter.hpp"
#include "model.hpp"
#include "console_viewer.hpp"
#include "console_reader.hpp"
#include "menu_state.hpp"
#include <iostream>
#include <string>


Presenter::Presenter(){
  mState = nullptr;
}


bool Presenter::init(){
  mModel = new Model();
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
