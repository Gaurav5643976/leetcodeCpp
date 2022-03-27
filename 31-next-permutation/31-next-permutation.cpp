class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int indx=0;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                int mi=INT_MAX;
                for(int j=i;j<n;j++){
                    if(nums[j]>nums[i-1] and mi>nums[j]){
                        mi=nums[j];
                        indx=j;
                    }
                }
                swap(nums[i-1],nums[indx]);
                indx=i;
                break;
            }
        }
        sort(nums.begin()+indx,nums.end());
    }
};