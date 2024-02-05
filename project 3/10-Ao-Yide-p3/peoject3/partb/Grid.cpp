#include "Grid.h"
#include <fstream>
#include <iostream>

using namespace std;

// Constructor for the Grid class, initializes length and width to zero
Grid::Grid():length(0),width(0){};

// Reads grid data from a file and populates the gridMatrix vector
void Grid::readgrid(const string& filename){
    // Open the specified file
    ifstream file(filename);
    string line;
    string localengthstring,localwidthstring;

    // Read the first line to obtain length and width information
    getline(file,localengthstring,' ');
    length = stoi(localengthstring);
    getline(file,localwidthstring,'\n');
    width = stoi(localwidthstring);

    // Read each subsequent line and populate the gridMatrix vector
    while(getline(file,line)){
        vector<char> rowchar;

        // Extract non-space characters from the line and add them to the rowchar vector
        for (int i = 0; i < line.length(); i++) {
            if((line[i])!= ' '){
            rowchar.push_back(line[i]);
            }
        }

        // Add the rowchar vector to the gridMatrix vector
        gridMatrix.push_back(rowchar);
    }

    // Close the file after reading
    file.close();
}

// Gets the string representation of the cell at position (x, y)
string Grid::getstring(int x, int y){
    // Get the character at position (x, y) from the gridMatrix
    char charcell = gridMatrix[x][y];

    // Convert the character to a string
    string cell;
    cell += charcell;

    return cell;
}

// Returns the length of the grid
int Grid::getlength() {
    return length;
}

// Returns the width of the grid
int Grid::getwidth(){
    return width;

}

// Prints the contents of the gridMatrix to the console
void Grid::printGrid() {
    for (int i = 0; i < getlength(); i++) {
        for (int j = 0; j < getwidth(); j++) {
            cout << getstring(i, j) << " ";
        }
        cout << endl;
    }
}