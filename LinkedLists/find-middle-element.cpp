
// finding middle element of a linked list using 2 pointers


#define loop(i,a,b) for(int i=a;i<b;i++)
#include<bits/stdc++.h>
#include<math.h>
using namespace std;


/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

// A utility function to print a given linked list
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void printMiddle(struct Node * ptr){
    if(ptr==NULL){return;}
    struct Node * fast = ptr, * slow = ptr;

    // BEWARE
    // while( fast->next != NULL && fast!=NULL )
    //This condition is wrong because if fast becomes null then fast->next will be evaluated first
    //which leads to segmentation error

    while( fast!=NULL && fast->next != NULL ){
        fast = fast->next->next;
        slow = slow->next;
    }
    cout<<"\n Middle element : "<<slow->data<<endl;
}


int main() {
    struct Node* head = NULL;
    int i;

    for (i=5; i>0; i--)
    {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }

    return 0;
}




