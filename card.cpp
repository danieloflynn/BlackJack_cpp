#include <iostream>
#include <vector>
#include <string>
#include "card.h"

using namespace std;

Card::Card(int suitidx, int valueidx)
{
    // These should be static
    suits = {"Spades", "Hearts", "Diamonds", "Clubs"};
    shortSuits = {"S", "H", "D", "C"};
    values = {"", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    shortValues = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    this->suitidx = suitidx;
    this->valueidx = valueidx;
    suit = suits[suitidx];
    value = values[valueidx];
}

string Card::getValue()
{
    return value;
}

string Card::getSuit()
{
    return suit;
}

string Card::get()
{
    return getValue() + " of " + getSuit();
}

string Card::showValueShort()
{
    return shortValues[valueidx];
}

char Card::showSuitShort()
{
    return suit[0];
}

int Card::getValueidx()
{
    return valueidx;
}

int Card::getSuitidx()
{
    return suitidx;
}
