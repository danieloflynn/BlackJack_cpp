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
public:
    int handValue;
    std::vector<Card> cardsHeld;

    float currentBet;
    bool isSoft;
    static std::unordered_map<std::string, int> cardValues;
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
    bool isBlackJack();
    void makeBet();
    void getOptions();
    char makeDecision();
    void newTurn();
    void win();
    void lose();
    void push();
    void blackJack();
};

#endif