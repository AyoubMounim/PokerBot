
#ifndef CARD_OBJECT
#define CARD_OBJECT

#include <vector>


struct Card{
  int value;
  int suit;
};


struct Hand{
  Card firstCard;
  Card secondCard;
};


struct Deck{
  std::vector<Card> deckCards;
};


struct Table{
  std::vector<Card> tableCards;
};


#endif