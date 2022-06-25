// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
       long long Total = 1e18;
    bool overDemand = false;
    long long water(vector<int> adj[], int *Cap, int visited[], int source)
    {
        visited[source] = 1;
        long long ans = 0;
        int count = 0;
        for (auto x : adj[source])
        {
            if (visited[x]==0)
            {
                count++;
                long long temp = water(adj, Cap, visited, x);
                ans = max(temp, ans);
            }
        }
        long long waterReq = count * ans + Cap[source-1];
        if(waterReq>Total) overDemand = true;
        return waterReq;
    }
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap)
    {
        // Code here
        int visited[N + 1] = {0};
        vector<int> adj[N+1];
        for(int i=0;i<Edges.size();i++)
        {
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        long long  ans = water(adj, Cap, visited, S);
        return overDemand==true ? -1 : ans;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends