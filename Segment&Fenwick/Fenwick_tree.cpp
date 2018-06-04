#define loop(i,a,b) for(int i=a;i<b;i++)
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// find_sum runs in O(logn) time

int find_sum(int * fen_tree, int index, int size){
    int sum = 0;
    while(index){
        sum += fen_tree[index];
        index = index & (index - 1);
    }
    return sum;
}


// add operation

void add(int * fen_tree, int index,int size, int val){
    while(index<=size){
        fen_tree[index] += val;
        index += index&-index;
    }
}

void update_tree(int * fen_tree, int index ,int size, int val ){
    int x = index + 1;
    while(x<=size){
        fen_tree[x] += val;
        x += x&-x;
    }
}



int * construct_fenwick_tree(int arr[],int size){
    int * fen_tree = new int[size + 1];

    // initialise with 0
    for(int i=1;i<=size;i++){
        fen_tree[i] = 0;
    }

    // consider arr[i] add arr[i] to all the required places

    for(int i=0;i<size;i++){
        update_tree(fen_tree,i,size,arr[i]);
    }

    // display fenwick tree
    //loop(i,1,size+1){ cout<<fen_tree[i]<<" ";  }

    return fen_tree;
}



int main()
{
  int arr[] = {1,7,3,0,5,8,3,2,6,2,1,1,4,5};
  int size = sizeof(arr)/sizeof(int);
  int * fen_tree = construct_fenwick_tree(arr,size);
  cout<<find_sum(fen_tree,13,size)<<endl;
  add(fen_tree,5,size,2);
  loop(i,1,size+1){ cout<<fen_tree[i]<<" ";  }
  return 0;
}
