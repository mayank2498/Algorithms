// double pointers to structures
#include<iostream>

#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;


struct node{
    int a;
    char b;
};

void change(node ** N){
    cout<<N;
    //N->a = 6;
}


int main(){
    node * N = new node;
    //node * N;    wont work
    N->a = 2;
    cout<<sizeof(N)<<endl;  // 0x8fec20
    //cout<<N->a;
    //change(&N);
    node ** x = &N;
    cout<<sizeof(x)<<endl;
    node *** y = &x;
    cout<<sizeof(y);
}

