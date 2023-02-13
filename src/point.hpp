
#ifndef point
#define point

#include <iostream>
#include <vector>
#include <stdexcept>
#include "app_object.hpp"


enum hands{
    HIGH_CARD,
    PAIR,
    DOUBLE_PAIR,
    TRIS,
    STRAIGHT,
    FLUSH,
    FULL,
    POKER,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
};


class Point: public AppObject{
    private:
    hands name;
    int kicker;

    public:
    Point(hands, int);
    void setName(hands);
    void setKicker(int);
    void render();
    hands getName();
    int getKicker();
};

#endif

