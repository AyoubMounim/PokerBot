
#include "model.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <stdexcept>


Model::Model(Rater *pRater)
: mPlayerDeck(initializeDeck()),
  mTableDeck(initializeDeck()),
  mRater(pRater){
}


Deck Model::initializeDeck(bool shuffle){
  std::vector<Card> cards;
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine e(seed);
  for (int value = 2; value < 15; value++){
    for (int suit = 0; suit < 4; suit++){
      cards.push_back(Card(value, suit));
    }
  }
  if (shuffle){
    std::shuffle(cards.begin(), cards.end(), e);
  }
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


void Model::addToTable(Card *pCard){
  mTable.tableCards.push_back(*pCard);
  removeCardTableDeck(pCard);
  return;
}


void Model::setHand(Hand *pHand){
  mPlayerHand = *pHand;
  removeCardPlayerDeck(&(pHand->firstCard));
  removeCardPlayerDeck(&(pHand->secondCard));
  return;
}


void Model::setTable(Table *pTable){
  mTable = *pTable;
  for (auto &pCard: mTable.tableCards){
    removeCardTableDeck(&pCard);
  }
  return;
}


void Model::removeCardPlayerDeck(Card *pCard){
  removeCard(pCard, &mPlayerDeck);
  return;
}


void Model::removeCardTableDeck(Card *pCard){
  removeCard(pCard, &mTableDeck);
  return;
}


void Model::removeCard(Card *pCard, Deck *pDeck){
  auto it = (pDeck->deckCards).begin();
  while (it != (pDeck->deckCards).end()){
    if (pCard->value == it->value && pCard->suit == it->suit){
      (pDeck->deckCards).erase(it);
      return;
    }
    it++;
  }
  throw std::logic_error("Card to remove not found.");
}


void Model::rateRiver(){
  rating = mRater->rateHandRiver(
    &mPlayerHand,
    &mPlayerDeck,
    &mTable,
    n_opponents
  );
  return;
}


void Model::rateTurn(){
  rating = mRater->rateHandTurn(
    &mPlayerHand,
    &mPlayerDeck,
    &mTable,
    &mTableDeck,
    n_opponents
  );
  return;
}


void Model::rateFlop(){
  rating = mRater->rateHandFlop(
    &mPlayerHand,
    &mPlayerDeck,
    &mTable,
    &mTableDeck,
    n_opponents
  );
  return;
}


void Model::ratePreFlop(){
  rating = mRater->rateHandPreFlop(
    &mPlayerHand,
    &mPlayerDeck,
    n_opponents
  );
  return;
}
