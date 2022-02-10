class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int sum=0,ans=0;
        unordered_map<int,int> um;
        um[0]=1;
        for(auto i:nums){
            sum+=i;
            ans+=um[sum-target];
            um[sum]++;
        }
        return ans;
    }
};