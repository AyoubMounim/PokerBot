
#ifndef Point_hpp
#define Point_hpp


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


class Point{
    private:
    hands name;
    int kicker;

    public:
    Point(hands, int);
    void setName(hands);
    void setKicker(int);
    void printPoint();
    hands getName();
    int getKicker();
};


#endif

