#define loop(i,a,b) for(int i=a;i<b;i++)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int ele;
};

// call by reference with respect to a in main

void change_reference(Node ** y){
    //Node * b = new Node;
    // make the pointer in main to point to a new location , that is b

    // try above mentioned task

    cout<<"\n y = "<<y<<" ,  *y = "<<*y<<"  ,  &(*y) = "<<&(*y)<<"\n\n";
    // we can use the stuct node using (*y)->ele
    cout<<"Struct objects value in main "<<(*y)->ele;
}

int main()
{

    cout<<endl<<"############################"<<endl;
    Node * a = new Node;
    a->ele = 2;
    cout<<"a = "<<a<<" , &a = "<<&a<<endl;
    change_reference(&a);
}

