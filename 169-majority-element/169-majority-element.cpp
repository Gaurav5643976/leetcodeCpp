class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorElement=nums[0], count=1;
        for(int i=1;i<nums.size();i++){
            if(count==0){
                count=1;
                majorElement=nums[i];
            }
            else if(nums[i]==majorElement){
                count++;
            }
            else{
                count--;
            }
        }
        return majorElement;
    }
};