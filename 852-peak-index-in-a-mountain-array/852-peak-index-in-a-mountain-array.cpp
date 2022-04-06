class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0, high=arr.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mid==0){
                return 1;
            }
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]){
                return  mid;
            }
            else if(arr[mid]<arr[mid-1]){
                high=mid-1;
            }
            else if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }
        }
        return low;
    }
};