#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <string>
#include <vector>

#include "player.h"

class Dealer : public Player
{
private:
    std::unordered_map<std::string, int> cardValues;

public:
    Dealer();
};

#endif