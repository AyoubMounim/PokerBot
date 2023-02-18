
#include "model.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>


Model::Model()
: mPlayerDeck(initializeDeck()),
  mTableDeck(initializeDeck()){
}


Deck Model::initializeDeck(){
  std::vector<Card> cards;
  for (int value = 2; value < 15; value++){
    for (int suit = 0; suit < 4; suit++){
      cards.push_back(Card(value, suit));
    }
  }
  return Deck(cards);
}


void Model::drawHand(){
  mPlayerHand = mDealer.drawHand(&mPlayerDeck);
  return;
}


void Model::drawFlop(){
  mTable = mDealer.drawFlop(&mTableDeck);
  std::cout << mTableDeck.deckCards.size() << std::endl;
  return;
}


void Model::drawTurn(){
  mTable = mDealer.drawTurn(&mTable, &mTableDeck);
  std::cout << mTableDeck.deckCards.size() << std::endl;
  return;
}


void Model::drawRiver(){
  mTable = mDealer.drawRiver(&mTable, &mTableDeck);
  std::cout << mTableDeck.deckCards.size() << std::endl;
  return;
}
