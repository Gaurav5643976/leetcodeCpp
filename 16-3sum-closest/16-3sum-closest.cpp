class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0,diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(diff>abs(target-sum)){
                    diff=abs(target-sum);
                    ans=sum;
                }
                if(target-sum==0){
                    return sum;
                }
                else if(target-sum>0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};