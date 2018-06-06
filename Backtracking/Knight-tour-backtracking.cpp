// Knight tour problem using simple backtracking approach

#include<bits/stdc++.h>
#include <iostream>
#define loop(i,a,b) for(long i=a;i<b;i++)
#define N 8

using namespace std;
// 8 possibilties of a move
int moves[8][2] = {
                   {1,2},
                   {2,1},
                   {-1,2},
                   {-2,1},
                   {-2,-1},
                   {-1,-2},
                   {1,-2},
                   {2,-1}};

    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

void printBoard(int board[][N]){
    loop(i,0,N){
        loop(j,0,N){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


bool issafe(int x,int y,int board[][N]){
    if ( (x < 0) || y < 0 || x>=N || y>=N || board[x][y]>=0) { return false; }
    return true;
}

bool recurr(int board[][N],int x,int y, int movecount){
    //printBoard(board);
    if( movecount == N*N ) {
        cout<<"Found a solution..............................................";
        printBoard(board);
        return true;
    }

    loop(i,0,8){
        //int newx = x + xMove[i];
        //int newy = y + yMove[i];

        int newx = x + moves[i][0];
        int newy = y + moves[i][1];

        if( issafe(newx,newy,board) ){
            board[newx][newy] = movecount;
            bool res = recurr(board,newx,newy,movecount+1);
            if(res){return true;}
            board[newx][newy] = -1;

        }

    }
    return false;
}


void solve(){
    int board[N][N];
    // initialise board to negative values
    memset(board,-1,sizeof(board));

    //starting point of knight
    board[0][0]=0;
    if ( recurr(board,0,0,1) == false ) {
        cout<<"NO solution exists";
    }

}




int main()
{   //cout<<moves[1][0]<<moves[1][1];
    solve();
    return 1;
}

