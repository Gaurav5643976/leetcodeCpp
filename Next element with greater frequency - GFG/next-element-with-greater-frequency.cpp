// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void solve(vector<pair<int,int>>& v,int n,vector<int>& ans){
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                if(st.top().second>v[i].second){
                    ans[i]=st.top().first;
                }
                else{
                    while(!st.empty()){
                        if(st.top().second<=v[i].second){
                            st.pop();
                        }
                        else{
                            ans[i]=st.top().first;
                            break;
                        }
                    }
                }
            }
            st.push(v[i]);
        }
    }
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        // code here
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            um[arr[i]]++;
        }
        vector<pair<int,int>> vp;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            vp.push_back({arr[i],um[arr[i]]});
        }
        solve(vp,n,ans);
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends