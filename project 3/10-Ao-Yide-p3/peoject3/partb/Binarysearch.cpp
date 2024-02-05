#include"Binarysearch.h"

// Constructor for the Binarysearch class
Binarysearch::Binarysearch(){};

// Binary search method to find a target string in a sorted vector of strings
bool Binarysearch::search(vector<string>&arr, string &target){
    // Initialize indices for the first and last elements of the vector
    int first =0; 
    int last =arr.size()-1;

    // Variables to store the mid index and corresponding value
    int mid;
    string midvalue;

    // Continue the search until the first index exceeds the last index
    while (first <= last) {
        // Calculate the mid index
        mid = (first + last) / 2;

        // Retrieve the value at the mid index
        midvalue = arr[mid];

        // Check if the midvalue is equal to the target
        if (midvalue == target){
            // Target found, return true
            return true;
        }
        // If the midvalue is less than the target, adjust the search range to the right half
        else if (midvalue < target){
            first = mid + 1;

        // If the midvalue is greater than the target, adjust the search range to the left half
        }else{
            last = mid - 1;
    }
    }

    // If the loop completes without finding the target, return false
    return false;
}