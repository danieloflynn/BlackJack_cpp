#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <string>
#include "card.h"

class Deck
{
private:
    std::vector<Card> cards;
    std::vector<Card> originalCards;

public:
    Deck();
    Card drawCard();
    std::vector<Card> drawCards(int numCards);
    void revealCards();
    void shuffleCards();
    void newDeck();
    void resetDeck();
};

#endif