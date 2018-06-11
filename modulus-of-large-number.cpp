// C++ program to compute mod of a big number represented
// as string

#include<iostream>
using namespace std;

// Function to compute num (mod a)
int mod(string num, int a)
{
    // Initialize result
    int res = 0;
    int i;
    //cout<<"res is "<<res<<endl;
    // One by one process all digits of 'num'
    for (i = 0; i < num.length(); i++){
         cout<<res<<endl;
         res = (res*10 + (int)num[i] - '0') %a;
    }
    return res;
}

// Driver program
int main()
{
    string num = "1234";
    cout << mod(num, 5);
    return 0;
}

