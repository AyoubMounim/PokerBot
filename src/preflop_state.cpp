
#include "preflop_state.hpp"
#include "viewer.hpp"
#include "flop_state.hpp"


PreflopState::PreflopState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "PREFLOP";
  mNextState = new FlopState(pPresenter);
}


void PreflopState::onEnter(){
  // State::onEnter();
  GameState::onEnter();
  return;
}


void PreflopState::onExit(){
  // State::onExit();
  return;
}


void PreflopState::update(){
  mPresenter->resetPlayerDeck();
  mPresenter->resetTableDeck();
  mPresenter->setNumOpponents();
  drawHand();
  mPresenter->clearTable();
  GameState::nameHand();
  GameState::rateHand(mStateId);
  return;
}


void PreflopState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderPoint(GameState::getPoint());
  mPresenter->getViewer()->renderRating(GameState::getRating());
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
