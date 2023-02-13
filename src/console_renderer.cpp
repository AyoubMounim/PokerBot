
#include "console_renderer.hpp"


ConsoleRenderer::ConsoleRenderer()
: Renderer(){}

void ConsoleRenderer::renderCard(Card *pCard){
  std::cout
    << "\nCard: "
    << pCard->getValue()
    << pCard->getSuit() 
    << std::endl;
  return;
}


void ConsoleRenderer::renderHand(Hand *pHand){
  std::cout
    << "\nYour hand: "
    << pHand->get_first_card().getValue()
    << pHand->get_first_card().getSuit()
    << " "
    << pHand->get_second_card().getValue()
    << pHand->get_second_card().getSuit()
    << std::endl;
  return;
}


void ConsoleRenderer::renderTable(Table *pTable){
  std::cout << "\nThe table: ";
  for (auto &card: pTable->getCards()){
    std::cout << " " << card.getValue() << card.getSuit();
  }
  std::cout << std::endl;
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