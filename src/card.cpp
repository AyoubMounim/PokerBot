
#include "application.hpp"
#include "card.hpp"


const std::vector<std::string> card_names = {
    "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"
};

const std::vector<std::string> card_suits = {
    "Clubs", "Diamonds", "Hearts", "Spades"
};


Card::Card(int value, suit s)
: AppObject(){
    setSuit(s);
    setValue(value);
    setId(value, s);
}


void Card::setSuit(suit s){
    cardSuit = s;
}


void Card::setValue(int v){
    if ((v < 2) || (v > 14)){
        throw std::invalid_argument("Invalid card value.");
    }
    cardValue = v;
}


suit Card::getSuit(){
    return cardSuit;
}


int Card::getValue(){
    return cardValue;
}


void Card::setId(int value, suit s){
    if ((value < 2) || (value > 14)){
        throw std::invalid_argument("Invalid card value.");
    }
    id = value*s;
}


int Card::getId(){
    return id;
}


void Card::render(){
    TheApplication::getInstance()->getRenderer()->renderCard(this);
    return;
}
