#include <iostream>
#include <string>
#include <vector>

#include "BlackJack.h"
#include "player.h"
#include "deck.h"

using namespace std;

BlackJack::BlackJack()
{
    // Ask how many players you want to play
    cout << "Please enter the number of players: ";
    cin >> numPlayers;
    // Need to change this to error handling
    if (numPlayers < 2)
    {
        cout << "Error: need at least 2 players to play Black Jack";
    }

    // Initialize the players
    players = {};
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Player " << i + 1 << " ";
        players.push_back(new Player(3000));
    }
};

// This will be where the game is started
void BlackJack::play(){

};

// Get a list of player names
string BlackJack::getPlayerNames()
{
    string playerNames = "";
    for (Player *p : players)
    {
        playerNames += p->getName() + "\n";
    }
    return playerNames;
}