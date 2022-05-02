// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        // code here
        int res=INT_MAX;
        for(int i=1;i<=N;i++){
            int ans=0;
            vector<bool> vis(N+1,false);
            queue<pair<int,int>> q;
            q.push({i,0});
            vis[i]=true;
            while(!q.empty()){
                pair<int,int> p=q.front();
                q.pop();
                ans=max(ans,p.second);
                for(auto nbr:adj[p.first]){
                    if(!vis[nbr]){
                        vis[nbr]=true;
                        q.push({nbr,p.second+1});
                    }
                }
            }
            
            res=min(res,ans);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends