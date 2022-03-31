class Solution {
public:
    int bfs(vector<vector<int>>& grid,int i,int j){
        int area=1;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        grid[i][j]='0';
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
                    area++;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxArea=max(maxArea,bfs(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};