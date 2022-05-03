// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    int dp[21][201];
public:
    int solve(vector<int> arr, int n,int k,int curr){
        if(n==0) return curr==k;
        if(dp[n][curr]!=-1)
         return dp[n][curr];
         
        return dp[n][curr]=solve(arr,n-1,k,curr)+solve(arr,n-1,k,curr^arr[n-1]);
        
    }
    int subsetXOR(vector<int> arr, int n, int k) {
        // code here
        int curr=0;
        memset(dp,-1,sizeof(dp));
        return solve(arr,n,k,curr);
    }
    
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends