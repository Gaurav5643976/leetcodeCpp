class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int n,m;
    int path(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
       int temp=0;
       for(int a=0;a<4;a++)
       {
           int x=i+dx[a],y=j+dy[a];
           if(x>=0 and y>=0 and x<n and y<m and matrix[x][y]>matrix[i][j])
           {
               temp=max(temp,path(x,y,matrix,dp));
           }
       }
       return dp[i][j]=1+temp;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        n=matrix.size(),m=matrix[0].size();  
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               ans=max(ans,path(i,j,matrix,dp));    
            }
        }
        return ans;
    }
};