class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char> st;
        int n=num.size();
        for(int i=0;i<n;i++){
            if(k<=0){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                while(i<n){
                    ans+=num[i];
                    i++;
                }
                break;
            }
            else{
                if(st.empty()){
                    st.push(num[i]);
                }
                else{
                    while(!st.empty() and st.top()>num[i] and k>0){
                        st.pop();
                        k--;
                    }
                    st.push(num[i]);
                }
                if(i==n-1){
                    while(!st.empty() and k--){
                        st.pop();
                    }
                    while(!st.empty()){
                        ans+=st.top();
                        st.pop();
                    }
                    reverse(ans.begin(),ans.end());
                }
            }
        }
        if(ans[0]=='0'){
            int sz=ans.size(),i=0;
            while(i<sz and ans[i]=='0'){
                i++;
            }
            ans=ans.substr(i);
        }
        if(ans==""){
            ans="0";
        }
        return ans;
    }
};