
#ifndef RENDERER
#define RENDERER

#include <string>


class Card;
class Hand;
class Table;
class Deck;
class Point;


class Renderer{
  public:
    virtual void renderCard(Card *pCard) = 0;
    virtual void renderHand(Hand *pHand) = 0;
    virtual void renderTable(Table *pTable) = 0;
    virtual void renderDeck(Deck *pDeck) = 0;
    virtual void renderPoint(Point *pPoint) = 0;
    virtual void renderState(std::string state_id) = 0;
  
  protected:
    Renderer(){}
};

#endif