#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

#include "card.h"
#include "player.h"
#include "Hand.h"

using namespace std;

Player::Player()
{
}

Player::Player(float cash)
{
    hands = {};
    handValue = 0;
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

int Player::numHands()
{
    return hands.size();
}

// Adds hand, used for splits
void Player::addHand()
{
    Hand h;
    hands.push_back(h);
}

// Adds card to cardsHeld
void Player::dealCard(Card card, int handNo)
{
    if (handNo > hands.size() - 1)
    {
        throw runtime_error("Error: hand index out of bounds");
    }
    hands[handNo].dealCard(card);
};

// Add vector containing multiple cards to cardsHeld
void Player::dealCards(vector<Card> cards, int handNo)
{
    if (handNo > hands.size() - 1)
    {
        throw runtime_error("Error: hand index out of bounds");
    }
    hands[handNo].dealCards(cards);
};

// Shows the cards
string Player::showCardsShort(int handNo)
{
    string cds = hands[handNo].showCardsShort();
    return cds;
};

void Player::clearHands()
{
    Hand h;
    hands = {h};
};

void Player::split(int handNo, vector<Card> cards)
{
    Card c = hands[handNo].removeCard();
    addHand();
    int hand2No = hands.size() - 1;
    cout << name << " drew " << cards[0].showValueShort() << "\n";
    hands[handNo].dealCard(cards[0]);

    float betAmount = hands[handNo].currentBet;
    cout << betAmount << " bet on hand " << hand2No << "\n";
    hands[hand2No].dealCard(c);
    hands[hand2No].dealCard(cards[1]);
    hands[hand2No].makeBet(betAmount);
}

int Player::getHandValue(int handNo)
{
    return hands[handNo].getHandValue();
};

bool Player::isBlackJack(int handNo)
{
    return hands[handNo].isBlackJack();
}

void Player::makeBet(int handNo)
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
    hands[handNo].makeBet(betAmount);
    cash -= betAmount;
};

bool Player::canSplit(int handNo)
{
    return hands[handNo].canSplit() && cash >= hands[handNo].currentBet;
}

bool Player::canSurrender(int handNo)
{
    return hands[handNo].canSurrender();
}

vector<char> Player::getOptions(int handNo)
{
    string outText = "type h to hit, s to stand";
    vector<char> options = {'h', 's'};
    if (canSplit(handNo))
    {
        outText += ", x to split";
        options.push_back('x');
    }
    if (canSurrender(handNo))
    {
        outText += ", f to surrender";
        options.push_back('f');
    }
    outText += ": ";
    cout << outText;
    return options;
};

char Player::makeDecision(int handNo)
{
    vector<char> options = getOptions(handNo);
    char response;
    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> response;
        if (cin.fail())
        {
            cout << "Error: value not recognised.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (find(options.begin(), options.end(), response) == options.end())
        {
            cout << "Error: Please enter a valid value \n";
        }
    } while (find(options.begin(), options.end(), response) == options.end());
    return response;
};

void Player::newTurn(){

};

void Player::win(int handNo)
{
    cash += 2 * hands[handNo].currentBet;
};

void Player::lose(int handNo)
{
    // Do nothing for now
}

void Player::push(int handNo)
{
    cash += hands[handNo].currentBet;
}

void Player::blackJack(int handNo)
{
    cash += 3 * hands[handNo].currentBet / 2;
}