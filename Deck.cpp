// -------------------------------------
// Deck related functions
// -------------------------------------

#include "Deck.hpp"

void Deck::makeAfullDeck ()
{
    for(int suit = 0; suit < 4; ++suit) {
        for(int value = 1; value <= 13; ++value) {
        Card new_card;
        new_card.setSuit(suit);
        new_card.setValue(value);
        cards.emplace_back(new_card);
        }
    }
}

Card Deck::getCardFromDeck()
{
    if (fullDeckCounter < 52) {
        ++fullDeckCounter;
        return cards.at(fullDeckCounter-1);
    }
    else {
        std::cout << "House out of cards!\n";
        // return nullptr? to avoid warning
    }
}

void Deck::addACard(Card c)
{   
    cards.emplace_back(c);
}
        
// Deck::Deck (int numberOfCards)
// {
//     for (int i = 0; i < numberOfCards; ++i) {
//         Card c = Card();
//         c.makeRandomCard();
//         cards.emplace_back(c);
//     }
// }

void Deck::showData()
{
    for (Card card : cards) {
        card.showData();
    }
    std::cout << "\n";
}

void Deck::printCards() // old aka deprecated
{
    for (Card card : cards) {
        card.printCard();
    }
}

void Deck::suffle() 
{
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng(seed);
    std::shuffle(cards.begin(), cards.end(), eng);
}

void Deck::sortByValue()
{
    std::sort(cards.begin(), cards.end(), compareCardsByValue);
}

void Deck::sortBySuit()
{
    std::sort(cards.begin(), cards.end(), compareCardsBySuit);
}

// void Deck::changeCards(std::string inputString)
// {
//     for(int i=0; i<inputString.length(); ++i) {
//         if(inputString.at(i) == 'o') {
//             //cards.at(i).makeRandomCard();
//             Card c = Card();
//             c.makeRandomCard();
//             cards.at(i) = c;
//             //std::cout << "Changing card number " << i+1 << "\n";
//         }
//     }
// }

int Deck::calculateValue()
{
    std::array<int, 13> matched{ {0,0,0,0,0,0,0,0,0,0,0,0,0} };
    std::array<int, 4> suits{ {0,0,0,0} };
    int pairs=0, threes=0, fours=0;
    bool flush=false;

    sortByValue();
    //sortBySuit();

    // calculating values based on this list
    // royal flush  100
    // straight flush 90 
    // four of a kind 80 
    // full house 70
    // flush 60
    // straight 50
    // three of a kind 40
    // two pair 30           
    // pair 20
    // higest card 1-13

    for (int i=0; i<NUMBER_OF_CARDS; ++i) {
         matched[cards.at(i).getValue() % 13]++;
         suits[(cards.at(i).getSuit() +1) % 4]++;
    }

    for (int i=0; i<13; ++i) {
        if (matched[i] == 2) {
            ++pairs;
        }
        else if (matched[i] == 3) {
            ++threes;
        }
        else if (matched[i] == 4) {
            ++fours;
        }
    }
    // std::cout << "Pairs:" << pairs << " Threes:" << threes << "Fours:" << fours << "\n";

    for (int i=0; i<4; ++i) {
        if (suits[i] == 5) 
            flush = true;
    }

    if ((cards.at(0).getValue() - cards.at(4).getValue() == 12) && flush) {
        std::cout << "Royal flush!\n";
        return 100;
    }

    else if ((cards.at(0).getValue() - cards.at(4).getValue() == 4) && flush) {
        std::cout << "Straight flush!\n";
        return 90;
    }

    else if (fours == 1) {
        std::cout << "Four of a kind!\n";
        return 80;
    }

    else if ( threes == 1 && pairs == 1 ) {
        std::cout << "Full house!\n";
        return 70;
    }

    else if (flush) {
        std::cout << "Flush!\n";
        return 60;
    }
    else if (cards.at(0).getValue() - cards.at(4).getValue() == 4 ) {
        std::cout << "Straight!\n";
        return 50;
    }
    else if (threes == 1) {
        std::cout << "Three of a kind!\n";
        return 40;
    }
    else if (pairs == 2) {
        std::cout << "Two pairs!\n";
        return 30;
    }
    else if (pairs == 1) {
        std::cout << "A pair!\n";
        return 20;
    }

    // if not anything else, just returnthe highest value card
    int higestValue = cards.at(0).getValue();
    for (Card card : cards) {
        if (card.getValue() > higestValue)
            higestValue = card.getValue();
    }
    std::cout << "Higest card is " << higestValue << "\n";
    return higestValue;
}

Card Deck::getCard(int value)
{
    return cards.at(value);
}

void Deck::changeCard(int i, Card c)
{
    cards.at(i) = c;
}
        
bool Deck::compareCardsByValue(Card a, Card b)
{
    return (a.getValue() > b.getValue());
}

bool Deck::compareCardsBySuit(Card a, Card b)
{
    return (a.getSuit() > b.getSuit());
}
