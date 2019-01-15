//https://www.hackerrank.com/contests/world-codesprint-12/challenges/red-knights-shortest-path
#define loop(i,a,b) for(int i=a;i<b;i++)
#include <iostream>
#include <queue>
#include<memory.h>
using namespace std;

struct cell{
    int x,y;
    cell(){}
    cell(int a,int b){ x=a; y=b; }
};
cell c;

void display_queue(queue< vector< pair<cell,string> > >  Q){
    vector< pair<cell,string> >::iterator it;
    cout<<"Queue is : ";
    while(!Q.empty()){
        for(int i=0;i<Q.front().size();i++){
            cout<<Q.front()[i].first.x<<":"<<Q.front()[i].first.y<<" "<<Q.front()[i].second<<",";
        }
        cout<<"||";
        Q.pop();
    }
    cout<<"\n\n";
}

bool issafe(cell c,int n){
    if ( c.x <0 || c.y <0 || c.x>=n || c.y>=n ){ return false; }
    return true;
}

void redKnight(int n,cell Start,cell End){
    bool visited[n][n];
    memset(visited,0,sizeof visited);
    visited[Start.x][Start.y] = 1;
    queue< vector< pair<cell,string> > >  Q;
    vector<pair<cell,string>> v;
    v.push_back(make_pair(Start,"S"));
    Q.push(v);


    while(!Q.empty()){
        display_queue(Q);
        vector<pair<cell,string>> path = Q.front();
        Q.pop();

        if ( path.back().first.x == End.x && path.back().first.y == End.y){
            return;
        }
        int choice[6][2] = { {-2,-1},{-2,1},{0,2},{2,1},{2,-1},{0,-2} };
        string choices[6] = { "UL", "UR",  "R",  "LR",  "LL",  "L"};


        for(int i=0;i<6;i++){
            c = cell(path.back().first.x,path.back().first.y);
            cell newcell(c.x+choice[i][0],c.y+choice[i][1]);

            if ( issafe(newcell,n) && !visited[newcell.x][newcell.y] ){
                visited[newcell.x][newcell.y] = 1;
                vector<pair<cell,string>> new_path = path;
                new_path.push_back(make_pair(newcell,choices[i]));
                Q.push(new_path);
            }
        }
    }
}

int main()
{
    int n = 7;
    int si = 6,sj= 6,ei=0 ,ej=1;

    redKnight(n,cell(si,sj),cell(ei,ej));
    return 0;
}