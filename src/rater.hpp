
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
    virtual float rateHandPreFlop(
      Hand *pHand,
      Deck *pPlayerDeck,
      int n_opponents
    ) = 0;
    virtual Point nameHand(Hand *pHand, Table *pTable);

  protected:
    Rater(){};

    virtual Point * checkPairs(std::vector<Card> *pCards);
    virtual Point * checkTris(std::vector<Card> *pCards);
    virtual Point * checkStraight(std::vector<Card> *pCards);
    virtual Point * checkFlush(std::vector<Card> *pCards);
    virtual Point * checkFull(std::vector<Card> *pCards);
    virtual Point * checkPoker(std::vector<Card> *pCards);
    virtual Point * checkStraightFlush(std::vector<Card> *pCards);
    virtual Point * checkRoyalFlush(std::vector<Card> *pCards);
};

#endif