
#include "Rater.hpp"


Rater::Rater(){};


void Rater::set_n_opponents(int n_opponents){
  if (n_opponents < 0){
    std::cout << "Number of opponents is not valid." << std::endl;
    return;
  }
  m_n_opponents = n_opponents;
  return;
}


float Rater::rate(){
  int result_hist[3] = {};
  std::vector<Card> cards_in_deck = mDeck->getDeckCards();
  int n_cards = cards_in_deck.size();
  int iterator_count = 0;
  for (int i = 0; i < n_cards - 1; i++){
    Card cardOne = cards_in_deck[i];
    for (int j = i + 1; j < n_cards; j++){
      Card cardTwo = cards_in_deck[j];

      Hand *opponentHand = new Hand(cardOne, cardTwo);
      Result result = compare_opponent_hands(opponentHand);
      result_hist[result]++;

      iterator_count++;
    }
  }
  std::cout << "Wins: " << result_hist[WIN] << std::endl;
  float win_rate = (float)result_hist[WIN]/iterator_count;
  return win_rate;
}


Result Rater::compare_opponent_hands(Hand *opponentHand){
  Point *opponentPoint = new Point(
    (opponentHand->nameHand(m_table)).getName(),
    (opponentHand->nameHand(m_table)).getKicker()
  );
  if (mPlayerPoint->getName() > opponentPoint->getName()){
    return WIN;
  }
  else if (mPlayerPoint->getName() < opponentPoint->getName()){
    return LOOSE;
  }
  else{
    if (mPlayerPoint->getKicker() > opponentPoint->getKicker()){
      return WIN;
    }
    else{
      return LOOSE;
    }
  }
  return DRAW;
}