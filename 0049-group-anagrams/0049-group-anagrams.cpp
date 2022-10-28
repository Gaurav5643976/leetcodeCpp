class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto i:strs){
            string a=i;
            int A[26]={0};
            for(auto j:a){
                A[j-'a']++;
            }
            a="";
            for(int i=0;i<26;i++){
                while(A[i]--){
                    a+=char(i+97);
                }
            }
            mp[a].push_back(i);
        }
        vector<vector<string>> v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        return v;
    }
};