
#include "table.hpp"
#include "application.hpp"


Table::Table(std::vector<Card> cards)
: AppObject(){
  if (cards.size()<3 || cards.size()>5){
    throw std::invalid_argument("Invalid table cards number.");
  }
  tableCards = cards;
}


void Table::addCard(Card card){
  if (tableCards.size() > 4){
    throw std::invalid_argument("Table full.");
  }
  tableCards.push_back(card);
  return;
}


void Table::removeCard(){
  if (tableCards.size() == 3){
    throw std::invalid_argument("Table has only 3 cards.");
  }
  tableCards.pop_back();
  return;
}


std::vector<Card> Table::getCards(){
  return tableCards;
}

void Table::render(){
  TheApplication::getInstance()->getRenderer()->renderTable(this);
  return;
}
