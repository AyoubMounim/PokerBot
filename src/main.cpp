
#include <iostream>
#include "Card.hpp"
#include "Hand.hpp"
#include "Table.hpp"
#include "Point.hpp"
#include "Deck.hpp"
#include "utils.hpp"


int main(){
    int n_players = 2;

    Deck myDeck = Deck();
    myDeck.shuffleDeck();

    Hand myHand = Hand(myDeck.drawCard(), myDeck.drawCard());
    Table myTable = Table(myDeck.drawCards(3));
    Point myPoint = myHand.nameHand(myTable);
    myPoint.printPoint();

    float rate = rateHand(myHand, myTable, myDeck);
    std::cout << "\nHand rate: " << rate << "\n";
}
