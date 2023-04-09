
#include "turn_state.hpp"
#include "viewer.hpp"
#include "river_state.hpp"


TurnState::TurnState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "TURN";
  mNextState = new RiverState(pPresenter);
}


void TurnState::onEnter(){
  // State::onEnter();
  GameState::onEnter();
  return;
}


void TurnState::onExit(){
  // State::onExit();
  return;
}


void TurnState::update(){
  drawTurn();
  GameState::nameHand();
  GameState::rateHand(mStateId);
  return;
}


void TurnState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  mPresenter->getViewer()->renderPoint(GameState::getPoint());
  mPresenter->getViewer()->renderRating(GameState::getRating());
  return;
}


void TurnState::drawTurn(){
  mPresenter->getModel()->drawTurn();
  return;
}