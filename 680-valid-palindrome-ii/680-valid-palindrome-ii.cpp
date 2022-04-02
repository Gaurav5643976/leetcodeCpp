class Solution {
public:
    bool validPalindrome(string s) {
        int start=0,end=s.size()-1;
        while(start<end and s[start]==s[end]){
            start++,end--;
        }
        int st1=start+1,en1=end;
        while(st1<en1 and s[st1]==s[en1]){
            st1++,en1--;
        }
        int st2=start,en2=end-1;
        while(st2<en2 and s[st2]==s[en2]){
            st2++,en2--;
        }
        if(st1<en1 and st2<en2){
            return false;
        }
        return true;
    }
};