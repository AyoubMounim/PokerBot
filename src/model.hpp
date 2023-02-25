
#ifndef MODEL
#define MODEL

#include "card_object.hpp"
#include "dealer.hpp"
#include "rater.hpp"


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

    Deck initializeDeck(bool shuffle = true);
    void resetPlayerDeck(){mPlayerDeck = initializeDeck();}
    void resetTableDeck(){mTableDeck = initializeDeck();}

    void rateHand(){rating = mRater.rateHand(&mPlayerHand);}
    void rateHandTable(){rating = mRater.rateHand(&mPlayerHand, &mTable);}
    float getRating(){return rating;}

    void nameHand(){mPoint = mRater.nameHand(&mPlayerHand, &mTable);}
    Point * getPoint(){return &mPoint;}

  private:
    Deck mPlayerDeck;
    Deck mTableDeck;
    Hand mPlayerHand;
    Table mTable;
    Dealer mDealer;
    Rater mRater;
    Point mPoint;
    float rating;
};

#endif