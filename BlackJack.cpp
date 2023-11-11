#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

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
    dealer.clearHands();
    dealer.dealCards(deck.drawCards(2));

    // Deal cards to each of the players
    for (Player &player : players)
    {
        player.clearHands();
        player.makeBet();
        player.dealCards(deck.drawCards(2));
    }
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Cards have been dealt \n";
    this_thread::sleep_for(chrono::seconds(1));

    // Show the dealer cards.
    cout << "Dealer is showing " << dealer.oneCard() << "\n";
    for (Player &player : players)
    {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "It's " << player.getName() << "'s turn.\n";
        this_thread::sleep_for(chrono::seconds(1));

        cout << "You have " << player.showCardsShort() << ", value " << player.getHandValue() << "\n";
        takeTurn(&player);
    }

    // Dealer's turn

    cout << "It's the dealer's turn.\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "You have " << dealer.showCardsShort() << ", value " << dealer.getHandValue() << "\n";
    this_thread::sleep_for(chrono::seconds(1));
    takeTurn(&dealer);

    // Determine winners
    int dealerHand = dealer.getHandValue();
    for (Player &player : players)
    {

        int playerHand = player.getHandValue();
        char result = determineResult(playerHand, dealerHand);

        switch (result)
        {
        case 'w':
            cout << player.getName() << " wins " << player.currentBet << "\n";
            player.win();
            break;
        case 'l':
            cout << player.getName() << " loses \n";
            player.lose();
            break;
        case 'p':
            cout << player.getName() << " draws \n";
            player.push();
            break;
        case 'b':
            cout << player.getName() << ": BlackJack! \n";
            player.blackJack();
            break;

        default:
            break;
        }

        cout << player.getName() << " has " << player.getCash() << " cash\n";
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
    bool finished = false;
    string name = player->getName();
    while (player->getHandValue() < 21 && !finished)
    {
        // Decision goes out to the player object, allowing for option to add AI players
        char decision = player->makeDecision();
        switch (decision)
        {
        case 'h':
            hit(player);
            this_thread::sleep_for(chrono::seconds(1));
            cout << "You have " << player->showCardsShort() << ", value " << player->getHandValue() << "\n";
            /* code */
            break;
        case 's':
            finished = true;
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
    Card c = deck.drawCard();
    this_thread::sleep_for(chrono::seconds(1));
    cout << player->getName() << " drew " << c.showValueShort() << "\n";
    player->dealCard(c);
};

char BlackJack::determineResult(int playerHand, int dealerHand)
{
    // If player has gone bust, player loses (even if dealer is bust)
    if (playerHand > 21)
    {
        return 'l'; // lose
    }
    else if (playerHand == dealerHand)
    {
        return 'p'; // push
    }
    else if (playerHand == 21)
    {
        return 'b'; // BlackJack
    }
    else if (dealerHand > 21)
    {
        return 'w'; // win
    }
    else if (playerHand > dealerHand)
    {
        return 'w'; // win
    }
    else
    {
        return 'l'; // player hand must be less than dealer hand, lose
    }
};