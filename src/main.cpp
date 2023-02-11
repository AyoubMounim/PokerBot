
#include <iostream>
#include <chrono>
#include "Card.hpp"
#include "Hand.hpp"
#include "Table.hpp"
#include "Point.hpp"
#include "Deck.hpp"
#include "utils.hpp"
#include "Rater.hpp"


int main(){
    int n_opponents = 2;
    Rater rater = Rater();

    Deck *playerDeck = new Deck();
    Deck *tableDeck = new Deck();
    playerDeck->shuffleDeck();
    tableDeck->shuffleDeck();

    Hand myHand = Hand(playerDeck->drawCard(), playerDeck->drawCard());
    Table myTable = Table(tableDeck->drawCards(3));
    Point myPoint = myHand.nameHand(&myTable);

    myHand.printHand();
    myTable.printTable();
    myPoint.printPoint();

    rater.set_player_point(&myPoint);
    rater.set_n_opponents(n_opponents);
    rater.set_table(&myTable);
    rater.set_deck(playerDeck);
    float rating = rater.rate();

    std::cout << "Rating: " << rating << std::endl;
}
