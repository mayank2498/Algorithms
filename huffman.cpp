
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;


void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
// heap node

struct MinHeapNode{
    char data;
    int freq;
    struct  MinHeapNode *left,*right;
};

struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode * array;
};


// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)

{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left].freq < minHeap->array[smallest].freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right].freq < minHeap->array[smallest].freq)
        smallest = right;

    if (smallest != idx) {
        swap(minHeap->array[smallest],minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}


void displayHeap(struct MinHeap * x){
    cout<<"\n Current Minheap is : "<<endl;
    loop(i,0,x->size){

        cout<<x->array[i].data<<","<<x->array[i].freq<<"  ";
        if(x->array[i].left!=NULL){cout<<"yes(L)";}
        if(x->array[i].right!=NULL){cout<<"yes(R)";}
    }
    cout<<endl;
}

// A standard funvtion to build min heap
void buildMinHeap(struct MinHeap* minHeap)

{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// extracts minimum and deletes root node
MinHeapNode * extractMin(struct MinHeap * h){
    MinHeapNode * smallest = new MinHeapNode;
    smallest->data = h->array[0].data;
    smallest->freq = h->array[0].freq;
    smallest->left = h->array[0].left;
    smallest->right = h->array[0].right;

    swap(h->array[0],h->array[h->size-1]);
    h->size--;
    minHeapify(h,0);
    //cout<<"\n Iam returning "<<small->freq<<" from extractMin\n";
    return smallest;
}

// inserting a new element to minheap
void insertKey(struct MinHeap * h,MinHeapNode * newnode){
    int i = h->size;
    h->array[i].data = newnode->data;
    h->array[i].freq = newnode->freq;
    h->array[i].left = newnode->left;
    h->array[i].right = newnode->right;
    h->size++;
    int parent = (i-1)/2;
    while(i>=0 && h->array[i].freq < h->array[parent].freq){
        swap(h->array[i],h->array[parent]);
        i = parent;
    }
}


// creates a minheap and returns the pointer to a MinHeap object just created
struct MinHeap * createAndBuildMinHeap(char arr[],int freq[],int cap){
    struct MinHeap * root = (struct MinHeap *)malloc(sizeof(MinHeap));
    root->size = cap;
    root->capacity = cap;
    root->array = new MinHeapNode[cap];

    // now minheap is created
    // copying arr to this minheap to start the heapifying procedure

    loop(i,0,cap){
        root->array[i].data = arr[i];
        root->array[i].freq = freq[i];
        root->array[i].left = NULL;
        root->array[i].right = NULL;
    }
    buildMinHeap(root);
    return root;
}


struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}


int isSizeOne(struct MinHeap* minHeap)
{

    return (minHeap->size == 1);
}


struct MinHeapNode * buildHuffmanTree(char arr[],int freq[],int size){
    // make an object minheap
    struct MinHeap * minheap = createAndBuildMinHeap(arr,freq,size);
    displayHeap(minheap);
    // extract 2 minimum elements from minheap using extractMin and add there frequencies to make a new node and push this new node
    // to the minheap

    // We remove 2 elements and insert 1 . Effectively we are deleting one element from the minheap in every iteration
    struct MinHeapNode * left, *right , *top;
    while(!isSizeOne(minheap)){
        left = extractMin(minheap);
        right = extractMin(minheap);
        cout<<"\n Left : "<<left->freq<<" , right :"<<right->freq<<endl;
        top = newNode('#',left->freq+right->freq);
        top->left = left;
        top->right = right;


        //cout<<"\n made  a node of freq "<<top->freq<<endl;
        insertKey(minheap,top);
        displayHeap(minheap);
    }
    return extractMin(minheap);

}



void show_root(MinHeapNode * h){
    if(h!=NULL){
        cout<<h->data<<" : "<<h->freq<<endl;
        show_root(h->left);
        show_root(h->right);
    }

}

// A utility function to print an array of size n
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)

{

    return !(root->left) && !(root->right);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(struct MinHeapNode* root, int arr[], int top)

{

    // Assign 0 to left edge and recur
    if (root->left) {

        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to right edge and recur
    if (root->right) {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, then
    // it contains one of the input
    // characters, print the character
    // and its code from arr[]
    if (isLeaf(root)) {

        printf("%c: ", root->data);
        printArr(arr, top);
    }
}


void HuffmanCodes(char arr[],int freq[],int size){
    // first step construct Huffman Tree
    //struct MinHeapNode * root = buildHuffmanTree(arr,freq,size);
    MinHeapNode * root = buildHuffmanTree(arr,freq,size);

    show_root(root);

    int myarray[100],top=0;
    printCodes(root, myarray, top);
}




int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e'};
    int freq[] = { 3, 5, 6, 4, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr,freq,size);
    return 0;
}
