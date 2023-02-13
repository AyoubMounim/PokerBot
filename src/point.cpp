
#include "point.hpp"


const std::vector<std::string> card_names = {
    "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"
};

const std::vector<std::string> point_names = {
    "High Card", "Pair", "Double Pair", "Tris", "Straight", "Flush", "Full",
    "Poker", "Straight Flush", "Royal Flush"
};


Point::Point(hands handName, int k)
: AppObject(){
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

void Point::render(){
  return;
}

hands Point::getName(){
    return name;
}

int Point::getKicker(){
    return kicker;
}