class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] or grid[n-1][n-1]){
            return -1;
        }
        vector<vector<int>> A={{-1,-1},{-1,0},{0,-1},{1,1},{0,1},{1,0},{-1,1},{1,-1}};
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        while(!q.empty()){
            vector<int> temp=q.front();
            q.pop();
            if(temp[0]==n-1 and temp[1]==n-1){
                return temp[2];
            }
            for(auto i:A){
                int x=temp[0]+i[0],y=temp[1]+i[1];
                if(x>=0 and x<n and y>=0 and y<n and grid[x][y]==0){
                    grid[x][y]=1;
                    q.push({x,y,temp[2]+1});
                }
            }
        }
        return -1;
    }
};