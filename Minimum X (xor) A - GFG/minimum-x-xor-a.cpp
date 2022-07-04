// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int set_bits(int x) {
        int s = 0; // set bits
        while (x != 0) {
            if (x % 2 == 1) {
                s++;
            }
            x = x / 2;
        }
        return s;
    }
    
    int minVal(int a, int b) {
        // code here
        int sa = set_bits(a);
        int sb = set_bits(b);
        
        if (sa == sb) return a;
        
        int ta = a, tb = b;
        int t = ((sa > sb) ? (sa - sb) : (sb - sa));
        int i = 1;
        int cmp;
        
        while (t > 0) {
            cmp = ((sa > sb) ? i : 0);
            if ((i & ta) == cmp) {
                ta = ta ^ i;
                t--;
            }
            i = i << 1;
        }
        
        return ta;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends