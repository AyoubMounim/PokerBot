
#include "flop_state.hpp"
#include "viewer.hpp"
#include "turn_state.hpp"


FlopState::FlopState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "FLOP";
  mNextState = new TurnState(pPresenter);
}


void FlopState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void FlopState::onExit(){
  State::onExit();
  return;
}


void FlopState::update(){
  resetTableDeck();
  drawPreflop();
  return;
}


void FlopState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  return;
}


void FlopState::resetTableDeck(){
  mPresenter->getModel()->resetTableDeck();
  return;
}


void FlopState::drawPreflop(){
  mPresenter->getModel()->drawFlop();
  return;
}
