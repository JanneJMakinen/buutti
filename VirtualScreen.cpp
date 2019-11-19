// -------------------------------------
// Virtual screen related functions
// -------------------------------------

#include <iostream>
#include <array>
#include "Card.hpp"
#include "Deck.hpp"
#include "VirtualScreen.hpp"

void utility_functions::printLogo()
{

    // http://patorjk.com/software/taag/#p=display&f=Soft&t=SuperPoker
                                                   
    std::cout << " ,---.                               ,------.        ,--.                   \n";
    std::cout << "'   .-' ,--.,--. ,---.  ,---. ,--.--.|  .--. ' ,---. |  |,-. ,---. ,--.--.  \n";
    std::cout << "`.  `-. |  ||  || .-. || .-. :|  .--'|  '--' || .-. ||     /| .-. :|  .--'  \n";
    std::cout << ".-'    |'  ''  '| '-' '|   --.|  |   |  | --' ' '-' '|     ||   --.|  |     \n";
    std::cout << "`-----'  `----' |  |-'  `----'`--'   `--'      `---' `--'`--'`----'`--'     \n";
    std::cout << "                `--'                                                        \n";
    std::cout << "\n";
}

void utility_functions::showHouseRules()
{
    system("clear");  //doesn't work for linux
    utility_functions::printLogo();
    std::cout << "--------------------------------------------------------------------------------------\n";
    std::cout << "Welcome to the house of SuperPoker. Regular physics rules may not apply. But behave! \n";
    std::cout << "You will have five cards. You may change any number of those cards. \n";
    std::cout << "Press ENTER to start the game.\n";
    std::cout << "--------------------------------------------------------------------------------------\n";
    std::string userInput;
    std::getline(std::cin, userInput);
}

void utility_functions::runTests()
{
    Card testCard1, testCard2, testCard3, testCard4, testCard5;
    Deck originalTestDeck;
    originalTestDeck.makeAfullDeck();   // making a deck of 52 cards
    originalTestDeck.suffle();
    Deck testHand;

    for (int i=0; i<NUMBER_OF_CARDS; ++i) {
        Card c = originalTestDeck.getCardFromDeck();
        testHand.addACard(c);
    }
    
    // Pair - works
    std::cout << "------------------------------" << "\n";
    std::cout << "- Testing -> A PAIR          -" << "\n";
    std::cout << "------------------------------" << "\n";    
    testCard1.setValue(1);
    testCard1.setSuit(0);
    testCard2.setValue(1);
    testCard2.setSuit(1);
    testCard3.setValue(10);
    testCard3.setSuit(2);
    testCard4.setValue(4);
    testCard4.setSuit(3);
    testCard5.setValue(5);
    testCard5.setSuit(1);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();

    // Pair - works
    std::cout << "------------------------------" << "\n";
    std::cout << "- Testing -> TWO PAIR        -" << "\n";
    std::cout << "------------------------------" << "\n";    
    testCard1.setValue(1);
    testCard1.setSuit(0);
    testCard2.setValue(1);
    testCard2.setSuit(1);
    testCard3.setValue(10);
    testCard3.setSuit(2);
    testCard4.setValue(10);
    testCard4.setSuit(3);
    testCard5.setValue(5);
    testCard5.setSuit(1);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();


    // Three same value - works
    std::cout << "-----------------------------" << "\n";
    std::cout << "- Testing -> THREE OF SAME  -" << "\n";
    std::cout << "-----------------------------" << "\n";    
    testCard1.setValue(1);
    testCard1.setSuit(0);
    testCard2.setValue(1);
    testCard2.setSuit(1);
    testCard3.setValue(1);
    testCard3.setSuit(2);
    testCard4.setValue(6);
    testCard4.setSuit(3);
    testCard5.setValue(7);
    testCard5.setSuit(1);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();

    // Four same value - works
    std::cout << "-----------------------------" << "\n";
    std::cout << "- Testing -> FOUR OF SAME   -" << "\n";
    std::cout << "-----------------------------" << "\n";  
    testCard1.setValue(1);
    testCard1.setSuit(0);
    testCard2.setValue(1);
    testCard2.setSuit(1);
    testCard3.setValue(1);
    testCard3.setSuit(2);
    testCard4.setValue(1);
    testCard4.setSuit(3);
    testCard5.setValue(5);
    testCard5.setSuit(1);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();
    
    // Flush- works
    std::cout << "-----------------------------" << "\n";
    std::cout << "- Testing -> FLUSH          -" << "\n";
    std::cout << "-----------------------------" << "\n";  
    testCard1.setValue(1);
    testCard1.setSuit(0);
    testCard2.setValue(2);
    testCard2.setSuit(0);
    testCard3.setValue(3);
    testCard3.setSuit(0);
    testCard4.setValue(4);
    testCard4.setSuit(0);
    testCard5.setValue(6);
    testCard5.setSuit(0);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();

    // Straight flush - works
    std::cout << "-----------------------------" << "\n";
    std::cout << "- Testing -> STRAIGHT FLUSH -" << "\n";
    std::cout << "-----------------------------" << "\n";  
    testCard1.setValue(2);
    testCard1.setSuit(0);
    testCard2.setValue(3);
    testCard2.setSuit(0);
    testCard3.setValue(4);
    testCard3.setSuit(0);
    testCard4.setValue(5);
    testCard4.setSuit(0);
    testCard5.setValue(6);
    testCard5.setSuit(0);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();

    // Royal flush - works
    std::cout << "-----------------------------" << "\n";
    std::cout << "- Testing -> ROYAL FLUSH    -" << "\n";
    std::cout << "-----------------------------" << "\n";  
    testCard1.setValue(13);
    testCard1.setSuit(0);
    testCard2.setValue(12);
    testCard2.setSuit(0);
    testCard3.setValue(11);
    testCard3.setSuit(0);
    testCard4.setValue(10);
    testCard4.setSuit(0);
    testCard5.setValue(1);
    testCard5.setSuit(0);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();

    // Full house - works
    std::cout << "-----------------------------" << "\n";
    std::cout << "- Testing -> FULL HOUSE     -" << "\n";
    std::cout << "-----------------------------" << "\n";  
    testCard1.setValue(12);
    testCard1.setSuit(0);
    testCard2.setValue(12);
    testCard2.setSuit(1);
    testCard3.setValue(10);
    testCard3.setSuit(1);
    testCard4.setValue(10);
    testCard4.setSuit(2);
    testCard5.setValue(10);
    testCard5.setSuit(3);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();

    // Straight - works
    std::cout << "-----------------------------" << "\n";
    std::cout << "- Testing -> STRAIGHT       -" << "\n";
    std::cout << "-----------------------------" << "\n";  
    testCard1.setValue(12);
    testCard1.setSuit(0);
    testCard2.setValue(11);
    testCard2.setSuit(1);
    testCard3.setValue(10);
    testCard3.setSuit(1);
    testCard4.setValue(9);
    testCard4.setSuit(2);
    testCard5.setValue(8);
    testCard5.setSuit(3);
    testHand.changeCard(0, testCard1);
    testHand.changeCard(1, testCard2);
    testHand.changeCard(2, testCard3);
    testHand.changeCard(3, testCard4);
    testHand.changeCard(4, testCard5);
    testHand.calculateValue();
}
