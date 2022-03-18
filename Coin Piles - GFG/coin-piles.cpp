// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int n, int K) {
        // code here
     sort(A,A+n);
     int prefix[n];
     prefix[0]=A[0];
     int ans=INT_MAX;
     for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+A[i];
     }
     int prev=-1;
     
     for(int i=0;i<n;i++)
     {
         if(prev==A[i])
         continue;
         
         int permissible=A[i]+K;
         int idx=upper_bound(A,A+n,permissible)-A;
         
         int actual_pile=prefix[n-1]-prefix[idx-1];
         int desired_pile=(n-idx)*permissible;
         
         int reduction=actual_pile-desired_pile;
         if(i!=0){
            reduction+=prefix[i-1]; 
         }
         ans=min(ans,reduction);
         prev=A[i];
     }
     return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends