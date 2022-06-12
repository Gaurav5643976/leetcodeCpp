class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,j=1;
        set<int> s;
        s.insert(nums[0]);
        int sum=nums[0];
        int ma=sum;
        while(i<n-1 and j<n){
            bool pres=s.find(nums[j])!=s.end();
            if(!pres){
                sum+=nums[j];
                ma=max(ma,sum);
                s.insert(nums[j++]);
            }
            else{
                sum-=nums[i];
                s.erase(nums[i++]);
            }
        }
        return ma;
    }
};