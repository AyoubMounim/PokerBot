
#ifndef MODEL
#define MODEL

#include "card_object.hpp"
#include "dealer.hpp"


class Model{
  public:
    Model();
    Deck initializeDeck();

    Card * getCard(){return &mCard;}
    void setCard(){mCard = mDealer.drawCard(&mPlayerDeck);}

  private:
    Card mCard;
    Deck mPlayerDeck;
    Deck mTableDeck;
    Hand mPlayerHand;
    Dealer mDealer;
};


#endif