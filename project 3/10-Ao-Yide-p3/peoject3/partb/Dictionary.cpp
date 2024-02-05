#include "Dictionary.h"
#include "Binarysearch.h"
#include "Selectionsort.h"
#include "quicksort.h"
#include "Heap.h"
#include <fstream>
#include <iostream>

// Constructor for the Dictionary class
Dictionary::Dictionary(){};

// Reads words from a file and populates the wordlist vector, considering words with length 5 or more
void Dictionary::readDictionary(const string &filename){
    ifstream file(filename);
    string word;

            // Read each line from the file and add words to the wordlist
            while (getline(file, word)) {
                // Check if the word has a length of 5 or more characters
                if (word.length() >= 5) {
                    // Add the word to the wordlist
                    wordlist.push_back(word);
                }
            }

            // Close the file after reading
            file.close();
}

// Prints all words in the wordlist vector
void Dictionary::printwords(){
    for(long int i =0;i<wordlist.size()-1;i++){
        cout<<wordlist[i]<<endl;
    }
}

// Sorts the wordlist vector using the Selection Sort algorithm
void Dictionary::Selectionsorts(){
    Selectionsort selction;
    selction.sort(wordlist);
}

// Performs a binary search in the sorted wordlist to look up a target word
bool Dictionary::lookup(string target){
    Binarysearch search;
    return (search.search(wordlist,target));
}

// Sorts the wordlist vector using the Quicksort algorithm
void Dictionary::Quicksorts(){
    Quicksort quick;
    quick.quicksort(wordlist,0,(wordlist.size()-1));
    
}

// Sorts the wordlist vector using the Heapsort algorithm
void Dictionary::heapsorts(){
    Heap<string> heapsort;

    // Initialize a max heap using the wordlist
    heapsort.initializeMaxHeap(wordlist);

    // Perform heapsort
    heapsort.heapsort();

    // Update wordlist with sorted items
    for (int i = 0; i < wordlist.size(); i++) {
        wordlist[i] = heapsort.getItem(i); // Update wordlist with sorted items
    }
}