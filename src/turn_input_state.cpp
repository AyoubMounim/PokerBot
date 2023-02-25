
#include "turn_input_state.hpp"
#include "viewer.hpp"
#include "input_reader.hpp"
#include "river_input_state.hpp"


TurnInputState::TurnInputState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "TURN";
  mNextState = new RiverInputState(pPresenter);
}


void TurnInputState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void TurnInputState::onExit(){
  State::onExit();
  return;
}


void TurnInputState::update(){
  setTurn();
  GameState::rateHandTable();
  return;
}


void TurnInputState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  mPresenter->getViewer()->renderRating(mPresenter->getRating());
  return;
}


void TurnInputState::setTurn(){
  Card *pCard = mPresenter->getInputReader()->readCard();
  mPresenter->getModel()->addToTable(pCard);
  return;
}
