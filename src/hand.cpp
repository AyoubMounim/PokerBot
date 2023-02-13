
#include "hand.hpp"
#include "application.hpp"


Hand::Hand(Card cardOne, Card cardTwo)
: AppObject(),
  firstCard(cardOne),
  secondCard(cardTwo){}


void Hand::render(){
  TheApplication::getInstance()->getRenderer()->renderHand(this);
  return;
}
