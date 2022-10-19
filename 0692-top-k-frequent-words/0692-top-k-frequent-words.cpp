class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto i:words){
            if(m.find(i)!=m.end()){
                m[i]++;
            }
            else{
                m[i]=1;
            }
        }
        map<int,vector<string>> mp;
        for(auto i:m){
            mp[i.second].push_back(i.first);
        }
        vector<string> ans;
        int c=0;
        map<int,vector<string>>::reverse_iterator i;
        for(auto i=mp.rbegin();i!=mp.rend();i++){
            vector<string> v=i->second;
            sort(v.begin(),v.end());
            for(auto j:v){
                ans.push_back(j);
                c++;
                if(c==k){
                    break;
                }
            }
            if(c==k){
                break;
            }
        }
        return ans;
    }
};