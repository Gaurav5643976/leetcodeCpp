class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='(' or i=='{' or i=='['){
                st.push(i);
            }
            else{
                if(st.empty()){
                    //cout<<1<<" ";
                    return false;
                }
                else{
                    if(i==')'){
                        if(st.top()=='('){
                            st.pop();
                        }
                        else{
                            //cout<<2<<" ";
                            return false;
                        }
                    }
                    else if(i=='}'){
                        if(st.top()=='{'){
                            st.pop();
                        }
                        else{
                            //cout<<3<<" ";
                            return false;
                        }
                    }
                    else if(i==']'){
                        if(st.top()=='['){
                            st.pop();
                        }
                        else{
                            //cout<<4<<" ";
                            return false;
                        }
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};