
#include "model.hpp"


Model::Model(){
  mPlayerDeck = initializeDeck();
  mTableDeck = initializeDeck();
}


Deck Model::initializeDeck(){
  Deck deck;
  for (int value = 2; value < 15; value++){
    for (int suit = 0; suit < 5; suit++){
      Card card;
      card.value = value;
      card.suit = suit;
      deck.deckCards.push_back(card);
    }
  }
  return deck;
}