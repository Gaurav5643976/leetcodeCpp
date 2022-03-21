class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,vector<int>> um;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(um.find(s[i])==um.end()){
                um[s[i]].push_back(i);
                um[s[i]].push_back(i);
            }
            else{
                um[s[i]][1]=i;
            }
        }
        vector<pair<int,int>> vp;
        for(auto i:um){
            vp.push_back({i.second[0],i.second[1]});
        }
        sort(vp.begin(),vp.end());
        int a=vp[0].first,b=vp[0].second;
        for(int i=1;i<vp.size();i++){
            if(vp[i].first<b){
                b=max(b,vp[i].second);
            }
            else{
                ans.push_back(b-a+1);
                a=vp[i].first,b=vp[i].second;
            }
        }
        ans.push_back(b-a+1);
        return ans;
    }
};