
#ifndef INPUT_READER
#define INPUT_READER

#include "card_object.hpp"


class InputReader{
  public:
    virtual Card readCard() = 0;
    virtual Hand readHand() = 0;
    virtual Table readTable() = 0;

  private:
    InputReader(){};
};

#endif