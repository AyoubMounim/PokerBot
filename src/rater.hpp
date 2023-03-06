
#ifndef RATER
#define RATER

#include "card_object.hpp"
#include <vector>


class Rater{
  public:
    float rateHand(Hand *pHand);
    float rateHand(Hand *pHand, Table *pTable);
    Point nameHand(Hand *pHand, Table *pTable);

    std::vector<Hand *> generateHands(Deck *pDeck, int nOpponents);

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
