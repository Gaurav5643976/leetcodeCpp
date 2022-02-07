class Solution {
public:
    char findTheDifference(string s, string t) {
        int S[26]={0},T[26]={0};
        for(auto i:s){
            S[i-'a']++;
        }
        for(auto i:t){
            T[i-'a']++;
        }
        char ans;
        for(int i=0;i<26;i++){
            if(S[i]!=T[i]){
                ans='a'+i;
                break;
            }
        }
        return ans;
    }
};