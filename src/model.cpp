
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
    for (int suit = 0; suit < 5; suit++){
      cards.push_back(Card(value, suit));
    }
  }
  return Deck(cards);
}


void Model::drawHand(){
  mPlayerHand = mDealer.drawHand(&mPlayerDeck);
  return;
}


void Model::drawPreflop(){
  if (mTable.tableCards.size() != 0){
    throw std::logic_error("Card before preflop");
  }
  for (int i = 0; i < 3; i++){
    Card drawnCard = mDealer.drawCard(&mTableDeck);
    mTable.tableCards.push_back(drawnCard);
  }
  return;
}


void Model::drawTurn(){
  mTable = mDealer.drawTurn(&mTable, &mTableDeck);
  return;
}


void Model::drawRiver(){
  mTable = mDealer.drawRiver(&mTable, &mTableDeck);
  return;
}
