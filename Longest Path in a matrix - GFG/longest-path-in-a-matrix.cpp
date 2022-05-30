// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>& mat,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ma=0;
        for(auto d:dir){
            int x=d[0]+i,y=d[1]+j;
            if(x>=0 and x<n and y>=0 and y<m and mat[x][y]>mat[i][j]){
                ma=max(ma,dfs(mat,x,y,n,m,dp));
            }
        }
        return dp[i][j]=1+ma;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(dfs(matrix,i,j,n,m,dp),ans);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends