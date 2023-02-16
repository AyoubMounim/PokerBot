
#include <iostream>
#include "console_renderer.hpp"


ConsoleRenderer::ConsoleRenderer()
: Renderer(){
  card_names = {
    "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"
  };
  card_suits = {
    "Clubs", "Diamonds", "Hearts", "Spades"
  };
}

void ConsoleRenderer::renderCard(Card *pCard){
  std::string card_number = card_names[pCard->getValue()-2];
  std::string card_suit = card_suits[pCard->getSuit()-1];
  std::cout
    << "\nCard: "
    << card_number
    << card_suit
    << std::endl;
  return;
}


void ConsoleRenderer::renderHand(Hand *pHand){
  std::string card_number_1 = card_names[pHand->get_first_card().getValue()-2];
  std::string card_suit_1 = card_suits[pHand->get_first_card().getSuit()-1];
  std::string card_number_2 = card_names[pHand->get_second_card().getValue()-2];
  std::string card_suit_2 = card_suits[pHand->get_second_card().getSuit()-1];

  std::cout
    << "\nYour hand: "
    << card_number_1
    << card_suit_1
    << " "
    << card_number_2
    << card_suit_2
    << std::endl;
  return;
}


void ConsoleRenderer::renderTable(Table *pTable){
  std::cout << "\nThe table:";
  for (auto &card: pTable->getCards()){
    std::string card_number = card_names[card.getValue()-2];
    std::string card_suit = card_suits[card.getSuit()-1];
    std::cout << " " << card_number << card_suit;
  }
  std::cout << "\n" << std::endl;
  return;
}


void ConsoleRenderer::renderDeck(Deck *pDeck){
  if (pDeck->getDeckCards().size() == 0){
      std::cout << "The deck has no cards." << std::endl;
      return;
  }
  std::cout << "\nDeck: ";
  for (auto &card: pDeck->getDeckCards())
      renderCard(&card);
  return;
}


void ConsoleRenderer::renderPoint(Point *pPoint){
  std::cout
    << "\nYour point: "
    << pPoint->getName()
    << " ("
    << pPoint->getKicker()
    << " kicker)"
    << std::endl;
  return;
}


void ConsoleRenderer::renderState(std::string state_id){
  std::cout << "\n======= " << state_id << " =======" << std::endl;
  return;
}