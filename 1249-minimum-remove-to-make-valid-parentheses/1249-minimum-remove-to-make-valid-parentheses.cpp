class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                    ans+=s[i];
                }
            }
            else if(s[i]=='('){
                st.push(s[i]);
                ans+=s[i];
            }
            else{
                ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        int extraOpenParenthesis=st.size();
        while(extraOpenParenthesis--){
            size_t f=ans.find('(');
            ans.erase(f,1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};