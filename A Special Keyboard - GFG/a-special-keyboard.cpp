// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        int ans=0;
        unordered_map<char,int> um;
        for(int i=0;i<26;i++){
            um[S1[i]]=i;
        }
        ans=um[S2[0]];
        //cout<<ans;
        int n=S2.size();
        for(int i=0;i<n-1;i++){
            ans+=abs(um[S2[i]]-um[S2[i+1]]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends