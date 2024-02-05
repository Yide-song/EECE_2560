#include "Deck.h"
#include<iostream>
using namespace std;
int main(){
    Deck deck1;// Create a deck object
    cout<<"Before shuffle "<<endl<<endl;
    cout<<deck1;// Display the deck before shuffling
    cout<<endl;
    deck1.shuffle();// Shuffle the deck
     cout<<"After shuffle "<<endl<<endl;
    cout<<deck1;// Display the deck after shuffling
    return 0;
}