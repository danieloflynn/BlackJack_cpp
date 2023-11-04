#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <string>

class Card
{

public:
    Card(int suitidx, int valueidx);
    std::vector<std::string> suits;
    std::vector<std::string> shortSuits;
    std::vector<std::string> values;
    std::vector<std::string> shortValues;
    int suitidx;
    int valueidx;
    std::string suit;
    std::string value;
    std::string getValue();
    std::string getSuit();
    std::string get();
    std::string showValueShort();
    char showSuitShort();
    int getValueidx();
    int getSuitidx();
};

#endif
