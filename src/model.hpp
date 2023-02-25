
#ifndef MODEL
#define MODEL

#include "card_object.hpp"
#include "dealer.hpp"


class Model{
  public:
    Model();
    void drawHand();
    void drawFlop();
    void drawTurn();
    void drawRiver();

    void setHand(Hand *pHand);
    void setTable(Table *pTable);
    void addToTable(Card *pCard);

    void removeCardPlayerDeck(Card *pCard);
    void removeCardTableDeck(Card *pCard);
    void removeCard(Card *pCard, Deck *pDeck);

    Hand * getHand(){return &mPlayerHand;}
    Table * getTable(){return &mTable;}

    Deck initializeDeck();
    void resetPlayerDeck(){mPlayerDeck = initializeDeck();}
    void resetTableDeck(){mTableDeck = initializeDeck();}

  private:
    Deck mPlayerDeck;
    Deck mTableDeck;
    Hand mPlayerHand;
    Table mTable;
    Dealer mDealer;
};

#endif