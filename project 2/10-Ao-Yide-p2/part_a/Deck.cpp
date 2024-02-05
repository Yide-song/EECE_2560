#include "Deck.h"
// Constructor for Deck class
Deck::Deck(){
    string values[] ={"A","2","3","4", "5", "6", "7","8","9","10", "J","Q","K"};
    string suit[] = {"Clubs","diamond","Heart","Spades"};
    
    // Initialize the deck with cards in order
    for(int i = 3;i>=0;i--){
        for(int j = 12;j>=0;j--){
            Card newCard(values[j],suit[i]);
            DeckNode *NewCardNode = new DeckNode(newCard,front);
            front = NewCardNode;

        }
    }

}

// Method to shuffle the deck
void Deck::shuffle(){
   vector<Card> currentDeck;
   
    // Copy the cards from the linked list to a vector to prepare to shuffle
    DeckNode *p = front;
    while (p!=NULL){
        currentDeck.push_back(p->currentNode);
        p = p->next;
    }
    DeckNode *q = front;

    srand(time(0));
    // Shuffle the cards in the deck
    for(int i =0 ; i<currentDeck.size();i++){
        int randomIndex = rand()%currentDeck.size();
        q->currentNode = currentDeck[randomIndex];
        q = q->next;
    }
    
    
    

}
// Overloaded output operator to display the deck
ostream& operator<<(ostream &out, const Deck& deck){
    DeckNode *p = deck.front;
    while (p != NULL)
    {
        out<<p->currentNode<<endl;
        p = p->next;
    }
    
    return out;
    

}