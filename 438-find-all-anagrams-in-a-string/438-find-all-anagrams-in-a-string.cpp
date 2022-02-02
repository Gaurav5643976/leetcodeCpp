class Solution {
public:
    bool isAnagram(vector<int> a,vector<int> b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size()<p.size()){
            return ans;
        }
        vector<int> freqP(26,0),freqS(26,0);
        for(auto i:p){
            freqP[i-'a']++;
        }
        int psz=p.size();
        for(int i=0;i<psz;i++){
            freqS[s[i]-'a']++;
        }
        if(isAnagram(freqP,freqS)){
            ans.push_back(0);
        }
        for(int i=psz;i<s.size();i++){
            //cout<<s[i-psz]<<" "<<s[i]<<endl;
            freqS[s[i-psz]-'a']--;
            freqS[s[i]-'a']++;
            if(isAnagram(freqP,freqS)){
                ans.push_back(i-psz+1);
            }
        }
        return ans;
    }
};