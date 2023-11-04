#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "deck.h"

class BlackJack
{
private:
    int numPlayers;
    std::vector<Player *> players;
    Deck deck;

public:
    BlackJack();
    void play();
    std::string getPlayerNames();
    void hit();
};

#endif