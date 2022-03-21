class Solution {
public:
    vector<vector<pair<int,int>>> vvp;
    void bfs(vector<vector<int>>& grid,int i,int j){
        vector<pair<int,int>> vp;
        vp.push_back({i,j});
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        grid[i][j]=0;
        queue<vector<int>> q;
        q.push({i,j});
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            for(auto i:dir){
                int x=i[0]+v[0],y=i[1]+v[1];
                if(x>=0 and x<m and y>=0 and y<n and grid[x][y]==1){
                    q.push({x,y});
                    grid[x][y]=0;
                    vp.push_back({x,y});
                }
            }
        }
        vvp.push_back(vp);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    bfs(grid,i,j);
                }
            }
        }
        for(auto i:vvp[0]){
            for(auto j:vvp[1]){
                ans=min(ans,abs(i.first-j.first)+abs(i.second-j.second)-1);
            }
        }
        return ans;
    }
};