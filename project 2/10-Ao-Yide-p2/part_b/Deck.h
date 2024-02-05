#include<iostream>
#include <vector>
#include<ctime>
#include "Card.h"
#include "DeckNode.h"

#ifndef Deck_h
#define Deck_h
using namespace std;
// Deck class to represent a deck of cards
class Deck{
    public:
        DeckNode *front = NULL;// Pointer to the front of the deck
        Deck();// Constructor
        ~Deck();// Destructor
        friend ostream& operator<<(ostream &out, const Deck& deck);
        void shuffle();// Method to shuffle the deck
        Card deal();// Method to deal a card
        void replace(const Card &cardreplace);// Method to place a card in the deck in the bottom of deck


};
#endif