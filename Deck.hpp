// -------------------------------------
// Deck related functions
// -------------------------------------

#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <random>
#include <algorithm>
#include <array>
#include <cmath>

#include "Card.hpp"

class Deck 
{
    public:
        void makeAfullDeck ();
        Card getCardFromDeck();
        void addACard(Card c);
        void showData();
        void printCards(); // old aka deprecated
        void suffle();
        void sortByValue();
        void sortBySuit();
        int calculateValue();
        Card getCard(int value);
        void changeCard(int i, Card c);
    private:
        std::vector<Card> cards;
        int fullDeckCounter = 0;
        static bool compareCardsByValue(Card a, Card b);
        static bool compareCardsBySuit(Card a, Card b);
};

#endif