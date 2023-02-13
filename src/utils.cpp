
/*

#include <iostream>
#include "Deck.hpp"
#include "Hand.hpp"
#include "Table.hpp"
#include "Point.hpp"

int improvementOneStep(Hand myHand, Table myTable, Deck myDeck){
    Table possibleTable = Table(myTable.getCards());
    Point myPoint = myHand.nameHand(&myTable);
    Point max_point = Point(myPoint.getName(), myPoint.getKicker());
    int trials = 0;
    int improvements = 0;
    for (auto &card: myDeck.getDeckCards()){
        possibleTable.addCard(card);
        Point possiblePoint = myHand.nameHand(&possibleTable);
        if (possiblePoint.getName() > myPoint.getName()){
            improvements++;
            max_point.setName(possiblePoint.getName());
            max_point.setKicker(possiblePoint.getKicker());
        }
        else if (possiblePoint.getName() == myPoint.getName()){
            if (possiblePoint.getKicker() > myPoint.getKicker()){
                improvements++;
                max_point.setKicker(possiblePoint.getKicker());
            }
        }
        trials++;
        possibleTable.removeCard();
    }
    std::cout << "\nBest point:\n";
    max_point.printPoint();
    return improvements;
}


int improvementTwoStep(Hand myHand, Table myTable, Deck myDeck){
    Table possibleTable = Table(myTable.getCards());
    Point myPoint = myHand.nameHand(&myTable);
    Point max_point = Point(myPoint.getName(), myPoint.getKicker());
    int trials = 0;
    int improvements = 0;
    int deck_size = myDeck.getDeckCards().size();
    for (int i=0; i<deck_size; i++){
        possibleTable.addCard(myDeck.getDeckCards()[i]);
        for (int j=i+1; j<deck_size; j++){
            possibleTable.addCard(myDeck.getDeckCards()[j]);
            Point possiblePoint = myHand.nameHand(&possibleTable);
            if (possiblePoint.getName() > myPoint.getName()){
                improvements++;
                max_point.setName(possiblePoint.getName());
                max_point.setKicker(possiblePoint.getKicker());
            }
            else if (possiblePoint.getName() == myPoint.getName()){
                if (possiblePoint.getKicker() > myPoint.getKicker()){
                    improvements++;
                    max_point.setKicker(possiblePoint.getKicker());
                }
            }
            possibleTable.removeCard();
            trials++;
        }
        possibleTable.removeCard();
    }
    std::cout << "\nBest point:\n";
    max_point.printPoint();
    return improvements;
}


float rateHand(Hand myHand, Table myTable, Deck myDeck){
    int improvements = 0;
    int trials = 0;
    if (myTable.getCards().size() == 4){
        improvements = improvementOneStep(myHand, myTable, myDeck);
        trials = 46;
    }
    else if (myTable.getCards().size() == 3){
        improvements = improvementTwoStep(myHand, myTable, myDeck);
        trials = 1081;
    }
    float rate = (float)improvements/trials;
    return rate;
}
*/