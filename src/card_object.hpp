
#ifndef CARD_OBJECT
#define CARD_OBJECT

#include <vector>
#include <stdexcept>


struct Card{
  int value;
  int suit;

  Card(){}

  Card(int card_value, int card_suit){
    if (card_value < 2 || card_value > 14){
      throw std::invalid_argument("Card value not valid.");
    }
    if (card_suit < 0 || card_suit > 3){
      throw std::invalid_argument("Card suit not valid.");
    }
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