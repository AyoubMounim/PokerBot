
#ifndef EFFECTIVE_RATER
#define EFFECTIVE_RATER

#include "rater.hpp"
#include "card_object.hpp"


class EffectiveRater: public Rater{
  public:
    float rateHand(
      Hand *pHand,
      Deck *pPlayerDeck,
      Table *pTable,
      Deck *pTableDeck,
      int n_opponents
    );
    Point nameHand(Hand *pHand, Table *pTable);

  private:
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
