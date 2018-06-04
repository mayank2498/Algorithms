#define loop(i,a,b) for(int i=a;i<b;i++)
#include <cmath>
#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#define size 1000
using namespace std;

bool visited[size][size];
struct cell {
    int x,y;
    int dist;
    cell(){ }
    cell(int a,int b,int distance){
        x = a;
        y = b;
        dist = distance;
    }
};

bool isInside(cell t){
    if ( t.x >= 0 && t.y >= 0 && t.x < size && t.y < size ){
        return true;
    }
    else {
        return false;
    }
}

int find_steps_knight(int destination[]){

    loop(i,0,size){
        loop(j,0,size){
            visited[i][j] = false;
        }
    }

    cell temp,new_cell;
    queue<cell> q;
    int X[] = {2,2,1,1,-2,-2,-1,-1};
    int Y[] = {1,-1,2,-2,1,-1,2,-2};

    q.push(cell(0,0,0));
    visited[0][0] = true;

    while(!q.empty()){

        temp = q.front();
        q.pop();
        cout<<"( "<<temp.x<<" "<<temp.y<<" )"<<endl;
        if (temp.x == destination[0] && temp.y == destination[1]){
            return temp.dist;
        }

        for(int i=0;i<8;i++){
            new_cell = cell(temp.x + X[i],temp.y + Y[i],temp.dist + 1);
            if ( !visited[new_cell.x][new_cell.y] && isInside(new_cell)  ){
                q.push(new_cell);
                visited[new_cell.x][new_cell.y] = true;
            }
        }
    }
}

int main() {
    // knight starts from cell (0,0)
    
    int destination[2] = {1,1};
    cout<<find_steps_knight(destination)<<endl;
    return 0;
}


