#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "card.h"
#include "player.h"

using namespace std;

Player::Player()
{
    cardValues = {
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"10", 10},
        {"J", 10},
        {"Q", 10},
        {"K", 10},
        {"A", 11},
    };
    cardsHeld = {};
}

Player::Player(float cash)
{
    currentBet = 0;
    cout << "Please enter your name: ";
    cin >> name;
    this->cash = cash;
};

// Returns the player's name
string Player::getName()
{
    return name;
};

// returns the cash held by the player
float Player::getCash()
{
    return cash;
};

// Adds card to cardsHeld
void Player::dealCard(Card card)
{
    cardsHeld.push_back(card);
    updateHandValue();
};

// Add vector containing multiple cards to cardsHeld
void Player::dealCards(vector<Card> cards)
{
    cardsHeld.insert(cardsHeld.end(), cards.begin(), cards.end());
    updateHandValue();
};

void Player::clearHand()
{
    cardsHeld.clear();
    updateHandValue();
};

// Shows the cards
string Player::showCardsShort()
{
    string cds = "";
    for (Card c : cardsHeld)
    {
        cds += c.showValueShort() + " ";
    }
    cds.pop_back();
    return cds;
};

// Evaluates the player's hand
void Player::updateHandValue()
{
    handValue = 0;
    int aceCount = 0;
    for (Card c : cardsHeld)
    {
        cout << c.showValueShort();
        cout << cardValues["10"];

        if (c.showValueShort() == "A")
            aceCount++;
        handValue += cardValues[c.showValueShort()];
    }

    // If we have aces and we are bust can set ace value to 1 instead of 11
    for (int i = 0; i < aceCount && handValue > 21; i++)
    {
        handValue -= 10;
    }

    cout << "Hand value: " << handValue;
};

int Player::getHandValue()
{
    return handValue;
};

void Player::makeBet()
{
    float betAmount = -1;
    while (betAmount == -1)
    {
        float newBet;
        cout << "Please enter a bet amount ";
        cin >> newBet;
        if (cin.fail())
        {
            cout << "Error: Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            if (newBet <= 0)
            {
                cout << "Please enter a bet amount greater than 0.\n";
            }
            else if (newBet > cash)
            {
                cout << "Not enough cash to make this bet. You currently have " << cash << " cash.\n";
            }
            else
            {
                betAmount = newBet;
            }
        }
    }
    cout << name << " bet " << betAmount << "\n";
    currentBet += betAmount;
};

void Player::win()
{
    cash += currentBet;
    currentBet = 0;
};

void Player::lose()
{
    cash -= currentBet;
    currentBet = 0;
}