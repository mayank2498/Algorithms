

//   https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

#define loop(i,a,b) for(int i=a;i<b;i++)
int maxLen(int arr[], int n)
{
   unordered_map<int,int> m;
   int sum = 0,ans=0;
   loop(i,0,n){
       if(arr[i]) sum+=1;
       else sum-=1;
       if (sum==0)
          ans = i+1;
       else if(m.find(sum) != m.end() ){
           ans = max(ans, i-m[sum]);
       }else{
           m[sum] = i;
       }
   }
   return ans;
}
