
#include "effective_rater.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>


float EffectiveRater::rateHandRiver(
  Hand *pHand,
  Deck *pPlayerDeck,
  Table *pTable,
  int n_opponents
){
  std::vector<Hand *> opponentHands = generateHands(pPlayerDeck, 1);
  Point playerPoint = nameHand(pHand, pTable);
  float results[3] = {0};
  Result result;
  for (auto &hand: opponentHands){
    result = clashHands(&playerPoint, hand, pTable);
    results[result]++;
  }
  return effectiveStrength(results, 0, 0, n_opponents);
}


float EffectiveRater::rateHandTurn(
  Hand *pHand,
  Deck *pPlayerDeck,
  Table *pTable,
  Deck *pTableDeck,
  int n_opponents
){
  std::vector<Hand *> opponentHands = generateHands(pPlayerDeck, 1);
  Point playerPoint = nameHand(pHand, pTable);
  float results[3] = {0};
  float possible_results[3][3] = {0};
  Result result;
  Result possibleResult;
  for (auto &hand: opponentHands){
    result = clashHands(&playerPoint, hand, pTable);
    results[result]++;
    Table possibleTable = Table(*pTable);
    for (auto &card: pTableDeck->deckCards){
      possibleTable.tableCards.push_back(card);
      possibleResult = clashHands(pHand, hand, &possibleTable);
      possible_results[result][possibleResult]++;
      possibleTable.tableCards.pop_back();
    }
  }
  float pPot = positivePot(results, possible_results);
  float nPot = negativePot(results, possible_results);
  return effectiveStrength(results, pPot, nPot, n_opponents);
}


float EffectiveRater::rateHandFlop(
  Hand *pHand,
  Deck *pPlayerDeck,
  Table *pTable,
  Deck *pTableDeck,
  int n_opponents
){
  std::vector<Hand *> opponentHands = generateHands(pPlayerDeck, 1);
  Point playerPoint = nameHand(pHand, pTable);
  float results[3] = {0};
  float possible_results[3][3] = {0};
  Result result;
  Result possibleResult;
  for (auto &hand: opponentHands){
    result = clashHands(&playerPoint, hand, pTable);
    results[result]++;
    Table possibleTable = Table(*pTable);
    for (int i = 0; i < pTableDeck->deckCards.size() - 1; i++){
      possibleTable.tableCards.push_back(pTableDeck->deckCards[i]);
      for (int j = i + 1; j < pTableDeck->deckCards.size(); j++){
        possibleTable.tableCards.push_back(pTableDeck->deckCards[j]);
        possibleResult = clashHands(pHand, hand, &possibleTable);
        possible_results[result][possibleResult]++;
        possibleTable.tableCards.pop_back();
      }
      possibleTable.tableCards.pop_back();
    }
  }
  float pPot = positivePot(results, possible_results);
  float nPot = negativePot(results, possible_results);
  return effectiveStrength(results, pPot, nPot, n_opponents);
}


float EffectiveRater::rateHandPreFlop(Hand *pHand, Deck *pPlayerDeck, int n_opponents){
  std::vector<Hand *> opponentHands = generateHands(pPlayerDeck, 1);
  Table *pTable = new Table();
  Point playerPoint = nameHand(pHand, pTable);
  float results[3] = {0};
  Result result;
  for (auto &hand: opponentHands){
    result = clashHands(&playerPoint, hand, pTable);
    results[result]++;
  }
  return effectiveStrength(results, 0, 0, n_opponents);
}


float EffectiveRater::negativePot(float results[3], float possible_results[3][3]){
  return (possible_results[WIN][LOOSE] + possible_results[DRAW][LOOSE]/2 + possible_results[WIN][DRAW]/2)
        /(possible_results[WIN][LOOSE] + possible_results[WIN][WIN] + possible_results[WIN][DRAW]/2 + possible_results[DRAW][LOOSE]/2 + possible_results[DRAW][WIN]/2);
}


float EffectiveRater::positivePot(float results[3], float possible_results[3][3]){
  return (possible_results[LOOSE][WIN] + possible_results[LOOSE][DRAW]/2 + possible_results[DRAW][WIN]/2)
        /(possible_results[LOOSE][WIN] + possible_results[LOOSE][DRAW]/2 + possible_results[LOOSE][LOOSE] + possible_results[DRAW][WIN]/2 + possible_results[DRAW][LOOSE]/2);
}


float EffectiveRater::effectiveStrength(
  float results[3],
  float pPot,
  float nPot,
  int n_opponents
){
  float hand_strength = (results[WIN] + results[DRAW]/2)
                        /(results[WIN] + results[DRAW] + results[LOOSE]);
  float effective_strength = hand_strength*(1 - nPot) + (1 - hand_strength)*pPot;
  return std::pow(effective_strength, n_opponents);
}


Result EffectiveRater::clashHands(
  Hand *pPlayerHand,
  Hand *pOpponentHand,
  Table *pTable
){
  Point playerPoint = nameHand(pPlayerHand, pTable);
  Point opponentPoint = nameHand(pOpponentHand, pTable);
  if (playerPoint.grade > opponentPoint.grade){
    return WIN;
  }
  if (opponentPoint.grade == playerPoint.grade){
    if (playerPoint.kicker.value > opponentPoint.kicker.value){
      return WIN;
    }
    else if (playerPoint.kicker.value == opponentPoint.kicker.value){
      return DRAW;
    }
  }
  return LOOSE;
}


Result EffectiveRater::clashHands(
  Point *pPlayerPoint,
  Hand *pOpponentHand,
  Table *pTable
){
  Point opponentPoint = nameHand(pOpponentHand, pTable);
  if (pPlayerPoint->grade > opponentPoint.grade){
    return WIN;
  }
  if (opponentPoint.grade == pPlayerPoint->grade){
    if (pPlayerPoint->kicker.value > opponentPoint.kicker.value){
      return WIN;
    }
    else if (pPlayerPoint->kicker.value == opponentPoint.kicker.value){
      return DRAW;
    }
  }
  return LOOSE;
}


Point EffectiveRater::nameHand(Hand *pHand, Table *pTable){
  std::vector<Card> cards;
  Point *pPoint;
  cards.push_back(pHand->firstCard);
  cards.push_back(pHand->secondCard);
  for (auto &card: pTable->tableCards){
    cards.push_back(card);
  }
  sort(cards.begin(), cards.end(), std::greater<Card>());
  pPoint = checkRoyalFlush(&cards);
  if (pPoint != nullptr){
    return *pPoint;
  }
  pPoint = checkStraightFlush(&cards);
  if (pPoint != nullptr){
    return *pPoint;
  }
  pPoint = checkPoker(&cards);
  if (pPoint != nullptr){
    return *pPoint;
  }
  pPoint = checkFull(&cards);
  if (pPoint != nullptr){
    return *pPoint;
  }
  pPoint = checkFlush(&cards);
  if (pPoint != nullptr){
    return *pPoint;
  }
  pPoint = checkStraight(&cards);
  if (pPoint != nullptr){
    return *pPoint;
  }
  pPoint = checkTris(&cards);
  if (pPoint != nullptr){
    return *pPoint;
  }
  pPoint = checkPairs(&cards);
  if (pPoint != nullptr){
    return *pPoint;
  }
  return Point("HIGH CARD", cards[0], 0);
}


Point * EffectiveRater::checkPairs(std::vector<Card> *pCards){
  int pairs_count = 0;
  Card maxPairCard = Card(2, 0);

  for (int i = 0; i < pCards->size(); i++){
    for (int j = i+1; j < pCards->size(); j++){
      if ((*pCards)[i].value == (*pCards)[j].value){
        pairs_count++;
        if ((*pCards)[i].value > maxPairCard.value){
          maxPairCard.value = (*pCards)[i].value;
          maxPairCard.suit = (*pCards)[i].suit;
        }
        break;
      }
    }
  }
  if (pairs_count == 0){
    return nullptr;
  }
  else if (pairs_count == 1){
    return new Point("PAIR", maxPairCard, 1);
  }
  return new Point("DOUBLE PAIR", maxPairCard, 2);
}


Point * EffectiveRater::checkTris(std::vector<Card> *pCards){
  bool tris = false;
  Card maxCard = Card(2, 0);
  for (int i = 0; i < pCards->size(); i++){
    int matches_count = 0;
    for (int j = i+1; j < pCards->size(); j++){
      if ((*pCards)[i].value == (*pCards)[j].value){
        matches_count++;
        if (matches_count == 2 && (*pCards)[i].value >= maxCard.value){
          maxCard.value = (*pCards)[i].value;
          maxCard.suit = (*pCards)[i].suit;
          tris = true;
        }
      }
    }
  }
  if (!tris){
    return nullptr;
  }
  return new Point("TRIS", maxCard, 3);
}


Point * EffectiveRater::checkStraight(std::vector<Card> *pCards){
  if ((*pCards)[0].value == 14 && (*pCards)[1].value < 5){
    return nullptr;
  }
  if ((*pCards)[0].value < 6){
    return nullptr;
  }
  Card maxCard = Card(2, 0);
  int continuity = 0;
  for (int i = 0; i < pCards->size()-1; i++){
    if ((*pCards)[i].value - (*pCards)[i+1].value == 1){
      continuity++;
      if (continuity == 1){
        maxCard.value = (*pCards)[i].value;
        maxCard.suit = (*pCards)[i].suit;
      }
      else if (continuity == 4){
        break;
      }
    }
    else{
      continuity = 0;
    }
  }
  if (continuity == 3 && pCards->back().value == 2){
    if ((*pCards)[0].value == 14){
      return new Point("STRAIGHT", maxCard, 4);
    }
  }
  else if (continuity >= 4){
    return new Point("STRAIGHT", maxCard, 4);
  }
  return nullptr;
}


Point * EffectiveRater::checkFlush(std::vector<Card> *pCards){
  int suit_count[4] = {0};
  for (auto &card: *pCards){
    suit_count[card.suit]++;
  }
  int max_suit = std::max_element(suit_count, suit_count+4) - suit_count;
  int max_suit_count = suit_count[max_suit];
  if (max_suit_count >= 5){
    Card maxCard = Card(2, 0);
    for (auto &card: *pCards){
      if (card.suit != max_suit){
        continue;
      }
      if (card.value >= maxCard.value){
        maxCard = card;
      }
    }
    return new Point("FLUSH", maxCard, 5);
  }
  return nullptr;
}


Point * EffectiveRater::checkFull(std::vector<Card> *pCards){
  Point * Tris = checkTris(pCards);
  if (Tris == nullptr){
    return nullptr;
  }
  std::vector<Card> newCards;
  for (auto &card: *pCards){
    if (card.value != Tris->kicker.value){
      newCards.push_back(card);
    }
  }
  if (checkPairs(&newCards) == nullptr){
    return nullptr;
  }
  return new Point("FULL", Tris->kicker, 6);
}


Point * EffectiveRater::checkPoker(std::vector<Card> *pCards){
  bool poker = false;
  Card maxCard = Card(2, 0);
  for (int i = 0; i < pCards->size() - 1; i++){
    int matches_count = 0;
    for (int j = i+1; j < pCards->size(); j++){
      if ((*pCards)[i].value == (*pCards)[j].value){
        matches_count++;
        if (matches_count >= 3 && (*pCards)[i].value >= maxCard.value){
          maxCard = (*pCards)[i];
          poker = true;
        }
      }
    }
  }
  if (!poker){
    return nullptr;
  }
  return new Point("POKER", maxCard, 7);
}


Point * EffectiveRater::checkStraightFlush(std::vector<Card> *pCards){
  Point *Straight;
  int suit_count[4] = {0};
  for (auto &card: *pCards){
    suit_count[card.suit]++;
  }
  int max_suit = std::max_element(suit_count, suit_count+4) - suit_count;
  int max_suit_count = suit_count[max_suit];
  if (max_suit_count < 5){
    return nullptr;
  }
  std::vector<Card> newCards;
  for (auto &card: *pCards){
    if (card.suit == max_suit){
      newCards.push_back(card);
    }
  }
  Straight = checkStraight(&newCards);
  if (Straight == nullptr){
    return nullptr;
  }
  return new Point("STRAIGHT FLUSH", Straight->kicker, 8);
}


Point * EffectiveRater::checkRoyalFlush(std::vector<Card> *pCards){
  Point * Straight;
  int suit_count[4] = {0};
  for (auto &card: *pCards){
    suit_count[card.suit]++;
  }
  int max_suit = std::max_element(suit_count, suit_count+4) - suit_count;
  int max_suit_count = suit_count[max_suit];
  if (max_suit_count < 5){
    return nullptr;
  }
  std::vector<Card> newCards;
  for (auto &card: *pCards){
    if (card.suit == max_suit){
      newCards.push_back(card);
    }
  }
  Straight = checkStraight(&newCards);
  if (Straight == nullptr || Straight->kicker.value < 14){
    return nullptr;
  }
  return new Point("ROYAL FLUSH", Straight->kicker, 9);
}

std::vector<Hand *> EffectiveRater::generateHands(Deck *pDeck, int nOpponents){
  int n = pDeck->deckCards.size();
  int k = nOpponents*2;
  std::vector<bool> selector_outer(n);
  std::vector<bool> selector_inner(k);
  std::vector<Hand *> hands;
  std::vector<int> combinations_temp(k);
  std::fill(selector_outer.begin(), selector_outer.begin() + k, true);
  std::fill(selector_inner.begin(), selector_inner.begin() + 2, true);
  int combination = 0;
  do{
    combinations_temp.clear();
    int group_count = 0;
    for (int i = 0; i < n; i++){
      if (selector_outer[i]){
        combinations_temp.push_back(i);
        group_count++;
        if (group_count == k){
          break;
        }
      }
    }
    do{
      combination++;
      Card * pCards[2] = {nullptr, nullptr};
      int cards = 0;
      for (int j = 0; j < k; j++){
        if (selector_inner[j]){
          pCards[cards] = &(pDeck->deckCards[combinations_temp[j]]);
          cards++;
          if (cards==2){
            break;
          }
        }
      }
      hands.push_back(
        new Hand(*pCards[0], *pCards[1])
      );
    }
    while (std::prev_permutation(selector_inner.begin(), selector_inner.end()));
  }
  while (std::prev_permutation(selector_outer.begin(), selector_outer.end()));
  return hands;
}

