#include<iostream>

#include "Card.h"
using namespace std;
#ifndef DeckNode_h
#define DeckNode_h
// Node for a linked list representing a card in a deck
class DeckNode{
    public:
        Card currentNode;
        DeckNode *next;
        // Default constructor
        DeckNode():currentNode(Card()),next(NULL){}
        // Parameterized constructor
        DeckNode(const Card&current, DeckNode *nextNode = NULL):currentNode(current),next(nextNode){}
};

#endif