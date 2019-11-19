// -------------------------------------
// Card related functions
// -------------------------------------

#include <iostream>
#include <string>
#include "Card.hpp"

void Card::showData()
{
    std::cout << "Name: " << name << " ";
    std::cout << "Value: " << value << " ";
    std::cout << "Suit: " << suit << " ";
}

void Card::printCard() // old style
{
    std::cout << " _____ " << "\n";
    if (value < 10) 
        std::cout << "|" << value << "    |" << "\n";
    else 
        std::cout << "|" << value << "   |" << "\n";
    if (suit == 0)
        std::cout << "|  &  |" << "\n";
    else if (suit == 1)
        std::cout << "|  ^  |" << "\n";
    else if (suit == 2)
        std::cout << "|  v  |" << "\n";
    else if (suit == 3)
        std::cout << "|  o  |" << "\n";
    std::cout << "|     |" << "\n";
    std::cout << "|_____|" << "\n";
}       
        
void Card::makeRandomCard() // old style
{
    value = rand()%12 + 2;
    suit = rand()%4 + 1;
    if (suit == 1)
        name = "Club";
    else if (suit == 2)
        name = "Spades";
    else if (suit == 3)
        name = "Hearts";
    else if (suit == 4)
        name = "Diamond";
}

int Card::getValue()
{
    return value;
}

int Card::getSuit()
{
    return suit;
}
        
void Card::setValue(int cardValue)
{
    value = cardValue;
}
        
void Card::setSuit(int cardSuit)
{
    suit = cardSuit;
}
