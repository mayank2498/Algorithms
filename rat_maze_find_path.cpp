#define loop(i,a,b) for(int i=a;i<b;i++)
#include <cmath>
#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#define size 1000
using namespace std;
#define N 4

int count = 0;

bool isSafe(bool maze[N][N],int x,int y){
    if( !maze[x][y] || x >= N || y >= N ){
        return false;
    }
    else{
        return true;
    }
}


void print_path(bool path[N][N]){
    loop(i,0,N){
        loop(j,0,N){
            cout<<path[i][j]<<" ";
        }
        cout<<"\n";
    }
}



bool solve_mazeUtil(bool maze[N][N],int x,int y,bool path[N][N]){

    print_path(path);
    cout<<endl<<endl;
    if ( x==N-1 && y==N-1) {
        path[x][y] = 1;
        return true;
    }
    if ( isSafe(maze,x,y) ) {
        path[x][y] = 1;

        if ( solve_mazeUtil(maze,x+1,y,path) ){
            return true;
        }

        if ( solve_mazeUtil(maze,x,y+1,path) ){
            return true;
        }

        path[x][y] = 0;
        return false;
    }

    else{
        return false;
    }
}


void solve(bool maze[N][N]){

    bool path[N][N] = {{0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}};

    if ( solve_mazeUtil(maze,0,0,path) ){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

}

int main() {
    bool maze[N][N]  =  {
        {1, 1, 1, 0},
        {0, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };

    solve(maze);
    return 0;
}

