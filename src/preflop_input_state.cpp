
#include "preflop_input_state.hpp"
#include "viewer.hpp"
#include "input_reader.hpp"


PreflopInputState::PreflopInputState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "PREFLOP";
  mNextState = nullptr;
}



void PreflopInputState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void PreflopInputState::onExit(){
  State::onEnter();
  return;
}


void PreflopInputState::update(){
  setHand();
  return;
}


void PreflopInputState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  return;
}


void PreflopInputState::resetPlayerDeck(){
  mPresenter->getModel()->resetPlayerDeck();
  return;
}


void PreflopInputState::setHand(){
  Hand * pHand = mPresenter->getInputReader()->readHand();
  mPresenter->getModel()->setHand(pHand);
  return;
}