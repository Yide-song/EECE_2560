#include "Deck.h"
// Constructor for Deck class
Deck::Deck(){
    string values[] ={"A","2","3","4", "5", "6", "7","8","9","10", "J","Q","K"};
    string suit[] = {"Clubs","diamond","Heart","Spades"};
    for(int i = 3;i>=0;i--){
        for(int j = 12;j>=0;j--){
            Card newCard(values[j],suit[i]);
            DeckNode *NewCardNode = new DeckNode(newCard,front);
            front = NewCardNode;

        }
    }

}
// Destructor for Deck class
Deck::~Deck(){
    DeckNode *p = NULL;
    while (front != NULL)
    {
        p = front;
        front = front->next;
        delete p;
    }
    
}

// Method to shuffle the deck
void Deck::shuffle(){
   vector<Card> currentDeck;
   
    DeckNode *p = front;
    while (p!=NULL){
        currentDeck.push_back(p->currentNode);
        p = p->next;
    }
    DeckNode *q = front;

    srand(time(0));
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

// Method to deal a card(get the top cardc of deck)
Card Deck::deal(){
    if(front == NULL){
        cout<<"deck is empty"<<endl;
    }
    DeckNode *curr = front;
    front = front->next;
    Card topCard = curr->currentNode;
    delete curr;
    return topCard;
}

// Method to place a card in the deck in the bottom of deck
void Deck::replace(const Card &cardreplace){
    DeckNode *newCard = new DeckNode(cardreplace);
    if(front ==NULL){
        front  = newCard;
       
    }else{
        DeckNode *curr = front;
        while(curr->next !=NULL){
            curr = curr->next;
        }
        curr->next = newCard;

    }

}