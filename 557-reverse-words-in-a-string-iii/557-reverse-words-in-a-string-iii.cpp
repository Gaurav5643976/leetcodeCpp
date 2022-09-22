class Solution {
public:
    string reverseWords(string s) {
        string revS="";
        int n=s.size();
        for(int i=0;i<n;i++){
            string t="";
            while(i<n and s[i]!=' '){
                t+=s[i];
                i++;
            }
            reverse(t.begin(),t.end());
            revS+=t;
            if(i!=n){
                revS+=' ';
            }
        }
        return revS;
    }
};