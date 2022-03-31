// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    void dfs(int s , vector<int>graph[] , vector<int> &dp , int par , int d){
        dp[d]++;
        for(int i = 0 ; i < graph[s].size() ; i++){
            if(graph[s][i] != par){
                dfs(graph[s][i] , graph , dp, s , 1 - d);
            }
        }
       
    }
    public:
    int countOfNodes(vector<int> graph[], int n)
    {
        // code here
        vector<int>dp(2 , 0);
        dfs(1 , graph , dp , -1 , 0);
        return ((dp[0] * (dp[0] - 1)) + (dp[1] * (dp[1] - 1))) / 2;
        
   
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends