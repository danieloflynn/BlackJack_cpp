#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <string>
#include <vector>

#include "Dealer.h"
#include "player.h"
#include "deck.h"

class BlackJack
{
private:
    int numPlayers;
    std::vector<Player> players;
    Dealer dealer;
    Deck deck;

public:
    BlackJack();
    void play();
    std::string getPlayerNames();
    void takeTurn(Player *player);
    void hit(Player *player);
    char determineResult(int playerHand, int dealerHand);
};

#endif