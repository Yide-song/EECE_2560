#include<iostream>
#include <vector>
#include<ctime>

#include "DeckNode.h"

#ifndef Deck_h
#define Deck_h
using namespace std;

// Deck class to represent a deck of cards
class Deck{
    public:
        DeckNode *front = NULL;// Pointer to the front of the deck
        Deck();// Constructor
        friend ostream& operator<<(ostream &out, const Deck& deck);
        void shuffle();// Method to shuffle the deck


};
#endif