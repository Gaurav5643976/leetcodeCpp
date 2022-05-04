class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(auto i:nums){
            um[i]++;
        }
        int ans=0;
        for(auto i:um){
            if(um.find(k-i.first)!=um.end()){
                if(k-i.first==i.first){
                    ans+=um[i.first]/2;
                    um[i.first]=0;
                }
                else{
                    ans+=min(um[i.first],um[k-i.first]);
                    um[i.first]=0;
                    um[k-i.first]=0;
                }
            }
        }
        return ans;
    }
};