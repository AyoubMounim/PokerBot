
#include "dealer.hpp"


Card Dealer::drawCard(Deck *pDeck){
  Card card = pDeck->deckCards.back();
  pDeck->deckCards.pop_back();
  return card;
}


Hand Dealer::drawHand(Deck *pDeck){
  Card cardOne = drawCard(pDeck);
  Card cardTwo = drawCard(pDeck);
  return Hand(cardOne, cardTwo);
}


Table Dealer::drawPreFlop(Deck *pDeck){
  std::vector<Card> preFlop;
  for (int i = 0; i < 3; i++){
    Card aCard = drawCard(pDeck);
    preFlop.push_back(aCard); 
  }
  return Table(preFlop);
}