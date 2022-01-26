// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        vector<int> ans;
        unordered_map<int,int> um;
        for(auto i:array){
            um[i]++;
        }
        vector<pair<int,int>> vp;
        for(auto i:um){
            vp.push_back({i.second,i.first});
        }
        sort(vp.begin(),vp.end());
        int i=vp.size();
        while(k-- and i--){
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends