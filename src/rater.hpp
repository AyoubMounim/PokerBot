
#ifndef RATER
#define RATER

#include "card_object.hpp"


class Rater{
  public:
    float rateHand(Hand *pHand);
    float rateHand(Hand *pHand, Table *pTable);
};

#endif
