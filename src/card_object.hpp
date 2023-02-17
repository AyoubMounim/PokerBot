
#ifndef CARD_OBJECT
#define CARD_OBJECT

#include <vector>


struct Card{
  int value;
  int suit;

  Card(){}

  Card(int card_value, int card_suit){
    value = card_value;
    suit = card_suit;
  }
};


struct Hand{
  Card firstCard;
  Card secondCard;

  Hand(){}

  Hand(Card cardOne, Card cardTwo)
  : firstCard(cardOne),
    secondCard(cardTwo){}
};


struct Deck{
  std::vector<Card> deckCards;

  Deck(std::vector<Card> &cards){
    deckCards = cards;
  }
};


struct Table{
  std::vector<Card> tableCards;

  Table(){}

  Table(std::vector<Card> &cards){
    tableCards = cards;
  }
};

#endif