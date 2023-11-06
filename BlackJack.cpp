#include <iostream>
#include <string>
#include <vector>

#include "BlackJack.h"
#include "Dealer.h"
#include "player.h"
#include "deck.h"

using namespace std;

BlackJack::BlackJack()
{
    // Ask how many players you want to play
    cout << "Please enter the number of players: ";
    cin >> numPlayers;
    // Need to change this to error handling
    if (numPlayers < 1)
    {
        cout << "Error: need at least 1 player to play Black Jack";
    }

    // Initialize the players
    players = {};
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Player " << i + 1 << " ";
        Player p(10000);
        players.push_back(p);
    }

    Deck deck;
};

// This will be where the game is started
void BlackJack::play()
{
    // Deal cards to the dealer
    dealer.clearHand();
    dealer.dealCards(deck.drawCards(2));

    // Deal cards to each of the players
    for (Player &player : players)
    {
        player.clearHand();
        player.makeBet();
        player.dealCards(deck.drawCards(2));
    }

    cout << dealer.showCardsShort() << "\n";
    for (Player &player : players)
    {
        string name = player.getName();
        cout << "It's " << name << "'s turn.\n";
        cout << "You have" << player.showCardsShort() << ", value " << player.getHandValue() << "\n";
        player.makeDecision();
    }
};

// Get a list of player names
string BlackJack::getPlayerNames()
{
    string playerNames = "";
    for (Player p : players)
    {
        playerNames += p.getName() + "\n";
    }
    return playerNames;
}