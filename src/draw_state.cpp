
#include "draw_state.hpp"


DrawState::DrawState(Presenter *pPresenter)
: GameState(pPresenter){
  mStateId = "DRAW";
  mNextState = nullptr;
}


void DrawState::onEnter(){
  State::onEnter();
  std::cout << "\n======= " << mStateId << " =======" << std::endl;
  return;
}


void DrawState::onExit(){
  State::onExit();
  return;
}


void DrawState::update(){
  return;
}


void DrawState::render(){
  return;
}