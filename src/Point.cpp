
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Point.hpp"


const std::vector<std::string> card_names = {
    "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"
};

const std::vector<std::string> point_names = {
    "High Card", "Pair", "Double Pair", "Tris", "Straight", "Flush", "Full",
    "Poker", "Straight Flush", "Royal Flush"
};


Point::Point(hands handName, int k){
    setName(handName);
    setKicker(k);
}

void Point::setName(hands handName){
    name = handName;
}

void Point::setKicker(int k){
    if (k < 2 || k > 14){
        throw std::invalid_argument("Kicker value invalid.");
    }
    kicker = k;
}

void Point::printPoint(){
    std::string point_name = point_names[name];
    std::string kicker_name = card_names[kicker - 2];
    std::cout << "\nPoint:\n";
    std::cout << ">>> Name: " << point_name << "\n";
    std::cout << ">>> Kicker: " << kicker_name << "\n";
}

hands Point::getName(){
    return name;
}

int Point::getKicker(){
    return kicker;
}