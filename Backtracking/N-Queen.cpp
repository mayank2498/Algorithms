// N Queen problem
#include<bits/stdc++.h>
#include <iostream>

#define loop(i,a,b) for(long i=a;i<b;i++)
#define N 5

using namespace std;


void printSolution(int board[][N]){
    loop(i,0,N){
        loop(j,0,N){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool issafe(int board[][N],int row, int col){
    //check left side
    loop(j,0,col){
        if(board[row][j]) { return false; }
    }

    // check upper diagonal
    for(int i=row-1, j=col-1;i>=0 && j>=0;){
        if(board[i--][j--]){return false;}
    }
    // check lower diagonal
    for(int i=row+1, j=col-1;i<N && j>=0;){
        if(board[i++][j--]){return false;}
    }
    return true;
}



void check(int board[][N],int col){
    if( col==N ) {
        //cout<<"Solution exists\n";
        printSolution(board);
        return ;
    }
    loop(i,0,N){
        if( issafe(board,i,col)  ){
            board[i][col] = 1;
            check(board,col+1);
            board[i][col] = 0;
        }
    }
}


void solveNQ(){
    int board[N][N];
    memset(board,0,sizeof(board));
    check(board,0);

}


int main()
{
    solveNQ();
    return 1;
}

