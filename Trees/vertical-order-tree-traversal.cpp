// in this case the order of each row is not maintained

// to do that we can do a level order traversal using the same technique and store horizontal distances in the queue
// https://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/
#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
};

Node * newNode(int data){
    Node * x = new Node;
    x->data = data;
    x->left = NULL;
    x->right = NULL;
    return x;
}

void fillmap(map<int,vector<int>> &m ,Node * root ,int hd){
    if(root==NULL){return;}
    m[hd].push_back(root->data);
    fillmap(m,root->right,hd+1);
    fillmap(m,root->left,hd-1);
}

void verticalOrder(Node * root){
    map<int,vector<int>> m;
    fillmap(m,root,0);
    map<int,vector<int>>::iterator it;
    cout<<"Map contents \n\n";
    for(it=m.begin();it!=m.end();it++){
        loop(i,0,it->second.size()){
            cout<<"key = "<<it->first<<" , value : "<<it->second[i]<<endl;
        }
    }
}



int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    verticalOrder(root);
    return 0;
}







