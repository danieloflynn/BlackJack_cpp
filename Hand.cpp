#include <iostream>
#include <string>
#include <vector>

#include "Hand.h"
#include "card.h"

using namespace std;

Hand::Hand()
{
    handValue = 0;
    cardsHeld = {};
    currentBet = 0;
};

std::unordered_map<std::string, int> Hand::cardValues = {
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"10", 10},
    {"J", 10},
    {"Q", 10},
    {"K", 10},
    {"A", 11},
};

// Adds card to cardsHeld
void Hand::dealCard(Card card)
{
    cardsHeld.push_back(card);
    updateHandValue();
};

// Add vector containing multiple cards to cardsHeld
void Hand::dealCards(vector<Card> cards)
{
    cardsHeld.insert(cardsHeld.end(), cards.begin(), cards.end());
    updateHandValue();
};

Card Hand::removeCard()
{
    Card c = cardsHeld.back();
    cardsHeld.pop_back();
    return c;
}

void Hand::clearHand()
{
    cardsHeld.clear();
    updateHandValue();
};

// Shows the cards
string Hand::showCardsShort()
{
    string cds = "";
    for (Card c : cardsHeld)
    {
        cds += c.showValueShort() + " ";
    }
    cds.pop_back();
    return cds;
};

// Evaluates the player's hand
void Hand::updateHandValue()
{
    handValue = 0;
    int aceCount = 0;
    for (Card c : cardsHeld)
    {

        if (c.showValueShort() == "A")
            aceCount++;
        handValue += cardValues.at(c.showValueShort());
    }

    // If we have aces and we are bust can set ace value to 1 instead of 11
    for (int i = 0; i < aceCount && handValue > 21; i++)
    {
        handValue -= 10;
    }
};

// Return hand value
int Hand::getHandValue()
{
    return this->handValue;
};

bool Hand::isBlackJack()
{
    if (handValue == 21 && cardsHeld.size() == 2)
    {
        return true;
    }
    return false;
}

void Hand::makeBet(float bet)
{
    currentBet += bet;
}

bool Hand::canSplit()
{
    if (cardsHeld.size() == 2 && cardsHeld[0].getValue() == cardsHeld[1].getValue())
    {
        return true;
    }
    return false;
}

bool Hand::canSurrender()
{
    return cardsHeld.size() == 2;
}