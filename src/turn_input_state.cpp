
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
  // State::onEnter();
  GameState::onEnter();
  return;
}


void TurnInputState::onExit(){
  // State::onExit();
  return;
}


void TurnInputState::update(){
  mPresenter->setNumOpponents();
  setTurn();
  GameState::nameHand();
  GameState::rateHand(mStateId);
  return;
}


void TurnInputState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  mPresenter->getViewer()->renderPoint(GameState::getPoint());
  mPresenter->getViewer()->renderRating(GameState::getRating());
  return;
}


void TurnInputState::setTurn(){
  Card *pCard = mPresenter->getInputReader()->readCard();
  mPresenter->getModel()->addToTable(pCard);
  return;
}
