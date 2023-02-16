
#include "river_state.hpp"
#include "application.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "pre_flop_state.hpp"
#include <string>
#include <iostream>


RiverState::RiverState(
  Application *pApplication,
  std::map<std::string, AppObject *> objects
)
: State(pApplication){
  mObjects = objects;
}


void RiverState::onEnter(){
  std::cout << "Entering river state" << std::endl;

  Card drawnCard = dynamic_cast<Deck *>(mObjects["table_deck"])->drawCard();
  dynamic_cast<Table *>(mObjects["table"])->addCard(drawnCard);
  return;
}


void RiverState::onExit(){
  std::cout << "Exiting river state" << std::endl;
  return;
}


void RiverState::render(){
  mObjects["hand"]->render();
  mObjects["table"]->render();
  return;
}


void RiverState::update(){
  return;
}


void RiverState::handleInput(){
  std::string user_input;
  std::cout << "Press 'n' new game." << std::endl;
  std::cout << "Press 'q' to exit." << std::endl;
  std::cin >> user_input;

  if (user_input == "q"){
    onExit();
    TheApplication::getInstance()->setRunning(false);
  }
  else if (user_input == "n"){
    mApplication->changeState(
      new PreFlopState(mApplication)
    );
  }
  return;
}
