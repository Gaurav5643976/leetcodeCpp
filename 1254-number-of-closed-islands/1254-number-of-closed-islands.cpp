class Solution {
public:
    void bfs(vector<vector<int>>& grid,int i,int j){
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dir={{-1,0},{0,1},{0,-1},{1,0}};
        queue<vector<int>> q;
        q.push({i,j});
        grid[i][j]=1;
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            for(auto i:dir){
                int x=i[0]+v[0],y=i[1]+v[1];
                if(x>=0 and x<m and y>=0 and y<n and grid[x][y]==0){
                    grid[x][y]=1;
                    q.push({x,y});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j] and (i==0 or i==m-1 or j==0 or j==n-1)){
                    bfs(grid,i,j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};