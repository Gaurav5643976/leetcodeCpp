class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int s=0;
        for(auto i:nums){
            s+=i;
        }
        int sum =s - x;
        if(sum < 0){
            return -1;
        } 
        if(sum == 0){
            return n;
        } 
        int start = 0, cur = 0, len = -1;
        for(int end = 0; end < n; end++)
        {
            if (cur < sum){
                cur += nums[end];
            }
            while (cur >= sum)
            {
                if (cur == sum){
                    len = max(len, end - start + 1);
                }
                cur -= nums[start++];
            }
        }
        return len == -1 ? -1 : n - len;
    }
};