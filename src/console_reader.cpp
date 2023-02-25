
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
  int value;
  int suit;

  // read card value
  if (card_value == "A" || card_value == "a"){
    value = 14;
  }
  else if (card_value == "K" || card_value == "k"){
    value = 13;
  }
  else if (card_value == "Q" || card_value == "q"){
    value = 12;
  }
  else if (card_value == "J" || card_value == "j"){
    value = 11;
  }
  else if (card_value == "T" || card_value == "t"){
    value = 10;
  }
  else{
    value = std::stoi(card_value);
  }

  // read card suit
  if (card_suit == "C" || card_suit == "c"){
    suit = 0;
  }
  else if (card_suit == "D" || card_suit == "d"){
    suit = 1;
  }
  else if (card_suit == "H" || card_suit == "h"){
    suit = 2;
  }
  else if (card_suit == "S" || card_suit == "s"){
    suit = 3;
  }

  return new Card(value, suit);
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