class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])]<0){
                ans=abs(nums[i]);
                break;
            }
            nums[abs(nums[i])]*=-1;
        }
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        return ans;
    }
};