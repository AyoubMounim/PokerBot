
#include "preflop_state.hpp"
#include "viewer.hpp"


PreflopState::PreflopState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "PREFLOP";
  mNextState = nullptr;
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
  resetTableDeck();
  drawPreflop();
  return;
}


void PreflopState::render(){
  mPresenter->getViewer()->renderHand(getHand());
  mPresenter->getViewer()->renderTable(getTable());
  return;
}


void PreflopState::resetTableDeck(){
  mPresenter->getModel()->resetTableDeck();
  return;
}


void PreflopState::drawPreflop(){
  mPresenter->getModel()->drawPreflop();
  return;
}


Hand * PreflopState::getHand(){
  return mPresenter->getModel()->getHand();
}


Table * PreflopState::getTable(){
  return mPresenter->getModel()->getTable();
}
