class Solution {
public:
    bool isOkay(vector<int>& q,int mid,int m){
        int count=0;
        for(auto i:q){
            count+=i/mid;
            if(i%mid){
                count++;
            }
        }
        return count<=m;
    }
    int binarySearch(vector<int>& nums,int low,int high,int t){
        int ans=high;
        while(low<high){
            int mid=low+(high-low)/2;
            if(isOkay(nums,mid,t)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(isOkay(nums,low,t)){
            ans=low;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        return binarySearch(nums,low,high,threshold);
    }
};