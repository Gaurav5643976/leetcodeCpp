class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size(),n=grid[0].size();
        int i=m-1,j=0;
        while(j<n and i>=0){
            if(grid[i][j]<0){
                count+=(n-j);
                i--;
            }
            else{
                j++;
            }
        }
        return count;
    }
};