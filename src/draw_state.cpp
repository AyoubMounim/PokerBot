
#include "draw_state.hpp"
#include "viewer.hpp"
#include "preflop_state.hpp"


DrawState::DrawState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "DRAW";
  mNextState = new PreflopState(pPresenter);
}


void DrawState::onEnter(){
  State::onEnter();
  GameState::onEnter();
  return;
}


void DrawState::onExit(){
  State::onExit();
  return;
}


void DrawState::update(){
  resetPlayerDeck();
  drawHand();
  return;
}


void DrawState::render(){
  mPresenter->getViewer()->renderHand(GameState::getHand());
  return;
}


void DrawState::resetPlayerDeck(){
  mPresenter->getModel()->resetPlayerDeck();
  return;
}


void DrawState::drawHand(){
  mPresenter->getModel()->drawHand();
  return;
}
