// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
        // code here 
        int ans1=0,ans2=0;
        unordered_map<int,int> um;
        um[x]=0;
        while(x!=1){
            ans1++;
            x/=2;
            um[x]=ans1;
        }
        while(y!=1){
            if(um.find(y)!=um.end()){
                return um[y]+ans2;
            }
            ans2++;
            y/=2;
        }
        return ans1+ans2;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends