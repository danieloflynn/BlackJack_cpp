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
    // Show the dealer cards.
    cout << dealer.showCardsShort() << "\n";
    for (Player &player : players)
    {
        takeTurn(&player);
    }

    // Dealer's turn
    bool stand = false;
    while (dealer.getHandValue() < 21 && !stand)
    {
        cout << "It's the dealer's turn.\n";
        cout << "You have" << dealer.showCardsShort() << ", value " << dealer.getHandValue() << "\n";
        // Decision goes out to the dealer object, allowing for option to add AI dealers
        char decision = dealer.makeDecision();
        switch (decision)
        {
        case 'h':
            hit(&dealer);
            /* code */
            break;
        case 's':
            stand = true;
            break;
        default:
            cout << "Error: please enter a valid char\n";
            break;
        }
    }

    if (dealer.getHandValue() > 21)
    {
        cout << "Dealer has gone bust \n";
    }

    cout << "You're done";
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
};

// Takes care of the turn logic
void BlackJack::takeTurn(Player *player)
{
    bool stand = false;
    string name = player->getName();
    while (player->getHandValue() < 21 && !stand)
    {
        cout << "It's " << name << "'s turn.\n";
        cout << "You have" << player->showCardsShort() << ", value " << player->getHandValue() << "\n";
        // Decision goes out to the player object, allowing for option to add AI players
        char decision = player->makeDecision();
        switch (decision)
        {
        case 'h':
            hit(player);
            /* code */
            break;
        case 's':
            stand = true;
            break;
        default:
            cout << "Error: please enter a valid char\n";
            break;
        }
    }

    if (player->getHandValue() > 21)
    {
        cout << name << " has gone bust \n";
    }
};

// Hit the player with another card
void BlackJack::hit(Player *player)
{
    player->dealCard(deck.drawCard());
};