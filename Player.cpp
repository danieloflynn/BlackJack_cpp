#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

#include "card.h"
#include "player.h"

using namespace std;

Player::Player()
{
}

Player::Player(float cash)
{
    handValue = 0;
    cardsHeld = {};
    Player();
    currentBet = 0;
    cout << "Please enter your name: ";
    cin >> name;
    this->cash = cash;
};

std::unordered_map<std::string, int> Player::cardValues = {
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

        if (c.showValueShort() == "A")
            aceCount++;
        handValue += cardValues.at(c.showValueShort());
    }

    // If we have aces and we are bust can set ace value to 1 instead of 11
    for (int i = 0; i < aceCount && handValue > 21; i++)
    {
        handValue -= 10;
    }
};

int Player::getHandValue()
{
    return this->handValue;
};

bool Player::isBlackJack()
{
    if (handValue == 21 && cardsHeld.size() == 2)
    {
        return true;
    }
    return false;
}

void Player::makeBet()
{
    float betAmount = -1;
    while (betAmount == -1)
    {
        float newBet;
        cout << name << " please enter a bet amount: ";
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

void Player::getOptions(){
    // TODO: Add options for the player to have.
};

char Player::makeDecision()
{
    // getoptions();
    cout << "type h to hit, s to stand: ";
    char response;
    cin >> response;
    return response;
};

void Player::newTurn(){

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

void Player::push()
{
    currentBet = 0;
}

void Player::blackJack()
{
    cash += currentBet / 2;
    currentBet = 0;
}