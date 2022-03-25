class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1,majorityEle=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==majorityEle){
                count++;
            }
            else{
                count--;
            }
            if(count<0){
                majorityEle=nums[i];
                count=1;
            }
            //cout<<count<<" ";
        }
        return majorityEle;
    }
};