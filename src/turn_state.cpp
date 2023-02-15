
#include "turn_state.hpp"
#include "application.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "table.hpp"
#include <iostream>


TurnState::TurnState(
  Application *pApplication,
  std::map<std::string, AppObject *> objects
)
: State(pApplication){
  mObjects = objects;
}


void TurnState::onEnter(){
  std::cout << "Entering turn state." << std::endl;
  Card drawnCard = dynamic_cast<Deck *>(mObjects["table_deck"])->drawCard();
  dynamic_cast<Table *>(mObjects["table"])->addCard(drawnCard);
  return;
}


void TurnState::onExit(){
  std::cout << "Exiting turn state." << std::endl;
  return;
}


void TurnState::render(){
  mObjects["hand"]->render();
  mObjects["table"]->render();
  return;
}


void TurnState::update(){
  return;
}


void TurnState::handleInput(){
  std::string user_input;
  std::cout << "Press 'n' to go to flop." << std::endl;
  std::cout << "Press 'q' to exit." << std::endl;
  std::cin >> user_input;

  if (user_input == "q"){
    onExit();
    TheApplication::getInstance()->setRunning(false);
  }
  else if (user_input == "n"){
    /*
    mApplication->changeState(
      new RiverState(mApplication, mObjects)
    );
    */
  }
  return;
}
