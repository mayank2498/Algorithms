// alien dictionary
// Practice link  :  https://practice.geeksforgeeks.org/problems/alien-dictionary/1
// article : https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
// topological sorting


#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Graph{
    int V;
    vector<int> * adj;
    Graph(int vertices){
        V = vertices;
        adj = new vector<int>[V];
    }
};



int alpha_to_number(char x){
    return int(x)-97;
}
char number_to_alpha(int x){
    char ch = char(97+x);
    return ch;
}

void buildGraph(Graph &g,int n,string words[],int alpha){
    loop(i,0,n-1){
        string s1 = words[i];
        string s2 = words[i+1];
        int j=0;
        while( j < min(s1.size(),s2.size())){
            if( s1[j] != s2[j] ){
                int s1_index  = alpha_to_number(s1[j]);
                int s2_index  = alpha_to_number(s2[j]);
                g.adj[s1_index].push_back(s2_index);
                break;
            }
            j++;
        }
    }
}

void printGraph(Graph &g){
    loop(i,0,g.V){
        cout<<number_to_alpha(i)<<" : ";
        loop(j,0,g.adj[i].size()){
            cout<<number_to_alpha(g.adj[i][j])<<" , ";
        }
        cout<<endl;
    }
}

void topologicalSort(Graph &g,stack<char> &stack,int node,bool visited[]){
    if( visited[node] ){return;}

    visited[node] = 1;

    loop(i,0,g.adj[node].size()){
        topologicalSort(g,stack,g.adj[node][i],visited);
    }
    stack.push( number_to_alpha(node) );
}


void printOrder(string words[],int n,int alpha){
    Graph g(alpha);
    buildGraph(g,n,words,alpha);
    printGraph(g);

    stack<char> stack;
    bool visited[alpha];
    memset(visited,0,alpha);
    int  start = alpha_to_number(words[0][0]);
    //cout<<"Start is "<<start<<endl;
    topologicalSort(g,stack,start,visited);
    loop(i,0,alpha){
        topologicalSort(g,stack,i,visited);
    }
    cout<<"Final Answer : "<<endl;
    while(!stack.empty()){
        cout<<stack.top();
        stack.pop();
    }
}


int main()
{
    //string words[] = {"caa", "aaa", "aab"};
    string words[] = { "baa", "abcd", "abca" , "cab" , "cad"};
    int n = sizeof(words)/sizeof(words[0]);
    printOrder(words, n, 4);
}


