// -------------------------------------
// Card related functions
// -------------------------------------

#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

constexpr int CARD_SIZE_X = 7;
constexpr int CARD_SIZE_Y = 5;
constexpr int NUMBER_OF_CARDS = 5;

class Card
{
    public:
        void showData();
        void printCard(); // old aka deprecated
        void makeRandomCard(); // old aka deprecated
        int getValue();
        int getSuit();
        void setValue(int cardValue);
        void setSuit(int cardSuit);

    private:
        std::string name;
        int value, suit;
};

#endif
