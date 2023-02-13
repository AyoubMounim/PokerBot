
#ifndef CARD
#define CARD

#include <string>
#include <vector>
#include <stdexcept>
#include "app_object.hpp"


enum suit{
    CLUB = 1,
    DIAMOND,
    HEART,
    SPADE
};


class Card: public AppObject{
    public:
    Card(int, suit);
    void setSuit(suit);
    void setValue(int);
    void setId(int, suit);
    suit getSuit();
    int getValue();
    int getId();
    void render();

    private:
    int cardValue;
    int id;
    suit cardSuit;
};

#endif
