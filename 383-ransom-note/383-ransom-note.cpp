class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int A[26]={0},B[26]={0};
        for(auto i:ransomNote){
            A[i-'a']++;
        }
        for(auto i:magazine){
            B[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(A[i]>B[i]){
                return false;
            }
        }
        return true;
    }
};