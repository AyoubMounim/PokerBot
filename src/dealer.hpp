
#ifndef DEALER
#define DEALER

#include "card_object.hpp"


class Dealer{
  public:
    Card drawCard(Deck *pDeck);
    Hand drawHand(Deck *pDeck);
    Table drawPreFlop(Deck *pDeck);
    Table drawTurn(Table *pTable, Deck *pDeck);
    Table drawRiver(Table *pTable, Deck *pDeck);
};

#endif