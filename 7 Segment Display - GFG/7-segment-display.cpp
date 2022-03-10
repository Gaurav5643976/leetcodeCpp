// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string s, int N) {
        // code here
        long long arr[10]={6,2,5,5,4,5,6,3,7,5};
       long long n=0;
       for(int i=0;i<N;i++){
           n+=arr[s[i]-'0'];
       }
       for(long long i=0;i<N;i++){
           if((n-6)>=(N-i-1)*arr[1] && (n-6)<=(N-i-1)*arr[8]){
               s[i]='0';
               n-=6;
           }
           else if((n-2)>=(N-i-1)*arr[1] && (n-2)<=(N-i-1)*arr[8]){
               s[i]='1';
               n-=2;
           }
           else if((n-5)>=(N-i-1)*arr[1] && (n-5)<=(N-i-1)*arr[8]){
               s[i]='2';
               n-=5;
           }
           else if((n-4)>=(N-i-1)*arr[1] && (n-4)<=(N-i-1)*arr[8]){
               s[i]='4';
               n-=4;
           }
           else if((n-3)>=(N-i-1)*arr[1] && (n-3)<=(N-i-1)*arr[8]){
               s[i]='7';
               n-=3;
           }
           else if((n-7)>=(N-i-1)*arr[1] && (n-7)<=(N-i-1)*arr[8]){
               s[i]='8';
               n-=7;
           }
           
       }
       return s.substr(0,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends