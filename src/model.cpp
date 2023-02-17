
#include "model.hpp"
#include <vector>


Model::Model()
: mPlayerDeck(initializeDeck()),
  mTableDeck(initializeDeck()){}


Deck Model::initializeDeck(){
  std::vector<Card> cards;
  for (int value = 2; value < 15; value++){
    for (int suit = 0; suit < 5; suit++){
      cards.push_back(Card(value, suit));
    }
  }
  return Deck(cards);
}