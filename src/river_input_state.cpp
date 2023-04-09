
#include "river_input_state.hpp"
#include "viewer.hpp"
#include "input_reader.hpp"
#include "menu_state.hpp"
#include "preflop_input_state.hpp"


RiverInputState::RiverInputState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "RIVER";
  mNextState = nullptr;
}


void RiverInputState::onEnter(){
  // State::onEnter();
  GameState::onEnter();
  return;
}


void RiverInputState::onExit(){
  // State::onExit();
  return;
}


void RiverInputState::update(){
  mPresenter->setNumOpponents();
  setRiver();
  GameState::nameHand();
  GameState::rateHand(mStateId);
  return;
}


void RiverInputState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  mPresenter->getViewer()->renderPoint(GameState::getPoint());
  mPresenter->getViewer()->renderRating(GameState::getRating());
  return;
}


void RiverInputState::handleInput(){
  std::string input;
  std::cout << "\nPress 'n' for new game." << std::endl;
  std::cout << "Press 'q' to go to main menu." << std::endl;
  std::cin >> input;

  if (input == "n"){
    mPresenter->changeState(new PreflopInputState(mPresenter));
  }
  else if (input == "q"){
    mPresenter->changeState(new MenuState(mPresenter));
  }
  return;
}


void RiverInputState::setRiver(){
  Card *pCard = mPresenter->getInputReader()->readCard();
  mPresenter->getModel()->addToTable(pCard);
  return;
}
