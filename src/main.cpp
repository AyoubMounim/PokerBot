
#include "application.hpp"


int main(){
    TheApplication::getInstance()->initialize();
    while (TheApplication::getInstance()->getRunning()){
        TheApplication::getInstance()->update();
        TheApplication::getInstance()->render();
    }
}
