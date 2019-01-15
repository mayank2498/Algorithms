#define loop(i,a,b) for(int i=a;i<b;i++)
#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int N;

int construct_segment_tree(int A[],int low,int high,int segTree[],int pos){
    if ( high == low ) { segTree[pos] = A[low]; return A[low];}
    int mid = (high+low)/2;
    int x = construct_segment_tree(A,low,mid,segTree,2*pos+1);
    int y = construct_segment_tree(A,mid+1,high,segTree,2*pos+2);
    segTree[pos] = min(x,y);
    return min(x,y);

}

int* make_segTree(int A[],int max_size){
    int * segTree = new int[max_size];
    loop(i,0,max_size){ segTree[i] = MAX; }

    return segTree;
}

int minimum_inRange(int qlow,int qhigh, int low, int high,int pos,int* segTree){

    // total overlap
    if ( low >= qlow && high <= qhigh ){
        return segTree[pos];
    }
    // no overlap
    if ( high < qlow || low > qhigh ){
        return MAX;
    }

    //
    int mid = (high+low)/2;
    return min( minimum_inRange(qlow,qhigh,low,mid,2*pos+1,segTree) , minimum_inRange(qlow,qhigh,mid+1,high,2*pos+2,segTree) );
}

int main() {

    int A[] = {-1,3,4,0,2,1};
    N = sizeof(A)/sizeof(A[0]);

    // for n = 6 max_size = 15 , like complete binary tree

    int max_size = 2*pow(2,int(ceil(log2(N))))-1;

    int * segTree = make_segTree(A,max_size);

    int temp = construct_segment_tree(A,0,N-1,segTree,0);
    //display segment tree

    loop(i,0,max_size){ cout<<segTree[i]<<" "; }
    cout<<endl;
    // Finds the minimum between the ranges indices low , high

    int low,high;
    cin>>low>>high;
    cout<<endl<<minimum_inRange(low,high,0,5,0,segTree);
    return 0;
}

