
#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include "Card.hpp"

class Deck{
    public:
    Deck();
    void removeCard(Card);
    void removeCards(std::vector<Card>);
    void initializeDeck();
    void shuffleDeck();
    void printDeck();
    Card drawCard();
    std::vector<Card> drawCards(int);
    std::vector<Card> getDeckCards();

    private:
    std::vector<Card> deck_cards;
};


#endif