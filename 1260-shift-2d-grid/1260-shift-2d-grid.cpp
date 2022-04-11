class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        while(k--){
            vector<int> v;
            for(int i=0;i<m;i++){
                v.push_back(grid[i][n-1]);
            }
            for(int j=n-1;j>=1;j--){
                for(int i=0;i<m;i++){
                    grid[i][j]=grid[i][j-1];
                }
            }
            for(int i=0;i<m;i++){
                if(i==m-1){
                    grid[0][0]=v[m-1];
                }
                else{
                    grid[i+1][0]=v[i];
                }
            }
        }
        return grid;
    }
};