#include "quicksort.h"

// Constructor for the Quicksort class
Quicksort::Quicksort(){};

// Swap function to interchange the values of two strings
void Quicksort::swap(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

// Partition function for the Quicksort algorithm
// It rearranges the elements in the vector A[p..r] in such a way that
// elements less than or equal to A[r] are on the left, and elements greater
// than A[r] are on the right. It returns the index of the partitioning element.
int Quicksort:: partition(vector<string>& A, int p, int r){
    // Choose the rightmost element as the pivot
    string x = A[r];
    int i = p-1;

    // Iterate through the elements from p to r-1
    for(int j = p;j<=r-1;j++){
        // If the current element is less than or equal to the pivot, swap it with A[i+1]
        if(A[j]<=x){
            i++;
            swap(A[i], A[j]);
        }
    }

    // Swap the pivot (A[r]) with the element at A[i+1]
    swap(A[i+1],A[r]);

    // Return the index of the partitioning element
    return i+1;
}

// Quicksort function to recursively sort the vector A
void Quicksort::quicksort(vector<string>& A, int p, int r){
    // Recursively sort the two partitions if there is more than one element
    if (p<r){
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }

}