#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "card.h"

class Player
{
protected:
    std::string name;
    float cash;

private:
    int handValue;
    std::vector<Card> cardsHeld;
    std::unordered_map<std::string, int> cardValues;

public:
    Player();
    Player(float cash);
    std::string getName();
    float getCash();
    void dealCard(Card card);
    void dealCards(std::vector<Card> cards);
    void clearHand();
    std::string showCardsShort();
    void updateHandValue();
    int getHandValue();
    void win();
    void lose();
};

#endif