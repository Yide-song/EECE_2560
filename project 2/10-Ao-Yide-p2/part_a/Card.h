#include <iostream>
#include<ctime>
using namespace std;
#ifndef Card_h
#define Card_h
// Card class to represent a single card

class Card {
public:
    Card();
    Card(string value, string suit);

    void setValue(string  newValue);

    void setSuit(string newSuit);

    string  getValue() const;

    string getSuit() const;

    friend ostream& operator<<(ostream& out, const Card& card);
      

private:
    string  value; //  value from Ace to King
    string suit; // Club, Diamond, Heart, Spade

    
};

#endif