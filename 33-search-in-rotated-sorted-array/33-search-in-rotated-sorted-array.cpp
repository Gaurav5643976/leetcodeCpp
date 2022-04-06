class Solution {
public:
    int minIndex(vector<int>& arr){
        int n=arr.size();
        int low=0, high=n-1;
        while(low<high){
            if(arr[low]<arr[high]){
                return low;
            }
            int mid=low+(high-low)/2;
            int prev=(mid-1+n)%n,next=(mid+1)%n;
            if(arr[mid]<arr[prev] and arr[mid]<arr[next]){
                return  mid;
            }
            else if(arr[low]<=arr[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    int binarySearch(vector<int>& nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index=minIndex(nums);
        return max(binarySearch(nums,0,index-1,target),binarySearch(nums,index,nums.size()-1,target));
    }
};