
#ifndef RATER
#define RATER

#include "card_object.hpp"


class Rater{
  public:
    virtual float rateHandRiver(
      Hand *pHand,
      Deck *pPlayerDeck,
      Table *pTable,
      int n_opponents
    ) = 0;
    virtual float rateHandTurn(
      Hand *pHand,
      Deck *pPlayerDeck,
      Table *pTable,
      Deck *pTableDeck,
      int n_opponents
    ) = 0;
    virtual float rateHandFlop(
      Hand *pHand,
      Deck *pPlayerDeck,
      Table *pTable,
      Deck *pTableDeck,
      int n_opponents
    ) = 0;
    virtual Point nameHand(Hand *pHand, Table *pTable) = 0;

  protected:
    Rater(){};
};

#endif