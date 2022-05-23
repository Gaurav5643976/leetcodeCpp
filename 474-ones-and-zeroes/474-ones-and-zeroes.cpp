class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        for(int i=1;i<=l;i++)
        {
            int one=0,zero=0;
            for(char c:strs[i-1])
            {
                if(c=='1')one++;
                else zero++;
            } 
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    
                     if(j>=zero && k>=one)
                    {
                        dp[i][j][k]=max(1+dp[i-1][j-zero][k-one],dp[i-1][j][k]);
                    }
                    else
                    {
                        dp[i][j][k]=dp[i-1][j][k];
                    }
                }
            }
        }
        
        return dp[l][m][n];
    }
};