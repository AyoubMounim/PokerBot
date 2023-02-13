
#include "application.hpp"


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
  mState = new MenuState();
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