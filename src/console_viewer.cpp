
#include "console_viewer.hpp"
#include "card_object.hpp"
#include <iostream>


ConsoleViewer::ConsoleViewer()
: Viewer(){}

void ConsoleViewer::renderCard(Card *card){
  std::cout << "\nCard: " << card->value << " " << card->suit << std::endl;
  return;
}


void ConsoleViewer::renderHand(Hand *hand){
  return;
}


void ConsoleViewer::renderTable(Table *table){
  return;
}