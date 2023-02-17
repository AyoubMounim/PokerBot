
#include "dealer.hpp"


Card Dealer::drawCard(Deck *pDeck){
  Card card = pDeck->deckCards.back();
  pDeck->deckCards.pop_back();
  return card;
}