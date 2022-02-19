// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& M) {
        // Code here
        int n=M.size(),m=M[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]=='1'){
                    M[i][j]='0';
                    ans++;
                    queue<pair<int,int>> q;
                    vector<vector<int>> v={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        //cout<<p.first<<" "<<p.second<<endl;
                        for(auto k:v){
                            int x=p.first+k[0],y=p.second+k[1];
                            if(x>=0 and x<n and y>=0 and y<m and M[x][y]=='1'){
                                q.push({x,y});
                                M[x][y]='0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends