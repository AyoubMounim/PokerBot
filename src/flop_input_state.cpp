
#include "flop_input_state.hpp"
#include "viewer.hpp"
#include "input_reader.hpp"


FlopInputState::FlopInputState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "FLOP";
  mNextState = nullptr;
}


void FlopInputState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void FlopInputState::onExit(){
  State::onExit();
  return;
}


void FlopInputState::update(){
  resetTableDeck();
  setTable();
  return;
}


void FlopInputState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  return;
}


void FlopInputState::resetTableDeck(){
  mPresenter->getModel()->resetTableDeck();
  return;
}


void FlopInputState::setTable(){
  Table *pTable = mPresenter->getInputReader()->readTable(3);
  mPresenter->getModel()->setTable(pTable);
  return;
}