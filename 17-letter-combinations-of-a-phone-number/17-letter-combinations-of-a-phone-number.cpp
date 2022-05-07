class Solution {
public:
    void solve(vector<string>& ans,vector<string> v,string op){
        int n=op.size();
        if(n==v.size()){
            ans.push_back(op);
            return;
        }
        for(auto i:v[n]){
            solve(ans,v,op+i);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        vector<string> ans;
        map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        for(auto i:digits){
            v.push_back(m[i]);
        }
        if(v.size()!=0){
            solve(ans,v,"");
        }
        return ans;
    }
};