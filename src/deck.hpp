
#ifndef DECK
#define DECK

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <random>
#include "card.hpp"
#include "app_object.hpp"


class Hand;
class Table;


class Deck: public AppObject{
  public:
    Deck();
    void removeCard(Card);
    void removeCards(std::vector<Card>);
    void initializeDeck();
    void shuffleDeck();
    void render();
    Card drawCard();
    Hand * drawHand();
    Table * drawFlop();
    std::vector<Card> drawCards(int);
    std::vector<Card> getDeckCards();

  private:
    std::vector<Card> deck_cards;
};

#endif