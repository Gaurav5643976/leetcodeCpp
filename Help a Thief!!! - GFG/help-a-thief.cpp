// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        int ans=0;
        vector<vector<int>> dp(N,vector<int>(2));
        for(int i=0;i<N;i++){
            dp[i][0]=B[i],dp[i][1]=A[i];
        }
        sort(dp.begin(),dp.end());
        for(int i=N-1;i>=0;i--){
            int mi=min(T,dp[i][1]);
            T-=mi;
            ans+=(mi*dp[i][0]);
            if(T==0){
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends