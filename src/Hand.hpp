
#ifndef Hand_hpp
#define Hand_hpp

#include "Card.hpp"
#include "Table.hpp"
#include "Point.hpp"


class Hand{
    public:
    Hand(Card, Card);
    Point nameHand(Table *);
    void printHand();

    private:
    Card firstCard;
    Card secondCard;
};


#endif