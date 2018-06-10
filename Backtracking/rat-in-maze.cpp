//  https://www.geeksforgeeks.org/find-paths-from-corner-cell-to-middle-cell-in-maze/

/*
    Given a square maze containing positive numbers,
     find all paths from a corner cell (any of the extreme four corners)
     to the middle cell. We can move exactly n steps from a cell in 4 directions
     i.e. North, East, West and South where n is value of the cell,

*/

#include<bits/stdc++.h>
#include <string.h>
#define loop(i,a,b) for(long i=a;i<b;i++)
#define N 9


using namespace std;

void printPath(vector<pair<int,int>> path){
    loop(i,0,path.size()){
        cout<<"( "<<path[i].first<<" , "<<path[i].second<<" )\n";
    }
}


bool check_valid(int i,int j, bool visited[N][N]){
    if( i>=N || i<0 || j>=N || j<0 || visited[i][j] ) {
        return false;
    }
    return true;
}


int pathTomove[4][2] = {{1,0},
                {0,1},
                {-1,0},
                {0,-1}};


bool recurr(vector< pair<int,int> > path, int maze[N][N] ,bool visited[N][N], int i, int j){
    if(i==N/2 && j==N/2) { printPath(path); cout<<"Found the path....."; return true; }

    if ( ! check_valid(i,j,visited) ) {
        return false;
    }

    // check for 4 paths
    loop(t,0,4){
        int x = i + pathTomove[t][0] * maze[i][j];
        int y = j + pathTomove[t][1] * maze[i][j];
        if(check_valid(x,y,visited)) {
            visited[i][j] = 1;
            path.push_back(make_pair(i,j));
            if( recurr(path,maze,visited,x,y) ){
                return true;
            }
            visited[i][j] = 0;
            path.pop_back();
        }
    }
    return false;
}


void findPathInMaze(int maze[N][N]){
    bool visited[N][N];
    memset(visited,0,sizeof(visited));
    vector< pair<int,int> > path;
    path.clear();
    bool result = recurr(path,maze,visited,0,0);
}


int main()
{
    int maze[N][N] =
    {
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
    };

    findPathInMaze(maze);

    return 0;
}

