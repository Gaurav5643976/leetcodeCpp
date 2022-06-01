// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<pair<int,int>> ind;
    void Hanoi(int N,int strt, int goal, int middle, int n)
    {
        if(N==0) return;
        Hanoi(N-1,strt,middle,goal, n);
        ind.push_back({strt,goal});
        Hanoi(N-1,middle,goal,strt, n);
    }
    vector<int> shiftPile(int N, int n){
        // code here
        Hanoi(N,1,3,2, n); // 1,2,3 are boxes
        vector<int> ans(2);
        ans[0] = ind[n-1].first;
        ans[1] = ind[n-1].second;
        return ans;
    }

};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends