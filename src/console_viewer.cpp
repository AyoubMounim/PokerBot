
#include "console_viewer.hpp"
#include "card_object.hpp"
#include <iostream>


ConsoleViewer::ConsoleViewer()
: Viewer(){}

void ConsoleViewer::renderCard(Card *card){
  std::cout << card->value << " " << card->suit;
  return;
}


void ConsoleViewer::renderHand(Hand *hand){
  std::cout << "\nYour hand: ";
  renderCard(&(hand->firstCard));
  std::cout << ", ";
  renderCard(&(hand->secondCard));
  std::cout << std::endl;
  return;
}


void ConsoleViewer::renderTable(Table *table){
  std::cout << "\nThe table:";
  for (auto &card: table->tableCards){
    std::cout << " ";
    renderCard(&card);
  }
  std::cout << std::endl;
  return;
}