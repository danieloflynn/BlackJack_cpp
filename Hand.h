#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "card.h"

class Hand
{
public:
    Hand();
    int handValue;
    std::vector<Card> cardsHeld;
    float currentBet;
    static std::unordered_map<std::string, int> cardValues;

    void dealCard(Card card);
    void dealCards(std::vector<Card> cards);
    void clearHand();
    std::string showCardsShort();
    void updateHandValue();
    int getHandValue();
    bool isBlackJack();
    void makeBet(float bet);
    bool canSplit();
    void getOptions();
};

#endif