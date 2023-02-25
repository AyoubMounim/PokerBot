
#include "console_viewer.hpp"
#include "card_object.hpp"
#include <iostream>


ConsoleViewer::ConsoleViewer()
: Viewer(){
}

void ConsoleViewer::renderCard(Card *card){
  std::string card_value;
  switch (card->value){
    case 14:
      card_value = "A";
      break;
    
    case 13:
      card_value = "K";
      break;

    case 12:
      card_value = "Q";
      break;
    
    case 11:
      card_value = "J";
      break;
    
    case 10:
      card_value = "T";
      break;
    
    default:
      card_value = std::to_string(card->value);
      break;
  }
  std::cout << card_value << "" << suit_repr[card->suit];
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


void ConsoleViewer::renderRating(float rating){
  std::cout << "\n Rating: " << rating << std::endl;
  return;
}