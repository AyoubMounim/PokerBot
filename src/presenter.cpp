
#include "presenter.hpp"
#include "model.hpp"
#include "console_viewer.hpp"
#include <iostream>
#include <string>


Presenter::Presenter(){
  mModel = new Model();
  mViewer = new ConsoleViewer();
}


void Presenter::handleInput(){
  std::string input;
  std::cout << "Press 'n' for new card." << std::endl;
  std::cin >> input;

  if (input == "n"){
    mModel->setCard();
  }
  else if (input == "q"){
    std::cout << "Exit." << std::endl;
  }
  return;
}


void Presenter::update(){
  return;
}


void Presenter::render(){
  mViewer->renderCard(getCard());
  return;
}
