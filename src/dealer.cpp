
#include "dealer.hpp"
#include <stdexcept>


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


Table Dealer::drawFlop(Deck *pDeck){
  std::vector<Card> Flop;
  for (int i = 0; i < 3; i++){
    Card aCard = drawCard(pDeck);
    Flop.push_back(aCard); 
  }
  return Table(Flop);
}


Table Dealer::drawTurn(Table *pTable, Deck *pDeck){
  if (pTable->tableCards.size() != 3){
    throw std::logic_error("Wrong table at turn.");
  }
  Card drawnCard = drawCard(pDeck);
  pTable->tableCards.push_back(drawnCard);
  return *pTable;
}


Table Dealer::drawRiver(Table *pTable, Deck *pDeck){
  if (pTable->tableCards.size() != 4){
    throw std::logic_error("Wrong table at river.");
  }
  Card drawnCard = drawCard(pDeck);
  pTable->tableCards.push_back(drawnCard);
  return *pTable;
}
