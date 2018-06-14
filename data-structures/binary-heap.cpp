
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap {
    int * arr;
    int capacity;
    int heap_size;
public:
    MinHeap(int capacity);
    // min heapifying procedure prototype
    void minheapify(int i);

    int parent(int i){ return (i-1)/2; }
    int leftChild(int i){ return (2*i+1); }
    int rightChild(int i){ return 2*i + 2 ; }

    // deletes smallest element (root) from the heap
    int extractMin();

    // get minimum ( root)
    int getMin() { return arr[heap_size-1]; }

    // insert
    void insertKey(int i);

    // display heap
    void displayHeap();

    //deleting a key at particular index i of heap
    void deleteKey(int i);

    // helper function for deleteKey()
    void decreaseKey(int i);
};


// heapify or percolateDown
void MinHeap::minheapify(int i){
    int left = leftChild(i);
    int right = rightChild(i);

    int min = -1;
    int data = arr[i];
    if( data > arr[left] && left<heap_size)
        min = left;
    if( data > arr[right] && right<heap_size ){
        if( arr[right] < arr[left] )
            min = right;
    }

    if(min>=0){
        swap(arr[i],arr[min]);
        minheapify(min);
    }
}

int MinHeap::extractMin(){
    int smallest = arr[0];
    // swap root element with the last element of heap
    swap(arr[0],arr[heap_size-1]);
    // deleting last element which is the root
    heap_size--;
    // minheapify at root
    minheapify(0);

    return smallest;
}


MinHeap::MinHeap(int cap){
    heap_size = 0;
    capacity = cap;
    arr = new int[cap];
}


void MinHeap::insertKey(int key){
    //cout<<"Heap size :: "<<heap_size<<endl;
    //cout<<"Capacity of heap :: "<<capacity<<endl;
    if(heap_size == capacity){ cout<<"Heap is full !"; return; }
    heap_size++;
    arr[heap_size-1] = key;
    // store index of the new key in i
    int i = heap_size - 1;

    while(i>=0 &&  arr[i] < arr[parent(i)] ){
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }
}


void MinHeap::displayHeap(){

    cout<<"\nCurrent heap is : ";
    loop(i,0,heap_size){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void MinHeap::decreaseKey(int i){
    arr[i] = INT_MIN;
    // at index i of heap , the nodes below the heap are positioned fine. We have to check heap properties for nodes above i
    while(i>=0 && arr[i] < arr[parent(i)]){
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i){
    // bring node i to the top
    decreaseKey(i);
    // now delete the root node ( the node to be deleted)
    extractMin();
}


int main()
{
    MinHeap h(40);

    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(1);
    h.displayHeap();

    loop(i,0,5){
            cout<<"extractMin() called";
            cout<<"\nExtracted : "<<h.extractMin()<<endl;
            h.displayHeap();
    }



    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(1);
    h.displayHeap();
    cout<<"Deleting at index 1 (that is key 2)";
    h.deleteKey(1);
    h.displayHeap();

    return 0;
}

