
#ifndef RATER
#define RATER

#include "card_object.hpp"


class Rater{
  public:
    virtual float rateHand(
      Hand *pHand,
      Deck *pDeck,
      Table *pTable,
      int n_opponents
    ) = 0;
    virtual Point nameHand(Hand *pHand, Table *pTable) = 0;

  protected:
    Rater(){};
};

#endif