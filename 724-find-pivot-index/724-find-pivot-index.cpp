class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        int left=0;
        for(int i=0;i<n;i++){
            if(2*left==totalSum-nums[i]){
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};