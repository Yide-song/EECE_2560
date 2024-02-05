# include"Selectionsort.h"

// Constructor for the Selectionsort class
Selectionsort::Selectionsort(){};

// Sorts a vector of strings using the Selection Sort algorithm
void Selectionsort::sort(vector<string>& arr){
    int n = arr.size();
    unsigned long int smallIndex; // index of smallest element in the sublist
    unsigned long int pass, j;
    string temp;

    // Iterate through the list for each pass
    for (pass = 0; pass < n-1; pass++){
        smallIndex = pass;

        // Find the index of the smallest element in the remaining unsorted sublist
        for (j = pass+1; j<n; j++){
            if (arr[j] < arr[smallIndex]){
                smallIndex = j;
            }
        }

        /**if (smallIndex != pass){
            temp = arr[pass];
            arr[pass] = arr[smallIndex];
            arr[smallIndex] = temp;
        } **/

        // Swap the found smallest element with the first element in the sublist
        swap(arr[pass],arr[smallIndex]);

    }

}