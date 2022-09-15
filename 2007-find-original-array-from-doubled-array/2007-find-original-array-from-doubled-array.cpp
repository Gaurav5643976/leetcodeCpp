class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n&1){
            return {};
        }
        unordered_map<int,int> um;
        for(auto i:changed){
            um[i]++;
        }
        vector<int> keys;
        for(auto i:um){
            keys.push_back(i.first);
        }
        sort(keys.begin(),keys.end());
        vector<int> ans;
        for(auto i:keys){
            if(um[i]>um[2*i]){
                return {};
            }
            for (int j = 0; j < um[i]; ++j, um[2 * i]--){
                 ans.push_back(i);
            }        
        }
        return ans;
    }
};