
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <random>
#include <random>
#include <vector>
#include "Deck.hpp"
#include "Card.hpp"


suit card_suits[4] = {CLUB, DIAMOND, HEART, SPADE};


Deck::Deck(){
    initializeDeck();
}

void Deck::initializeDeck(){
    deck_cards.clear();
    for (int value=2; value<15; value++){
        for (auto &suit: card_suits){
            deck_cards.push_back(Card(value, suit));
        }
    }
    return;
}

void Deck::printDeck(){
    if (deck_cards.size() == 0){
        std::cout << "The deck has no cards.\n";
        return;
    }
    std::cout << "\nDeck:\n";
    for (auto &card: deck_cards)
        card.printCard(); 
    return;
}

std::vector<Card> Deck::getDeckCards(){
    return deck_cards;
}

void Deck::shuffleDeck(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck_cards.begin(), deck_cards.end(), g);
    return;
}

void Deck::removeCard(Card card){
    if (deck_cards.size() < 1)
        throw std::invalid_argument("The deck is empty.");

    int id_to_remove = card.getId();
    deck_cards.erase(
        std::remove_if(
            deck_cards.begin(),
            deck_cards.end(),
            [id_to_remove](Card c){return c.getId() == id_to_remove;}
        )
    );
    return;
}

void Deck::removeCards(std::vector<Card> cards){
    for (auto &card: cards)
        removeCard(card);
    return;
}

Card Deck::drawCard(){
    if (deck_cards.size() < 1)
        throw std::invalid_argument("Cannot draw from empty deck.");

    Card drawed = deck_cards.back();
    deck_cards.pop_back();
    return drawed;
}

std::vector<Card> Deck::drawCards(int n_cards){
    std::vector<Card> cards_drawed;
    for (int i=0; i<n_cards; i++){
        cards_drawed.push_back(drawCard());
    }
    return cards_drawed;
}
