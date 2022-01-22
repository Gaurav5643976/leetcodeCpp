// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n=s.size();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        unordered_set<string> us; 
        for(int i=0;i<n;i++){
            t[i][i]=true;
            us.insert(s.substr(i,1));
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                t[i][i+1]=true;
                us.insert(s.substr(i,2));
            }
        }
        for(int len=3;len<=n;len++){
            for(int start=0;start+len-1<n;start++){
                if(s[start]==s[start+len-1] and t[start+1][start+len-2]){
                    t[start][start+len-1]=true;
                    us.insert(s.substr(start,len));
                }
            }
        }
        int ans=us.size();
        return ans;
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends