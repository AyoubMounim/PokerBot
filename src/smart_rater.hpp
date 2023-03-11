
#ifndef SMART_RATER
#define SMART_RATER

#include "rater.hpp"
#include "card_object.hpp"
#include <vector>


class SmartRater: public Rater{
  public:
    float rateHand(Hand *pHand, Deck *pDeck, Table *pTable, int n_opponents);
    Point nameHand(Hand *pHand, Table *pTable);

    private:
      Point * checkPairs(std::vector<Card> *pCards);
      Point * checkTris(std::vector<Card> *pCards);
      Point * checkStraight(std::vector<Card> *pCards);
      Point * checkFlush(std::vector<Card> *pCards);
      Point * checkFull(std::vector<Card> *pCards);
      Point * checkPoker(std::vector<Card> *pCards);
      Point * checkStraightFlush(std::vector<Card> *pCards);
      Point * checkRoyalFlush(std::vector<Card> *pCards);
};

#endif
