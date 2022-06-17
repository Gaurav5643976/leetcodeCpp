// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int i,vector<int> adj[],int color,vector<int>& vis){
        vis[i]=color;
        for(auto nbr:adj[i]){
            if(vis[nbr]==-1){
                if(!dfs(nbr,adj,1-color,vis)){
                    return false;
                }
            }
            else if(vis[nbr]==vis[i]){
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            if(!dfs(i,adj,0,vis)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends