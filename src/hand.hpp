
#ifndef HAND
#define HAND

#include "card.hpp"
#include "app_object.hpp"


class Hand: public AppObject{
  public:
    Hand(Card, Card);
    void render();

    Card get_first_card(){return firstCard;}
    Card get_second_card(){return secondCard;}

  private:
    Card firstCard;
    Card secondCard;
};

#endif