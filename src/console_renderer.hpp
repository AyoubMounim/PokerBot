
#ifndef CONSOLE_RENDERER
#define CONSOLE_RENDERER

#include "renderer.hpp"
#include "card.hpp"
#include "hand.hpp"
#include "table.hpp"
#include "deck.hpp"
#include "point.hpp"
#include <string>
#include <vector>


class ConsoleRenderer: public Renderer{
  public:
    ConsoleRenderer();
    virtual void renderCard(Card *pCard);
    virtual void renderHand(Hand *pHand);
    virtual void renderTable(Table *pTable);
    virtual void renderDeck(Deck *pDeck);
    virtual void renderPoint(Point *pPoint);
    virtual void renderState(std::string state_id);

  private:
    std::vector<std::string> card_names;
    std::vector<std::string> card_suits;
};

#endif