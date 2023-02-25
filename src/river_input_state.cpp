
#include "river_input_state.hpp"
#include "viewer.hpp"
#include "input_reader.hpp"
#include "menu_state.hpp"


RiverInputState::RiverInputState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "RIVER";
  mNextState = new MenuState(pPresenter);
}


void RiverInputState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void RiverInputState::onExit(){
  State::onExit();
  return;
}


void RiverInputState::update(){
  setRiver();
  GameState::nameHand();
  GameState::rateHandTable();
  return;
}


void RiverInputState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  mPresenter->getViewer()->renderPoint(GameState::getPoint());
  mPresenter->getViewer()->renderRating(GameState::getRating());
  return;
}


void RiverInputState::setRiver(){
  Card *pCard = mPresenter->getInputReader()->readCard();
  mPresenter->getModel()->addToTable(pCard);
  return;
}
