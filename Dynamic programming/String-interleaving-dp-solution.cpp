// Dynamic programming solution of string interleaving problem


#include<bits/stdc++.h>
#include <string.h>
#define loop(i,a,b) for(long i=a;i<b;i++)

using namespace std;

bool dp[1000][1000];

void print_dp(int m,int n){
    cout<<"\n\n###################\nDP table \n";
    loop(i,0,m){
        loop(j,0,n){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}


bool is_interleaved(char * A,char *B, char *C ){
    int N = strlen(A);
    int M = strlen(B);

    //bool dp[M+1][N+1];

    //empty strings will be considered as an interleaving
    dp[0][0] = 1;

    // filling first row of dp table
    loop(i,1,N+1){
        if(C[i-1] == A[i-1]) { dp[0][i] = dp[0][i-1] ;}
        else{
            dp[0][i] = 0;  //We could have used a break here. But we will have to inialise dp as 0 with memset
        }
    }

    //filling first column of dp table

    loop(i,1,N+1){
        if(B[i-1] == C[i-1]){ dp[i][0] = dp[i-1][0]; }
        else {
            dp[i][0] = 0; //We could have used a break here. But we will have to inialise dp as 0 with memset
        }
    }

    loop(i,1,M+1){
        loop(j,1,N+1){
            // item to compare from A and B
            int scanned = C[i+j-1];

            if( B[i-1] == scanned )
                dp[i][j] = dp[i-1][j];
            else if( A[j-1] == scanned )
                dp[i][j] = dp[i][j-1];

            else
                dp[i][j] = 0;
        }
    }
    print_dp(M+1,N+1);
    return dp[M][N];
}


void test(char *A , char *B, char *C){

    if( strlen(C) != strlen(A) + strlen(B) ){
        cout<<"Not at all";
    }

    if( is_interleaved(A,B,C) ){
        cout<<"Yes !";
    }
    else{
        cout<<"No";
    }
}



int main()
{
    cout<<"Starting...";
    char A[] = "aaba";
    char B[] = "axy";
    char C[] = "aaxabya";
    test(A,B,C);
//    test("XXY", "XXZ", "XXZXXXY");
//    test("XY" ,"WZ" ,"WZXY");
//    test ("XY", "X", "XXY");
//    test ("YX", "X", "XXY");
//    test ("XXY", "XXZ", "XXXXZY");
    return 0;
}

