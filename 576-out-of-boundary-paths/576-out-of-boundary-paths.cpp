class Solution {
public:
    
    int rowSize,colSize;
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int md=1e9+7;
    
    int dfsSimulate(int row,int col,int moveRemaining,vector<vector<vector<int>>>&dp){
         
         if(row<0 || col<0 || row>=rowSize || col>=colSize)
         {
             return 1;
         }
         
         if(moveRemaining<=0)
            return 0;
        
         if(dp[row][col][moveRemaining]>=0)
             return dp[row][col][moveRemaining]%md;
        
         dp[row][col][moveRemaining]=0;
        
         for(int i=0;i<4;i++){
             
             int x=row+dx[i];
             int y=col+dy[i];
             
             dp[row][col][moveRemaining]=(dp[row][col][moveRemaining]+dfsSimulate(x,y,moveRemaining-1,dp))%md;
         }
         
         return dp[row][col][moveRemaining]%md;   
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        rowSize=m;
        colSize=n;
        
        return dfsSimulate(startRow,startColumn,maxMove,dp);
    }
};