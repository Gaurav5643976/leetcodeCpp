class Solution {
public:
    void solve(vector<string>& ans,string str,int op,int cl){
        if(op==0 and cl==0){
            ans.push_back(str);
            return;
        }
        if(op>0){
            str.push_back('(');
            solve(ans,str,op-1,cl);
            str.pop_back();
        }
        if(op<cl and cl>0){
            str.push_back(')');
            solve(ans,str,op,cl-1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str="";
        solve(ans,str,n,n);
        return ans;
    }
};