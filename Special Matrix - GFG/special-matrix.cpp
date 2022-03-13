// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    vector<vector<long long>> v(n,vector<long long>(m,1));
	    for(auto i:blocked_cells){
	        v[i[0]-1][i[1]-1]=0;
	    }
	    if(v[0][0]==0){
	        return 0;
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(v[i][j]){
    	            if(i==0 and j==0){
    	                v[i][j]=1;
    	            }
    	            else if(i==0){
    	                v[i][j]=v[i][j-1];
    	            }
    	            else if(j==0){
    	                v[i][j]=v[i-1][j];
    	            }
    	            else{
    	                v[i][j]=(v[i-1][j]+v[i][j-1])%1000000007;
    	            }
	            }
	        }
	    }
	    return v[n-1][m-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends