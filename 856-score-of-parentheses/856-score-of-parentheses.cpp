class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        st.push(0);
        for(auto i:S){
            if(i=='('){
                st.push(0);
            }
            else{
                int u=st.top();
                st.pop();
                int v=st.top();
                st.pop();
                int nxt=v+max(1,2*u);
                st.push(nxt);
            }
        }
        return st.top();
    }
};