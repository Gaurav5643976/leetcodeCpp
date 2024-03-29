class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==0){
                    if(i==0 and j==0){
                        dp[0][0]=1;
                    }
                    else if(i==0){
                        dp[i][j]=dp[i][j-1];
                    }
                    else if(j==0){
                        dp[i][j]=dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};