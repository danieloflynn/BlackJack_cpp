#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "card.h"
#include "deck.h"
#include "player.h"
#include "BlackJack.h"

using namespace std;

int main()
{
    // Initialize the players

    // Player player(1000);
    // Deck deck;
    // player.dealCards(deck.drawCards(2));

    // string name = player.getName();
    // cout << "It's " << name << "'s turn.\n";
    // string s = player.showCardsShort();
    // int i = player.getHandValue();
    // cout << "You have" << player.showCardsShort() << ", value " << player.getHandValue() << "\n";

    BlackJack B;
    B.play();

    return 0;
}
