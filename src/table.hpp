
#ifndef table
#define table

#include <vector>
#include "card.hpp"
#include "app_object.hpp"


class Table: public AppObject{
    public:
    Table(std::vector<Card>);
    void addCard(Card);
    void removeCard();
    std::vector<Card> getCards();
    void render();

    private:
    std::vector<Card> tableCards;
};


#endif