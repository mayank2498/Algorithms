// maximum element in a sliding window
// using dequeue

#include<iostream>

#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;


void showDQ(deque<int> DQ){
    deque<int> :: iterator it;
    cout<<"\nDeque is : ";

    for(it=DQ.begin(); it!=DQ.end(); it++)
        cout<<*it<<" ";

    cout<<endl;
}

void maxInSlidingWindow(int * A,int k,int * B,int n){
    deque<int> DQ;
    loop(i,0,k){
        while( !DQ.empty() && A[i] > A[DQ.back()] ){
            DQ.pop_back();
        }
        DQ.push_back(i);
    }
    //showDQ(DQ);

    int result = 0;


    loop(i,k,n){
        B[result++] = A[DQ.front()];

        // element at the front of the queue is out of the window remove it
        if( (i-DQ.front())  >= k ){   DQ.pop_front();  }

        while( !DQ.empty() && A[i] > A[DQ.back()] ){
            DQ.pop_back();
        }
        DQ.push_back(i);
    }
    // last element remains in the deque
    B[result] = A[DQ.front()];

        cout<<"\n";
    loop(i,0,n-k+1){
        cout<<B[i]<<" ";
    }
}


int main(){
    int A[] = {5,3,4,1,6,2,2,4,3,1,5};
    int k = 3;

    int n = sizeof(A)/sizeof(A[0]);
    int B[n-k+1];
    maxInSlidingWindow(A,k,B,n);
}

