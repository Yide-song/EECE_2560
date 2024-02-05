#ifndef Grid_H
#define Grid_H

#include <vector>
#include <string>

using namespace std;

class Grid{
public:
    Grid();
    void readgrid(const string& filename);
    string getstring(int x, int y);
    int getlength();
    int getwidth();
    void printGrid();
private:
    vector<vector<char>> gridMatrix;
    int length,width;
};
#endif