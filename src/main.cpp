
#include "presenter.hpp"


int main(){
  Presenter presenter = Presenter();
  while (true){
    presenter.handleInput();
    presenter.update();
    presenter.render();
  }
}