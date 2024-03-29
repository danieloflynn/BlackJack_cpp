#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "card.h"
#include "Hand.h"

class Player
{
protected:
    std::string name;
    float cash;
    std::vector<Card> cardsHeld;
    std::vector<Hand> hands;
    bool isSoft;
    std::vector<char> getOptions(int handNo = 0);
    static std::unordered_map<std::string, int> cardValues;

private:
public:
    float currentBet;
    Player();
    Player(float cash);
    std::string getName();
    float getCash();
    int numHands();
    void addHand();
    void dealCard(Card card, int handNo = 0);
    void dealCards(std::vector<Card> cards, int handNo = 0);
    void clearHand(int handNo);
    void clearHands();
    void split(int handNo, std::vector<Card> cards);
    std::string showCardsShort(int handNo = 0);
    int getHandValue(int handNo = 0);
    bool isBlackJack(int handNo = 0);
    void makeBet(int handNo = 0);
    bool canSplit(int handNo = 0);
    bool canSurrender(int handNo = 0);
    virtual char makeDecision(int handNo = 0);
    void newTurn();
    void win(int handNo = 0);
    void lose(int handNo = 0);
    void surrender(int handNo = 0);
    void push(int handNo = 0);
    void blackJack(int handNo = 0);
};

#endif