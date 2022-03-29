// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
vector<int> FindWays(vector<vector<int>>&matrix){
    // Code here
    int n=matrix.size();
    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]={0,matrix[i][j]};
        }
    }
    dp[0][0].first=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                int val1=0,val2=0;
                if(j>0 and (matrix[i][j-1]==1 or matrix[i][j-1]==3)){
                    dp[i][j].first+=dp[i][j-1].first;
                    val1=dp[i][j-1].second;
                }
                if(i>0 and (matrix[i-1][j]==2 or matrix[i-1][j]==3)){
                    dp[i][j].first+=dp[i-1][j].first;
                    val2=dp[i-1][j].second;
                }
                dp[i][j].first%=1000000007;
                dp[i][j].second+=max(val1,val2);
                if(dp[i][j].first==0){
                    dp[i][j].second=0;
                }
        }
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j.first<<" "<<j.second<<"    ";
    //     }
    //     cout<<endl;
    // }
    vector<int> ans;
    ans.push_back(dp[n-1][n-1].first);
    ans.push_back(dp[n-1][n-1].second);
    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends