class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,string> m;
        for(int i=0;i<26;i++){
            m[char(97+i)]="";
        }
        int n=pattern.size();
        for(int i=0;i<n;i++){
            m[pattern[i]]+=to_string(i);
        }
        set<string> s;
        for(auto i:m){
            s.insert(i.second);
        }
        vector<string> ans;
        for(auto i:words){
            unordered_map<char,string> mp;
            for(int j=0;j<26;j++){
                mp[char(97+j)]="";
            }
            string str=i;
            int l=str.size();
            for(int j=0;j<l;j++){
                mp[str[j]]+=to_string(j);
            }
            set<string> st;
            for(auto j:mp){
                st.insert(j.second);
            }
            if(st==s){
                ans.push_back(i);
            }
        }
        return ans;
    }
};