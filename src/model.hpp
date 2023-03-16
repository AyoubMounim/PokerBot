
#ifndef MODEL
#define MODEL

#include "card_object.hpp"
#include "dealer.hpp"
#include "rater.hpp"


class Model{
  public:
    Model(Rater *pRater);
    void drawHand();
    void drawFlop();
    void drawTurn();
    void drawRiver();

    void setHand(Hand *pHand);
    void setTable(Table *pTable);
    void addToTable(Card *pCard);
    void clearTable(){mTable.tableCards.clear();}
    void setNumOpponents(int n){n_opponents = n;}

    void removeCardPlayerDeck(Card *pCard);
    void removeCardTableDeck(Card *pCard);
    void removeCard(Card *pCard, Deck *pDeck);

    Hand * getHand(){return &mPlayerHand;}
    Table * getTable(){return &mTable;}

    Deck initializeDeck(bool shuffle = true);
    void resetPlayerDeck(){mPlayerDeck = initializeDeck();}
    void resetTableDeck(){mTableDeck = initializeDeck();}

    void rateHandTable(){
      rating = mRater->rateHand(
        &mPlayerHand,
        &mPlayerDeck,
        &mTable,
        &mTableDeck,
        n_opponents
      );
    }
    float getRating(){return rating;}

    void nameHand(){mPoint = mRater->nameHand(&mPlayerHand, &mTable);}
    Point * getPoint(){return &mPoint;}

  private:
    Deck mPlayerDeck;
    Deck mTableDeck;
    Hand mPlayerHand;
    Table mTable;
    Dealer mDealer;
    Rater *mRater;
    Point mPoint;
    int n_opponents;
    float rating;
};

#endif