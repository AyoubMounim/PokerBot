
#include "river_state.hpp"
#include "viewer.hpp"
#include "preflop_state.hpp"
#include "menu_state.hpp"


RiverState::RiverState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "RIVER";
  mNextState = new MenuState(pPresenter);
}


void RiverState::onEnter(){
  // State::onEnter();
  GameState::onEnter();
  return;
}


void RiverState::onExit(){
  // State::onExit();
  return;
}


void RiverState::update(){
  drawRiver();
  GameState::nameHand();
  GameState::rateHand(mStateId);
  return;
}


void RiverState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  mPresenter->getViewer()->renderPoint(GameState::getPoint());
  mPresenter->getViewer()->renderRating(GameState::getRating());
  return;
}


void RiverState::drawRiver(){
  mPresenter->getModel()->drawRiver();
  return;
}
