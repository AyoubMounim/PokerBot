
#include "presenter.hpp"
#include <iostream>


int main(){
  Presenter myPresenter;
  std::cout << "\nInitializing..." << std::endl;
  if (!myPresenter.init()){
    std::cout << "\nInitialization failed." << std::endl;
    return 0;
  }

  while (myPresenter.getRunning()){
    myPresenter.update();
    myPresenter.render();
    myPresenter.handleInput();
  }
}