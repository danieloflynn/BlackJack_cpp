#include <vector>
#include <thread>
#include <chrono>

#include "Dealer.h"

using namespace std;

Dealer::Dealer() : Player()
{
    cardsHeld = {};
    name = "Dealer";
    cash = 10000;
};

string Dealer::oneCard()
{
    if (cardsHeld.size() == 0)
    {
        return NULL;
    }
    return cardsHeld[0].showValueShort();
}

char Dealer::makeDecision()
{
    if (handValue < 17)
    {
        cout << "Dealer hits\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 'h';
    }

    cout << "Dealer stands \n";
    this_thread::sleep_for(chrono::seconds(1));
    return 's';
};