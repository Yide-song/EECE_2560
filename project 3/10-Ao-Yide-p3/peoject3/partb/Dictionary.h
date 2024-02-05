#ifndef Dictionary_H
#define Dictionary_H

#include <vector>
#include <string>
using namespace std;
class Dictionary {
public:
    Dictionary();
    void readDictionary(const string &filename);
    void printwords();
    void Selectionsorts();
    void Quicksorts();
    void heapsorts();
    bool lookup(string target);
private:
    vector <string> wordlist;
};
#endif