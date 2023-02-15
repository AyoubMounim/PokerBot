
#include "flop_state.hpp"
#include "app_object.hpp"
#include "deck.hpp"
#include "table.hpp"
#include "turn_state.hpp"
#include <iostream>


FlopState::FlopState(
  Application *pApplication,
  std::map<std::string, AppObject *> objects
)
: State(pApplication){
  mObjects = objects;
}


void FlopState::onEnter(){
  std::cout << "Entering flop state." << std::endl;
  Table *pTable = dynamic_cast<Deck *>(mObjects["table_deck"])->drawFlop();
  mObjects.emplace("table", pTable);
  return;
}


void FlopState::onExit(){
  std::cout << "Exiting flop state." << std::endl;
  return;
}


void FlopState::update(){
  return;
}



void FlopState::render(){
  mObjects["hand"]->render();
  mObjects["table"]->render();
  return;
}


void FlopState::handleInput(){
  std::string user_input;
  std::cout << "Press 'n' to go to turn." << std::endl;
  std::cout << "Press 'q' to exit." << std::endl;
  std::cin >> user_input;

  if (user_input == "q"){
    onExit();
    TheApplication::getInstance()->setRunning(false);
  }
  else if (user_input == "n"){
    mApplication->changeState(
      new TurnState(mApplication, mObjects)
    );
  }
  return;
}