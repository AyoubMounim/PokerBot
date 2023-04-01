
#ifndef RANGE_RATER
#define RANGE_RATER

#include "rater.hpp"


class RangeRater: public Rater{
  public:
    float rateHandRiver(
      Hand *pHand,
      Deck *pPlayerDeck,
      Table *pTable,
      int n_opponents
    );
    float rateHandTurn(
      Hand *pHand,
      Deck *pPlayerDeck,
      Table *pTable,
      Deck *pTableDeck,
      int n_opponents
    );
    float rateHandFlop(
      Hand *pHand,
      Deck *pPlayerDeck,
      Table *pTable,
      Deck *pTableDeck,
      int n_opponents
    );
    float rateHandPreFlop(
      Hand *pHand,
      Deck *pPlayerDeck,
      int n_opponents
    );
};

#endif
