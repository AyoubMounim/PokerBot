
#include "model.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <stdexcept>


Model::Model()
: mPlayerDeck(initializeDeck()),
  mTableDeck(initializeDeck()){
}


Deck Model::initializeDeck(){
  std::vector<Card> cards;
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine e(seed);
  for (int value = 2; value < 15; value++){
    for (int suit = 0; suit < 4; suit++){
      cards.push_back(Card(value, suit));
    }
  }
  std::shuffle(cards.begin(), cards.end(), e);
  return Deck(cards);
}


void Model::drawHand(){
  mPlayerHand = mDealer.drawHand(&mPlayerDeck);
  return;
}


void Model::drawFlop(){
  mTable = mDealer.drawFlop(&mTableDeck);
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
