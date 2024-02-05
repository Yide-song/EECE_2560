#include "Card.h"
using namespace std;
// Default constructor for Card
Card::Card():value(" "),suit(" "){};
// Parameterized constructor for Card
Card::Card(string value, string suit):value(value),suit(suit){};

// Setter for the card's value
void Card::setValue(string newValue){
    value=newValue;
    
    }

// Setter for the card's suit
void Card::setSuit(string newSuit){
    suit = newSuit;

    }

// Getter for the card's value
string Card::getValue() const {
    return value;
 }

// Getter for the card's suit
string Card::getSuit() const {
    return suit;
}

// Overloaded output operator to display Card
ostream& operator<<(ostream& out, const Card& card) {
        out << card.getValue() << " of " << card.getSuit();
        return out;
}