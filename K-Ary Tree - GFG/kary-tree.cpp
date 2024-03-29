// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     int mod=1000000007;
   long long power(int x, unsigned int y)
   {
       long long temp;
       if( y == 0)
           return 1;
       temp = (power(x, y / 2)%mod);
       if (y % 2 == 0)
           return (temp * temp)%mod;
       else
           return (x%mod * temp%mod * temp%mod)%mod;
   }
   long long karyTree(int k, int m) {
       long long ans=0;
       ans=(power(k,m))%mod;
       return ans;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends