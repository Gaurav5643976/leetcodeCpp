class Solution {
public:
    bool isAnagram(string s, string t) {
        int A[26]={0},B[26]={0};
        for(auto i:s){
            A[i-'a']++;
        }
        for(auto i:t){
            B[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(A[i]!=B[i]){
                return false;
            }
        }
        return true;
    }
};