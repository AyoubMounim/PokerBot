
#ifndef SMART_RATER
#define SMART_RATER

#include "rater.hpp"
#include "card_object.hpp"
#include <vector>


class SmartRater: public Rater{
  public:
    float rateHand(
      Hand *pHand,
      Deck *pDeck,
      Table *pTable,
      Deck *pTableDeck,
      int n_opponents
    );
    Point nameHand(Hand *pHand, Table *pTable);

    Point nameHand(std::vector<Card>);

  private:
    Point * checkPairs(std::vector<Card> *pCards);
    Point * checkTris(std::vector<Card> *pCards);
    Point * checkStraight(std::vector<Card> *pCards);
    Point * checkFlush(std::vector<Card> *pCards);
    Point * checkFull(std::vector<Card> *pCards);
    Point * checkPoker(std::vector<Card> *pCards);
    Point * checkStraightFlush(std::vector<Card> *pCards);
    Point * checkRoyalFlush(std::vector<Card> *pCards);

    int valueOnTable(int value, Table *pTable);
    int valueOnHand(int value, Hand *pHand);
    float noPair(int value, Hand *pHand, Table *pTable, int n_opponents);
};

#endif
