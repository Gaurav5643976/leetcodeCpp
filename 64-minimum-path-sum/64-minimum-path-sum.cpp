class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int t[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0){
                    t[i][j]=grid[i][j];
                }
                else if(i==0){
                    t[i][j]=grid[i][j]+t[i][j-1];
                }
                else if(j==0){
                     t[i][j]=grid[i][j]+t[i-1][j];
                }
                else{
                    t[i][j]=grid[i][j]+min(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n-1][m-1];
    }
};