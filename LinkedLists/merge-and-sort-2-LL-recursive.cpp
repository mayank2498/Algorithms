// merge and sort two linked lists
// recursive version

#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Node{
    int data;
    Node * next;
};


void printList(Node * x){
    cout<<endl<<"Current linked list \n";
    while(x!=NULL){
        cout<<x->data<<" ";
        x = x->next;
    }
}

struct Node * SortedMerge(Node * a,Node * b){

    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    cout<<"*a = "<<a->data<<" , *b = "<<b->data<<endl;

    Node * result = NULL;

    if(a->data <= b->data){
        result = a;
        result->next = SortedMerge(a->next,b);

    }
    else{
        result = b;
        result->next = SortedMerge(a,b->next);
    }

    return result;
} 
/*

Memory inefficient

struct Node * SortedMerge(Node * a,Node * b){

    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    cout<<"*a = "<<a->data<<" , *b = "<<b->data<<endl;

    Node * result = new Node;

    if(a->data <= b->data){
        result->data = a->data;
        result->next = SortedMerge(a->next,b);

    }
    else{
        result->data = b->data;
        result->next = SortedMerge(a,b->next);
    }

    return result;
} 
*/


void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}


int main()
{
    /* Start with the empty list */
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;

    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);

    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);

    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
}

