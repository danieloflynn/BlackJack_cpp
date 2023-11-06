#include <vector>

#include "Dealer.h"

using namespace std;

Dealer::Dealer() : Player()
{
    cardsHeld = {};
    name = "Dealer";
    cash = 10000;
};
