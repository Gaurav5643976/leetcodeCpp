// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        // code here
        long long n=S.size();
        vector<long long> freq(26,0);
        for(auto i:S){
            freq[i-'a']++;
        }
        bool flag=false;
        long long ans=n*(n-1)/2;
        for(int i=0;i<26;i++){
            if(freq[i]>1){
                flag=true;
                ans-=freq[i]*(freq[i]-1)/2;
            }
        }
        if(flag){
            return ans+1;
        }
        return ans;
    }
    
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends