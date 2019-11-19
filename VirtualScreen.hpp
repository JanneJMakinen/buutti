// -------------------------------------
// Virtual screen related functions
// Virtual screen is an array that
// allows sideway printing
// -------------------------------------

#ifndef VIRTUALSCREEN
#define VIRTUALSCREEN

#include <iostream>
#include <array>
#include "Card.hpp"

namespace utility_functions {
    void showHouseRules();
    void printLogo();
    void runTests();
}
template <class T, size_t ROW, size_t COL>
using VirtualScreen = std::array<std::array<T, COL>, ROW>;

template <class T>
void show(T &t, size_t rows, size_t columns)
{
  for(size_t i = 0;i < rows; ++i)
  {
    for(size_t j = 0;j < columns; ++j)
      std::cout << t[i][j];

    std::cout << "\n";
  }
}

template <class T>
void initialize(T &t, size_t rows, size_t columns)
{
  for(size_t i = 0;i < rows; ++i)
  {
    for(size_t j = 0;j < columns; ++j)
      t[i][j] = ' ';
  }
}

template <class T>
void addDeck(T &t, Card c, size_t y, size_t x)
{
    // works, but a mess, recode with using constants
    for(size_t i = 0;i < y; ++i) 
    {
         t[i+1][x-5] = '|';
    }
    for(size_t i = 0;i < y; ++i)
    {
         t[i+1][x] = '|';
    }
    for(size_t i = 0;i < CARD_SIZE_X-3; ++i)    // 3 is for that corners are not printed
    {
         t[0][i+1+x-5] = '_';
    }
    for(size_t i = 0;i < CARD_SIZE_X-3; ++i)    // 3 is for that corners are not printed
    {
         t[CARD_SIZE_Y][i+1+x-5] = '_';
    }
    if (c.getSuit() == 0)
        t[y-2][x-2] = '&';
    else if (c.getSuit() == 1)
        t[y-2][x-2] = '^';
    else if (c.getSuit() == 2)
        t[y-2][x-2] = 'v';
    else if (c.getSuit() == 3)
        t[y-2][x-2] = 'o';
    
    if (c.getValue() < 10)
        t[y-4][x-4] = (char)('0' + c.getValue());
    else
    {
        t[y-4][x-4] = '1';
        t[y-4][x-3] = (char)('0' + c.getValue()-10);   
    }
}

// add a function that prints blank house cards
// move constants to functions, so that main is more readable
// if time code a memset function to copy ascii characters to an array:
// copyArrayToVirtualScreen(VirtualScreen, asciiArray, xSizeOfArray, ySizeOfArray)
// or 
// maybe struct or a class is better solution rather than this

#endif