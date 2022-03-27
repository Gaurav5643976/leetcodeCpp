class Solution {
public:
    void dfs(vector<vector<int>>& grid2,int i,int j,int n,int m,vector<pair<int,int>>& vp){
        if(i<0 or i>=n or j<0 or j>=m or grid2[i][j]==0){
            return;
        }
        vp.push_back({i,j});
        grid2[i][j]=0;
        dfs(grid2,i-1,j,n,m,vp);
        dfs(grid2,i,j-1,n,m,vp);
        dfs(grid2,i+1,j,n,m,vp);
        dfs(grid2,i,j+1,n,m,vp);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size(),m=grid2[0].size();
        vector<vector<pair<int,int>>> islands; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    vector<pair<int,int>> vp;
                    dfs(grid2,i,j,n,m,vp);
                    islands.push_back(vp);
                }
            }
        }
        int countSubIslands=0;
        for(auto i:islands){
            bool status=true;
            for(auto j:i){
                if(grid1[j.first][j.second]==0){
                    status=false;
                    break;
                }
            }
            if(status){
                countSubIslands++;
            }
        }
        return countSubIslands;
    }
};