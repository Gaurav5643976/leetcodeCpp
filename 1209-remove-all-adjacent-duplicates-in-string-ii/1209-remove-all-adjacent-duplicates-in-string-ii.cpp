class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({'#',0});
        for(auto i:s){
            if(st.top().first==i){
                pair<char,int> p=st.top();
                st.pop();
                if(p.second+1!=k){
                    st.push({i,p.second+1});
                }
            }
            else{
                st.push({i,1});
            }
        }
        s="";
        while(!st.empty()){
            pair<char,int> p=st.top();
            st.pop();
            while(p.second--){
                s+=p.first;
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};