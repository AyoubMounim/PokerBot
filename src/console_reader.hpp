
#ifndef CONSOLE_READER
#define CONSOLE_READER

#include "input_reader.hpp"
#include <string>


class ConsoleReader: public InputReader{
  public:
    Card * readCard();
    Hand * readHand();
    Table * readTable(int n_cards);
    int readNumOpponents();

  private:
    Card * buildCard(std::string card_value, std::string card_suit);
};

#endif