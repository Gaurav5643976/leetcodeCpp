class Solution {
public:
     int md;
    int helper(int n, int k, int target,vector<vector<int>>&dp){
        
        if(target==0 && n==0)
            return 1;
        
        if(n<=0 || target<0)
            return 0;
        
        if(dp[n][target]!=-1)
            return dp[n][target];
            
        long long int ans=0;
        
        for(int i=k;i>=1;i--){
            ans=(ans+helper(n-1,k,target-i,dp))%md;
        }
        
        return dp[n][target]=ans%md;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        md=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return helper(n,k,target,dp);
    }
};