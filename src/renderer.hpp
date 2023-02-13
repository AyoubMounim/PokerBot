
#ifndef renderer
#define renderer

#include "card.hpp"
#include "hand.hpp"
#include "table.hpp"
#include "deck.hpp"
#include "point.hpp"


class Renderer{
  public:
    virtual void renderCard(Card *pCard) = 0;
    virtual void renderHand(Hand *pHand) = 0;
    virtual void renderTable(Table *pTable) = 0;
    virtual void renderDeck(Deck *pDeck) = 0;
    virtual void renderPoint(Point *pPoint) = 0;
  
  protected:
    Renderer(){}
};

#endif