
#include "Hand.hpp"
#include "Card.hpp"
#include "Point.hpp"
#include <algorithm>


bool cardGreater(Card& lhs, Card& rhs){
    return lhs.getValue() > rhs.getValue();
}


std::array<int, 2> checkPairs(std::vector<Card> cards){
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


std::array<int, 2> checkTris(std::vector<Card> cards){
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


std::array<int, 2> checkStraight(std::vector<Card> cards){
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


std::array<int, 2> checkFlush(std::vector<Card> cards){
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


std::array<int, 2> checkFull(std::vector<Card> cards){
    std::array<int, 2> result = {0};
    std::array<int, 2> isTris = checkTris(cards);
    if (isTris[0] == 0){
        return result;
    }
    std::vector<Card> new_cards;
    for (auto& card: cards){
        if (card.getValue() != isTris[1]){
            new_cards.push_back(card);
        }
    }
    std::array<int, 2> isPairs = checkPairs(new_cards);
    if (isPairs[0] == 0){
        return result;
    }
    return isTris;
}


std::array<int, 2> checkPoker(std::vector<Card> cards){
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


std::array<int, 2> checkStraightFlush(std::vector<Card> cards){
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
    std::array<int, 2> isStraight = checkStraight(new_cards);
    return isStraight;
}


std::array<int, 2> checkRoyalFlush(std::vector<Card> cards){
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
    std::array<int, 2> isStraight = checkStraight(new_cards);
    if (isStraight[0] == 0 || isStraight[1] != 14){
        return result;
    }
    return isStraight;
}


Hand::Hand(Card cardOne, Card cardTwo)
    : firstCard{cardOne}, secondCard{cardTwo}
{
}

void Hand::printHand(){
    printf("\nHand:");
    firstCard.printCard();
    secondCard.printCard();
}

Point Hand::nameHand(Table table){
    std::vector<Card> cards;
    for (auto& card: table.getCards()){
        cards.push_back(card);
    }
    cards.push_back(firstCard);
    cards.push_back(secondCard);
    sort(cards.begin(), cards.end(), &cardGreater);

    std::array<int, 2> isRoyalFlush = checkRoyalFlush(cards);
    if (isRoyalFlush[0] == 1){
        return Point(ROYAL_FLUSH, isRoyalFlush[1]);
    }
    std::array<int, 2> isStraightFlush = checkStraightFlush(cards);
    if (isStraightFlush[0] == 1){
        return Point(STRAIGHT_FLUSH, isStraightFlush[1]);
    }
    std::array<int, 2> isPoker = checkPoker(cards);
    if (isPoker[0] == 1){
        return Point(POKER, isPoker[1]);
    }
    std::array<int, 2> isFull = checkFull(cards);
    if (isFull[0] == 1){
        return Point(FULL, isFull[1]);
    }

    std::array<int, 2> isFlush = checkFlush(cards);
    if (isFlush[0] == 1){
        return Point(FLUSH, isFlush[1]);
    }
    std::array<int, 2> isStraight = checkStraight(cards);
    if (isStraight[0] == 1){
        return Point(STRAIGHT, isStraight[1]);
    }
    std::array<int, 2> isTris = checkTris(cards);
    if (isTris[0] == 1){
        return Point(TRIS, isTris[1]);
    }
    std::array<int, 2> isPairs = checkPairs(cards);
    switch (isPairs[0]){
        case 0:
        return Point(HIGH_CARD, isPairs[1]);
        case 1:
        return Point(PAIR, isPairs[1]);    
        default:
        return Point(DOUBLE_PAIR, isPairs[1]);
    }
}

