
#include "river_state.hpp"
#include "viewer.hpp"


RiverState::RiverState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "RIVER";
  mNextState = nullptr;
}


void RiverState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void RiverState::onExit(){
  State::onExit();
  return;
}


void RiverState::update(){
  mPresenter->setNumOpponents();
  drawRiver();
  return;
}


void RiverState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  mPresenter->getViewer()->renderTable(GameState::getTable());
  return;
}


void RiverState::drawRiver(){
  mPresenter->getModel()->drawRiver();
  return;
}
