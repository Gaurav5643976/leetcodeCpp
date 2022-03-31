class Solution {
public:
    int binarySearch(vector<int>& nums,int low,int high,int m){
        int ans=0;
        while(low<high){
            int mid=low+(high-low)/2+1;
            int count=1,sum=0;
            for(auto i:nums){
                sum+=i;
                if(sum>mid){
                    if(i>mid){
                        count=m+1;
                        break;
                    }
                    sum=i;
                    count++;
                }
            }
            if(count<=m){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid;
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int weightsSum=0;
        for(auto i:weights){
            weightsSum+=i;
        }
        return binarySearch(weights,0,weightsSum,days);
    }
};