
#include "smart_rater.hpp"
#include <algorithm>


float SmartRater::rateHandRiver(
  Hand *pHand,
  Deck *pDeck,
  Table *pTable,
  int n_opponents
){
  return -1;
}


float SmartRater::rateHandTurn(
  Hand *pHand,
  Deck *pDeck,
  Table *pTable,
  Deck *pTableDeck,
  int n_opponents
){
  return -1;
}


float SmartRater::rateHandFlop(
  Hand *pHand,
  Deck *pDeck,
  Table *pTable,
  Deck *pTableDeck,
  int n_opponents
){
  return -1;
}


int SmartRater::valueOnTable(int value, Table *pTable){
  int count_value = 0;
  for (auto &card: pTable->tableCards){
    if (card.value == value){
      count_value++;
    }
  }
  return count_value;
}


int SmartRater::valueOnHand(int value, Hand *pHand){
  int count_value = 0;
  if (pHand->firstCard.value == value){
    count_value++;
  }
  if (pHand->secondCard.value == value){
    count_value++;
  }
  return count_value;
}


float SmartRater::noPair(int value, Hand *pHand, Table *pTable, int n_opponents){
  int value_in_deck = 4 - valueOnHand(value, pHand);
  float p = 1;
  switch (valueOnTable(value, pTable)){
    case 0:
      for (int i = 0; i < 2*n_opponents; i++){
        p *= (50.0 - i - value_in_deck)/(50.0 - i);
      }
      p *= (1 + 2*n_opponents*value_in_deck/(51.0 - 2*n_opponents));
      break;
    case 1:
      for (int i = 0; i < 2*n_opponents; i++){
        p *= (50.0 - i - value_in_deck)/(50.0 - i);
      }
      break;
    default:
      p = -1;
      break;
  }
  return p;
}


Point SmartRater::nameHand(Hand *pHand, Table *pTable){
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


Point SmartRater::nameHand(std::vector<Card> cards){
  sort(cards.begin(), cards.end(), std::greater<Card>());
  Point *pPoint;
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


Point * SmartRater::checkPairs(std::vector<Card> *pCards){
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


Point * SmartRater::checkTris(std::vector<Card> *pCards){
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


Point * SmartRater::checkStraight(std::vector<Card> *pCards){
  if ((*pCards)[0].value == 14 && (*pCards)[1].value < 5){
    return nullptr;
  }
  if ((*pCards)[0].value < 6){
    return nullptr;
  }
  Card maxCard = Card(2, 0);
  int continuity;
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


Point * SmartRater::checkFlush(std::vector<Card> *pCards){
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


Point * SmartRater::checkFull(std::vector<Card> *pCards){
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


Point * SmartRater::checkPoker(std::vector<Card> *pCards){
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


Point * SmartRater::checkStraightFlush(std::vector<Card> *pCards){
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
  if (Straight == nullptr){
    return nullptr;
  }
  return new Point("STRAIGHT FLUSH", Straight->kicker, 8);
}


Point * SmartRater::checkRoyalFlush(std::vector<Card> *pCards){
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
