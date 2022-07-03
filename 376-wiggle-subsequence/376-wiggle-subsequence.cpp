class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int u=1,d=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                d=u+1;
            }
            else if(nums[i]>nums[i+1]){
                u=d+1;
            }
        }
        return max(u,d);
    }
};