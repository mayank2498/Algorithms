/*
    Binary Tree to Doubly Linked List( Inorder Based)

    https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/

*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)

struct node {
    node * left;
    node * right;
    char data;
};

node * make(int data){
    node * x = new node;
    x->left = NULL;
    x->right = NULL;
    x->data = data;
    return x;
}


void convert(node * root,node ** head_ref){
    if( root == NULL ){return ;}

    convert(root->right,&(*head_ref));

    if(*head_ref == NULL){
        *head_ref = root;
        root->right = NULL;
        root->left = NULL;
    }
    else{
        node * temp = *head_ref;
        *head_ref = root;
        (*head_ref)->right = temp;
        temp->left = *head_ref;
    }
    convert(root->left,&(*head_ref));
}


int main()
{
    node * root = make('a');
    root->left = make('b'); root->right = make('c');
    root->left->left = make('d'); root->left->right = make('e');
    root->right->left = make('f'); root->right->right = make('g');

    /*
         a
       b   c
    d  e   f  g

    Doubly linked list should be  d=b=e=a=f=c=g
    Inorder
    */
    node * head = NULL;
    convert(root,&head);

    // tree is converted into a doubly linked list
    // with head as the root of doubly linked list

    node * x = head;
    while(x!=NULL){
        cout<<x->data<<" ";
        x = x->right;
    }

    return 0;
}

