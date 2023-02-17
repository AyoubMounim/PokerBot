
#ifndef MODEL
#define MODEL

#include "card_object.hpp"
#include "dealer.hpp"


class Model{
  public:
    Model();
    Deck initializeDeck();

  private:
    Deck mPlayerDeck;
    Deck mTableDeck;
    Hand mPlayerHand;
    Table mTable;
    Dealer mDealer;
};


#endif