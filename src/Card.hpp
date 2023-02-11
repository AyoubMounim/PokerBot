
#ifndef Card_hpp
#define Card_hpp

#include <string>
#include <stdio.h>
#include <stdexcept>


enum suit{
    CLUB = 1,
    DIAMOND,
    HEART,
    SPADE
};


class Card{
    public:
    Card(int, suit);
    void setSuit(suit);
    void setValue(int);
    void setId(int, suit);
    suit getSuit();
    int getValue();
    int getId();
    void printCard();

    private:
    int cardValue;
    int id;
    suit cardSuit;
};


#endif
