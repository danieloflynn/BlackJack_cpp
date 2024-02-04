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
    // // Initialize the players
    // Player player(1000);
    // // Deck deck;
    // Card c(1, 1);
    // Card d(1, 3);
    // Card e(2, 4);
    // player.clearHands();
    // player.dealCard(c);
    // player.dealCard(c);
    // player.makeDecision(0);
    // player.split(0, {d, e});
    // cout << player.showCardsShort(0) << "\n";
    // cout << player.showCardsShort(1) << "\n";

    // string name = player.getName();
    // cout << "It's " << name << "'s turn.\n";
    // string s = player.showCardsShort();
    // int i = player.getHandValue();
    // cout << "You have" << player.showCardsShort() << ", value " << player.getHandValue() << "\n";

    BlackJack B;
    B.play();

    return 0;
}
