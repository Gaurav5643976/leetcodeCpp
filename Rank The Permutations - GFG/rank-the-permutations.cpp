// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    unordered_map<int, int> mp;
   void helper(string s){
       for(int i = 0; i < s.size();i++){
           mp[s[i]-'a']++;
       }
   }
   long long fact(int n){
       long long res = 1;
       for(int i = 1; i <= n; i++) res *= i;
       return res;
   }
   
   long long findRank(string s) {
       helper(s);
       int n = s.size();
       long long res = 1;
       for(int i = 0; i < n; i++){
           int cnt= 0;
           for(int j = 0; j < s[i] - 'a' ; j++){
               cnt += mp[j];
           }
           mp[s[i] -'a']--;
           res += (cnt * fact(n - 1 - i));
       }
       return res;
   }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends