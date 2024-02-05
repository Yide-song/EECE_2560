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
int main(){
    // Create an instance of the Dictionary class
    Dictionary dictionary;

    // Read and sort the dictionary from a file
    dictionary.readDictionary("dictionary.txt");
    dictionary.sorts();

    // Create an instance of the Grid class
    Grid grid;

    // Read the grid from a file
    grid.readgrid("input15.txt");

    // Find and print word matches in the grid based on the dictionary
    findMatches(dictionary, grid);
    
    return 0;

}