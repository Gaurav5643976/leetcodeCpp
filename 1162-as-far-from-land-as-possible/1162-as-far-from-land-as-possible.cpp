class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=-1;
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j,1});
                }
            }
        }
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            for(auto i:dir){
                int x=i[0]+v[0],y=i[1]+v[1];
                if(x>=0 and x<n and y>=0 and y<n and grid[x][y]==0){
                    q.push({x,y,v[2]+1});
                    grid[x][y]=v[2]+1;
                }
            }
        }
        for(auto i:grid){
            for(auto j:i){
                ans=max(ans,j);
            }
        }
        return (ans==1 or ans==-1)?-1:ans-1;
    }
};