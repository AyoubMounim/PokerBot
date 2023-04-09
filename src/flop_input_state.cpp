
#include "flop_input_state.hpp"
#include "viewer.hpp"
#include "input_reader.hpp"
#include "turn_input_state.hpp"


FlopInputState::FlopInputState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "FLOP";
  mNextState = new TurnInputState(pPresenter);
}


void FlopInputState::onEnter(){
  // State::onEnter();
  GameState::onEnter();
  return;
}


void FlopInputState::onExit(){
  // State::onExit();
  return;
}


void FlopInputState::update(){
  resetTableDeck();
  mPresenter->setNumOpponents();
  setTable();
  GameState::nameHand();
  GameState::rateHand(mStateId);
  return;
}


void FlopInputState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  mPresenter->getViewer()->renderPoint(GameState::getPoint());
  mPresenter->getViewer()->renderRating(GameState::getRating());
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