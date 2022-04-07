class Solution {
public:
    int firstPosition(vector<int>& nums,int target){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int lastPosition(vector<int>& nums,int target){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        ans[0]=firstPosition(nums,target);
        ans[1]=lastPosition(nums,target);
        return ans;
    }
};