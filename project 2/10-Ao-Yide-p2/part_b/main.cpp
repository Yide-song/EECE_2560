#include"Deck.h"
#include"DeckNode.h"
#include<iostream>
#include<vector>
using namespace std;
void playFlip(){
    Deck deckplay;
    DeckNode *curr = deckplay.front;
    vector<Card>drawdeckes;
     // Shuffle the deck three times
    for(int i =0;i<=2;i++){
        deckplay.shuffle();
        
    }
    int times =1;
    // Draw 24 cards
    cout<<"Game start "<<endl;
    cout<<"draw 24 cards"<<endl;
    for(int i =0;i<24;i++){
        drawdeckes.push_back(deckplay.deal());
        
    }
    // Display the drawn cards

    for(int i =0;i<24;i++){
        cout<<drawdeckes[i]<<endl;
    }
  
    cout<<endl;
     // Display the remaining cards

    cout<<"remaining cards "<<endl;
    cout<<deckplay<<endl;
    double scores =0.0;
    int index =0;
    int roundNumber =1;
    // Game loop

    while(drawdeckes.size()!=0&&index<drawdeckes.size()){
        string userInput;

        cout<<"\nRound "<<roundNumber<<endl;//display round number
        cout<<"Press y/n to select wheter to filp a card, or press q to quite"<<endl;
        cin>> userInput;
        if(userInput=="y"){
            cout<<"\nThe card you flip is"<<endl;
            cout<<drawdeckes[index]<<endl;
            string valueOfCard = drawdeckes[index].getValue();
            string suitOfCard = drawdeckes[index].getSuit();
            
            // Scoring logic
           if(valueOfCard == "A"){
                scores +=10;
           }else if(valueOfCard == "K"||valueOfCard == "J"||valueOfCard == "Q"){
                scores += 5;
           }else if(valueOfCard == "8"||valueOfCard == "9"||valueOfCard == "10"){
                scores += 0;
           }else if(valueOfCard == "7"){
                scores /= 2;
           }else if (valueOfCard == "2"||valueOfCard == "3"||valueOfCard == "4"||valueOfCard == "5"||valueOfCard == "6")
           {
                scores =0;
           }
           if (suitOfCard == "Heart")
           {
                scores += 1;
           }
           cout<<"\nYour current score is "<<scores<<endl;
           deckplay.replace(drawdeckes[index]);

           drawdeckes.erase(drawdeckes.begin()+index);
            roundNumber++;
            
        }else if(userInput =="n"){
            index++;
             roundNumber++;
        }else if(userInput =="q"){
            break;//quit if press q
        }
        else{
            cout<<"invalid input"<<endl;//output invalid if something else press
        }
       
    }
    cout<<"\nGame End"<<endl;
    cout<<"Your finaly score is "<<scores<<endl;

    

    
    




}
int main(){
    playFlip();
    return 0;
   
   
}