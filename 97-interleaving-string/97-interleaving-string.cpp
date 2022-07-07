class Solution {
public:
    bool solve(string &s1, string &s2, string &s3,int n, int m, int k,vector<vector<int>>&dp){
        if(n==0 && m==0){
            if(k==0){
                return true;
            }
            return false;
        }
        if(k<=0){
            return false;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        bool ans=false;  
        if(n>0 && s1[n-1]==s3[k-1]){
             ans|=solve(s1,s2,s3,n-1,m,k-1,dp);
        }
        if(m>0 && s2[m-1]==s3[k-1]){
            ans|=solve(s1,s2,s3,n,m-1,k-1,dp);
        }
        return dp[n][m]=ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
            int n=s1.length(),m=s2.length();
            vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
            return solve(s1,s2,s3,n,m,s3.length(),dp);
    }
};