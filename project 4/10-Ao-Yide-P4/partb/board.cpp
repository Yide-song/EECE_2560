#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <vector>
#include <fstream>
using namespace std;

// Define some constants
typedef int ValueType; // The type of the value in a cell
const int Blank = -1; // Indicates that a cell is blank
const int SquareSize = 3; // The number of cells in a small square
const int BoardSize = SquareSize * SquareSize;
const int MinValue = 1;
const int MaxValue = 9;
int numSolutions = 0;

// Class declaration for the Sudoku board
class board {
public:
    // Constructor
    board(int);

    // Member functions
    void clear();
    void setCell(int i, int j, int val);
    void initialize(ifstream &fin);
    void print();
    void clearCell(int i, int j);
    void updateConflict(int i, int j,int initalval, bool clearconflict);
    bool solverecu();
    bool cellvalid(int i,int j, int val);
 

    void printConflicts();
    bool isBlank(int, int);
    void restConflicts();
    bool isSolved();
    int iterations = 0;
    int totaliteration =0;
    ValueType getCell(int, int);

private:
    matrix<ValueType> value; // Matrix to store cell values
    matrix<int> rowconf; // Matrix to store row conflicts
    matrix<int> colconf; // Matrix to store column conflicts
    matrix<int> matrixconf; // Matrix to store square conflicts
};

// Constructor for the board class
board::board(int sqSize) : value(BoardSize+1, BoardSize+1),rowconf(BoardSize+1,BoardSize+1,Blank),colconf(BoardSize+1,BoardSize+1,Blank),matrixconf(BoardSize+1,BoardSize+1,Blank) {
    clear();
}

// Function to clear the board
void board::clear() {
    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++) {
            value[i][j] = Blank;
            rowconf[i][j] = Blank;
            colconf[i][j] = Blank;
            matrixconf[i][j] = Blank;
        }
}

// Function to set a cell with a value and update conflicts
void board::setCell(int i, int j, int val){
    value[i][j] =val;
    updateConflict(i,j,val,false);
}

// Function to clear a cell and update conflicts
void board::clearCell(int i, int j){
    value[i][j] =Blank;
}

// Function to initialize the board from a file
void board::initialize(ifstream &fin) {
    char ch;
    clear();

    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++) {
            fin >> ch;
            if (ch != '.')
                setCell(i, j, ch - '0');
                updateConflict(i,j,ch - '0',false);
        }
}

// Function to get the square number for a given cell
int squareNumber(int i, int j) {
    return SquareSize * ((i-1) / SquareSize) + (j-1) / SquareSize + 1;
}

// Function to check if the board is solved
bool board::isSolved(){
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++) {
            if(rowconf[i][j]==Blank){
                return false;
            }else if(colconf[i][j] == Blank){
                return false;
            }else if (matrixconf[i][j] == Blank){
                return false;
            }
        }
    }
    
    return true;
}

// Recursive backtracking solver for the Sudoku board
bool board::solverecu() {
    iterations++;
    for (int i = 1; i <= BoardSize; i++) {
        for (int j = 1; j <= BoardSize; j++) {
            if (value[i][j] == Blank) { 
                for (int num = MinValue; num <= MaxValue; num++) { 
                    if (cellvalid(i, j, num)) {
                        value[i][j] = num; 
                        updateConflict(i, j, num, false); 

                        if (solverecu()) {
                            return true;
                        }

                        value[i][j] = Blank;
                        updateConflict(i, j, num, true); 
                    }
                }
                return false; 
            }
        }
    }
    cout<<"Number of iterations " <<iterations<<endl;
    totaliteration += iterations;
    return true; 
}

// Function to check if a cell value is valid
bool board::cellvalid(int i,int j, int val){
    int square = squareNumber(i,j);
    if(rowconf[i][val]!=Blank){
        return false;
    }else if(colconf[j][val]!=Blank){
        return false;
    }else if (matrixconf[square][val]!=Blank)
    {
       return false;
    }
    updateConflict(i,j,val,false);;
    return true;
    
}


// Function to update conflicts for a given cell
void board::updateConflict(int i, int j,int initalval, bool clearconflict){
    int square = squareNumber(i,j);
    if(clearconflict){
        
        rowconf[i][initalval] = Blank;
        colconf[j][initalval] = Blank;
        matrixconf[square][initalval] = Blank;
    }else{
        rowconf[i][initalval] = initalval;
        colconf[j][initalval] = initalval;
        matrixconf[square][initalval] = initalval;
    }
}

// Function to print conflicts for each cell
void board::printConflicts(){
     for (int i = 1; i <= BoardSize; i++) {
       for (int j = 1; j <= BoardSize; j++){
            cout<< "Cell ["<<i<<"] ["<<j<<"]      ";
            int val = value[i][j];
            int square = squareNumber(i,j);
            if(val != Blank){
                cout <<"Existing value"<<endl;

            }else 
            {
                for(int k = 1; k <= BoardSize; k++){
                    if(rowconf[i][k]!=Blank){
                        cout<< rowconf[i][k] <<" ";
                        continue;
                    }else if(colconf[j][k]!=Blank){
                        cout<< colconf[j][k] <<" ";
                        continue;
                    }else if(matrixconf[square][k]!=Blank){
                        cout <<matrixconf[square][k]<<" ";
                        
                        
                    }
                }
                cout<<endl;
            }
       }
     }  
}

// Overloaded operator to print vector elements
ostream &operator<<(ostream &ostr, vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
        ostr << v[i] << " ";
    cout << endl;
}

// Function to get the value of a cell
ValueType board::getCell(int i, int j) {
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
        return value[i][j];
    else
        throw rangeError("bad value in getCell");
}

// Function to check if a cell is blank
bool board::isBlank(int i, int j) {
    if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
        throw rangeError("bad value in setCell");
    return (getCell(i, j) == Blank);
}

// Function to print the Sudoku board
void board::print() {
    for (int i = 1; i <= BoardSize; i++) {
        if ((i-1) % SquareSize == 0) {
            cout << " -";
            for (int j = 1; j <= BoardSize; j++)
                cout << "---";
            cout << "-";
            cout << endl;
        }

        for (int j = 1; j <= BoardSize; j++) {
            if ((j-1) % SquareSize == 0)
                cout << "|";
            if (!isBlank(i, j))
                cout << " " << getCell(i, j) << " ";
            else
                cout << "   ";
        }

        cout << "|";
        cout << endl;
    }

    cout << " -";
    for (int j = 1; j <= BoardSize; j++)
        cout << "---";
    cout << "-";
    cout << endl;
}

// Main function to read Sudoku boards from a file and solve them
int main() {
    int Numboard = 0;
    ifstream fin;
    string fileName = "sudoku.txt";

    fin.open(fileName.c_str());
    if (!fin) {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }

    try {
        // Process each Sudoku board in the file
        board b1(SquareSize);
        while (fin && fin.peek() != 'Z') {
            b1.initialize(fin);
            b1.print();
            cout<<"solve"<<endl;
            b1.iterations =0;
            b1.solverecu();
            b1.print();
   
            if(b1.isSolved()){
                cout<<"This board is Solved"<<endl;
            }else{
                cout<<"This board isn't solved"<<endl;
            }
            Numboard++;
            b1.clear();

            
            
            
        }
      
        float average = (b1.totaliteration)/Numboard;
        cout<<"Average Iteration Number "<< average<<endl;
    } catch (indexRangeError &ex) {
        cout << ex.what() << endl;
        exit(1);
    }
}
