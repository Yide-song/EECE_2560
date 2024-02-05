#ifndef Quicksort_h
#define Quicksort_h
#include <string>
#include <vector>
using namespace std;
class Quicksort{
    public:
    Quicksort();
    void swap(string& a, string& b);
    int partition(vector<string>& A, int p, int r);
    void quicksort(vector<string>& A, int p, int r);

};

#endif