class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        if(n==0){
            return ans;
        }
        int count=0,start=nums[0];
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]-1){
                count++;
            }
            else{
                if(count==0){
                    //cout<<1<<" ";
                    ans.push_back(to_string(start));
                }
                else{
                    //cout<<2<<" ";
                    ans.push_back(to_string(start)+"->"+to_string(start+count));
                }
                count=0;
                start=nums[i+1];
            }
        }
        if(count==0){
            //cout<<1<<" ";
            ans.push_back(to_string(start));
        }
        else{
            //cout<<2<<" ";
            ans.push_back(to_string(start)+"->"+to_string(start+count));
        }
        return ans;
    }
};