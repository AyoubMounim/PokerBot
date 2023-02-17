
#ifndef PRESENTER
#define PRESENTER

#include "model.hpp"

struct Card;
class Viewer;


class Presenter{
  public:
    Presenter();

    Card * getCard(){return mModel->getCard();}
    void handleInput();
    void update();
    void render();
  
  private:
    Model *mModel;
    Viewer *mViewer;
};


#endif