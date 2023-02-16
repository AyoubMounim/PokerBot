
#include "pre_flop_state.hpp"
#include "flop_state.hpp"
#include <iostream>
#include "hand.hpp"
#include "deck.hpp"
#include "table.hpp"


PreFlopState::PreFlopState(Application *pApplication)
: State(pApplication){
  state_id = "PRE-FLOP";
}


void PreFlopState::onEnter(){
  std::cout << "Entering pre-flop state." << std::endl;

  mObjects.emplace("player_deck", new Deck());
  mObjects.emplace("table_deck", new Deck());

  Hand *pHand = dynamic_cast<Deck *>(mObjects["player_deck"])->drawHand();
  mObjects.emplace("hand", pHand);

  return;
}


void PreFlopState::onExit(){
  std::cout << "Exiting pre-flop state." << std::endl;
  return;
}


void PreFlopState::update(){
  return;
}


void PreFlopState::render(){
  State::render();
  mObjects["hand"]->render();
  return;
}


void PreFlopState::handleInput(){
  std::string user_input;
  std::cout << "Press 'n' to go to flop." << std::endl;
  std::cout << "Press 'q' to exit." << std::endl;
  std::cin >> user_input;

  if (user_input == "q"){
    onExit();
    TheApplication::getInstance()->setRunning(false);
  }
  else if (user_input == "n"){
    mApplication->changeState(
      new FlopState(mApplication, mObjects)
    );
  }
  return;
}