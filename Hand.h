#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "card.h"

class Hand
{
private:
    static std::unordered_map<std::string, int> cardValues;

public:
    int handValue;
    Hand();
    std::vector<Card> cardsHeld;
    float currentBet;

    void dealCard(Card card);
    void dealCards(std::vector<Card> cards);
    Card removeCard();
    void clearHand();
    std::string showCardsShort();
    void updateHandValue();
    int getHandValue();
    bool isBlackJack();
    void makeBet(float bet);
    bool canSplit();
    bool canSurrender();
};

#endif