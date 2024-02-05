#ifndef Heap_H
#define Heap_H
#include <vector>
using namespace std;
template <typename T>
class Heap{
public:
    Heap();
    T getItem(int n);
    void initializeMaxHeap( vector<T> &input);
    void buildMaxHeap();
    void maxHeapify(int i,int heapsize);
    void heapsort();


    
private:
    vector<T> objects;
    int parent(int n);
    int left(int n);
    int right(int n);

};

template <typename T>
Heap<T>::Heap() {};

template <typename T>
int Heap<T>::parent(int i){return ((i-1)/2);};

template <typename T>
int Heap<T>::left(int i){return (2*i+1);};

template <typename T>
int Heap<T>::right(int i){return (2*i+2);};

template <typename T>
void Heap<T>::maxHeapify(int i,int heapsize ) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < heapsize && objects[l] > objects[i]){
        largest = l;
    }else{
        largest = i;
    }
    if (r < heapsize && objects[r] > objects[largest]){
        largest = r;
    }
    if(largest !=i){
        swap(objects[i],objects[largest]);
        maxHeapify(largest,heapsize);
    }
}

template <typename T>
void Heap<T>::buildMaxHeap(){
    int begin = (objects.size()/2)-1;
    for(int i = begin; i>=0;i-- ){
        maxHeapify(i,objects.size());
    }
}
template <typename T>
void Heap<T>::heapsort(){
   
    buildMaxHeap();
    int heapsize = objects.size();

    for(int i = objects.size()-1;i>=1;i--){
        swap(objects[0],objects[i]);
        heapsize--;
        maxHeapify(0,heapsize);

    }
}
template <typename T>
T Heap<T>::getItem(int n){
    return objects[n];
}
template <typename T>
void  Heap<T>::initializeMaxHeap( vector<T> &input){
    for(int i =0; i < input.size();i++){
        objects.push_back(input[i]);
    }
    buildMaxHeap();
}
#endif