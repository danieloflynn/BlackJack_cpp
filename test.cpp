#include <iostream>
#include <vector>
#include <string>

#include "card.h"
#include "deck.h"
#include "player.h"
#include "BlackJack.h"

using namespace std;

int main()
{
    int a = 2;
    // float b = 10;

    BlackJack B;
    cout << B.getPlayerNames();
    B.play();
    return 0;
}
