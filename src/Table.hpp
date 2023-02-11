
#ifndef Table_hpp
#define Table_hpp

#include <vector>
#include "Card.hpp"


class Table{
    public:
    Table(std::vector<Card>);
    void addCard(Card);
    void removeCard();
    std::vector<Card> getCards();
    void printTable();

    private:
    std::vector<Card> tableCards;
};


#endif