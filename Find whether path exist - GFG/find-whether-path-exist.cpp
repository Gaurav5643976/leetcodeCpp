// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool solve(vector<vector<int>>& grid,int n,int i,int j,int dx,int dy){
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j]==0){
            return false;
        }
        if(grid[i][j]==2){
            return true;
        }
        int val=grid[i][j];
        grid[i][j]=0;
        bool res=solve(grid,n,i+1,j,dx,dy) or solve(grid,n,i,j+1,dx,dy) or solve(grid,n,i-1,j,dx,dy) or solve(grid,n,i,j-1,dx,dy);
        grid[i][j]=val;
        return res;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int sx,sy,dx,dy;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    sx=i,sy=j;
                }
                else if(grid[i][j]==2){
                    dx=i,dy=j;
                }
            }
        }
        return solve(grid,n,sx,sy,dx,dy);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends