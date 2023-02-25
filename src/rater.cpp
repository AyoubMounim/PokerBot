
#include "rater.hpp"
#include <iostream>


float Rater::rateHand(Hand *pHand){
  std::cout << "rating hand" << std::endl;
  return 1;
}


float Rater::rateHand(Hand *pHand, Table *pTable){
  std::cout << "rating hand with table" << std::endl;
  return 1;
}
