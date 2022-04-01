class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ma=0,n=nums.size();
        for(int i=0;i<=ma;i++){
            ma=max(ma,nums[i]+i);
            if(ma>=n-1){
                return true;
            }
        }
        return false;
    }
};