class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        um[0]=1;
        int count=0;
        int sum=0;
        for(auto i:nums){
            sum=(sum+i%k+k)%k;
            count+=um[sum];
            um[sum]++;
        }
        return count;
    }
};