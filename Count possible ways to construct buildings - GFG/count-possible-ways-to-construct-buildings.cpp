// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	#define MOD 1000000007
	int TotalWays(int N)
	{
	     if(N==1) return 4 ; 
	     if(N==2) return 9 ; 
	     vector<long long>dp(N+1,0)  ;
	     dp[1] = 2; 
	     dp[2] = 3 ; 
	     dp[3] = 5 ; 
	     for(int i=4;i<=N;i++){
	         dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD)  ; 
	     }
	     
	     return (dp[N]*dp[N]) % MOD; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends