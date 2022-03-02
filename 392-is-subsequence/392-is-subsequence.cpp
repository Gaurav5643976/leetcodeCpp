class Solution {
public:
    bool isSubsequence(string s, string t) {
        int S=s.size(),T=t.size();
        int i=0,j=0;
        while(i<S and j<T){
            if(s[i]==t[j]){
                i++,j++;
            }
            else{
                j++;
            }
        }
        if(i>=S){
            return true;
        }
        return false;
    }
};