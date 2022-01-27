// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int cat(int n){

        int c=0;
        
        if(n==0)return 1;
        
        for(int i=0; i<n; i++){
        
        c+=cat(i)*cat(n-i-1);}
        
        return c;
        
    }
    int count(int N){
        // code here
        if(N&1){
            return 0;
        }
        return cat(N/2);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends