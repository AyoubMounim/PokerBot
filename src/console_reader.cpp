
#include "console_reader.hpp"
#include <string>
#include <iostream>


Card * ConsoleReader::readCard(){
  std::string card_value; 
  std::string card_suit; 
  std::cout << "Insert card value: ";
  std::cin >> card_value;
  std::cout << "\nInstert card suit: ";
  std::cin >> card_suit;
  std::cout << std::endl;

  return buildCard(card_value, card_suit);
}

Card * ConsoleReader::buildCard(std::string card_value, std::string card_suit){
  return new Card(14, 0); //TODO: implement for real
}


Hand * ConsoleReader::readHand(){
  Card * firstCard; 
  Card * secondCard; 
  std::cout << "\nInsert your hand:" << std::endl;
  firstCard = readCard();
  secondCard = readCard();
  return new Hand(*firstCard, *secondCard);
}


Table * ConsoleReader::readTable(int n_cards){
  std::vector<Card> tableCards;
  std::cout << "\nInsert the table:" << std::endl;
  for (int i = 0; i < n_cards; i++){
    tableCards.push_back(*readCard());
  }
  return new Table(tableCards);
}