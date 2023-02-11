
#ifndef Rater_hpp
#define Rater_hpp

#include <iostream>
#include <vector>
#include <chrono>
#include "Hand.hpp"
#include "Point.hpp"
#include "Table.hpp"
#include "Deck.hpp"


enum Result{
  WIN,
  LOOSE,
  DRAW
};


class Rater{
  public:
    Rater();
    float rate();
    Point name_hand();
    void set_n_opponents(int n_opponents);

    void set_player_point(Point *player_point){mPlayerPoint = player_point;}
    void set_table(Table *table){m_table = table;}
    void set_deck(Deck *deck){mDeck = deck;}

  private:
    Result compare_opponent_hands(Hand *opponentHand);

    int m_n_opponents;
    Point *mPlayerPoint;
    std::vector<Hand> m_opponent_hands;
    Table *m_table;
    Deck *mDeck;
};

#endif