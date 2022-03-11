// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(unordered_map<int,vector<int>>& um,int c,int& a,unordered_set<int>& st,int i){
        st.insert(i);
        //cout<<i<<" ";
        a=max(a,c);
        for(auto j:um[i]){
            if(st.find(j)==st.end()){
                dfs(um,c+1,a,st,j);
            }
        }
        //st.erase(i);
    }
    int findHeight(int N, int arr[]){
        // code here
        unordered_map<int,vector<int>> um;
        for(int i=0;i<N;i++){
            um[arr[i]].push_back(i);
        }
        int count=0,ans=0;
        unordered_set<int> st;
        dfs(um,count,ans,st,-1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends