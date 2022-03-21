// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isSubstring(string A,string B){
        int n=A.size(),m=B.size();
        int i=0,j=0;
        while(i<n and j<m){
            if(A[i]==B[j]){
                i++;
                j++;
            }
            else{
                i++;
                j=0;
            }
        }
        if(j<m){
            return false;
        }
        return true;
    }
    int minRepeats(string A, string B) {
        // code here
        string final=A;
        int k=1;
        while(final.size()<B.size()){
            final+=A;
            k++;
        }
        if(isSubstring(final,B)){
            return k;
        }
        final+=A;
        k++;
        if(isSubstring(final,B)){
            return k;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends