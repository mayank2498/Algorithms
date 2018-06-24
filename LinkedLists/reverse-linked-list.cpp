// reverse a linked list
// iterative 
// using 2 pointers

#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Node{
    int data;
    Node * next;
};

Node * reverse(Node * head){
    if(head==NULL || head->next==NULL){return head;}

    Node * prev = NULL,*curr = head->next;
    while(1){
        head->next = prev;
        prev = head;
        head = curr;
        if(curr == NULL){
            return prev;
        }
        else{
            curr = curr->next;
        }
    }
}



Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// A utility function to print a linked list
void printlist(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main()
{
    Node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    cout << "Given linked list\n";
    printlist(head1);
    head1 = reverse(head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}





