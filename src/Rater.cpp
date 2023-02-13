/*
#include "Rater.hpp"


bool card_greater(Card& lhs, Card& rhs){
    return lhs.getValue() > rhs.getValue();
}


std::array<int, 2> Rater::check_pairs(std::vector<Card> cards){
    std::array<int, 2> result;
    int pairsCount = 0;
    int max_value_pair = 0;
    int max_value = cards.back().getValue();
    for (int i=0; i<cards.size()-1; i++){
        if (cards[i].getValue() > max_value){
            max_value = cards[i].getValue();
        }
        for (int j=i+1; j<cards.size(); j++){
            if (cards[i].getValue() == cards[j].getValue()){
                pairsCount++;
                if (cards[i].getValue() > max_value_pair){
                    max_value_pair = cards[i].getValue();
                }
                break;
            }
        }
    }
    result[0] = pairsCount;
    result[1] = max_value_pair;
    if (pairsCount == 0){
        result[1] = max_value;
    }
    return result;
}


std::array<int, 2> Rater::check_tris(std::vector<Card> cards){
    std::array<int, 2> result = {0};
    int max_value = 0;
    for (int i=0; i<cards.size()-1; i++){
        int matchesCount = 0;
        for (int j=i+1; j<cards.size(); j++){
            if (cards[i].getValue() == cards[j].getValue()){
                matchesCount++;
                if (matchesCount >= 2 && cards[i].getValue() > max_value){
                    max_value = cards[i].getValue();
                }
            }
        } 
    }
    if (max_value > 0){
        result[0] = 1;
        result[1] = max_value;
    }
    return result;
}


std::array<int, 2> Rater::check_straight(std::vector<Card> cards){
    std::array<int, 2> result = {0};
    if (cards[0].getValue() == 14 && cards[1].getValue() < 5){
        return result;
    }
    if (cards[0].getValue() < 6){
        return result;
    }
    int max_value = 0;
    int continuity = 0;
    for (int i=0; i<cards.size()-1; i++){
        if (cards[i].getValue() - cards[i+1].getValue() == 1){
            continuity++;
            if (continuity == 1){
                max_value = cards[i].getValue();
            }
            else if (continuity == 4){
                break;
            }
        }
        else{
            continuity = 0;
        }
    }
    if (continuity >= 4){
        result[0] = 1;
        result[1] = max_value;
    }
    else if (continuity == 3 && cards.back().getValue() == 2){
        if (cards[0].getValue() == 14){
            result[0] = 1;
            result[1] = max_value;
        }
    }
    return result;
}


std::array<int, 2> Rater::check_flush(std::vector<Card> cards){
    std::array<int, 2> result;
    int suitCount[4] = {0};
    for (auto& card: cards){
        suitCount[card.getSuit()]++;
    }
    int max_suit = std::max_element(suitCount, suitCount + 4) - suitCount;
    int max_suit_count = suitCount[max_suit];
    if (max_suit_count >= 5){
        result[0] = 1;
        int max_value = 0;
        for (auto& card: cards){
            if (card.getSuit() != max_suit){
                continue;
            }
            if (card.getValue() > max_value){
                max_value = card.getValue();
            }
        }
        result[1] = max_value;
    }
    else{
        result[0] = 0;
        result[1] = 0;
    }
    return result;
}


std::array<int, 2> Rater::check_full(std::vector<Card> cards){
    std::array<int, 2> result = {0};
    std::array<int, 2> isTris = check_tris(cards);
    if (isTris[0] == 0){
        return result;
    }
    std::vector<Card> new_cards;
    for (auto& card: cards){
        if (card.getValue() != isTris[1]){
            new_cards.push_back(card);
        }
    }
    std::array<int, 2> isPairs = check_pairs(new_cards);
    if (isPairs[0] == 0){
        return result;
    }
    return isTris;
}


std::array<int, 2> Rater::check_poker(std::vector<Card> cards){
    std::array<int, 2> result = {0};
    int max_value = 0;
    for (int i=0; i<cards.size()-1; i++){
        int matchesCount = 0;
        for (int j=i+1; j<cards.size(); j++){
            if (cards[i].getValue() == cards[j].getValue()){
                matchesCount++;
                if (matchesCount >= 3 && cards[i].getValue() > max_value){
                    max_value = cards[i].getValue();
                }
            }
        } 
    }
    if (max_value > 0){
        result[0] = 1;
        result[1] = max_value;
    }
    return result;
}


std::array<int, 2> Rater::check_straight_flush(std::vector<Card> cards){
    std::array<int, 2> result = {0};
    int suitCount[4] = {0};
    for (auto& card: cards){
        suitCount[card.getSuit()]++;
    }
    int max_suit = std::max_element(suitCount, suitCount + 4) - suitCount;
    int max_suit_count = suitCount[max_suit];
    if (max_suit_count < 5){
        return result;
    }
    std::vector<Card> new_cards;
    for (auto& card: cards){
        if (card.getSuit() == max_suit){
            new_cards.push_back(card);
        }
    }
    std::array<int, 2> isStraight = check_straight(new_cards);
    return isStraight;
}


std::array<int, 2> Rater::check_royal_flush(std::vector<Card> cards){
    std::array<int, 2> result = {0};
    int suitCount[4] = {0};
    for (auto& card: cards){
        suitCount[card.getSuit()]++;
    }
    int max_suit = std::max_element(suitCount, suitCount + 4) - suitCount;
    int max_suit_count = suitCount[max_suit];
    if (max_suit_count < 5){
        return result;
    }
    std::vector<Card> new_cards;
    for (auto& card: cards){
        if (card.getSuit() == max_suit){
            new_cards.push_back(card);
        }
    }
    std::array<int, 2> isStraight = check_straight(new_cards);
    if (isStraight[0] == 0 || isStraight[1] != 14){
        return result;
    }
    return isStraight;
}


Rater::Rater(){
  mPlayerHand = nullptr;
  mPlayerPoint = nullptr;
  mTable = nullptr;
  mDeck = nullptr;
};


void Rater::set_n_opponents(int n_opponents){
  if (n_opponents < 0){
    std::cout << "Number of opponents is not valid." << std::endl;
    return;
  }
  m_n_opponents = n_opponents;
  return;
}


void Rater::set_player_hand(Hand *playerHand){
  mPlayerHand = playerHand;
  mPlayerPoint = nullptr;
  return;
}


Point * Rater::name_hand(Hand *hand){
  if (hand == nullptr || mTable == nullptr){
    std::cout << "Naming hand failed." << std::endl;
  }
  std::vector<Card> cards;
  Card firstCard = hand->get_first_card();
  Card secondCard = hand->get_second_card();
  for (auto& card: mTable->getCards()){
      cards.push_back(card);
  }
  cards.push_back(firstCard);
  cards.push_back(secondCard);
  sort(cards.begin(), cards.end(), &card_greater);

  std::array<int, 2> isRoyalFlush = check_royal_flush(cards);
  if (isRoyalFlush[0] == 1){
      return new Point(ROYAL_FLUSH, isRoyalFlush[1]);
  }
  std::array<int, 2> isStraightFlush = check_straight_flush(cards);
  if (isStraightFlush[0] == 1){
      return new Point(STRAIGHT_FLUSH, isStraightFlush[1]);
  }
  std::array<int, 2> isPoker = check_poker(cards);
  if (isPoker[0] == 1){
      return new Point(POKER, isPoker[1]);
  }
  std::array<int, 2> isFull = check_full(cards);
  if (isFull[0] == 1){
      return new Point(FULL, isFull[1]);
  }

  std::array<int, 2> isFlush = check_flush(cards);
  if (isFlush[0] == 1){
      return new Point(FLUSH, isFlush[1]);
  }
  std::array<int, 2> isStraight = check_straight(cards);
  if (isStraight[0] == 1){
      return new Point(STRAIGHT, isStraight[1]);
  }
  std::array<int, 2> isTris = check_tris(cards);
  if (isTris[0] == 1){
      return new Point(TRIS, isTris[1]);
  }
  std::array<int, 2> isPairs = check_pairs(cards);
  switch (isPairs[0]){
      case 0:
      return new Point(HIGH_CARD, isPairs[1]);
      case 1:
      return new Point(PAIR, isPairs[1]);    
      default:
      return new Point(DOUBLE_PAIR, isPairs[1]);
  }
}


float Rater::rate(){
  mPlayerPoint = name_hand(mPlayerHand);
  if (mPlayerPoint == nullptr){
    std::cout << "Player point is not valid" << std::endl;
  }
  int result_hist[3] = {};
  std::vector<Card> cards_in_deck = mDeck->getDeckCards();
  int n_cards = cards_in_deck.size();
  int iterator_count = 0;

  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < n_cards - 1; i++){
    Card cardOne = cards_in_deck[i];
    for (int j = i + 1; j < n_cards; j++){
      Card cardTwo = cards_in_deck[j];

      Hand *opponentHand = new Hand(cardOne, cardTwo);
      Result result = compare_opponent_hands(opponentHand);
      result_hist[result]++;

      iterator_count++;
    }
  }
  auto end = std::chrono::steady_clock::now();
  std::cout 
    << "Time: " 
    << (std::chrono::duration_cast<std::chrono::microseconds>(end-start).count())/1000000.0 
    << std::endl;

  float win_rate = (float)result_hist[WIN]/iterator_count;
  return win_rate;
}


Result Rater::compare_opponent_hands(Hand *opponentHand){
  Point *opponentPoint = name_hand(opponentHand);
  if (mPlayerPoint->getName() > opponentPoint->getName()){
    return WIN;
  }
  else if (mPlayerPoint->getName() < opponentPoint->getName()){
    return LOOSE;
  }
  else{
    if (mPlayerPoint->getKicker() > opponentPoint->getKicker()){
      return WIN;
    }
    else{
      return LOOSE;
    }
  }
  return DRAW;
}
*/