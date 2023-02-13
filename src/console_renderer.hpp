
#ifndef console_renderer
#define console_renderer

#include <iostream>
#include "renderer.hpp"
#include "card.hpp"
#include "hand.hpp"
#include "table.hpp"
#include "deck.hpp"
#include "point.hpp"


class ConsoleRenderer: public Renderer{
  public:
    ConsoleRenderer();
    virtual void renderCard(Card *pCard);
    virtual void renderHand(Hand *pHand);
    virtual void renderTable(Table *pTable);
    virtual void renderDeck(Deck *pDeck);
    virtual void renderPoint(Point *pPoint);
};

#endif