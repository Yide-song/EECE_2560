#include "Dictionary.h"
#include "Binarysearch.h"
#include "Selectionsort.h"
#include <fstream>
#include <iostream>

// Constructor for the Dictionary class
Dictionary::Dictionary(){};

// Reads words from a file and populates the wordlist vector, considering words with length 5 or more
void Dictionary::readDictionary(const string &filename){
    // Open the specified file
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
    // Iterate through the wordlist and print each word
    for(long int i =0;i<wordlist.size()-1;i++){
        cout<<wordlist[i]<<endl;
    }
}

// Sorts the wordlist vector using the Selection Sort algorithm
void Dictionary::sorts(){
    // Create an instance of the Selectionsort class
    Selectionsort selction;

    // Call the sort method of the Selectionsort class to sort the wordlist
    selction.sort(wordlist);
}

// Performs a binary search in the sorted wordlist to look up a target word
bool Dictionary::lookup(string target){
    // Create an instance of the Binarysearch class
    Binarysearch search;

    // Call the search method of the Binarysearch class and return the result
    return (search.search(wordlist,target));
}