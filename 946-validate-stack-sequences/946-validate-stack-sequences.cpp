class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_set<int> s;
        stack<int> st;
        int n=pushed.size(),m=popped.size();
        int i=0,j=0;
        while(i<n and j<m){
            if(st.empty()){
                st.push(pushed[i]);
                i++;
            }
            else{
                if(st.top()==popped[j]){
                    st.pop();
                    j++;
                }
                else{
                    st.push(pushed[i]);
                    i++;
                }
            }
        }
        while(j<m and !st.empty()){
            if(st.top()==popped[j]){
                st.pop();
                j++;
            }
            else{
                return false;
            }
        }
        if(i<n or !st.empty()){
            return false;
        }
        return true;
    }
};