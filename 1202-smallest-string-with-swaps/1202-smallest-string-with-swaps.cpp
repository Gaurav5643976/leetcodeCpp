class Solution {
public:
    void dfs(vector<int> adj[],int i,vector<bool>& vis,vector<int>& v){
        v.push_back(i);
        vis[i]=true;
        for(auto nbr:adj[i]){
            if(!vis[nbr]){
                dfs(adj,nbr,vis,v);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ans=s;
        int n=s.size();
        vector<int> adj[n];
        for(auto i:pairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> v;
                dfs(adj,i,vis,v);
                string str="";
                for(auto j:v){
                    str+=s[j];
                }
                sort(str.begin(),str.end());
                sort(v.begin(),v.end());
                int k=0;
                for(auto j:v){
                    ans[j]=str[k];
                    k++;
                }
            }
        }
        return ans;
    }
};