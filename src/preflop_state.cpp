
#include "preflop_state.hpp"
#include "viewer.hpp"
#include "flop_state.hpp"


PreflopState::PreflopState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "PREFLOP";
  mNextState = new FlopState(pPresenter);
}


void PreflopState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void PreflopState::onExit(){
  State::onExit();
  return;
}


void PreflopState::update(){
  resetPlayerDeck();
  drawHand();
  return;
}


void PreflopState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  return;
}


void PreflopState::resetPlayerDeck(){
  mPresenter->getModel()->resetPlayerDeck();
  return;
}


void PreflopState::drawHand(){
  mPresenter->getModel()->drawHand();
  return;
}
