class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==0 ){
                if(nums[mid]>nums[mid+1]){
                    return mid;
                }
                else{
                    low=mid+1;
                }
            }
            else if(mid==n-1){
                if(nums[mid]>nums[mid-1]){
                    return mid;
                }
                else{
                    high=mid-1;
                }
            }
            else if(mid>0 and mid<n-1){
                if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]){
                    return mid;
                }
                else if(nums[mid]<nums[mid-1]){
                    high=mid-1;
                }
                else if(nums[mid]<nums[mid+1]){
                    low=mid+1;
                }
            }
        }
        return low;
    }
};