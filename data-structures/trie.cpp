// Trie insert insert and search

#include<bits/stdc++.h>
#include <string>
#define loop(i,a,b) for(long i=a;i<b;i++)
#define SIZE 26
using namespace std;


struct TrieNode {
    struct TrieNode *children[SIZE];
    bool endOfWord;
};


struct TrieNode* getNode(){
    struct TrieNode * mynode = new TrieNode;

    // initilase all children of the new node to null values
    loop(i,0,SIZE)
    mynode->children[i] = NULL;

    mynode->endOfWord = false;
    return mynode;
}



void insert(struct TrieNode * root, string key){
    struct TrieNode * myroot = root;
    loop(i,0,key.length()){
        int key_index = key[i]-'a';

        if( myroot->children[key_index] == NULL )
            myroot->children[key_index] = getNode();

        myroot = myroot->children[key_index];
    }
    myroot->endOfWord = true;
}

bool search(struct TrieNode * root,string key){
    struct TrieNode * myroot = root;
    loop(i,0,key.length()){
        int key_index = key[i]-'a';
        if(myroot->children[key_index] == NULL){
            return false;
        }
        myroot = myroot->children[key_index];
    }
    if( myroot->endOfWord )
    return true;
    else
    return false;
}


int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };

    struct TrieNode *root = getNode();
    loop(i,0,7){ insert(root,keys[i]);}
    string s = "answer";
    if ( search(root,"answer") == true)
    { cout<<"yes"; }
    if ( !search(root,"dah") ){ cout<<"yoyo great"; }

    return 1;
}

