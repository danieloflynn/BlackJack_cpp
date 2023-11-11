#include <vector>
#include <thread>
#include <chrono>

#include "Dealer.h"

using namespace std;

Dealer::Dealer() : Player()
{
    hands = {};
    name = "Dealer";
    cash = 10000;
};

string Dealer::oneCard()
{
    if (hands[0].cardsHeld.size() == 0)
    {
        return NULL;
    }
    return hands[0].cardsHeld[0].showValueShort();
}

char Dealer::makeDecision(int handNo)
{
    if (hands[0].handValue < 17)
    {
        cout << "Dealer hits\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 'h';
    }

    cout << "Dealer stands \n";
    this_thread::sleep_for(chrono::seconds(1));
    return 's';
};