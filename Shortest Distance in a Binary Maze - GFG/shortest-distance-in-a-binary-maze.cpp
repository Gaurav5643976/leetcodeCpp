//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size(), m=grid[0].size();
        if(!grid[source.first][source.second]){
            return -1;
        }
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        queue<vector<int>> q;
        q.push({source.first, source.second, 0});
        grid[source.first][source.second]=0;
        while(!q.empty()){
            vector<int> v=q.front();
            //cout<<v[0]<<" "<<v[1]<<endl;
            if(v[0]==destination.first and v[1]==destination.second){
                return v[2];
            }
            q.pop();
            for(int i=0;i<4;i++){
                int x=v[0]+dir[i][0], y=v[1]+dir[i][1];
                if (x>=0 and x<n and y>=0 and y<m and grid[x][y]){
                    q.push({x,y,v[2]+1});
                    grid[x][y]=0;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends