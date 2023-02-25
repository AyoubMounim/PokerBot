
#include "preflop_input_state.hpp"
#include "viewer.hpp"
#include "input_reader.hpp"
#include "flop_input_state.hpp"


PreflopInputState::PreflopInputState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "PREFLOP";
  mNextState = new FlopInputState(pPresenter);
}



void PreflopInputState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void PreflopInputState::onExit(){
  State::onExit();
  return;
}


void PreflopInputState::update(){
  resetPlayerDeck();
  setHand();
  GameState::rateHand();
  return;
}


void PreflopInputState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderRating(mPresenter->getRating());
  return;
}


void PreflopInputState::resetPlayerDeck(){
  mPresenter->getModel()->resetPlayerDeck();
  return;
}


void PreflopInputState::setHand(){
  Hand *pHand = mPresenter->getInputReader()->readHand();
  mPresenter->getModel()->setHand(pHand);
  return;
}