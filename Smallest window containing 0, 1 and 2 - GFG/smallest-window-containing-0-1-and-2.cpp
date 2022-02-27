// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool solve(string& s,int w){
        int p[3]={0};
        for(int i=0;i<w;i++){
            p[s[i]-'0']++;
        }
        if(p[0] and p[1] and p[2]){
            return true;
        }
        for(int i=w;i<s.size();i++){
            p[s[i-w]-'0']--;
            p[s[i]-'0']++;
            if(p[0] and p[1] and p[2]){
                return true;
            }
        }
        return false;
    }
    int smallestSubstring(string S) {
        // Code here
        vector<bool> p(3,true);
        for(auto i:S){
            p[i-'0']=false;
        }
        if(p[0] or p[1] or p[2]){
            return -1;
        }
        int low=3,high=S.size(),ans=0;
        while(low<=high){
            int avg=low+(high-low)/2;
            bool check=solve(S,avg);
            if(check){
                high=avg-1;
                ans=avg;
            }
            else{
                low=avg+1;
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
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends