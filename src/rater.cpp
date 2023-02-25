
#include "rater.hpp"
#include <iostream>


float Rater::rateHand(Hand *pHand){
  return 11;
}


float Rater::rateHand(Hand *pHand, Table *pTable){
  return 13;
}


Point Rater::nameHand(Hand *pHand, Table *pTable){
  return Point("Test", Card(14, 0), 0); // TODO: implement for real
}
