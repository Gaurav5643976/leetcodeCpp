// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string solve(string s){
        string ans="";
        for(int i=0;i<s.size();i++){
            int j=i+1;
            bool flag=false;
            while(j<s.size() and s[i]==s[j]){
                flag=true;
                j++;
            }
            if(!flag){
                ans+=s[i];
            }
            else{
                i=j-1;
            }
        }
        return ans;
    }
    string remove(string s){
        // code here
        string ans;
        while(1){
            ans=solve(s);
            if(ans==s){
                break;
            }
            s=ans;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends