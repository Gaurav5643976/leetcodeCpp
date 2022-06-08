class Solution {
public:
    bool isPalindrome(string S){
        int n=S.size();
        for(int i=0;i<n/2;i++){
            if(S[i]!=S[n-1-i]){
                return false;
            }
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s==""){
            return 0;
        }
        if(isPalindrome(s)){
            return 1;
        }
        return 2;
    }
};