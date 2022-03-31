class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(auto i:nums){
            um[i]++;
        }
        int ans1=0,ans2=0;
        for(auto i:um){
            if(k==0){
                if(um[i.first]>1){
                    ans1++;
                }
            }
            else{
                if(um.find(i.first+k)!=um.end()){
                    ans2++;
                }
                if(um.find(i.first-k)!=um.end()){
                    ans2++;
                }
                //cout<<endl;
            }
        }
        return ans1+ans2/2;
    }
};