class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> res=nums;
        sort(nums.begin(),nums.end());
        int a=0,b=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=res[i]){
                a=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=res[i]){
                b=i;
                break;
            }
        }
        return b-a+1;
    }
};