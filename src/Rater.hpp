/*
#ifndef Rater_hpp
#define Rater_hpp

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "hand.hpp"
#include "point.hpp"
#include "table.hpp"
#include "deck.hpp"


enum Result{
  WIN,
  LOOSE,
  DRAW
};


class Rater{
  public:
    Rater();
    float rate();
    Point * name_hand(Hand *hand);
    void set_n_opponents(int n_opponents);

    void set_player_hand(Hand *playerHand);
    void set_table(Table *table){mTable = table;}
    void set_deck(Deck *deck){mDeck = deck;}

  private:
    Result compare_opponent_hands(Hand *opponentHand);
    std::array<int, 2> check_pairs(std::vector<Card> cards);
    std::array<int, 2> check_tris(std::vector<Card> cards);
    std::array<int, 2> check_straight(std::vector<Card> cards);
    std::array<int, 2> check_flush(std::vector<Card> cards);
    std::array<int, 2> check_full(std::vector<Card> cards);
    std::array<int, 2> check_poker(std::vector<Card> cards);
    std::array<int, 2> check_straight_flush(std::vector<Card> cards);
    std::array<int, 2> check_royal_flush(std::vector<Card> cards);

    int m_n_opponents;
    Hand *mPlayerHand;
    Point *mPlayerPoint;
    Table *mTable;
    Deck *mDeck;
    std::vector<Hand> m_opponent_hands;
};

#endif
*/