
#include "application.hpp"
#include "state.hpp"
#include "menu_state.hpp"
#include <iostream>


Application * Application::sInstance = nullptr;


Application * Application::getInstance(){
  if (sInstance == nullptr){
    sInstance = new Application();
  }
  return sInstance;
}


void Application::initialize(){
  mRunning = true;
  mRenderer = new ConsoleRenderer();
  mState = new MenuState(sInstance);
  mState->onEnter();
  std::cout << "Initialization succesfull." << std::endl;
  return;
}


void Application::update(){
  mState->update();
  return;
}


void Application::render(){
  mState->render();
  return;
}


void Application::handleInput(){
  mState->handleInput();
  return;
}


void Application::changeState(State *pSate){
  mState->onExit();
  mState = pSate;
  mState->onEnter();
  return;  
}