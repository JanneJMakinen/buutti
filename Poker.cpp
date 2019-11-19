// -------------------------------------
// Superpoker game
// Janne J. Mäkinen (c)
// -------------------------------------

// Compile with this
// g++ -std=c++17 Poker.cpp Card.cpp Deck.cpp VirtualScreen.cpp -o superpoker

#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <random>
#include <array>
#include "Card.hpp"
#include "Deck.hpp"
#include "VirtualScreen.hpp"

int main() {
 
    // make a virtual screen for cards
    VirtualScreen<char, CARD_SIZE_X, (((CARD_SIZE_Y+4)*NUMBER_OF_CARDS)+4)> virtualScreen;
    
    // show logo and the instructions
    utility_functions::showHouseRules();

    // make a deck, suffle and deal cards from that to the player and to house
    Deck originalDeck;
    originalDeck.makeAfullDeck();
    originalDeck.suffle();
    Deck playerHand;
    Deck houseHand;
    for (int i=0; i<NUMBER_OF_CARDS; ++i) {
        Card c = originalDeck.getCardFromDeck();
        playerHand.addACard(c);
    }
    for (int i=0; i<NUMBER_OF_CARDS; ++i) {
        Card c = originalDeck.getCardFromDeck();
        houseHand.addACard(c);
    }

    // show the cards
    std::cout << "Here are your cards! \n";
    initialize(virtualScreen, CARD_SIZE_X, (((CARD_SIZE_Y+4)*NUMBER_OF_CARDS)+4));
    for(int i=0; i<NUMBER_OF_CARDS; ++i) {
        addDeck(virtualScreen, playerHand.getCard(i), CARD_SIZE_Y, CARD_SIZE_X*(i+1)); 
    }
    show(virtualScreen, CARD_SIZE_X, (((CARD_SIZE_Y+4)*NUMBER_OF_CARDS)+4));
    
    // ask any change
    std::cout << "Wich ones you want to change? Enter by x and o wich ones you choose to change.\n";
    std::cout << "Example xoxxo means you want to change the second and fifth card. Make your move.\n";
    std::string inputString;
    std::cin >> inputString;
    for(int i=0; i<inputString.length(); ++i) {
        if(inputString.at(i) == 'o') {
                    Card c = originalDeck.getCardFromDeck();
                    playerHand.changeCard(i, c);
        }
    }

    std::cout << "Here are your new cards! \n";
    initialize(virtualScreen, CARD_SIZE_X, (((CARD_SIZE_Y+4)*NUMBER_OF_CARDS)+4));
    for(int i=0; i<NUMBER_OF_CARDS; ++i) {
        addDeck(virtualScreen, playerHand.getCard(i), CARD_SIZE_Y, CARD_SIZE_X*(i+1)); 
    }
    show(virtualScreen, CARD_SIZE_X, (((CARD_SIZE_Y+4)*NUMBER_OF_CARDS)+4));

    std::cout << "Here are house cards! \n";
    initialize(virtualScreen, 7, (((CARD_SIZE_Y+4)*NUMBER_OF_CARDS)+4));
    for(int i=0; i<NUMBER_OF_CARDS; ++i) {
        addDeck(virtualScreen, houseHand.getCard(i), CARD_SIZE_Y, CARD_SIZE_X*(i+1)); 
    }
    show(virtualScreen, CARD_SIZE_X, (((CARD_SIZE_Y+4)*NUMBER_OF_CARDS)+4));

    // calculate values and show the winner
    std::cout << "Player has: ";
    int playerResult = playerHand.calculateValue();
    std::cout << "House has: ";
    int houseResult = houseHand.calculateValue();
    if (playerResult>houseResult) {
        std::cout << "Player wins!\n";
    }
    else if (houseResult>playerResult) {
        std::cout << "House wins!\n";
    }
    else if (playerResult == houseResult) {
        std::cout << "Game was a tie.\n";
    }

    // testing all different poker results
    // just remove the line comment, compile and run
    //utility_functions::runTests();
}

// todo 
// simpler virtualscreen, maybe a struct is a better solution
// testing to own class
// card calculations are not perfect, for ex pair doesn't calculate the value of the pair

