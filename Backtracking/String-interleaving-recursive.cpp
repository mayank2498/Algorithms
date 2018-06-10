

#include<bits/stdc++.h>
#include <string.h>
#define loop(i,a,b) for(long i=a;i<b;i++)

using namespace std;
// Recursive inefficient implementation
int count = 0;
bool isInterleaved(char *A,char *B, char *C){
    ::count++;
    cout<<A<<" : "<<B<<" : "<<C<<endl;

    // if all string A B C become empty it is true
    if ( !*A && !*B && !*C ) {
        //cout<<"Found an interleaving\n";
        return true;
    }

    // one of A or B is non empty and C becomes empty
    if ( *C == '\0' ){
        return false;
    }

    if(*A==*C) {
        bool x = isInterleaved(A+1,B,C+1);
        if(*B==*C){
            return isInterleaved(A,B+1,C+1);
        }
        return x;
    }

    if(*B==*C){
        return isInterleaved(A,B+1,C+1);
    }

    // if C is not matching A or B in any manner
    return false;
}



// a more clear approach

bool isInterleaved(char *A, char *B, char *C)
{
    // Base Case: If all strings are empty
    if (!(*A || *B || *C))
        return true;

    // If C is empty and any of the two strings is not empty
    if (*C == '\0')
        return false;

    // If any of the above mentioned two possibilities is true,
    // then return true, otherwise false
    return ( (*C == *A) && isInterleaved(A+1, B, C+1))
           || ((*C == *B) && isInterleaved(A, B+1, C+1));
}





using namespace std;

int main()
{   ::count = 0;
    char A[] = "aaaa";
    char B[] = "aaaa";
    char C[] = "aaaaaaaa";
    if( isInterleaved(A,B,C) ){
        cout<<"Yes it is an interleaving";
    }else{ cout<<"No its not";}
    cout<<endl<<::count;

    return 0;
}

