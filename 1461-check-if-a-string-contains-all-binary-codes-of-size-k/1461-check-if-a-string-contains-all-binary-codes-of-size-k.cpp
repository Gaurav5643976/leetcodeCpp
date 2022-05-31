class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n=s.size();
        for(int i=0;i<n-k+1;i++){
            st.insert(s.substr(i,k));
        }
        int m=pow(2,k);
        if(m==st.size()){
            return true;
        }
        return false;
    }
};