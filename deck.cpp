#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

#include "card.h"
#include "deck.h"

using namespace std;

Deck::Deck()
{
    newDeck();
};

// Draws card
Card Deck::drawCard()
{
    Card c = cards.back();
    cards.pop_back();
    return c;
};

vector<Card> Deck::drawCards(int numCards)
{
    vector<Card> cds;
    for (int i = 0; i < numCards; i++)
    {
        cds.push_back(drawCard());
    }

    return cds;
};

void Deck::revealCards()
{
    for (auto c : cards)
        cout << c.get() << "\n";
};

// Shuffles cards
void Deck::shuffleCards()
{
    random_device r = random_device{};
    default_random_engine rng = default_random_engine{r()};
    shuffle(begin(cards), end(cards), rng);
};

// Make a new deck
void Deck::newDeck()
{
    // Iterate through the suits
    for (int i = 0; i <= 3; i++)
    {
        // Iterate through the values
        for (int j = 1; j <= 13; j++)
        {
            Card c(i, j);
            cards.push_back(c);
            originalCards = cards;
        }
    }

    shuffleCards();
};

// Reset the deck back to original
void Deck::resetDeck()
{
    cards = originalCards;
};