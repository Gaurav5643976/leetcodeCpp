class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int minMoves=0;
        for(auto i:nums){
            minMoves+=abs(i-nums[n/2]);
        }
        return minMoves;
    }
};