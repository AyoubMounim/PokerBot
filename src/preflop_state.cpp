
#include "preflop_state.hpp"
#include "viewer.hpp"
#include "turn_state.hpp"


PreflopState::PreflopState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "PREFLOP";
  mNextState = new TurnState(pPresenter);
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
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
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
