// add 1 to a linked list
// 1-9-9-9 changes to 2-0-0-0

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

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

Node * add(Node * head){
    Node * temp = head,*prev;
    int sum = 1;
    while(head != NULL){
        sum = sum + head->data;
        head->data = sum%10;
        sum = sum/10;
        prev = head;
        head = head->next;
    }
    if(sum!=0){

        prev->next = newNode(sum);
        //printList(reverse(head));
    }
    return temp;
}

Node * addOne(Node * head){
    Node * newhead = reverse(head);
    newhead = add(newhead);
    return reverse(newhead);
}

int main()
{

    Node *head = newNode(9);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);

    printf("List is ");
    printList(head);

    head = addOne(head);

    printf("\nResultant list is ");
    printList(head);

    return 0;
}





