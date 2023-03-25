
#ifndef EFFECTIVE_RATER
#define EFFECTIVE_RATER

#include "rater.hpp"
#include "card_object.hpp"


enum Result{
  LOOSE,
  DRAW,
  WIN
};


class EffectiveRater: public Rater{
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
    Point nameHand(Hand *pHand, Table *pTable);

  private:
    std::vector<Hand *> generateHands(Deck *pDeck, int nOpponents);
    Result clashHands(
      Hand *pPlayerHand,
      Hand *pOpponentHand,
      Table *pTable
    );
    Result clashHands(
      Point *pPlayerPoint,
      Hand *pOpponentHand,
      Table *pTable
    );
    float negativePot(float results[3], float possible_results[3][3]);
    float positivePot(float results[3], float possible_results[3][3]);
    float effectiveStrength(
      float results[3],
      float pPot,
      float nPot,
      int n_opponents
    );

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
