// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string s ,int q, int index[], string source[], string target[]) {
        // code here
        int n = s.length();
        string original = s;
        string temp = "";
        string ans = "";
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            if(k < q && i == index[k])
            {
                string fromSource = source[k];
                int lengthFromSource = fromSource.length();
                string fromOriginal = original.substr(index[k], lengthFromSource);
                if(fromSource == fromOriginal)
                {
                    ans += target[k];
                    i += lengthFromSource - 1;
                }
                else
                {
                   ans += original[i];
                }
                k++;
            }
            else
            {
                ans += original[i];
            }
           
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends