#include "Binarysearch.h"
#include "Grid.h"
#include"Selectionsort.h"
#include "Dictionary.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find word matches in the grid based on the given dictionary
void findMatches( Dictionary& dictionary,   Grid& grid) {
    int n = grid.getlength();
    int m = grid.getwidth();

    // Check all directions
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string word = "";

            // Check left
            word = "";
            for (int k = j; k >= 0; k--) {
                word += grid.getstring(i,k);
                if (dictionary.lookup(word)) {
                    cout << word <<endl;
                }
            }
            word = "";


            // Check right
            for (int k = j; k < m; k++) {
                word += grid.getstring(i,k);
                if (dictionary.lookup(word)) {
                   cout << word <<endl;
                }
            }

            // Check up
            word = "";
            for (int k = i; k >= 0; k--) {
                word += grid.getstring(k,j);
                if (dictionary.lookup(word)) {
                    cout << word <<endl;
                }
            }

            // Check down
            word = "";
            for (int k = i; k < n; k++) {
                word += grid.getstring(k,j);
                if (dictionary.lookup(word)) {
                    cout << word <<endl;
                }
            }

            // Check left-up
            word = "";
            for (int k = 0; i - k >= 0 && j - k >= 0; k++) {
                word += grid.getstring((i - k),(j - k));
                if (dictionary.lookup(word)) {
                    cout << word <<endl;
                }
            }

            // Check left-down
            word = "";
            for (int k = 0; i + k < n && j - k >= 0; k++) {
                word += grid.getstring((i + k),(j - k));
                if (dictionary.lookup(word)) {
                    cout << word <<endl;
                }
            }

            // Check right-up
            word = "";
            for (int k = 0; i - k >= 0 && j + k < m; k++) {
                word += grid.getstring((i - k),(j + k));
                if (dictionary.lookup(word)) {
                    cout << word <<endl;
                }
            }

            // Check right-down
            word = "";
            for (int k = 0; i + k < n && j + k < m; k++) {
                word += grid.getstring((i + k),(j + k));
                if (dictionary.lookup(word)) {
                    cout << word <<endl;
                }
            }
        }
    }
}

// Function to perform a word search in the grid using a selected sorting algorithm
void search(int algochoice){
    // Create an instance of the Dictionary class
    Dictionary dictionary;
    // Read and initialize the dictionary from a file
    dictionary.readDictionary("dictionary.txt");

    cout<<"input the file name"<<endl;
    string gridname;
    cin>> gridname;

    // Create an instance of the Grid class
    Grid grid;
    // Read and initialize the grid from a file
    grid.readgrid(gridname);

    // Choose and apply the selected sorting algorithm
    switch ((algochoice))
    {
    case 1:
        dictionary.heapsorts();
        //dictionary.printwords();
        break;
    case 2: 
        dictionary.Quicksorts();
        //dictionary.printwords();

        break;
    case 3:
        dictionary.Selectionsorts();
        //dictionary.printwords();

        break;
    default:
        break;
    }

    // Find and print word matches in the grid based on the sorted dictionary
    findMatches(dictionary, grid);
}

int main(){
    int end;

    // Keep looping until the user chooses to end (option 4)
    while(end != 4){
        cout<<"Selction the sort algorithm, 1 for heap Sort, 2 for 1uick sort, 3 for selection sort, 4 for end "<<endl;
        int algo;
        cin>>algo;

        if(algo !=4){
            // Perform the word search using the chosen algorithm
            search(algo);
        }else{
            // End the loop if the user chooses option 4
            end =4;
            break;
        }
        
    }

}