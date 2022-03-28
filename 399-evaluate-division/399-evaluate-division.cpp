class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string, double>>>& um,string node,string end,unordered_set<string>& st,double& val){
        if(!um.count(node)){
            return -1.00000;
        }
        if(node==end){
            return val;
        }
        st.insert(node);
        for(auto i:um[node]){
            if(!st.count(i.first)){
                double k=val*i.second;
                double res= dfs(um,i.first,end,st,k);
                if(res!=-1.00000){
                    return res;
                }
            }
        }
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string, double>>> um;
        int n=equations.size();
        for(int i=0;i<n;i++){
            um[equations[i][0]].push_back({equations[i][1],values[i]});
            um[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double> ans;
        double val=1;
        for(auto i:queries){
            unordered_set<string> st;
            ans.push_back(dfs(um,i[0],i[1],st,val));
        }
        return ans;
    }
};