class Solution {
public:
    string find(string a){
        stack<char> st;
        for(auto i:a){
            if(i=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }
        a.clear();
        while(!st.empty()){
            a+=st.top();
            st.pop();
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
        string S=find(s);
        string T=find(t);
        if(S==T){
            return true;
        }
        return false;
    }
};